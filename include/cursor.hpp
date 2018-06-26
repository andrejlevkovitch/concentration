//cursor.hpp

#include"koords.hpp"

class Cursor : public Koords {
    private:
        static const unsigned PAS_SIDE {9};
        static const unsigned PAS_FRWD {4};
    public:
        Cursor (const Koords &in);
        ~Cursor();
        Koords &move_up();
        Koords &move_down();
        Koords &move_right();
        Koords &move_left();
};
