/* [Apple Macintosh] ... */
#if defined(__APPLE__ ) && defined(__MACH__)
    /* Definition > ... */
    #undef ldk__detected_platform
    #define ldk__detected_platform ldk_platform__macintosh
#endif
