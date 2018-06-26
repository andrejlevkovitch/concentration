//fill_field.cpp

#include"../../include/move.hpp"
#include"../../include/colors.hpp"

void fill_field(const Koords &lhs_ucorner, const Koords &rhs_dcorner)
{
    Koords temp {lhs_ucorner};
    for (int i {lhs_ucorner.getY()}; i <= rhs_dcorner.getY(); ++i) {
        move_at(temp);
        for (int i {lhs_ucorner.getX()}; i <= rhs_dcorner.getX(); ++i) {
            addch(' ' | COLOR_PAIR(FREE_CELL));
        }
        temp.move_down();
    }
    return;
}
