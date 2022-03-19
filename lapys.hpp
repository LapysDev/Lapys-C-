/* Constant > ... */
#ifndef LAPYS_MAX_ARITY
# define LAPYS_MAX_ARITY 255u
#endif

#ifndef LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH
# define LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH 500u // --> x > 1
#endif

/* Import */
#include "lapys/includes.hpp"

/* Deletion */
#undef CPP_COMPILER
# undef CPP__CLANG__COMPILER
# undef CPP__GCC__COMPILER
# undef CPP__ICC__COMPILER
# undef CPP__MSVC__COMPILER
#undef CPP_ENDIAN
# undef CPP__BIG__ENDIAN
# undef CPP__LITTLE__ENDIAN
# undef CPP__MIXED__ENDIAN
# undef CPP__WORDS_LITTLE__ENDIAN
#undef CPP_STANDARD_PREPROCESSOR
# undef CPP__MSVC__PREPROCESSOR
#undef CPP_VENDOR
# undef CPP__APPLE_MACINTOSH__VENDOR
# undef CPP__LINUX__VENDOR
# undef CPP__MICROSOFT_WINDOWS__VENDOR
# undef CPP__NINTENDO__VENDOR
# undef CPP__UNIX__VENDOR
#undef CPP_VERSION
#
#undef LAPYS_MAX_TEMPLATE_INSTANTIATION
#
#undef alignmentas
#undef alignmentof
#undef classenum
#undef constenum
#undef constfunc
# undef constfunc_false
# undef constfunc_true
#undef constvar
#undef discard
#undef empty
#undef exceptof
#undef exceptspec
# undef exceptspec_fail
# undef exceptspec_pass
#   undef exceptspec_check_true
#undef final
#undef init
#undef int128_t
#undef lref
#undef nodecay
#undef nodecayparam
#undef noexcept
#undef noexit
#undef noignore
#undef noinline
#undef nouniqueaddr
#undef rref
#undef second
#undef typeof
#undef uint128_t
#undef varinit
