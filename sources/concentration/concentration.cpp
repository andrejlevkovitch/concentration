//concentration.cpp

#include<vector>
#include<random>
#include<cstdbool>
#include<chrono>
#include<thread>
#include<cmath>

#include"concentration.hpp"
#include"move.hpp"

const unsigned short &Concentration::MIN_SIDE_SIZE() {
    static const unsigned short retval {4};
    return retval;
}

const unsigned short &Concentration::MAX_SIDE_SIZE()
{
    static const unsigned short retval (sqrt(Card::CARD_VALUES().size() * 2));
    return retval;
};

const Koords &Concentration::BEG_SCR()
{
    static const Koords retval {3, 5};
    return retval;
};

const Koords &Concentration::DISTANCE_BITWIN_CARDS()
{
    static const Koords retval {1, 2};
    return retval;
};

const Koords &Concentration::BEG_CRD_POS()
{
    static const Koords retval {BEG_SCR() + DISTANCE_BITWIN_CARDS() +
        Koords {1, 1}};
    return retval;
};

const Koords &Concentration::CARD_PASS()
{
    static const Koords retval {Koords (Card::getYsize(), Card::getXsize()) +
        DISTANCE_BITWIN_CARDS()};
    return retval;
};

const Koords &Concentration::END_SCR() const
{
    return end_scr_;
};

const std::chrono::milliseconds &Concentration::SLEEPING_TIME()
{
    static const std::chrono::milliseconds retval {500};
    return retval;
};

Concentration::Concentration (unsigned short size) : cursor_ {BEG_CRD_POS()}
{
    size_ = (size > MAX_SIDE_SIZE()) ? MAX_SIDE_SIZE() : size;
    size_ = (size_ % 2) ? size_ - 1 : size_;
    size_ = (size_ < MIN_SIDE_SIZE()) ? MIN_SIDE_SIZE() : size_;
    end_scr_ = BEG_CRD_POS() + size_ * CARD_PASS();
    unsigned short counter {};
    for (int i {}; i < size_; ++i) {
        for (int j {}; j < size_; ++j) {
            pack_.insert({
                    BEG_CRD_POS() + Koords (i, j) * CARD_PASS(),
                    Card (counter / 2)
                    });
            counter++;
        }
    }
}

Concentration::~Concentration()
{
}

void Concentration::show_pack() const
{
    frame(BEG_SCR(), END_SCR());
    fill_field(BEG_SCR() + Koords {1, 1}, END_SCR() - Koords {1, 1});
    for (const auto &card : pack_) {
        card.second.show_card(card.first);
    }
    return;
}

void Concentration::shuffle()
{
    int n = pack_.size() - 1;
    std::vector<Koords> koords;
    koords.reserve(pack_.size());
    for (const auto &card : pack_) {
        koords.push_back(card.first);
    }
#ifdef __linux__
    std::random_device rd;
    std::mt19937 gen {rd()};
#else
    static std::mt19937 gen(std::chrono::system_clock::to_time_t
            (std::chrono::system_clock::now()));
#endif
    while (n) {
        std::uniform_int_distribution<int> dist {0, n};
        std::swap(pack_[koords[n]], pack_[koords[dist(gen)]]);
        n--;
    }
    return;
}

bool Concentration::game()
{
    shuffle();
    show_pack();
    int ch {};
    bool is_second = false;
    do {
        move_at(cursor_);
        higlith_current_card_on();
        switch (ch = getch()) {
            case 'k':
            case 'w':
            case KEY_UP:
                higlith_current_card_off();
                if (!(cursor_.move_up() > BEG_SCR())) {
                    cursor_.move_down();
                }
                higlith_current_card_on();
                break;
            case 'j':
            case 's':
            case KEY_DOWN:
                higlith_current_card_off();
                if (!(cursor_.move_down() < END_SCR())) {
                    cursor_.move_up();
                }
                higlith_current_card_on();
                break;
            case 'h':
            case 'a':
            case KEY_LEFT:
                higlith_current_card_off();
                if (!(cursor_.move_left() > BEG_SCR())) {
                    cursor_.move_right();
                }
                higlith_current_card_on();
                break;
            case 'l':
            case 'd':
            case KEY_RIGHT:
                higlith_current_card_off();
                if (!(cursor_.move_right() < END_SCR())) {
                    cursor_.move_left();
                }
                higlith_current_card_on();
                break;
            case ENTER:
                if (is_second) {
                    if (compared_card_pair_ == current_card_pair() ||
                            current_card_pair()->second.is_open()) {
                        break;
                    }
                    open_current_card();
                    if (!(compared_card_pair_->second ==
                                current_card_pair()->second)) {
                        close_last_cards();
                    }
                    is_second = false;
                }
                else {
                    compared_card_pair_ = current_card_pair();
                    if (!compared_card_pair_->second.is_open()) {
                        open_current_card();
                        is_second = true;
                    }
                }
                break;
            case EOF:
            case '':
                ch = ESC;
                break;
            default:
                break;
        }
    } while (ch != ESC);
    return false;
}

const Card &Concentration::open_current_card()
{
    return current_card_pair()->second.change_status().show_card(cursor_);
}

auto Concentration::current_card_pair() -> const decltype(compared_card_pair_)
{
    return pack_.find(cursor_);
}

void Concentration::close_last_cards()
{
    std::this_thread::sleep_for(Concentration::SLEEPING_TIME());
    compared_card_pair_->second.change_status().
        show_card(compared_card_pair_->first);
    current_card_pair()->second.change_status().show_card(cursor_);
    return;
}

const Card &Concentration::higlith_current_card_on() const
{
    return pack_.find(cursor_)->second.highlith(cursor_);
}

const Card &Concentration::higlith_current_card_off() const
{
    return pack_.find(cursor_)->second.show_card(cursor_);
}
