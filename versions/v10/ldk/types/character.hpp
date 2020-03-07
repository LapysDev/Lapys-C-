/* Class > Character */
struct character {
    /* ... */
    friend boolean;
    friend fraction;
    friend integer;
    friend null_pointer;
    friend number;
    friend pointer;
    friend primitive;
    friend raw_pointer;
    friend shared_smart_pointer;
    friend size;
    friend smart_pointer;
    friend string;
    friend unique_smart_pointer;
    friend wide;

    // [...]
    private:
        // Definition > Character Type
        #if CHAR8_MAX - CHAR8_MIN >= CHAR_MAX - CHAR_MIN && CHAR8_MAX - CHAR8_MIN >= CHAR16_MAX - CHAR16_MIN && CHAR8_MAX - CHAR8_MIN >= CHAR32_MAX - CHAR32_MIN && CHAR8_MAX - CHAR8_MIN >= WCHAR_MAX - WCHAR_MIN
            typedef char8_t character_type;
        #elif CHAR16_MAX - CHAR16_MIN >= CHAR_MAX - CHAR_MIN && CHAR16_MAX - CHAR16_MIN >= CHAR8_MAX - CHAR8_MIN && CHAR16_MAX - CHAR16_MIN >= CHAR32_MAX - CHAR32_MIN && CHAR16_MAX - CHAR16_MIN >= WCHAR_MAX - WCHAR_MIN
            typedef char16_t character_type;
        #elif CHAR32_MAX - CHAR32_MIN >= CHAR_MAX - CHAR_MIN && CHAR32_MAX - CHAR32_MIN >= CHAR8_MAX - CHAR8_MIN && CHAR32_MAX - CHAR32_MIN >= CHAR16_MAX - CHAR16_MIN && CHAR32_MAX - CHAR32_MIN >= WCHAR_MAX - WCHAR_MIN
            typedef char32_t character_type;
        #elif WCHAR_MAX - WCHAR_MIN >= CHAR_MAX - CHAR_MIN && WCHAR_MAX - WCHAR_MIN >= CHAR8_MAX - CHAR8_MIN && WCHAR_MAX - WCHAR_MIN >= CHAR16_MAX - CHAR16_MIN && WCHAR_MAX - WCHAR_MIN >= CHAR32_MAX - CHAR32_MIN
            typedef wchar_t character_type;
        #else
            typedef char character_type;
        #endif

    // [...]
    public:
};
