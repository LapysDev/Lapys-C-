/* Namespace > Mathematics */
namespace Mathematics {
    constexpr double const E = M_E;
    constexpr double const LOG2E = M_LOG2E;
    constexpr double const LOG10E = M_LOG10E;
    constexpr double const LN2 = M_LN2;
    constexpr double const LN10 = M_LN10;
    constexpr double const PI = M_PI;
    constexpr double const TAU = 6.283185307179586232;
    constexpr double const SQRT2 = M_SQRT2;
    constexpr double const SQRT3 = 1.73205080756887719318;
    constexpr double const SQRT5 = 2.23606797749978980505;

    struct Infinity { public:
        constexpr inline bool is(double const number) const noexcept;
        constexpr inline bool is(float const number) const noexcept;
        constexpr inline bool is(int const) const noexcept;
        constexpr inline bool is(long const) const noexcept;
        constexpr inline bool is(long double const number) const noexcept;
        constexpr inline bool is(short const) const noexcept;
        constexpr inline bool is(signed char const) const noexcept;
        constexpr inline bool is(unsigned char const) const noexcept;
        constexpr inline bool is(unsigned int const) const noexcept;
        constexpr inline bool is(unsigned long const) const noexcept;
        constexpr inline bool is(unsigned short const) const noexcept;

        constexpr inline bool isnt(double const number) const noexcept;
        constexpr inline bool isnt(float const number) const noexcept;
        constexpr inline bool isnt(int const) const noexcept;
        constexpr inline bool isnt(long const) const noexcept;
        constexpr inline bool isnt(long double const number) const noexcept;
        constexpr inline bool isnt(short const) const noexcept;
        constexpr inline bool isnt(signed char const) const noexcept;
        constexpr inline bool isnt(unsigned char const) const noexcept;
        constexpr inline bool isnt(unsigned int const) const noexcept;
        constexpr inline bool isnt(unsigned long const) const noexcept;
        constexpr inline bool isnt(unsigned short const) const noexcept;

        constexpr inline operator double(void) const noexcept;
    } const Infinity;

    struct NaN { public:
        constexpr inline bool is(double const number) const noexcept;
        constexpr inline bool is(float const number) const noexcept;
        constexpr inline bool is(int const) const noexcept;
        constexpr inline bool is(long const) const noexcept;
        constexpr inline bool is(long double const number) const noexcept;
        constexpr inline bool is(short const) const noexcept;
        constexpr inline bool is(signed char const) const noexcept;
        constexpr inline bool is(unsigned char const) const noexcept;
        constexpr inline bool is(unsigned int const) const noexcept;
        constexpr inline bool is(unsigned long const) const noexcept;
        constexpr inline bool is(unsigned short const) const noexcept;

        constexpr inline bool isnt(double const number) const noexcept;
        constexpr inline bool isnt(float const number) const noexcept;
        constexpr inline bool isnt(int const) const noexcept;
        constexpr inline bool isnt(long const) const noexcept;
        constexpr inline bool isnt(long double const number) const noexcept;
        constexpr inline bool isnt(short const) const noexcept;
        constexpr inline bool isnt(signed char const) const noexcept;
        constexpr inline bool isnt(unsigned char const) const noexcept;
        constexpr inline bool isnt(unsigned int const) const noexcept;
        constexpr inline bool isnt(unsigned long const) const noexcept;
        constexpr inline bool isnt(unsigned short const) const noexcept;

        constexpr inline operator double(void) const noexcept;
        constexpr inline operator float(void) const noexcept;
        constexpr inline operator long double(void) const noexcept;
    } const NaN;
} namespace Math = Mathematics;
