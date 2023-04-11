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
  /* Guard > Lapys */
  #ifdef Lapys
  # error Lapys C++: Well, this is awkward... Unexpected `Lapys` macro definition
  #endif

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
  // : [C/ C++ Standard Library]
  #include "lapys/guards/c.h"
  #include "lapys/guards/cpp.h"
  #include <ciso646>   // C ISO 646
  #include <cstddef>   // C Standard Definitions
  #include <stdbool.h> // Standard Boolean
  #include <stdfloat>  // Standard Float ->> Optional in freestanding environments?

  // : [C Standard Library]

  // : [...]
  #include "lapys/extensions.hpp"

  // : [Microsoft Windows]
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
  #
  # if included(<windows.h>)
  #   include "lapys/guards/windows.h"
  #   include <windows.h>
  # else
  #   error Lapys C++: Microsoft Windows-specific header `<windows.h>` required
  # endif
  #endif

  // : [UNIX]
  #if CPP_VENDOR & CPP__UNIX__VENDOR
  # if included(<sys/mman.h>)
  #   include "lapys/guards/sys_mman.h"
  #   include <sys/mman.h>
  # else
  #   error Lapys C++: Unix-specific POSIX header `<sys/mman.h>` required
  # endif
  #endif

  // : [...]
  #include "lapys/traits.hpp"
#endif

/* Deletion */
#undef boundsas
#undef boundsof
#undef constfunc
# undef constfunc_
# undef constfunc_false
# undef constfunc_true
#undef constint
# undef constint_1u
# undef constint_2u
#undef constvar
#undef discard
#undef enumint
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
#undef included
#undef init
#undef lref
#undef mustinline
#undef mustreturn
#undef nilinit
#undef nodecay
#undef nodecayparam
#undef noexit
#undef noinline
#undef nouniqueaddr
#undef nullptr
#undef restricted
#undef rlref
#undef rref
#undef typeof
#undef varinit

#if LAPYS_PREPROCESSOR
# undef widthof
# define widthof(argument) (CHAR_BIT * sizeof(argument))
#else
# undef as
#   undef as_operator
# undef choose
#   undef choose_false
#   undef choose_true
# undef empty
# undef float16_t
# undef float32_t
# undef float64_t
# undef float128_t
# undef int128_t
# undef uint128_t
# undef widthof
#   undef widthof_operator
# ifndef __cpp_static_assert
#   undef static_assert
#     undef static_assert_1u
#     undef static_assert_2u
#     undef static_assert_declaration
# endif
#endif

#if LAPYS_PREPROCESSOR
#else
# undef CPP_ARCHITECTURE
#   undef CPP_ALPHA_ARCHITECTURE
#   undef CPP_ARM_ARCHITECTURE
#   undef CPP_BLACKFIN_ARCHITECTURE
#   undef CPP_CONVEX_ARCHITECTURE
#   undef CPP_E2K_ARCHITECTURE
#   undef CPP_HP_PA_RISC_ARCHITECTURE
#   undef CPP_INTEL_ITANIUM_ARCHITECTURE
#   undef CPP_INTEL_X86_64_ARCHITECTURE
#   undef CPP_INTEL_X86_ARCHITECTURE
#   undef CPP_MIPS_ARCHITECTURE
#   undef CPP_MOTOROLA_68K_ARCHITECTURE
#   undef CPP_POWER_PC_64_ARCHITECTURE
#   undef CPP_POWER_PC_ARCHITECTURE
#   undef CPP_PTX_ARCHITECTURE
#   undef CPP_PYRAMID_9810_ARCHITECTURE
#   undef CPP_RISC_V_ARCHITECTURE
#   undef CPP_RS_6000_ARCHITECTURE
#   undef CPP_SPARC_ARCHITECTURE
#   undef CPP_SUPER_H_ARCHITECTURE
#   undef CPP_SYSTEM_370_ARCHITECTURE
#   undef CPP_SYSTEM_390_ARCHITECTURE
#   undef CPP_Z_ARCHITECTURE
# undef CPP_COMPILER
#   undef CPP_BORLAND_COMPILER
#   undef CPP_CIRCLE_COMPILER
#   undef CPP_CLANG_COMPILER
#   undef CPP_COMEAU_COMPILER
#   undef CPP_DEC_COMPILER
#   undef CPP_DIAB_COMPILER
#   undef CPP_DMC_COMPILER
#   undef CPP_EDG_COMPILER
#   undef CPP_GCCXML_COMPILER
#   undef CPP_GHS_COMPILER
#   undef CPP_GNUC_COMPILER
#   undef CPP_HIGHC_COMPILER
#   undef CPP_HPACC_COMPILER
#   undef CPP_IAR_COMPILER
#   undef CPP_IBM_COMPILER
#   undef CPP_INTEL_COMPILER
#   undef CPP_KCC_COMPILER
#   undef CPP_LLVM_COMPILER
#   undef CPP_MPW_COMPILER
#   undef CPP_MRI_COMPILER
#   undef CPP_MSVC_COMPILER
#   undef CPP_MWERKS_COMPILER
#   undef CPP_NVCC_COMPILER
#   undef CPP_PALM_COMPILER
#   undef CPP_PATH_COMPILER
#   undef CPP_PGI_COMPILER
#   undef CPP_SGI_COMPILER
#   undef CPP_SUNPRO_COMPILER
#   undef CPP_SYSC_COMPILER
#   undef CPP_TENDRA_COMPILER
#   undef CPP_WATCOM_COMPILER
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
# undef LAPYS_MODULE_EXTENSIONS
# undef LAPYS_MODULE_TRAITS
#endif
