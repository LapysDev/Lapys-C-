/* Features -->
    - LAPYS_MODULE_EXTENSIONS

    - CPP_ARCHITECTURE;        CPP_*_ARCHITECTURE
    - CPP_COMPILER;            CPP_*_COMPILER
    - CPP_ENDIAN;              CPP_*_ENDIAN; CPP_ENDIAN_RUNTIME
    - CPP_FRONTEND;            CPP_*_FRONTEND
    - CPP_HOSTED;
    - CPP_PREPROCESSOR_FORMAT; CPP_PREPROCESSOR_*_FORMAT
    - CPP_VENDOR;              CPP_*_VENDOR
    - CPP_VERSION == 1997uL | 2011uL | 2014uL | 2017uL | 2020uL | 2023uL

    - apply                 (f, bool, f, ...)
    - apply_comma           (...)
    - apply_expression_begin(...)
    - apply_expression_end  (...)
    - apply_*               (...)
    - arity                 (N)
    - boundsof              (...)
    - boundsspec            (...)
    - choose                (false | true, ..., ...); choose(N, ...)
    - combine               (A, B)
    - constfunc             (false | true)
    - constint              (T, name, value)
    - countof               (...)
    - defer                 (f, ...)
    - defined               (macro)
    - enumint               (T, name)
    - exceptof              (...)
    - exceptspec            (false | true)
    - included              (<source.cpp>); included("source.cpp")
    - init                  (...)
    - nilinit               (T)
    - noeval                (...)
    - novoid                (...)
    - nul                   ()
    - param_fref            (name)
    - parse                 (...)
    - preprocessed          (macro)
    - refspec               (...)
    - stall                 (...)
    - static_assert         (bool, "...")
    - stringify             (...)
    - subapply              (f, bool, f, ...)
    - typeof                (...)

    - constvar
    - decl
    - discard
    - final
    - float16_t
    - float32_t
    - float64_t
    - float128_t
    - fref
    - func
    - int128_t
    - lref
    - member_lref
    - member_rlref
    - member_rref
    - mustinline
    - noexit
    - noignore
    - noinline
    - nouniqueaddr
    - nullptr
    - restricted
    - rlref
    - rref
    - uint128_t
    - varinit(value)
*/
#ifndef LAPYS_MODULE_EXTENSIONS
# define LAPYS_MODULE_EXTENSIONS
  /* Deletion ->> Silently remove stray tokens used in conditional/ iterative/ recursive function-like macro substitutions */
  #undef _FORMAT
  #undef choose_
  #undef constfunc_
  #undef CPP_PREPROCESSOR_
  #undef exceptspec_
  #undef ISO
  #undef MSVC

  /* Definition */
  // : [C++ Compiler] ->> `CPP_COMPILER` attempts to avoid backends to otherwise strictly identify the main vendor --- CITE (Lapys)
  # define CPP_CIRCLE_COMPILER  0x01u // -> https://www.circle-lang.org/
  # define CPP_CLANG_COMPILER   0x02u // -> https://en.wikipedia.org/wiki/Clang
  # define CPP_GNUC_COMPILER    0x03u // -> https://en.wikipedia.org/wiki/GNU_Compiler_Collection
  # define CPP_INTEL_COMPILER   0x04u // -> https://en.wikipedia.org/wiki/Intel_C++
  # define CPP_LLVM_COMPILER    0x05u // -> https://en.wikipedia.org/wiki/LLVM
  # define CPP_MSVC_COMPILER    0x06u // -> https://en.wikipedia.org/wiki/Visual_studio
  # define CPP_NVCC_COMPILER    0x07u // -> https://docs.nvidia.com/hpc-sdk/compilers/hpc-compilers-ref-guide/
  #                                   // ->> Unsupported compilers
  # define CPP_BORLAND_COMPILER 0x08u // -> https://en.wikipedia.org/wiki/C_plus_plus_builder
  # define CPP_COMEAU_COMPILER  0x09u // -> https://en.wikipedia.org/wiki/Comeau_C/C++
  # define CPP_DEC_COMPILER     0x0Au // -> https://www.openvms.compaq.com/openvms/brochures/deccplus/
  # define CPP_DIAB_COMPILER    0x0Bu // -> https://www.windriver.com/products/development_suite/wind_river_compiler/
  # define CPP_DMC_COMPILER     0x0Cu // -> https://en.wikipedia.org/wiki/Digital_Mars
  # define CPP_EDG_COMPILER     0x0Du // -> https://en.wikipedia.org/wiki/Edison_Design_Group
  # define CPP_GCCXML_COMPILER  0x0Eu // -> https://en.wikipedia.org/wiki/GNU_Compiler_Collection
  # define CPP_GHS_COMPILER     0x0Fu // -> https://en.wikipedia.org/wiki/Green_Hills_Software
  # define CPP_HIGHC_COMPILER   0x10u // ->
  # define CPP_HPACC_COMPILER   0x11u // ->
  # define CPP_IAR_COMPILER     0x12u // ->
  # define CPP_IBM_COMPILER     0x13u // -> https://en.wikipedia.org/wiki/VisualAge
  # define CPP_KCC_COMPILER     0x14u // ->
  # define CPP_MPW_COMPILER     0x15u // -> https://en.wikipedia.org/wiki/Macintosh_Programmer's_Workshop
  # define CPP_MRI_COMPILER     0x16u // -> https://www.mentor.com/microtec/
  # define CPP_MWERKS_COMPILER  0x17u // -> https://en.wikipedia.org/wiki/CodeWarrior
  # define CPP_PALM_COMPILER    0x18u // ->
  # define CPP_PATH_COMPILER    0x19u // -> https://en.wikipedia.org/wiki/PathScale
  # define CPP_PGI_COMPILER     0x1Au // -> https://en.wikipedia.org/wiki/The_Portland_Group
  # define CPP_SGI_COMPILER     0x1Bu // -> https://en.wikipedia.org/wiki/MIPSpro
  # define CPP_SUNPRO_COMPILER  0x1Cu // -> https://en.wikipedia.org/wiki/Oracle_Solaris_Studio
  # define CPP_SYSC_COMPILER    0x1Du // -> https://www.dignus.com/dcxx/
  # define CPP_TENDRA_COMPILER  0x1Eu // -> https://en.wikipedia.org/wiki/TenDRA_Compiler
  # define CPP_WATCOM_COMPILER  0x1Fu // -> https://en.wikipedia.org/wiki/Watcom

  #if defined __circle_lang__
  # define CPP_COMPILER CPP_CIRCLE_COMPILER
  #elif defined __ICC or defined __INTEL_COMPILER or defined __INTEL_LLVM_COMPILER
  # define CPP_COMPILER CPP_INTEL_COMPILER
  #elif defined __clang__
  # define CPP_COMPILER CPP_CLANG_COMPILER
  #elif defined __GNUC__
  # define CPP_COMPILER CPP_GNUC_COMPILER
  #elif defined _MSC_VER
  # define CPP_COMPILER CPP_MSVC_COMPILER
  #elif defined __llvm__
  # define CPP_COMPILER CPP_LLVM_COMPILER
  # // ->> Unsupported compilers
  #elif defined __BORLANDC__ or defined __CODEGEARC__
  # define CPP_COMPILER CPP_BORLAND_COMPILER
  #elif defined __COMO__ or defined __COMO_VERSION__
  # define CPP_COMPILER CPP_COMEAU_COMPILER
  #elif defined __COMPILER_VER__ or defined __IBMCPP__ or defined __xlC__ or defined __xlc__
  # define CPP_COMPILER CPP_IBM_COMPILER
  #elif defined __CUDACC_VER_BUILD__ or defined __CUDACC_VER_MAJOR__ or defined __CUDACC_VER_MINOR__ or defined __NVCC__ or defined __NVCOMPILER
  # define CPP_COMPILER CPP_NVCC_COMPILER
  #elif defined __CWCC__ or defined __MWERKS__
  # define CPP_COMPILER CPP_MWERKS_COMPILER
  #elif defined __DCC__ or defined __VERSION_NUMBER__
  # define CPP_COMPILER CPP_DIAB_COMPILER
  #elif defined __DECC or defined __DECC_VER or defined __DECCXX or defined __DECCXX_VER
  # define CPP_COMPILER CPP_DEC_COMPILER
  #elif defined __DMC__
  # define CPP_COMPILER CPP_DMC_COMPILER
  #elif defined __EDG__
  # define CPP_COMPILER CPP_EDG_COMPILER
  #elif defined __GCCXML__
  # define CPP_COMPILER CPP_GCCXML_COMPILER
  #elif defined __GHS_VERSION_NUMBER__ or defined __ghs or defined __ghs__
  # define CPP_COMPILER CPP_GHS_COMPILER
  #elif defined __HIGHC__
  # define CPP_COMPILER CPP_HIGHC_COMPILER
  #elif defined __HP_aCC
  # define CPP_COMPILER CPP_HPACC_COMPILER
  #elif defined __IAR_SYSTEMS_ICC__ or defined __VER__
  # define CPP_COMPILER CPP_IAR_COMPILER
  #elif defined __KCC or defined __KCC_VERSION
  # define CPP_COMPILER CPP_KCC_COMPILER
  #elif defined __MRC__ or defined MPW_C or defined MPW_CPLUS
  # define CPP_COMPILER CPP_MPW_COMPILER
  #elif defined __PATHCC__ or defined __PATHCC_MINOR__ or defined __PATHCC_PATCHLEVEL__
  # define CPP_COMPILER CPP_PATH_COMPILER
  #elif defined __PGI or defined __PGIC__ or defined __PGIC_MINOR__ or defined __PGIC_PATCHLEVEL__
  # define CPP_COMPILER CPP_PGI_COMPILER
  #elif defined __SUNPRO_C or defined __SUNPRO_CC
  # define CPP_COMPILER CPP_SUNPRO_COMPILER
  #elif defined __SYSC_ZARCH__
  # define CPP_COMPILER CPP_SYSC_COMPILER
  #elif defined __TenDRA__
  # define CPP_COMPILER CPP_TENDRA_COMPILER
  #elif defined __WATCOMC__
  # define CPP_COMPILER CPP_WATCOM_COMPILER
  #elif defined _COMPILER_VERSION or defined __sgi or defined _SGI_COMPILER_VERSION or defined sgi
  # define CPP_COMPILER CPP_SGI_COMPILER
  #elif defined _MRI
  # define CPP_COMPILER CPP_MRI_COMPILER
  #elif defined _PACC_VER
  # define CPP_COMPILER CPP_PALM_COMPILER
  #else
  # define CPP_COMPILER 0x00u
  #endif

  // : [C++ Front-end]
  # define CPP_CLANG_FRONTEND 0x01u
  # define CPP_GNUC_FRONTEND  0x02u
  # define CPP_MSVC_FRONTEND  0x04u

  #if defined __clang__
  # define CPP_FRONTEND CPP_CLANG_FRONTEND
  #elif defined __GNUC__
  # define CPP_FRONTEND CPP_GNUC_FRONTEND
  #elif defined _MSC_VER
  # define CPP_FRONTEND CPP_MSVC_FRONTEND
  #else
  # define CPP_FRONTEND 0x00u
  #endif

  // : [C++ Version] ->> Assume most universal version, otherwise
  #if CPP_COMPILER == CPP_MSVC_COMPILER
  # ifndef _MSVC_LANG
  #   define CPP_VERSION 2014uL
  # elif _MSVC_LANG == 201402L
  #   define CPP_VERSION 2014uL
  # elif _MSVC_LANG <= 201703L
  #   define CPP_VERSION 2017uL
  # elif _MSVC_LANG <= 202002L
  #   define CPP_VERSION 2020uL
  # endif
  #endif

  #ifndef CPP_VERSION
  # ifndef __cplusplus
  #   define CPP_VERSION 1997uL
  # elif __cplusplus <= 199711L
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

  /* Import > C++ Standard Library */
  #if (CPP_VERSION >= 2020uL) and (CPP_COMPILER == CPP_CLANG_COMPILER or CPP_COMPILER == CPP_GNUC_COMPILER or CPP_COMPILER == CPP_INTEL_COMPILER or CPP_COMPILER == CPP_MSVC_COMPILER or CPP_COMPILER == CPP_NVCC_COMPILER)
  # include <version> // Language Support
  #endif

  #if CPP_VERSION >= 2023uL
  # include <stdfloat> // Standard Float ->> Optional in freestanding environments?
  #endif

  /* Definition */
  // : [Preprocessor Substitution] ->> Evaluate preprocessor token as conditional boolean
  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # pragma clang diagnostic push
  # pragma clang diagnostic ignored "-Wvariadic-macros"
  #elif CPP_COMPILER == CPP_GNUC_COMPILER
  # pragma GCC diagnostic push
  # pragma GCC diagnostic ignored "-Wvariadic-macros"
  # pragma GCC system_header // ->> `-Wno-variadic-macros` doesn't work as it ought to
  #endif
    #define preprocessed(...) (__VA_ARGS__ + 0)
  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # pragma clang diagnostic pop
  #elif CPP_COMPILER == CPP_GNUC_COMPILER
  # pragma GCC diagnostic pop
  #endif

  // : [Source File Inclusion] ->> Conditionally preferable error diagnostics when `#include`ing other source files
  #if CPP_VERSION >= 2017uL
  # define included(path) (__has_include decl(path))
  #elif CPP_FRONTEND == CPP_CLANG_FRONTEND or CPP_FRONTEND == CPP_GNUC_FRONTEND
  # ifdef __has_include
  #   define included(path) (__has_include decl(path))
  # else
  #   define included(path) (false)
  #   undef  included
  # endif
  #endif
  #
  #ifndef included
  # ifdef __has_include
  #   define included(path) (__has_include decl(path))
  # else
  #   define included(path) (true) // ->> Presume `path` exists by default
  # endif
  #endif

  // : [C++ Architecture] --- CITE (Lapys)
  # define CPP_ALPHA_ARCHITECTURE         0x01u // -> https://en.wikipedia.org/wiki/DEC_Alpha
  # define CPP_ARM_ARCHITECTURE           0x02u // -> https://en.wikipedia.org/wiki/ARM_architecture
  # define CPP_BLACKFIN_ARCHITECTURE      0x03u //
  # define CPP_CONVEX_ARCHITECTURE        0x04u // -> https://en.wikipedia.org/wiki/Convex_Computer
  # define CPP_E2K_ARCHITECTURE           0x05u // -> https://en.wikipedia.org/wiki/Elbrus_2000
  # define CPP_HP_PA_RISC_ARCHITECTURE    0x06u // -> https://en.wikipedia.org/wiki/PA-RISC_family
  # define CPP_INTEL_ITANIUM_ARCHITECTURE 0x07u // -> https://en.wikipedia.org/wiki/Ia64
  # define CPP_INTEL_X86_64_ARCHITECTURE  0x08u // -> https://en.wikipedia.org/wiki/X86-64
  # define CPP_INTEL_X86_ARCHITECTURE     0x09u // -> https://en.wikipedia.org/wiki/X86
  # define CPP_MIPS_ARCHITECTURE          0x0Au // -> https://en.wikipedia.org/wiki/MIPS_architecture
  # define CPP_MOTOROLA_68K_ARCHITECTURE  0x0Bu // -> https://en.wikipedia.org/wiki/M68k
  # define CPP_POWER_PC_64_ARCHITECTURE   0x0Cu // -> https://en.wikipedia.org/wiki/PowerPC
  # define CPP_POWER_PC_ARCHITECTURE      0x0Du // -> https://en.wikipedia.org/wiki/PowerPC
  # define CPP_PTX_ARCHITECTURE           0x0Eu // -> https://en.wikipedia.org/wiki/Parallel_Thread_Execution
  # define CPP_PYRAMID_9810_ARCHITECTURE  0x0Fu //
  # define CPP_RISC_V_ARCHITECTURE        0x10u //
  # define CPP_RS_6000_ARCHITECTURE       0x11u // -> https://en.wikipedia.org/wiki/RS/6000
  # define CPP_SPARC_ARCHITECTURE         0x12u // -> https://en.wikipedia.org/wiki/SPARC
  # define CPP_SUPER_H_ARCHITECTURE       0x13u // -> https://en.wikipedia.org/wiki/SuperH
  # define CPP_SYSTEM_370_ARCHITECTURE    0x14u // -> https://en.wikipedia.org/wiki/System/370
  # define CPP_SYSTEM_390_ARCHITECTURE    0x15u // -> https://en.wikipedia.org/wiki/System/390
  # define CPP_Z_ARCHITECTURE             0x16u // -> https://en.wikipedia.org/wiki/Z/Architecture

  #if defined __370__ or defined __THW_370__
  # define CPP_ARCHITECTURE CPP_SYSTEM_370_ARCHITECTURE
  #elif defined __aarch64__ or defined __AARCH64EL__ or defined __arm64 or defined __arm__ or defined __ARM_ARCH or defined __ARM_ARCH_4__ or defined __ARM_ARCH_4T__ or defined __ARM_ARCH_5TE__ or defined __ARM_ARCH_5TEJ__ or defined __ARM_ARCH_6K__ or defined __ARM_ARCH_6KZ__ or defined __ARM_ARCH_6T2__ or defined __ARM_ARCH_6Z__ or defined __ARM_ARCH_7__ or defined __ARM_ARCH_7A__ or defined __ARM_ARCH_7M__ or defined __ARM_ARCH_7R__ or defined __TARGET_ARCH_ARM or defined __TARGET_ARCH_THUMB or defined __thumb__ or defined _M_ARM or defined _M_ARM64
  # define CPP_ARCHITECTURE CPP_ARM_ARCHITECTURE
  #elif defined __alpha or defined __alpha__ or defined __alpha_ev4__ or defined __alpha_ev5__ or defined __alpha_ev6__ or defined _M_ALPHA
  # define CPP_ARCHITECTURE CPP_ALPHA_ARCHITECTURE
  #elif defined __amd64 or defined __amd64__ or defined __x86_64 or defined __x86_64__ or defined _M_X64
  # define CPP_ARCHITECTURE CPP_INTEL_X86_64_ARCHITECTURE
  #elif defined __bfin__ or defined __BFIN__ or defined bfin or defined BFIN
  # define CPP_ARCHITECTURE CPP_BLACKFIN_ARCHITECTURE
  #elif defined __convex__ or defined __convex_c1__ or defined __convex_c2__ or defined __convex_c32__ or defined __convex_c34__ or defined __convex_c38__
  # define CPP_ARCHITECTURE CPP_CONVEX_ARCHITECTURE
  #elif defined __CUDA_ARCH__
  # define CPP_ARCHITECTURE CPP_PTX_ARCHITECTURE
  #elif defined __e2k__
  # define CPP_ARCHITECTURE CPP_E2K_ARCHITECTURE
  #elif defined __hppa or defined __HPPA11__ or defined __HPPA20__ or defined __hppa__ or defined __HPPA__ or defined __PA7100__ or defined __PA8000__ or defined __RISC2_0__ or defined _PA_RISC1_0 or defined _PA_RISC1_1 or defined _PA_RISC2_0
  # define CPP_ARCHITECTURE CPP_HP_PA_RISC_ARCHITECTURE
  #elif defined __i386 or defined __i386__ or defined __i386__ or defined __i486__ or defined __i486__ or defined __i586__ or defined __i586__ or defined __i686__ or defined __i686__ or defined __I86__ or defined __I86__ or defined __INTEL__ or defined __THW_INTEL__ or defined _M_IX86 or defined _M_IX86 or defined _X86_ or defined i386
  # define CPP_ARCHITECTURE CPP_INTEL_X86_ARCHITECTURE
  #elif defined __ia64 or defined __ia64__ or defined __IA64__ or defined __itanium__ or defined _IA64 or defined _M_IA64
  # define CPP_ARCHITECTURE CPP_INTEL_ITANIUM_ARCHITECTURE
  #elif defined __m68k__ or defined __mc68000 or defined __mc68000__ or defined __mc68010 or defined __mc68010__ or defined __mc68020 or defined __mc68020__ or defined __mc68030 or defined __mc68030__ or defined __mc68040 or defined __mc68040__ or defined __mc68060 or defined __mc68060__ or defined M68000 or defined mc68000 or defined mc68010 or defined mc68020 or defined mc68030 or defined mc68040 or defined mc68060
  # define CPP_ARCHITECTURE CPP_MOTOROLA_68K_ARCHITECTURE
  #elif defined __mips or defined __MIPS__ or defined __MIPS_ISA2__ or defined __MIPS_ISA3__ or defined __MIPS_ISA4__ or defined _MIPS_ISA_MIPS1 or defined _MIPS_ISA_MIPS2 or defined _MIPS_ISA_MIPS3 or defined _MIPS_ISA_MIPS4 or defined _R3000 or defined _R4000
  # define CPP_ARCHITECTURE CPP_MIPS_ARCHITECTURE
  #elif defined __powerpc or defined __powerpc64__ or defined __powerpc__ or defined __POWERPC__ or defined __ppc or defined __ppc601__ or defined __ppc603__ or defined __ppc604__ or defined __ppc604__ or defined __ppc64__ or defined __PPC64__ or defined __ppc__ or defined __PPC__ or defined __PPCBROADWAY__ or defined __PPCGECKO__ or defined _ARCH_601 or defined _ARCH_603 or defined _ARCH_PPC or defined _ARCH_PPC64 or defined _M_PPC or defined _XENON
  # define CPP_ARCHITECTURE CPP_POWER_PC_ARCHITECTURE
  #elif defined __powerpc64__ or defined __ppc64__ or defined __PPC64__ or defined _ARCH_PPC64
  # define CPP_ARCHITECTURE CPP_POWER_PC_64_ARCHITECTURE
  #elif defined __riscv
  # define CPP_ARCHITECTURE CPP_RISC_V_ARCHITECTURE
  #elif defined __s390__ or defined __s390x__
  # define CPP_ARCHITECTURE CPP_SYSTEM_390_ARCHITECTURE
  #elif defined __sh__ or defined __SH5__ or defined __SH4__ or defined __sh3__ or defined __SH3__ or defined __sh2__ or defined __sh1__
  # define CPP_ARCHITECTURE CPP_SUPER_H_ARCHITECTURE
  #elif defined __sparc or defined __sparc__ or defined __sparc_v8__ or defined __sparc_v9__ or defined __sparcv8 or defined __sparcv9
  # define CPP_ARCHITECTURE CPP_SPARC_ARCHITECTURE
  #elif defined __SYSC_ZARCH__
  # define CPP_ARCHITECTURE CPP_Z_ARCHITECTURE
  #elif defined __THW_RS6000 or defined _ARCH_PWR or defined _ARCH_PWR2 or defined _IBMR2 or defined _POWER
  # define CPP_ARCHITECTURE CPP_RS_6000_ARCHITECTURE
  #elif defined pyr
  # define CPP_ARCHITECTURE CPP_PYRAMID_9810_ARCHITECTURE
  #else
  # define CPP_ARCHITECTURE 0x00u
  #endif

  // : [C++ Environment]
  #ifdef __STDC_HOSTED__
  # if   __STDC_HOSTED__ == 1
  #   define CPP_HOSTED true
  # elif __STDC_HOSTED__ == 0
  #   define CPP_HOSTED false
  # endif
  #else
  # define CPP_HOSTED (CPP_FRONTEND == CPP_CLANG_FRONTEND or CPP_FRONTEND == CPP_GNUC_FRONTEND or CPP_FRONTEND == CPP_MSVC_FRONTEND)
  #endif

  // : [C++ Preprocessor]
  #if preprocessed(LAPYS_PREPROCESSOR)
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   pragma clang diagnostic push
  #   pragma clang diagnostic ignored "-Wvariadic-macros"
  # elif CPP_COMPILER == CPP_GNUC_COMPILER
  #   pragma GCC diagnostic push
  #   pragma GCC diagnostic ignored "-Wvariadic-macros"
  #   pragma GCC system_header // ->> `-Wno-variadic-macros` doesn't work as it ought to
  # endif
    #define CPP_PREPROCESSOR_FORMAT CPP_PREPROCESSOR_FORMAT_CHECK(~, MSVC)
    # define CPP_PREPROCESSOR_ISO_FORMAT  0x0u
    # define CPP_PREPROCESSOR_MSVC_FORMAT 0x1u
    #
    # define CPP_PREPROCESSOR_FORMAT_CHECK(...)             CPP_PREPROCESSOR_FORMAT_SELECT(__VA_ARGS__)
    # define CPP_PREPROCESSOR_FORMAT_SELECT(arguments, ...) defer(combine, defer(combine, CPP_PREPROCESSOR_, choose(2u, arguments, ISO, ~)), _FORMAT)
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   pragma clang diagnostic pop
  #elif CPP_COMPILER == CPP_GNUC_COMPILER
  #   pragma GCC diagnostic pop
  # endif
  #endif

  // : [C++ Vendor] ->> Cross-platform (partial) awareness
  # define CPP_APPLE_MACINTOSH_VENDOR   0x01u
  # define CPP_CYGWIN_VENDOR            0x02u
  # define CPP_HAIKU_VENDOR             0x04u
  # define CPP_LINUX_VENDOR             0x08u
  # define CPP_MICROSOFT_WINDOWS_VENDOR 0x10u
  # define CPP_NINTENDO_VENDOR          0x20u
  # define CPP_UNIX_VENDOR              0x40u

  #if defined _3DS or defined __SWITCH__
  # define CPP_VENDOR CPP_NINTENDO_VENDOR
  #elif defined __APPLE__ or defined __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ or defined __MACH__
  # define CPP_VENDOR (CPP_APPLE_MACINTOSH_VENDOR | CPP_UNIX_VENDOR)
  #elif defined __bsdi__ or defined __DragonFly__ or defined __FreeBSD__ or defined __FreeBSD_version or defined __NETBSD__ or defined __NETBSD_version or defined NetBSD0_8 or defined NetBSD0_9 or defined NetBSD1_0 or defined __OpenBSD__ or defined OpenBSD2_0 or defined OpenBSD2_1 or defined OpenBSD2_2 or defined OpenBSD2_3 or defined OpenBSD2_4 or defined OpenBSD2_5 or defined OpenBSD2_6 or defined OpenBSD2_7 or defined OpenBSD2_8 or defined OpenBSD2_9 or defined OpenBSD3_0 or defined OpenBSD3_1 or defined OpenBSD3_2 or defined OpenBSD3_3 or defined OpenBSD3_4 or defined OpenBSD3_5 or defined OpenBSD3_6 or defined OpenBSD3_7 or defined OpenBSD3_8 or defined OpenBSD3_9 or defined OpenBSD4_0 or defined OpenBSD4_1 or defined OpenBSD4_2 or defined OpenBSD4_3 or defined OpenBSD4_4 or defined OpenBSD4_5 or defined OpenBSD4_6 or defined OpenBSD4_7 or defined OpenBSD4_8 or defined OpenBSD4_9 or defined __OS400__ or defined __unix or defined __unix__ or defined _POSIX_SOURCE or defined _XOPEN_SOURCE or defined __QNX__ or defined __QNXNTO__ or defined _NTO_VERSION or defined sun or defined __sun or defined __sysv__ or defined __SVR4 or defined __svr4__ or defined _SYSTYPE_SVR4 or defined VMS or defined __VMS or defined __VMS_VER or defined unix
  # define CPP_VENDOR CPP_UNIX_VENDOR
  #elif defined __CYGWIN__
  # define CPP_VENDOR (CPP_CYGWIN_VENDOR | CPP_UNIX_VENDOR)
  #elif defined __gnu_linux__ or defined linux or defined __linux or defined __linux__
  # define CPP_VENDOR (CPP_LINUX_VENDOR | CPP_UNIX_VENDOR)
  #elif defined __HAIKU__
  # define CPP_VENDOR CPP_HAIKU_VENDOR
  #elif defined __NT__ or defined __TOS_WIN__ or defined __WIN32__ or defined __WINDOWS__ or defined _WIN16 or defined _WIN32 or defined _WIN32_WCE or defined _WIN64
  # define CPP_VENDOR CPP_MICROSOFT_WINDOWS_VENDOR
  #elif defined WIN32
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

  #if included(<machine/endian.h>) and (defined __APPLE__ or defined __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ or defined __MACH__ or defined __OpenBSD__ or defined OpenBSD2_0 or defined OpenBSD2_1 or defined OpenBSD2_2 or defined OpenBSD2_3 or defined OpenBSD2_4 or defined OpenBSD2_5 or defined OpenBSD2_6 or defined OpenBSD2_7 or defined OpenBSD2_8 or defined OpenBSD2_9 or defined OpenBSD3_0 or defined OpenBSD3_1 or defined OpenBSD3_2 or defined OpenBSD3_3 or defined OpenBSD3_4 or defined OpenBSD3_5 or defined OpenBSD3_6 or defined OpenBSD3_7 or defined OpenBSD3_8 or defined OpenBSD3_9 or defined OpenBSD4_0 or defined OpenBSD4_1 or defined OpenBSD4_2 or defined OpenBSD4_3 or defined OpenBSD4_4 or defined OpenBSD4_5 or defined OpenBSD4_6 or defined OpenBSD4_7 or defined OpenBSD4_8 or defined OpenBSD4_9)
  # include <machine/endian.h>
  #elif included(<sys/endian.h>) and (defined __bsdi__ or defined __DragonFly__ or defined __FreeBSD__ or defined __FreeBSD_version or defined __NETBSD__ or defined __NETBSD_version or defined NetBSD0_8 or defined NetBSD0_9 or defined NetBSD1_0 or defined __OpenBSD__ or defined OpenBSD2_0 or defined OpenBSD2_1 or defined OpenBSD2_2 or defined OpenBSD2_3 or defined OpenBSD2_4 or defined OpenBSD2_5 or defined OpenBSD2_6 or defined OpenBSD2_7 or defined OpenBSD2_8 or defined OpenBSD2_9 or defined OpenBSD3_0 or defined OpenBSD3_1 or defined OpenBSD3_2 or defined OpenBSD3_3 or defined OpenBSD3_4 or defined OpenBSD3_5 or defined OpenBSD3_6 or defined OpenBSD3_7 or defined OpenBSD3_8 or defined OpenBSD3_9 or defined OpenBSD4_0 or defined OpenBSD4_1 or defined OpenBSD4_2 or defined OpenBSD4_3 or defined OpenBSD4_4 or defined OpenBSD4_5 or defined OpenBSD4_6 or defined OpenBSD4_7 or defined OpenBSD4_8 or defined OpenBSD4_9)
  # include <sys/endian.h>
  #endif

  #ifdef __cpp_lib_endian // --> 201907L
  # include <bit>
  # undef CPP_ENDIAN_RUNTIME
  # if CPP_VERSION < 2011uL
  #   define CPP_ENDIAN_RUNTIME (0x00 == (std::endian::native & (std::endian::big | std::endian::little)) and sizeof decl(unsigned char) != sizeof decl(unsigned long))
  #   define CPP_ENDIAN (std::endian::native == std::endian::little ? CPP_BYTE_LITTLE_ENDIAN : std::endian::native == std::endian::big ? CPP_BYTE_BIG_ENDIAN : sizeof decl(unsigned char) == sizeof decl(unsigned long)      or reinterpret_cast<unsigned char const&>(static_cast<unsigned long      const&>(1uL))  == 1u ? CPP_BYTE_LITTLE_ENDIAN : reinterpret_cast<unsigned char const*>(&static_cast<unsigned long      const&>(1uL)) [sizeof decl(unsigned long)      - 1u] == 1u ? CPP_BYTE_BIG_ENDIAN : CPP_MIXED_ENDIAN)
  # else
  #   define CPP_ENDIAN_RUNTIME (0x00 == (std::endian::native & (std::endian::big | std::endian::little)) and sizeof decl(unsigned char) != sizeof decl(unsigned long long))
  #   define CPP_ENDIAN (std::endian::native == std::endian::little ? CPP_BYTE_LITTLE_ENDIAN : std::endian::native == std::endian::big ? CPP_BYTE_BIG_ENDIAN : sizeof decl(unsigned char) == sizeof decl(unsigned long long) or reinterpret_cast<unsigned char const&>(static_cast<unsigned long long const&>(1uLL)) == 1u ? CPP_BYTE_LITTLE_ENDIAN : reinterpret_cast<unsigned char const*>(&static_cast<unsigned long long const&>(1uLL))[sizeof decl(unsigned long long) - 1u] == 1u ? CPP_BYTE_BIG_ENDIAN : CPP_MIXED_ENDIAN)
  # endif
  #else
  # if included(<machine/endian.h>) and (CPP_VENDOR & CPP_APPLE_MACINTOSH_VENDOR)
  #   include <machine/endian.h>
  # elif included(<endian.h>) and (defined __CYGWIN__ or defined __GLIBC__ or defined __gnu_linux__ or defined __linux or defined __linux__ or defined __QNX__ or defined __QNXNTO__ or defined __sun or defined __SVR4 or defined __svr4__ or defined __sysv__ or defined __unix or defined __unix__ or defined __VMS or defined __VMS_VER or defined _NTO_VERSION or defined _POSIX_SOURCE or defined _SYSTYPE_SVR4 or defined _XOPEN_SOURCE or defined linux or defined sun or defined unix or defined VMS)
  #   include <endian.h>
  # elif included(<sys/endian.h>) and (defined __bsdi__ or defined __DragonFly__ or defined __FreeBSD__ or defined __FreeBSD_version or defined __NETBSD__ or defined __NETBSD_version or defined NetBSD0_8 or defined NetBSD0_9 or defined NetBSD1_0 or defined __OpenBSD__ or defined OpenBSD2_0 or defined OpenBSD2_1 or defined OpenBSD2_2 or defined OpenBSD2_3 or defined OpenBSD2_4 or defined OpenBSD2_5 or defined OpenBSD2_6 or defined OpenBSD2_7 or defined OpenBSD2_8 or defined OpenBSD2_9 or defined OpenBSD3_0 or defined OpenBSD3_1 or defined OpenBSD3_2 or defined OpenBSD3_3 or defined OpenBSD3_4 or defined OpenBSD3_5 or defined OpenBSD3_6 or defined OpenBSD3_7 or defined OpenBSD3_8 or defined OpenBSD3_9 or defined OpenBSD4_0 or defined OpenBSD4_1 or defined OpenBSD4_2 or defined OpenBSD4_3 or defined OpenBSD4_4 or defined OpenBSD4_5 or defined OpenBSD4_6 or defined OpenBSD4_7 or defined OpenBSD4_8 or defined OpenBSD4_9 or defined __OS400__ or defined __unix)
  #   include <sys/endian.h>
  # endif
  #
  #
  # if false == defined CPP_ENDIAN and defined __GLIBC__ // ->> Compiler endian constants
  #   if defined _BYTE_ORDER
  #     if defined _LITTLE_ENDIAN
  #       if _BYTE_ORDER == _LITTLE_ENDIAN
  #         define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #       endif
  #     elif defined _BIG_ENDIAN
  #       if _BYTE_ORDER == _BIG_ENDIAN
  #         define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #       endif
  #     elif defined _PDP_ENDIAN
  #       if _BYTE_ORDER == _PDP_ENDIAN
  #         define CPP_ENDIAN CPP_WORD_LITTLE_ENDIAN
  #       endif
  #     endif
  #   elif defined __BYTE_ORDER
  #     if defined __LITTLE_ENDIAN
  #       if __BYTE_ORDER == __LITTLE_ENDIAN
  #         define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #       endif
  #     elif defined __BIG_ENDIAN
  #       if __BYTE_ORDER == __BIG_ENDIAN
  #         define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #       endif
  #     elif defined __PDP_ENDIAN
  #       if __BYTE_ORDER == __PDP_ENDIAN
  #         define CPP_ENDIAN CPP_WORD_LITTLE_ENDIAN
  #       endif
  #     endif
  #   endif
  # endif
  #
  # if false == defined CPP_ENDIAN and defined __GNUC__
  #   ifdef __BYTE_ORDER__
  #     if defined __ORDER_LITTLE_ENDIAN__
  #       if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  #         define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #       endif
  #     elif defined __ORDER_BIG_ENDIAN__
  #       if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  #         define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #       endif
  #     elif defined __ORDER_PDP_ENDIAN__
  #       if __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
  #         define CPP_ENDIAN CPP_WORD_LITTLE_ENDIAN
  #       endif
  #     endif
  #   endif
  # endif
  #
  # if false == defined CPP_ENDIAN
  #   if (defined __LITTLE_ENDIAN__ and false == defined __BIG_ENDIAN__) or (defined _LITTLE_ENDIAN and false == defined _BIG_ENDIAN)
  #     define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #   elif (defined __BIG_ENDIAN__ and false == defined __LITTLE_ENDIAN__) or (defined _BIG_ENDIAN and false == defined _LITTLE_ENDIAN)
  #     define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #   endif
  # endif
  #
  # if false == defined CPP_ENDIAN // ->> Vendor endian constants
  #   if defined __ARMEL__ or defined __MIPSEL or defined __MIPSEL__ or defined __THUMBEL__ or defined _MIPSEL
  #     define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #   elif defined __AARCH64EB__ or defined __ARMEB__ or defined __MIPSEB or defined __MIPSEB__ or defined __THUMBEB__ or defined _MIPSEB
  #     define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #   endif
  # endif
  #
  # if false == defined CPP_ENDIAN
  #   if defined _M_AMD64 or CPP_ARCHITECTURE == CPP_ALPHA_ARCHITECTURE or CPP_ARCHITECTURE == CPP_BLACKFIN_ARCHITECTURE or CPP_ARCHITECTURE == CPP_INTEL_ITANIUM_ARCHITECTURE or CPP_ARCHITECTURE == CPP_INTEL_X86_64_ARCHITECTURE or CPP_ARCHITECTURE == CPP_INTEL_X86_ARCHITECTURE or (CPP_ARCHITECTURE == CPP_ARM_ARCHITECTURE and (CPP_VENDOR & CPP_MICROSOFT_WINDOWS_VENDOR))
  #     define CPP_ENDIAN CPP_BYTE_LITTLE_ENDIAN
  #   elif defined __hpux or CPP_ARCHITECTURE == CPP_HP_PA_RISC_ARCHITECTURE or CPP_ARCHITECTURE == CPP_MOTOROLA_68K_ARCHITECTURE or CPP_ARCHITECTURE == CPP_POWER_PC_ARCHITECTURE or CPP_ARCHITECTURE == CPP_RS_6000_ARCHITECTURE or CPP_ARCHITECTURE == CPP_SPARC_ARCHITECTURE or CPP_ARCHITECTURE == CPP_SYSTEM_370_ARCHITECTURE or CPP_ARCHITECTURE == CPP_SYSTEM_390_ARCHITECTURE or CPP_ARCHITECTURE == CPP_Z_ARCHITECTURE
  #     define CPP_ENDIAN CPP_BYTE_BIG_ENDIAN
  #   endif
  # endif
  #
  # if false == defined CPP_ENDIAN // ->> Language endian constants
  #   undef  CPP_ENDIAN_RUNTIME
  #   if CPP_VERSION < 2011uL
  #     define CPP_ENDIAN_RUNTIME (sizeof decl(unsigned char) != sizeof decl(unsigned long))
  #     define CPP_ENDIAN (false == CPP_ENDIAN_RUNTIME or reinterpret_cast<unsigned char const&>(static_cast<unsigned long      const&>(1uL))  == 1u ? CPP_BYTE_LITTLE_ENDIAN : reinterpret_cast<unsigned char const*>(&static_cast<unsigned long      const&>(1uL)) [sizeof decl(unsigned long)      - 1u] == 1u ? CPP_BYTE_BIG_ENDIAN : CPP_MIXED_ENDIAN)
  #   else
  #     define CPP_ENDIAN_RUNTIME (sizeof decl(unsigned char) != sizeof decl(unsigned long long))
  #     define CPP_ENDIAN (false == CPP_ENDIAN_RUNTIME or reinterpret_cast<unsigned char const&>(static_cast<unsigned long long const&>(1uLL)) == 1u ? CPP_BYTE_LITTLE_ENDIAN : reinterpret_cast<unsigned char const*>(&static_cast<unsigned long long const&>(1uLL))[sizeof decl(unsigned long long) - 1u] == 1u ? CPP_BYTE_BIG_ENDIAN : CPP_MIXED_ENDIAN)
  #   endif
  # endif
  #endif

  /* Definition */
  // : [Constant Function] ->> Attempts to specify a constant evaluable function; Only accepts tokens `false` and `true`
  #define constfunc(unrelaxed) constfunc_ ## unrelaxed decl
  #ifdef __cpp_constexpr // --> 200704L
  # if CPP_VERSION > 2011uL or __cpp_constexpr >= 201304L
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

  // : [Constant Integer] ->> Specifies a constant evaluable integer
  #if CPP_VERSION < 2011uL
  # define constint(type, name, value) constint_2u(__LINE__, type, name, value)
  #else
  # define constint(type, name, ...) constint_2u(__LINE__, type, name, __VA_ARGS__)
  #endif

  # ifdef __cpp_constexpr // --> 200704L
  #   if CPP_VERSION < 2011uL
  #     define constint_1u(id, type, name, value)                                                        constexpr static type name varinit((value))
  #   else
  #     define constint_1u(id, type, name, ...)                                                          constexpr static type name varinit((__VA_ARGS__))
  #   endif
  # elif CPP_VERSION < 2011uL
  #   define constint_1u(id, type, name, value) enum        { name ## id = static_cast<int> (value) };       const static type name varinit((value))
  # else
  #   define constint_1u(id, type, name, ...)   enum : type { name ## id = static_cast<type>(__VA_ARGS__) }; const static type name varinit((__VA_ARGS__))
  # endif
  # if CPP_VERSION < 2011uL
  #   define constint_2u(id, type, name, value) constint_1u(id, type, name, value)
  # else
  #   define constint_2u(id, type, name, ...) constint_1u(id, type, name, __VA_ARGS__)
  # endif

  // : [Constant Variable] ->> Attempts to specify a constant evaluable variable
  #ifdef __cpp_constexpr // --> 200704L
  # define constvar constexpr
  #else
  # define constvar
  #endif

  // : [Deleted Function Specifier] ->> Attempts to mark a function ill-formed to evaluate; Recommended to use exclusively from `inline`
  #if CPP_VERSION < 2011uL
  # define discard // ->> Not defining the function also mostly works
  #else
  # define discard = delete
  #endif

  // : [Exception Operator] ->> Determines if an expression can `throw` an exception
  #if CPP_VERSION < 2011uL
  # define exceptof(expression) false
  #else
  # define exceptof(...) noexcept decl(__VA_ARGS__)
  #endif

  // : [Exception Specifier] ->> Attempts to explicitly anticipate `throw` in a specified function
  #if CPP_VERSION < 2011uL
  # define exceptspec(specification) exceptspec_ ## specification // --> choose(specification, exceptspec_true, exceptspec_false)
  #   if CPP_COMPILER == CPP_MSVC_COMPILER
  #     define exceptspec_false throw decl(...)
  #     define exceptspec_true  noexcept
  #   else
  #     define exceptspec_false
  #     define exceptspec_true noexcept
  #   endif
  # define noexcept throw decl() // ->> Shim the `noexcept` keyword
  #else
  # define exceptspec(specification) noexcept decl(specification)
  #endif

  // : [Expression Reference Specification] ->> Determines if an expression is an lvalue or rvalue reference
  #if CPP_VERSION < 2011uL
  # define refspec(expression) (sizeof(::Lapys::Traits::reference_true) == sizeof(::Lapys::Traits::refspec(), (expression),  ::Lapys::Traits::refspec()))
  #else
  # define refspec(...)        (sizeof(::Lapys::Traits::reference_true) == sizeof(::Lapys::Traits::refspec(), (__VA_ARGS__), ::Lapys::Traits::refspec()))
  #endif

  // : [Expression `void` Filter] ->> Reference-qualifies, then re-evaluates `void` expressions as `struct ::Lapys::Traits::novoid` expressions
  #if CPP_VERSION < 2011uL
  # define novoid(expression) (::Lapys::Traits::novoid(), (expression),  ::Lapys::Traits::novoid())
  #else
  # define novoid(...)        (::Lapys::Traits::novoid(), (__VA_ARGS__), ::Lapys::Traits::novoid())
  #endif

  // : [Floating-Point Types] ->> Acknowledges extended floating-point types
  #if __STDCPP_FLOAT16_T__
  # if LAPYS_PREPROCESSOR_GUARD and defined float16_t
  #   error Lapys C++: Unexpected `float16_t` macro definition
  # endif
  # define float16_t std::float16_t
  #elif defined float16_t
  # error Lapys C++: Unexpected `float16_t` macro definition
  #endif

  #if __STDCPP_FLOAT32_T__
  # if LAPYS_PREPROCESSOR_GUARD and defined float32_t
  #   error Lapys C++: Unexpected `float32_t` macro definition
  # endif
  # define float32_t std::float32_t
  #elif defined float32_t
  # error Lapys C++: Unexpected `float32_t` macro definition
  #endif

  #if __STDCPP_FLOAT64_T__
  # if LAPYS_PREPROCESSOR_GUARD and defined float64_t
  #   error Lapys C++: Unexpected `float64_t` macro definition
  # endif
  # define float64_t std::float64_t
  #elif defined float64_t
  # error Lapys C++: Unexpected `float64_t` macro definition
  #endif

  #if __STDCPP_FLOAT128_T__
  # if LAPYS_PREPROCESSOR_GUARD and defined float128_t
  #   error Lapys C++: Unexpected `float128_t` macro definition
  # endif
  # define float128_t std::float128_t
  #elif defined float128_t
  # error Lapys C++: Unexpected `float128_t` macro definition
  #endif

  // : [Forwarding Reference] ->> Perfect-forwarding reference-qualification
  #ifdef __cpp_rvalue_references // --> 200610L
  # define fref             &&
  # define param_fref(name) decl (&&name)
  #else
  # define fref             const&
  # define param_fref(name) const decl (&name)
  #endif

  // : [Guard] ->> Intended to guard against function-like macros
  #define decl

  // : [Inheritance Specifier] ->> Attempt to specify a `class` or `struct` as non-inheritable
  #if CPP_VERSION < 2011uL
  # define final
  #endif

  // : [Initialization] ->> Common initialization syntax
  #ifdef __cpp_initializer_lists // --> 200806L
  # define nilinit(type)     {}
  # define varinit(argument) {argument}
  # if CPP_VERSION < 2011uL
  #   define init(arguments) {arguments}
  # else
  #   define init(...)       {__VA_ARGS__}
  # endif
  #else
  # define nilinit(type)     = type decl ()
  # define varinit(argument) = argument
  # if CPP_VERSION < 2011uL
  #   define init(arguments) (arguments)
  # else
  #   define init(...)       (__VA_ARGS__)
  # endif
  #endif

  // : [Integral Enumeration] ->> Attempts to define an enumeration with a specified underlying type
  #if CPP_VERSION < 2011uL
  # define enumint(type, name) enum name
  #else
  # define enumint(type, name) enum name : type
  #endif

  // : [Integral Types] ->> Acknowledges extended integer types
  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # define int128_t  __int128_t
  # define uint128_t __uint128_t
  #elif CPP_COMPILER == CPP_GNUC_COMPILER
  # ifdef __SIZEOF_INT128__
  #   pragma GCC diagnostic push
  #   pragma GCC diagnostic ignored "-Wpedantic"
  #   define int128_t           __int128
  #   define uint128_t unsigned __int128
  #   pragma GCC diagnostic pop
  # elif LAPYS_PREPROCESSOR_GUARD
  #   ifdef int128_t
  #     error Lapys C++: Unexpected `int128_t` macro definition
  #   endif
  #   ifdef uint128_t
  #     error Lapys C++: Unexpected `uint128_t` macro definition
  #   endif
  # endif
  #elif defined __cpp_lib_ranges // --> 201911L
  # if CPP_VERSION < 2011uL
  #   define int128_t  std::ranges::range_difference_t<std::ranges::iota_view<long,          long> >
  #   define uint128_t std::ranges::range_difference_t<std::ranges::iota_view<unsigned long, unsigned long> >
  # else
  #   define int128_t  std::ranges::range_difference_t<std::ranges::iota_view<long long,          long long> >
  #   define uint128_t std::ranges::range_difference_t<std::ranges::iota_view<unsigned long long, unsigned long long> >
  # endif
  #elif LAPYS_PREPROCESSOR_GUARD
  # ifdef int128_t
  #   error Lapys C++: Unexpected `int128_t` macro definition
  # endif
  # ifdef uint128_t
  #   error Lapys C++: Unexpected `uint128_t` macro definition
  # endif
  #endif

  // : [Parameter Pack]
  #if CPP_VERSION < 2011uL
  # define countof(pack) ::Lapys::Traits::collection<::Lapys::Traits::constant<std::size_t, sizeof typeid decl(pack), true>...>::length
  #else
  # define countof(pack) sizeof...(pack)
  #endif

  // : [Pointer Aliasing]
  #if CPP_COMPILER == CPP_CIRCLE_COMPILER or CPP_COMPILER == CPP_CLANG_COMPILER or CPP_COMPILER == CPP_GNUC_COMPILER or CPP_COMPILER == CPP_INTEL_COMPILER or CPP_COMPILER == CPP_MSVC_COMPILER
  # if false == defined restricted and CPP_COMPILER != CPP_MSVC_COMPILER
  #   ifdef __restrict__
  #     define restricted __restrict__
  #   endif
  # endif
  # if false == defined restricted
  #   ifndef __restrict
  #     define restricted __restrict
  #   endif
  # endif
  # if false == defined restricted
  #   define restricted
  # endif
  #else
  # define restricted
  #endif

  // : [Pointer Nullity]
  #if CPP_VERSION < 2011uL
  # define nullptr NULL // ->> Closest null pointer alias for function pointers
  #else
  # define nullptr nullptr
  #endif

  // : [Reference Qualifier] ->> Attempts to reference-qualify
  #ifdef __cpp_rvalue_references // --> 200610L
  # define lref  &
  # define rlref rref
  # define rref  &&
  #else
  # define lref  &
  # define rlref lref
  # define rref
  #endif

  #ifdef __cpp_ref_qualifiers // --> 200710L
  # define member_lref  &
  # define member_rlref member_rref
  # define member_rref  &&
  #else
  # define member_lref
  # define member_rlref member_lref
  # define member_rref
  #endif

  // : [Return Specifier] ->> Attempts to modify certain attributes of specified functions
  #if CPP_COMPILER == CPP_CLANG_COMPILER or CPP_COMPILER == CPP_GNUC_COMPILER
  # define mustinline __attribute__((always_inline))
  #elif CPP_COMPILER == CPP_INTEL_COMPILER or CPP_COMPILER == CPP_MSVC_COMPILER
  # define mustinline __forceinline
  #else
  # define mustinline inline
  #endif

  #if CPP_VERSION < 2011uL
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   define noexit _Noreturn
  # elif CPP_COMPILER == CPP_GNUC_COMPILER
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
  # if CPP_COMPILER == CPP_CLANG_COMPILER or CPP_COMPILER == CPP_GNUC_COMPILER
  #   define noignore __attribute__((warn_unused_result))
  # else
  #   define noignore
  # endif
  #else
  # define noignore [[nodiscard]]
  #endif

  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # if CPP_VERSION > 1997uL
  #   define noinline [[clang::noinline]]
  # elif __has_attribute(noinline)
  #   define noinline __attribute__((noinline))
  # else
  #   define noinline
  # endif
  #elif CPP_COMPILER == CPP_GNUC_COMPILER or CPP_COMPILER == CPP_INTEL_COMPILER
  #   define noinline __attribute__((noinline))
  #elif CPP_COMPILER == CPP_MSVC_COMPILER
  #   define noinline __declspec(noinline)
  #else
  #   define noinline // ->> Does not prevent constant-folding
  #endif

  // : [Storage Specifier]
  #if CPP_COMPILER == CPP_MSVC_COMPILER
  # pragma warning(disable: 4848)
  # define nouniqueaddr [[msvc::no_unique_address]]
  #elif CPP_VERSION >= 2020uL or CPP_COMPILER == CPP_INTEL_COMPILER or (CPP_VERSION > 1997uL and (CPP_COMPILER == CPP_CLANG_COMPILER or CPP_COMPILER == CPP_GNUC_COMPILER))
  # define nouniqueaddr [[no_unique_address]]
  #else
  # define nouniqueaddr
  #endif

  // : [Type Alignment Specifier] ->> Attempt to align members or variables on a specified boundary, or evaluate an acceptable alignment width of a specified type
  #if CPP_VERSION < 2011uL
  # if CPP_COMPILER == CPP_GNUC_COMPILER and included(<stdalign.h>)
  #  include <stdalign.h> // ->> since C++11
  # elif CPP_COMPILER == CPP_MSVC_COMPILER
  #  define __alignof_is_defined true
  # endif
  #
  # ifdef __alignof_is_defined
  #   ifdef _Alignof
  #     if CPP_VERSION < 2011uL
  #       define boundsof(type) _Alignof(type)
  #     else
  #       define boundsof(...)  _Alignof(__VA_ARGS__)
  #     endif
  #   else
  #     if CPP_VERSION < 2011uL
  #       define boundsof(type) alignof(type)
  #     else
  #       define boundsof(...)  alignof(__VA_ARGS__)
  #     endif
  #   endif
  # else
  #   if CPP_COMPILER == CPP_GNUC_COMPILER
  #     if CPP_VERSION < 2011uL
  #       define boundsof(type) __alignof__(type)
  #     else
  #       define boundsof(...)  __alignof__(__VA_ARGS__)
  #     endif
  #   elif CPP_COMPILER == CPP_MSVC_COMPILER
  #     if CPP_VERSION < 2011uL
  #       define boundsof(type) __alignof(type)
  #     else
  #       define boundsof(...)  __alignof(__VA_ARGS__)
  #     endif
  #   else
  #     if CPP_VERSION < 2011uL
  #       define boundsof(type) sizeof decl(type)
  #     else
  #       define boundsof(...)  sizeof decl(__VA_ARGS__)
  #     endif
  #   endif
  # endif
  #
  # ifdef __alignas_is_defined
  #   ifdef _Alignas
  #     if CPP_VERSION < 2011uL
  #       define boundsspec(argument) _Alignas(argument)
  #     else
  #       define boundsspec(...)      _Alignas(__VA_ARGS__)
  #     endif
  #   else
  #     if CPP_VERSION < 2011uL
  #       define boundsspec(argument) alignas(argument)
  #     else
  #       define boundsspec(...)      alignas(__VA_ARGS__)
  #     endif
  #   endif
  # else
  #   if CPP_COMPILER == CPP_GNUC_COMPILER
  #     if CPP_VERSION < 2011uL
  #       define boundsspec(argument) __attribute__(aligned(argument))
  #     else
  #       define boundsspec(...)      __attribute__(aligned(__VA_ARGS__))
  #     endif
  #   elif CPP_COMPILER == CPP_MSVC_COMPILER
  #     if CPP_VERSION < 2011uL
  #       define boundsspec(argument) __declspec(align(argument))
  #     else
  #       define boundsspec(...)      __declspec(align(__VA_ARGS__))
  #     endif
  #   else
  #     if CPP_VERSION < 2011uL
  #       define boundsspec(argument)
  #     else
  #       define boundsspec(...)
  #     endif
  #   endif
  # endif
  #else
  # if CPP_VERSION < 2011uL
  #   define boundsspec(argument) alignas decl(argument)
  #   define boundsof(type)       alignof decl(type)
  # else
  #   define boundsspec(...) alignas decl(__VA_ARGS__)
  #   define boundsof(...)   alignof decl(__VA_ARGS__)
  # endif
  #endif

  // : [Type Inspection Specifier] ->> Reflect on the resulting type of an expression
  #ifndef typeof
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   pragma clang diagnostic push
  #   pragma clang diagnostic ignored "-Wkeyword-macro"
  # endif
  #   if CPP_FRONTEND == CPP_MSVC_FRONTEND or defined __cpp_decltype // --> 200707L
  #     if CPP_VERSION < 2011uL
  #       define typeof(expression) decltype(expression)
  #     else
  #       define typeof(...)        decltype(__VA_ARGS__)
  #     endif
  #   elif CPP_FRONTEND == CPP_GNUC_FRONTEND
  #     if CPP_VERSION < 2011uL
  #       define typeof(expression) __decltype(expression)
  #     else
  #       define typeof(...)        __decltype(__VA_ARGS__)
  #     endif
  #   elif CPP_FRONTEND == CPP_CLANG_FRONTEND // --- NOTE (Lapys) -> Presume `__typeof__(...)` does not acknowledge reference qualifications
  #     if CPP_VERSION < 2011uL               // --- WARN (Lapys) -> Incorrectly evaluates non-const-volatile-qualified rvalue reference types as non-reference types i.e., `T&& == T`
  #       define typeof(expression)          ::Lapys::Traits::conditional<::Lapys::Traits::is_void<__typeof__(expression)> ::value or not refspec((expression)),  __typeof__(expression),           ::Lapys::Traits::conditional<sizeof decl(::Lapys::Traits::boolean_true) == sizeof decl (::Lapys::Traits::typeinfo::is_lvalue_reference)(novoid((expression))),  __typeof__(novoid((expression)))  lref,          ::Lapys::Traits::conditional<sizeof decl(::Lapys::Traits::boolean_true) == sizeof decl (::Lapys::Traits::typeinfo::is_rvalue_reference)(novoid((expression))),  __typeof__(novoid((expression)))  rref, __typeof__(novoid((expression)))> ::type>::type>::type decl
  #     else
  #       define typeof(...)        typename ::Lapys::Traits::conditional<::Lapys::Traits::is_void<__typeof__(__VA_ARGS__)>::value or not refspec((__VA_ARGS__)), __typeof__(__VA_ARGS__), typename ::Lapys::Traits::conditional<sizeof decl(::Lapys::Traits::boolean_true) == sizeof decl (::Lapys::Traits::typeinfo::is_lvalue_reference)(novoid((__VA_ARGS__))), __typeof__(novoid((__VA_ARGS__))) lref, typename ::Lapys::Traits::conditional<sizeof decl(::Lapys::Traits::boolean_true) == sizeof decl (::Lapys::Traits::typeinfo::is_rvalue_reference)(novoid((__VA_ARGS__))), __typeof__(novoid((__VA_ARGS__))) rref, __typeof__(novoid((__VA_ARGS__)))>::type>::type>::type decl
  #     endif
  #   endif
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   pragma clang diagnostic pop
  # endif
  #endif

  // : [Unevaluated Expression] ->> Returns a constant whilst parsing, but not evaluating its `expression` operand
  #if CPP_COMPILER == CPP_MSVC_COMPILER or CPP_VERSION > 1997uL
  # define noeval noexcept decl
  #else
  # include <typeinfo> // Type Information
  # define noeval typeid decl
  #endif

  // : [Assertion] ->> Compile-time assertion
  #ifndef __cpp_static_assert // --> 200410L
    template <bool>
    union static_assert_declaration {
      constfunc(true) decl (static_assert_declaration)(char const[]) noexcept {}
    };

    template <> // ... ->> alternatively declare `static_assert_declaration<false>` but not define it
    union static_assert_declaration<false> {
      private:
        template <typename, unsigned char = 0x00u>
        struct static_assert_message;

        template <unsigned char specialization>
        struct static_assert_message<char const, specialization> final {};

      public:
        template <typename type, std::size_t capacity> // ->> Single constructor, no overload disambiguation
        constfunc(false) decl (static_assert_declaration)(type decl (&)[capacity]) exceptspec(false) /* --> static_assert_declaration<false> */ {
          static_assert_message<type>(); // ->> Assert that `type` is `char const`, the element type used by expected string literals
          throw static_assert_declaration<false>(*this); // ->> Error handling is unfortunately runtime-only so re-throw a copy of itself and indirectly call `std::terminate(...)`
        }
    };

    #define static_assert static_assert_declaration
    # define static_assert_declaration(condition, message) static_assert_2u(__LINE__, condition, message)
    #   ifdef __cpp_nsdmi // --> 200809L
    #     define static_assert_1u(id, condition, message) ::static_assert_declaration<(condition)> _ ## id = ::static_assert_declaration<(condition)>(message)
    #   elif CPP_VERSION < 2011uL
    #     define static_assert_1u(id, condition, message) typedef          ::Lapys::Traits::conditional<static_cast<bool>(condition), ::static_assert_declaration<(condition)> >::type _ ## id
    #   else
    #     define static_assert_1u(id, condition, message) typedef typename ::Lapys::Traits::conditional<static_cast<bool>(condition), ::static_assert_declaration<(condition)> >::type _ ## id
    #   endif
    #   define static_assert_2u(id, condition, message) static_assert_1u(id, condition, "" message "")
  #endif

  /* Definition */
  #if (LAPYS_MAX_ARITY) > 127u
  # undef  LAPYS_MAX_ARITY
  # define LAPYS_MAX_ARITY 127u
  #endif

  #define choose(argument, truthy, falsy) defer(combine, choose_, argument)(truthy, falsy)
  # define choose_false(truthy, falsy) falsy
  # define choose_true(truthy, falsy)  truthy

  #define nul()

  #if CPP_FRONTEND == CPP_CLANG_FRONTEND
  # pragma clang diagnostic push
  # pragma clang diagnostic ignored "-Wc++20-compat"
  # pragma clang diagnostic ignored "-Wvariadic-macros"
  #elif CPP_FRONTEND == CPP_GNUC_FRONTEND
  # pragma GCC diagnostic push
  # pragma GCC diagnostic ignored "-Wvariadic-macros"
  # pragma GCC system_header // ->> `-Wno-variadic-macros` doesn't work as it ought to
  #endif
    #define apply_comma(argument, ...)            ,
    #define apply_expression_begin(argument, ...) (
    #define apply_expression_end(argument, ...)   )
  #if CPP_COMPILER == CPP_CLANG_COMPILER
  # pragma clang diagnostic pop
  #elif CPP_COMPILER == CPP_GNUC_COMPILER
  # pragma GCC diagnostic pop
  #endif

  #if preprocessed(LAPYS_PREPROCESSOR)
  # if CPP_FRONTEND == CPP_CLANG_FRONTEND
  #   pragma clang diagnostic push
  #   pragma clang diagnostic ignored "-Wc++20-compat"
  #   pragma clang diagnostic ignored "-Wvariadic-macros"
  # elif CPP_FRONTEND == CPP_GNUC_FRONTEND
  #   pragma GCC diagnostic push
  #   pragma GCC diagnostic ignored "-Wvariadic-macros"
  #   pragma GCC system_header // ->> `-Wno-variadic-macros` doesn't work as it ought to
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
    # if CPP_COMPILER == CPP_CIRCLE_COMPILER or CPP_COMPILER == CPP_CLANG_COMPILER or CPP_COMPILER == CPP_GNUC_COMPILER or CPP_COMPILER == CPP_INTEL_COMPILER
    #   define choose_127u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, argument123, argument124, argument125, argument126, argument127, ...) argument127
    # else
    #   define choose_127u(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8, argument9, argument10, argument11, argument12, argument13, argument14, argument15, argument16, argument17, argument18, argument19, argument20, argument21, argument22, argument23, argument24, argument25, argument26, argument27, argument28, argument29, argument30, argument31, argument32, argument33, argument34, argument35, argument36, argument37, argument38, argument39, argument40, argument41, argument42, argument43, argument44, argument45, argument46, argument47, argument48, argument49, argument50, argument51, argument52, argument53, argument54, argument55, argument56, argument57, argument58, argument59, argument60, argument61, argument62, argument63, argument64, argument65, argument66, argument67, argument68, argument69, argument70, argument71, argument72, argument73, argument74, argument75, argument76, argument77, argument78, argument79, argument80, argument81, argument82, argument83, argument84, argument85, argument86, argument87, argument88, argument89, argument90, argument91, argument92, argument93, argument94, argument95, argument96, argument97, argument98, argument99, argument100, argument101, argument102, argument103, argument104, argument105, argument106, argument107, argument108, argument109, argument110, argument111, argument112, argument113, argument114, argument115, argument116, argument117, argument118, argument119, argument120, argument121, argument122, argument123, argument124, argument125, argument126, argument127) argument127
    # endif
    #endif

    #define arity(count) combine(arity_, count)
    # define arity_0u

    #undef  choose
    #define choose(argument, ...) defer(combine, choose_, argument)(__VA_ARGS__)
    # define choose_0u(...)
    # define choose_1u(argument1, ...)            argument1
    # define choose_2u(argument1, argument2, ...) argument2

    #define combine(argument1, argument2) argument1 ## argument2

    #define defer(function, ...) defer_1u(function, (__VA_ARGS__))
    # define defer_0u(function, ...)   function(__VA_ARGS__)
    # define defer_1u(function, call)  function call
    # define defer_2u(function, call)  defer_1u (function, call)
    # define defer_3u(function, call)  defer_2u (function, call)
    # define defer_4u(function, call)  defer_3u (function, call)
    # define defer_5u(function, call)  defer_4u (function, call)
    # define defer_6u(function, call)  defer_5u (function, call)
    # define defer_7u(function, call)  defer_6u (function, call)
    # define defer_8u(function, call)  defer_7u (function, call)
    # define defer_9u(function, call)  defer_8u (function, call)
    # define defer_10u(function, call) defer_9u (function, call)
    # define defer_11u(function, call) defer_10u(function, call)
    # define defer_12u(function, call) defer_11u(function, call)

    #undef apply
    # define apply_begin(function, condition, separator, currentArgument, nextArgument, ...) choose(condition(currentArgument, nextArgument, __VA_ARGS__), apply_continue, apply_break)( /* ->> Body of the `apply(...)` loop */ \
      function,                                                                                                                                                                                                                  \
      choose(condition(nextArgument, __VA_ARGS__), separator, apply_terminator),                                                                                                                                                 \
      stall(reapply)()stall((function, condition, separator, nextArgument, __VA_ARGS__, break)),                                                                                                                                 \
      currentArgument, nextArgument, __VA_ARGS__                                                                                                                                                                                 \
    )
    # undef  apply_condition                  // ->> Asserts to `false` or `true` by default
    # define apply_function(argument)argument // ->> Evaluates to `argument` by default
    # define apply_separator(argument, ...)   // ->> Does not separate by default
    #   define apply_condition_default ~, false
    #   define apply_function_default  ~, false
    #   define apply_separator_default ~, false
    #
    #   define apply_access(argument, ...)                      .
    #   define apply_access_pointer(argument, ...)              .*
    #   define apply_add(argument, ...)                         +
    #   define apply_assign(argument, ...)                      =
    #   define apply_bitwise_and(argument, ...)                 &
    #   define apply_bitwise_or(argument, ...)                  |
    #   define apply_bitwise_shift_left(argument, ...)          <<
    #   define apply_bitwise_shift_right(argument, ...)         >>
    #   define apply_bitwise_xor(argument, ...)                 ^
    #   define apply_boolean_and(argument, ...)                 &&
    #   define apply_boolean_or(argument, ...)                  ||
    #   define apply_compare(argument, ...)                     <=>
    #   define apply_conditional_falsy(argument, ...)           :
    #   define apply_conditional_truthy(argument, ...)          ?
    #   define apply_dereferenced_access(argument, ...)         ->
    #   define apply_dereferenced_access_pointer(argument, ...) ->*
    #   define apply_divide(argument, ...)                      /
    #   define apply_equals(argument, ...)                      ==
    #   define apply_greater(argument, ...)                     >
    #   define apply_greater_equals(argument, ...)              >=
    #   define apply_initializer_begin(argument, ...)           {
    #   define apply_initializer_end(argument, ...)             }
    #   define apply_lesser(argument, ...)                      <
    #   define apply_lesser_equals(argument, ...)               <=
    #   define apply_modulo(argument, ...)                      %
    #   define apply_multiply(argument, ...)                    *
    #   define apply_scope(argument, ...)                       ::
    #   define apply_subscript_begin(argument, ...)             [
    #   define apply_subscript_end(argument, ...)               ]
    #   define apply_subtract(argument, ...)                    -
    #   define apply_unequals(argument, ...)                    !=
    # define apply_break(function, separator, applyer, argument, ...) // ->> Stop expanding
    # define apply_continue(function, separator, applyer, argument, ...) function(argument)separator(argument, __VA_ARGS__) applyer
    # undef  apply_setup
    # define apply_terminator(argument, ...)
    # if CPP_PREPROCESSOR_FORMAT == CPP_PREPROCESSOR_ISO_FORMAT
    #   define apply(...) parse(apply_setup(__VA_ARGS__))
    #     define apply_condition(argument, ...) defer(choose_2u, reapply_ ## argument, true, ~)
    #     define apply_setup(function, condition, separator, ...) apply_begin(                            \
            choose(defer(choose_2u, apply_function_  ## function,  true, ~), function,  apply_function),  \
            choose(defer(choose_2u, apply_condition_ ## condition, true, ~), condition, apply_condition), \
            choose(defer(choose_2u, apply_separator_ ## separator, true, ~), separator, apply_separator), \
            __VA_ARGS__, break, break                                                                     \
          )
    # elif CPP_PREPROCESSOR_FORMAT == CPP_PREPROCESSOR_MSVC_FORMAT
    #   if CPP_COMPILER == CPP_INTEL_COMPILER
    #     define apply(...) parse(apply_setup(__VA_ARGS__))
    #       define apply_condition(argument, ...) defer_1u(choose_2u, (reapply_ ## argument, true, ~))
    #       define apply_setup(function, condition, separator, ...) defer_2u(apply_begin, (                 \
              choose(defer(choose_2u, apply_function_  ## function,  true, ~), function,  apply_function),  \
              choose(defer(choose_2u, apply_condition_ ## condition, true, ~), condition, apply_condition), \
              choose(defer(choose_2u, apply_separator_ ## separator, true, ~), separator, apply_separator), \
              __VA_ARGS__, break, break                                                                     \
            ))
    #   else
    #     define apply(...) parse_12u(defer(apply_setup, __VA_ARGS__))
    #       define apply_condition(argument, ...) stall(defer(choose_2u, choose_1u(reapply_ ## argument, ~), true))
    #       define apply_setup(function, condition, separator, ...) defer(apply_begin,                                           \
              stall(choose(defer(choose_2u, choose_1u(apply_function_  ## function,  ~), true, ~), function,  apply_function)),  \
              stall(choose(defer(choose_2u, choose_1u(apply_condition_ ## condition, ~), true, ~), condition, apply_condition)), \
              stall(choose(defer(choose_2u, choose_1u(apply_separator_ ## separator, ~), true, ~), separator, apply_separator)), \
              __VA_ARGS__, break, break                                                                                          \
            )
    #   endif
    # else
    #   error Variadic macro expansion feature `apply(...)` requested
    # endif
    # define reapply() apply_begin // ->> Succession of the `apply(...)` loop
    #   define reapply_break ~, false // ->> End     of the `apply(...)` loop

    #undef subapply // --> `subapply(...)`, `subapply_begin(...)`, `subapply_continue(...)`, and `subapply_setup(...)` are similar to their `apply(...)` counterparts
    # define subapply_begin(function, condition, separator, currentArgument, nextArgument, ...) choose(condition(currentArgument, nextArgument, __VA_ARGS__), subapply_continue, apply_break)( \
      function,                                                                                                                                                                                \
      choose(condition(nextArgument, __VA_ARGS__), separator, apply_terminator),                                                                                                               \
      stall(resubapply)()stall((function, condition, separator, nextArgument, __VA_ARGS__, break)),                                                                                            \
      currentArgument, nextArgument, __VA_ARGS__                                                                                                                                               \
    )
    # define subapply_continue(function, separator, applyer, argument, ...) function(argument)separator(argument, __VA_ARGS__) applyer
    # undef  subapply_setup
    # if CPP_PREPROCESSOR_FORMAT == CPP_PREPROCESSOR_ISO_FORMAT
    #   define subapply(...) subapply_setup(__VA_ARGS__)
    #     define subapply_setup(function, condition, separator, ...) subapply_begin(                      \
            choose(defer(choose_2u, apply_function_  ## function,  true, ~), function,  apply_function),  \
            choose(defer(choose_2u, apply_condition_ ## condition, true, ~), condition, apply_condition), \
            choose(defer(choose_2u, apply_separator_ ## separator, true, ~), separator, apply_separator), \
            __VA_ARGS__, break, break                                                                     \
          )
    # elif CPP_PREPROCESSOR_FORMAT == CPP_PREPROCESSOR_MSVC_FORMAT
    #   if CPP_COMPILER == CPP_INTEL_COMPILER
    #     define subapply(...) defer_1u(subapply_setup, (__VA_ARGS__))
    #       define subapply_setup(function, condition, separator, ...) subapply_begin(                           \
              choose(defer_1u(choose_2u, (apply_function_  ## function,  true, ~)), function,  apply_function),  \
              choose(defer_1u(choose_2u, (apply_condition_ ## condition, true, ~)), condition, apply_condition), \
              choose(defer_1u(choose_2u, (apply_separator_ ## separator, true, ~)), separator, apply_separator), \
              __VA_ARGS__, break, break                                                                          \
            )
    #   else
    #     define subapply(...) defer(subapply_setup, __VA_ARGS__)
    #       define subapply_setup(function, condition, separator, ...) defer(subapply_begin,                                     \
              stall(choose(defer(choose_2u, choose_1u(apply_function_  ## function,  ~), true, ~), function,  apply_function)),  \
              stall(choose(defer(choose_2u, choose_1u(apply_condition_ ## condition, ~), true, ~), condition, apply_condition)), \
              stall(choose(defer(choose_2u, choose_1u(apply_separator_ ## separator, ~), true, ~), separator, apply_separator)), \
              __VA_ARGS__, break, break                                                                                          \
            )
    #   endif
    # else
    #   error Variadic macro expansion feature `subapply(...)` requested
    # endif
    # define resubapply() subapply_begin

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
    # define parse_2u(...)  parse_1u (parse_1u (__VA_ARGS__))
    # define parse_3u(...)  parse_2u (parse_2u (__VA_ARGS__))
    # define parse_4u(...)  parse_3u (parse_3u (__VA_ARGS__))
    # define parse_5u(...)  parse_4u (parse_4u (__VA_ARGS__))
    # define parse_6u(...)  parse_5u (parse_5u (__VA_ARGS__))
    # define parse_7u(...)  parse_6u (parse_6u (__VA_ARGS__))
    # define parse_8u(...)  parse_7u (parse_7u (__VA_ARGS__))
    # define parse_9u(...)  parse_8u (parse_8u (__VA_ARGS__))
    # define parse_10u(...) parse_9u (parse_9u (__VA_ARGS__))
    # define parse_11u(...) parse_10u(parse_10u(__VA_ARGS__))
    # define parse_12u(...) parse_11u(parse_11u(__VA_ARGS__))

    #define stall(macro) stall_2u(macro)
    # define stall_1u(macro)  macro nul()
    # define stall_2u(macro)  macro nul nul()()
    # define stall_3u(macro)  macro nul nul nul()()()
    # define stall_4u(macro)  macro nul nul nul nul()()()()
    # define stall_5u(macro)  macro nul nul nul nul nul()()()()()
    # define stall_6u(macro)  macro nul nul nul nul nul nul()()()()()()
    # define stall_7u(macro)  macro nul nul nul nul nul nul nul()()()()()()()
    # define stall_8u(macro)  macro nul nul nul nul nul nul nul nul()()()()()()()()
    # define stall_9u(macro)  macro nul nul nul nul nul nul nul nul nul()()()()()()()()()
    # define stall_10u(macro) macro nul nul nul nul nul nul nul nul nul nul()()()()()()()()()()
    # define stall_11u(macro) macro nul nul nul nul nul nul nul nul nul nul nul()()()()()()()()()()()
    # define stall_12u(macro) macro nul nul nul nul nul nul nul nul nul nul nul nul()()()()()()()()()()()()

    #define stringify(argument) #argument
  # if CPP_COMPILER == CPP_CLANG_COMPILER
  #   pragma clang diagnostic pop
  # elif CPP_COMPILER == CPP_GNUC_COMPILER
  #   pragma GCC diagnostic pop
  # endif
  #endif
#endif
