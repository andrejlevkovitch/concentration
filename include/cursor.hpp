//cursor.hpp

#pragma once

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
