//move.hpp

#pragma once

#ifndef __cplusplus
#error C++ is required
#elif __cplusplus <= 201103L
#error C++14 is required
#endif

#include<curses.h>
#include<string>

#include"koords.hpp"

void move_at(const Koords &);
void move_add(const Koords &, chtype);
void move_add(const Koords &, const std::string &);
