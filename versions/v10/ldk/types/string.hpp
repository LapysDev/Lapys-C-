/* Class > String */
struct string {
    /* ... */
    friend boolean;
    friend character;
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
    friend unique_smart_pointer;
    friend wide;

    // [...]
    private:
        // Definition > Value
        character *value;

    // [...]
    public:
        // Initialization >  Length
        struct string_length__accessor {
            // [...]
            private:
                // Definition > String
                string *string;

            // [...]
            public:
                // [Constructor]
                constexpr inline string_length(const string* string) : string{string} {}
                constexpr inline string_length(void) : string{NULL} {}

                // [Operator] > ...
                inline operator size(void) const noexcept { size length = 0u; if (this -> string -> value) for (character *iterator = this -> string -> value; *iterator; ++iterator) ++length; return length; }
        } length;

        // [Constructor]
        string(char argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(const char argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(char8_t argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(const char8_t argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(char16_t argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(const char16_t argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(char32_t argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(const char32_t argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(signed char argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(const signed char argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(unsigned char argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(const unsigned char argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(wchar_t argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        string(const wchar_t argument[]) : value{NULL}, length{this} { if (argument && *argument) { this -> value = LDKF::array__create<character>(LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } }
        inline string(character argument[]) : value{NULL}, length{this} { string::string((character::character_type*) argument); }
        inline string(const character argument[]) : value{NULL}, length{this} { string::string((const character::character_type*) argument); }
        string(string&& argument) { if (argument) { this -> value = LDKF::array__create<character>(argument.length); LDKF::pointer__copy(this -> value, argument.value, argument.length); } }
        string(const string& argument) { if (argument) { this -> value = LDKF::array__create<character>(argument.length); LDKF::pointer__copy(this -> value, argument.value, argument.length); } }
        constexpr inline string(void) : value{NULL}, length{this} {}

        // [Destructor]
        ~string(void) { LDKF::array__free(this -> value); }

        // Function
            /* Raw */
            constexpr inline const character* raw(void) const noexcept { return this -> value; }

            // To Character String
            // To UTF-8 Character String
            // To UTF-16 Character String
            // To UTF-32 Character String
            // To Signed Character String
            // To Unsigned Character String
            // To Wide Character String
            /* Value Of */

        // [Operator] > ...
        string& operator =(char argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(const char argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(char8_t argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(const char8_t argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(char16_t argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(const char16_t argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(char32_t argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(const char32_t argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(signed char argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(const signed char argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(unsigned char argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(const unsigned char argument[]) noexcept { if (argument && *argument) { LDKF::array__resize<character>(this -> value, LDKF::string__length(argument)); LDKF::string__copy((character::character_type*) this -> value, argument); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        inline string& operator =(character argument[]) noexcept { string::operator =((character::character_type*) argument); return *this; }
        inline string& operator =(const character argument[]) noexcept { string::operator =((const character::character_type*) argument); return *this; }
        string& operator =(string&& argument) noexcept { if (argument) { LDKF::array__resize<character>(this -> value, argument.length); LDKF::pointer__copy(this -> value, argument.value, argument.length); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }
        string& operator =(const string& argument) noexcept { if (argument) { LDKF::array__resize<character>(this -> value, argument.length); LDKF::pointer__copy(this -> value, argument.value, argument.length); } else { LDKF::array__free(this -> value); this -> value = NULL; } return *this; }

        inline character& operator [](size index) const noexcept { return *(this -> value + index); }
        inline operator boolean(void) const noexcept { return this -> value && *(this -> value); }
};
