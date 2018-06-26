//cursor.hpp

#pragma once

#include"koords.hpp"

class Cursor : public Koords {
    private:
        static const decltype(Koords {}.getY()) PAS_FRWD_;
        static const decltype(Koords {}.getX()) PAS_SIDE_;
    public:
        Cursor (const Koords &in);
        ~Cursor();
        Koords &move_up();
        Koords &move_down();
        Koords &move_right();
        Koords &move_left();
};
