/* ... Class > Decimal --- REDACT (Lapys) */
struct decimal {
    private: long double value;
    public:
        constexpr decimal(long double const = false);

        inline decimal& operator =(decimal const argument) noexcept { this -> value = argument; return *this; }
        inline decimal& operator +=(decimal const argument) noexcept { this -> value += argument; return *this; }
        inline decimal& operator -=(decimal const argument) noexcept { this -> value -= argument; return *this; }
        inline decimal& operator *=(decimal const argument) noexcept { this -> value *= argument; return *this; }
        inline decimal& operator /=(decimal const argument) noexcept { this -> value /= argument; return *this; }
        inline decimal& operator %=(decimal const argument) noexcept { Math::mod(this -> value); return *this; }
        inline decimal& operator ^=(decimal const argument) noexcept { this -> value ^= argument; return *this; }
        inline decimal& operator &=(decimal const argument) noexcept { this -> value &= argument; return *this; }
        inline decimal& operator |=(decimal const argument) noexcept { this -> value |= argument; return *this; }
        inline decimal operator ++(int const) noexcept { (this -> value)++; return *this; }
        inline decimal& operator ++(void) noexcept { ++(this -> value); return *this; }
        constexpr inline operator long double(void) const noexcept { return this -> value; }
};

/* Import > Boolean */
#include "decimal.cpp"
