// + - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >>
// >>= <<= == != <= >= <=> (since C++20) && || ++ -- , ->* -> ( ) [ ]
/* C++ 11 and higher */

/* ... */
#pragma once

/* Logic */
#ifndef LDK
    /* Definition > Lapys Development Kit */
    #define LDK

    /* Import > ... */
    #include "includes/polyfills.h" // Polyfills
    #include "includes/standards.h" // C Standard Library

    /* Namespace > Lapys Development Kit */
    namespace LapysDevelopmentKit {
        /* Definition > ... */
        namespace Constants {}
        namespace Functions {}
        namespace Mathematics {}
        namespace Types {}

        /* Namespace */
            /* Types */
            namespace Types {
                /* Definition > ... */
                typedef struct boolean boolean; // NOTE (Lapys) -> Boolean logic container.
                typedef struct character character; // NOTE (Lapys) -> Native character type wrapper.
                typedef struct fraction fraction; // NOTE (Lapys) -> Native non-integer numeric type wrapper.
                typedef struct integer integer; // NOTE (Lapys) -> Native integral type wrapper.
                typedef struct number number; // NOTE (Lapys) -> Native numeric type wrapper.
                typedef struct object object; // NOTE (Lapys) -> Generic object.
                typedef struct pointer pointer;
                    typedef struct null_pointer null_pointer;
                    typedef struct shared_pointer shared_pointer;
                    typedef struct unique_pointer unique_pointer;
                typedef struct primitive primitive; // NOTE (Lapys) -> Native data type wrapper.
                typedef struct size size; // WARN (Lapys) -> Does not overflow.
                typedef struct string string;
            }

            /* Functions */
            namespace Functions {
                /* Definition > ... */
                enum array__memory_chunk_allocation_method : unsigned char;

                /* Declaration > ... */
                template <typename type> LapysDevelopmentKit::Types::size array__allocate_memory_chunk(type*&, const LapysDevelopmentKit::Types::size, const LapysDevelopmentKit::Types::size);
                template <typename type> LapysDevelopmentKit::Types::size array__allocate_memory_chunk(type*&, const LapysDevelopmentKit::Types::size, const LapysDevelopmentKit::Types::size, const LapysDevelopmentKit::Functions::array__memory_chunk_allocation_method);

                inline LapysDevelopmentKit::Types::boolean number__is_finite(const double);
                inline LapysDevelopmentKit::Types::boolean number__is_finite(const float);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const long);
                inline LapysDevelopmentKit::Types::boolean number__is_finite(const long double);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const unsigned int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const unsigned long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const unsigned long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const unsigned short);
                inline LapysDevelopmentKit::Types::boolean number__is_infinite(const double);
                inline LapysDevelopmentKit::Types::boolean number__is_infinite(const float);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const long);
                inline LapysDevelopmentKit::Types::boolean number__is_infinite(const long double);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const unsigned int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const unsigned long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const unsigned long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const unsigned short);
                inline LapysDevelopmentKit::Types::boolean number__is_nan(const double);
                inline LapysDevelopmentKit::Types::boolean number__is_nan(const float);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const long);
                inline LapysDevelopmentKit::Types::boolean number__is_nan(const long double);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const unsigned int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const unsigned long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const unsigned long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const unsigned short);

                template <typename type> inline type* pointer__allocate_memory(type*&, const LapysDevelopmentKit::Types::size);
                template <typename type> inline const LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(type*&);
                template <typename type> inline type* pointer__reallocate_memory(type*&, const LapysDevelopmentKit::Types::size);
            }
    }

    /* Modification > Lapys Development Kit */
        /* Types */
            // Boolean
            struct LapysDevelopmentKit::Types::boolean {
                /* ... */
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;

                // [...]
                private:
                    // Definition > ...
                    enum : unsigned char {boolean_false = (false == true), boolean_true = !boolean_false} value : 8;

                // [...]
                public:
                    // [Constructor]
                    constexpr inline boolean(const unsigned char);
                    constexpr inline boolean(boolean&);
                    constexpr inline boolean(boolean&&);
                    constexpr inline boolean(const boolean&);
                    constexpr inline boolean(const boolean&&);

                    // [Operator] > ...
                    constexpr inline boolean operator !(void) const noexcept;
                    constexpr inline boolean& operator =(const unsigned char) noexcept;
                    constexpr inline boolean& operator =(boolean&) noexcept;
                    constexpr inline boolean& operator =(boolean&&) noexcept;
                    constexpr inline boolean& operator =(const boolean&) noexcept;
                    constexpr inline boolean& operator =(const boolean&&) noexcept;
                    constexpr inline boolean operator ==(const boolean&) const noexcept;
                    constexpr inline boolean operator !=(const boolean&) const noexcept;
                    constexpr inline boolean operator &&(const boolean&) const noexcept;
                    constexpr inline boolean operator ||(const boolean&) const noexcept;

                    constexpr inline operator unsigned char(void) const noexcept;
            };

            // Character
            struct LapysDevelopmentKit::Types::character {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;

                // [...]
                private:
                    // Declaration > Value
                    unsigned value;

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

                    constexpr inline character(character&);
                    constexpr inline character(character&&);
                    constexpr inline character(const character&);
                    constexpr inline character(const character&&);

                    // [Operator] > ...
                    constexpr inline character operator +(void) const noexcept;
                    constexpr inline character operator +(const character&) const noexcept;
                    constexpr inline character operator -(void) const noexcept;
                    constexpr inline character operator -(const character&) const noexcept;
                    constexpr inline character operator *(const character&) const noexcept;
                    constexpr inline character operator /(const character&) const noexcept;
                    constexpr inline character operator %(const character&) const noexcept;
                    constexpr inline character operator ^(const character&) const noexcept;
                    constexpr inline character operator &(const character&) const noexcept;
                    constexpr inline character operator |(const character&) const noexcept;
                    constexpr inline character operator ~(void) const noexcept;
                    constexpr inline boolean operator !(void) const noexcept;
                    constexpr inline character& operator =(const char) noexcept;
                    constexpr inline character& operator =(const char8_t) noexcept;
                    constexpr inline character& operator =(const char16_t) noexcept;
                    constexpr inline character& operator =(const char32_t) noexcept;
                    constexpr inline character& operator =(const signed char) noexcept;
                    constexpr inline character& operator =(const unsigned char) noexcept;
                    constexpr inline character& operator =(const wchar_t) noexcept;
                    constexpr inline character& operator =(character&) noexcept;
                    constexpr inline character& operator =(character&&) noexcept;
                    constexpr inline character& operator =(const character&) noexcept;
                    constexpr inline character& operator =(const character&&) noexcept;
                    constexpr inline boolean operator <(const character&) const noexcept;
                    constexpr inline boolean operator >(const character&) const noexcept;
                    constexpr inline character& operator +=(const character&) noexcept;
                    constexpr inline character& operator -=(const character&) noexcept;
                    constexpr inline character& operator *=(const character&) noexcept;
                    constexpr inline character& operator /=(const character&) noexcept;
                    constexpr inline character& operator %=(const character&) noexcept;
                    constexpr inline character& operator ^=(const character&) noexcept;
                    constexpr inline character& operator &=(const character&) noexcept;
                    constexpr inline character& operator |=(const character&) noexcept;
                    constexpr inline character operator <<(const character&) noexcept;
                    constexpr inline character operator >>(const character&) noexcept;
                    constexpr inline character& operator >>=(const character&) noexcept;
                    constexpr inline character& operator <<=(const character&) noexcept;
                    constexpr inline boolean operator ==(const character&) const noexcept;
                    constexpr inline boolean operator !=(const character&) const noexcept;
                    constexpr inline boolean operator <=(const character&) const noexcept;
                    constexpr inline boolean operator >=(const character&) const noexcept;
                    constexpr inline boolean operator &&(const character&) const noexcept;
                    constexpr inline boolean operator ||(const character&) const noexcept;
                    constexpr inline character operator ++(int) const noexcept;
                    constexpr inline character operator ++(void) const noexcept;
                    constexpr inline character operator --(int) const noexcept;
                    constexpr inline character operator --(void) const noexcept;

                    constexpr inline operator unsigned(void) const;
            };

            // Fraction
            struct LapysDevelopmentKit::Types::fraction {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;

                // [...]
                private:
                    // Initialization > Value
                    long double value;

                // [...]
                public:
                    // [Constructor]
                    constexpr inline fraction(const double);
                    constexpr inline fraction(const float);
                    constexpr inline fraction(const long double);
                    constexpr inline fraction(void);

                    constexpr inline fraction(fraction&);
                    constexpr inline fraction(fraction&&);
                    constexpr inline fraction(const fraction&);
                    constexpr inline fraction(const fraction&&);

                    // [Operator] > ...
                    constexpr inline fraction operator +(void) const;
                    constexpr inline fraction operator +(const fraction&) const;
                    constexpr inline fraction operator -(void) const;
                    constexpr inline fraction operator -(const fraction&) const;
                    constexpr inline fraction operator *(const fraction&) const;
                    constexpr inline fraction operator /(const fraction&) const;
                    constexpr inline boolean operator !(void) const;
                    constexpr inline fraction& operator =(const double) const;
                    constexpr inline fraction& operator =(const float) const;
                    constexpr inline fraction& operator =(const long double) const;
                    constexpr inline fraction& operator =(fraction&) const;
                    constexpr inline fraction& operator =(fraction&&) const;
                    constexpr inline fraction& operator =(const fraction&) const;
                    constexpr inline fraction& operator =(const fraction&&) const;
                    constexpr inline boolean operator <(const fraction&) const;
                    constexpr inline boolean operator >(const fraction&) const;
                    constexpr inline fraction& operator +=(const fraction&) const;
                    constexpr inline fraction& operator -=(const fraction&) const;
                    constexpr inline fraction& operator *=(const fraction&) const;
                    constexpr inline fraction& operator /=(const fraction&) const;
                    constexpr inline boolean operator ==(const fraction&) const;
                    constexpr inline boolean operator !=(const fraction&) const;
                    constexpr inline boolean operator <=(const fraction&) const;
                    constexpr inline boolean operator >=(const fraction&) const;
                    constexpr inline boolean operator &&(const fraction&) const;
                    constexpr inline boolean operator ||(const fraction&) const;
                    constexpr inline fraction& operator ++(int) const;
                    constexpr inline fraction& operator ++(void) const;
                    constexpr inline fraction& operator --(int) const;
                    constexpr inline fraction& operator --(void) const;

                    constexpr inline operator long double(void) const;
            };

            // Integer
            struct LapysDevelopmentKit::Types::integer {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;

                // [...]
                private:
                    // Definition > Value
                    long long value;

                // [...]
                public:
                    // [Constructor]
                    constexpr inline integer(const int);
                    constexpr inline integer(const long);
                    constexpr inline integer(const long long);
                    constexpr inline integer(const short);
                    constexpr inline integer(const unsigned int);
                    constexpr inline integer(const unsigned long);
                    constexpr inline integer(const unsigned long long);
                    constexpr inline integer(const unsigned short);
                    constexpr inline integer(void);

                    constexpr inline integer(integer&);
                    constexpr inline integer(integer&&);
                    constexpr inline integer(const integer&);
                    constexpr inline integer(const integer&&);

                    // [Operator] > ...
                    constexpr inline integer operator +(void) const noexcept;
                    constexpr inline integer operator +(const integer&) const noexcept;
                    constexpr inline integer operator -(void) const noexcept;
                    constexpr inline integer operator -(const integer&) const noexcept;
                    constexpr inline integer operator *(const integer&) const noexcept;
                    constexpr inline integer operator /(const integer&) const noexcept;
                    constexpr inline integer operator %(const integer&) const noexcept;
                    constexpr inline integer operator ^(const integer&) const noexcept;
                    constexpr inline integer operator &(const integer&) const noexcept;
                    constexpr inline integer operator |(const integer&) const noexcept;
                    constexpr inline integer operator ~(void) const noexcept;
                    constexpr inline boolean operator !(void) const noexcept;
                    constexpr inline integer& operator =(const int) noexcept;
                    constexpr inline integer& operator =(const long) noexcept;
                    constexpr inline integer& operator =(const long long) noexcept;
                    constexpr inline integer& operator =(const short) noexcept;
                    constexpr inline integer& operator =(const unsigned int) noexcept;
                    constexpr inline integer& operator =(const unsigned long) noexcept;
                    constexpr inline integer& operator =(const unsigned long long) noexcept;
                    constexpr inline integer& operator =(const unsigned short) noexcept;
                    constexpr inline integer& operator =(integer&) noexcept;
                    constexpr inline integer& operator =(integer&&) noexcept;
                    constexpr inline integer& operator =(const integer&) noexcept;
                    constexpr inline integer& operator =(const integer&&) noexcept;
                    constexpr inline boolean operator <(const integer&) const noexcept;
                    constexpr inline boolean operator >(const integer&) const noexcept;
                    constexpr inline integer& operator +=(const integer&) noexcept;
                    constexpr inline integer& operator -=(const integer&) noexcept;
                    constexpr inline integer& operator *=(const integer&) noexcept;
                    constexpr inline integer& operator /=(const integer&) noexcept;
                    constexpr inline integer& operator %=(const integer&) noexcept;
                    constexpr inline integer& operator ^=(const integer&) noexcept;
                    constexpr inline integer& operator &=(const integer&) noexcept;
                    constexpr inline integer& operator |=(const integer&) noexcept;
                    constexpr inline integer operator <<(const integer&) noexcept;
                    constexpr inline integer operator >>(const integer&) noexcept;
                    constexpr inline integer& operator >>=(const integer&) noexcept;
                    constexpr inline integer& operator <<=(const integer&) noexcept;
                    constexpr inline boolean operator ==(const integer&) const noexcept;
                    constexpr inline boolean operator !=(const integer&) const noexcept;
                    constexpr inline boolean operator <=(const integer&) const noexcept;
                    constexpr inline boolean operator >=(const integer&) const noexcept;
                    constexpr inline boolean operator &&(const integer&) const noexcept;
                    constexpr inline boolean operator ||(const integer&) const noexcept;
                    constexpr inline integer operator ++(int) const noexcept;
                    constexpr inline integer operator ++(void) const noexcept;
                    constexpr inline integer operator --(int) const noexcept;
                    constexpr inline integer operator --(void) const noexcept;

                    constexpr inline operator long long(void) const noexcept;
            };

            // Number
            struct LapysDevelopmentKit::Types::number {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;

                // [...]
                private:
                    // Initialization > Value
                    long double value;

                // [...]
                public:
                    // [Constructor]
                    constexpr inline number(const double);
                    constexpr inline number(const float);
                    constexpr inline number(const int);
                    constexpr inline number(const long);
                    constexpr inline number(const long double);
                    constexpr inline number(const long long);
                    constexpr inline number(const short);
                    constexpr inline number(const unsigned int);
                    constexpr inline number(const unsigned long);
                    constexpr inline number(const unsigned long long);
                    constexpr inline number(const unsigned short);
                    constexpr inline number(void);

                    constexpr inline number(number&);
                    constexpr inline number(number&&);
                    constexpr inline number(const number&);
                    constexpr inline number(const number&&);

                    // [Operator] > ...
                    constexpr inline number operator +(void) const noexcept;
                    constexpr inline number operator +(const double) const noexcept;
                    constexpr inline number operator +(const float) const noexcept;
                    constexpr inline number operator +(const int) const noexcept;
                    constexpr inline number operator +(const long) const noexcept;
                    constexpr inline number operator +(const long double) const noexcept;
                    constexpr inline number operator +(const long long) const noexcept;
                    constexpr inline number operator +(const short) const noexcept;
                    constexpr inline number operator +(const unsigned int) const noexcept;
                    constexpr inline number operator +(const unsigned long) const noexcept;
                    constexpr inline number operator +(const unsigned long long) const noexcept;
                    constexpr inline number operator +(const unsigned short) const noexcept;
                    constexpr inline number operator +(number&) const noexcept;
                    constexpr inline number operator +(number&&) const noexcept;
                    constexpr inline number operator +(const number&) const noexcept;
                    constexpr inline number operator +(const number&&) const noexcept;
                    constexpr inline number operator -(void) const noexcept;
                    constexpr inline number operator -(const number&) const noexcept;
                    constexpr inline number operator *(const number&) const noexcept;
                    constexpr inline number operator /(const number&) const noexcept;
                    constexpr inline number operator %(const number&) const noexcept;
                    constexpr inline number operator ^(const number&) const noexcept;
                    constexpr inline number operator &(const number&) const noexcept;
                    constexpr inline number operator |(const number&) const noexcept;
                    constexpr inline number operator ~(void) const noexcept;
                    constexpr inline boolean operator !(void) const noexcept;
                    constexpr inline number& operator =(const int) noexcept;
                    constexpr inline number& operator =(const long) noexcept;
                    constexpr inline number& operator =(const long long) noexcept;
                    constexpr inline number& operator =(const short) noexcept;
                    constexpr inline number& operator =(const unsigned int) noexcept;
                    constexpr inline number& operator =(const unsigned long) noexcept;
                    constexpr inline number& operator =(const unsigned long long) noexcept;
                    constexpr inline number& operator =(const unsigned short) noexcept;
                    constexpr inline number& operator =(number&) noexcept;
                    constexpr inline number& operator =(number&&) noexcept;
                    constexpr inline number& operator =(const number&) noexcept;
                    constexpr inline number& operator =(const number&&) noexcept;
                    constexpr inline boolean operator <(const number&) const noexcept;
                    constexpr inline boolean operator >(const number&) const noexcept;
                    constexpr inline number& operator +=(const number&) noexcept;
                    constexpr inline number& operator -=(const number&) noexcept;
                    constexpr inline number& operator *=(const number&) noexcept;
                    constexpr inline number& operator /=(const number&) noexcept;
                    constexpr inline number& operator %=(const number&) noexcept;
                    constexpr inline number& operator ^=(const number&) noexcept;
                    constexpr inline number& operator &=(const number&) noexcept;
                    constexpr inline number& operator |=(const number&) noexcept;
                    constexpr inline number operator <<(const number&) noexcept;
                    constexpr inline number operator >>(const number&) noexcept;
                    constexpr inline number& operator >>=(const number&) noexcept;
                    constexpr inline number& operator <<=(const number&) noexcept;
                    constexpr inline boolean operator ==(const number&) const noexcept;
                    constexpr inline boolean operator !=(const number&) const noexcept;
                    constexpr inline boolean operator <=(const number&) const noexcept;
                    constexpr inline boolean operator >=(const number&) const noexcept;
                    constexpr inline boolean operator &&(const number&) const noexcept;
                    constexpr inline boolean operator ||(const number&) const noexcept;
                    constexpr inline number operator ++(int) const noexcept;
                    constexpr inline number operator ++(void) const noexcept;
                    constexpr inline number operator --(int) const noexcept;
                    constexpr inline number operator --(void) const noexcept;

                    constexpr inline operator long double(void) const;
            };

            // Size
            struct LapysDevelopmentKit::Types::size : LapysDevelopmentKit::Types::number {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;

                // [...]
                private:
                    // Definition > Value
                    unsigned long long value;

                // [...]
                public:
                    // [Constructor]
                    constexpr inline size(const LapysDevelopmentKit::Types::number);
                    constexpr inline size(void);

                    constexpr inline size(size&);
                    constexpr inline size(size&&);
                    constexpr inline size(const size&);
                    constexpr inline size(const size&&);

                    // [Operator] > ...
                    constexpr inline size& operator =(const LapysDevelopmentKit::Types::number) noexcept;
                    constexpr inline size& operator =(size&) noexcept;
                    constexpr inline size& operator =(size&&) noexcept;
                    constexpr inline size& operator =(const size&) noexcept;
                    constexpr inline size& operator =(const size&&) noexcept;

                    constexpr inline operator long double(void) const = delete;
                    constexpr inline operator unsigned long long(void) const noexcept;
            };

            // Object
            struct LapysDevelopmentKit::Types::object {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;

                // [...]
                private:
                    // Definition > Index
                    size id;

                // [...]
                protected:
                    // Declaration > ...
                    inline virtual void initiate() const = 0;
                    inline virtual void reset() const = 0;
                    inline virtual void update() const = 0;
                    inline virtual void terminate() const = 0;

                // [...]
                public:
                    // Modification > Registry ...
                    static object *registry;
                    static size registry_length;

                    // [Constructor]
                    object(void);
                    constexpr inline object(object&) = delete;
                    constexpr inline object(object&&) = delete;
                    constexpr inline object(const object&) = delete;
                    constexpr inline object(const object&&) = delete;

                    // [Destructor]
                    ~object(void);

                    // [Operator] > [=]
                    inline object& operator =(object&) const = delete;
                    inline object& operator =(object&&) const = delete;
                    inline object& operator =(const object&) const = delete;
                    inline object& operator =(const object&&) const = delete;
            };

            // Pointer
            struct LapysDevelopmentKit::Types::pointer {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;

                // [...]
                private:
                    // [Constructor]
                    constexpr inline pointer(void);
                    constexpr inline pointer(pointer&);
                    constexpr inline pointer(pointer&&);
                    constexpr inline pointer(const pointer&);
                    constexpr inline pointer(const pointer&&);

                    // [Operator] > ...
                    inline operator *(void) const noexcept;
                    inline operator &(void) const noexcept;
                    inline operator ->(void) const noexcept;

                    inline pointer& operator =(pointer&) const noexcept;
                    inline pointer& operator =(pointer&&) const noexcept;
                    inline pointer& operator =(const pointer&) const noexcept;
                    inline pointer& operator =(const pointer&&) const noexcept;
            };
                // Null Pointer
                struct LapysDevelopmentKit::Types::null_pointer : LapysDevelopmentKit::Types::pointer {
                    /* ... */
                    friend LapysDevelopmentKit::Types::boolean;
                    friend LapysDevelopmentKit::Types::character;
                    friend LapysDevelopmentKit::Types::fraction;
                    friend LapysDevelopmentKit::Types::integer;
                    friend LapysDevelopmentKit::Types::number;
                    friend LapysDevelopmentKit::Types::object;
                    friend LapysDevelopmentKit::Types::pointer;
                    friend LapysDevelopmentKit::Types::primitive;
                    friend LapysDevelopmentKit::Types::shared_pointer;
                    friend LapysDevelopmentKit::Types::size;
                    friend LapysDevelopmentKit::Types::string;
                    friend LapysDevelopmentKit::Types::unique_pointer;

                    // [...]
                    private:
                        // [Constructor]
                        constexpr inline null_pointer(null_pointer&) noexcept;
                        constexpr inline null_pointer(null_pointer&&) noexcept;
                        constexpr inline null_pointer(const null_pointer&) noexcept;
                        constexpr inline null_pointer(const null_pointer&&) noexcept;

                        // [Operator] > [=]
                        inline null_pointer& operator =(null_pointer&) const noexcept;
                        inline null_pointer& operator =(null_pointer&&) const noexcept;
                        inline null_pointer& operator =(const null_pointer&) const noexcept;
                        inline null_pointer& operator =(const null_pointer&&) const noexcept;

                    // [...]
                    public:
                        // [Constructor]
                        constexpr inline null_pointer(void);

                        // [Operator] > [...]
                        template <typename type> inline operator type*() const noexcept;
                };

                // Shared Pointer
                struct LapysDevelopmentKit::Types::shared_pointer : LapysDevelopmentKit::Types::pointer {
                    /* ... */
                    friend LapysDevelopmentKit::Types::boolean;
                    friend LapysDevelopmentKit::Types::character;
                    friend LapysDevelopmentKit::Types::fraction;
                    friend LapysDevelopmentKit::Types::integer;
                    friend LapysDevelopmentKit::Types::null_pointer;
                    friend LapysDevelopmentKit::Types::number;
                    friend LapysDevelopmentKit::Types::object;
                    friend LapysDevelopmentKit::Types::pointer;
                    friend LapysDevelopmentKit::Types::primitive;
                    friend LapysDevelopmentKit::Types::size;
                    friend LapysDevelopmentKit::Types::string;
                    friend LapysDevelopmentKit::Types::unique_pointer;

                    // [...]
                    private:
                        // Definition > (References ..., Value)
                        static struct shared_pointer_reference {
                            // ...
                            friend shared_pointer;

                            // [...]
                            private:
                                // Definition > (Reference Count, Value)
                                size referenceCount;
                                const void *value;

                            // [...]
                            public:
                                // [Constructor]
                                constexpr inline shared_pointer_reference(const void*, const size);
                        } *references;
                        static size references_length;

                        void *value;

                    // [...]
                    public:
                        // [Constructor]
                        template <typename type> shared_pointer(type*);

                        // [Destructor]
                        ~shared_pointer(void);

                        // [Operator] > ...
                        template <typename type> shared_pointer& operator =(type*);
                };

                // Unique Pointer
                struct LapysDevelopmentKit::Types::unique_pointer : LapysDevelopmentKit::Types::pointer {
                    /* ... */
                    friend LapysDevelopmentKit::Types::boolean;
                    friend LapysDevelopmentKit::Types::character;
                    friend LapysDevelopmentKit::Types::fraction;
                    friend LapysDevelopmentKit::Types::integer;
                    friend LapysDevelopmentKit::Types::null_pointer;
                    friend LapysDevelopmentKit::Types::number;
                    friend LapysDevelopmentKit::Types::object;
                    friend LapysDevelopmentKit::Types::pointer;
                    friend LapysDevelopmentKit::Types::primitive;
                    friend LapysDevelopmentKit::Types::shared_pointer;
                    friend LapysDevelopmentKit::Types::size;
                    friend LapysDevelopmentKit::Types::string;
                };

            // Primitive
            struct LapysDevelopmentKit::Types::primitive {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::string;
                friend LapysDevelopmentKit::Types::unique_pointer;
            };

            // String
            struct LapysDevelopmentKit::Types::string {
                /* ... */
                friend LapysDevelopmentKit::Types::boolean;
                friend LapysDevelopmentKit::Types::character;
                friend LapysDevelopmentKit::Types::fraction;
                friend LapysDevelopmentKit::Types::integer;
                friend LapysDevelopmentKit::Types::null_pointer;
                friend LapysDevelopmentKit::Types::number;
                friend LapysDevelopmentKit::Types::object;
                friend LapysDevelopmentKit::Types::pointer;
                friend LapysDevelopmentKit::Types::primitive;
                friend LapysDevelopmentKit::Types::shared_pointer;
                friend LapysDevelopmentKit::Types::size;
                friend LapysDevelopmentKit::Types::unique_pointer;
            };

        /* Functions */
            // Array > Memory Chunk Allocation
            enum LapysDevelopmentKit::Functions::array__memory_chunk_allocation_method : unsigned char {EXPONENTIAL, FIBONACCI, LINEAR};

        /* Types */
            // Boolean
                // [Constructor]
                constexpr inline LapysDevelopmentKit::Types::boolean::boolean(const unsigned char argument) : value{argument ? this -> boolean_true : this -> boolean_false} {}
                constexpr inline LapysDevelopmentKit::Types::boolean::boolean(boolean& argument) : value{argument.value} {}
                constexpr inline LapysDevelopmentKit::Types::boolean::boolean(boolean&& argument) : value{argument.value} {}
                constexpr inline LapysDevelopmentKit::Types::boolean::boolean(const boolean& argument) : value{argument.value} {}
                constexpr inline LapysDevelopmentKit::Types::boolean::boolean(const boolean&& argument) : value{argument.value} {}

            // Null Pointer > ([Constructor], [Operator] > [...])
            constexpr inline LapysDevelopmentKit::Types::null_pointer::null_pointer(void) {}
            template <typename type> inline LapysDevelopmentKit::Types::null_pointer::operator type*() const noexcept { return NULL; }

            // Number
                // [Constructor]
                constexpr inline LapysDevelopmentKit::Types::number::number(const double argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const float argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const int argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const long argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const long double argument) : value{argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const long long argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const short argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const unsigned int argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const unsigned long argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const unsigned long long argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const unsigned short argument) : value{(long double) argument} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(void) : value{0.00} {}

                constexpr inline LapysDevelopmentKit::Types::number::number(number& argument) : value{argument.value} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(number&& argument) : value{argument.value} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const number& argument) : value{argument.value} {}
                constexpr inline LapysDevelopmentKit::Types::number::number(const number&& argument) : value{argument.value} {}

            // Pointer > [Constructor]
            constexpr inline LapysDevelopmentKit::Types::pointer::pointer(void) {}

            // Shared Pointer
                // [Constructor]
                template <typename type>
                LapysDevelopmentKit::Types::shared_pointer::shared_pointer(type* argument) : value{argument} {}

                // [Destructor]
                LapysDevelopmentKit::Types::shared_pointer::~shared_pointer(void) {}

                // [Operator] > ...
                template <typename type>
                LapysDevelopmentKit::Types::shared_pointer& LapysDevelopmentKit::Types::shared_pointer::operator =(type* pointer) {
                    // Return
                    return *this;
                }

                // References (Length)
                LapysDevelopmentKit::Types::shared_pointer::shared_pointer_reference *LapysDevelopmentKit::Types::shared_pointer::references {NULL};
                LapysDevelopmentKit::Types::size LapysDevelopmentKit::Types::shared_pointer::references_length {0u};

                /* Shared Pointer Reference > [Constructor] */
                constexpr inline LapysDevelopmentKit::Types::shared_pointer::shared_pointer_reference::shared_pointer_reference(const void* pointer, const size referenceCount) : referenceCount{referenceCount}, value{pointer} {}

            // Size
                // [Constructor]
                constexpr inline size(const LapysDevelopmentKit::Types::number argument) { if (LapysDevelopmentKit::Functions::number__is_finite(argument.value) && !LapysDevelopmentKit::Functions::number__is_nan(argument.value)) this -> value = (unsigned long long) argument.value; }
                constexpr inline size(void) : value{0uLL} {}

                constexpr inline size(size& argument) : value{argument.value} {}
                constexpr inline size(size&& argument) : value{argument.value} {}
                constexpr inline size(const size& argument) : value{argument.value} {}
                constexpr inline size(const size&& argument) : value{argument.value} {}

    /* [Modification] Namespace > Lapys Development Kit */
    namespace LapysDevelopmentKit {
        /* Constants */
        namespace Constants {
            // Constant > Null
            constexpr const LapysDevelopmentKit::Types::null_pointer null;
        }
    }

    /* Modification > Lapys Development Kit */
        /* Functions */
            // Array > Allocate Memory Chunk
            template <typename type> LapysDevelopmentKit::Types::size LapysDevelopmentKit::Functions::array__allocate_memory_chunk(type*& array, const LapysDevelopmentKit::Types::size currentLength, const LapysDevelopmentKit::Types::size newLength) { return LapysDevelopmentKit::Functions::array__allocate_memory_chunk(array, currentLength, newLength, LapysDevelopmentKit::Functions::array__memory_chunk_allocation_method::LINEAR); }
            template <typename type> LapysDevelopmentKit::Types::size LapysDevelopmentKit::Functions::array__allocate_memory_chunk(type*& array, const LapysDevelopmentKit::Types::size currentLength, const LapysDevelopmentKit::Types::size newLength, const LapysDevelopmentKit::Functions::array__memory_chunk_allocation_method ALLOCATION_METHOD) {
                // Initialization > Length
                LapysDevelopmentKit::Types::size length = currentLength;

                // Logic
                switch (ALLOCATION_METHOD) {
                    // [Exponential]
                    case LapysDevelopmentKit::Functions::array__memory_chunk_allocation_method::EXPONENTIAL: {} break;

                    // [Fibonacci]
                    case LapysDevelopmentKit::Functions::array__memory_chunk_allocation_method::FIBONACCI: {} break;

                    // [Linear]
                    case LapysDevelopmentKit::Functions::array__memory_chunk_allocation_method::LINEAR: {} break;
                }

                // Return
                return length;
            }

            // Number Is ...
            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const double argument) { return !std::isinf(argument); }
            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const float argument) { return !std::isinf(argument); }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const int argument) { return true; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const long argument) { return true; }
            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const long double argument) { return !std::isinf(argument); }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const long long argument) { return true; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const short argument) { return true; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const unsigned int argument) { return true; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const unsigned long argument) { return true; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const unsigned long long argument) { return true; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_finite(const unsigned short argument) { return true; }

            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const double argument) { return std::isinf(argument); }
            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const float argument) { return std::isinf(argument); }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const int argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const long argument) { return false; }
            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const long double argument) { return std::isinf(argument); }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const long long argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const short argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const unsigned int argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const unsigned long argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const unsigned long long argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_infinite(const unsigned short argument) { return false; }

            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const double argument) { return std::isnan(argument); }
            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const float argument) { return std::isnan(argument); }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const int argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const long argument) { return false; }
            inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const long double argument) { return std::isnan(argument); }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const long long argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const short argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const unsigned int argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const unsigned long argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const unsigned long long argument) { return false; }
            constexpr inline LapysDevelopmentKit::Types::boolean LapysDevelopmentKit::Functions::number__is_nan(const unsigned short argument) { return false; }

            // Pointer ... Memory
            template <typename type> inline type* LapysDevelopmentKit::Functions::pointer__allocate_memory(type*& pointer, const LapysDevelopmentKit::Types::size size) { return (pointer = std::malloc(size)); }
            template <typename type> inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__free_memory(type*& pointer) { std::free(pointer); return (pointer = LapysDevelopmentKit::Constants::null); }
            template <typename type> inline type* LapysDevelopmentKit::Functions::pointer__reallocate_memory(type*& pointer, const LapysDevelopmentKit::Types::size size) { return (pointer = std::realloc(pointer, size)); }
#endif
