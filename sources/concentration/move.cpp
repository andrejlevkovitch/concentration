//move.cpp

#include<string>
#include<curses.h>

#include"move.hpp"

void move_at(const Koords &in)
{
    move(in.getY(), in.getX());
    return;
}

void move_add(const Koords &in, chtype symbol)
{
    move_at(in);
    addch(symbol);
    return;
}

void move_add(const Koords &in, const std::string &value)
{
    move_at(in);
    addstr(value.c_str());
    return;
}
