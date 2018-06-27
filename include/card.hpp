//card.hpp

#pragma once

#include<vector>
#include<string>

#include"koords.hpp"
#include"colors.hpp"

typedef std::vector<std::string> SHIRT;

class Card {
    public:
        static const Koords &VALUE_KOORDS();
        static const std::vector<SHIRT> &CARD_VALUES();
        static const SHIRT &CARD();
    private:
        unsigned short value_;
        Cell cell_;
    public:
        Card (unsigned short value_number = 0, const Cell = DEFAULT_CELL);
        ~Card();
        static unsigned short getYsize();
        static unsigned short getXsize();
        bool operator==(const Card &) const;
        const Card &show_face_down(const Koords &) const;
        const Card &show_face_up(const Koords &) const;
    private:
        void show_value(const Koords &) const;
};
