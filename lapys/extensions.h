/* ... */
#undef CPP_
#undef _MSVC_
#undef _PREPROCESSOR

/* Definition > ... */
// : [C++ Compiler]
#define CPP_COMPILER true
# define CPP__CLANG__COMPILER false
# define CPP__GCC__COMPILER   false
# define CPP__ICC__COMPILER   false
# define CPP__MSVC__COMPILER  false

#if defined(__clang__)
# undef  CPP__CLANG__COMPILER
# define CPP__CLANG__COMPILER true
#elif defined(__GNUC__)
# undef  CPP__GCC__COMPILER
# define CPP__GCC__COMPILER   true
#elif defined(__INTEL_COMPILER)
# undef  CPP__ICC__COMPILER
# define CPP__ICC__COMPILER   true
#elif defined(_MSC_VER)
# undef  CPP__MSVC__COMPILER
# define CPP__MSVC__COMPILER  true
#endif

// : [C++ Version]
#if CPP_COMPILER == CPP__MSVC__COMPILER
# if   _MSVC_LANG == 201402L
#   define CPP_VERSION 2014uL
# elif _MSVC_LANG <= 201703L
#   define CPP_VERSION 2017uL
# elif _MSVC_LANG <= 202002L
#   define CPP_VERSION 2020uL
# endif
#endif

#ifndef CPP_VERSION
# if   __cplusplus <= 199711L
#   define CPP_VERSION 1997uL
# elif __cplusplus <= 201103L
#   define CPP_VERSION 2011uL
# elif __cplusplus <= 201402L
#   define CPP_VERSION 2014uL
# elif __cplusplus <= 201703L
#   define CPP_VERSION 2017uL
# elif __cplusplus <= 202002L
#   define CPP_VERSION 2020uL
# else
#   define CPP_VERSION 2023uL
# endif
#endif

// : [C++ Pre-processor]
#define CPP_STANDARD_PREPROCESSOR 0u
#define CPP__MSVC__PREPROCESSOR   1u

#if CPP_VERSION < 2011uL
# define CPP_PREPROCESSOR CPP_STANDARD_PREPROCESSOR
#else
# define CPP_PREPROCESSOR CPP_PREPROCESSOR_CHECK(~, _MSVC_)
#   define CPP_PREPROCESSOR_CHECK(...) CPP_PREPROCESSOR_SELECT(__VA_ARGS__)
#   define CPP_PREPROCESSOR_SELECT(arguments, ...) defer(concatenate, defer(concatenate, CPP_, second(arguments, STANDARD, ~)), _PREPROCESSOR)
#endif

// : [C++ Vendor]
#define CPP_VENDOR true
# define CPP__APPLE_MACINTOSH__VENDOR   false
# define CPP__LINUX__VENDOR             false
# define CPP__MICROSOFT_WINDOWS__VENDOR false
# define CPP__NINTENDO__VENDOR          false
# define CPP__UNIX__VENDOR              false

#if defined(__APPLE__) && defined(__MACH__)
# undef  CPP__APPLE_MACINTOSH__VENDOR
# define CPP__APPLE_MACINTOSH__VENDOR true
# undef  CPP__UNIX__VENDOR
# define CPP__UNIX__VENDOR true
#elif defined(__unix) || defined(__unix__)
# undef  CPP__UNIX__VENDOR
# define CPP__UNIX__VENDOR true
#endif
#
#if defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__)
# undef  CPP__LINUX__VENDOR
# define CPP__LINUX__VENDOR true
#endif
#
#if defined(ARM9) || defined(_3DS) || defined(__SWITCH__)
# undef  CPP__NINTENDO__VENDOR
# define CPP__NINTENDO__VENDOR true
#endif
#
#if defined(__NT__) || defined(__TOS_WIN__) || defined(_WIN16) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32_WCE) || defined(_WIN64) || defined(__WINDOWS__)
# undef  CPP__MICROSOFT_WINDOWS__VENDOR
# define CPP__MICROSOFT_WINDOWS__VENDOR true
#endif

/* Definition > ... */
// : [Address Specifier]
#if CPP_VERSION < 2020uL
# if (CPP_COMPILER == CPP__CLANG__COMPILER || CPP_COMPILER == CPP__GCC__COMPILER) && CPP_VERSION >= 2011uL
#   define nouniqueaddr [[no_unique_address]]
# elif CPP_COMPILER == CPP__ICC__COMPILER
#   define nouniqueaddr [[no_unique_address]]
# else
#   define nouniqueaddr
# endif
#else
# define nouniqueaddr [[no_unique_address]]
#endif

// : [Constant Expression]
#define constfunc(strict) constfunc_ ## strict
#if CPP_VERSION < 2011uL
# define constfunc_false
# define constfunc_true
#elif CPP_VERSION < 2014uL
# define constfunc_false
# define constfunc_true constexpr
#else
# define constfunc_false constexpr
# define constfunc_true  constexpr
#endif

#if CPP_VERSION < 2011uL
# define constvar
#else
# define constvar constexpr
#endif

// : [Deleted Function Specifier]
#if CPP_VERSION < 2011uL
# define discard ;
#else
# define discard = delete;
#endif

// : [Exception Operator]
#if CPP_VERSION < 2011uL
# define exceptof(expression) (false)
#else
# define exceptof(...) noexcept(__VA_ARGS__)
#endif

// : [Exception Specifier]
#if CPP_VERSION < 2011uL
# define exceptspec(specification) defer(concatenate, exceptspec_, defer(second, exceptspec_check_ ## specification, fail, ~))
#   define exceptspec_pass noexcept
#   if CPP_COMPILER == CPP__MSVC__COMPILER
#     define exceptspec_fail throw(...)
#   else
#     define exceptspec_fail
#   endif
#     define exceptspec_check_true ~, pass
# define noexcept throw()
#else
# define exceptspec(specification) noexcept(specification)
#endif

// : [Forwarding]
#if CPP_VERSION < 2011uL
# define nodecay const&
#else
# define nodecay &&
#endif

// : [Inheritance Specifier]
#if CPP_VERSION < 2011uL
# define final
#endif

// : [Inline Specifier]
#if CPP_COMPILER == CPP__CLANG__COMPILER
# if __has_attribute(noinline)
#   define noinline __attribute__((noinline))
# else
#   define noinline
# endif
#elif CPP_COMPILER == CPP__GCC__COMPILER || CPP_COMPILER == CPP__ICC__COMPILER
#   define noinline __attribute__((noinline))
#elif CPP_COMPILER == CPP__MSVC__COMPILER
#   define noinline __declspec(noinline)
#else
#   define noinline
#endif

// : [Reference Qualifier]
#if CPP_VERSION < 2011uL
# define lvalue
# define rvalue
#else
# define lvalue &
# define rvalue &&
#endif

// : [Return Specifier]
#if CPP_VERSION < 2011uL
# if CPP_COMPILER == CPP__CLANG__COMPILER
#   if __has_attribute(noreturn)
#     define noreturn __attribute__((noreturn))
#   else
#     define noreturn
#   endif
# elif CPP_COMPILER == CPP__GCC__COMPILER
#     define noreturn __attribute__((noreturn))
# elif CPP_COMPILER == CPP__MSVC__COMPILER
#     define noreturn __declspec(noreturn)
# else
#     define noreturn
# endif
#else
# define noreturn [[noreturn]]
#endif

// : [Type Inspection Specifier]
#if CPP_COMPILER == CPP__CLANG__COMPILER
# if defined(__typeof__)
#   define typeof(expression) __typeof__(expression)
# elif defined(__typeof)
#   define typeof(expression) __typeof(expression)
# endif
#elif CPP_COMPILER == CPP__GCC__COMPILER
# define typeof(expression) __decltype(expression)
#elif CPP_COMPILER == CPP__ICC__COMPILER
# define typeof(expression) typeof(expression)
#elif CPP_COMPILER == CPP__MSVC__COMPILER
# define typeof(expression) decltype(expression)
#endif
