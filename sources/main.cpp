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
    Concentration a {10};
    a.game();
    endwin();
    return 0;
}
