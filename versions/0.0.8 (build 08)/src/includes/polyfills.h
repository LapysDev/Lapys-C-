/* ... */
#ifndef CLOCKS_PER_SEC // Clock Cycles Per Second
#  define CLOCKS_PER_SEC CLK_TCK
#endif

#ifndef EXIT_SUCCESS // Successful Exit Program Status
#  define EXIT_SUCCESS 0
#endif

#ifndef INFINITY // Infinity
#  define INFINITY HUGE_VAL
#endif

#ifndef NULL // Null Pointer
#  define NULL /* (void*) */0x0
#endif

#ifndef VK_HANGUL // Virtual Key Hangul
#  define VK_HANGUL VK_HANGUEL
#endif

/* C Versions */
#ifdef __STDC__ // C 1989, ANSI X3.159-1989 -> C 1990, ISO/IEC 9899:1990
#endif

#if __STDC_VERSION__ == 199409L // C 1994, ISO/IEC 9899-1:1994
#endif

#if __STDC_VERSION__ == 199901L // C 1999, ISO/IEC 9899:1999
#endif

#if __STDC_VERSION__ == 201112L // C 2011, ISO/IEC 9899:2011
#endif

/* C++ Versions */
#if __cplusplus <= 199711L // C++ 1998, ISO/IEC 14882:1998
#  define constexpr
#  define inline
#  define noexcept throw()
#endif

#if __cplusplus <= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900) // C++ 2011, ISO/IEC 14882:2011
#endif

#if __cplusplus <= 201402L // C++ 2014, ISO/IEC 14882:2014
#endif

#if __cplusplus <= 201703L // C++ 2017, ISO/IEC 14882:2017
typedef struct char8_t {
    // [...]
    private:
        // Declaration > Value
        unsigned char value;

    // [...]
    public:
        // [Constructor]
        constexpr inline char8_t(const unsigned char argument) : value{argument} {}
        constexpr inline char8_t(char8_t& argument) : value{argument.value} {}
        constexpr inline char8_t(char8_t&& argument) : value{argument.value} {}
        constexpr inline char8_t(const char8_t& argument) : value{argument.value} {}
        constexpr inline char8_t(const char8_t&& argument) : value{argument.value} {}

        // [Operator]
            // [=]
            constexpr inline char8_t& operator =(const unsigned char argument) { this -> value = argument; return *this; }
            constexpr inline char8_t& operator =(char8_t& argument) { this -> value = argument.value; return *this; }
            constexpr inline char8_t& operator =(char8_t&& argument) { this -> value = argument.value; return *this; }
            constexpr inline char8_t& operator =(const char8_t& argument) { this -> value = argument.value; return *this; }
            constexpr inline char8_t& operator =(const char8_t&& argument) { this -> value = argument.value; return *this; }

            // [...]
            constexpr inline operator unsigned char(void) const { return this -> value; }
} char8_t;
#endif

#if __cplusplus_cli == 200406L // Command-Line Interface C++, ECMA-372
#endif

#ifndef __embedded_cplusplus // Embedded C++
#endif
