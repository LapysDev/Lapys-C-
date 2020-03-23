/* Definition */
    /* ... */
    #ifndef CLOCKS_PER_SEC // Clock Cycles Per Second
    #  define CLOCKS_PER_SEC CLK_TCK
    #endif

    #ifndef NANF // Not-A-Number
    #  define NANF ((float) NAN)
    #endif

    #ifndef NANL // Not-A-Number
    #  define NANL ((long double) NAN)
    #endif

    #ifndef NULL // Null Pointer
    #  define NULL 0x0
    #endif

    #ifndef EXIT_SUCCESS // Successful Exit Program Status
    #  define EXIT_SUCCESS 0
    #endif

    #ifndef VK_HANGUL // Virtual Key: Hangul
    #  define VK_HANGUL VK_HANGUEL
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
        #  if __STDC_VERSION__ == 199409L
        #     define c__version 1994uL
        #  elif __STDC_VERSION__ == 199901L
        #     define c__version 1999uL
        #  elif __STDC_VERSION__ == 201112L
        #     define c__version 2011uL
        #  elif __STDC_VERSION__ == 201710L
        #     define c__version 2018uL
        #  endif
        #else
        #  define c__version 1990uL
        #endif

        #ifndef c__version
        #  define c__version true
        #endif

        /* [Shimming] */
        #if c__version <= 1990uL // C 1990, ANSI X3.159-1989 -> C 1990, ISO/IEC 9899:1990
        #elif c__version <= 1994uL
        #  ifndef INFINITY // Infinity
        #      ifdef HUGE_VAL
        #         define INFINITY HUGE_VAL
        #      else
        #         define HUGE_VAL ((unsigned long) ~0)
        #         define INFINITY ((unsigned long) ~0)
        #      endif
        #  endif

        #  ifndef HUGE_VALF // Huge Value
        #      define HUGE_VALF HUGE_VAL
        #  endif

        #  ifndef HUGE_VALL // Huge Value
        #      define HUGE_VALL HUGE_VAL
        #  endif

        #  ifndef WCHAR_MAX // Wide Character Maximum
        #     define WCHAR_MAX sizeof(wchar_t)
        #  endif

        #  ifndef WCHAR_MIN // Wide Character Minimum
        #     define WCHAR_MIN sizeof(wchar_t)
        #  endif
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
        #  define cpp__version 1997uL
        #elif __cplusplus == 201103L
        #  define cpp__version 2011uL
        #elif __cplusplus == 201402L
        #  define cpp__version 2014uL
        #elif __cplusplus == 201703L
        #  define cpp__version 2017uL
        #endif

        #ifndef cpp__version
        #  define cpp__version true
        #endif

        /* [Shimming] */
        #if cpp__version <= 1997uL // C++ 1997, ISO/IEC 14882:1998 -> C++ 2003, ISO/IEC 14882:2003
        #  define abstract = delete
        #  define constexpr // ...
        #  define inline
        #  define noexcept throw()

        typedef struct char16_t { // UTF-16 Character Type
            // [...]
            private:
                // Definition > Value
                unsigned short value;

            // [...]
            public:
                // [Constructor]
                constexpr inline char16_t(void) : value{} {}
                constexpr inline char16_t(char16_t& argument) : value{argument.value} {}
                constexpr inline char16_t(char16_t&& argument) : value{argument.value} {}
                constexpr inline char16_t(char16_t const& argument) : value{argument.value} {}
                constexpr inline char16_t(char16_t const&& argument) : value{argument.value} {}
                template <typename type> constexpr inline char16_t(type argument) : value{argument} {}

                // [Operator] > ...
                template <typename type> inline char16_t& operator =(type argument) noexcept { this -> value = argument; return *this; }
                template <typename type> inline char16_t& operator +=(type argument) noexcept { this -> value += argument; return *this; }
                template <typename type> inline char16_t& operator -=(type argument) noexcept { this -> value -= argument; return *this; }
                template <typename type> inline char16_t& operator *=(type argument) noexcept { this -> value *= argument; return *this; }
                template <typename type> inline char16_t& operator /=(type argument) noexcept { this -> value /= argument; return *this; }
                template <typename type> inline char16_t& operator %=(type argument) noexcept { this -> value %= argument; return *this; }
                template <typename type> inline char16_t& operator ^=(type argument) noexcept { this -> value ^= argument; return *this; }
                template <typename type> inline char16_t& operator &=(type argument) noexcept { this -> value &= argument; return *this; }
                template <typename type> inline char16_t& operator |=(type argument) noexcept { this -> value |= argument; return *this; }
                template <typename type> inline char16_t& operator >>=(type argument) noexcept { return this -> value >>= argument; return *this; }
                template <typename type> inline char16_t& operator <<=(type argument) noexcept { return this -> value <<= argument; return *this; }
                inline char16_t operator ++(int const) noexcept { (this -> value)++; return *this; }
                inline char16_t& operator ++(void) noexcept { ++(this -> value); return *this; }
                inline char16_t operator --(int const) noexcept { (this -> value)--; return *this; }
                inline char16_t& operator --(void) noexcept { --(this -> value); return *this; }
                constexpr inline operator unsigned short(void) const noexcept { return this -> value; }
        } char16_t;
        #  define CHAR16_MAX USHRT_MAX
        #  define CHAR16_MIN USHRT_MIN

        typedef struct char32_t { // UTF-32 Character Type
            // [...]
            private:
                // Definition > Value
                unsigned int value;

            // [...]
            public:
                // [Constructor]
                constexpr inline char32_t(void) : value{} {}
                constexpr inline char32_t(char32_t& argument) : value{argument.value} {}
                constexpr inline char32_t(char32_t&& argument) : value{argument.value} {}
                constexpr inline char32_t(char32_t const& argument) : value{argument.value} {}
                constexpr inline char32_t(char32_t const&& argument) : value{argument.value} {}
                template <typename type> constexpr inline char32_t(type argument) : value{argument} {}

                // [Operator] > ...
                template <typename type> inline char32_t& operator =(type argument) noexcept { this -> value = argument; return *this; }
                template <typename type> inline char32_t& operator +=(type argument) noexcept { this -> value += argument; return *this; }
                template <typename type> inline char32_t& operator -=(type argument) noexcept { this -> value -= argument; return *this; }
                template <typename type> inline char32_t& operator *=(type argument) noexcept { this -> value *= argument; return *this; }
                template <typename type> inline char32_t& operator /=(type argument) noexcept { this -> value /= argument; return *this; }
                template <typename type> inline char32_t& operator %=(type argument) noexcept { this -> value %= argument; return *this; }
                template <typename type> inline char32_t& operator ^=(type argument) noexcept { this -> value ^= argument; return *this; }
                template <typename type> inline char32_t& operator &=(type argument) noexcept { this -> value &= argument; return *this; }
                template <typename type> inline char32_t& operator |=(type argument) noexcept { this -> value |= argument; return *this; }
                template <typename type> inline char32_t& operator >>=(type argument) noexcept { return this -> value >>= argument; return *this; }
                template <typename type> inline char32_t& operator <<=(type argument) noexcept { return this -> value <<= argument; return *this; }
                inline char32_t operator ++(int const) noexcept { (this -> value)++; return *this; }
                inline char32_t& operator ++(void) noexcept { ++(this -> value); return *this; }
                inline char32_t operator --(int const) noexcept { (this -> value)--; return *this; }
                inline char32_t& operator --(void) noexcept { --(this -> value); return *this; }
                constexpr inline operator unsigned int(void) const noexcept { return this -> value; }
        } char32_t;
        #  define CHAR32_MAX UINT_MAX
        #  define CHAR32_MIN UINT_MIN
        #endif

        #if cpp__version <= 2011uL // C++ 2011, ISO/IEC 14882:2011
        #  define abstract = 0
        #endif

        #if cpp__version <= 2014uL // C++ 2014, ISO/IEC 14882:2014
        #endif

        #if cpp__version <= 2017uL // C++ 2017, ISO/IEC 14882:2017
        typedef struct char8_t { // UTF-8 Character Type
            // [...]
            private:
                // Definition > Value
                unsigned char value;

            // [...]
            public:
                // [Constructor]
                constexpr inline char8_t(void) : value{} {}
                constexpr inline char8_t(char8_t& argument) : value{argument.value} {}
                constexpr inline char8_t(char8_t&& argument) : value{argument.value} {}
                constexpr inline char8_t(char8_t const& argument) : value{argument.value} {}
                constexpr inline char8_t(char8_t const&& argument) : value{argument.value} {}
                template <typename type> constexpr inline char8_t(type argument) : value{argument} {}

                // [Operator] > ...
                template <typename type> inline char8_t& operator =(type argument) noexcept { this -> value = argument; return *this; }
                template <typename type> inline char8_t& operator +=(type argument) noexcept { this -> value += argument; return *this; }
                template <typename type> inline char8_t& operator -=(type argument) noexcept { this -> value -= argument; return *this; }
                template <typename type> inline char8_t& operator *=(type argument) noexcept { this -> value *= argument; return *this; }
                template <typename type> inline char8_t& operator /=(type argument) noexcept { this -> value /= argument; return *this; }
                template <typename type> inline char8_t& operator %=(type argument) noexcept { this -> value %= argument; return *this; }
                template <typename type> inline char8_t& operator ^=(type argument) noexcept { this -> value ^= argument; return *this; }
                template <typename type> inline char8_t& operator &=(type argument) noexcept { this -> value &= argument; return *this; }
                template <typename type> inline char8_t& operator |=(type argument) noexcept { this -> value |= argument; return *this; }
                template <typename type> inline char8_t& operator >>=(type argument) noexcept { return this -> value >>= argument; return *this; }
                template <typename type> inline char8_t& operator <<=(type argument) noexcept { return this -> value <<= argument; return *this; }
                inline char8_t operator ++(int const) noexcept { (this -> value)++; return *this; }
                inline char8_t& operator ++(void) noexcept { ++(this -> value); return *this; }
                inline char8_t operator --(int const) noexcept { (this -> value)--; return *this; }
                inline char8_t& operator --(void) noexcept { --(this -> value); return *this; }
                constexpr inline operator unsigned char(void) const noexcept { return this -> value; }
        } char8_t;
        #  define CHAR8_MAX UCHAR_MAX
        #  define CHAR8_MIN UCHAR_MIN
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
        #  define cpp_command_line__version 2004uL
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
