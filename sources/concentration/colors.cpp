//colors.cpp

#include<curses.h>

#include"../../include/colors.hpp"

void init_colors(void)
{
    if (!has_colors()) {
        throw "Colors are not supported!";
    }
    start_color();

    init_pair(FREE_CELL, COLOR_WHITE, COLOR_WHITE);
    init_pair(FRAME_CELL, COLOR_BLACK, COLOR_WHITE);
    init_pair(CARD_CELL, COLOR_GREEN, COLOR_BLUE);

    return;
}
