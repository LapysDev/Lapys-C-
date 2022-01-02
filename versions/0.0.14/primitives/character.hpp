/* Class > Character --- REDACT (Lapys) */
struct character_t {
    private: unsigned int value;
    public:
        constexpr character_t(unsigned int const = 0u);

        inline character_t& operator =(character_t const argument) noexcept { this -> value = argument; return *this; }
        inline character_t& operator +=(character_t const argument) noexcept { this -> value += argument; return *this; }
        inline character_t& operator -=(character_t const argument) noexcept { this -> value -= argument; return *this; }
        inline character_t& operator *=(character_t const argument) noexcept { this -> value *= argument; return *this; }
        inline character_t& operator /=(character_t const argument) noexcept { this -> value /= argument; return *this; }
        inline character_t& operator %=(character_t const argument) noexcept { this -> value %= argument; return *this; }
        inline character_t& operator ^=(character_t const argument) noexcept { this -> value ^= argument; return *this; }
        inline character_t& operator &=(character_t const argument) noexcept { this -> value &= argument; return *this; }
        inline character_t& operator |=(character_t const argument) noexcept { this -> value |= argument; return *this; }
        inline character_t& operator >>=(character_t const argument) noexcept { this -> value >>= argument; return *this; }
        inline character_t& operator <<=(character_t const argument) noexcept { this -> value <<= argument; return *this; }
        inline character_t operator ++(int const) noexcept { (this -> value)++; return *this; }
        inline character_t& operator ++(void) noexcept { ++(this -> value); return *this; }
        inline character_t operator --(int const) noexcept { (this -> value)--; return *this; }
        inline character_t& operator --(void) noexcept { --(this -> value); return *this; }
        constexpr inline operator unsigned int(void) const noexcept { return this -> value; }
};

/* Import > Character */
#include "character.cpp"
