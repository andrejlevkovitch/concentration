//card.hpp

#pragma once

#include<vector>
#include<string>

#include"koords.hpp"
#include"colors.hpp"

typedef std::vector<std::string> SHIRT;

const SHIRT CARD_VALUES
{
    "-->",
    "<--",
    ":-)",
    "::{",
    "(|)",
    "/|\\",
    "***",
    "777",
};

class Card {
    private:
        static const Koords value_koords_;
    public:
        static const SHIRT card_;
    private:
        std::string value_;
        Cell cell_;
    public:
        Card (const std::string &value = "", const Cell = DEFAULT_CELL);
        ~Card();
        static short getYsize();
        static short getXsize();
        bool operator==(const Card &) const;
        const Card &show_face_down(const Koords &) const;
        const Card &show_face_up(const Koords &) const;
};
