//concentration.hpp

#pragma once

#include<vector>
#include<map>
#include<set>

#include"card.hpp"
#include"cursor.hpp"

typedef std::map<Koords, Card, Koords::greater> PACK;

const int ESC {27};
const int ENTER {'\n'};

class Concentration {
    public:
        static const Koords BEG_SCR;
        static const Koords END_SCR;
        static const Koords BEG_CRS_POS;
        static const short CARD_ON_SIDE;
    private:
        static const short U_CARD_PASS {1};
        static const short S_CARD_PASS {2};
    private:
        PACK pack_;
        Cursor cursor_;
        decltype(pack_.find(cursor_)) compared_card_;
        std::set<Koords, Koords::greater> open_cards_;
    public:
        Concentration ();
        ~Concentration();
        void show_pack() const;
        void shuffle();
        bool game();
    private:
        const Card &show_current_card() const;
        void close_cards() const;
        auto current_card() -> decltype(compared_card_) const;
};
