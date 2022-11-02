#ifndef LAPYS_MODULE_EXTENSIONS
# define LAPYS_MODULE_EXTENSIONS
  /* Deletion
    --- NOTE ---
    #Lapys:
      Remove identifiers unexpectedly `#define`d as macros since these are used in the expansion steps of the following defined macros.
      (explicit removal is not required for the following defined macros which won't quietly fail when re-purposed)
  */
  #undef _FORMAT
  #undef choose_
  #undef constfunc_
  #undef CPP_PREPROCESSOR_
  #undef MSVC
  #undef STANDARD

  /* Definition */
  // : [C++ Compiler]
  # define CPP_CIRCLE_COMPILER 0x01u
  # define CPP_CLANG_COMPILER  0x02u
  # define CPP_EDG_COMPILER    0x03u // WARN (Lapys) -> No support planned
  # define CPP_GCC_COMPILER    0x04u
  # define CPP_ICC_COMPILER    0x05u
  # define CPP_MSVC_COMPILER   0x06u

  #if defined(__circle_lang__)
  # define CPP_COMPILER CPP_CIRCLE_COMPILER
  #elif defined(__clang__)
  # define CPP_COMPILER CPP_CLANG_COMPILER
  #elif defined(__ICC) || defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER)
  # define CPP_COMPILER CPP_ICC_COMPILER
  #elif defined(__GNUC__)
  # define CPP_COMPILER CPP_GCC_COMPILER
  #elif defined(_MSC_VER)
  # define CPP_COMPILER CPP_MSVC_COMPILER
  #elif defined(__EDG__)
  # define CPP_COMPILER CPP_EDG_COMPILER
  #else
  # define CPP_COMPILER 0x00u
  #endif

  // : [C++ Version]
  #if CPP_COMPILER == CPP_MSVC_COMPILER
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

  /* ... */
  #if CPP_VERSION >= 2020uL || (CPP_COMPILER == CPP__CLANG__COMPILER || CPP_COMPILER == CPP__GCC__COMPILER || CPP_COMPILER == CPP__ICC__COMPILER || CPP_COMPILER == CPP__MSVC__COMPILER)
  # include <version>
  #endif

  /* Definition */
  // : [C++ Preprocessor]
  #if LAPYS_PREPROCESSOR
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   pragma clang diagnostic push
  #   pragma clang diagnostic ignored "-Wvariadic-macros"
  # elif CPP_COMPILER == CPP_GCC_COMPILER
  #   pragma GCC system_header
  # endif

  # define CPP_PREPROCESSOR_FORMAT CPP_PREPROCESSOR_FORMAT_CHECK(~, MSVC)
  #   define CPP_PREPROCESSOR_STANDARD_FORMAT 0x0u
  #     define CPP_PREPROCESSOR_MSVC_FORMAT 0x1u
  #   define CPP_PREPROCESSOR_FORMAT_CHECK(...) CPP_PREPROCESSOR_FORMAT_SELECT(__VA_ARGS__)
  #   define CPP_PREPROCESSOR_FORMAT_SELECT(arguments, ...) defer(combine, defer(combine, CPP_PREPROCESSOR_, choose(2u, arguments, STANDARD, ~)), _FORMAT)

  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #    pragma clang diagnostic pop
  # endif
  #endif

  // : [C++ Vendor] ->> Cross-platform awareness
  # define CPP_APPLE_MACINTOSH_VENDOR   0x01u
  # define CPP_CYGWIN_VENDOR            0x02u
  # define CPP_HAIKU_VENDOR             0x04u
  # define CPP_LINUX_VENDOR             0x08u
  # define CPP_MICROSOFT_WINDOWS_VENDOR 0x10u
  # define CPP_NINTENDO_VENDOR          0x20u
  # define CPP_UNIX_VENDOR              0x40u

  #if defined(__APPLE__) || defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) || defined(__MACH__)
  # define CPP_VENDOR (CPP_APPLE_MACINTOSH_VENDOR | CPP_UNIX_VENDOR)
  #elif defined(__CYGWIN__)
  # define CPP_VENDOR (CPP_CYGWIN_VENDOR | CPP_UNIX_VENDOR)
  #elif defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__)
  # define CPP_VENDOR (CPP_LINUX_VENDOR | CPP_UNIX_VENDOR)
  #elif defined(__HAIKU__)
  # define CPP_VENDOR CPP_HAIKU_VENDOR
  #elif defined(_3DS) || defined(__SWITCH__)
  # define CPP_VENDOR CPP_NINTENDO_VENDOR
  #elif defined(__NT__) || defined(__TOS_WIN__) || defined(__WIN32__) || defined(__WINDOWS__) || defined(_WIN16) || defined(_WIN32) || defined(_WIN32_WCE) || defined(_WIN64)
  # define CPP_VENDOR CPP_MICROSOFT_WINDOWS_VENDOR
  #elif defined(__bsdi__) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__FreeBSD_version) || defined(__NETBSD__) || defined(__NETBSD_version) || defined(NetBSD0_8) || defined(NetBSD0_9) || defined(NetBSD1_0) || defined(__OpenBSD__) || defined(OpenBSD2_0) || defined(OpenBSD2_1) || defined(OpenBSD2_2) || defined(OpenBSD2_3) || defined(OpenBSD2_4) || defined(OpenBSD2_5) || defined(OpenBSD2_6) || defined(OpenBSD2_7) || defined(OpenBSD2_8) || defined(OpenBSD2_9) || defined(OpenBSD3_0) || defined(OpenBSD3_1) || defined(OpenBSD3_2) || defined(OpenBSD3_3) || defined(OpenBSD3_4) || defined(OpenBSD3_5) || defined(OpenBSD3_6) || defined(OpenBSD3_7) || defined(OpenBSD3_8) || defined(OpenBSD3_9) || defined(OpenBSD4_0) || defined(OpenBSD4_1) || defined(OpenBSD4_2) || defined(OpenBSD4_3) || defined(OpenBSD4_4) || defined(OpenBSD4_5) || defined(OpenBSD4_6) || defined(OpenBSD4_7) || defined(OpenBSD4_8) || defined(OpenBSD4_9) || defined(__OS400__) || defined(__unix) || defined(__unix__) || defined(_POSIX_SOURCE) || defined(_XOPEN_SOURCE) || defined(__QNX__) || defined(__QNXNTO__) || defined(_NTO_VERSION) || defined(sun) || defined(__sun) || defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4) || defined(VMS) || defined(__VMS) || defined(__VMS_VER) || defined(unix)
  # define CPP_VENDOR CPP_UNIX_VENDOR
  #elif defined(WIN32)
  # define CPP_VENDOR CPP_MICROSOFT_WINDOWS_VENDOR
  #else
  # define CPP_VENDOR 0x00u
  #endif

  // : [C++ Endianness] ->> Possibly runtime value determining environment endianness
  #define CPP_ENDIAN_RUNTIME false
  # define CPP_BYTE_BIG_ENDIAN    0x01u
  # define CPP_BYTE_LITTLE_ENDIAN 0x02u
  # define CPP_MIXED_ENDIAN       0x04u
  # define CPP_WORD_BIG_ENDIAN    0x08u
  # define CPP_WORD_LITTLE_ENDIAN 0x10u

  #if defined(__APPLE__) || defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) || defined(__MACH__) || defined(__OpenBSD__) || defined(OpenBSD2_0) || defined(OpenBSD2_1) || defined(OpenBSD2_2) || defined(OpenBSD2_3) || defined(OpenBSD2_4) || defined(OpenBSD2_5) || defined(OpenBSD2_6) || defined(OpenBSD2_7) || defined(OpenBSD2_8) || defined(OpenBSD2_9) || defined(OpenBSD3_0) || defined(OpenBSD3_1) || defined(OpenBSD3_2) || defined(OpenBSD3_3) || defined(OpenBSD3_4) || defined(OpenBSD3_5) || defined(OpenBSD3_6) || defined(OpenBSD3_7) || defined(OpenBSD3_8) || defined(OpenBSD3_9) || defined(OpenBSD4_0) || defined(OpenBSD4_1) || defined(OpenBSD4_2) || defined(OpenBSD4_3) || defined(OpenBSD4_4) || defined(OpenBSD4_5) || defined(OpenBSD4_6) || defined(OpenBSD4_7) || defined(OpenBSD4_8) || defined(OpenBSD4_9)
  # include <machine/endian.h>
  #elif defined(__bsdi__) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__FreeBSD_version) || defined(__NETBSD__) || defined(__NETBSD_version) || defined(NetBSD0_8) || defined(NetBSD0_9) || defined(NetBSD1_0) || defined(__OpenBSD__) || defined(OpenBSD2_0) || defined(OpenBSD2_1) || defined(OpenBSD2_2) || defined(OpenBSD2_3) || defined(OpenBSD2_4) || defined(OpenBSD2_5) || defined(OpenBSD2_6) || defined(OpenBSD2_7) || defined(OpenBSD2_8) || defined(OpenBSD2_9) || defined(OpenBSD3_0) || defined(OpenBSD3_1) || defined(OpenBSD3_2) || defined(OpenBSD3_3) || defined(OpenBSD3_4) || defined(OpenBSD3_5) || defined(OpenBSD3_6) || defined(OpenBSD3_7) || defined(OpenBSD3_8) || defined(OpenBSD3_9) || defined(OpenBSD4_0) || defined(OpenBSD4_1) || defined(OpenBSD4_2) || defined(OpenBSD4_3) || defined(OpenBSD4_4) || defined(OpenBSD4_5) || defined(OpenBSD4_6) || defined(OpenBSD4_7) || defined(OpenBSD4_8) || defined(OpenBSD4_9)
  # include <sys/endian.h>
  #endif

  #ifdef __cpp_lib_endian
  # include <bit>
  # define CPP_ENDIAN (std::endian::native == std::endian::little ? CPP_BYTE_LITTLE_ENDIAN : CPP_BYTE_BIG_ENDIAN)
  #else
  # if CPP_VENDOR & CPP_APPLE_MACINTOSH_VENDOR
  #   include <machine/endian.h>
  # elif defined(__CYGWIN__) || defined(__GLIBC__) || defined(__gnu_linux__) || defined(__linux) || defined(__linux__) || defined(__QNX__) || defined(__QNXNTO__) || defined(__sun) || defined(__SVR4) || defined(__svr4__) || defined(__sysv__) || defined(__unix) || defined(__unix__) || defined(__VMS) || defined(__VMS_VER) || defined(_NTO_VERSION) || defined(_POSIX_SOURCE) || defined(_SYSTYPE_SVR4) || defined(_XOPEN_SOURCE) || defined(linux) || defined(sun) || defined(unix) || defined(VMS)
  #   include <endian.h>
  # elif defined(__bsdi__) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__FreeBSD_version) || defined(__NETBSD__) || defined(__NETBSD_version) || defined(NetBSD0_8) || defined(NetBSD0_9) || defined(NetBSD1_0) || defined(__OpenBSD__) || defined(OpenBSD2_0) || defined(OpenBSD2_1) || defined(OpenBSD2_2) || defined(OpenBSD2_3) || defined(OpenBSD2_4) || defined(OpenBSD2_5) || defined(OpenBSD2_6) || defined(OpenBSD2_7) || defined(OpenBSD2_8) || defined(OpenBSD2_9) || defined(OpenBSD3_0) || defined(OpenBSD3_1) || defined(OpenBSD3_2) || defined(OpenBSD3_3) || defined(OpenBSD3_4) || defined(OpenBSD3_5) || defined(OpenBSD3_6) || defined(OpenBSD3_7) || defined(OpenBSD3_8) || defined(OpenBSD3_9) || defined(OpenBSD4_0) || defined(OpenBSD4_1) || defined(OpenBSD4_2) || defined(OpenBSD4_3) || defined(OpenBSD4_4) || defined(OpenBSD4_5) || defined(OpenBSD4_6) || defined(OpenBSD4_7) || defined(OpenBSD4_8) || defined(OpenBSD4_9) || defined(__OS400__) || defined(__unix)
  #   include <sys/endian.h>
  # endif
  #
  #
  # if false == defined(CPP_ENDIAN) && defined(__GLIBC__)
  #   if defined(_BYTE_ORDER)
  #     if defined(_LITTLE_ENDIAN)
  #       if _BYTE_ORDER == _LITTLE_ENDIAN
  #         define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #       endif
  #     elif defined(_BIG_ENDIAN)
  #       if _BYTE_ORDER == _BIG_ENDIAN
  #         define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #       endif
  #     elif defined(_PDP_ENDIAN)
  #       if _BYTE_ORDER == _PDP_ENDIAN
  #         define CPP_ENDIAN CPP_WORD_LITTLE_ENDIAN
  #       endif
  #     endif
  #   elif defined(__BYTE_ORDER)
  #     if defined(__LITTLE_ENDIAN)
  #       if __BYTE_ORDER == __LITTLE_ENDIAN
  #         define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #       endif
  #     elif defined(__BIG_ENDIAN)
  #       if __BYTE_ORDER == __BIG_ENDIAN
  #         define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #       endif
  #     elif defined(__PDP_ENDIAN)
  #       if __BYTE_ORDER == __PDP_ENDIAN
  #         define CPP_ENDIAN CPP_WORD_LITTLE_ENDIAN
  #       endif
  #     endif
  #   endif
  # endif
  #
  # if false == defined(CPP_ENDIAN) && defined(__GNUC__)
  #   ifdef __BYTE_ORDER__
  #     if defined(__ORDER_LITTLE_ENDIAN__)
  #       if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  #         define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #       endif
  #     elif defined(__ORDER_BIG_ENDIAN__)
  #       if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  #         define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #       endif
  #     elif defined(__ORDER_PDP_ENDIAN__)
  #       if __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
  #         define CPP_ENDIAN CPP_WORD_LITTLE_ENDIAN
  #       endif
  #     endif
  #   endif
  # endif
  #
  # if false == defined(CPP_ENDIAN)
  #   if (defined(__LITTLE_ENDIAN__) && false == defined(__BIG_ENDIAN__)) || (defined(_LITTLE_ENDIAN) && false == defined(_BIG_ENDIAN))
  #     define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #   elif (defined(__BIG_ENDIAN__) && false == defined(__LITTLE_ENDIAN__)) || (defined(_BIG_ENDIAN) && false == defined(_LITTLE_ENDIAN))
  #     define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #   endif
  # endif
  #
  # if false == defined(CPP_ENDIAN)
  #   if defined(__AARCH64EL__) || defined(__ARMEL__) || defined(__MIPSEL) || defined(__MIPSEL__) || defined(__THUMBEL__) || defined(_MIPSEL)
  #     define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #   elif defined(__AARCH64EB__) || defined(__ARMEB__) || defined(__MIPSEB) || defined(__MIPSEB__) || defined(__THUMBEB__) || defined(_MIPSEB)
  #     define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #   endif
  # endif
  #
  # if false == defined(CPP_ENDIAN)
  #   if defined(__alpha__) || defined(__amd64) || defined(__amd64) || defined(__amd64__) || defined(__amd64__) || defined(__bfin__) || defined(__BFIN__) || defined(__i386) || defined(__i386__) || defined(__i486__) || defined(__i486__) || defined(__i586__) || defined(__i586__) || defined(__i686__) || defined(__I86__) || defined(__ia64) || defined(__ia64__) || defined(__IA64__) || defined(__INTEL__) || defined(__itanium__) || defined(__THW_INTEL__) || defined(__x86_64) || defined(__x86_64__) || defined(_IA64) || defined(_M_ALPHA) || defined(_M_AMD64) || defined(_M_IA64) || defined(_M_IX86) || defined(_M_X64) || defined(_X86_) || defined(bfin) || defined(BFIN) || defined(i386) || ((CPP_VENDOR & CPP_MICROSOFT_WINDOWS_VENDOR) && (defined(__arm64) || defined(__arm__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(__thumb__) || defined(_M_ARM)))
  #     define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #   elif defined(__370__) || defined(__hppa) || defined(__hpux) || defined(__m68k__) || defined(__mc68000) || defined(__mc68000__) || defined(__mc68010) || defined(__mc68010__) || defined(__mc68020) || defined(__mc68020__) || defined(__mc68030) || defined(__mc68030__) || defined(__mc68040) || defined(__mc68040__) || defined(__mc68060) || defined(__mc68060__) || defined(__powerpc__) || defined(__ppc__) || defined(__s390__) || defined(__s390__) || defined(__s390x__) || defined(__sparc) || defined(__sparc__) || defined(__sparcv8) || defined(__sparcv9) || defined(__SYSC_ZARCH__) || defined(__THW_370__) || defined(_POWER) || defined(M68000) || defined(mc68000) || defined(mc68010) || defined(mc68020) || defined(mc68030) || defined(mc68040) || defined(mc68060)
  #     define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #   endif
  # endif
  #
  # if false == defined(CPP_ENDIAN)
  #   undef  CPP_ENDIAN_RUNTIME
  #   define CPP_ENDIAN_RUNTIME true
  #   if CPP_VERSION < 2011uL
  #     define CPP_ENDIAN sizeof(unsigned char) == sizeof(unsigned long)      || (1u == reinterpret_cast<unsigned char const&>(static_cast<unsigned long const&>(1u))      ? CPP_BYTE_LITTLE_ENDIAN : CPP_BYTE_BIG_ENDIAN)
  #   else
  #     define CPP_ENDIAN sizeof(unsigned char) == sizeof(unsigned long long) || (1u == reinterpret_cast<unsigned char const&>(static_cast<unsigned long long const&>(1u)) ? CPP_BYTE_LITTLE_ENDIAN : CPP_BYTE_BIG_ENDIAN)
  #   endif
  # endif
  #endif

  /* Definition */
  // : [Address Specifier]
  #if CPP_COMPILER == CPP_MSVC_COMPILER
  # pragma warning(disable: 4848)
  # define nouniqueaddr [[msvc::no_unique_address]]
  #elif CPP_VERSION < 2020uL
  # if CPP_COMPILER == CPP_ICC_COMPILER
  #   define nouniqueaddr [[no_unique_address]]
  # elif (CPP_COMPILER == CPP_CLANG_COMPILER || CPP_COMPILER == CPP_GCC_COMPILER) && CPP_VERSION >= 2011uL
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
  #elif CPP_VERSION >= 2011uL
  # define constenum(type, name, value) enum : type { name = value }
  #else
  # define constenum(type, name, value) enum { name = value }
  #endif

  // : [Constant Function] --- NOTE (Lapys) -> Attempts to make a function callable in a constant evaluated context
  #define constfunc(unrelaxed) constfunc_ ## unrelaxed
  #ifdef __cpp_constexpr
  # if CPP_VERSION >= 2014uL || __cpp_constexpr >= 201304L
  #   define constfunc_false constexpr
  #   define constfunc_true  constexpr
  # else
  #   define constfunc_false
  #   define constfunc_true constexpr
  # endif
  #else
  # define constfunc_false
  # define constfunc_true
  #endif

  // : [Constant Variable] --- NOTE (Lapys) -> Attempts to specify a variable as compile-time
  #ifdef __cpp_constexpr
  # define constvar constexpr
  #else
  # define constvar
  #endif

  // : [Deleted Function Specifier] --- NOTE (Lapys) -> Attempts to mark a function `delete`d
  #if CPP_VERSION < 2011uL
  # define discard // ->> Leaving the function undefined mostly also works
  #else
  # define discard = delete
  #endif

  // : [Exception Operator] --- NOTE (Lapys) -> Attempts to determine if an expression can `throw` an exception
  #if CPP_VERSION < 2011uL
  # define exceptof(expression) false
  #else
  # define exceptof(expression) noexcept(expression)
  #endif

  // : [Exception Specifier] --- NOTE (Lapys) -> Attempts to explicitly anticipate `throw` in a specified function
  #if CPP_VERSION < 2011uL
  # define exceptspec(specification) choose(specification, exceptspec_true, exceptspec_false)
  #   if CPP_COMPILER == CPP_MSVC_COMPILER
  #     define exceptspec_false throw(...)
  #     define exceptspec_true  noexcept
  #   else
  #     define exceptspec_false
  #     define exceptspec_true noexcept
  #   endif
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

  // : [Integer Types] --- NOTE (Lapys) -> Acknowledges extended integer types --- WARN (Lapys) -> Not intended to be type definitions
  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # define int128_t  __int128_t
  # define uint128_t __uint128_t
  #elif CPP_COMPILER == CPP_GCC_COMPILER
  # ifdef __SIZEOF_INT128__
  #   pragma GCC diagnostic push
  #   pragma GCC diagnostic ignored "-Wpedantic"
  #   define int128_t           __int128
  #   define uint128_t unsigned __int128
  #   pragma GCC diagnostic pop
  # endif
  #elif CPP_COMPILER == CPP_ICC_COMPILER
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

  // : [Pointer Nullity]
  #if CPP_VERSION < 2011uL
  # define nullptr NULL
  #endif

  // : [Reference Qualifier] --- NOTE (Lapys) -> Attempts to reference-qualify
  #ifdef __cpp_ref_qualifiers
  # define lref &
  # define rref &&
  #else
  # define lref
  # define rref
  #endif

  // : [Return Specifier] --- NOTE (Lapys) -> Attempts to modify certain attributes of specified functions
  #if CPP_COMPILER == CPP_CLANG_COMPILER || CPP_COMPILER == CPP_GCC_COMPILER
  # define mustinline __attribute__((always_inline))
  #elif CPP_COMPILER == CPP_ICC_COMPILER || CPP_COMPILER == CPP_MSVC_COMPILER
  # define mustinline __forceinline
  #else
  # define mustinline inline
  #endif

  #if CPP_VERSION < 2011uL
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   define noexit _Noreturn
  # elif CPP_COMPILER == CPP_GCC_COMPILER
  #   define noexit __attribute__((noreturn))
  # elif CPP_COMPILER == CPP_MSVC_COMPILER
  #   define noexit __declspec(noreturn)
  # else
  #   define noexit
  # endif
  #else
  # define noexit [[noreturn]]
  #endif

  #if CPP_VERSION < 2011uL
  # if CPP_COMPILER == CPP_CLANG_COMPILER || CPP_COMPILER == CPP_GCC_COMPILER
  #   define noignore __attribute__((warn_unused_result))
  # else
  #   define noignore
  # endif
  #else
  # define noignore [[nodiscard]]
  #endif

  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # if CPP_COMPILER >= 2011uL
  #   define noinline [[clang::noinline]]
  # elif __has_attribute(noinline)
  #   define noinline __attribute__((noinline))
  # else
  #   define noinline
  # endif
  #elif CPP_COMPILER == CPP_GCC_COMPILER || CPP_COMPILER == CPP_ICC_COMPILER
  #   define noinline __attribute__((noinline))
  #elif CPP_COMPILER == CPP_MSVC_COMPILER
  #   define noinline __declspec(noinline)
  #else
  #   define noinline // ->> Does not prevent constant-folding
  #endif

  // : [Type Alignment Specifier] --- NOTE (Lapys) -> Attempt to align members or variables on a specified boundary, or evaluate an acceptable alignment width of a specified type
  #if CPP_VERSION < 2011uL
  # if CPP_COMPILER == CPP_GCC_COMPILER
  #  include <stdalign.h> // ->> since C++11
  # elif CPP_COMPILER == CPP_MSVC_COMPILER
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
  #   if CPP_COMPILER == CPP_GCC_COMPILER
  #     define boundsas(argument) __attribute__((aligned(argument)))
  #   elif CPP_COMPILER == CPP_MSVC_COMPILER
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
  #   if CPP_COMPILER == CPP_GCC_COMPILER
  #     define boundsof(type) __alignof__(type)
  #   elif CPP_COMPILER == CPP_MSVC_COMPILER
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
  #   if CPP_COMPILER == CPP_CLANG_COMPILER
  #     define typeof(expression) __typeof__(expression)
  #   elif CPP_COMPILER == CPP_GCC_COMPILER
  #     define typeof(expression) __decltype(expression)
  #   elif CPP_COMPILER == CPP_ICC_COMPILER
  #     define typeof(expression) typeof(expression)
  #   elif CPP_COMPILER == CPP_MSVC_COMPILER
  #     define typeof(expression) decltype(expression)
  #   else
  #     error Static type inspection feature `typeof(...)` required
  #   endif
  # else
  #   if CPP_COMPILER == CPP_CLANG_COMPILER
  #     pragma clang diagnostic push
  #     pragma clang diagnostic ignored "-Wkeyword-macro"
  #   endif
  #   define typeof(expression) decltype(expression)
  #   if CPP_COMPILER == CPP_CLANG_COMPILER
  #     pragma clang diagnostic pop
  #   endif
  # endif
  #endif

  /* Definition */
  #define choose(argument, truthy, falsy) defer(combine, choose_, argument)(truthy, falsy)
  # define choose_false(truthy, falsy) falsy
  # define choose_true(truthy, falsy)  truthy

  #define empty()

  #if (LAPYS_MAX_ARITY) > 127u
  # undef LAPYS_MAX_ARITY
  # define LAPYS_MAX_ARITY 127u
  #endif

  #if LAPYS_PREPROCESSOR
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   pragma clang diagnostic push
  #   pragma clang diagnostic ignored "-Wc++20-compat"
  #   pragma clang diagnostic ignored "-Wvariadic-macros"
  # elif CPP_COMPILER == CPP_GCC_COMPILER
  #   pragma GCC diagnostic push
  #   pragma GCC diagnostic ignored "-Wvariadic-macros"
  #   pragma GCC system_header
  # endif
    #if (LAPYS_MAX_ARITY) >= 1u
    # define arity_1u 1u
    #endif
    #if (LAPYS_MAX_ARITY) >= 2u
    # define arity_2u 1u, 2u
    #endif
    #if (LAPYS_MAX_ARITY) >= 3u
    # define arity_3u 1u, 2u, 3u
    # define choose_3u(argument1, argument2, argument3, ...) argument3
    #endif
    #if (LAPYS_MAX_ARITY) >= 4u
    # define arity_4u 1u, 2u, 3u, 4u
    # define choose_4u(argument1, argument2, argument3, argument4, ...) argument4
    #endif
    #if (LAPYS_MAX_ARITY) >= 5u
    # define arity_5u 1u, 2u, 3u, 4u, 5u
    # define choose_5u(argument1, argument2, argument3, argument4, argument5, ...) argument5
    #endif
    #if (LAPYS_MAX_ARITY) >= 6u
    # define arity_6u 1u, 2u, 3u, 4u, 5u, 6u
    # define choose_6u(argument1, argument2, argument3, argument4, argument5, argument6, ...) argument6
    #endif
    #if (LAPYS_MAX_ARITY) >= 7u
    # define arity_7u 1u, 2u, 3u, 4u, 5u, 6u, 7u
    # define choose_7u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, ...) argument7
    #endif
    #if (LAPYS_MAX_ARITY) >= 8u
    # define arity_8u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u
    # define choose_8u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, ...) argument8
    #endif
    #if (LAPYS_MAX_ARITY) >= 9u
    # define arity_9u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u
    # define choose_9u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, ...) argument9
    #endif
    #if (LAPYS_MAX_ARITY) >= 10u
    # define arity_10u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u
    # define choose_10u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, ...) argument10
    #endif
    #if (LAPYS_MAX_ARITY) >= 11u
    # define arity_11u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u
    # define choose_11u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, ...) argument11
    #endif
    #if (LAPYS_MAX_ARITY) >= 12u
    # define arity_12u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u
    # define choose_12u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, ...) argument12
    #endif
    #if (LAPYS_MAX_ARITY) >= 13u
    # define arity_13u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u
    # define choose_13u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, ...) argument13
    #endif
    #if (LAPYS_MAX_ARITY) >= 14u
    # define arity_14u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u
    # define choose_14u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, ...) argument14
    #endif
    #if (LAPYS_MAX_ARITY) >= 15u
    # define arity_15u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u
    # define choose_15u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, ...) argument15
    #endif
    #if (LAPYS_MAX_ARITY) >= 16u
    # define arity_16u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u
    # define choose_16u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, ...) argument16
    #endif
    #if (LAPYS_MAX_ARITY) >= 17u
    # define arity_17u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u
    # define choose_17u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, ...) argument17
    #endif
    #if (LAPYS_MAX_ARITY) >= 18u
    # define arity_18u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u
    # define choose_18u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, ...) argument18
    #endif
    #if (LAPYS_MAX_ARITY) >= 19u
    # define arity_19u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u
    # define choose_19u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, ...) argument19
    #endif
    #if (LAPYS_MAX_ARITY) >= 20u
    # define arity_20u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u
    # define choose_20u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, ...) argument20
    #endif
    #if (LAPYS_MAX_ARITY) >= 21u
    # define arity_21u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u
    # define choose_21u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, ...) argument21
    #endif
    #if (LAPYS_MAX_ARITY) >= 22u
    # define arity_22u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u
    # define choose_22u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, ...) argument22
    #endif
    #if (LAPYS_MAX_ARITY) >= 23u
    # define arity_23u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u
    # define choose_23u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, ...) argument23
    #endif
    #if (LAPYS_MAX_ARITY) >= 24u
    # define arity_24u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u
    # define choose_24u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, ...) argument24
    #endif
    #if (LAPYS_MAX_ARITY) >= 25u
    # define arity_25u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u
    # define choose_25u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, ...) argument25
    #endif
    #if (LAPYS_MAX_ARITY) >= 26u
    # define arity_26u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u
    # define choose_26u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, ...) argument26
    #endif
    #if (LAPYS_MAX_ARITY) >= 27u
    # define arity_27u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u
    # define choose_27u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, ...) argument27
    #endif
    #if (LAPYS_MAX_ARITY) >= 28u
    # define arity_28u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u
    # define choose_28u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, ...) argument28
    #endif
    #if (LAPYS_MAX_ARITY) >= 29u
    # define arity_29u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u
    # define choose_29u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, ...) argument29
    #endif
    #if (LAPYS_MAX_ARITY) >= 30u
    # define arity_30u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u
    # define choose_30u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, ...) argument30
    #endif
    #if (LAPYS_MAX_ARITY) >= 31u
    # define arity_31u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u
    # define choose_31u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, ...) argument31
    #endif
    #if (LAPYS_MAX_ARITY) >= 32u
    # define arity_32u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u
    # define choose_32u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, ...) argument32
    #endif
    #if (LAPYS_MAX_ARITY) >= 33u
    # define arity_33u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u
    # define choose_33u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, ...) argument33
    #endif
    #if (LAPYS_MAX_ARITY) >= 34u
    # define arity_34u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u
    # define choose_34u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, ...) argument34
    #endif
    #if (LAPYS_MAX_ARITY) >= 35u
    # define arity_35u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u
    # define choose_35u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, ...) argument35
    #endif
    #if (LAPYS_MAX_ARITY) >= 36u
    # define arity_36u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u
    # define choose_36u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, ...) argument36
    #endif
    #if (LAPYS_MAX_ARITY) >= 37u
    # define arity_37u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u
    # define choose_37u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, ...) argument37
    #endif
    #if (LAPYS_MAX_ARITY) >= 38u
    # define arity_38u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u
    # define choose_38u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, ...) argument38
    #endif
    #if (LAPYS_MAX_ARITY) >= 39u
    # define arity_39u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u
    # define choose_39u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, ...) argument39
    #endif
    #if (LAPYS_MAX_ARITY) >= 40u
    # define arity_40u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u
    # define choose_40u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, ...) argument40
    #endif
    #if (LAPYS_MAX_ARITY) >= 41u
    # define arity_41u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u
    # define choose_41u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, ...) argument41
    #endif
    #if (LAPYS_MAX_ARITY) >= 42u
    # define arity_42u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u
    # define choose_42u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, ...) argument42
    #endif
    #if (LAPYS_MAX_ARITY) >= 43u
    # define arity_43u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u
    # define choose_43u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, ...) argument43
    #endif
    #if (LAPYS_MAX_ARITY) >= 44u
    # define arity_44u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u
    # define choose_44u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, ...) argument44
    #endif
    #if (LAPYS_MAX_ARITY) >= 45u
    # define arity_45u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u
    # define choose_45u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, ...) argument45
    #endif
    #if (LAPYS_MAX_ARITY) >= 46u
    # define arity_46u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u
    # define choose_46u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, ...) argument46
    #endif
    #if (LAPYS_MAX_ARITY) >= 47u
    # define arity_47u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u
    # define choose_47u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, ...) argument47
    #endif
    #if (LAPYS_MAX_ARITY) >= 48u
    # define arity_48u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u
    # define choose_48u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, ...) argument48
    #endif
    #if (LAPYS_MAX_ARITY) >= 49u
    # define arity_49u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u
    # define choose_49u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, ...) argument49
    #endif
    #if (LAPYS_MAX_ARITY) >= 50u
    # define arity_50u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u
    # define choose_50u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, ...) argument50
    #endif
    #if (LAPYS_MAX_ARITY) >= 51u
    # define arity_51u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u
    # define choose_51u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, ...) argument51
    #endif
    #if (LAPYS_MAX_ARITY) >= 52u
    # define arity_52u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u
    # define choose_52u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, ...) argument52
    #endif
    #if (LAPYS_MAX_ARITY) >= 53u
    # define arity_53u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u
    # define choose_53u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, ...) argument53
    #endif
    #if (LAPYS_MAX_ARITY) >= 54u
    # define arity_54u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u
    # define choose_54u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, ...) argument54
    #endif
    #if (LAPYS_MAX_ARITY) >= 55u
    # define arity_55u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u
    # define choose_55u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, ...) argument55
    #endif
    #if (LAPYS_MAX_ARITY) >= 56u
    # define arity_56u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u
    # define choose_56u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, ...) argument56
    #endif
    #if (LAPYS_MAX_ARITY) >= 57u
    # define arity_57u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u
    # define choose_57u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, ...) argument57
    #endif
    #if (LAPYS_MAX_ARITY) >= 58u
    # define arity_58u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u
    # define choose_58u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, ...) argument58
    #endif
    #if (LAPYS_MAX_ARITY) >= 59u
    # define arity_59u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u
    # define choose_59u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, ...) argument59
    #endif
    #if (LAPYS_MAX_ARITY) >= 60u
    # define arity_60u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u
    # define choose_60u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, ...) argument60
    #endif
    #if (LAPYS_MAX_ARITY) >= 61u
    # define arity_61u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u
    # define choose_61u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, ...) argument61
    #endif
    #if (LAPYS_MAX_ARITY) >= 62u
    # define arity_62u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u
    # define choose_62u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, ...) argument62
    #endif
    #if (LAPYS_MAX_ARITY) >= 63u
    # define arity_63u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u
    # define choose_63u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, ...) argument63
    #endif
    #if (LAPYS_MAX_ARITY) >= 64u
    # define arity_64u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u
    # define choose_64u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, ...) argument64
    #endif
    #if (LAPYS_MAX_ARITY) >= 65u
    # define arity_65u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u
    # define choose_65u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, ...) argument65
    #endif
    #if (LAPYS_MAX_ARITY) >= 66u
    # define arity_66u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u
    # define choose_66u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, ...) argument66
    #endif
    #if (LAPYS_MAX_ARITY) >= 67u
    # define arity_67u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u
    # define choose_67u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, ...) argument67
    #endif
    #if (LAPYS_MAX_ARITY) >= 68u
    # define arity_68u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u
    # define choose_68u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, ...) argument68
    #endif
    #if (LAPYS_MAX_ARITY) >= 69u
    # define arity_69u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u
    # define choose_69u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, ...) argument69
    #endif
    #if (LAPYS_MAX_ARITY) >= 70u
    # define arity_70u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u
    # define choose_70u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, ...) argument70
    #endif
    #if (LAPYS_MAX_ARITY) >= 71u
    # define arity_71u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u
    # define choose_71u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, ...) argument71
    #endif
    #if (LAPYS_MAX_ARITY) >= 72u
    # define arity_72u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u
    # define choose_72u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, ...) argument72
    #endif
    #if (LAPYS_MAX_ARITY) >= 73u
    # define arity_73u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u
    # define choose_73u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, ...) argument73
    #endif
    #if (LAPYS_MAX_ARITY) >= 74u
    # define arity_74u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u
    # define choose_74u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, ...) argument74
    #endif
    #if (LAPYS_MAX_ARITY) >= 75u
    # define arity_75u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u
    # define choose_75u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, ...) argument75
    #endif
    #if (LAPYS_MAX_ARITY) >= 76u
    # define arity_76u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u
    # define choose_76u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, ...) argument76
    #endif
    #if (LAPYS_MAX_ARITY) >= 77u
    # define arity_77u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u
    # define choose_77u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, ...) argument77
    #endif
    #if (LAPYS_MAX_ARITY) >= 78u
    # define arity_78u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u
    # define choose_78u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, ...) argument78
    #endif
    #if (LAPYS_MAX_ARITY) >= 79u
    # define arity_79u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u
    # define choose_79u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, ...) argument79
    #endif
    #if (LAPYS_MAX_ARITY) >= 80u
    # define arity_80u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u
    # define choose_80u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, ...) argument80
    #endif
    #if (LAPYS_MAX_ARITY) >= 81u
    # define arity_81u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u
    # define choose_81u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, ...) argument81
    #endif
    #if (LAPYS_MAX_ARITY) >= 82u
    # define arity_82u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u
    # define choose_82u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, ...) argument82
    #endif
    #if (LAPYS_MAX_ARITY) >= 83u
    # define arity_83u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u
    # define choose_83u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, ...) argument83
    #endif
    #if (LAPYS_MAX_ARITY) >= 84u
    # define arity_84u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u
    # define choose_84u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, ...) argument84
    #endif
    #if (LAPYS_MAX_ARITY) >= 85u
    # define arity_85u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u
    # define choose_85u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, ...) argument85
    #endif
    #if (LAPYS_MAX_ARITY) >= 86u
    # define arity_86u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u
    # define choose_86u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, ...) argument86
    #endif
    #if (LAPYS_MAX_ARITY) >= 87u
    # define arity_87u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u
    # define choose_87u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, ...) argument87
    #endif
    #if (LAPYS_MAX_ARITY) >= 88u
    # define arity_88u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u
    # define choose_88u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, ...) argument88
    #endif
    #if (LAPYS_MAX_ARITY) >= 89u
    # define arity_89u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u
    # define choose_89u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, ...) argument89
    #endif
    #if (LAPYS_MAX_ARITY) >= 90u
    # define arity_90u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u
    # define choose_90u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, ...) argument90
    #endif
    #if (LAPYS_MAX_ARITY) >= 91u
    # define arity_91u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u
    # define choose_91u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, ...) argument91
    #endif
    #if (LAPYS_MAX_ARITY) >= 92u
    # define arity_92u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u
    # define choose_92u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, ...) argument92
    #endif
    #if (LAPYS_MAX_ARITY) >= 93u
    # define arity_93u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u
    # define choose_93u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, ...) argument93
    #endif
    #if (LAPYS_MAX_ARITY) >= 94u
    # define arity_94u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u
    # define choose_94u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, ...) argument94
    #endif
    #if (LAPYS_MAX_ARITY) >= 95u
    # define arity_95u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u
    # define choose_95u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, ...) argument95
    #endif
    #if (LAPYS_MAX_ARITY) >= 96u
    # define arity_96u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u
    # define choose_96u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, ...) argument96
    #endif
    #if (LAPYS_MAX_ARITY) >= 97u
    # define arity_97u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u
    # define choose_97u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, ...) argument97
    #endif
    #if (LAPYS_MAX_ARITY) >= 98u
    # define arity_98u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u
    # define choose_98u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, ...) argument98
    #endif
    #if (LAPYS_MAX_ARITY) >= 99u
    # define arity_99u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u
    # define choose_99u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, ...) argument99
    #endif
    #if (LAPYS_MAX_ARITY) >= 100u
    # define arity_100u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u
    # define choose_100u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, ...) argument100
    #endif
    #if (LAPYS_MAX_ARITY) >= 101u
    # define arity_101u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u
    # define choose_101u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, ...) argument101
    #endif
    #if (LAPYS_MAX_ARITY) >= 102u
    # define arity_102u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u
    # define choose_102u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, ...) argument102
    #endif
    #if (LAPYS_MAX_ARITY) >= 103u
    # define arity_103u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u
    # define choose_103u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, ...) argument103
    #endif
    #if (LAPYS_MAX_ARITY) >= 104u
    # define arity_104u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u
    # define choose_104u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, ...) argument104
    #endif
    #if (LAPYS_MAX_ARITY) >= 105u
    # define arity_105u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u
    # define choose_105u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, ...) argument105
    #endif
    #if (LAPYS_MAX_ARITY) >= 106u
    # define arity_106u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u
    # define choose_106u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, ...) argument106
    #endif
    #if (LAPYS_MAX_ARITY) >= 107u
    # define arity_107u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u
    # define choose_107u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, ...) argument107
    #endif
    #if (LAPYS_MAX_ARITY) >= 108u
    # define arity_108u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u
    # define choose_108u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, ...) argument108
    #endif
    #if (LAPYS_MAX_ARITY) >= 109u
    # define arity_109u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u
    # define choose_109u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, ...) argument109
    #endif
    #if (LAPYS_MAX_ARITY) >= 110u
    # define arity_110u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u
    # define choose_110u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, ...) argument110
    #endif
    #if (LAPYS_MAX_ARITY) >= 111u
    # define arity_111u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u
    # define choose_111u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, ...) argument111
    #endif
    #if (LAPYS_MAX_ARITY) >= 112u
    # define arity_112u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u
    # define choose_112u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, ...) argument112
    #endif
    #if (LAPYS_MAX_ARITY) >= 113u
    # define arity_113u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u
    # define choose_113u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, ...) argument113
    #endif
    #if (LAPYS_MAX_ARITY) >= 114u
    # define arity_114u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u
    # define choose_114u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, ...) argument114
    #endif
    #if (LAPYS_MAX_ARITY) >= 115u
    # define arity_115u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u
    # define choose_115u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, ...) argument115
    #endif
    #if (LAPYS_MAX_ARITY) >= 116u
    # define arity_116u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u
    # define choose_116u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, ...) argument116
    #endif
    #if (LAPYS_MAX_ARITY) >= 117u
    # define arity_117u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u
    # define choose_117u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, ...) argument117
    #endif
    #if (LAPYS_MAX_ARITY) >= 118u
    # define arity_118u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u
    # define choose_118u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, ...) argument118
    #endif
    #if (LAPYS_MAX_ARITY) >= 119u
    # define arity_119u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u
    # define choose_119u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, ...) argument119
    #endif
    #if (LAPYS_MAX_ARITY) >= 120u
    # define arity_120u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u, 120u
    # define choose_120u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, ...) argument120
    #endif
    #if (LAPYS_MAX_ARITY) >= 121u
    # define arity_121u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u, 120u, 121u
    # define choose_121u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, ...) argument121
    #endif
    #if (LAPYS_MAX_ARITY) >= 122u
    # define arity_122u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u, 120u, 121u, 122u
    # define choose_122u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, ...) argument122
    #endif
    #if (LAPYS_MAX_ARITY) >= 123u
    # define arity_123u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u, 120u, 121u, 122u, 123u
    # define choose_123u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, argument123, ...) argument123
    #endif
    #if (LAPYS_MAX_ARITY) >= 124u
    # define arity_124u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u, 120u, 121u, 122u, 123u, 124u
    # define choose_124u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, argument123, argument124, ...) argument124
    #endif
    #if (LAPYS_MAX_ARITY) >= 125u
    # define arity_125u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u, 120u, 121u, 122u, 123u, 124u, 125u
    # define choose_125u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, argument123, argument124, argument125, ...) argument125
    #endif
    #if (LAPYS_MAX_ARITY) >= 126u
    # define arity_126u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u, 120u, 121u, 122u, 123u, 124u, 125u, 126u
    # define choose_126u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, argument123, argument124, argument125, argument126, ...) argument126
    #endif
    #if (LAPYS_MAX_ARITY) >= 127u
    # define arity_127u 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 62u, 63u, 64u, 65u, 66u, 67u, 68u, 69u, 70u, 71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u, 85u, 86u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 97u, 98u, 99u, 100u, 101u, 102u, 103u, 104u, 105u, 106u, 107u, 108u, 109u, 110u, 111u, 112u, 113u, 114u, 115u, 116u, 117u, 118u, 119u, 120u, 121u, 122u, 123u, 124u, 125u, 126u, 127u
    # if CPP_COMPILER == CPP_CIRCLE_COMPILER || CPP_COMPILER == CPP_CLANG_COMPILER || CPP_COMPILER == CPP_GCC_COMPILER || CPP_COMPILER == CPP_ICC_COMPILER
    #   define choose_127u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, argument123, argument124, argument125, argument126, argument127, ...) argument127
    # else
    #   define choose_127u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, argument123, argument124, argument125, argument126, argument127) argument127
    # endif
    #endif

    #define arity(count) arity_ ## count
    # define arity_0u

    #undef  choose
    #define choose(argument, ...) defer(combine, choose_, argument)(__VA_ARGS__)
    # define choose_0u(...)
    # define choose_1u(argument1, ...) argument1
    # define choose_2u(argument1, argument2, ...) argument2

    #define combine(argument1, argument2) argument1 ## argument2

    #define defer(function, ...) defer_1u(function, (__VA_ARGS__))
    # define defer_0u(function, ...) function(__VA_ARGS__)
    # define defer_1u(function, call) function call
    # define defer_2u(function, call) defer_1u(function, call)
    # define defer_3u(function, call) defer_2u(function, call)
    # define defer_4u(function, call) defer_3u(function, call)
    # define defer_5u(function, call) defer_4u(function, call)
    # define defer_6u(function, call) defer_5u(function, call)
    # define defer_7u(function, call) defer_6u(function, call)
    # define defer_8u(function, call) defer_7u(function, call)
    # define defer_9u(function, call) defer_8u(function, call)
    # define defer_10u(function, call) defer_9u(function, call)
    # define defer_11u(function, call) defer_10u(function, call)
    # define defer_12u(function, call) defer_11u(function, call)

    #undef apply // UPDATE (Lapys) -> Allow for nested `apply(...)`s within `apply(...)`s
    # define apply_begin(function, condition, separator, currentArgument, nextArgument, ...) choose(condition(currentArgument, nextArgument, __VA_ARGS__), apply_continue, apply_end)( /* ->> Body of the `apply(...)` loop */ \
      function,                                                                                                                                                                                                                \
      choose(condition(nextArgument, __VA_ARGS__), separator, apply_terminator),                                                                                                                                               \
      stall(reapply)()(function, condition, separator, nextArgument, __VA_ARGS__, break),                                                                                                                                      \
      currentArgument, nextArgument, __VA_ARGS__                                                                                                                                                                               \
    )
    # undef  apply_condition                   // ->> Asserts to `false` or `true` by default
    # define apply_function(argument)argument  // ->> Evaluates to `argument` by default
    # define apply_separator(argument, ...)    // ->> Does not separate by default
    #   define apply_condition_default ~, false
    #   define apply_function_default  ~, false
    #   define apply_separator_default ~, false
    #
    #   define apply_access(argument, ...)                  .
    #   define apply_access_pointer(argument, ...)          .*
    #   define apply_add(argument, ...)                     +
    #   define apply_assign(argument, ...)                  =
    #   define apply_bitwise_and(argument, ...)             &
    #   define apply_bitwise_or(argument, ...)              |
    #   define apply_bitwise_shift_left(argument, ...)      <<
    #   define apply_bitwise_shift_right(argument, ...)     >>
    #   define apply_bitwise_xor(argument, ...)             ^
    #   define apply_boolean_and(argument, ...)             &&
    #   define apply_boolean_or(argument, ...)              ||
    #   define apply_comma(argument, ...)                   ,
    #   define apply_compare(argument, ...)                 <=>
    #   define apply_deferred_access(argument, ...)         ->
    #   define apply_deferred_access_pointer(argument, ...) ->*
    #   define apply_divide(argument, ...)                  /
    #   define apply_equals(argument, ...)                  ==
    #   define apply_expression_begin(argument, ...)        (
    #   define apply_expression_end(argument, ...)          )
    #   define apply_greater(argument, ...)                 >
    #   define apply_greater_equals(argument, ...)          >=
    #   define apply_initializer_begin(argument, ...)       {
    #   define apply_initializer_end(argument, ...)         }
    #   define apply_lesser(argument, ...)                  <
    #   define apply_lesser_equals(argument, ...)           <=
    #   define apply_modulo(argument, ...)                  %
    #   define apply_multiply(argument, ...)                *
    #   define apply_scope(argument, ...)                   ::
    #   define apply_subscript_begin(argument, ...)         [
    #   define apply_subscript_end(argument, ...)           ]
    #   define apply_subtract(argument, ...)                -
    #   define apply_ternary_falsy(argument, ...)           :
    #   define apply_ternary_truthy(argument, ...)          ?
    #   define apply_unequals(argument, ...)                !=
    # define apply_continue(function, separator, applyer, argument, ...) function(argument)separator(argument, __VA_ARGS__) applyer
    # define apply_end(function, separator, applyer, argument, ...) // ->> Stop expanding
    # undef  apply_setup
    # define apply_terminator(argument, ...)
    # if CPP_PREPROCESSOR_FORMAT == CPP_PREPROCESSOR_STANDARD_FORMAT || CPP_COMPILER == CPP_ICC_COMPILER
    #   define apply(...) parse(apply_setup(__VA_ARGS__))
    #     define apply_condition(argument, ...) defer(choose_2u, reapply_ ## argument, true, ~)
    #     define apply_setup(function, condition, separator, ...) apply_begin(                            \
            choose(defer(choose_2u, apply_function_  ## function , true, ~), function,  apply_function),  \
            choose(defer(choose_2u, apply_condition_ ## condition, true, ~), condition, apply_condition), \
            choose(defer(choose_2u, apply_separator_ ## separator, true, ~), separator, apply_separator), \
            __VA_ARGS__, break, break                                                                     \
          )
    #     if CPP_COMPILER == CPP_ICC_COMPILER
    #       undef  apply_continue // ->> unknown why the `applyer` function needs to become redundant
    #       define apply_continue(function, separator, applyer, argument, ...) function(argument)separator(argument, __VA_ARGS__)
    #     endif
    # elif CPP_PREPROCESSOR_FORMAT == CPP_PREPROCESSOR_MSVC_FORMAT
    #   define apply(...) parse(defer(apply_setup, __VA_ARGS__))
    #     define apply_condition(argument, ...) stall(defer(choose_2u, choose_1u(reapply_ ## argument, ~), true))
    #     define apply_setup(function, condition, separator, ...) defer(apply_begin,                                           \
            stall(choose(defer(choose_2u, choose_1u(apply_function_  ## function , ~), true, ~), function,  apply_function)),  \
            stall(choose(defer(choose_2u, choose_1u(apply_condition_ ## condition, ~), true, ~), condition, apply_condition)), \
            stall(choose(defer(choose_2u, choose_1u(apply_separator_ ## separator, ~), true, ~), separator, apply_separator)), \
            __VA_ARGS__, break, break                                                                                          \
          )
    # endif
    # define reapply() apply_begin // ->> Update of the `apply(...)` loop
    #   define reapply_break ~, false // ->> End of the `apply(...)` loop

    #if (LAPYS_MAX_ARITY) <= (1u << 1u)
    # define parse(...) parse_1u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 2u)
    # define parse(...) parse_2u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 3u)
    # define parse(...) parse_3u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 4u)
    # define parse(...) parse_4u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 5u)
    # define parse(...) parse_5u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 6u)
    # define parse(...) parse_6u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 7u)
    # define parse(...) parse_7u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 8u)
    # define parse(...) parse_8u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 9u)
    # define parse(...) parse_9u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 10u)
    # define parse(...) parse_10u(__VA_ARGS__)
    #elif (LAPYS_MAX_ARITY) <= (1u << 11u)
    # define parse(...) parse_11u(__VA_ARGS__)
    #else
    # define parse(...) parse_12u(__VA_ARGS__)
    #endif
    # define parse_1u(...)  __VA_ARGS__
    # define parse_2u(...)  parse_1u(parse_1u(__VA_ARGS__))
    # define parse_3u(...)  parse_2u(parse_2u(__VA_ARGS__))
    # define parse_4u(...)  parse_3u(parse_3u(__VA_ARGS__))
    # define parse_5u(...)  parse_4u(parse_4u(__VA_ARGS__))
    # define parse_6u(...)  parse_5u(parse_5u(__VA_ARGS__))
    # define parse_7u(...)  parse_6u(parse_6u(__VA_ARGS__))
    # define parse_8u(...)  parse_7u(parse_7u(__VA_ARGS__))
    # define parse_9u(...)  parse_8u(parse_8u(__VA_ARGS__))
    # define parse_10u(...) parse_9u(parse_9u(__VA_ARGS__))
    # define parse_11u(...) parse_10u(parse_10u(__VA_ARGS__))
    # define parse_12u(...) parse_11u(parse_11u(__VA_ARGS__))

    #define stall(macro) stall_2u(macro)
    # define stall_1u(macro) macro empty()
    # define stall_2u(macro) macro empty empty()()
    # define stall_3u(macro) macro empty empty empty()()()
    # define stall_4u(macro) macro empty empty empty empty()()()()
    # define stall_5u(macro) macro empty empty empty empty empty()()()()()
    # define stall_6u(macro) macro empty empty empty empty empty empty()()()()()()
    # define stall_7u(macro) macro empty empty empty empty empty empty empty()()()()()()()
    # define stall_8u(macro) macro empty empty empty empty empty empty empty empty()()()()()()()()
    # define stall_9u(macro) macro empty empty empty empty empty empty empty empty empty()()()()()()()()()
    # define stall_10u(macro) macro empty empty empty empty empty empty empty empty empty empty()()()()()()()()()()
    # define stall_11u(macro) macro empty empty empty empty empty empty empty empty empty empty empty()()()()()()()()()()()
    # define stall_12u(macro) macro empty empty empty empty empty empty empty empty empty empty empty empty()()()()()()()()()()()()

    #define stringify(argument) #argument
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   pragma clang diagnostic pop
  # elif CPP_COMPILER == CPP_GCC_COMPILER
  #   pragma GCC diagnostic pop
  # endif
  #endif
#endif
