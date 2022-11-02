/* Constant */
// : [Maximum Arity] --- NOTE (Lapys) -> Maximum number of supported function/ template arguments in variadics (always lesser than `127u`)
#ifndef LAPYS_MAX_ARITY
# define LAPYS_MAX_ARITY 8u
#endif

// : [Maximum Template Instantiation Depth] --- NOTE (Lapys) -> Maximum template instantiation depth for recursive traits (must be greater than `1u`)
#ifndef LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH
# define LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH 500u
#endif

/* : [Preprocessor]
  --- NOTE ---
  #Lapys: Defines additional macros and prevents some from being cancelled
    Additional macros:
    - apply  (...)
    - combine(...)
    - defer  (...)
    - first  (...)
    - join   (...)
    - parse  (...)
    - refer  (...)
    - second (...)
    - stall  (...)

    Uncleaned macros:
    - CPP_COMPILER (including CPP_*_COMPILER)
    - CPP_ENDIAN
    - CPP_VENDOR (including CPP_*_VENDOR)

    - choose(...)
    - empty ()
*/
#ifndef LAPYS_PREPROCESSOR
# define LAPYS_PREPROCESSOR 0u // --> false
#endif

/* ... */
#ifndef LAPYS
# define LAPYS
  /* Namespace */
  namespace Lapys {}

  /* Definition ->> for the C `stdint.h` header */
  #ifndef __STDC_CONSTANT_MACROS
  # define __STDC_CONSTANT_MACROS
  #endif

  #ifndef __STDC_FORMAT_MACROS
  # define __STDC_FORMAT_MACROS
  #endif

  #ifndef __STDC_LIMIT_MACROS
  # define __STDC_LIMIT_MACROS
  #endif

  /* Import */
  // : [C++ Standard Library]
  #include <cstddef> // C Standard Definitions

  // : [C Standard Library]

  // : [...]
  #include "lapys/extensions.hpp"

  // : [UNIX]
  #if CPP_VENDOR & CPP__UNIX__VENDOR
  # include <sys/mman.h>
  #endif

  // : [Windows]
  #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
  # define NOATOM
  # define NOCLIPBOARD
  # define NOCOLOR
  # define NOCOMM
  # define NOCTLMGR
  # define NODEFERWINDOWPOS
  # define NODRAWTEXT
  # define NOGDI
  # define NOGDICAPMASKS
  # define NOHELP
  # define NOICONS
  # define NOKANJI
  # define NOKERNEL
  # define NOKEYSTATES
  # define NOMB
  # define NOMCX
  # define NOMEMMGR
  # define NOMENUS
  # define NOMETAFILE
  # define NOMINMAX
  # define NOMSG
  # define NONLS
  # define NOOPENFILE
  # define NOPROFILER
  # define NORASTEROPS
  # define NOSCROLL
  # define NOSERVICE
  # define NOSHOWWINDOW
  # define NOSOUND
  # define NOSYSCOMMANDS
  # define NOSYSMETRICS
  # define NOTEXTMETRIC
  # define NOUSER
  # define NOVIRTUALKEYCODES
  # define NOWH
  # define NOWINMESSAGES
  # define NOWINOFFSETS
  # define NOWINSTYLES
  # define OEMRESOURCE
  # define WIN32_LEAN_AND_MEAN
  # include <windows.h>
  #endif

  // : [...]
  #include "lapys/traits.hpp"
#endif

/* Deletion */
#undef boundsas
#undef boundsof
#undef constenum
#undef constfunc
# undef constfunc_
# undef constfunc_false
# undef constfunc_true
#undef constvar
#undef discard
#undef exceptof
#undef exceptspec
# if CPP_VERSION < 2011uL
#   undef exceptspec_false
#   undef exceptspec_true
#   undef noexcept
# endif
#if CPP_VERSION < 2011uL
# undef final
#endif
#undef init
#undef int128_t
#undef intenum
#undef lref
#undef mustinline
#undef nilinit
#undef nodecay
#undef nodecayparam
#undef noexit
#undef noignore
#undef noinline
#undef nouniqueaddr
#undef nullptr
#undef rref
#undef typeof
#undef uint128_t
#undef varinit

#if LAPYS_PREPROCESSOR
#else
# undef choose
#   undef choose_false
#   undef choose_true
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
# undef CPP_ENDIAN_RUNTIME
#   undef CPP_BYTE_BIG_ENDIAN
#   undef CPP_BYTE_LITTLE_ENDIAN
#   undef CPP_MIXED_ENDIAN
#   undef CPP_WORD_BIG_ENDIAN
#   undef CPP_WORD_LITTLE_ENDIAN
# undef CPP_PREPROCESSOR_FORMAT
#   undef CPP_PREPROCESSOR_FORMAT_CHECK
#   undef CPP_PREPROCESSOR_FORMAT_SELECT
#   undef CPP_PREPROCESSOR_MSVC_FORMAT
#   undef CPP_PREPROCESSOR_STANDARD_FORMAT
# undef CPP_VENDOR
#   undef CPP_APPLE_MACINTOSH_VENDOR
#   undef CPP_CYGWIN_VENDOR
#   undef CPP_HAIKU_VENDOR
#   undef CPP_LINUX_VENDOR
#   undef CPP_MICROSOFT_WINDOWS_VENDOR
#   undef CPP_NINTENDO_VENDOR
#   undef CPP_UNIX_VENDOR
# undef CPP_VERSION
# undef LAPYS_MAX_ARITY
# undef LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH
// # undef LAPYS_MODULE_EXTENSIONS
# undef LAPYS_MODULE_TRAITS
#endif
