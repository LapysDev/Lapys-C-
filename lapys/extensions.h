/* ... */
#undef CPP_
#undef CPP_ENDIAN
#undef STANDARD
#undef _PREPROCESSOR
#undef _MSVC_
#
#undef exceptspec_
#undef exceptspec_check_
#undef fail
#undef pass

/* Definition > ... */
// : [C++ Compiler]
# define CPP__CLANG__COMPILER 0x1u
# define CPP__GCC__COMPILER   0x2u
# define CPP__ICC__COMPILER   0x4u
# define CPP__MSVC__COMPILER  0x8u

#if defined(__clang__)
# define CPP_COMPILER CPP__CLANG__COMPILER
#elif defined(__GNUC__)
# define CPP_COMPILER CPP__GCC__COMPILER
#elif defined(__INTEL_COMPILER)
# define CPP_COMPILER CPP__ICC__COMPILER
#elif defined(_MSC_VER)
# define CPP_COMPILER CPP__MSVC__COMPILER
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

// : [C++ Endianness]
# define CPP__BIG__ENDIAN          0x1u
# define CPP__LITTLE__ENDIAN       0x2u
# define CPP__MIXED__ENDIAN        0x4u
# define CPP__WORDS_LITTLE__ENDIAN 0x8u

#ifdef __cpp_lib_endian
# include <bit>
# define CPP_ENDIAN (std::endian::native == std::endian::little ? CPP__LITTLE__ENDIAN : CPP__BIG__ENDIAN)
#else
# if false == defined(CPP_ENDIAN) && defined(__GLIBC__)
#   include <endian.h>
#   ifdef __BYTE_ORDER
#     if defined(__LITTLE_ENDIAN) && __BYTE_ORDER == __LITTLE_ENDIAN
#       define CPP_ENDIAN CPP__LITTLE__ENDIAN
#     elif defined(__BIG_ENDIAN) && __BYTE_ORDER == __BIG_ENDIAN
#       define CPP_ENDIAN CPP__BIG__ENDIAN
#     endif
#   endif
# endif
#
# if false == defined(CPP_ENDIAN) && defined(__GNUC__)
#   ifdef __BYTE_ORDER__
#     if defined(__ORDER_LITTLE_ENDIAN__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#       define CPP_ENDIAN CPP__LITTLE__ENDIAN
#     elif defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#       define CPP_ENDIAN CPP__BIG__ENDIAN
#     endif
#   endif
# endif
#
# ifndef CPP_ENDIAN
#   ifdef __BYTE_ORDER__
#     if defined(_LITTLE_ENDIAN) && false == defined(_BIG_ENDIAN)
#       define CPP_ENDIAN CPP__LITTLE__ENDIAN
#     elif defined(_BIG_ENDIAN) && false == defined(_LITTLE_ENDIAN)
#       define CPP_ENDIAN CPP__BIG__ENDIAN
#     endif
#   endif
# endif
#
# ifndef CPP_ENDIAN
#   if (defined(_MSC_VER) && (defined(_M_ARM) || defined(_M_ARM64))) || (defined(__amd64) || defined(__amd64__) || defined(__bfin__) || defined(__i386__) || defined(__alpha__) || defined(__ia64) || defined(__ia64__) || defined(_M_ALPHA) || defined(_M_AMD64) || defined(_M_IA64) || defined(_M_IX86) || defined(_M_X64) || defined(__x86_64) || defined(__x86_64__))
#     define CPP_ENDIAN CPP__LITTLE__ENDIAN
#   elif defined(__hppa) || defined(__hpux) || defined(_MIPSEB) || defined(_POWER) || defined(__powerpc__) || defined(__ppc__) || defined(_POWER) || defined(__s390__) || defined(__sparc) || defined(__sparc__)
#     define CPP_ENDIAN CPP__BIG__ENDIAN
#   endif
# endif
#
# ifndef CPP_ENDIAN
#   define CPP_ENDIAN (1u == *static_cast<uint8_t const*>(static_cast<void const*>(&static_cast<uint16_t const&>(1u))) ? CPP__LITTLE__ENDIAN : CPP__BIG__ENDIAN)
# endif
#endif

// : [C++ Pre-processor]
#define CPP_STANDARD_PREPROCESSOR 0x1u
#define CPP__MSVC__PREPROCESSOR   0x2u

#if CPP_VERSION < 2011uL
# define CPP_PREPROCESSOR CPP_STANDARD_PREPROCESSOR
#else
# define CPP_PREPROCESSOR CPP_PREPROCESSOR_CHECK(~, _MSVC_)
#   define CPP_PREPROCESSOR_CHECK(...) CPP_PREPROCESSOR_SELECT(__VA_ARGS__)
#   define CPP_PREPROCESSOR_SELECT(arguments, ...) defer(concatenate, defer(concatenate, CPP_, second(arguments, STANDARD, ~)), _PREPROCESSOR)
#endif

// : [C++ Vendor]
# define CPP__APPLE_MACINTOSH__VENDOR   0x01u
# define CPP__LINUX__VENDOR             0x02u
# define CPP__MICROSOFT_WINDOWS__VENDOR 0x04u
# define CPP__NINTENDO__VENDOR          0x08u
# define CPP__UNIX__VENDOR              0x10u

#if defined(__APPLE__) && defined(__MACH__)
# define CPP_VENDOR (CPP__APPLE_MACINTOSH__VENDOR | CPP__UNIX__VENDOR)
#elif defined(__unix) || defined(__unix__)
# define CPP_VENDOR CPP__UNIX__VENDOR
#endif
#
#if defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__)
# define CPP_VENDOR (CPP__LINUX__VENDOR | CPP__UNIX__VENDOR)
#endif
#
#if defined(ARM9) || defined(_3DS) || defined(__SWITCH__)
# define CPP_VENDOR CPP__NINTENDO__VENDOR
#endif
#
#if defined(__NT__) || defined(__TOS_WIN__) || defined(_WIN16) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32_WCE) || defined(_WIN64) || defined(__WINDOWS__)
# define CPP_VENDOR CPP__MICROSOFT_WINDOWS__VENDOR
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
#if CPP_VERSION < 2011uL
# define constenum(type, name, value) enum { name = value }
#else
# define constenum(type, name, value) constexpr type name varinit(value)
#endif

#define constfunc(unrelaxed) constfunc_ ## unrelaxed
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
# define discard
#else
# define discard = delete
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
#   if CPP_COMPILER == CPP__MSVC__COMPILER
#     define exceptspec_fail throw(...)
#     define exceptspec_pass noexcept
#   else
#     define exceptspec_fail
#     define exceptspec_pass noexcept
#   endif
#     define exceptspec_check_true ~, pass
# define noexcept throw()
#else
# define exceptspec(specification) noexcept(specification)
#endif

// : [Forwarding Reference]
#ifdef __cpp_rvalue_references
# define nodecay &&
# define nodecayparam(name) (&&name)
#else
# define nodecay const&
# define nodecayparam(name) const (&name)
#endif

// : [Inheritance Specifier]
#if CPP_VERSION < 2011uL
# define final
#endif

// : [Initialization]
#if CPP_VERSION < 2011uL
# define init(arguments)   (arguments)
# define varinit(arguments) = arguments
#else
# define init(arguments)    {arguments}
# define varinit(arguments) {arguments}
#endif

// : [Return Specifier]
#if CPP_VERSION < 2011uL
# define noignore
#else
# define noignore [[nodiscard]]
#endif

#if CPP_VERSION < 2011uL
# if CPP_COMPILER == CPP__CLANG__COMPILER
#   if __has_attribute(noreturn)
#     define noexit __attribute__((noreturn))
#   else
#     define noexit
#   endif
# elif CPP_COMPILER == CPP__GCC__COMPILER
#     define noexit __attribute__((noreturn))
# elif CPP_COMPILER == CPP__MSVC__COMPILER
#     define noexit __declspec(noreturn)
# else
#     define noexit
# endif
#else
# define noexit [[noreturn]]
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
#ifdef __cpp_ref_qualifiers
# define lref &
# define rref &&
#else
# define lref
# define rref
#endif

// : [Type Alignment Specifier]
#if CPP_VERSION < 2011uL
# if CPP_COMPILER == CPP__MSVC__COMPILER
#  define __alignof_is_defined true
# elif CPP_COMPILER != CPP__CLANG__COMPILER
#  include <stdalign.h>
# endif
#
# ifdef __alignas_is_defined
#  ifdef _Alignas
#    define alignmentas(argument) _Alignas(argument)
#  else
#    define alignmentas(argument) alignas(argument)
#  endif
# else
#   if CPP_COMPILER == CPP__GCC__COMPILER
#     define alignmentas(argument) __attribute__((aligned(argument)))
#   elif CPP_COMPILER == CPP__MSVC__COMPILER
#     define alignmentas(argument) __declspec(align(argument))
#   else
#     define alignmentas(argument)
#   endif
# endif
# ifdef __alignof_is_defined
#   ifdef _Alignof
#     define alignmentof(type) _Alignof(type)
#   else
#     define alignmentof(type) alignof(type)
#   endif
# else
#   if CPP_COMPILER == CPP__GCC__COMPILER
#     define alignmentof(type) __alignof__(type)
#   elif CPP_COMPILER == CPP__MSVC__COMPILER
#     define alignmentof(type) __alignof(type)
#   else
#     define alignmentof(type) sizeof(type)
#   endif
# endif
#else
# define alignmentas(argument)   alignas(argument)
# define alignmentof(type) alignof(type)
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
