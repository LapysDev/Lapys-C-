/* Definition */
// Maximum Arity ->> Maximum number of supported function/ template arguments in variadics --> LAPYS_MAX_ARITY < 127u
#ifndef LAPYS_MAX_ARITY
# define LAPYS_MAX_ARITY 127u
#endif

// Maximum Template Instantiation Depth ->> Maximum template instantiation depth for recursive traits --> LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH > 1u
#ifndef LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH
# define LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH 500u
#endif

/* Preprocessor
  --- NOTE ---
  Conditionally defines additional library function-like macros and prevents some default library macros from being undefined
    Additional macros:
    - apply   (...) ->> Recursively invoke a function-like macro (`function_macro(argument)`) iteratively on a list of `arguments`                --> apply(function_macro, condition_macro, separator_macro, ...arguments)
    - arity   (...) ->> Evaluates to a comma-separated list of `unsigned` integers                                                                --> arity(3u) --> 1u, 2u, 3u
    - combine (...) ->> Concatenate two arguments                                                                                                 --> combine(a, b) --> ab
    - defer   (...) ->> Forwards invocation of a `function` with some `arguments` while `stall(...)`ing                                           --> defer(function, ...arguments)
    - first   (...) ->> Evaluates to the first `argument` in a provided list of `arguments`; Useful for conditional selection with `choose(...)`  --> first(a, b, ...arguments) --> a
    - parse   (...) ->> Delays evaluation of preprocessor tokens                                                                                  --> parse(...arguments)
    - second  (...) ->> Evaluates to the second `argument` in a provided list of `arguments`; Useful for conditional selection with `choose(...)` --> first(a, b, ...arguments) --> a
    - subapply(...) ->> Working `apply` function-like macro within an `apply(...)` evaluation                                                     --> subapply(function_macro, condition_macro, separator_macro, ...arguments) --> apply(subapply, ...)
    - stall   (...) ->> Delays evaluation of preprocessor tokens                                                                                  --> stall(...)

    Persisted macros:
    - CPP_ARCHITECTURE        (including `CPP_*_ARCHITECTURE` macros)
    - CPP_COMPILER            (including `CPP_*_COMPILER`     macros)
    - CPP_ENDIAN              (including `CPP_*_ENDIAN`              and `CPP_ENDIAN_*`              macros)
    - CPP_PREPROCESSOR_FORMAT (including `CPP_PREPROCESSOR_*_FORMAT` and `CPP_PREPROCESSOR_FORMAT_*` macros)
    - CPP_VENDOR              (including `CPP_*_VENDOR` macros)
    - CPP_VERSION
    - LAPYS_MAX_ARITY
    - LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH
    - float16_t
    - float32_t
    - float64_t
    - float128_t
    - int128_t
    - uint128_t

    - as<>         (...) ->> Casts any type to another other specified type despite correctness
    - choose       (...) ->> Conditionally selects the falsy/ truthy argument or evaluates to the indexed argument within a list of arguments
    - empty        ()    ->> Evaluates to nothing
    - static_assert(...) ->> Fallback for C++98
    - widthof      (...) ->> Evaluates the bit size of an expression (or type)
*/
#ifndef LAPYS_PREPROCESSOR
# define LAPYS_PREPROCESSOR false
#endif

// Preprocessor Guard ->> Conditionally asserts certain preprocessor macros against spoofing (see `guards` module for list of macros)
#ifndef LAPYS_PREPROCESSOR_GUARD
# define LAPYS_PREPROCESSOR_GUARD true
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
  // : [C++ Standard Library]
  #include <ciso646> // C ISO 646:1991

  // : [...]
  #include "lapys/extensions.hpp"
  #include "lapys/guards/c.h"
  #include "lapys/guards/cpp.h"
  #include "lapys/guards/keywords.h"

  // : [C/ C++ Standard Library]
  #include <cstddef>   // C Standard Definitions
  #include <stdbool.h> // Standard Boolean

  // : [Microsoft Windows]
  #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
  # undef _MBCS
  # undef _UNICODE
  # undef _WIN32_WINNT
  # undef NOATOM
  # undef NOCLIPBOARD
  # undef NOCOLOR
  # undef NOCOMM
  # undef NOCTLMGR
  # undef NODEFERWINDOWPOS
  # undef NODRAWTEXT
  # undef NOGDI
  # undef NOGDICAPMASKS
  # undef NOHELP
  # undef NOICONS
  # undef NOKANJI
  # undef NOKERNEL
  # undef NOKEYSTATES
  # undef NOMB
  # undef NOMCX
  # undef NOMEMMGR
  # undef NOMENUS
  # undef NOMETAFILE
  # undef NOMINMAX
  # undef NOMSG
  # undef NONLS
  # undef NOOPENFILE
  # undef NOPROFILER
  # undef NORASTEROPS
  # undef NOSCROLL
  # undef NOSERVICE
  # undef NOSHOWWINDOW
  # undef NOSOUND
  # undef NOSYSCOMMANDS
  # undef NOSYSMETRICS
  # undef NOTEXTMETRIC
  # undef NOUSER
  # undef NOVIRTUALKEYCODES
  # undef NOWH
  # undef NOWINMESSAGES
  # undef NOWINOFFSETS
  # undef NOWINSTYLES
  # undef OEMRESOURCE
  # undef UNICODE
  # undef WIN32_LEAN_AND_MEAN

  # define _UNICODE
  # define _WIN32_WINNT 0x0501
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
  # define UNICODE
  # define WIN32_LEAN_AND_MEAN
  #
  # if included(<windows.h>)
  #   include "lapys/guards/windows.h"
  #   include <sdkddkver.h>
  #   include <windows.h>
  #   include <winnt.h>
  #     include <memoryapi.h>
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
  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # ifndef __cpp_nsdmi // --> 200809L
  #   pragma clang diagnostic push
  #   pragma clang diagnostic ignored "-Wunused-local-typedef"
  # endif
  #elif CPP_COMPILER == CPP_MSVC_COMPILER
  # pragma warning(disable:4506)
  # pragma warning(push)
  #endif
  # include "lapys/traits.hpp"
  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # ifndef __cpp_nsdmi // --> 200809L
  #   pragma clang diagnostic pop
  # endif
  #elif CPP_COMPILER == CPP_MSVC_COMPILER
  # pragma warning(pop)
  #endif

  /* Deletion */
  #ifdef LAPYS_MODULE_TRAITS
  # if preprocessed(LAPYS_PREPROCESSOR)
  #   undef  widthof
  #   define widthof(argument) (CHAR_BIT * sizeof(argument))
  # else
  #   undef CPP_MAX_SIZE
  #   undef widthof
  # endif
  #
  # undef sfinaeptr
  #endif

  #ifdef LAPYS_MODULE_EXTENSIONS
  # if CPP_VERSION < 2011uL
  #   undef final
  # endif
  #
  # if preprocessed(LAPYS_PREPROCESSOR)
  # else
  #   undef CPP_ARCHITECTURE
  #     undef CPP_ALPHA_ARCHITECTURE
  #     undef CPP_ARM_ARCHITECTURE
  #     undef CPP_BLACKFIN_ARCHITECTURE
  #     undef CPP_CONVEX_ARCHITECTURE
  #     undef CPP_E2K_ARCHITECTURE
  #     undef CPP_HP_PA_RISC_ARCHITECTURE
  #     undef CPP_INTEL_ITANIUM_ARCHITECTURE
  #     undef CPP_INTEL_X86_64_ARCHITECTURE
  #     undef CPP_INTEL_X86_ARCHITECTURE
  #     undef CPP_MIPS_ARCHITECTURE
  #     undef CPP_MOTOROLA_68K_ARCHITECTURE
  #     undef CPP_POWER_PC_64_ARCHITECTURE
  #     undef CPP_POWER_PC_ARCHITECTURE
  #     undef CPP_PTX_ARCHITECTURE
  #     undef CPP_PYRAMID_9810_ARCHITECTURE
  #     undef CPP_RISC_V_ARCHITECTURE
  #     undef CPP_RS_6000_ARCHITECTURE
  #     undef CPP_SPARC_ARCHITECTURE
  #     undef CPP_SUPER_H_ARCHITECTURE
  #     undef CPP_SYSTEM_370_ARCHITECTURE
  #     undef CPP_SYSTEM_390_ARCHITECTURE
  #     undef CPP_Z_ARCHITECTURE
  #   undef CPP_COMPILER
  #     undef CPP_BORLAND_COMPILER
  #     undef CPP_CIRCLE_COMPILER
  #     undef CPP_CLANG_COMPILER
  #     undef CPP_COMEAU_COMPILER
  #     undef CPP_DEC_COMPILER
  #     undef CPP_DIAB_COMPILER
  #     undef CPP_DMC_COMPILER
  #     undef CPP_EDG_COMPILER
  #     undef CPP_GCCXML_COMPILER
  #     undef CPP_GHS_COMPILER
  #     undef CPP_GNUC_COMPILER
  #     undef CPP_HIGHC_COMPILER
  #     undef CPP_HPACC_COMPILER
  #     undef CPP_IAR_COMPILER
  #     undef CPP_IBM_COMPILER
  #     undef CPP_INTEL_COMPILER
  #     undef CPP_KCC_COMPILER
  #     undef CPP_LLVM_COMPILER
  #     undef CPP_MPW_COMPILER
  #     undef CPP_MRI_COMPILER
  #     undef CPP_MSVC_COMPILER
  #     undef CPP_MWERKS_COMPILER
  #     undef CPP_NVCC_COMPILER
  #     undef CPP_PALM_COMPILER
  #     undef CPP_PATH_COMPILER
  #     undef CPP_PGI_COMPILER
  #     undef CPP_SGI_COMPILER
  #     undef CPP_SUNPRO_COMPILER
  #     undef CPP_SYSC_COMPILER
  #     undef CPP_TENDRA_COMPILER
  #     undef CPP_WATCOM_COMPILER
  #   undef CPP_ENDIAN
  #   undef CPP_ENDIAN_RUNTIME
  #     undef CPP_BYTE_BIG_ENDIAN
  #     undef CPP_BYTE_LITTLE_ENDIAN
  #     undef CPP_MIXED_ENDIAN
  #     undef CPP_WORD_BIG_ENDIAN
  #     undef CPP_WORD_LITTLE_ENDIAN
  #   undef CPP_FRONTEND
  #     undef CPP_CLANG_FRONTEND
  #     undef CPP_GNUC_FRONTEND
  #     undef CPP_MSVC_FRONTEND
  #   undef CPP_PREPROCESSOR_FORMAT
  #     undef CPP_PREPROCESSOR_FORMAT_CHECK
  #     undef CPP_PREPROCESSOR_FORMAT_SELECT
  #     undef CPP_PREPROCESSOR_MSVC_FORMAT
  #     undef CPP_PREPROCESSOR_STANDARD_FORMAT
  #   undef CPP_VENDOR
  #     undef CPP_APPLE_MACINTOSH_VENDOR
  #     undef CPP_CYGWIN_VENDOR
  #     undef CPP_HAIKU_VENDOR
  #     undef CPP_LINUX_VENDOR
  #     undef CPP_MICROSOFT_WINDOWS_VENDOR
  #     undef CPP_NINTENDO_VENDOR
  #     undef CPP_UNIX_VENDOR
  #   undef CPP_VERSION
  #   undef LAPYS_MAX_ARITY
  #   undef LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH
  #   undef choose
  #     undef choose_false
  #     undef choose_true
  #   undef empty
  #   undef float16_t
  #   undef float32_t
  #   undef float64_t
  #   undef float128_t
  #   undef int128_t
  #   undef uint128_t
  #   ifndef __cpp_static_assert
  #     undef static_assert
  #       undef static_assert_declaration
  #         undef static_assert_1u
  #         undef static_assert_2u
  #   endif
  # endif
  #
  # undef arityof
  # undef boundsas
  # undef boundsof
  # undef constfunc
  #   undef constfunc_
  #   undef constfunc_false
  #   undef constfunc_true
  # undef constint
  #   undef constint_1u
  #   undef constint_2u
  # undef constvar
  # undef discard
  # undef enumint
  # undef exceptof
  # undef exceptspec
  #   if CPP_VERSION < 2011uL
  #     undef exceptspec_false
  #     undef exceptspec_true
  #     undef noexcept
  #   endif
  # undef included
  # undef init
  # undef lref
  # undef member_lref
  # undef member_rlref
  # undef member_rref
  # undef mustinline
  # undef mustreturn
  # undef nilinit
  # undef nodecay
  # undef nodecayparam
  # undef noeval
  # undef noexit
  # undef noinline
  # undef nouniqueaddr
  # undef nullptr
  # undef preprocessed
  # undef restricted
  # undef rlref
  # undef rref
  # ifdef typeof
  #   undef notypeof
  #   undef typeof
  # endif
  # undef varinit
  #endif

  #undef LAPYS_PREPROCESSOR_GUARD
  #undef LAPYS_MODULE_EXTENSIONS
  #undef LAPYS_MODULE_TRAITS
#endif
