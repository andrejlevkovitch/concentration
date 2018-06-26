//card.cpp

#include<string>
#include<curses.h>

#include"../../include/card.hpp"
#include"../../include/koords.hpp"
#include"../../include/move.hpp"

const Koords Card::value_koords_ {1, 2};

const SHIRT Card::card_
        {
            "+-----+",
            "|     |",
            "+-----+"
        };

Card::Card (const std::string &value, const Cell cell) :
    value_ {value}, cell_ {cell}
{
}

Card::~Card()
{
}

const Card &Card::show_face_down(const Koords &current) const
{
    Koords temp {current};
    attron(COLOR_PAIR(cell_));
    for (int i {}; i < card_.size(); ++i) {
        move_at(temp);
        for (int j {}; j < card_[i].size(); ++j) {
            addch(card_[i][j]);
        }
        temp.move_down();
    }
    attroff(COLOR_PAIR(cell_));
    refresh();
    return *this;
}

const Card &Card::show_face_up(const Koords &current) const
{
    attron(A_REVERSE);
    show_face_down(current);
    attron(COLOR_PAIR(cell_));
    move_add(value_koords_ + current, value_);
    attroff(A_REVERSE);
    attroff(COLOR_PAIR(cell_));
    refresh();
    return *this;
}

short Card::getYsize()
{
    return card_.size();
}

short Card::getXsize()
{
    return card_[0].size();
}

bool Card::operator==(const Card &rhs) const
{
    if (value_ == rhs.value_)
        return true;
    else
        return false;
}
