/* ... Class > Decimal --- REDACT (Lapys) */
struct decimal_t {
    private: long double value;
    public:
        constexpr decimal_t(long double const = false);

        inline decimal_t& operator =(decimal_t const argument) noexcept { this -> value = argument; return *this; }
        inline decimal_t& operator +=(decimal_t const argument) noexcept { this -> value += argument; return *this; }
        inline decimal_t& operator -=(decimal_t const argument) noexcept { this -> value -= argument; return *this; }
        inline decimal_t& operator *=(decimal_t const argument) noexcept { this -> value *= argument; return *this; }
        inline decimal_t& operator /=(decimal_t const argument) noexcept { this -> value /= argument; return *this; }
        inline decimal_t& operator %=(decimal_t const argument) noexcept { Math::mod(this -> value); return *this; }
        inline decimal_t& operator ^=(decimal_t const argument) noexcept { this -> value ^= argument; return *this; }
        inline decimal_t& operator &=(decimal_t const argument) noexcept { this -> value &= argument; return *this; }
        inline decimal_t& operator |=(decimal_t const argument) noexcept { this -> value |= argument; return *this; }
        inline decimal_t operator ++(int const) noexcept { (this -> value)++; return *this; }
        inline decimal_t& operator ++(void) noexcept { ++(this -> value); return *this; }
        constexpr inline operator long double(void) const noexcept { return this -> value; }
};

/* Import > Decimal */
#include "decimal.cpp"
