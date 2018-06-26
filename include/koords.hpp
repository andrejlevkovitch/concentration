//koords.hpp

#pragma once

#include<cstdbool>

class Koords {
    public:
        static const unsigned PAS_SIDE{1};
        static const unsigned PAS_FRWD{1};
    private:
        short y_;
        short x_;
    public:
        explicit Koords (short = 0, short = 0);
        Koords(const Koords &);
        auto getY() const -> decltype(y_);
        auto getX() const -> decltype(x_);
        virtual bool operator<(const Koords &) const;
        virtual bool operator>(const Koords &) const;
        Koords operator-(const Koords &) const;
        Koords operator+(const Koords &) const;
        bool operator==(const Koords &) const;
        virtual Koords &move_right();
        virtual Koords &move_left();
        virtual Koords &move_up();
        virtual Koords &move_down();
        struct greater {
            bool operator()(const Koords &lhs, const Koords &rhs) const;
        };
};
