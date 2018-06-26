//cursor.cpp

#include"cursor.hpp"
#include"concentration.hpp"

Cursor::Cursor (const Koords &in) : Koords {in}
{
}

Cursor::~Cursor()
{
}

Koords &Cursor::move_right()
{
    for (int i {}; i < PAS_SIDE_; ++i) {
        Koords::move_right();
    }
    return *this;
}

Koords &Cursor::move_left()
{
    for (int i {}; i < PAS_SIDE_; ++i) {
        Koords::move_left();
    }
    return *this;
}

Koords &Cursor::move_up()
{
    for (int i {}; i < PAS_FRWD_; ++i) {
        Koords::move_up();
    }
    return *this;
}

Koords &Cursor::move_down()
{
    for (int i {}; i < PAS_FRWD_; ++i) {
        Koords::move_down();
    }
    return *this;
}
