/* Import */
    // [...]
    #if defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__)
        #define IS_LINUX_ENVIRONMENT true

        #include <fcntl.h> // File Control
        #include <unistd.h> // UNIX Standard Library
    #else
        #define IS_LINUX_ENVIRONMENT false
    #endif
