/* Deletion > ...
  --- NOTE ---
  #Lapys:
    Remove identifiers unexpectedly `#define`d as macros since these are used in the expansion steps of the following defined macros.
    (explicit removal is not required for the following defined macros which won't quietly fail when re-purposed)
*/
#undef _FORMAT
#undef _MSVC_
#undef CPP_PREPROCESSOR_
#undef STANDARD
#
#undef constfunc__
#undef exceptspec__
#undef exceptspec__check__
#undef fail

/* Definition > ... */
// : [C++ Compiler]
# define CPP__CLANG__COMPILER 0x01u
# define CPP__EDG__COMPILER   0x02u // WARN (Lapys) -> No support planned
# define CPP__GCC__COMPILER   0x04u
# define CPP__ICC__COMPILER   0x08u
# define CPP__MSVC__COMPILER  0x10u

#if defined(__clang__)
# define CPP_COMPILER CPP__CLANG__COMPILER
#elif defined(__GNUC__)
# define CPP_COMPILER CPP__GCC__COMPILER
#elif defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER)
# define CPP_COMPILER CPP__ICC__COMPILER
#elif defined(_MSC_VER)
# define CPP_COMPILER CPP__MSVC__COMPILER
#elif defined(__EDG__)
# define CPP_COMPILER CPP__EDG__COMPILER
#else
# define CPP_COMPILER 0x00u
#endif

// : [C++ Preprocessor]
#if LAPYS_PREPROCESSOR
# if CPP_COMPILER == CPP__CLANG__COMPILER
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wvariadic-macros"
# elif CPP_COMPILER == CPP__GCC__COMPILER
#   pragma GCC system_header
# endif

# define CPP_PREPROCESSOR_FORMAT CPP_PREPROCESSOR_FORMAT__CHECK(~, _MSVC_)
#   define CPP_PREPROCESSOR_STANDARD_FORMAT 0x0u
#     define CPP_PREPROCESSOR__MSVC__FORMAT 0x1u
#   define CPP_PREPROCESSOR_FORMAT__CHECK(...) CPP_PREPROCESSOR_FORMAT__SELECT(__VA_ARGS__)
#   define CPP_PREPROCESSOR_FORMAT__SELECT(arguments, ...) defer(concatenate, defer(concatenate, CPP_PREPROCESSOR_, second(arguments, STANDARD, ~)), _FORMAT)

# if CPP_COMPILER == CPP__CLANG__COMPILER
#    pragma clang diagnostic pop
# endif
#endif

// : [C++ Version]
#if CPP_COMPILER == CPP__MSVC__COMPILER
# ifndef _MSVC_LANG // ->> Assume most universal version
#   define CPP_VERSION 2014uL
# else
#   if   _MSVC_LANG == 201402L
#     define CPP_VERSION 2014uL
#   elif _MSVC_LANG <= 201703L
#     define CPP_VERSION 2017uL
#   elif _MSVC_LANG <= 202002L
#     define CPP_VERSION 2020uL
#   endif
# endif
#endif

#ifndef CPP_VERSION
# ifndef __cplusplus // ->> Assume most universal version
#   define CPP_VERSION 1997uL
# else
#   if   __cplusplus <= 199711L
#     define CPP_VERSION 1997uL
#   elif __cplusplus <= 201103L
#     define CPP_VERSION 2011uL
#   elif __cplusplus <= 201402L
#     define CPP_VERSION 2014uL
#   elif __cplusplus <= 201703L
#     define CPP_VERSION 2017uL
#   elif __cplusplus <= 202002L
#     define CPP_VERSION 2020uL
#   else
#     define CPP_VERSION 2023uL
#   endif
# endif
#endif

// : [C++ Endianness] ->> Possibly runtime value determining environment endianness
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
#   if defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN)
#     if __BYTE_ORDER == __LITTLE_ENDIAN
#       define CPP_ENDIAN CPP__LITTLE__ENDIAN
#     endif
#   elif defined(__BYTE_ORDER) && defined(__BIG_ENDIAN)
#     if __BYTE_ORDER == __BIG_ENDIAN
#       define CPP_ENDIAN CPP__BIG__ENDIAN
#     endif
#   endif
# endif
#
# if false == defined(CPP_ENDIAN) && defined(__GNUC__)
#   if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__)
#     if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#       define CPP_ENDIAN CPP__LITTLE__ENDIAN
#     endif
#   elif defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__)
#     if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#       define CPP_ENDIAN CPP__BIG__ENDIAN
#     endif
#   endif
# endif
#
# if false == defined(CPP_ENDIAN)
#   ifdef __BYTE_ORDER__
#     if defined(_LITTLE_ENDIAN) && false == defined(_BIG_ENDIAN)
#       define CPP_ENDIAN CPP__LITTLE__ENDIAN
#     elif defined(_BIG_ENDIAN) && false == defined(_LITTLE_ENDIAN)
#       define CPP_ENDIAN CPP__BIG__ENDIAN
#     endif
#   endif
# endif
#
# if false == defined(CPP_ENDIAN)
#   if (defined(_MSC_VER) && (defined(_M_ARM) || defined(_M_ARM64))) || (defined(__amd64) || defined(__amd64__) || defined(__bfin__) || defined(__i386__) || defined(__alpha__) || defined(__ia64) || defined(__ia64__) || defined(_M_ALPHA) || defined(_M_AMD64) || defined(_M_IA64) || defined(_M_IX86) || defined(_M_X64) || defined(__x86_64) || defined(__x86_64__))
#     define CPP_ENDIAN CPP__LITTLE__ENDIAN
#   elif defined(__hppa) || defined(__hpux) || defined(_MIPSEB) || defined(_POWER) || defined(__powerpc__) || defined(__ppc__) || defined(_POWER) || defined(__s390__) || defined(__sparc) || defined(__sparc__)
#     define CPP_ENDIAN CPP__BIG__ENDIAN
#   endif
# endif
#
# if false == defined(CPP_ENDIAN)
#   define CPP_ENDIAN (1u == *reinterpret_cast<uint8_t const*>(&static_cast<uint16_t const&>(1u)) ? CPP__LITTLE__ENDIAN : CPP__BIG__ENDIAN)
# endif
#endif

// : [C++ Vendor] ->> Cross-platform awareness
# define CPP__APPLE_MACINTOSH__VENDOR   0x01u
# define CPP__LINUX__VENDOR             0x02u
# define CPP__MICROSOFT_WINDOWS__VENDOR 0x04u
# define CPP__NINTENDO__VENDOR          0x08u
# define CPP__UNIX__VENDOR              0x10u

#if defined(__APPLE__) && defined(__MACH__)
# define CPP_VENDOR (CPP__APPLE_MACINTOSH__VENDOR | CPP__UNIX__VENDOR)
#elif defined(__unix) || defined(__unix__)
# define CPP_VENDOR CPP__UNIX__VENDOR
#elif defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__)
# define CPP_VENDOR (CPP__LINUX__VENDOR | CPP__UNIX__VENDOR)
#elif defined(ARM9) || defined(_3DS) || defined(__SWITCH__)
# define CPP_VENDOR CPP__NINTENDO__VENDOR
#elif defined(__NT__) || defined(__TOS_WIN__) || defined(_WIN16) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32_WCE) || defined(_WIN64) || defined(__WINDOWS__)
# define CPP_VENDOR CPP__MICROSOFT_WINDOWS__VENDOR
#else
# define CPP_VENDOR 0x00u
#endif

/* Definition > ... */
// : [Address Specifier] --- UPDATE (Lapys) -> Must also apply for MSVC before C++20
#if CPP_VERSION < 2020uL
# if CPP_COMPILER == CPP__ICC__COMPILER
#   define nouniqueaddr [[no_unique_address]]
# elif (CPP_COMPILER == CPP__CLANG__COMPILER || CPP_COMPILER == CPP__GCC__COMPILER) && CPP_VERSION >= 2011uL
#   define nouniqueaddr [[no_unique_address]]
# else
#   define nouniqueaddr
# endif
#else
# define nouniqueaddr [[no_unique_address]]
#endif

// : [Constant Enumeration] --- NOTE (Lapys) -> Attempts to define a compile-time constant of a specified integral type
#ifdef __cpp_constexpr
# define constenum(type, name, value) constexpr static type name varinit(value)
#else
# define constenum(type, name, value) enum { name = value }
#endif

// : [Constant Function] --- NOTE (Lapys) -> Attempts to specify a function as compile-time invocable
#define constfunc(unrelaxed) constfunc__ ## unrelaxed
#ifdef __cpp_constexpr
# if CPP_VERSION >= 2014uL || __cpp_constexpr >= 201304L
#   define constfunc__false constexpr
#   define constfunc__true  constexpr
# else
#   define constfunc__false
#   define constfunc__true constexpr
# endif
#else
# define constfunc__false
# define constfunc__true
#endif

// : [Constant Variable] --- NOTE (Lapys) -> Attempts to specify a variable as compile-time
#ifdef __cpp_constexpr
# define constvar constexpr
#else
# define constvar
#endif

// : [Deleted Function Specifier] --- NOTE (Lapys) -> Attempts to mark a function `delete`d
#if CPP_VERSION < 2011uL
# define discard // ->> Leaving the function undefined also works
#else
# define discard = delete
#endif

// : [Exception Operator] --- NOTE (Lapys) -> Attempts to determine if an expression
#if CPP_VERSION < 2011uL
# define exceptof(expression) false
#else
# define exceptof(expression) noexcept(expression)
#endif

// : [Exception Specifier] --- NOTE (Lapys) -> Attempts to explicitly anticipate `throw` in a specified function
#if CPP_VERSION < 2011uL
# define exceptspec(specification) defer(concatenate, exceptspec__, defer(second, exceptspec__check__ ## specification, fail, ~))
#   if CPP_COMPILER == CPP__MSVC__COMPILER
#     define exceptspec__fail throw(...)
#     define exceptspec__pass noexcept
#   else
#     define exceptspec__fail
#     define exceptspec__pass noexcept
#   endif
#     define exceptspec__check__true ~, pass
# define noexcept throw() // ->> Shim the `noexcept` keyword
#else
# define exceptspec(specification) noexcept(specification)
#endif

// : [Forwarding Reference] --- NOTE (Lapys) -> Perfect-forwarding reference-qualification
#ifdef __cpp_rvalue_references
# define nodecay &&
# define nodecayparam(name) (&&name)
#else
# define nodecay const&
# define nodecayparam(name) const (&name)
#endif

// : [Inheritance Specifier] --- NOTE (Lapys) -> Attempt to specify a `class` or `struct` as non-inheritable
#if CPP_VERSION < 2011uL
# define final
#endif

// : [Initialization] --- NOTE (Lapys) -> Common initialization syntax
#ifdef __cpp_aggregate_paren_init
# define init(arguments)    {arguments}
# define nilinit(type)      {}
# define varinit(arguments) {arguments}
#else
# define init(arguments)    (arguments)
# define nilinit(type)      = type()
# define varinit(arguments) = arguments
#endif

// : [Integer Types] --- NOTE (Lapys) -> Acknowledges extended integer types
#if CPP_COMPILER == CPP__CLANG__COMPILER
# define int128_t  __int128_t
# define uint128_t __uint128_t
#elif CPP_COMPILER == CPP__GCC__COMPILER
# ifdef __SIZEOF_INT128__
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wpedantic"
#   define int128_t  __int128
#   define uint128_t unsigned __int128
#   pragma GCC diagnostic pop
# endif
#elif CPP_COMPILER == CPP__ICC__COMPILER
# ifdef __SSE2__
# define int128_t  __i128
# define uint128_t __u128
# endif
#else
# undef int128_t
# undef uint128_t
#endif

// : [Integral Enumeration] --- NOTE (Lapys) -> Attempts to define an `enum` with a specified underlying type
#if CPP_VERSION < 2011uL
# define intenum(type, name) enum name
#else
# define intenum(type, name) enum name : type
#endif

// : [Reference Qualifier] --- NOTE (Lapys) -> Attempts to reference-qualifier
#ifdef __cpp_ref_qualifiers
# define lref &
# define rref &&
#else
# define lref
# define rref
#endif

// : [Return Specifier] --- NOTE (Lapys) -> Attempts to modify certain attributes of specified functions
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

#if CPP_VERSION < 2011uL
# define noignore
#else
# define noignore [[nodiscard]]
#endif

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
#   define noinline // ->> Does not prevent constant-folding
#endif

// : [Type Alignment Specifier] --- NOTE (Lapys) -> Attempt to align members or variables on a specified boundary, or evaluate an acceptable alignment width of a specified type
#if CPP_VERSION < 2011uL
# if CPP_COMPILER == CPP__GCC__COMPILER
#  include <stdalign.h> // ->> since C++11
# elif CPP_COMPILER == CPP__MSVC__COMPILER
#  define __alignof_is_defined true
# endif
#
# ifdef __alignas_is_defined
#  ifdef _Alignas
#    define boundsas(argument) _Alignas(argument)
#  else
#    define boundsas(argument) alignas(argument)
#  endif
# else
#   if CPP_COMPILER == CPP__GCC__COMPILER
#     define boundsas(argument) __attribute__((aligned(argument)))
#   elif CPP_COMPILER == CPP__MSVC__COMPILER
#     define boundsas(argument) __declspec(align(argument))
#   else
#     define boundsas(argument)
#   endif
# endif
#
# ifdef __alignof_is_defined
#   ifdef _Alignof
#     define boundsof(type) _Alignof(type)
#   else
#     define boundsof(type) alignof(type)
#   endif
# else
#   if CPP_COMPILER == CPP__GCC__COMPILER
#     define boundsof(type) __alignof__(type)
#   elif CPP_COMPILER == CPP__MSVC__COMPILER
#     define boundsof(type) __alignof(type)
#   else
#     define boundsof(type) sizeof(type)
#   endif
# endif
#else
# define boundsas(argument) alignas(argument)
# define boundsof(type)     alignof(type)
#endif

// : [Type Inspection Specifier] --- NOTE (Lapys) -> Reflect on the resulting data type of an expression
#ifndef typeof
# if CPP_VERSION < 2011uL
#   if CPP_COMPILER == CPP__CLANG__COMPILER
#     define typeof(expression) __typeof__(expression)
#   elif CPP_COMPILER == CPP__GCC__COMPILER
#     define typeof(expression) __decltype(expression)
#   elif CPP_COMPILER == CPP__ICC__COMPILER
#     define typeof(expression) typeof(expression)
#   elif CPP_COMPILER == CPP__MSVC__COMPILER
#     define typeof(expression) decltype(expression)
#   else
#     error Static type inspection feature `typeof(...)` required
#   endif
# else
#   define typeof(expression) decltype(expression)
# endif
#endif

/* Definition > ... */
// : [...]
#define empty()

#if LAPYS_PREPROCESSOR
# if CPP_COMPILER == CPP__CLANG__COMPILER
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wvariadic-macros"
# elif CPP_COMPILER == CPP__GCC__COMPILER
#   pragma GCC system_header
# endif
  #define concatenate(argument1, argument2) argument1 ## argument2

  #define defer(function, ...) defer_parse(function, (__VA_ARGS__))
  # define defer_parse(function, call) function call

  #define first(argument1, ...) argument1
  #define second(argument1, argument2, ...) argument2

  #undef apply // UPDATE (Lapys) -> Allow for nested `apply(...)`s within `apply(...)`s
  # define apply__begin(function, separator, condition, argument, next, ...)                                       \
    defer(concatenate, apply__condition_is_, condition(argument, next, __VA_ARGS__))(apply__continue, apply__end)( \
      function,                                                                                                    \
      defer(concatenate, apply__condition_is_, condition(next, __VA_ARGS__))(separator, apply__separator),         \
      stall(apply__recurse)()(function, separator, condition, next, __VA_ARGS__, until),                           \
      argument, next, __VA_ARGS__                                                                                  \
    )
  # undef  apply__condition
  #   define apply__condition_accept(condition)   condition
  #   define apply__condition_fallback(condition) apply__condition
  #   define apply__condition_fail() false
  #   define apply__condition_pass() true
  #   define apply__condition_is_false(truthy, falsy) falsy
  #   define apply__condition_is_true(truthy, falsy)  truthy
  #     define apply__condition_found_until       ~, fail
  #     define apply__condition_selection_default ~, fallback
  # define apply__continue(function, separator, applyer, argument, ...) function(argument) separator(argument, __VA_ARGS__) applyer
  # define apply__end(...)
  # define apply__function(argument) argument
  #   define apply__function_accept(function)   function
  #   define apply__function_fallback(function) apply__function
  #     define apply__function_selection_default ~, fallback
  # define apply__separator(...)
  #   define apply__separator_accept(separator)   separator
  #   define apply__separator_fallback(separator) apply__separator
  #     define apply__separator_selection_default ~, fallback
  # undef  apply__setup
  # define apply__recurse() apply__begin
  # if CPP_PREPROCESSOR_FORMAT == CPP_PREPROCESSOR_STANDARD_FORMAT
  #   define apply(...) parse(apply__setup(__VA_ARGS__, until, until, until))
  #     define apply__condition(argument, ...) defer(concatenate, apply__condition_, defer(second, apply__condition_found_ ## argument, pass, ~))()
  #     define apply__setup(function, condition, separator, ...) apply__begin(                                                  \
          defer(concatenate, apply__function_ , defer(second, apply__function_selection_  ## function , accept, ~))(function ), \
          defer(concatenate, apply__separator_, defer(second, apply__separator_selection_ ## separator, accept, ~))(separator), \
          defer(concatenate, apply__condition_, defer(second, apply__condition_selection_ ## condition, accept, ~))(condition), \
          __VA_ARGS__                                                                                                           \
        )
  # elif CPP_PREPROCESSOR_FORMAT == CPP_PREPROCESSOR__MSVC__FORMAT
  #   if CPP_COMPILER == CPP__ICC__COMPILER // ->> No full support planned (ICC is likely *still bugged)
  #     define apply(...) parse(apply__setup(__VA_ARGS__))
  #       define apply__condition(argument, ...) defer(concatenate, apply__condition_, defer(second, apply__condition_found_ ## argument, pass, ~))()
  #       define apply__setup(function, condition, separator, ...) apply__begin(                                                  \
            defer(concatenate, apply__function_ , defer(second, apply__function_selection_  ## function , accept, ~))(function ), \
            defer(concatenate, apply__separator_, defer(second, apply__separator_selection_ ## separator, accept, ~))(separator), \
            defer(concatenate, apply__condition_, defer(second, apply__condition_selection_ ## condition, accept, ~))(condition), \
            __VA_ARGS__, until, until                                                                                             \
          )
  #   else
  #     define apply(...) parse(defer(apply__setup, __VA_ARGS__))
  #       define apply__condition(argument, ...) defer(concatenate, apply__condition_, stall(defer(second, first(apply__condition_found_ ## argument, ~), pass)))()
  #       define apply__setup(function, condition, separator, ...) defer(apply__begin,                                                             \
            stall(defer(concatenate, apply__function_ , defer(second, first(apply__function_selection_  ## function , ~), accept, ~))(function )), \
            stall(defer(concatenate, apply__separator_, defer(second, first(apply__separator_selection_ ## separator, ~), accept, ~))(separator)), \
            stall(defer(concatenate, apply__condition_, defer(second, first(apply__condition_selection_ ## condition, ~), accept, ~))(condition)), \
            __VA_ARGS__, until, until                                                                                                              \
          )
  #   endif
  # endif

  #define parse(...) parse__12(__VA_ARGS__)
  # define parse__1(...)  __VA_ARGS__
  # define parse__2(...)  parse__1(parse__1(__VA_ARGS__))
  # define parse__3(...)  parse__2(parse__2(__VA_ARGS__))
  # define parse__4(...)  parse__3(parse__3(__VA_ARGS__))
  # define parse__5(...)  parse__4(parse__4(__VA_ARGS__))
  # define parse__6(...)  parse__5(parse__5(__VA_ARGS__))
  # define parse__7(...)  parse__6(parse__6(__VA_ARGS__))
  # define parse__8(...)  parse__7(parse__7(__VA_ARGS__))
  # define parse__9(...)  parse__8(parse__8(__VA_ARGS__))
  # define parse__10(...) parse__9(parse__9(__VA_ARGS__))
  # define parse__11(...) parse__10(parse__10(__VA_ARGS__))
  # define parse__12(...) parse__11(parse__11(__VA_ARGS__))

  #define refer(function, ...) function(__VA_ARGS__)

  // #define select(argument) defer(concatenate, select_, defer(second, select_check_ ## argument, fail, ~))(argument)
  // # define select_fail(argument) "`" #argument "`\tfailed selection"
  // # define select_pass(argument) "`" #argument "`\tpassed selection"
  // #   define select_check_anything  ~, pass
  // #   define select_check_literally ~, pass

  #define stall(macro) stall__2(macro)
  # define stall__1(macro) macro empty()
  # define stall__2(macro) macro empty empty()()
# if CPP_COMPILER == CPP__CLANG__COMPILER
#   pragma clang diagnostic pop
# endif
#endif
