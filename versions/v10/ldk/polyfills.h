/* ... */
#ifndef CLOCKS_PER_SEC // Clock Cycles Per Second
#  define CLOCKS_PER_SEC CLK_TCK
#endif

#ifndef EXIT_SUCCESS // Successful Exit Program Status
#  define EXIT_SUCCESS 0
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

#if defined(__STDC_VERSION__) && __STDC_VERSION__ <= 199409L // C 1994, ISO/IEC 9899-1:1994
#  ifndef INFINITY
#      ifdef HUGE_VAL
#         define INFINITY HUGE_VAL
#      else
#         define HUGE_VAL ((unsigned long) ~0)
#         define INFINITY ((unsigned long) ~0)
#      endif
#  endif

#  ifndef HUGE_VALF
#      define HUGE_VALF HUGE_VAL
#  endif

#  ifndef HUGE_VALL
#      define HUGE_VALL HUGE_VAL
#  endif

#  ifndef WCHAR_MAX
#  define WCHAR_MAX sizeof(wchar_t)
#  endif

#  ifndef WCHAR_MIN
#  define WCHAR_MIN sizeof(wchar_t)
#  endif
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ <= 199901L // C 1999, ISO/IEC 9899:1999
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ <= 201112L // C 2011, ISO/IEC 9899:2011
#endif

/* C++ Standard Library */
using std::calloc;
using std::malloc;
using std::free;
using std::realloc;

void* _alloca(...);
inline void _freea(...) {}
template <typename... types> inline void* _malloca(types... arguments) { return ::_alloca(arguments...); }

/* C++ Versions */
#if defined(__cplusplus) && __cplusplus <= 199711L // C++ 1998, ISO/IEC 14882:1998
#  define constexpr
#  define inline
#  define noexcept throw()

typedef struct char16_t {
    // [...]
    private:
        // Declaration > Value
        unsigned short value;

    // [...]
    public:
        // [Constructor]
        constexpr inline char16_t(const unsigned short argument) : value{argument} {}
        constexpr inline char16_t(void) : value{} {}
        constexpr inline char16_t(char16_t&& argument) : value{argument.value} {}
        constexpr inline char16_t(const char16_t& argument) : value{argument.value} {}

        // [Operator] > ...
        constexpr inline char16_t& operator =(char16_t&& argument) { this -> value = argument.value; return *this; }
        constexpr inline char16_t& operator =(const char16_t& argument) { this -> value = argument.value; return *this; }
        constexpr inline operator unsigned short(void) const { return this -> value; }
} char16_t;
#  define CHAR16_MAX USHRT_MAX
#  define CHAR16_MIN USHRT_MIN

typedef struct char32_t {
    // [...]
    private:
        // Declaration > Value
        unsigned int value;

    // [...]
    public:
        // [Constructor]
        constexpr inline char32_t(const unsigned int argument) : value{argument} {}
        constexpr inline char32_t(void) : value{} {}
        constexpr inline char32_t(char32_t&& argument) : value{argument.value} {}
        constexpr inline char32_t(const char32_t& argument) : value{argument.value} {}

        // [Operator] > ...
        constexpr inline char32_t& operator =(char32_t&& argument) { this -> value = argument.value; return *this; }
        constexpr inline char32_t& operator =(const char32_t& argument) { this -> value = argument.value; return *this; }
        constexpr inline operator unsigned int(void) const { return this -> value; }
} char32_t;
#  define CHAR32_MAX UINT_MAX
#  define CHAR32_MIN UINT_MIN
#endif

#if defined(__cplusplus) && __cplusplus <= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900) // C++ 2011, ISO/IEC 14882:2011
#endif

#if defined(__cplusplus) && __cplusplus <= 201402L // C++ 2014, ISO/IEC 14882:2014
#endif

#if defined(__cplusplus) && __cplusplus <= 201703L // C++ 2017, ISO/IEC 14882:2017
typedef struct char8_t {
    // [...]
    private:
        // Declaration > Value
        unsigned char value;

    // [...]
    public:
        // [Constructor]
        constexpr inline char8_t(const unsigned char argument) : value{argument} {}
        constexpr inline char8_t(void) : value{} {}
        constexpr inline char8_t(char8_t&& argument) : value{argument.value} {}
        constexpr inline char8_t(const char8_t& argument) : value{argument.value} {}

        // [Operator] > ...
        constexpr inline char8_t& operator =(char8_t&& argument) { this -> value = argument.value; return *this; }
        constexpr inline char8_t& operator =(const char8_t& argument) { this -> value = argument.value; return *this; }
        constexpr inline operator unsigned char(void) const { return this -> value; }
} char8_t;

#  define CHAR8_MAX UCHAR_MAX
#  define CHAR8_MIN UCHAR_MIN
#endif

#if defined(__cplusplus_cli) && __cplusplus_cli == 200406L // Command-Line Interface C++, ECMA-372
#endif

#ifdef __embedded_cplusplus // Embedded C++
#endif
