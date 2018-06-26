//colors.hpp

#pragma once

#include<curses.h>

enum Cell {DEFAULT_CELL, FRAME_CELL, FREE_CELL, CARD_CELL};
const chtype DEF_VALUE {' ' | COLOR_PAIR(FREE_CELL)};

void init_colors(void);
