/* Function */
    // Get Page Size
    #if ldk__detected_platform == ldk_platform__android || ldk__detected_platform == ldk_platform__linux
        inline std::size_t system__get_page_size(void) noexcept { return ::sysconf(_SC_PAGESIZE); }
    #elif ldk__detected_platform == ldk_platform__windows
        inline std::size_t system__get_page_size(void) noexcept { SYSTEM_INFO systemInformation; ::GetSystemInfo(&systemInformation); return systemInformation.dwPageSize; }
    #endif
