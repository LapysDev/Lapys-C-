/* Pragma */
#pragma once

/* [Abstraction] Class */
    /* Boolean */
    struct boolean {
        // [...]
        private:
            // Definition > Value
            enum {boolean_false, boolean_true} value;

        // [...]
        public:
            // [Constructor]
            constexpr inline boolean(const bool);
            constexpr inline boolean(void);
            constexpr inline boolean(boolean&);
            constexpr inline boolean(const boolean&);
            constexpr inline boolean(boolean&&);
            constexpr inline boolean(const boolean&&);

            // [Operator] > ...
            inline boolean& operator =(const bool) noexcept;
            inline boolean& operator =(boolean&) noexcept;
            inline boolean& operator =(boolean&&) noexcept;
            inline boolean& operator =(const boolean&) noexcept;
            inline boolean& operator =(const boolean&&) noexcept;

            inline operator bool(void) const noexcept;
    };

    /* Character */
    struct character {
        // [...]
        public:
            // Definition > ...
            #if WCHAR_MAX > CHAR_MAX
                typedef wchar_t character_type;
            #elif CHAR32_MAX > CHAR_MAX
                typedef char32_t character_type;
            #elif CHAR16_MAX > CHAR_MAX
                typedef char16_t character_type;
            #elif CHAR8_MAX > CHAR_MAX
                typedef char8_t character_type;
            #else
                typedef char character_type;
            #endif

        // [...]
        private:
            // Definition > Value
            character_type value;

        // [...]
        public:
            // [Constructor]
            constexpr inline character(const char);
            constexpr inline character(const char8_t);
            constexpr inline character(const char16_t);
            constexpr inline character(const char32_t);
            constexpr inline character(const signed char);
            constexpr inline character(const unsigned char);
            constexpr inline character(const wchar_t);
            constexpr inline character(void);
            constexpr inline character(character&);
            constexpr inline character(character&&);
            constexpr inline character(const character&);
            constexpr inline character(const character&&);

            // [Operator] > ...
            inline character& operator =(const char) noexcept;
            inline character& operator =(const char8_t) noexcept;
            inline character& operator =(const char16_t) noexcept;
            inline character& operator =(const char32_t) noexcept;
            inline character& operator =(const signed char) noexcept;
            inline character& operator =(const unsigned char) noexcept;
            inline character& operator =(const wchar_t) noexcept;
            inline character& operator =(character&) noexcept;
            inline character& operator =(character&&) noexcept;
            inline character& operator =(const character&) noexcept;
            inline character& operator =(const character&&) noexcept;

            inline operator character_type(void) const noexcept;
    };

    /* Wide --- NOTE (Lapys) -> Alias for the largest C++ primitive integral type. --- WARN (Lapys) -> Defers value without sign. */
    struct wide {
        // [...]
        private:
            // Definition > (..., Value)
            #if defined(__cplusplus) && __cplusplus <= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900) // C++ 2011, ISO/IEC 14882:2011
                typedef signed long long wide_signed_type;
                typedef unsigned long long wide_unsigned_type;
            #else
                typedef signed long wide_signed_type;
                typedef unsigned long wide_unsigned_type;
            #endif
            wide_type value;

        // [...]
        public:
            // [Constructor]
            constexpr inline wide(const wide_signed_type);
            constexpr inline wide(const wide_unsigned_type);
            constexpr inline wide(void);
            constexpr inline wide(wide&);
            constexpr inline wide(wide&&);
            constexpr inline wide(const wide&);
            constexpr inline wide(const wide&&);

            // [Operator] > ...
            inline wide& operator =(const wide_signed_type) noexcept;
            inline wide& operator =(const wide_unsigned_type) noexcept;
            inline wide& operator =(wide&) noexcept;
            inline wide& operator =(wide&&) noexcept;
            inline wide& operator =(const wide&) noexcept;
            inline wide& operator =(const wide&&) noexcept;

            inline operator wide_unsigned_type(void) const noexcept;
    };

    /* Integral --- WARN (Lapys) -> Stores value without sign. */
    struct integral {
        // [...]
        private:
            // Definition > (..., Value)
            enum {integral__int_type, integral__long_type, integral__short_type, integral__wide_type} type;
            union { public: unsigned int int_value; unsigned long long_value; unsigned short short_value; wide wide_value; } value;

        // [...]
        public:
            // [Constructor]
            inline integral(const int);
            inline integral(const long);
            inline integral(const short);
            inline integral(const unsigned int);
            inline integral(const unsigned long);
            inline integral(const unsigned short);
            inline integral(const wide);
            inline integral(void);
            constexpr inline integral(integral&);
            constexpr inline integral(integral&&);
            constexpr inline integral(const integral&);
            constexpr inline integral(const integral&&);

            // [Operator] > ...
            inline integral& operator =(const int) noexcept;
            inline integral& operator =(const long) noexcept;
            inline integral& operator =(const short) noexcept;
            inline integral& operator =(const unsigned int) noexcept;
            inline integral& operator =(const unsigned long) noexcept;
            inline integral& operator =(const unsigned short) noexcept;
            inline integral& operator =(const wide) noexcept;
            inline integral& operator =(integral&) noexcept;
            inline integral& operator =(integral&&) noexcept;
            inline integral& operator =(const integral&) noexcept;
            inline integral& operator =(const integral&&) noexcept;

            inline operator wide(void) const noexcept;
    };

    /* Rational */
    struct rational {
        // [...]
        private:
            // Definition > (..., Value)
            enum {rational__double_type, rational__float_type, rational__long_double_type} type;
            union { public: double double_value; float float_value; long double long_double_value; } value;

        // [...]
        public:
            // [Constructor]
            inline rational(const double);
            inline rational(const float);
            inline rational(const long double);
            inline rational(void);
            constexpr inline rational(rational&);
            constexpr inline rational(rational&&);
            constexpr inline rational(const rational&);
            constexpr inline rational(const rational&&);

            // [Operator] > ...
            inline rational& operator =(const double) noexcept;
            inline rational& operator =(const float) noexcept;
            inline rational& operator =(const long double) noexcept;
            inline rational& operator =(rational&) noexcept;
            inline rational& operator =(rational&&) noexcept;
            inline rational& operator =(const rational&) noexcept;
            inline rational& operator =(const rational&&) noexcept;

            inline operator long double(void) const noexcept;
    };

    /* Number */
    struct number {
        // [...]
        private:
            // Definition > (..., Value)
            enum {number__integral_type, number__rational_type} type;
            union { public: integral integral_value; rational rational_value; } value;

        // [...]
        public:
            // [Constructor]
            constexpr inline number(const integral);
            constexpr inline number(const rational);
            constexpr inline number(void);
            constexpr inline number(number&);
            constexpr inline number(number&&);
            constexpr inline number(const number&);
            constexpr inline number(const number&&);

            // [Operator] > ...
            inline operator double(void);
            inline operator float(void);
            inline operator int(void);
            inline operator long(void);
            inline operator long double(void);
            inline operator long long(void);
            inline operator short(void);
            inline operator unsigned int(void);
            inline operator unsigned long(void);
            inline operator unsigned short(void);
            inline operator wide(void);
    };

    /* Pointer */
    struct pointer {
        // [...]
        public:
            // [Operator] > ...
            inline virtual void operator *(void) const noexcept;
            inline virtual void operator &(void) const noexcept;

            template <typename type> inline virtual operator type*(void) const noexcept;
    };

    /* Null Pointer */
    struct null_pointer : pointer {
        // [...]
        public:
            // [Operator] > ...
            constexpr inline void operator *(void) const noexcept;
            constexpr inline void operator &(void) const noexcept;

            template <typename type> inline operator type*(void) const noexcept;
    };

    /* Raw Pointer */
    struct raw_pointer : pointer {
        // [...]
        private:
            // Definition > Value
            void *value;

        // [...]
        public:
            // [Constructor]
            constexpr inline raw_pointer(void);
            template <typename type> constexpr inline raw_pointer(type*);

            // [Operator] > ...
            constexpr inline void operator *(void) const noexcept;
            constexpr inline void operator &(void) const noexcept;
            template <typename type> inline raw_pointer& operator =(type*) noexcept;

            template <typename type> inline operator type*(void) const noexcept;
    };

    /* String --- WARN (Lapys) -> Requires the `character` type. */
    struct string {
        // [...]
        private:
            // Definition > Value
            character *value;

        // [...]
        public:
            // [Constructor]
            constexpr inline string(char*);
            constexpr inline string(const char*);
            constexpr inline string(char8_t*);
            constexpr inline string(const char8_t*);
            constexpr inline string(char16_t*);
            constexpr inline string(const char16_t*);
            constexpr inline string(char32_t*);
            constexpr inline string(const char32_t*);
            constexpr inline string(signed char*);
            constexpr inline string(const signed char*);
            constexpr inline string(unsigned char*);
            constexpr inline string(const unsigned char*);
            constexpr inline string(wchar_t*);
            constexpr inline string(const wchar_t*);
            constexpr inline string(void);
            template <size_t length> constexpr inline string(char (&)[length]);
            template <size_t length> constexpr inline string(const char (&)[length]);
            template <size_t length> constexpr inline string(char8_t (&)[length]);
            template <size_t length> constexpr inline string(const char8_t (&)[length]);
            template <size_t length> constexpr inline string(char16_t (&)[length]);
            template <size_t length> constexpr inline string(const char16_t (&)[length]);
            template <size_t length> constexpr inline string(char32_t (&)[length]);
            template <size_t length> constexpr inline string(const char32_t (&)[length]);
            template <size_t length> constexpr inline string(signed char (&)[length]);
            template <size_t length> constexpr inline string(const signed char (&)[length]);
            template <size_t length> constexpr inline string(unsigned char (&)[length]);
            template <size_t length> constexpr inline string(const unsigned char (&)[length]);
            template <size_t length> constexpr inline string(wchar_t (&)[length]);
            template <size_t length> constexpr inline string(const wchar_t (&)[length]);

            // [Operator] > ...
            inline string& operator =(char*) noexcept;
            inline string& operator =(const char*) noexcept;
            inline string& operator =(char8_t*) noexcept;
            inline string& operator =(const char8_t*) noexcept;
            inline string& operator =(char16_t*) noexcept;
            inline string& operator =(const char16_t*) noexcept;
            inline string& operator =(char32_t*) noexcept;
            inline string& operator =(const char32_t*) noexcept;
            inline string& operator =(signed char*) noexcept;
            inline string& operator =(const signed char*) noexcept;
            inline string& operator =(unsigned char*) noexcept;
            inline string& operator =(const unsigned char*) noexcept;
            inline string& operator =(wchar_t*) noexcept;
            inline string& operator =(const wchar_t*) noexcept;
            template <size_t length> inline string& operator =(const char (&)[length]) noexcept;
            template <size_t length> inline string& operator =(const char8_t (&)[length]) noexcept;
            template <size_t length> inline string& operator =(const char16_t (&)[length]) noexcept;
            template <size_t length> inline string& operator =(const char32_t (&)[length]) noexcept;
            template <size_t length> inline string& operator =(const signed char (&)[length]) noexcept;
            template <size_t length> inline string& operator =(const unsigned char (&)[length]) noexcept;
            template <size_t length> inline string& operator =(const wchar_t (&)[length]) noexcept;

            inline operator char*(void) const noexcept;
            inline operator const char*(void) const noexcept;
            inline operator char8_t*(void) const noexcept;
            inline operator const char8_t*(void) const noexcept;
            inline operator char16_t*(void) const noexcept;
            inline operator const char16_t*(void) const noexcept;
            inline operator char32_t*(void) const noexcept;
            inline operator const char32_t*(void) const noexcept;
            inline operator signed char*(void) const noexcept;
            inline operator const signed char*(void) const noexcept;
            inline operator unsigned char*(void) const noexcept;
            inline operator const unsigned char*(void) const noexcept;
            inline operator void*(void) const noexcept;
            inline operator const void*(void) const noexcept;
            inline operator wchar_t*(void) const noexcept;
            inline operator const wchar_t*(void) const noexcept;
            inline operator boolean(void) const noexcept;
    };

    /* Variable --- WARN (Lapys) -> Requires the `boolean`, `character`, `number`, `raw_pointer`, and `string` types. */
    struct var {
        // [...]
        private:
            // Definition > (..., Value)
            enum {var__integral_type, var__pointer_type, var__rational_type} type;
            void *value;

        // [...]
        public:
            // [Constructor]
            inline var(const boolean);
            inline var(const character);
            inline var(const number);
            inline var(const raw_pointer);
            inline var(const string);
            inline var(void);
            constexpr inline var(var&);
            constexpr inline var(var&&);
            constexpr inline var(const var&);
            constexpr inline var(const var&&);

            // [Operator] > ...
            inline var& operator =(const boolean) noexcept;
            inline var& operator =(const character) noexcept;
            inline var& operator =(const number) noexcept;
            inline var& operator =(const raw_pointer) noexcept;
            inline var& operator =(const string) noexcept;
            inline var& operator =(var&) noexcept;
            inline var& operator =(var&&) noexcept;
            inline var& operator =(const var&) noexcept;
            inline var& operator =(const var&&) noexcept;

            inline operator bool(void) const noexcept;
            inline operator char(void) const noexcept;
            inline operator char8_t(void) const noexcept;
            inline operator char16_t(void) const noexcept;
            inline operator char32_t(void) const noexcept;
            inline operator double(void) const noexcept;
            inline operator float(void) const noexcept;
            inline operator int(void) const noexcept;
            inline operator long(void) const noexcept;
            inline operator long double(void) const noexcept;
            inline operator short(void) const noexcept;
            inline operator unsigned int(void) const noexcept;
            inline operator unsigned long(void) const noexcept;
            inline operator unsigned short(void) const noexcept;
            inline operator void*(void) const noexcept;
            inline operator const void*(void) const noexcept;
            inline operator wchar_t(void) const noexcept;
            inline operator wide(void) const noexcept;
    };

/* [Interface] Class */
    /* Array */
    class Array {};

    /* Big Number --- NOTE (Lapys) -> Arbitrary-precision number. */
    class BigNumber {};

    /* Boolean */
    class Boolean {};

    /* Clamped Array --- NOTE (Lapys) -> Static-length array. */
    class ClampedArray {};

    /* Clamped Number --- NOTE (Lapys) -> Number within a range not determined by data architecture. --- WARN (Lapys) -> Allows for overflow. */
    class ClampedNumber {};

    /* Function */
    class Function {};

    /* Number */
    class Number {};

    /* Object */
    class Object {};

    /* Regular Expression */
    class RegularExpression {};

    /* String */
    class String {};

    /* Symbol */
    class Symbol {};

/* Function */
    /* ... */
    var __(...);

    /* Array */
    var array__(...);

    /* Number */
    var number__(...);

    /* Pointer */
    var pointer__(...);

    /* String */
    var string__(...);

/* Modification */
    /* Boolean */
        // [Constructor]
        constexpr inline boolean::boolean(const bool argument) : value{argument ? boolean::boolean_true : boolean::boolean_false} {}
        constexpr inline boolean::boolean(void) : value{boolean::boolean_false} {}
        constexpr inline boolean::boolean(boolean& argument) : value{argument.value} {}
        constexpr inline boolean::boolean(const boolean& argument) : value{argument.value} {}
        constexpr inline boolean::boolean(boolean&& argument) : value{argument.value} {}
        constexpr inline boolean::boolean(const boolean&& argument) : value{argument.value} {}

        // [Operator] > ...
        inline boolean& boolean::operator =(const bool argument) noexcept { this -> value = argument ? boolean::boolean_true : boolean::boolean_false; return *this; }
        inline boolean& boolean::operator =(boolean& argument) noexcept { this -> value = argument.value; return *this; }
        inline boolean& boolean::operator =(boolean&& argument) noexcept { this -> value = argument.value; return *this; }
        inline boolean& boolean::operator =(const boolean& argument) noexcept { this -> value = argument.value; return *this; }
        inline boolean& boolean::operator =(const boolean&& argument) noexcept { this -> value = argument.value; return *this; }

        inline boolean::operator bool(void) const noexcept { return boolean::boolean_true == this -> value; }

    /* Character */
        // [Constructor]
        constexpr inline character::character(const char argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(const char8_t argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(const char16_t argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(const char32_t argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(const signed char argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(const unsigned char argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(const wchar_t argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(void) : value{'\0'} {}
        constexpr inline character::character(character& argument) : value{argument.value} {}
        constexpr inline character::character(character&& argument) : value{argument.value} {}
        constexpr inline character::character(const character& argument) : value{argument.value} {}
        constexpr inline character::character(const character&& argument) : value{argument.value} {}

        // [Operator] > ...
        inline character& character::operator =(const char argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(const char8_t argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(const char16_t argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(const char32_t argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(const signed char argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(const unsigned char argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(const wchar_t argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(character& argument) noexcept { this -> value = argument.value; return *this; }
        inline character& character::operator =(character&& argument) noexcept { this -> value = argument.value; return *this; }
        inline character& character::operator =(const character& argument) noexcept { this -> value = argument.value; return *this; }
        inline character& character::operator =(const character&& argument) noexcept { this -> value = argument.value; return *this; }

        inline character::operator character_type(void) const noexcept { return this -> value; }

    /* Integral */
        // [Constructor]
        inline integral::integral(const int argument) : type{integral::integral__int_type}, value{} { this -> value.int_value = argument; }
        inline integral::integral(const long argument) : type{integral::integral__long_type}, value{} { this -> value.long_value = argument; }
        inline integral::integral(const short argument) : type{integral::integral__short_type}, value{} { this -> value.short_value = argument; }
        inline integral::integral(const unsigned int argument) : type{integral::integral__int_type}, value{} { this -> value.int_value = argument; }
        inline integral::integral(const unsigned long argument) : type{integral::integral__long_type}, value{} { this -> value.long_value = argument; }
        inline integral::integral(const unsigned short argument) : type{integral::integral__short_type}, value{} { this -> value.short_value = argument; }
        inline integral::integral(const wide argument) : type{integral::integral__wide_type}, value{} { this -> value.wide_value = argument; }
        inline integral::integral(void) : type{integral::integral__short_type}, value{} { this -> value.short_value = 0u; }
        constexpr inline integral::integral(integral& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline integral::integral(integral&& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline integral::integral(const integral& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline integral::integral(const integral&& argument) : type{argument.type}, value{argument.value} {}

        // [Operator] > ...
        inline integral& integral::operator =(const int argument) noexcept { this -> type = integral::integral__int_type; this -> value = argument; return *this; }
        inline integral& integral::operator =(const long argument) noexcept { this -> type = integral::integral__long_type; this -> value = argument; return *this; }
        inline integral& integral::operator =(const short argument) noexcept { this -> type = integral::integral__short_type; this -> value = argument; return *this; }
        inline integral& integral::operator =(const unsigned int argument) noexcept { this -> type = integral::integral__int_type; this -> value = argument; return *this; }
        inline integral& integral::operator =(const unsigned long argument) noexcept { this -> type = integral::integral__long_type; this -> value = argument; return *this; }
        inline integral& integral::operator =(const unsigned short argument) noexcept { this -> type = integral::integral__short_type; this -> value = argument; return *this; }
        inline integral& integral::operator =(const wide argument) noexcept { this -> type = integral::integral__wide_type; this -> value = argument; return *this; }
        inline integral& integral::operator =(integral& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline integral& integral::operator =(integral&& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline integral& integral::operator =(const integral& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline integral& integral::operator =(const integral&& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }

        inline integral::operator wide(void) const noexcept { switch (this -> type) {
            case integral::integral__int_type: return this -> value.int_value;
            case integral::integral__long_type: return this -> value.long_value;
            case integral::integral__short_type: return this -> value.short_value;
            case integral::integral__wide_type: return this -> value.wide_value;
        } }

    /* Null Pointer */
    /* Number */
        // [Constructor]
        constexpr inline number(const integral);
        constexpr inline number(const rational);
        constexpr inline number(void);
        constexpr inline number(number&);
        constexpr inline number(number&&);
        constexpr inline number(const number&);
        constexpr inline number(const number&&);

        // [Operator] > ...
        inline operator double(void);
        inline operator float(void);
        inline operator int(void);
        inline operator long(void);
        inline operator long double(void);
        inline operator long long(void);
        inline operator short(void);
        inline operator unsigned int(void);
        inline operator unsigned long(void);
        inline operator unsigned short(void);
        inline operator wide(void);

    /* Pointer */
    /* Rational */
        // [Constructor]
        inline rational::rational(const double argument) : type{rational::rational__double_type}, value{} { this -> value.double_value = argument; }
        inline rational::rational(const float argument) : type{rational::rational__float_type}, value{} { this -> value.float_value = argument; }
        inline rational::rational(const long double argument) : type{rational::rational__long_double_type}, value{} { this -> value.long_double_value = argument; }
        inline rational::rational(void) : type{rational::rational__float_type}, value{} { this -> value.float_value = 0.0f; }
        constexpr inline rational::rational(rational& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline rational::rational(rational&& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline rational::rational(const rational& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline rational::rational(const rational&& argument) : type{argument.type}, value{argument.value} {}

        // [Operator] > ...
        inline rational& rational::operator =(const double argument) noexcept { this -> type = rational::rational__double_type; this -> value.double_value = argument; return *this; }
        inline rational& rational::operator =(const float argument) noexcept { this -> type = rational::rational__float_type; this -> value.float_value = argument; return *this; }
        inline rational& rational::operator =(const long double argument) noexcept { this -> type = rational::rational__long_double_type; this -> value.long_double_value = argument; return *this; }
        inline rational& rational::operator =(rational& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline rational& rational::operator =(rational&& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline rational& rational::operator =(const rational& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline rational& rational::operator =(const rational&& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }

        inline rational::operator long double(void) const noexcept { switch (this -> type) {
            case rational::rational__double_type: return this -> value.double_value;
            case rational::rational__float_type: return this -> value.float_value;
            case rational::rational__long_double_type: return this -> value.long_double_value;
        } }

    /* Raw Pointer */
    /* String */
    /* Variable */
    /* Wide */
        // [Constructor]
        constexpr inline wide::wide(const wide_signed_type argument) : value{argument} {}
        constexpr inline wide::wide(const wide_unsigned_type argument) : value{argument} {}
        constexpr inline wide::wide(void) : value{0LL} {}
        constexpr inline wide::wide(wide& argument) : value{argument.value} {}
        constexpr inline wide::wide(wide&& argument) : value{argument.value} {}
        constexpr inline wide::wide(const wide& argument) : value{argument.value} {}
        constexpr inline wide::wide(const wide&& argument) : value{argument.value} {}

        // [Operator] > ...
        inline wide& wide::operator =(const wide_signed_type argument) noexcept { this -> value = argument; return *this; }
        inline wide& wide::operator =(const wide_unsigned_type argument) noexcept { this -> value = argument; return *this; }
        inline wide& wide::operator =(wide& argument) noexcept { this -> value = argument.value; return *this; }
        inline wide& wide::operator =(wide&& argument) noexcept { this -> value = argument.value; return *this; }
        inline wide& wide::operator =(const wide& argument) noexcept { this -> value = argument.value; return *this; }
        inline wide& wide::operator =(const wide&& argument) noexcept { this -> value = argument.value; return *this; }

        inline wide::operator wide_unsigned_type(void) const noexcept { return this -> value; }
