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
        static const Cell &CELL();
    private:
        unsigned short value_;
        bool is_open_;
    public:
        Card (unsigned short value_number = 0);
        ~Card();
        bool is_open() const;
        const Card &change_status();
        static unsigned short getYsize();
        static unsigned short getXsize();
        bool operator==(const Card &) const;
        static void show_shirt(const Koords &);
        const Card &show_card(const Koords &) const;
        const Card &highlith(const Koords &) const;
    private:
        void show_value(const Koords &) const;
};
