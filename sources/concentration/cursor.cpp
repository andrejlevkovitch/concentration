//cursor.cpp

#include"cursor.hpp"
#include"concentration.hpp"

const decltype(Koords {}.getY()) &Cursor::PAS_FRWD()
{
    static const auto retval {Concentration::CARD_PASS().getY()};
    return retval;
};

const decltype(Koords {}.getX()) &Cursor::PAS_SIDE()
{
    static const auto retval {Concentration::CARD_PASS().getX()};
    return retval;
};

Cursor::Cursor (const Koords &in) : Koords {in}
{
}

Cursor::~Cursor()
{
}

Koords &Cursor::move_right()
{
    for (int i {}; i < PAS_SIDE(); ++i) {
        Koords::move_right();
    }
    return *this;
}

Koords &Cursor::move_left()
{
    for (int i {}; i < PAS_SIDE(); ++i) {
        Koords::move_left();
    }
    return *this;
}

Koords &Cursor::move_up()
{
    for (int i {}; i < PAS_FRWD(); ++i) {
        Koords::move_up();
    }
    return *this;
}

Koords &Cursor::move_down()
{
    for (int i {}; i < PAS_FRWD(); ++i) {
        Koords::move_down();
    }
    return *this;
}
