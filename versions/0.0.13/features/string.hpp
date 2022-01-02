namespace { class Character { friend __MAIN__; friend File; friend String; }; }

class NullASCIIString { friend __MAIN__; friend File;
    typedef DynamicArray<Character>::length_t length_t;
    typedef ::Character Character;

    char *value;
};

class NullUnicodeString { friend __MAIN__; friend File;
    typedef DynamicArray<Character>::length_t length_t;
    typedef ::Character Character;

    wchar_t? *value;
}; typedef NullUnicodeString NullString;

class ASCIIString : DynamicArray<Character> { friend __MAIN__; friend File;
    typedef DynamicArray<Character>::length_t length_t;
    typedef ::Character Character;

    ASCIIString(void); // like default arguments but in reverse order
    ASCIIString(length_t const length);
    ASCIIString(char*);
    ASCIIString(length_t const length, char*);
    ASCIIString(char const*);
    ASCIIString(length_t const length, char const*);
};

class UnicodeString : DynamicArray<Character> { friend __MAIN__; friend File; friend constexpr bool URL::isValid(bool);
    typedef DynamicArray<Character>::length_t length_t;
    typedef ::Character Character;

    public:
        UnicodeString(void); // like default arguments but in reverse order
        UnicodeString(length_t const length);
        UnicodeString(char*);
        UnicodeString(length_t const length, char*);
        UnicodeString(char const*);
        UnicodeString(length_t const length, char const*);
        UnicodeString(char16_t*);
        UnicodeString(length_t const length, char16_t*);
        UnicodeString(char16_t const*);
        UnicodeString(length_t const length, char16_t const*);
        UnicodeString(char32_t*);
        UnicodeString(length_t const length, char32_t*);
        UnicodeString(char32_t const*);
        UnicodeString(length_t const length, char32_t const*);
        UnicodeString(wchar_t*);
        UnicodeString(length_t const length, wchar_t*);
        UnicodeString(wchar_t const*);
        UnicodeString(length_t const length, wchar_t const*);
        UnicodeString(Character*);
        UnicodeString(length_t const length, Character*);
        UnicodeString(Character const*);
        UnicodeString(length_t const length, Character const*);
        UnicodeString(UnicodeString const&);
        UnicodeString(length_t const length, UnicodeString const&);
        UnicodeString(UnicodeString&&);
        UnicodeString(length_t const length, UnicodeString&&);

        char* toASCII(void);
        wchar_t* toFixedWidth(void);
        char16_t* toUnicode16(void);
        char32_t* toUnicode32(void);
        Character* valueOf(void);
}; typedef UnicodeString String;
