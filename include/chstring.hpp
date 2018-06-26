//chstring.hpp

#pragma once

#include<vector>
#include<string>
#include<curses.h>

#include"colors.hpp"

class chstring {
    private:
        std::vector<chtype> string_;
    public: chstring (const std::string &, const Cell = DEFAULT_CELL);
        ~chstring();
        chtype *ch_str();
};
