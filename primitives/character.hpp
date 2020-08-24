/* Class > Character --- REDACT (Lapys) */
struct character {
    private: unsigned int value;
    public:
        constexpr character(unsigned int const = 0u);

        inline character& operator =(character const argument) noexcept { this -> value = argument; return *this; }
        inline character& operator +=(character const argument) noexcept { this -> value += argument; return *this; }
        inline character& operator -=(character const argument) noexcept { this -> value -= argument; return *this; }
        inline character& operator *=(character const argument) noexcept { this -> value *= argument; return *this; }
        inline character& operator /=(character const argument) noexcept { this -> value /= argument; return *this; }
        inline character& operator %=(character const argument) noexcept { this -> value %= argument; return *this; }
        inline character& operator ^=(character const argument) noexcept { this -> value ^= argument; return *this; }
        inline character& operator &=(character const argument) noexcept { this -> value &= argument; return *this; }
        inline character& operator |=(character const argument) noexcept { this -> value |= argument; return *this; }
        inline character& operator >>=(character const argument) noexcept { this -> value >>= argument; return *this; }
        inline character& operator <<=(character const argument) noexcept { this -> value <<= argument; return *this; }
        inline character operator ++(int const) noexcept { (this -> value)++; return *this; }
        inline character& operator ++(void) noexcept { ++(this -> value); return *this; }
        inline character operator --(int const) noexcept { (this -> value)--; return *this; }
        inline character& operator --(void) noexcept { --(this -> value); return *this; }
        constexpr inline operator unsigned int(void) const noexcept { return this -> value; }
};

/* Import > Character */
#include "character.cpp"
