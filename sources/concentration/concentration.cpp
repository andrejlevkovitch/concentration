//concentration.cpp

#include<vector>
#include<cmath>
#include<random>
#include<cstdbool>
#include<tuple>
#include<thread>

#include"../../include/concentration.hpp"
#include"../../include/move.hpp"

const short Concentration::CARD_ON_SIDE (std::sqrt(CARD_VALUES.size() * 2));
const Koords Concentration::BEG_SCR {3, 6};
const Koords Concentration::END_SCR {BEG_SCR + Koords {16, 37}};
const Koords Concentration::BEG_CRS_POS {BEG_SCR + Koords {1, 2}};

Concentration::Concentration () : cursor_ {BEG_CRS_POS}
{
    int counter {};
    for (int i {}; i < CARD_ON_SIDE; ++i) {
        for (int j {}; j < CARD_ON_SIDE; ++j) {
            pack_.insert({
                    BEG_SCR + Koords {U_CARD_PASS, S_CARD_PASS} +
                    Koords (i * (Card::getYsize() + U_CARD_PASS),
                            j * (Card::getXsize() + S_CARD_PASS)),
                    Card {CARD_VALUES[counter / 2], CARD_CELL}
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
    frame(BEG_SCR, END_SCR);
    fill_field(BEG_SCR + Koords {1, 1}, END_SCR - Koords {1, 1});
    for (const auto &card : pack_) {
        card.second.show_face_down(card.first);
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
    std::random_device rd;
    std::mt19937 gen {rd()};
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
        switch (ch = getch()) {
            case 'k':
            case 'w':
            case KEY_UP:
                if (cursor_.move_up() > BEG_SCR) {
                }
                else {
                    cursor_.move_down();
                }
                break;
            case 'j':
            case 's':
            case KEY_DOWN:
                if (cursor_.move_down() < END_SCR) {
                }
                else {
                    cursor_.move_up();
                }
                break;
            case 'h':
            case 'a':
            case KEY_LEFT:
                if (cursor_.move_left() > BEG_SCR) {
                }
                else {
                    cursor_.move_right();
                }
                break;
            case 'l':
            case 'd':
            case KEY_RIGHT:
                if (cursor_.move_right() < END_SCR) {
                }
                else {
                    cursor_.move_left();
                }
                break;
            case ENTER:
                if (is_second) {
                    if (compared_card_ == current_card()) {
                        break;
                    }
                    show_current_card();
                    if ((*compared_card_).second == (*current_card()).second) {
                        open_cards_.insert((*compared_card_).first);
                        open_cards_.insert((*current_card()).first);
                    }
                    else {
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        (*compared_card_).second.show_face_down((*compared_card_).first);
                        if (current_card() == pack_.end()) {
                        }
                        else {
                            (*current_card()).second.show_face_down(cursor_);
                        }
                    }
                    is_second = false;
                }
                else {
                    compared_card_ = current_card();
                    if (compared_card_ != pack_.end()) {
                        show_current_card();
                        is_second = true;
                    }
                }
                break;
            case '':
                ch = ESC;
                break;
            default:
                break;
        }
    } while (ch != ESC);
    return false;
}

const Card &Concentration::show_current_card() const
{
    return pack_.find(cursor_)->second.show_face_up(cursor_);
}

auto Concentration::current_card() -> decltype(compared_card_) const
{
    auto temp {pack_.find(cursor_)};
    if (open_cards_.find(temp->first) == open_cards_.end())
        return temp;
    else
        return pack_.end();
}
