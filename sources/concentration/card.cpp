//card.cpp

#include<string>
#include<curses.h>

#include"card.hpp"
#include"koords.hpp"
#include"move.hpp"

const Koords &Card::VALUE_KOORDS()
{
    static const Koords retval {1, 2};
    return retval;
};

const std::vector<SHIRT> &Card::CARD_VALUES()
{
    static const std::vector<SHIRT> retval {
        {"-->"},
        {"<--"},
        {":-)"},
        {"::{"},
        {"(|)"},
        {"/|\\"},
        {"***"},
        {"777"},
        {"000"},
        {":?)"},
        {"+++"},
        {"---"},
        {"-$-"},
        {"&pt"},
        {"sex"},
        {"_^_"},
        {"^_^"},
        {"!!!"}
    };
    return retval;
};

const SHIRT &Card::CARD()
{
    static const SHIRT retval {
    "+-----+",
    "|     |",
    "+-----+"
    };
    return retval;
};

const Cell &Card::CELL()
{
    static const Cell retvalue {CARD_CELL};
    return retvalue;
};

Card::Card (unsigned short card_number) : is_open_(false)
{
    value_ = (card_number < CARD_VALUES().size()) ? card_number : 0;
}

Card::~Card()
{
}

bool Card::is_open() const
{
    return is_open_;
}

const Card &Card::change_status()
{
    is_open_ = !is_open_;
    return *this;
}

void Card::show_shirt(const Koords &in)
{
    Koords temp {in};
    for (int i {}; i < CARD().size(); ++i) {
        move_at(temp);
        for (int j {}; j < CARD()[i].size(); ++j) {
            addch(CARD()[i][j]);
        }
        temp.move_down();
    }
    return;
}

const Card &Card::show_card(const Koords &in) const
{
    if (is_open_) {
        attron(A_REVERSE);
    }
    attron(COLOR_PAIR(CELL()));
    show_shirt(in);
    if (is_open_) {
        show_value(in);
    }
    attroff(COLOR_PAIR(CELL()));
    if (is_open_) {
        attroff(A_REVERSE);
    }

    refresh();
    return *this;
}

const Card &Card::highlith(const Koords &in) const
{
    attron(A_BOLD);
    show_card(in);
    attroff(A_BOLD);
    return *this;
}

unsigned short Card::getYsize()
{
    return CARD().size();
}

unsigned short Card::getXsize()
{
    return CARD()[0].size();
}

bool Card::operator==(const Card &rhs) const
{
    if (value_ == rhs.value_)
        return true;
    else
        return false;
}

void Card::show_value(const Koords &in) const
{
    auto temp {in + VALUE_KOORDS()};
    for (int i {}; i < CARD_VALUES()[value_].size(); ++i) {
        move_at(temp);
        for (int j {}; j < CARD_VALUES()[value_][i].size(); ++j) {
            addch(CARD_VALUES()[value_][i][j]);
        }
        temp.move_down();
    }
    return;
}
