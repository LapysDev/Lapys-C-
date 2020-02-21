/* [Linux] ... */
// Android
#ifdef __ANDROID__
    /* Definition > ... */
    #undef ldk__detected_platform
    #define ldk__detected_platform ldk_platform__android

// Linux
#elif defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__)
    /* Definition > ... */
    #undef ldk__detected_platform
    #define ldk__detected_platform ldk_platform__linux

    /* Import */
    #include <fcntl.h> // Functional
    #include <sys/mman.h> // Memory Manipulation
    #include <unistd.h> // UNIX Standard
#endif
