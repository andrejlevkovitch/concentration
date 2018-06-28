//main.cpp

#include<iostream>
#include<curses.h>

#include"concentration.hpp"
#include"move.hpp"
#include"colors.hpp"

int main(int argc, char *argv[])
{
    initscr();
    keypad(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    noecho();
    init_colors();
    Concentration a {4};
    a.game();
    Concentration b {8};
    b.game();
    endwin();
    return 0;
}
