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

Card::Card (unsigned short card_number, const Cell cell) :
    cell_ {cell}
{
    value_ = (card_number < CARD_VALUES().size()) ? card_number : 0;
}

Card::~Card()
{
}

const Card &Card::show_face_down(const Koords &in) const
{
    Koords temp {in};
    attron(COLOR_PAIR(cell_));
    for (int i {}; i < CARD().size(); ++i) {
        move_at(temp);
        for (int j {}; j < CARD()[i].size(); ++j) {
            addch(CARD()[i][j]);
        }
        temp.move_down();
    }
    attroff(COLOR_PAIR(cell_));
    refresh();
    return *this;
}

const Card &Card::show_face_up(const Koords &in) const
{
    attron(A_REVERSE);
    show_face_down(in);
    show_value(in);
    attroff(A_REVERSE);
    refresh();
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
    attron(COLOR_PAIR(cell_));
    auto temp {in + VALUE_KOORDS()};
    for (int i {}; i < CARD_VALUES()[value_].size(); ++i) {
        move_at(temp);
        for (int j {}; j < CARD_VALUES()[value_][i].size(); ++j) {
            addch(CARD_VALUES()[value_][i][j]);
        }
        temp.move_down();
    }
    attroff(COLOR_PAIR(cell_));
    return;
}
