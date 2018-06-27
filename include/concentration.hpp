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
        static const unsigned short &CARD_ON_SIDE();
        static const Koords &BEG_SCR();
        static const Koords &DISTANCE_BITWIN_CARDS();
        static const Koords &BEG_CRD_POS();
        static const Koords &CARD_PASS();
        static const Koords &END_SCR();
        static const int &SLEEPING_TIME();
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
        void close_last_cards();
        const decltype(compared_card_) current_card();
};
