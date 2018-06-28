//colors.hpp

#pragma once

#ifndef __cplusplus
#error C++ is required
#elif __cplusplus <= 201103L
#error C++14 is required
#endif

#include<curses.h>

enum Cell {DEFAULT_CELL, FRAME_CELL, FREE_CELL, CARD_CELL};
const chtype DEF_VALUE {' ' | COLOR_PAIR(FREE_CELL)};

void init_colors(void);
