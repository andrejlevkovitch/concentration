//cursor.hpp

#pragma once

#ifndef __cplusplus
#error C++ is required
#elif __cplusplus <= 201103L
#error C++14 is required
#endif

#include"koords.hpp"

class Cursor : public Koords {
    public:
        static const decltype(Koords {}.getY()) &PAS_FRWD();
        static const decltype(Koords {}.getX()) &PAS_SIDE();
    public:
        Cursor (const Koords &in);
        ~Cursor();
        Koords &move_up();
        Koords &move_down();
        Koords &move_right();
        Koords &move_left();
};
