/* Modification > System */
    // Get Page Size
    constexpr inline size_t System::getPageSize(void) noexcept {
        // ... Return
        #if environment__is_windows
            SYSTEM_INFO systemInformation {};
            ::GetSystemInfo(&systemInformation);
            return systemInformation.dwPageSize;
        #else
            return ::sysconf(_SC_PAGESIZE);
            return ::getpagesize();
        #endif
    }
