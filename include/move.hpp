//move.hpp

#pragma once

#include<curses.h>
#include<string>

#include"koords.hpp"

void move_at(const Koords &);
void move_add(const Koords &, chtype);
void move_add(const Koords &, const std::string &);

void frame(const Koords &lhs_ucorner, const Koords &rhs_dcorner);
void fill_field(const Koords &lhs_ucorner, const Koords &rhs_dcorner);
