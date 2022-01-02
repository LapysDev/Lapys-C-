/* Modification > Mathematics */
    // Infinity > ...
    #if c__version >= 1999uL
        constexpr inline bool Mathematics::Infinity::is(double const number) const noexcept { return isinf(number); }
        constexpr inline bool Mathematics::Infinity::is(float const number) const noexcept { return isinf(number); }
        constexpr inline bool Mathematics::Infinity::is(long double const number) const noexcept { return isinf(number); }
    #elif cpp__version >= 2011uL
        constexpr inline bool Mathematics::Infinity::is(double const number) const noexcept { return ::isinf(number); }
        constexpr inline bool Mathematics::Infinity::is(float const number) const noexcept { return ::isinf(number); }
        constexpr inline bool Mathematics::Infinity::is(long double const number) const noexcept { return ::isinf(number); }
    #else
        constexpr inline bool Mathematics::Infinity::is(double const number) const noexcept { return INFINITY == number; }
        constexpr inline bool Mathematics::Infinity::is(float const number) const noexcept { return INFINITY == number; }
        constexpr inline bool Mathematics::Infinity::is(long double const number) const noexcept { return INFINITY == number; }
    #endif

    constexpr inline bool Mathematics::Infinity::is(int const) const noexcept { return false; }
    constexpr inline bool Mathematics::Infinity::is(long const) const noexcept { return false; }
    constexpr inline bool Mathematics::Infinity::is(short const) const noexcept { return false; }
    constexpr inline bool Mathematics::Infinity::is(signed char const) const noexcept { return false; }
    constexpr inline bool Mathematics::Infinity::is(unsigned char const) const noexcept { return false; }
    constexpr inline bool Mathematics::Infinity::is(unsigned int const) const noexcept { return false; }
    constexpr inline bool Mathematics::Infinity::is(unsigned long const) const noexcept { return false; }
    constexpr inline bool Mathematics::Infinity::is(unsigned short const) const noexcept { return false; }

    #if c__version >= 1999uL
        constexpr inline bool Mathematics::Infinity::isnt(double const number) const noexcept { return isfinite(number); }
        constexpr inline bool Mathematics::Infinity::isnt(float const number) const noexcept { return isfinite(number); }
        constexpr inline bool Mathematics::Infinity::isnt(long double const number) const noexcept { return isfinite(number); }
    #elif cpp__version >= 2011uL
        constexpr inline bool Mathematics::Infinity::isnt(double const number) const noexcept { return ::isfinite(number); }
        constexpr inline bool Mathematics::Infinity::isnt(float const number) const noexcept { return ::isfinite(number); }
        constexpr inline bool Mathematics::Infinity::isnt(long double const number) const noexcept { return ::isfinite(number); }
    #else
        constexpr inline bool Mathematics::Infinity::isnt(double const number) const noexcept { return INFINITY != number; }
        constexpr inline bool Mathematics::Infinity::isnt(float const number) const noexcept { return INFINITY != number; }
        constexpr inline bool Mathematics::Infinity::isnt(long double const number) const noexcept { return INFINITY != number; }
    #endif

    constexpr inline bool Mathematics::Infinity::isnt(int const) const noexcept { return true; }
    constexpr inline bool Mathematics::Infinity::isnt(long const) const noexcept { return true; }
    constexpr inline bool Mathematics::Infinity::isnt(short const) const noexcept { return true; }
    constexpr inline bool Mathematics::Infinity::isnt(signed char const) const noexcept { return true; }
    constexpr inline bool Mathematics::Infinity::isnt(unsigned char const) const noexcept { return true; }
    constexpr inline bool Mathematics::Infinity::isnt(unsigned int const) const noexcept { return true; }
    constexpr inline bool Mathematics::Infinity::isnt(unsigned long const) const noexcept { return true; }
    constexpr inline bool Mathematics::Infinity::isnt(unsigned short const) const noexcept { return true; }

    constexpr inline Mathematics::Infinity::operator double(void) const noexcept { return INFINITY; }

    // Not-A-Number > ...
    constexpr inline bool Mathematics::NaN::is(int const number) const noexcept { return number != number; }
    constexpr inline bool Mathematics::NaN::is(long const number) const noexcept { return number != number; }
    constexpr inline bool Mathematics::NaN::is(short const number) const noexcept { return number != number; }
    constexpr inline bool Mathematics::NaN::is(signed char const number) const noexcept { return number != number; }
    constexpr inline bool Mathematics::NaN::is(unsigned char const number) const noexcept { return number != number; }
    constexpr inline bool Mathematics::NaN::is(unsigned int const number) const noexcept { return number != number; }
    constexpr inline bool Mathematics::NaN::is(unsigned long const number) const noexcept { return number != number; }
    constexpr inline bool Mathematics::NaN::is(unsigned short const number) const noexcept { return number != number; }

    #if c__version >= 1999uL
        constexpr inline bool Mathematics::NaN::is(double const number) const noexcept { return NaN::is((long double) number); }
        constexpr inline bool Mathematics::NaN::is(float const number) const noexcept { return NaN::is((long double) number); }
        constexpr inline bool Mathematics::NaN::is(long double const number) const noexcept { return isnan(number); }
    #elif cpp__version >= 2011uL
        constexpr inline bool Mathematics::NaN::is(double const number) const noexcept { return ::isnan(number); }
        constexpr inline bool Mathematics::NaN::is(float const number) const noexcept { return ::isnan(number); }
        constexpr inline bool Mathematics::NaN::is(long double const number) const noexcept { return ::isnan(number); }
    #else
        constexpr inline bool Mathematics::NaN::is(double const number) const noexcept { return NaN::is((long double) number); }
        constexpr inline bool Mathematics::NaN::is(float const number) const noexcept { return NaN::is((long double) number); }
        constexpr inline bool Mathematics::NaN::is(long double const number) const noexcept { return number != number; }
    #endif

    constexpr inline bool Mathematics::NaN::isnt(double const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(float const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(int const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(long const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(long double const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(short const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(signed char const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(unsigned char const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(unsigned int const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(unsigned long const number) const noexcept { return false == NaN::is(number); }
    constexpr inline bool Mathematics::NaN::isnt(unsigned short const number) const noexcept { return false == NaN::is(number); }

    constexpr inline Mathematics::NaN::operator double(void) const noexcept { return NAN; }
    constexpr inline Mathematics::NaN::operator float(void) const noexcept { return NANF; }
    constexpr inline Mathematics::NaN::operator long double(void) const noexcept { return NANL; }
