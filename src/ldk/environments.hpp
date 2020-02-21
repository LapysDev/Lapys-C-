/* Import */
#include "environments/c.h" // C Standard Library
#include "environments/c++.hpp" // C++ Standard Library

/* Definition > ... */
#define ldk__detected_platform
#  define ldk_platform__android 1
#  define ldk_platform__linux 2
#  define ldk_platform__macintosh 3
#  define ldk_platform__windows 4

/* Import */
#include "environments/linux.h" // Linux
#include "environments/macintosh.h" // Apple Macintosh
#include "environments/windows.h" // Microsoft Windows
