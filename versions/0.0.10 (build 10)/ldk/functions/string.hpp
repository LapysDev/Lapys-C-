/* Meta > ... */
template <typename type>
inline bool string__instanceof(void) noexcept {
    // Return
    return (
        ((std::is_same<type, char*>::value || std::is_same<type, char[]>::value) || (std::is_same<type, const char*>::value || std::is_same<type, const char[]>::value)) ||
        ((std::is_same<type, char8_t*>::value || std::is_same<type, char8_t[]>::value) || (std::is_same<type, const char8_t*>::value || std::is_same<type, const char8_t[]>::value)) ||
        ((std::is_same<type, char16_t*>::value || std::is_same<type, char16_t[]>::value) || (std::is_same<type, const char16_t*>::value || std::is_same<type, const char16_t[]>::value)) ||
        ((std::is_same<type, char32_t*>::value || std::is_same<type, char32_t[]>::value) || (std::is_same<type, const char32_t*>::value || std::is_same<type, const char32_t[]>::value)) ||
        ((std::is_same<type, signed char*>::value || std::is_same<type, signed char[]>::value) || (std::is_same<type, const signed char*>::value || std::is_same<type, const signed char[]>::value)) ||
        ((std::is_same<type, unsigned char*>::value || std::is_same<type, unsigned char[]>::value) || (std::is_same<type, const unsigned char*>::value || std::is_same<type, const unsigned char[]>::value)) ||
        ((std::is_same<type, wchar_t*>::value || std::is_same<type, wchar_t[]>::value) || (std::is_same<type, const wchar_t*>::value || std::is_same<type, const wchar_t[]>::value))
    );
}

template <typename> struct string__typeof;
template <> struct string__typeof<char*> { public: using type = char; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<const char*> { public: using type = char; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<char8_t*> { public: using type = char8_t; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<const char8_t*> { public: using type = char8_t; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<char16_t*> { public: using type = char16_t; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<const char16_t*> { public: using type = char16_t; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<char32_t*> { public: using type = char32_t; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<const char32_t*> { public: using type = char32_t; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<signed char*> { public: using type = signed char; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<const signed char*> { public: using type = signed char; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<unsigned char*> { public: using type = unsigned char; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<const unsigned char*> { public: using type = unsigned char; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<wchar_t*> { public: using type = wchar_t; constexpr inline string__typeof(void) {} };
template <> struct string__typeof<const wchar_t*> { public: using type = wchar_t; constexpr inline string__typeof(void) {} };

/* Utilization > ... --- NOTE (Lapys) -> Fails if `type` is not a collection of C-type characters. */
template <typename type>
using string__character_type = typename std::enable_if<LDKF::string__instanceof<type>(), typename LDKF::string__typeof<type>()>::type;

template <typename type>
using string__type = typename std::enable_if<LDKF::string__instanceof<type>(), type>::type;

/* Function
        --- RULES ---
            #Lapys:
                - Manipulated destination argument strings may be heap allocated or freed dynamically onto memory.
                - Static array strings may not have their length asserted via templates.
                - With the exception of conversions functions, each function may only accept strings of the same type.
*/
    // At
    template <typename type>
    inline string__character_type<type*> string__at(type characterString[], const std::size_t index) noexcept { return *(characterString + index); }

    // Clone
    template <typename type>
    inline string__type<type*> string__clone(type characterString[]) noexcept {
        // Logic
        if (characterString) {
            // Initialization > Character String (Clone, Length)
            std::size_t characterStringLength = LDKF::string__length(characterString);
            type *characterStringClone = LDKF::array__create<characterStringLength, type>();

            // Update > Character String Clone
            LDKF::array__copy(characterStringClone, characterString, characterStringLength);

            // Return
            return characterStringClone;
        }

        else
            // Return
            return NULL;
    }

    // Concatenate
    inline void string__concatenate() noexcept;

    // Copy --- WARN (Lapys) -> Do not copy null strings.
    // template <typename type>
    // inline string__type<type*> string__copy(type characterString[]) noexcept {}

    inline char* string__copy(char characterString[], char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char *characterStringIterator = characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline char* string__copy(char characterString[], const char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char *characterStringIterator = characterString, characterStringSourceIterator = (char*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline const char* string__copy(const char characterString[], char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char *characterStringIterator = (char*) characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline const char* string__copy(const char characterString[], const char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char *characterStringIterator = (char*) characterString, characterStringSourceIterator = (char*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline char8_t* string__copy(char8_t characterString[], char8_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char8_t *characterStringIterator = characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline char8_t* string__copy(char8_t characterString[], const char8_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char8_t *characterStringIterator = characterString, characterStringSourceIterator = (char8_t*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline const char8_t* string__copy(const char8_t characterString[], char8_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char8_t *characterStringIterator = (char8_t*) characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline const char8_t* string__copy(const char8_t characterString[], const char8_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char8_t *characterStringIterator = (char8_t*) characterString, characterStringSourceIterator = (char8_t*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline char16_t* string__copy(char16_t characterString[], char16_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char16_t *characterStringIterator = characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline char16_t* string__copy(char16_t characterString[], const char16_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char16_t *characterStringIterator = characterString, characterStringSourceIterator = (char16_t*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline const char16_t* string__copy(const char16_t characterString[], char16_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char16_t *characterStringIterator = (char16_t*) characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline const char16_t* string__copy(const char16_t characterString[], const char16_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char16_t *characterStringIterator = (char16_t*) characterString, characterStringSourceIterator = (char16_t*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline char32_t* string__copy(char32_t characterString[], char32_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char32_t *characterStringIterator = characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline char32_t* string__copy(char32_t characterString[], const char32_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char32_t *characterStringIterator = characterString, characterStringSourceIterator = (char32_t*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline const char32_t* string__copy(const char32_t characterString[], char32_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char32_t *characterStringIterator = (char32_t*) characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline const char32_t* string__copy(const char32_t characterString[], const char32_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (char32_t *characterStringIterator = (char32_t*) characterString, characterStringSourceIterator = (char32_t*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline signed char* string__copy(signed char characterString[], signed char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (signed char *characterStringIterator = characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline signed char* string__copy(signed char characterString[], const signed char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (signed char *characterStringIterator = characterString, characterStringSourceIterator = (signed char*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline const signed char* string__copy(const signed char characterString[], signed char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (signed char *characterStringIterator = (signed char*) characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline const signed char* string__copy(const signed char characterString[], const signed char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (signed char *characterStringIterator = (signed char*) characterString, characterStringSourceIterator = (signed char*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline unsigned char* string__copy(unsigned char characterString[], unsigned char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (unsigned char *characterStringIterator = characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline unsigned char* string__copy(unsigned char characterString[], const unsigned char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (unsigned char *characterStringIterator = characterString, characterStringSourceIterator = (unsigned char*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline const unsigned char* string__copy(const unsigned char characterString[], unsigned char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (unsigned char *characterStringIterator = (unsigned char*) characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline const unsigned char* string__copy(const unsigned char characterString[], const unsigned char characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (unsigned char *characterStringIterator = (unsigned char*) characterString, characterStringSourceIterator = (unsigned char*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline wchar_t* string__copy(wchar_t characterString[], wchar_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (wchar_t *characterStringIterator = characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline wchar_t* string__copy(wchar_t characterString[], const wchar_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (wchar_t *characterStringIterator = characterString, characterStringSourceIterator = (wchar_t*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }
    inline const wchar_t* string__copy(const wchar_t characterString[], wchar_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (wchar_t *characterStringIterator = (wchar_t*) characterString; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSource++));) continue; return characterString; } else return NULL; }
    inline const wchar_t* string__copy(const wchar_t characterString[], const wchar_t characterStringSource[]) noexcept { if (characterString && characterStringSource) { for (wchar_t *characterStringIterator = (wchar_t*) characterString, characterStringSourceIterator = (wchar_t*) characterStringSource; *characterStringIterator && (*(characterStringIterator++) = *(characterStringSourceIterator++));) continue; return characterString; } else return NULL; }

    // Cut --- WARN (Lapys) -> Assumes the index is valid.
    inline char* string__cut(char characterString[], std::size_t index) noexcept { while (*(characterString + index)) { *(characterString + index) = *(characterString + (index + 1u)); ++index; } return characterString; }
    inline const char* string__cut(const char characterString[], std::size_t index) noexcept { for (char *characterStringIterator = (char*) characterString; *(characterStringIterator + index); ++index) *(characterStringIterator + index) = *(characterStringIterator + (index + 1u)); return characterString; }
    inline char8_t* string__cut(char8_t characterString[], std::size_t index) noexcept { while (*(characterString + index)) { *(characterString + index) = *(characterString + (index + 1u)); ++index; } return characterString; }
    inline const char8_t* string__cut(const char8_t characterString[], std::size_t index) noexcept { for (char8_t *characterStringIterator = (char8_t*) characterString; *(characterStringIterator + index); ++index) *(characterStringIterator + index) = *(characterStringIterator + (index + 1u)); return characterString; }
    inline char16_t* string__cut(char16_t characterString[], std::size_t index) noexcept { while (*(characterString + index)) { *(characterString + index) = *(characterString + (index + 1u)); ++index; } return characterString; }
    inline const char16_t* string__cut(const char16_t characterString[], std::size_t index) noexcept { for (char16_t *characterStringIterator = (char16_t*) characterString; *(characterStringIterator + index); ++index) *(characterStringIterator + index) = *(characterStringIterator + (index + 1u)); return characterString; }
    inline char32_t* string__cut(char32_t characterString[], std::size_t index) noexcept { while (*(characterString + index)) { *(characterString + index) = *(characterString + (index + 1u)); ++index; } return characterString; }
    inline const char32_t* string__cut(const char32_t characterString[], std::size_t index) noexcept { for (char32_t *characterStringIterator = (char32_t*) characterString; *(characterStringIterator + index); ++index) *(characterStringIterator + index) = *(characterStringIterator + (index + 1u)); return characterString; }
    inline signed char* string__cut(signed char characterString[], std::size_t index) noexcept { while (*(characterString + index)) { *(characterString + index) = *(characterString + (index + 1u)); ++index; } return characterString; }
    inline const signed char* string__cut(const signed char characterString[], std::size_t index) noexcept { for (signed char *characterStringIterator = (signed char*) characterString; *(characterStringIterator + index); ++index) *(characterStringIterator + index) = *(characterStringIterator + (index + 1u)); return characterString; }
    inline unsigned char* string__cut(unsigned char characterString[], std::size_t index) noexcept { while (*(characterString + index)) { *(characterString + index) = *(characterString + (index + 1u)); ++index; } return characterString; }
    inline const unsigned char* string__cut(const unsigned char characterString[], std::size_t index) noexcept { for (unsigned char *characterStringIterator = (unsigned char*) characterString; *(characterStringIterator + index); ++index) *(characterStringIterator + index) = *(characterStringIterator + (index + 1u)); return characterString; }
    inline wchar_t* string__cut(wchar_t characterString[], std::size_t index) noexcept { while (*(characterString + index)) { *(characterString + index) = *(characterString + (index + 1u)); ++index; } return characterString; }
    inline const wchar_t* string__cut(const wchar_t characterString[], std::size_t index) noexcept { for (wchar_t *characterStringIterator = (wchar_t*) characterString; *(characterStringIterator + index); ++index) *(characterStringIterator + index) = *(characterStringIterator + (index + 1u)); return characterString; }

    // Cut From End
    inline void string__cut_from_end() noexcept;

    // Cut From Start
    inline void string__cut_from_start() noexcept;

    // Free
    inline void string__free() noexcept;

    // Index
    inline void string__index() noexcept;

    // Index From End
    inline void string__index_from_end() noexcept;

    // Index From Start
    inline void string__index_from_start() noexcept;

    // Length
    inline void string__length() noexcept;

    // Slice
    inline void string__slice() noexcept;

    // Source Concatenate
    inline void string__source_concatenate() noexcept;

    // Remove
    inline void string__remove() noexcept;

    // Replace
    inline void string__replace() noexcept;

    // To Character String
    inline void string__to_character_string() noexcept;

    // To Number
    inline void string__to_number() noexcept;

    // To Signed Character String
    inline void string__to_signed_character_string() noexcept;

    // To Unsigned Character String
    inline void string__to_unsigned_character_string() noexcept;

    // To UTF-8 Character String
    inline void string__to_utf8_character_string() noexcept;

    // To UTF-16 Character String
    inline void string__to_utf16_character_string() noexcept;

    // To UTF-32 Character String
    inline void string__to_utf32_character_string() noexcept;

    // To Wide Character String
    inline void string__to_wide_character_string() noexcept;
