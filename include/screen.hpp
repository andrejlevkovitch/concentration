//screen.hpp

#include"koords.hpp"

class Screen {
    public:
        Screen (const Koords &beg, const Koords &end);
        ~Screen();
    private:
        void frame(const Koords &beg, const Koords &end);
        void fill_field(const Koords &beg, const Koords &end);
};
