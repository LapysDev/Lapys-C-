/* Definition > ... [Linux] */
#define environment__is_linux (defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__))

/* Import */
#if environment__is_linux || (\
    defined(__CYGWIN__) || \
    defined(__clang__) || defined(__clang_major__) || defined(__clang_minor__) || defined(__clang_patchlevel__) || \
    defined(__GNUC__) || defined(__GNUC_MINOR__) || defined(__GNUC_PATCHLEVEL__) || defined(__GNUG__) || \
    defined(_MSC_VER) \
)

#  include <fcntl.h> // File Control
#  include <unistd.h> // UNIX Standard Library
#endif
