/* Constant > ... */
// : [Maximum Arity] --- NOTE (Lapys) -> Maximum number of supported function/ template arguments in variadics
#ifndef LAPYS_MAX_ARITY
# define LAPYS_MAX_ARITY 255u
#endif

// : [Maximum Template Instantiation Depth] --- NOTE (Lapys) -> Maximum template instantiation depth for recursive traits (must be greater than `1u`)
#ifndef LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH
# define LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH 500u
#endif

/* : [Preprocessor]
  --- NOTE ---
  #Lapys: Defines additional macros and prevents some from being cleaned
    Additional macros:
    - apply(...)
    - concatenate(...)
    - defer(...)
    - first(...)
    - parse(...)
    - refer(...)
    - second(...)
    - stall(...)

    Uncleaned macros:
    - CPP_COMPILER (including CPP_*_COMPILER)
    - CPP_ENDIAN
    - CPP_VENDOR (including CPP_*_VENDOR)

    - empty()
*/
#ifndef LAPYS_PREPROCESSOR
# define LAPYS_PREPROCESSOR 0u // --> false
#endif

/* ... --> #pragma once */
#ifndef LAPYS
# define LAPYS
  /* Namespace */
  namespace Lapys {}

  /* Definition > ... ->> for the C `stdint.h` header */
  // #ifndef __STDC_CONSTANT_MACROS
  // # define __STDC_CONSTANT_MACROS
  // #endif

  // #ifndef __STDC_FORMAT_MACROS
  // # define __STDC_FORMAT_MACROS
  // #endif

  // #ifndef __STDC_LIMIT_MACROS
  // # define __STDC_LIMIT_MACROS
  // #endif

  /* Import > ... */
  // : [C++ Standard Library]
  // : [C Standard Library]

  // : [...]
  #include "lapys/extensions.hpp"

  // : [UNIX]
  #if CPP_VENDOR & CPP__UNIX__VENDOR
  #endif

  // : [Windows]
  #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
  #endif

  /* Import > ... */
#endif

/* Deletion > ... */
#undef boundsas
#undef boundsof
#undef constenum
#undef constfunc
# undef constfunc__
# undef constfunc__false
# undef constfunc__true
#undef constvar
#undef discard
#undef exceptspec
# if CPP_VERSION < 2011uL
#   undef exceptspec__check__true
#   undef exceptspec__fail
#   undef exceptspec__pass
#   undef noexcept
# endif
#if CPP_VERSION < 2011uL
# undef final
#endif
#undef init
#undef int128_t
#undef intenum
#undef nilinit
#undef nodecay
#undef nodecayparam
#undef noexit
#undef noignore
#undef noinline
#undef nouniqueaddr
#undef typeof
#undef uint128_t
#undef varinit

#if LAPYS_PREPROCESSOR
#else
# undef empty
#endif

#if LAPYS_PREPROCESSOR
#else
# undef CPP_COMPILER
#   undef CPP__CLANG__COMPILER
#   undef CPP__EDG__COMPILER
#   undef CPP__GCC__COMPILER
#   undef CPP__ICC__COMPILER
#   undef CPP__MSVC__COMPILER
# undef CPP_ENDIAN
# undef CPP_VENDOR
#   undef CPP__APPLE_MACINTOSH__VENDOR
#   undef CPP__LINUX__VENDOR
#   undef CPP__MICROSOFT_WINDOWS__VENDOR
#   undef CPP__NINTENDO__VENDOR
#   undef CPP__UNIX__VENDOR
# undef CPP_VERSION
#endif
