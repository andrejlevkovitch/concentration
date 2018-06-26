//koords.cpp

#include"koords.hpp"
#include<cstdbool>

const unsigned Koords::PAS_SIDE_ {1};
const unsigned Koords::PAS_FRWD_ {1};

Koords::Koords (short y, short x) : y_(y), x_(x)
{
}

Koords::Koords(const Koords &in) : y_(in.y_), x_(in.x_)
{
}

auto Koords::getY() const -> decltype(y_)
{
    return y_;
}

auto Koords::getX() const -> decltype(x_)
{
    return x_;
}

bool Koords::operator<(const Koords &right) const
{
    if (y_ < right.y_ && x_ < right.x_)
        return true;
    else
        return false;
}

bool Koords::operator>(const Koords &right) const
{
    if (y_ > right.y_ && x_ > right.x_)
        return true;
    else
        return false;
}

Koords &Koords::move_right()
{
    x_ += PAS_SIDE_;
    return *this;
}

Koords &Koords::move_left()
{
    x_ -= PAS_SIDE_;
    return *this;
}

Koords &Koords::move_up()
{
    y_ -= PAS_FRWD_;
    return *this;
}

Koords &Koords::move_down()
{
    y_ += PAS_FRWD_;
    return *this;
}

Koords Koords::operator-(const Koords &right) const
{
    return Koords (y_ - right.y_, x_ - right.x_);
}

Koords Koords::operator+(const Koords &right) const
{
    return Koords (y_ + right.y_, x_ + right.x_);
}

Koords Koords::operator*(const Koords &rhs) const
{
    return Koords (y_ * rhs.y_, x_ * rhs.x_);
}

Koords Koords::operator*(int n) const
{
    return Koords (y_ * n, x_ * n);
}

Koords operator*(int n, const Koords &in)
{
    return in * n;
}

bool Koords::operator==(const Koords &right) const
{
    if (y_ == right.y_ && x_ == right.x_)
        return true;
    else
        return false;
}

bool Koords::greater::operator()(const Koords &lhs, const Koords &rhs) const
{
    if (lhs.getY() > rhs.getY())
        return true;
    else if (lhs.getY() < rhs.getY())
        return false;
    else {
        if (lhs.getX() > rhs.getX())
            return true;
        else
            return false;
    }
}
