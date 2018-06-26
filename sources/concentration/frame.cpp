//frame.cpp

#include<curses.h>

#include"../../include/koords.hpp"
#include"../../include/colors.hpp"
#include"../../include/move.hpp"

void frame(const Koords &lhs_ucorner, const Koords &rhs_dcorner)
{
    Koords temp {lhs_ucorner};
    attron(COLOR_PAIR(FRAME_CELL));
    move_add(temp, ACS_ULCORNER);
    for (int i {lhs_ucorner.getX()}; i < rhs_dcorner.getX() - 1; ++i) {
        addch(ACS_HLINE);
    }
    addch(ACS_URCORNER);
    Koords other_side {lhs_ucorner.getY(), rhs_dcorner.getX()};
    for (int i {lhs_ucorner.getY()}; i < rhs_dcorner.getY() - 1; ++i) {
        move_add(temp.move_down(), ACS_VLINE);
        move_add(other_side.move_down(), ACS_VLINE);
    }
    move_add(temp.move_down(), ACS_LLCORNER);
    for (int i {lhs_ucorner.getX()}; i < rhs_dcorner.getX() - 1; ++i) {
        addch(ACS_HLINE);
    }
    addch(ACS_LRCORNER);
    attroff(COLOR_PAIR(FRAME_CELL));
    refresh();
    return;
}
