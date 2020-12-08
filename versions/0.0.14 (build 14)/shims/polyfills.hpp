/* Definition */
/* ... */
#if false == defined(CLOCKS_PER_SEC) && defined(CLK_TCK) // Clock Cycles Per Second
#   define CLOCKS_PER_SEC CLK_TCK
#endif

#ifndef INFINITY // Infinity
    struct INFINITY { // WARN (Lapys) -> Non-standard implementation.
        private: unsigned long const value[2];
        public:
            constexpr inline INFINITY(void) : value{0x00000000, 0x7FF00000} {}
            constexpr inline operator double(void) const noexcept { return *(double const*) (this -> value); }
    } const INFINITY = {};
#endif

#ifndef INT_EPSILON // Integer Epsilon
#   define INT_EPSILON 1
#endif

#ifndef LONG_EPSILON // Long Integer Epsilon
#   define LONG_EPSILON 1L
#endif

#ifndef M_LOG2E // Mathematical Binary Logarithm of Euler's Number
#   define M_LOG2E 1.44269504088896340736
#endif

#ifndef M_LOG10E // Mathematical Denary Logarithm of Euler's Number
#   define M_LOG10E 0.434294481903251827651
#endif

#ifndef NAN // Not-A-Number
    struct NAN { // WARN (Lapys) -> Non-standard implementation.
        private: unsigned long const value[2];
        public:
            constexpr inline NAN(void) : value{0x00000000, 0x7FF80000} {}
            constexpr inline operator double(void) const noexcept { return *(double const*) (this -> value); }
    } const NAN = {};
#endif

#ifndef NANF // Not-A-Number
#   define NANF ((float) NAN)
#endif

#ifndef NANL // Not-A-Number
#   define NANL ((long double) NAN)
#endif

#ifndef NULL // Null Pointer
#   define NULL 0x0
#endif

#ifndef O_BINARY // Open Binary (Mode)
#   define O_BINARY 0x0
#endif

#ifndef SHRT_EPSILON // Short Integer Epsilon
#   define SHRT_EPSILON 1
#endif

#ifndef UINT_EPSILON // Unsigned Integer Epsilon
#   define UINT_EPSILON 1u
#endif

#ifndef ULONG_EPSILON // Unsigned Long Integer Epsilon
#   define ULONG_EPSILON 1uL
#endif

#ifndef USHRT_EPSILON // Unsigned Short Integer Epsilon
#   define USHRT_EPSILON 1u
#endif

#if false == defined(VK_HANGUL) && defined(VK_HANGUEL) // Virtual Key: Hangul
#   define VK_HANGUL VK_HANGUEL
#endif

/* C .... */
#define c__version
#define source_is_c false

#ifdef __STDC__
    /* [Versioning] */
    #undef c__version
    #undef source_is_c
    #define source_is_c true

    #ifdef __STDC_VERSION__
    #   if __STDC_VERSION__ == 199409L
    #     define c__version 1994uL
    #   elif __STDC_VERSION__ == 199901L
    #     define c__version 1999uL
    #   elif __STDC_VERSION__ == 201112L
    #     define c__version 2011uL
    #   elif __STDC_VERSION__ == 201710L
    #     define c__version 2018uL
    #   else
    #       define c__version 1990uL
    #   endif
    #else
    #   define c__version 1989uL
    #endif

    #ifndef c__version
    #   define c__version true
    #endif

    /* [Shimming] */
    #if c__version <= 1990uL // C 1990, ANSI X3.159-1989 -> C 1990, ISO/IEC 9899:1990
    #elif c__version <= 1994uL
    #   ifndef INFINITY // Infinity
    #       ifndef HUGE_VAL
    #           define HUGE_VAL ((unsigned long) ~0)
    #       endif
    #       define INFINITY HUGE_VAL
    #   endif

    #   ifndef HUGE_VALF // Huge Value
    #       define HUGE_VALF ((float) HUGE_VAL)
    #   endif

    #   ifndef HUGE_VALL // Huge Value
    #       define HUGE_VALL ((long double) HUGE_VAL)
    #   endif

    #   if false == (defined(__STD_UTF_16__) && __STD_UTF_16__) // Standard Unicode Text Format (UTF-16)
            typedef struct char16_t { // UTF-16 Character Type
                // [...]
                private:
                    // Definition > Value
                    unsigned short value;

                // [...]
                public:
                    // [Constructor]
                    char16_t(void) : value{} {}
                    template <class type> char16_t(type argument) : value{argument} {}
                    char16_t(char16_t const& argument) : value{argument.value} {}
                    char16_t(char16_t&& argument) : value{argument.value} {}

                    // [Operator] > ...
                    char16_t& operator =(char16_t const argument) throw() { this -> value = argument; return *this; }
                    char16_t& operator +=(char16_t const argument) throw() { this -> value += argument; return *this; }
                    char16_t& operator -=(char16_t const argument) throw() { this -> value -= argument; return *this; }
                    char16_t& operator *=(char16_t const argument) throw() { this -> value *= argument; return *this; }
                    char16_t& operator /=(char16_t const argument) throw() { this -> value /= argument; return *this; }
                    char16_t& operator %=(char16_t const argument) throw() { this -> value %= argument; return *this; }
                    char16_t& operator ^=(char16_t const argument) throw() { this -> value ^= argument; return *this; }
                    char16_t& operator &=(char16_t const argument) throw() { this -> value &= argument; return *this; }
                    char16_t& operator |=(char16_t const argument) throw() { this -> value |= argument; return *this; }
                    char16_t& operator >>=(char16_t const argument) throw() { return this -> value >>= argument; return *this; }
                    char16_t& operator <<=(char16_t const argument) throw() { return this -> value <<= argument; return *this; }
                    char16_t operator ++(int const) throw() { (this -> value)++; return *this; }
                    char16_t& operator ++(void) throw() { ++(this -> value); return *this; }
                    char16_t operator --(int const) throw() { (this -> value)--; return *this; }
                    char16_t& operator --(void) throw() { --(this -> value); return *this; }
                    operator unsigned short(void) const throw() { return this -> value; }
            } char16_t;

    #       define CHAR16_MAX USHRT_MAX
    #       define CHAR16_MIN USHRT_MIN
    #   endif

    #   if false == (defined(__STD_UTF_32__) && __STD_UTF_32__) // Standard Unicode Text Format (UTF-32)
            typedef struct char32_t { // UTF-32 Character Type
                // [...]
                private:
                    // Definition > Value
                    unsigned int value;

                // [...]
                public:
                    // [Constructor]
                    char32_t(void) : value{} {}
                    char32_t(unsigned int const argument) : value{argument} {}
                    char32_t(char32_t const& argument) : value{argument.value} {}
                    char32_t(char32_t&& argument) : value{argument.value} {}

                    // [Operator] > ...
                    char32_t& operator =(char32_t const argument) throw() { this -> value = argument; return *this; }
                    char32_t& operator +=(char32_t const argument) throw() { this -> value += argument; return *this; }
                    char32_t& operator -=(char32_t const argument) throw() { this -> value -= argument; return *this; }
                    char32_t& operator *=(char32_t const argument) throw() { this -> value *= argument; return *this; }
                    char32_t& operator /=(char32_t const argument) throw() { this -> value /= argument; return *this; }
                    char32_t& operator %=(char32_t const argument) throw() { this -> value %= argument; return *this; }
                    char32_t& operator ^=(char32_t const argument) throw() { this -> value ^= argument; return *this; }
                    char32_t& operator &=(char32_t const argument) throw() { this -> value &= argument; return *this; }
                    char32_t& operator |=(char32_t const argument) throw() { this -> value |= argument; return *this; }
                    char32_t& operator >>=(char32_t const argument) throw() { return this -> value >>= argument; return *this; }
                    char32_t& operator <<=(char32_t const argument) throw() { return this -> value <<= argument; return *this; }
                    char32_t operator ++(int const) throw() { (this -> value)++; return *this; }
                    char32_t& operator ++(void) throw() { ++(this -> value); return *this; }
                    char32_t operator --(int const) throw() { (this -> value)--; return *this; }
                    char32_t& operator --(void) throw() { --(this -> value); return *this; }
                    operator unsigned int(void) const throw() { return this -> value; }
            } char32_t;

    #       define CHAR32_MAX UINT_MAX
    #       define CHAR32_MIN UINT_MIN
    #   endif

    #   if false == (defined(__STD_UTF_8__) && __STD_UTF_8__) // Standard Unicode Text Format (UTF-8)
            typedef struct char8_t { // UTF-8 Character Type
                // [...]
                private:
                    // Definition > Value
                    unsigned char value;

                // [...]
                public:
                    // [Constructor]
                    constexpr inline char8_t(void) : value{} {}
                    constexpr inline char8_t(unsigned char argument) : value{argument} {}
                    constexpr inline char8_t(char8_t const& argument) : value{argument.value} {}
                    constexpr inline char8_t(char8_t&& argument) : value{argument.value} {}

                    // [Operator] > ...
                    inline char8_t& operator =(char8_t const argument) noexcept { this -> value = argument; return *this; }
                    inline char8_t& operator +=(char8_t const argument) noexcept { this -> value += argument; return *this; }
                    inline char8_t& operator -=(char8_t const argument) noexcept { this -> value -= argument; return *this; }
                    inline char8_t& operator *=(char8_t const argument) noexcept { this -> value *= argument; return *this; }
                    inline char8_t& operator /=(char8_t const argument) noexcept { this -> value /= argument; return *this; }
                    inline char8_t& operator %=(char8_t const argument) noexcept { this -> value %= argument; return *this; }
                    inline char8_t& operator ^=(char8_t const argument) noexcept { this -> value ^= argument; return *this; }
                    inline char8_t& operator &=(char8_t const argument) noexcept { this -> value &= argument; return *this; }
                    inline char8_t& operator |=(char8_t const argument) noexcept { this -> value |= argument; return *this; }
                    inline char8_t& operator >>=(char8_t const argument) noexcept { return this -> value >>= argument; return *this; }
                    inline char8_t& operator <<=(char8_t const argument) noexcept { return this -> value <<= argument; return *this; }
                    inline char8_t operator ++(int const) noexcept { (this -> value)++; return *this; }
                    inline char8_t& operator ++(void) noexcept { ++(this -> value); return *this; }
                    inline char8_t operator --(int const) noexcept { (this -> value)--; return *this; }
                    inline char8_t& operator --(void) noexcept { --(this -> value); return *this; }
                    constexpr inline operator unsigned char(void) const noexcept { return this -> value; }
            } char8_t;

    #       define CHAR8_MAX UCHAR_MAX
    #       define CHAR8_MIN UCHAR_MIN
    #   endif

    #   ifndef WCHAR_MAX // Wide Character Maximum
    #       define WCHAR_MAX sizeof(wchar_t)
    #   endif

    #   ifndef WCHAR_MIN // Wide Character Minimum
    #       define WCHAR_MIN sizeof(wchar_t)
    #   endif
    #elif c__version <= 1999uL // C 1999, ISO/IEC 9899:1999
    #elif c__version <= 2011uL // C 2011, ISO/IEC 9899:2011
    #elif c__version <= 2018uL // C 2018
    #endif
#endif

/* C++ ... */
#define cpp__version
#define cpp_command_line__version

#define cpp__interface_is_command_line false
#define cpp__interface_is_embedded false

#define source_is_cpp false

#ifdef __cplusplus
    /* [Versioning] */
    #undef cpp__version
    #undef source_is_cpp
    #define source_is_cpp true

    #if __cplusplus == 199711L
    #   define cpp__version 1997uL
    #elif __cplusplus == 201103L
    #   define cpp__version 2011uL
    #elif __cplusplus == 201402L
    #   define cpp__version 2014uL
    #elif __cplusplus == 201703L
    #   define cpp__version 2017uL
    #else
    #   define cpp__version 2020uL
    #endif

    #ifndef cpp__version
    #   define cpp__version true
    #endif

    /* [Shimming] */
    #if cpp__version <= 1997uL // C++ 1997, ISO/IEC 14882:1998 -> C++ 2003, ISO/IEC 14882:2003
    #   define constexpr // ...
    #   define final
    #   define inline
    #   define noexcept throw()
    #endif

    #if cpp__version <= 2011uL // C++ 2011, ISO/IEC 14882:2011
    #endif

    #if cpp__version <= 2014uL // C++ 2014, ISO/IEC 14882:2014
    #endif

    #if cpp__version <= 2017uL // C++ 2017, ISO/IEC 14882:2017
        constexpr std::size_t operator ""zu(unsigned long long const number) noexcept { return number; }
    #endif

    #if cpp__version <= 2020uL // C++ 2020, ...
    #endif
#endif

#ifdef __cplusplus_cli
    /* [Versioning] */
    #undef cpp__interface_is_command_line
    #undef cpp_command_line__version

    #define cpp__interface_is_command_line true

    #if __cplusplus_cli == 200406L
    #   define cpp_command_line__version 2004uL
    #endif

    /* [Shimming] */
    #if cpp_command_line__version == 2004uL // C++ CLI 2004, ECMA-372
    #endif
#endif

#ifdef __embedded_cplusplus
    /* [Versioning] */
    #undef cpp__interface_is_embedded
    #define cpp__interface_is_embedded true

    /* [Shimming] */
#endif
