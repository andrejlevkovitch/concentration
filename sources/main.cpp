//main.cpp

#include<iostream>
#include<curses.h>

#include"../include/concentration.hpp"
#include"../include/move.hpp"
#include"../include/colors.hpp"

int main(int argc, char *argv[])
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    init_colors();
    Concentration a {};
    a.game();
    endwin();
    return 0;
}
