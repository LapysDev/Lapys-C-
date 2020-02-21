/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Global > ... */
    char *PROGRAM_TYPE = 0x0;

    /* ... */
    #if defined(__ANDROID__)
        const char PLATFORM_NAME[] = "Android";
    #elif defined(__APPLE__ ) && defined(__MACH__)
        const char PLATFORM_NAME[] = "Macintosh";
    #elif defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__)
        const char PLATFORM_NAME[] = "Linux";
    #elif defined(__TOS_WIN__) || defined(_WIN16) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32_WCE) || defined(_WIN64) || defined(__WINDOWS__)
        const char PLATFORM_NAME[] = "Windows";
    #endif
#endif
