/* ... */
#ifndef char8_t
#include "polyfills/char8_t.hpp"
#endif

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC CLK_TCK
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef INFINITY
#define INFINITY HUGE_VAL
#endif

#ifndef NULL
#define NULL 0x0
#endif

#if __STDC_VERSION__ < 199901L
#define constexpr
#define inline
#define noexcept throw()
#endif

#ifndef VK_HANGUL
#define VK_HANGUL VK_HANGUEL
#endif
