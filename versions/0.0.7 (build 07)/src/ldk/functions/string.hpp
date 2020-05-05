/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Definition > ... */
    char* string__clone(char[]); const char* string__clone(const char[]);
    char8_t* string__clone(char8_t[]); const char8_t* string__clone(const char8_t[]);
    char16_t* string__clone(char16_t[]); const char16_t* string__clone(const char16_t[]);
    char32_t* string__clone(char32_t[]); const char32_t* string__clone(const char32_t[]);
    signed char* string__clone(signed char[]); const signed char* string__clone(const signed char[]);
    unsigned char* string__clone(unsigned char[]); const unsigned char* string__clone(const unsigned char[]);
    wchar_t* string__clone(wchar_t[]); const wchar_t* string__clone(const wchar_t[]);

    const char* string__concatenate(char[], char[]);
    const char* string__concatenate(char[], const char[]);
    const char* string__concatenate(const char[], char[]);
    const char* string__concatenate(const char[], const char[]);
    const char8_t* string__concatenate(char8_t[], char8_t[]);
    const char8_t* string__concatenate(char8_t[], const char8_t[]);
    const char8_t* string__concatenate(const char8_t[], char8_t[]);
    const char8_t* string__concatenate(const char8_t[], const char8_t[]);
    const char16_t* string__concatenate(char16_t[], char16_t[]);
    const char16_t* string__concatenate(char16_t[], const char16_t[]);
    const char16_t* string__concatenate(const char16_t[], char16_t[]);
    const char16_t* string__concatenate(const char16_t[], const char16_t[]);
    const char32_t* string__concatenate(char32_t[], char32_t[]);
    const char32_t* string__concatenate(char32_t[], const char32_t[]);
    const char32_t* string__concatenate(const char32_t[], char32_t[]);
    const char32_t* string__concatenate(const char32_t[], const char32_t[]);
    const signed char* string__concatenate(signed char[], signed char[]);
    const signed char* string__concatenate(signed char[], const signed char[]);
    const signed char* string__concatenate(const signed char[], signed char[]);
    const signed char* string__concatenate(const signed char[], const signed char[]);
    const unsigned char* string__concatenate(unsigned char[], unsigned char[]);
    const unsigned char* string__concatenate(unsigned char[], const unsigned char[]);
    const unsigned char* string__concatenate(const unsigned char[], unsigned char[]);
    const unsigned char* string__concatenate(const unsigned char[], const unsigned char[]);
    const wchar_t* string__concatenate(wchar_t[], wchar_t[]);
    const wchar_t* string__concatenate(wchar_t[], const wchar_t[]);
    const wchar_t* string__concatenate(const wchar_t[], wchar_t[]);
    const wchar_t* string__concatenate(const wchar_t[], const wchar_t[]);

    char* string__copy(char*&, char[]);
    char* string__copy(char*&, const char[]);
    char8_t* string__copy(char8_t*&, char8_t[]);
    char8_t* string__copy(char8_t*&, const char8_t[]);
    char16_t* string__copy(char16_t*&, char16_t[]);
    char16_t* string__copy(char16_t*&, const char16_t[]);
    char32_t* string__copy(char32_t*&, char32_t[]);
    char32_t* string__copy(char32_t*&, const char32_t[]);
    signed char* string__copy(signed char*&, signed char[]);
    signed char* string__copy(signed char*&, const signed char[]);
    unsigned char* string__copy(unsigned char*&, unsigned char[]);
    unsigned char* string__copy(unsigned char*&, const unsigned char[]);
    wchar_t* string__copy(wchar_t*&, wchar_t[]);
    wchar_t* string__copy(wchar_t*&, const wchar_t[]);

    char* string__free(char*&);
    char8_t* string__free(char8_t*&);
    char16_t* string__free(char16_t*&);
    char32_t* string__free(char32_t*&);
    signed char* string__free(signed char*&);
    unsigned char* string__free(unsigned char*&);
    wchar_t* string__free(wchar_t*&);

    boolean string__is_empty(char[]); boolean string__is_empty(const char[]);
    boolean string__is_empty(char8_t[]); boolean string__is_empty(const char8_t[]);
    boolean string__is_empty(char16_t[]); boolean string__is_empty(const char16_t[]);
    boolean string__is_empty(char32_t[]); boolean string__is_empty(const char32_t[]);
    boolean string__is_empty(signed char[]); boolean string__is_empty(const signed char[]);
    boolean string__is_empty(unsigned char[]); boolean string__is_empty(const unsigned char[]);
    boolean string__is_empty(wchar_t[]); boolean string__is_empty(const wchar_t[]);

    std::size_t string__length(char[]); std::size_t string__length(const char[]);
    std::size_t string__length(char8_t[]); std::size_t string__length(const char8_t[]);
    std::size_t string__length(char16_t[]); std::size_t string__length(const char16_t[]);
    std::size_t string__length(char32_t[]); std::size_t string__length(const char32_t[]);
    std::size_t string__length(signed char[]); std::size_t string__length(const signed char[]);
    std::size_t string__length(unsigned char[]); std::size_t string__length(const unsigned char[]);
    std::size_t string__length(wchar_t[]); std::size_t string__length(const wchar_t[]);

    char* string__source_concatenate(char*&, char[]);
    char* string__source_concatenate(char*&, const char[]);
    char8_t* string__source_concatenate(char8_t*&, char8_t[]);
    char8_t* string__source_concatenate(char8_t*&, const char8_t[]);
    char16_t* string__source_concatenate(char16_t*&, char16_t[]);
    char16_t* string__source_concatenate(char16_t*&, const char16_t[]);
    char32_t* string__source_concatenate(char32_t*&, char32_t[]);
    char32_t* string__source_concatenate(char32_t*&, const char32_t[]);
    signed char* string__source_concatenate(signed char*&, signed char[]);
    signed char* string__source_concatenate(signed char*&, const signed char[]);
    unsigned char* string__source_concatenate(unsigned char*&, unsigned char[]);
    unsigned char* string__source_concatenate(unsigned char*&, const unsigned char[]);
    wchar_t* string__source_concatenate(wchar_t*&, wchar_t[]);
    wchar_t* string__source_concatenate(wchar_t*&, const wchar_t[]);

    char* string__to_character_string(char[]); char* string__to_character_string(const char[]);
    char* string__to_character_string(char8_t[]); char* string__to_character_string(const char8_t[]);
    char* string__to_character_string(char16_t[]); char* string__to_character_string(const char16_t[]);
    char* string__to_character_string(char32_t[]); char* string__to_character_string(const char32_t[]);
    char* string__to_character_string(signed char[]); char* string__to_character_string(const signed char[]);
    char* string__to_character_string(unsigned char[]); char* string__to_character_string(const unsigned char[]);
    char* string__to_character_string(wchar_t[]); char* string__to_character_string(const wchar_t[]);

    char* string__to_signed_character_string(char[]); char* string__to_signed_character_string(const char[]);
    char* string__to_signed_character_string(char8_t[]); char* string__to_signed_character_string(const char8_t[]);
    char* string__to_signed_character_string(char16_t[]); char* string__to_signed_character_string(const char16_t[]);
    char* string__to_signed_character_string(char32_t[]); char* string__to_signed_character_string(const char32_t[]);
    char* string__to_signed_character_string(signed char[]); char* string__to_signed_character_string(const signed char[]);
    char* string__to_signed_character_string(unsigned char[]); char* string__to_signed_character_string(const unsigned char[]);
    char* string__to_signed_character_string(wchar_t[]); char* string__to_signed_character_string(const wchar_t[]);

    char* string__to_unsigned_character_string(char[]); char* string__to_unsigned_character_string(const char[]);
    char* string__to_unsigned_character_string(char8_t[]); char* string__to_unsigned_character_string(const char8_t[]);
    char* string__to_unsigned_character_string(char16_t[]); char* string__to_unsigned_character_string(const char16_t[]);
    char* string__to_unsigned_character_string(char32_t[]); char* string__to_unsigned_character_string(const char32_t[]);
    char* string__to_unsigned_character_string(signed char[]); char* string__to_unsigned_character_string(const signed char[]);
    char* string__to_unsigned_character_string(unsigned char[]); char* string__to_unsigned_character_string(const unsigned char[]);
    char* string__to_unsigned_character_string(wchar_t[]); char* string__to_unsigned_character_string(const wchar_t[]);

    char* string__to_UTF8_character_string(char[]); char* string__to_UTF8_character_string(const char[]);
    char* string__to_UTF8_character_string(char8_t[]); char* string__to_UTF8_character_string(const char8_t[]);
    char* string__to_UTF8_character_string(char16_t[]); char* string__to_UTF8_character_string(const char16_t[]);
    char* string__to_UTF8_character_string(char32_t[]); char* string__to_UTF8_character_string(const char32_t[]);
    char* string__to_UTF8_character_string(signed char[]); char* string__to_UTF8_character_string(const signed char[]);
    char* string__to_UTF8_character_string(unsigned char[]); char* string__to_UTF8_character_string(const unsigned char[]);
    char* string__to_UTF8_character_string(wchar_t[]); char* string__to_UTF8_character_string(const wchar_t[]);

    char* string__to_UTF16_character_string(char[]); char* string__to_UTF16_character_string(const char[]);
    char* string__to_UTF16_character_string(char8_t[]); char* string__to_UTF16_character_string(const char8_t[]);
    char* string__to_UTF16_character_string(char16_t[]); char* string__to_UTF16_character_string(const char16_t[]);
    char* string__to_UTF16_character_string(char32_t[]); char* string__to_UTF16_character_string(const char32_t[]);
    char* string__to_UTF16_character_string(signed char[]); char* string__to_UTF16_character_string(const signed char[]);
    char* string__to_UTF16_character_string(unsigned char[]); char* string__to_UTF16_character_string(const unsigned char[]);
    char* string__to_UTF16_character_string(wchar_t[]); char* string__to_UTF16_character_string(const wchar_t[]);

    char* string__to_UTF32_character_string(char[]); char* string__to_UTF32_character_string(const char[]);
    char* string__to_UTF32_character_string(char8_t[]); char* string__to_UTF32_character_string(const char8_t[]);
    char* string__to_UTF32_character_string(char16_t[]); char* string__to_UTF32_character_string(const char16_t[]);
    char* string__to_UTF32_character_string(char32_t[]); char* string__to_UTF32_character_string(const char32_t[]);
    char* string__to_UTF32_character_string(signed char[]); char* string__to_UTF32_character_string(const signed char[]);
    char* string__to_UTF32_character_string(unsigned char[]); char* string__to_UTF32_character_string(const unsigned char[]);
    char* string__to_UTF32_character_string(wchar_t[]); char* string__to_UTF32_character_string(const wchar_t[]);

    char* string__to_wide_character_string(char[]); char* string__to_wide_character_string(const char[]);
    char* string__to_wide_character_string(char8_t[]); char* string__to_wide_character_string(const char8_t[]);
    char* string__to_wide_character_string(char16_t[]); char* string__to_wide_character_string(const char16_t[]);
    char* string__to_wide_character_string(char32_t[]); char* string__to_wide_character_string(const char32_t[]);
    char* string__to_wide_character_string(signed char[]); char* string__to_wide_character_string(const signed char[]);
    char* string__to_wide_character_string(unsigned char[]); char* string__to_wide_character_string(const unsigned char[]);
    char* string__to_wide_character_string(wchar_t[]); char* string__to_wide_character_string(const wchar_t[]);

    /* Function > String ... */
        // Clone
        char* string__clone(char characterString[]) { char *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return characterStringClone; }
        const char* string__clone(const char characterString[]) { char *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return (const char*) characterStringClone; }
        char8_t* string__clone(char8_t characterString[]) { char8_t *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return characterStringClone; }
        const char8_t* string__clone(const char8_t characterString[]) { char8_t *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return (const char8_t*) characterStringClone; }
        char16_t* string__clone(char16_t characterString[]) { char16_t *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return characterStringClone; }
        const char16_t* string__clone(const char16_t characterString[]) { char16_t *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return (const char16_t*) characterStringClone; }
        char32_t* string__clone(char32_t characterString[]) { char32_t *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return characterStringClone; }
        const char32_t* string__clone(const char32_t characterString[]) { char32_t *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return (const char32_t*) characterStringClone; }
        signed char* string__clone(signed char characterString[]) { signed char *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return characterStringClone; }
        const signed char* string__clone(const signed char characterString[]) { signed char *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return (const signed char*) characterStringClone; }
        unsigned char* string__clone(unsigned char characterString[]) { unsigned char *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return characterStringClone; }
        const unsigned char* string__clone(const unsigned char characterString[]) { unsigned char *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return (const unsigned char*) characterStringClone; }
        wchar_t* string__clone(wchar_t characterString[]) { wchar_t *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return characterStringClone; }
        const wchar_t* string__clone(const wchar_t characterString[]) { wchar_t *characterStringClone; if (NULL != characterString) { std::size_t iterator = string__length(characterString); characterStringClone = pointer__allocate_memory(characterStringClone, iterator * sizeof(char)); *characterStringClone = *characterString; for (; iterator; iterator--) *(characterStringClone + iterator) = *(characterString + iterator); } else characterStringClone = pointer__allocate_memory(characterStringClone, 0u); return (const wchar_t*) characterStringClone; }

        // Concatenate
        const char* string__concatenate(char characterStringA[], char characterStringB[]) {
            char *characterStringConcatenation;

            std::size_t characterStringAIterator = string__length(characterStringA);
            std::size_t characterStringBIterator = string__length(characterStringB);

            pointer__allocate_memory(characterStringConcatenation, (characterStringAIterator + characterStringBIterator + 1u) * sizeof(char));

            return characterStringConcatenation;
        }
        const char* string__concatenate(char[], const char[]);
        const char* string__concatenate(const char[], char[]);
        const char* string__concatenate(const char[], const char[]);
        const char8_t* string__concatenate(char8_t[], char8_t[]);
        const char8_t* string__concatenate(char8_t[], const char8_t[]);
        const char8_t* string__concatenate(const char8_t[], char8_t[]);
        const char8_t* string__concatenate(const char8_t[], const char8_t[]);
        const char16_t* string__concatenate(char16_t[], char16_t[]);
        const char16_t* string__concatenate(char16_t[], const char16_t[]);
        const char16_t* string__concatenate(const char16_t[], char16_t[]);
        const char16_t* string__concatenate(const char16_t[], const char16_t[]);
        const char32_t* string__concatenate(char32_t[], char32_t[]);
        const char32_t* string__concatenate(char32_t[], const char32_t[]);
        const char32_t* string__concatenate(const char32_t[], char32_t[]);
        const char32_t* string__concatenate(const char32_t[], const char32_t[]);
        const signed char* string__concatenate(signed char[], signed char[]);
        const signed char* string__concatenate(signed char[], const signed char[]);
        const signed char* string__concatenate(const signed char[], signed char[]);
        const signed char* string__concatenate(const signed char[], const signed char[]);
        const unsigned char* string__concatenate(unsigned char[], unsigned char[]);
        const unsigned char* string__concatenate(unsigned char[], const unsigned char[]);
        const unsigned char* string__concatenate(const unsigned char[], unsigned char[]);
        const unsigned char* string__concatenate(const unsigned char[], const unsigned char[]);
        const wchar_t* string__concatenate(wchar_t[], wchar_t[]);
        const wchar_t* string__concatenate(wchar_t[], const wchar_t[]);
        const wchar_t* string__concatenate(const wchar_t[], wchar_t[]);
        const wchar_t* string__concatenate(const wchar_t[], const wchar_t[]);

        // Copy
        // Free
        // Is Empty
        inline boolean string__is_empty(char characterString[]) { return NULL == characterString || *characterString == '\0'; }
        inline boolean string__is_empty(const char characterString[]) { return NULL == characterString || *characterString == '\0'; }
        inline boolean string__is_empty(char8_t characterString[]) { return NULL == characterString || !*characterString; }
        inline boolean string__is_empty(const char8_t characterString[]) { return NULL == characterString || !*characterString; }
        inline boolean string__is_empty(char16_t characterString[]) { return NULL == characterString || *characterString == u'\0'; }
        inline boolean string__is_empty(const char16_t characterString[]) { return NULL == characterString || *characterString == u'\0'; }
        inline boolean string__is_empty(char32_t characterString[]) { return NULL == characterString || *characterString == U'\0'; }
        inline boolean string__is_empty(const char32_t characterString[]) { return NULL == characterString || *characterString == U'\0'; }
        inline boolean string__is_empty(signed char characterString[]) { return NULL == characterString || *characterString == '\0'; }
        inline boolean string__is_empty(const signed char characterString[]) { return NULL == characterString || *characterString == '\0'; }
        inline boolean string__is_empty(unsigned char characterString[]) { return NULL == characterString || *characterString == '\0'; }
        inline boolean string__is_empty(const unsigned char characterString[]) { return NULL == characterString || *characterString == '\0'; }
        inline boolean string__is_empty(wchar_t characterString[]) { return NULL == characterString || *characterString == L'\0'; }
        inline boolean string__is_empty(const wchar_t characterString[]) { return NULL == characterString || *characterString == L'\0'; }

        // Length
        inline std::size_t string__length(char characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString++)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(const char characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString + characterStringLength)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(char8_t characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString++)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(const char8_t characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString + characterStringLength)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(char16_t characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString++)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(const char16_t characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString + characterStringLength)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(char32_t characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString++)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(const char32_t characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString + characterStringLength)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(signed char characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString++)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(const signed char characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString + characterStringLength)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(unsigned char characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString++)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(const unsigned char characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString + characterStringLength)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(wchar_t characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString++)) characterStringLength++; return characterStringLength; } }
        inline std::size_t string__length(const wchar_t characterString[]) { if (NULL == characterString) return 0u; else { std::size_t characterStringLength = 0u; while (*(characterString + characterStringLength)) characterStringLength++; return characterStringLength; } }

        // Source Concatenate
        // To Character String
        // To Signed Character String
        // To Unsigned Character String
        // To UTF-8 String
        // To UTF-16 String
        // To UTF-32 String
        // To Wide Character String
#endif
