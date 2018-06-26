//constants.cpp

#include"card.hpp"
#include"concentration.hpp"

#include<cmath>

const Koords Card::VALUE_KOORDS_ {1, 2};

const std::vector<SHIRT> Card::CARD_VALUES_ {
    {"-->"},
    {"<--"},
    {":-)"},
    {"::{"},
    {"(|)"},
    {"/|\\"},
    {"***"},
    {"777"},
    {"000"},
    {":?)"},
    {"+++"},
    {"---"},
    {"-$-"},
    {"&pt"},
    {"sex"},
    {"_^_"},
    {"^_^"},
    {"!!!"},
};

const SHIRT Card::CARD_ {
    "+-----+",
    "|     |",
    "+-----+"
};

const int Concentration::SLEEPING_TIME_ {500};
const short Concentration::CARD_ON_SIDE_ (sqrt(Card::CARD_VALUES_.size() * 2));
const Koords Concentration::BEG_SCR_ {0, 5};
const Koords Concentration::DISTANCE_BITWIN_CARDS_ {1, 2};
const Koords Concentration::BEG_CRD_POS_ {BEG_SCR_ + DISTANCE_BITWIN_CARDS_ +
    Koords {1, 1}};
const Koords Concentration::CARD_PASS_ {
    Koords {Card::getYsize(), Card::getXsize()} + DISTANCE_BITWIN_CARDS_};
const Koords Concentration::END_SCR_ {BEG_CRD_POS_ + CARD_ON_SIDE_ * CARD_PASS_
};

const decltype(Koords {}.getY()) Cursor::PAS_FRWD_ {Concentration::CARD_PASS_.getY()};
const decltype(Koords {}.getX()) Cursor::PAS_SIDE_ {Concentration::CARD_PASS_.getX()};
