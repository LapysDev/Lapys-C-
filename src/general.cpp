/* Pragma */
#pragma once

/* Class */
    /* Boolean --- NOTE (Lapys) -> Allowed niladic constructor. */
    struct boolean {
        // [...]
        private:
            // Definition > Value
            enum {boolean_false, boolean_true} value;

        // [...]
        public:
            // [Constructor]
            constexpr inline boolean(bool const);
            constexpr inline boolean(void);
            constexpr inline boolean(boolean&);
            constexpr inline boolean(boolean const&);
            constexpr inline boolean(boolean&&);
            constexpr inline boolean(boolean const&&);

            // [Operator] > ...
            inline boolean& operator =(bool const) noexcept;
            inline boolean& operator =(boolean&) noexcept;
            inline boolean& operator =(boolean&&) noexcept;
            inline boolean& operator =(boolean const&) noexcept;
            inline boolean& operator =(boolean const&&) noexcept;

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

    /* Wide
            --- NOTE (Lapys) -> Alias for the largest C++ primitive integral type; Allowed niladic constructor.
            --- WARN (Lapys) -> Defers value without sign which may cause misinterpretations.
    */
    struct wide {
        // [...]
        public:
            // Definition > (..., Value)
            #if cpp__version <= 2011uL
                typedef signed long long wide_signed_type;
                typedef unsigned long long wide_unsigned_type;
            #else
                typedef signed long wide_signed_type;
                typedef unsigned long wide_unsigned_type;
            #endif

        // [...]
        private:
            wide_unsigned_type value;

        // [...]
        public:
            // [Constructor]
            constexpr inline wide(void);
            template <typename type> constexpr inline wide(type);

            // [Operator] > ...
            template <typename type> inline wide& operator =(type argument) noexcept;
            template <typename type> inline wide& operator +=(type argument) noexcept;
            template <typename type> inline wide& operator -=(type argument) noexcept;
            template <typename type> inline wide& operator *=(type argument) noexcept;
            template <typename type> inline wide& operator /=(type argument) noexcept;
            template <typename type> inline wide& operator %=(type argument) noexcept;
            template <typename type> inline wide& operator ^=(type argument) noexcept;
            template <typename type> inline wide& operator &=(type argument) noexcept;
            template <typename type> inline wide& operator |=(type argument) noexcept;
            template <typename type> inline wide& operator >>=(type argument) noexcept;
            template <typename type> inline wide& operator <<=(type argument) noexcept;
            inline wide operator ++(int const) noexcept;
            inline wide& operator ++(void) noexcept;
            inline wide operator --(int const) noexcept;
            inline wide& operator --(void) noexcept;

            constexpr inline operator wide_unsigned_type(void) const noexcept;
    };

    /* Integral --- WARN (Lapys) -> Requires the `wide` type; Stores value without sign. */
    struct integral {
        // [...]
        private:
            // Definition > (..., Value)
            enum {integral__int__type, integral__long__type, integral__short__type, integral__wide__type} type;
            union integral_value { public: unsigned int integral__int__value; unsigned long integral__long__value; unsigned short integral__short__value; wide integral__wide__value; } value;

        // [...]
        public:
            // [Constructor]
            inline integral(int const);
            inline integral(long const);
            inline integral(short const);
            inline integral(unsigned int const);
            inline integral(unsigned long const);
            inline integral(unsigned short const);
            inline integral(wide const);
            inline integral(integral&);
            inline integral(integral&&);
            inline integral(integral const&);
            inline integral(integral const&&);

            // [Operator] > ...
            inline integral& operator =(int const) noexcept;
            inline integral& operator =(long const) noexcept;
            inline integral& operator =(short const) noexcept;
            inline integral& operator =(unsigned int const) noexcept;
            inline integral& operator =(unsigned long const) noexcept;
            inline integral& operator =(unsigned short const) noexcept;
            inline integral& operator =(wide const) noexcept;
            inline integral& operator =(integral&) noexcept;
            inline integral& operator =(integral&&) noexcept;
            inline integral& operator =(integral const&) noexcept;
            inline integral& operator =(integral const&&) noexcept;

            inline operator wide(void) const noexcept;
    };

    /* Rational */
    struct rational {
        // [...]
        private:
            // Definition > (..., Value)
            enum {rational__double__type, rational__float__type, rational__long_double__type} type;
            union rational_value { public: double rational__double__value; float rational__float__value; long double rational__long_double__value; } value;

        // [...]
        public:
            // [Constructor]
            inline rational(double const);
            inline rational(float const);
            inline rational(long double const);
            constexpr inline rational(rational&);
            constexpr inline rational(rational&&);
            constexpr inline rational(rational const&);
            constexpr inline rational(rational const&&);

            // [Operator] > ...
            inline rational& operator =(double const) noexcept;
            inline rational& operator =(float const) noexcept;
            inline rational& operator =(long double const) noexcept;
            inline rational& operator =(rational&) noexcept;
            inline rational& operator =(rational&&) noexcept;
            inline rational& operator =(rational const&) noexcept;
            inline rational& operator =(rational const&&) noexcept;

            inline operator long double(void) const noexcept;
    };

    /* Number --- WARN (Lapys) -> Requires the `integral`, `rational`, and `wide` type. */
    struct number {
        // [...]
        private:
            // Definition > (..., Value)
            enum {number__integral__type, number__rational__type} type;
            union number_value { public: integral number__integral__value; rational number__rational__value; } value;

        // [...]
        public:
            // [Constructor]
            inline number(integral const);
            inline number(rational const);
            inline number(number&);
            inline number(number&&);
            inline number(number const&);
            inline number(number const&&);

            // [Operator] > ...
            inline number& operator =(integral const) noexcept;
            inline number& operator =(rational const) noexcept;
            inline number& operator =(number&) noexcept;
            inline number& operator =(number&&) noexcept;
            inline number& operator =(number const&) noexcept;
            inline number& operator =(number const&&) noexcept;

            inline operator double(void) noexcept;
            inline operator float(void) noexcept;
            inline operator int(void) noexcept;
            inline operator long(void) noexcept;
            inline operator long double(void) noexcept;
            inline operator long long(void) noexcept;
            inline operator short(void) noexcept;
            inline operator unsigned int(void) noexcept;
            inline operator unsigned long(void) noexcept;
            inline operator unsigned short(void) noexcept;
            inline operator wide(void) noexcept;
    };

    /* Pointer --- NOTE (Lapys) -> Base user-defined type. */
    struct pointer {
        // [...]
        public:
            // [Constructor]
            constexpr inline pointer(void);
            constexpr inline pointer(pointer&);
            constexpr inline pointer(pointer&&);
            constexpr inline pointer(pointer const&);
            constexpr inline pointer(pointer const&&);

            // [Operator] > ...
            inline virtual void operator *(void) const noexcept;
            inline virtual void operator &(void) const noexcept;

            template <typename type> inline operator type*(void) const noexcept;
    };

    /* Null Pointer --- NOTE (Lapys) -> Allowed niladic constructor. */
    struct null_pointer : pointer {
        // [...]
        public:
            // [Constructor]
            constexpr inline null_pointer(void);
            constexpr inline null_pointer(null_pointer&);
            constexpr inline null_pointer(null_pointer&&);
            constexpr inline null_pointer(null_pointer const&);
            constexpr inline null_pointer(null_pointer const&&);

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
            constexpr inline raw_pointer(raw_pointer&);
            constexpr inline raw_pointer(raw_pointer&&);
            constexpr inline raw_pointer(raw_pointer const&);
            constexpr inline raw_pointer(raw_pointer const&&);
            template <typename type> constexpr inline raw_pointer(type* const);

            // [Operator] > ...
            inline raw_pointer& operator =(raw_pointer&) noexcept;
            inline raw_pointer& operator =(raw_pointer&&) noexcept;
            inline raw_pointer& operator =(raw_pointer const&) noexcept;
            inline raw_pointer& operator =(raw_pointer const&&) noexcept;
            template <typename type> inline raw_pointer& operator =(type* const) noexcept;

            constexpr inline void operator *(void) const noexcept;
            constexpr inline void operator &(void) const noexcept;
            template <typename type> inline operator type*(void) const noexcept;
    };

    /* Primitive --- WARN (Lapys) -> Requires `number`, and `pointer` types. */
    struct primitive {
        // [...]
        private:
            // Definition > (..., Value)
            enum {primitive__number__type, primitive__pointer__type} type;
            union primitive_value { public: number primitive__number__value; raw_pointer primitive__pointer__value; } value;

        // [...]
        public:
            // [Constructor]
            inline primitive(number const);
            inline primitive(raw_pointer const);
            inline primitive(primitive&);
            inline primitive(primitive&&);
            inline primitive(primitive const&);
            inline primitive(primitive const&&);

            // [Operator] > ...
            inline primitive& operator =(number const) noexcept;
            inline primitive& operator =(raw_pointer const) noexcept;
            inline primitive& operator =(primitive&) noexcept;
            inline primitive& operator =(primitive&&) noexcept;
            inline primitive& operator =(primitive const&) noexcept;
            inline primitive& operator =(primitive const&&) noexcept;

            inline operator number(void) noexcept;
            inline operator pointer(void) noexcept;
    };

    /* String
            --- NOTE (Lapys) -> Manages its own data store.
            --- WARN (Lapys) -> Requires the `character` type.
    */
    struct string {
        // [...]
        private:
            // Definition > (..., Value)
            size_t length;
            character *value;

        // [...]
        public:
            // [Constructor]
            inline string(char* const);
            inline string(char const* const);
            inline string(char8_t* const);
            inline string(char8_t const* const);
            inline string(char16_t* const);
            inline string(char16_t const* const);
            inline string(char32_t* const);
            inline string(char32_t const* const);
            inline string(signed char* const);
            inline string(signed char const* const);
            inline string(unsigned char* const);
            inline string(unsigned char const* const);
            inline string(wchar_t* const);
            inline string(wchar_t const* const);
            inline string(void);
            inline string(string&);
            inline string(string&&);
            inline string(string const&);
            inline string(string const&&);
            template <size_t length> inline string(char (&)[length]);
            template <size_t length> inline string(char const (&)[length]);
            template <size_t length> inline string(char8_t (&)[length]);
            template <size_t length> inline string(char8_t const (&)[length]);
            template <size_t length> inline string(char16_t (&)[length]);
            template <size_t length> inline string(char16_t const (&)[length]);
            template <size_t length> inline string(char32_t (&)[length]);
            template <size_t length> inline string(char32_t const (&)[length]);
            template <size_t length> inline string(signed char (&)[length]);
            template <size_t length> inline string(signed char const (&)[length]);
            template <size_t length> inline string(unsigned char (&)[length]);
            template <size_t length> inline string(unsigned char const (&)[length]);
            template <size_t length> inline string(wchar_t (&)[length]);
            template <size_t length> inline string(wchar_t const (&)[length]);

            // [Destructor]
            ~string(void);

            // [Operator] > ...
            inline string& operator =(char* const) noexcept;
            inline string& operator =(char const* const) noexcept;
            inline string& operator =(char8_t* const) noexcept;
            inline string& operator =(char8_t const* const) noexcept;
            inline string& operator =(char16_t* const) noexcept;
            inline string& operator =(char16_t const* const) noexcept;
            inline string& operator =(char32_t* const) noexcept;
            inline string& operator =(char32_t const* const) noexcept;
            inline string& operator =(signed char* const) noexcept;
            inline string& operator =(signed char const* const) noexcept;
            inline string& operator =(unsigned char* const) noexcept;
            inline string& operator =(unsigned char const* const) noexcept;
            inline string& operator =(wchar_t* const) noexcept;
            inline string& operator =(wchar_t const* const) noexcept;
            inline string& operator =(string&) noexcept;
            inline string& operator =(string&&) noexcept;
            inline string& operator =(string const&) noexcept;
            inline string& operator =(string const&&) noexcept;
            template <size_t length> inline string& operator =(char (&)[length]) noexcept;
            template <size_t length> inline string& operator =(char const (&)[length]) noexcept;
            template <size_t length> inline string& operator =(char8_t (&)[length]) noexcept;
            template <size_t length> inline string& operator =(char8_t const (&)[length]) noexcept;
            template <size_t length> inline string& operator =(char16_t (&)[length]) noexcept;
            template <size_t length> inline string& operator =(char16_t const (&)[length]) noexcept;
            template <size_t length> inline string& operator =(char32_t (&)[length]) noexcept;
            template <size_t length> inline string& operator =(char32_t const (&)[length]) noexcept;
            template <size_t length> inline string& operator =(signed char (&)[length]) noexcept;
            template <size_t length> inline string& operator =(signed char const (&)[length]) noexcept;
            template <size_t length> inline string& operator =(unsigned char (&)[length]) noexcept;
            template <size_t length> inline string& operator =(unsigned char const (&)[length]) noexcept;
            template <size_t length> inline string& operator =(wchar_t (&)[length]) noexcept;
            template <size_t length> inline string& operator =(wchar_t const (&)[length]) noexcept;

            inline operator char*(void) const noexcept;
            inline operator char const*(void) const noexcept;
            inline operator char8_t*(void) const noexcept;
            inline operator char8_t const*(void) const noexcept;
            inline operator char16_t*(void) const noexcept;
            inline operator char16_t const*(void) const noexcept;
            inline operator char32_t*(void) const noexcept;
            inline operator char32_t const*(void) const noexcept;
            inline operator signed char*(void) const noexcept;
            inline operator signed char const*(void) const noexcept;
            inline operator unsigned char*(void) const noexcept;
            inline operator unsigned char const*(void) const noexcept;
            inline operator void*(void) const noexcept;
            inline operator void const*(void) const noexcept;
            inline operator wchar_t*(void) const noexcept;
            inline operator wchar_t const*(void) const noexcept;
            inline operator boolean(void) const noexcept;
    };

/* Function */
    /* Array */
        // Concatenate --- MINIFY (Lapys) --- NOTE (Lapys) -> Allocates memory onto the heap.
        void array__concatenate(void) noexcept {}

        // Copy --- MINIFY (Lapys) --- NOTE (Lapys) -> Allocates memory onto the heap.
        void array__copy(void) noexcept {}

        // Create --- NOTE (Lapys) -> Allocates memory onto the heap.
        template <size_t length, typename type> constexpr inline type* array__create(void) noexcept { return new type[length]; }

        // Fill --- CHECKPOINT (Lapys)
        template <size_t length, typename type> inline void array__fill(type* const array, type& value) noexcept { for (size_t iterator = 0u; iterator ^ length; ++iterator) pointer__source_copy_memory(array + iterator, &value, sizeof(type)); }
        template <size_t length, typename type> inline void array__fill(type* const array, type&& value) noexcept {
            for (size_t iterator = 0u; iterator ^ length; ++iterator)
            pointer__source_copy_memory(array + iterator, &value, sizeof(type));
        }

        // Free --- WARN (Lapys) -> Assumes the array is heap allocated.
        void array__free(void) noexcept {}

        // Includes
        void array__includes(void) noexcept {}

        // Index --- NOTE (Lapys) -> Custom searching algorithm.
        void array__index(void) noexcept {}

        // Index From Back
        void array__index_from_back(void) noexcept {}

        // Index From Front
        void array__index_from_front(void) noexcept {}

        // Resize --- WARN (Lapys) -> Assumes the array is heap-allocated.
        void array__resize(void) noexcept {}

        // Reverse --- MINIFY (Lapys)
        void array__reverse(void) noexcept {}

        // Slice
        void array__slice(void) noexcept {}

        // Splice
        void array__splice(void) noexcept {}

        // Source Concatenate --- WARN (Lapys) -> Assumes the array is heap-allocated.
        void array__source_concatenate(void) noexcept {}

        // Source Copy --- WARN (Lapys) -> Assumes the array is heap-allocated.
        void array__source_copy(void) noexcept {}

        // Zero
        template <size_t> void array__zero(void* const) noexcept;
        template <size_t> void array__zero(void const* const) noexcept;
        template <size_t length, typename type> inline void array__zero(type* const array) noexcept { pointer__zero_memory(array, length * sizeof(type)); }
        template <size_t length, typename type> inline void array__zero(type (&array)[length]) noexcept { pointer__zero_memory(array, length * sizeof(type)); }

    /* Number */
        // Absolute
        constexpr inline double number__absolute(double const number) noexcept { return ::fabs(number); }
        constexpr inline float number__absolute(float const number) noexcept {
            #if cpp__version >= 2011uL
                return ::fabsf(number);
            #else
                return ::fabs(number);
            #endif
        }
        constexpr inline int number__absolute(int const number) noexcept { return ::abs(number); }
        inline long number__absolute(long const number) noexcept {
            #if cpp__version >= 1997uL
                return ::abs(number);
            #else
                return number < 0L ? -number : number;
            #endif
        }
        constexpr inline long double number__absolute(long double const number) noexcept {
            #if cpp__version >= 2011uL
                return ::fabsl(number);
            #else
                return ::fabs(number);
            #endif
        }
        constexpr inline short number__absolute(short const number) noexcept { return number < 0 ? -number : number; }
        constexpr inline unsigned int number__absolute(unsigned int const number) noexcept { return number; }
        constexpr inline unsigned long number__absolute(unsigned long const number) noexcept { return number; }
        constexpr inline unsigned short number__absolute(unsigned short const number) noexcept { return number; }
        inline wide number__absolute(wide const number) noexcept {
            #if cpp__version >= 2011uL
                return ::abs((wide::wide_signed_type) number);
            #else
                if (((wide::wide_signed_type) number) < 0) return -((wide::wide_signed_type) number);
                else return number;
            #endif
        }

        // Arc Cosine
        constexpr inline double number__arc_cosine(double const number) { return ::acos(number); }
        constexpr inline float number__arc_cosine(float const number) {
            #if c__version >= 1990uL
                return ::acosf(number);
            #elif c__version
                return number__arc_cosine((double) number);
            #else
                return ::acos(number);
            #endif
        }
        constexpr inline float number__arc_cosine(int const number) {
            #if cpp__version >= 2011uL
                return ::acos(number);
            #else
                return number__arc_cosine((float) number);
            #endif
        }
        constexpr inline double number__arc_cosine(long const number) {
            #if cpp__version >= 2011uL
                return ::acos(number);
            #else
                return number__arc_cosine((double) number);
            #endif
        }
        constexpr inline long double number__arc_cosine(long double const number) {
            #if c__version <= 1999uL
                return ::acosl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_cosine(number - DBL_MAX);
                else return number__arc_cosine((double) number);
            #else
                return ::acos(number);
            #endif
        }
        constexpr inline float number__arc_cosine(short const number) {
            #if cpp__version >= 2011uL
                return ::acos(number);
            #else
                return number__arc_cosine((float) number);
            #endif
        }
        constexpr inline float number__arc_cosine(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::acos(number);
            #else
                return number__arc_cosine((float) number);
            #endif
        }
        constexpr inline double number__arc_cosine(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::acos(number);
            #else
                return number__arc_cosine((double) number);
            #endif
        }
        constexpr inline float number__arc_cosine(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::acos(number);
            #else
                return number__arc_cosine((float) number);
            #endif
        }
        inline long double number__arc_cosine(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::acos((wide::wide_signed_type) number);
                else return ::acos((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__arc_cosine((long double) (wide::wide_signed_type) number);
                else return number__arc_cosine((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Arc Sine
        constexpr inline double number__arc_sine(double const number) { return ::asin(number); }
        constexpr inline float number__arc_sine(float const number) {
            #if c__version >= 1990uL
                return ::asinf(number);
            #elif c__version
                return number__arc_sine((double) number);
            #else
                return ::asin(number);
            #endif
        }
        constexpr inline float number__arc_sine(int const number) {
            #if cpp__version >= 2011uL
                return ::asin(number);
            #else
                return number__arc_sine((float) number);
            #endif
        }
        constexpr inline double number__arc_sine(long const number) {
            #if cpp__version >= 2011uL
                return ::asin(number);
            #else
                return number__arc_sine((double) number);
            #endif
        }
        constexpr inline long double number__arc_sine(long double const number) {
            #if c__version <= 1999uL
                return ::asinl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_sine(number - DBL_MAX);
                else return number__arc_sine((double) number);
            #else
                return ::asin(number);
            #endif
        }
        constexpr inline float number__arc_sine(short const number) {
            #if cpp__version >= 2011uL
                return ::asin(number);
            #else
                return number__arc_sine((float) number);
            #endif
        }
        constexpr inline float number__arc_sine(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::asin(number);
            #else
                return number__arc_sine((float) number);
            #endif
        }
        constexpr inline double number__arc_sine(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::asin(number);
            #else
                return number__arc_sine((double) number);
            #endif
        }
        constexpr inline float number__arc_sine(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::asin(number);
            #else
                return number__arc_sine((float) number);
            #endif
        }
        inline long double number__arc_sine(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::asin((wide::wide_signed_type) number);
                else return ::asin((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__arc_sine((long double) (wide::wide_signed_type) number);
                else return number__arc_sine((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Arc Tangent
        constexpr inline double number__arc_tangent(double const number) { return ::atan(number); }
        constexpr inline float number__arc_tangent(float const number) {
            #if c__version >= 1990uL
                return ::atanf(number);
            #elif c__version
                return number__arc_tangent((double) number);
            #else
                return ::atan(number);
            #endif
        }
        constexpr inline float number__arc_tangent(int const number) {
            #if cpp__version >= 2011uL
                return ::atan(number);
            #else
                return number__arc_tangent((float) number);
            #endif
        }
        constexpr inline double number__arc_tangent(long const number) {
            #if cpp__version >= 2011uL
                return ::atan(number);
            #else
                return number__arc_tangent((double) number);
            #endif
        }
        constexpr inline long double number__arc_tangent(long double const number) {
            #if c__version <= 1999uL
                return ::atanl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
                else return number__arc_tangent((double) number);
            #else
                return ::atan(number);
            #endif
        }
        constexpr inline float number__arc_tangent(short const number) {
            #if cpp__version >= 2011uL
                return ::atan(number);
            #else
                return number__arc_tangent((float) number);
            #endif
        }
        constexpr inline float number__arc_tangent(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::atan(number);
            #else
                return number__arc_tangent((float) number);
            #endif
        }
        constexpr inline double number__arc_tangent(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::atan(number);
            #else
                return number__arc_tangent((double) number);
            #endif
        }
        constexpr inline float number__arc_tangent(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::atan(number);
            #else
                return number__arc_tangent((float) number);
            #endif
        }
        inline long double number__arc_tangent(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::atan((wide::wide_signed_type) number);
                else return ::atan((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__arc_tangent((long double) (wide::wide_signed_type) number);
                else return number__arc_tangent((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Area Hyperbolic Cosine
        constexpr inline double number__area_hyperbolic_cosine(double const number) {
            #if c__version <= 1999uL
                return ::acosh(number);
            #elif cpp__version >= 2011uL
                return ::acosh(number);
            #endif
            return NAN;
        }
        constexpr inline float number__area_hyperbolic_cosine(float const number) {
            #if c__version <= 1999uL
                return ::acosf(number);
            #elif cpp__version >= 2011uL
                return ::acosh(number);
            #endif
            return NANF;
        }
        constexpr inline float number__area_hyperbolic_cosine(int const number) {
            #if cpp__version >= 2011uL
                return ::acosh(number);
            #else
                return number__area_hyperbolic_cosine((float) number);
            #endif
        }
        constexpr inline double number__area_hyperbolic_cosine(long const number) {
            #if cpp__version >= 2011uL
                return ::acosh(number);
            #else
                return number__area_hyperbolic_cosine((double) number);
            #endif
        }
        constexpr inline long double number__area_hyperbolic_cosine(long double const number) {
            #if c__version <= 1999uL
                return ::acosl(number);
            #elif cpp__version >= 2011uL
                return ::acosh(number);
            #endif
            return NANL;
        }
        constexpr inline float number__area_hyperbolic_cosine(short const number) {
            #if cpp__version >= 2011uL
                return ::acosh(number);
            #else
                return number__area_hyperbolic_cosine((float) number);
            #endif
        }
        constexpr inline float number__area_hyperbolic_cosine(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::acosh(number);
            #else
                return number__area_hyperbolic_cosine((float) number);
            #endif
        }
        constexpr inline double number__area_hyperbolic_cosine(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::acosh(number);
            #else
                return number__area_hyperbolic_cosine((double) number);
            #endif
        }
        constexpr inline float number__area_hyperbolic_cosine(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::acosh(number);
            #else
                return number__area_hyperbolic_cosine((float) number);
            #endif
        }
        inline long double number__area_hyperbolic_cosine(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0) return ::acosh((wide::wide_signed_type) number);
                else return ::acosh((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0) return number__area_hyperbolic_cosine((long double) (wide::wide_signed_type) number);
                else return number__area_hyperbolic_cosine((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Area Hyperbolic Sine
        constexpr inline double number__area_hyperbolic_sine(double const number) {
            #if c__version <= 1999uL
                return ::asinh(number);
            #elif cpp__version >= 2011uL
                return ::asinh(number);
            #endif
            return NAN;
        }
        constexpr inline float number__area_hyperbolic_sine(float const number) {
            #if c__version <= 1999uL
                return ::asinhf(number);
            #elif cpp__version >= 2011uL
                return ::asinh(number);
            #endif
            return NANF;
        }
        constexpr inline float number__area_hyperbolic_sine(int const number) {
            #if cpp__version >= 2011uL
                return ::asinh(number);
            #else
                return number__area_hyperbolic_sine((float) number);
            #endif
        }
        constexpr inline double number__area_hyperbolic_sine(long const number) {
            #if cpp__version >= 2011uL
                return ::asinh(number);
            #else
                return number__area_hyperbolic_sine((double) number);
            #endif
        }
        constexpr inline long double number__area_hyperbolic_sine(long double const number) {
            #if c__version <= 1999uL
                return ::asinhl(number);
            #elif cpp__version >= 2011uL
                return ::asinh(number);
            #endif
            return NANL;
        }
        constexpr inline float number__area_hyperbolic_sine(short const number) {
            #if cpp__version >= 2011uL
                return ::asinh(number);
            #else
                return number__area_hyperbolic_sine((float) number);
            #endif
        }
        constexpr inline float number__area_hyperbolic_sine(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::asinh(number);
            #else
                return number__area_hyperbolic_sine((float) number);
            #endif
        }
        constexpr inline double number__area_hyperbolic_sine(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::asinh(number);
            #else
                return number__area_hyperbolic_sine((double) number);
            #endif
        }
        constexpr inline float number__area_hyperbolic_sine(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::asinh(number);
            #else
                return number__area_hyperbolic_sine((float) number);
            #endif
        }
        inline long double number__area_hyperbolic_sine(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0) return ::asinh((wide::wide_signed_type) number);
                else return ::asinh((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0) return number__area_hyperbolic_sine((long double) (wide::wide_signed_type) number);
                else return number__area_hyperbolic_sine((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Area Hyperbolic Tangent
        constexpr inline double number__area_hyperbolic_tangent(double const number) {
            #if c__version <= 1999uL
                return ::atanh(number);
            #elif cpp__version >= 2011uL
                return ::atanh(number);
            #endif
            return NAN;
        }
        constexpr inline float number__area_hyperbolic_tangent(float const number) {
            #if c__version <= 1999uL
                return ::atanhf(number);
            #elif cpp__version >= 2011uL
                return ::atanh(number);
            #endif
            return NANF;
        }
        constexpr inline float number__area_hyperbolic_tangent(int const number) {
            #if cpp__version >= 2011uL
                return ::atanh(number);
            #else
                return number__area_hyperbolic_tangent((float) number);
            #endif
        }
        constexpr inline double number__area_hyperbolic_tangent(long const number) {
            #if cpp__version >= 2011uL
                return ::atanh(number);
            #else
                return number__area_hyperbolic_tangent((double) number);
            #endif
        }
        constexpr inline long double number__area_hyperbolic_tangent(long double const number) {
            #if c__version <= 1999uL
                return ::atanhl(number);
            #elif cpp__version >= 2011uL
                return ::atanh(number);
            #endif
            return NANL;
        }
        constexpr inline float number__area_hyperbolic_tangent(short const number) {
            #if cpp__version >= 2011uL
                return ::atanh(number);
            #else
                return number__area_hyperbolic_tangent((float) number);
            #endif
        }
        constexpr inline float number__area_hyperbolic_tangent(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::atanh(number);
            #else
                return number__area_hyperbolic_tangent((float) number);
            #endif
        }
        constexpr inline double number__area_hyperbolic_tangent(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::atanh(number);
            #else
                return number__area_hyperbolic_tangent((double) number);
            #endif
        }
        constexpr inline float number__area_hyperbolic_tangent(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::atanh(number);
            #else
                return number__area_hyperbolic_tangent((float) number);
            #endif
        }
        inline long double number__area_hyperbolic_tangent(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0) return ::atanh((wide::wide_signed_type) number);
                else return ::atanh((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0) return number__area_hyperbolic_tangent((long double) (wide::wide_signed_type) number);
                else return number__area_hyperbolic_tangent((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Ceiling --- CHECKPOINT (Lapys) -> Move one-up the number line.
        constexpr inline double number__ceiling(double const number) noexcept { return ::ceil(number); }
        constexpr inline float number__ceiling(float const number) noexcept {
            #if c__version >= 1990uL
                return ::ceilf(number);
            #elif cpp__version >= 1997uL
                return ::ceil(number);
            #else
                float const integer = number__floor(number);
                return number > integer ? integer + 1.0f : integer;
            #endif
        }
        constexpr inline int number__ceiling(int const number) noexcept {
            #if cpp__version >= 2011uL
                return ::ceil(number);
            #else
                return number;
            #endif
        }
        constexpr inline long number__ceiling(long const number) noexcept {
            #if cpp__version >= 2011uL
                return ::ceil(number);
            #else
                return number;
            #endif
        }
        constexpr inline long double number__ceiling(long double const number) noexcept {
            #if c__version >= 1990uL
                return ::ceill(number);
            #elif cpp__version >= 1997uL
                return ::ceil(number);
            #else
                long double const integer = number__floor(number);
                return number > integer ? integer + 1.00 : integer;
            #endif
        }
        constexpr inline short number__ceiling(short const number) noexcept {
            #if cpp__version >= 2011uL
                return ::ceil(number);
            #else
                return number;
            #endif
        }
        constexpr inline unsigned int number__ceiling(unsigned int const number) noexcept {
            #if cpp__version >= 2011uL
                return ::ceil(number);
            #else
                return number;
            #endif
        }
        constexpr inline unsigned long number__ceiling(unsigned long const number) noexcept {
            #if cpp__version >= 2011uL
                return ::ceil(number);
            #else
                return number;
            #endif
        }
        constexpr inline unsigned short number__ceiling(unsigned short const number) noexcept {
            #if cpp__version >= 2011uL
                return ::ceil(number);
            #else
                return number;
            #endif
        }
        inline wide number__ceiling(wide const number) noexcept {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::ceil((wide::wide_signed_type) number);
                else return ::ceil((wide::wide_unsigned_type) number);
            #else
                return number;
            #endif
        }

        // Cosine
        constexpr inline double number__cosine(double const number) { return ::cos(number); }
        constexpr inline float number__cosine(float const number) {
            #if c__version >= 1990uL
                return ::cosf(number);
            #elif cpp__version >= 1997uL
                return ::cos(number);
            #else
                return number__cosine((double) number);
            #endif
        }
        constexpr inline float number__cosine(int const number) {
            #if cpp__version >= 2011uL
                return ::cos(number);
            #else
                return number__cosine((float) number);
            #endif
        }
        constexpr inline double number__cosine(long const number) {
            #if cpp__version >= 2011uL
                return ::cos(number);
            #else
                return number__cosine((double) number);
            #endif
        }
        inline long double number__cosine(long double const number) {
            #if c__version >= 1990uL
                return ::cosl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
                else return number__arc_tangent((double) number);
            #elif cpp__version >= 1997uL
                return ::cos(number);
            #endif
        }
        constexpr inline float number__cosine(short const number) {
            #if cpp__version >= 2011uL
                return ::cos(number);
            #else
                return number__cosine((float) number);
            #endif
        }
        constexpr inline float number__cosine(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::cos(number);
            #else
                return number__cosine((float) number);
            #endif
        }
        constexpr inline double number__cosine(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::cos(number);
            #else
                return number__cosine((double) number);
            #endif
        }
        constexpr inline float number__cosine(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::cos(number);
            #else
                return number__cosine((float) number);
            #endif
        }
        inline long double number__cosine(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::cos((wide::wide_signed_type) number);
                else return ::cos((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__cosine((long double) (wide::wide_signed_type) number);
                else return number__cosine((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Create Indeterminate
        struct number__create_indeterminate { public:
            constexpr inline number__create_indeterminate(void) {}
            inline operator double(void) const {
                static unsigned long const indeterminateBitRepresentation[2] = {0x00000000, 0xFFF80000}; // NOTE (Lapys) -> IEEE-754 hexadecimal form.
                static double const indeterminate = *((double const*) indeterminateBitRepresentation);

                return indeterminate;
            }
        };

        // Create Negative Infinity
        struct number__create_negative_infinity { public:
            constexpr inline number__create_negative_infinity(void) {}
            inline operator float(void) const noexcept { return -INFINITY; }
        };

        // Create Non-Computable
        struct number__create_non_computable { public:
            constexpr inline number__create_non_computable(void) {}
            inline operator double(void) const noexcept { return NAN; }
            inline operator float(void) const noexcept { return NANF; }
            inline operator long double(void) const noexcept { return NANL; }
        };

        // Create Positive Infinity
        struct number__create_positive_infinity { public:
            constexpr inline number__create_positive_infinity(void) {}
            inline operator float(void) const noexcept { return INFINITY; }
        };

        // Cube Root
        constexpr inline double number__cube_root(double const number) noexcept {
            #if c__version >= 1990uL || cpp__version >= 1998uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.5);
            #endif
        }
        constexpr inline float number__cube_root(float const number) noexcept {
            #if c__version >= 1999uL
                return ::cbrtf(number);
            #elif cpp__version >= 1998uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        constexpr inline int number__cube_root(int const number) noexcept {
            #if cpp__version >= 2011uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        constexpr inline long number__cube_root(long const number) noexcept {
            #if cpp__version >= 2011uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.5);
            #endif
        }
        constexpr inline long double number__cube_root(long double const number) noexcept {
            #if c__version >= 1999uL
                return ::cbrtl(number);
            #elif cpp__version >= 1998uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.50);
            #endif
        }
        constexpr inline short number__cube_root(short const number) noexcept {
            #if cpp__version >= 2011uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        constexpr inline unsigned int number__cube_root(unsigned int const number) noexcept {
            #if cpp__version >= 2011uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        constexpr inline unsigned long number__cube_root(unsigned long const number) noexcept {
            #if cpp__version >= 2011uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.5);
            #endif
        }
        constexpr inline unsigned short number__cube_root(unsigned short const number) noexcept {
            #if cpp__version >= 2011uL
                return ::cbrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        inline wide number__cube_root(wide const number) noexcept {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::cbrt((wide::wide_signed_type) number);
                else return ::cbrt((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((wide::wide_signed_type) number, 0.50);
                else return number__exponentiate((wide::wide_unsigned_type) number, 0.50);
            #endif
        }

        // Exponentiate
        constexpr inline long double number__exponentiate(double const number, double const exponent) { return ::pow(number, exponent); }
        constexpr inline long double number__exponentiate(double const number, float const exponent) {
            #if cpp__version <= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(double const number, int const exponent) { return ::pow(number, exponent); }
        constexpr inline long double number__exponentiate(double const number, long const exponent) {
            #if cpp__version <= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(double const number, long double const exponent) {
            #if cpp__version <= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(double const number, short const exponent) {
            #if cpp__version <= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(double const number, unsigned int const exponent) {
            #if cpp__version <= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(double const number, unsigned long const exponent) {
            #if cpp__version <= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(double const number, unsigned short const exponent) {
            #if cpp__version <= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (double) exponent);
            #endif
        }
        inline long double number__exponentiate(double const number, wide const exponent) {
            #if cpp__version <= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, (double) (wide::wide_signed_type) exponent);
                else return number__exponentiate(number, (double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        constexpr inline double number__exponentiate(float const number, double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline double number__exponentiate(float const number, float const exponent) {
            #if c__version >= 1999uL
                return ::powf(number, exponent);
            #elif cpp__version >= 1998uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline double number__exponentiate(float const number, int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (float) exponent);
            #endif
        }
        constexpr inline double number__exponentiate(float const number, long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(float const number, long double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #elif
                return number__exponentiate((long double) number, exponent);
            #endif
        }
        constexpr inline double number__exponentiate(float const number, short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (float) exponent);
            #endif
        }
        constexpr inline double number__exponentiate(float const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (float) exponent);
            #endif
        }
        constexpr inline double number__exponentiate(float const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline double number__exponentiate(float const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (float) exponent);
            #endif
        }
        inline long double number__exponentiate(float const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) number, (long double) (wide::wide_signed_type) exponent);
                else return number__exponentiate((long double) number, (long double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(int const number, double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline double number__exponentiate(int const number, float const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, exponent);
            #endif
        }
        constexpr inline long number__exponentiate(int const number, int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(int const number, long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(int const number, long double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, exponent);
            #endif
        }
        constexpr inline long number__exponentiate(int const number, short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline long number__exponentiate(int const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline long number__exponentiate(int const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long number__exponentiate(int const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        inline wide number__exponentiate(int const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) number, (long double) (wide::wide_signed_type) exponent);
                else return number__exponentiate((long double) number, (long double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long const number, double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline double number__exponentiate(long const number, float const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(long const number, int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(long const number, long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long const number, long double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(long const number, short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(long const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(long const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(long const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        inline wide number__exponentiate(long const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) number, (long double) (wide::wide_signed_type) exponent);
                else return number__exponentiate((long double) number, (long double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, (long double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, float const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, (long double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, int const exponent) {
            #if cpp__version >= 1998uL
                return ::pow(number, exponent);
            #elif cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, (long double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (long double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, long double const exponent) {
            #if c__version >= 1999uL
                return ::powl(number, exponent);
            #elif cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                if (number > DBL_MAX) return number__exponentiate(number - DBL_MAX, exponent);
                else if (exponent > DBL_MAX) return number__exponentiate(number, exponent - DBL_MAX);
                else return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (long double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (long double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (long double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(long double const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate(number, (long double) exponent);
            #endif
        }
        inline long double number__exponentiate(long double const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (long double) (wide::wide_signed_type) exponent);
                else return ::pow(number, (long double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        constexpr inline double number__exponentiate(short const number, double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline float number__exponentiate(short const number, float const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, exponent);
            #endif
        }
        constexpr inline long number__exponentiate(short const number, int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline long number__exponentiate(short const number, long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(short const number, long double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, exponent);
            #endif
        }
        constexpr inline int number__exponentiate(short const number, short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline long number__exponentiate(short const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline long number__exponentiate(short const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline int number__exponentiate(short const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        inline int number__exponentiate(short const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) number, (long double) (wide::wide_signed_type) exponent);
                else return number__exponentiate((long double) number, (long double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(unsigned int const number, double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline double number__exponentiate(unsigned int const number, float const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, exponent);
            #endif
        }
        constexpr inline long number__exponentiate(unsigned int const number, int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline long number__exponentiate(unsigned int const number, long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(unsigned int const number, long double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, exponent);
            #endif
        }
        constexpr inline long number__exponentiate(unsigned int const number, short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline unsigned long number__exponentiate(unsigned int const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline unsigned long number__exponentiate(unsigned int const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline unsigned long number__exponentiate(unsigned int const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        inline wide number__exponentiate(unsigned int const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) number, (long double) (wide::wide_signed_type) exponent);
                else return number__exponentiate((long double) number, (long double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(unsigned long const number, double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(unsigned long const number, float const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(unsigned long const number, int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(unsigned long const number, long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(unsigned long const number, long double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(unsigned long const number, short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(unsigned long const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(unsigned long const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(unsigned long const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        inline wide number__exponentiate(unsigned long const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) number, (long double) (wide::wide_signed_type) exponent);
                else return number__exponentiate((long double) number, (long double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        constexpr inline double number__exponentiate(unsigned short const number, double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, exponent);
            #endif
        }
        constexpr inline double number__exponentiate(unsigned short const number, float const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, exponent);
            #endif
        }
        constexpr inline long number__exponentiate(unsigned short const number, int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(unsigned short const number, long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline long double number__exponentiate(unsigned short const number, long double const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((long double) number, exponent);
            #endif
        }
        constexpr inline int number__exponentiate(unsigned short const number, short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline unsigned long number__exponentiate(unsigned short const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        constexpr inline wide number__exponentiate(unsigned short const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((double) number, (double) exponent);
            #endif
        }
        constexpr inline unsigned int number__exponentiate(unsigned short const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                return ::pow(number, exponent);
            #else
                return number__exponentiate((float) number, (float) exponent);
            #endif
        }
        inline wide number__exponentiate(unsigned short const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) exponent < 0L) return ::pow(number, (wide::wide_signed_type) exponent);
                else return ::pow(number, (wide::wide_unsigned_type) exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) number, (long double) (wide::wide_signed_type) exponent);
                else return number__exponentiate((long double) number, (long double) (wide::wide_unsigned_type) exponent);
            #endif
        }
        inline long double number__exponentiate(wide const number, double const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline long double number__exponentiate(wide const number, float const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline wide number__exponentiate(wide const number, int const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline wide number__exponentiate(wide const number, long const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline long double number__exponentiate(wide const number, long double const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline wide number__exponentiate(wide const number, short const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline wide number__exponentiate(wide const number, unsigned int const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline wide number__exponentiate(wide const number, unsigned long const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline wide number__exponentiate(wide const number, unsigned short const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::pow((wide::wide_signed_type) number, exponent);
                else return ::pow((wide::wide_unsigned_type) number, exponent);
            #else
                if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, exponent);
                else return number__exponentiate((long double) (wide::wide_unsigned_type) number, exponent);
            #endif
        }
        inline wide number__exponentiate(wide const number, wide const exponent) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) {
                    if ((wide::wide_signed_type) exponent < 0L) return ::pow((wide::wide_signed_type) number, (wide::wide_signed_type) exponent);
                    else return ::pow((wide::wide_signed_type) number, (wide::wide_unsigned_type) exponent);
                }
                else {
                    if ((wide::wide_signed_type) exponent < 0L) return ::pow((wide::wide_unsigned_type) number, (wide::wide_signed_type) exponent);
                    else return ::pow((wide::wide_unsigned_type) number, (wide::wide_unsigned_type) exponent);
                }
            #else
                if ((wide::wide_signed_type) exponent < 0L) {
                    if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) (wide::wide_signed_type) number, (long double) (wide::wide_signed_type) exponent);
                    else return number__exponentiate((long double) (wide::wide_signed_type) number, (long double) (wide::wide_unsigned_type) exponent);
                }
                else {
                    if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate((long double) (wide::wide_unsigned_type) number, (long double) (wide::wide_signed_type) exponent);
                    else return number__exponentiate((long double) (wide::wide_unsigned_type) number, (long double) (wide::wide_unsigned_type) exponent);
                }
            #endif
        }

        // Exponentiate Euler`s Number
        constexpr inline double number__exponentiate_eulers_number(double const number) { return ::exp(number); }
        constexpr inline float number__exponentiate_eulers_number(float const number) {
            #if c__version >= 1990uL
                return ::expf(number);
            #elif cpp__version >= 1997uL
                return ::exp(number);
            #else
                return number__exponentiate_eulers_number((double) number);
            #endif
        }
        constexpr inline float number__exponentiate_eulers_number(int const number) {
            #if cpp__version >= 2011uL
                return ::exp(number);
            #else
                return number__exponentiate_eulers_number((float) number);
            #endif
        }
        inline long double number__exponentiate_eulers_number(long const number) {
            #if cpp__version >= 2011uL
                return ::exp(number);
            #else
                return number__exponentiate_eulers_number((long double) number);
            #endif
        }
        inline long double number__exponentiate_eulers_number(long double const number) {
            #if c__version >= 1990uL
                return ::expl(number);
            #elif cpp__version >= 1997uL
                return ::exp(number);
            #else
                if (number > DBL_MAX) return number__exponentiate_eulers_number(number - DBL_MAX);
                else return number__exponentiate_eulers_number((double) number);
            #endif
        }
        constexpr inline float number__exponentiate_eulers_number(short const number) {
            #if cpp__version >= 2011uL
                return ::exp(number);
            #else
                return number__exponentiate_eulers_number((float) number);
            #endif
        }
        constexpr inline float number__exponentiate_eulers_number(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::exp(number);
            #else
                return number__exponentiate_eulers_number((float) number);
            #endif
        }
        inline long double number__exponentiate_eulers_number(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::exp(number);
            #else
                return number__exponentiate_eulers_number((long double) number);
            #endif
        }
        constexpr inline float number__exponentiate_eulers_number(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::exp(number);
            #else
                return number__exponentiate_eulers_number((float) number);
            #endif
        }
        inline long double number__exponentiate_eulers_number(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::exp((wide::wide_signed_type) number);
                else return ::exp((wide::wide_unsigned_type) number);
            #else
                return number__exponentiate_eulers_number((long double) number);
            #endif
        }

        // Floor --- CHECKPOINT (Lapys) -> Move one-down the number line.
        inline double number__floor(double const number) noexcept {
            #if c__version >= 1990uL
                return ::floorf(number);
            #elif cpp__version >= 1997uL
                return ::floor(number);
            #else
            #endif
        }
        inline float number__floor(float const number) noexcept {
            #if c__version >= 1990uL
                return ::floorf(number);
            #elif cpp__version >= 1997uL
                return ::floor(number);
            #else
            #endif
        }
        constexpr inline int number__floor(int const number) noexcept { return number; }
        constexpr inline long number__floor(long const number) noexcept { return number; }
        inline long double number__floor(long double const number) noexcept {
            #if c__version >= 1990uL
                return ::floorl(number);
            #elif cpp__version >= 1997uL
                return ::floor(number);
            #else
            #endif
        }
        constexpr inline short number__floor(short const number) noexcept { return number; }
        constexpr inline unsigned int number__floor(unsigned int const number) noexcept { return number; }
        constexpr inline unsigned long number__floor(unsigned long const number) noexcept { return number; }
        constexpr inline unsigned short number__floor(unsigned short const number) noexcept { return number; }
        constexpr inline wide number__floor(wide const number) noexcept { return number; }

        // Hyperbolic Cosine
        constexpr inline double number__hyperbolic_cosine(double const number) { return ::cosh(number); }
        constexpr inline float number__hyperbolic_cosine(float const number) {
            #if c__version >= 1990uL
                return ::coshf(number);
            #elif cpp__version >= 1997uL
                return ::cosh(number);
            #else
                return number__hyperbolic_cosine((double) number);
            #endif
        }
        constexpr inline float number__hyperbolic_cosine(int const number) {
            #if cpp__version >= 2011uL
                return ::cosh(number);
            #else
                return number__hyperbolic_cosine((float) number);
            #endif
        }
        constexpr inline double number__hyperbolic_cosine(long const number) {
            #if cpp__version >= 2011uL
                return ::cosh(number);
            #else
                return number__hyperbolic_cosine((double) number);
            #endif
        }
        inline long double number__hyperbolic_cosine(long double const number) {
            #if c__version >= 1990uL
                return ::coshl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
                else return number__arc_tangent((double) number);
            #elif cpp__version >= 1997uL
                return ::cosh(number);
            #endif
        }
        constexpr inline float number__hyperbolic_cosine(short const number) {
            #if cpp__version >= 2011uL
                return ::cosh(number);
            #else
                return number__hyperbolic_cosine((float) number);
            #endif
        }
        constexpr inline float number__hyperbolic_cosine(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::cosh(number);
            #else
                return number__hyperbolic_cosine((float) number);
            #endif
        }
        constexpr inline double number__hyperbolic_cosine(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::cosh(number);
            #else
                return number__hyperbolic_cosine((double) number);
            #endif
        }
        constexpr inline float number__hyperbolic_cosine(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::cosh(number);
            #else
                return number__hyperbolic_cosine((float) number);
            #endif
        }
        inline long double number__hyperbolic_cosine(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::cosh((wide::wide_signed_type) number);
                else return ::cosh((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__hyperbolic_cosine((long double) (wide::wide_signed_type) number);
                else return number__hyperbolic_cosine((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Hyperbolic Sine
        constexpr inline double number__hyperbolic_sine(double const number) { return ::sinh(number); }
        constexpr inline float number__hyperbolic_sine(float const number) {
            #if c__version >= 1990uL
                return ::sinhf(number);
            #elif cpp__version >= 1997uL
                return ::sinh(number);
            #else
                return number__hyperbolic_sine((double) number);
            #endif
        }
        constexpr inline float number__hyperbolic_sine(int const number) {
            #if cpp__version >= 2011uL
                return ::sinh(number);
            #else
                return number__hyperbolic_sine((float) number);
            #endif
        }
        constexpr inline double number__hyperbolic_sine(long const number) {
            #if cpp__version >= 2011uL
                return ::sinh(number);
            #else
                return number__hyperbolic_sine((double) number);
            #endif
        }
        inline long double number__hyperbolic_sine(long double const number) {
            #if c__version >= 1990uL
                return ::sinhl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
                else return number__arc_tangent((double) number);
            #elif cpp__version >= 1997uL
                return ::sinh(number);
            #endif
        }
        constexpr inline float number__hyperbolic_sine(short const number) {
            #if cpp__version >= 2011uL
                return ::sinh(number);
            #else
                return number__hyperbolic_sine((float) number);
            #endif
        }
        constexpr inline float number__hyperbolic_sine(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::sinh(number);
            #else
                return number__hyperbolic_sine((float) number);
            #endif
        }
        constexpr inline double number__hyperbolic_sine(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::sinh(number);
            #else
                return number__hyperbolic_sine((double) number);
            #endif
        }
        constexpr inline float number__hyperbolic_sine(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::sinh(number);
            #else
                return number__hyperbolic_sine((float) number);
            #endif
        }
        inline long double number__hyperbolic_sine(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::sinh((wide::wide_signed_type) number);
                else return ::sinh((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__hyperbolic_sine((long double) (wide::wide_signed_type) number);
                else return number__hyperbolic_sine((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Hyperbolic Tangent
        constexpr inline double number__hyperbolic_tangent(double const number) { return ::tanh(number); }
        constexpr inline float number__hyperbolic_tangent(float const number) {
            #if c__version >= 1990uL
                return ::tanhf(number);
            #elif cpp__version >= 1997uL
                return ::tanh(number);
            #else
                return number__hyperbolic_tangent((double) number);
            #endif
        }
        constexpr inline float number__hyperbolic_tangent(int const number) {
            #if cpp__version >= 2011uL
                return ::tanh(number);
            #else
                return number__hyperbolic_tangent((float) number);
            #endif
        }
        constexpr inline double number__hyperbolic_tangent(long const number) {
            #if cpp__version >= 2011uL
                return ::tanh(number);
            #else
                return number__hyperbolic_tangent((double) number);
            #endif
        }
        inline long double number__hyperbolic_tangent(long double const number) {
            #if c__version >= 1990uL
                return ::tanhl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
                else return number__arc_tangent((double) number);
            #elif cpp__version >= 1997uL
                return ::tanh(number);
            #endif
        }
        constexpr inline float number__hyperbolic_tangent(short const number) {
            #if cpp__version >= 2011uL
                return ::tanh(number);
            #else
                return number__hyperbolic_tangent((float) number);
            #endif
        }
        constexpr inline float number__hyperbolic_tangent(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::tanh(number);
            #else
                return number__hyperbolic_tangent((float) number);
            #endif
        }
        constexpr inline double number__hyperbolic_tangent(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::tanh(number);
            #else
                return number__hyperbolic_tangent((double) number);
            #endif
        }
        constexpr inline float number__hyperbolic_tangent(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::tanh(number);
            #else
                return number__hyperbolic_tangent((float) number);
            #endif
        }
        inline long double number__hyperbolic_tangent(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::tanh((wide::wide_signed_type) number);
                else return ::tanh((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__hyperbolic_tangent((long double) (wide::wide_signed_type) number);
                else return number__hyperbolic_tangent((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Is Approximate Equal --- CHECKPOINT (Lapys)
        inline bool number__is_approximate_equal(double const numberA, double const numberB, double const tolerance = DBL_EPSILON) noexcept { double const difference = number__absolute(numberA - numberB); return difference <= tolerance || difference < number__maximum(number__absolute(numberA), number__absolute(numberB)) * tolerance; }

        // Is Approximate Zero
        inline bool number__is_approximate_zero(double const number, double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, float const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, long double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, unsigned int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, unsigned long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, unsigned short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(double const number, wide const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, float const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, long double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, unsigned int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, unsigned long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, unsigned short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(float const number, wide const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        constexpr inline bool number__is_approximate_zero(int const number, double const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, float const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, int const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, long const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, long double const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, short const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, unsigned int const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, unsigned long const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, unsigned short const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(int const number, wide const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, double const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, float const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, int const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, long const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, long double const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, short const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, unsigned int const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, unsigned long const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, unsigned short const) noexcept { return 0L == number; }
        constexpr inline bool number__is_approximate_zero(long const number, wide const) noexcept { return 0L == number; }
        inline bool number__is_approximate_zero(long double const number, double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, float const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, long double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, unsigned int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, unsigned long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, unsigned short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        inline bool number__is_approximate_zero(long double const number, wide const tolerance) noexcept { return number__absolute(number) <= tolerance; }
        constexpr inline bool number__is_approximate_zero(short const number, double const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, float const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, int const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, long const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, long double const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, short const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, unsigned int const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, unsigned long const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, unsigned short const) noexcept { return 0 == number; }
        constexpr inline bool number__is_approximate_zero(short const number, wide const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, double const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, float const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, int const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, long const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, long double const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, short const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, unsigned int const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, unsigned long const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, unsigned short const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned int const number, wide const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, double const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, float const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, int const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, long const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, long double const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, short const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, unsigned int const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, unsigned long const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, unsigned short const) noexcept { return 0uL == number; }
        constexpr inline bool number__is_approximate_zero(unsigned long const number, wide const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, double const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, float const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, int const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, long const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, long double const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, short const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, unsigned int const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, unsigned long const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, unsigned short const) noexcept { return 0u == number; }
        constexpr inline bool number__is_approximate_zero(unsigned short const number, wide const) noexcept { return 0u == number; }
        inline bool number__is_approximate_zero(wide const number, double const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, float const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, int const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, long const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, long double const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, short const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, unsigned int const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, unsigned long const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, unsigned short const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }
        inline bool number__is_approximate_zero(wide const number, wide const) noexcept { return 0L == (wide::wide_signed_type) number && 0uL == (wide::wide_unsigned_type) number; }

        // Is Computable --- NOTE (Lapys) -> Is not `NaN`.
        constexpr inline bool number__is_computable(double const number) noexcept {
            #if cpp__version >= 2011uL
                return false == ::isnan(number);
            #else
                return false == isnan(number);
            #endif
        }
        constexpr inline bool number__is_computable(float const number) noexcept {
            #if cpp__version >= 2011uL
                return false == ::isnan(number);
            #else
                return false == isnan(number);
            #endif
        }
        constexpr inline bool number__is_computable(int const) noexcept { return true; }
        constexpr inline bool number__is_computable(long const) noexcept { return true; }
        constexpr inline bool number__is_computable(long double const number) noexcept {
            #if cpp__version >= 2011uL
                return false == ::isnan(number);
            #else
                return false == isnan(number);
            #endif
        }
        constexpr inline bool number__is_computable(short const) noexcept { return true; }
        constexpr inline bool number__is_computable(unsigned int const) noexcept { return true; }
        constexpr inline bool number__is_computable(unsigned long const) noexcept { return true; }
        constexpr inline bool number__is_computable(unsigned short const) noexcept { return true; }
        constexpr inline bool number__is_computable(wide const) noexcept { return true; }

        // Is Determinate
        inline bool number__is_determinate(double const number) noexcept { return number == number && number != (double) number__create_indeterminate(); }
        inline bool number__is_determinate(float const number) noexcept { return number__is_determinate((double) number); }
        constexpr inline bool number__is_determinate(int const) noexcept { return true; }
        constexpr inline bool number__is_determinate(long const) noexcept { return true; }
        inline bool number__is_determinate(long double const number) noexcept { if (number > DBL_MAX) return number__is_determinate(number - DBL_MAX); else return number__is_determinate((double) number); }
        constexpr inline bool number__is_determinate(short const) noexcept { return true; }
        constexpr inline bool number__is_determinate(unsigned int const) noexcept { return true; }
        constexpr inline bool number__is_determinate(unsigned long const) noexcept { return true; }
        constexpr inline bool number__is_determinate(unsigned short const) noexcept { return true; }
        constexpr inline bool number__is_determinate(wide const) noexcept { return true; }

        // Is Finite
        inline bool number__is_finite(double const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isfinite(number);
            #else
                return isfinite(number);
            #endif
        }
        inline bool number__is_finite(float const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isfinite(number);
            #else
                return isfinite(number);
            #endif
        }
        constexpr inline bool number__is_finite(int const) noexcept { return true; }
        constexpr inline bool number__is_finite(long const) noexcept { return true; }
        inline bool number__is_finite(long double const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isfinite(number);
            #else
                return isfinite(number);
            #endif
        }
        constexpr inline bool number__is_finite(short const) noexcept { return true; }
        constexpr inline bool number__is_finite(unsigned int const) noexcept { return true; }
        constexpr inline bool number__is_finite(unsigned long const) noexcept { return true; }
        constexpr inline bool number__is_finite(unsigned short const) noexcept { return true; }
        constexpr inline bool number__is_finite(wide const) noexcept { return true; }

        // Is Infinite --- NOTE (Lapys) -> Defined only because `isinf` is a standard-defined function.
        constexpr inline bool number__is_infinite(double const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isinf(number);
            #else
                return isinf(number);
            #endif
        }
        constexpr inline bool number__is_infinite(float const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isinf(number);
            #else
                return isinf(number);
            #endif
        }
        constexpr inline bool number__is_infinite(int const) noexcept { return false; }
        constexpr inline bool number__is_infinite(long const) noexcept { return false; }
        constexpr inline bool number__is_infinite(long double const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isinf(number);
            #else
                return isinf(number);
            #endif
        }
        constexpr inline bool number__is_infinite(short const) noexcept { return false; }
        constexpr inline bool number__is_infinite(unsigned int const) noexcept { return false; }
        constexpr inline bool number__is_infinite(unsigned long const) noexcept { return false; }
        constexpr inline bool number__is_infinite(unsigned short const) noexcept { return false; }
        constexpr inline bool number__is_infinite(wide const) noexcept { return false; }

        // Is Lesser Than --- CHECKPOINT (Lapys)
        inline bool number__is_lesser_than(long double const number, long double const comparison) noexcept { long double const difference = number - comparison; return difference < LDBL_EPSILON || difference < ::fmax(::fabs(number), ::fabs(comparison)) * LDBL_EPSILON; }

        // Is Greater Than --- CHECKPOINT (Lapys)
        inline bool number__is_greater_than(long double const number, long double const comparison) noexcept { long double const difference = number - comparison; return difference > LDBL_EPSILON || difference > ::fmax(::fabs(number), ::fabs(comparison)) * LDBL_EPSILON; }

        // Is Normalized
        inline bool number__is_normalized(double const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isnormal(number);
            #else
                return isnormal(number);
            #endif
        }
        inline bool number__is_normalized(float const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isnormal(number);
            #else
                return isnormal(number);
            #endif
        }
        constexpr inline bool number__is_normalized(int const) noexcept { return true; }
        constexpr inline bool number__is_normalized(long const) noexcept { return true; }
        inline bool number__is_normalized(long double const number) noexcept {
            #if cpp__version >= 2011uL
                return ::isnormal(number);
            #else
                return isnormal(number);
            #endif
        }
        constexpr inline bool number__is_normalized(short const) noexcept { return true; }
        constexpr inline bool number__is_normalized(unsigned int const) noexcept { return true; }
        constexpr inline bool number__is_normalized(unsigned long const) noexcept { return true; }
        constexpr inline bool number__is_normalized(unsigned short const) noexcept { return true; }
        constexpr inline bool number__is_normalized(wide const) noexcept { return true; }

        // Is Safe --- NOTE (Lapys) -> Is computable, determinate, finite and normalized.
        inline bool number__is_safe(double const number) noexcept { return number__is_computable(number) && number__is_determinate(number) && number__is_finite(number) && number__is_normalized(number); }
        inline bool number__is_safe(float const number) noexcept { return number__is_computable(number) && number__is_determinate(number) && number__is_finite(number) && number__is_normalized(number); }
        inline bool number__is_safe(int const number) noexcept { return INT_MAX ^ number; }
        inline bool number__is_safe(long const number) noexcept { return LONG_MAX ^ number; }
        inline bool number__is_safe(long double const number) noexcept { return number__is_computable(number) && number__is_determinate(number) && number__is_finite(number) && number__is_normalized(number); }
        inline bool number__is_safe(short const number) noexcept { return SHRT_MAX ^ number; }
        inline bool number__is_safe(unsigned int const number) noexcept { return UINT_MAX ^ number; }
        inline bool number__is_safe(unsigned long const number) noexcept { return ULONG_MAX ^ number; }
        inline bool number__is_safe(unsigned short const) noexcept { return true; } // FLAG (Lapys) -> This is safe, right? Yeah, let`s ignore `USHRT_MAX`...
        inline bool number__is_safe(wide const number) noexcept {
            #if cpp__version >= 2011uL
                return (LLONG_MAX ^ (wide::wide_signed_type) number) && (ULLONG_MAX ^ (wide::wide_unsigned_type) number);
            #else
                return true;
            #endif
        }

        // Logarithm --- NOTE (Lapys) -> Compute natural logarithm.
        constexpr inline double number__logarithm(double const number) { return ::log(number); }
        constexpr inline float number__logarithm(float const number) {
            #if c__version <= 1999uL
                return ::logf(number);
            #elif cpp__version >= 1997uL
                return ::log(number);
            #endif
        }
        constexpr inline float number__logarithm(int const number) {
            #if cpp__version >= 2011uL
                return ::log(number);
            #else
                return number__logarithm((float) number);
            #endif
        }
        constexpr inline double number__logarithm(long const number) {
            #if cpp__version >= 2011uL
                return ::log(number);
            #else
                return number__logarithm((double) number);
            #endif
        }
        constexpr inline long double number__logarithm(long double const number) {
            #if c__version <= 1999uL
                return ::logl(number);
            #elif cpp__version >= 1997uL
                return ::log(number);
            #endif
        }
        constexpr inline float number__logarithm(short const number) {
            #if cpp__version >= 2011uL
                return ::log(number);
            #else
                return number__logarithm((float) number);
            #endif
        }
        constexpr inline float number__logarithm(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::log(number);
            #else
                return number__logarithm((float) number);
            #endif
        }
        constexpr inline double number__logarithm(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::log(number);
            #else
                return number__logarithm((double) number);
            #endif
        }
        constexpr inline float number__logarithm(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::log(number);
            #else
                return number__logarithm((float) number);
            #endif
        }
        inline long double number__logarithm(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::log((wide::wide_signed_type) number);
                else return ::log((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__logarithm((long double) (wide::wide_signed_type) number);
                else return number__logarithm((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Maximum --- CHECKPOINT (Lapys) -> `fmax` and `max` functions.
        constexpr inline double number__maximum(double const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(double const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(double const numberA, int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(double const numberA, long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(double const numberA, long double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(double const numberA, short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(double const numberA, unsigned int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(double const numberA, unsigned long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(double const numberA, unsigned short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        inline long double number__maximum(double const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA > (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__maximum(float const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(float const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(float const numberA, int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(float const numberA, long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(float const numberA, long double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(float const numberA, short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(float const numberA, unsigned int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(float const numberA, unsigned long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(float const numberA, unsigned short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        inline long double number__maximum(float const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA > (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__maximum(int const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(int const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline int number__maximum(int const numberA, int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(int const numberA, long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(int const numberA, long double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline int number__maximum(int const numberA, short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(int const numberA, unsigned int const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned int) numberA > numberB ? numberA : numberB); }
        constexpr inline double number__maximum(int const numberA, unsigned long const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned int) numberA > numberB ? numberA : numberB); }
        constexpr inline long number__maximum(int const numberA, unsigned short const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned int) numberA > numberB ? numberA : numberB); }
        inline wide number__maximum(int const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA > (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < 0 ? (wide::wide_unsigned_type) numberB : ((unsigned int) numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB);
        }
        constexpr inline double number__maximum(long const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(long const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(long const numberA, int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(long const numberA, long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long const numberA, long double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(long const numberA, short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(long const numberA, unsigned int const numberB) noexcept { return numberA < 0L ? numberB : ((unsigned long) numberA > numberB ? numberA : numberB); }
        constexpr inline double number__maximum(long const numberA, unsigned long const numberB) noexcept { return numberA < 0L ? numberB : ((unsigned long) numberA > numberB ? numberA : numberB); }
        constexpr inline double number__maximum(long const numberA, unsigned short const numberB) noexcept { return numberA < 0L ? numberB : ((unsigned long) numberA > numberB ? numberA : numberB); }
        inline long double number__maximum(long const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA > (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < 0 ? (wide::wide_unsigned_type) numberB : ((unsigned long) numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB);
        }
        constexpr inline long double number__maximum(long double const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long double const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long double const numberA, int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long double const numberA, long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long double const numberA, long double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long double const numberA, short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long double const numberA, unsigned int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long double const numberA, unsigned long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(long double const numberA, unsigned short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        inline long double number__maximum(long double const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA > (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__maximum(short const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(short const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline int number__maximum(short const numberA, int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(short const numberA, long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long double number__maximum(short const numberA, long double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline short number__maximum(short const numberA, short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(short const numberA, unsigned int const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned short) numberA > numberB ? numberA : numberB); }
        constexpr inline double number__maximum(short const numberA, unsigned long const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned short) numberA > numberB ? numberA : numberB); }
        constexpr inline int number__maximum(short const numberA, unsigned short const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned short) numberA > numberB ? numberA : numberB); }
        inline long double number__maximum(short const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA > (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < 0 ? (wide::wide_unsigned_type) numberB : ((unsigned short) numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB);
        }
        constexpr inline double number__maximum(unsigned int const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(unsigned int const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(unsigned int const numberA, int const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned int) numberB ? numberA : numberB); }
        constexpr inline long number__maximum(unsigned int const numberA, long const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned int) numberB ? numberA : numberB); }
        constexpr inline long double number__maximum(unsigned int const numberA, long double const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned int) numberB ? numberA : numberB); }
        constexpr inline long number__maximum(unsigned int const numberA, short const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned int) numberB ? numberA : numberB); }
        constexpr inline unsigned int number__maximum(unsigned int const numberA, unsigned int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline unsigned long number__maximum(unsigned int const numberA, unsigned long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline unsigned int number__maximum(unsigned int const numberA, unsigned short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        inline wide number__maximum(unsigned int const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return (wide::wide_signed_type) numberB < 0L ? numberA : (numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_signed_type) numberB);
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__maximum(unsigned long const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(unsigned long const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(unsigned long const numberA, int const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned long) numberB ? numberA : numberB); }
        constexpr inline double number__maximum(unsigned long const numberA, long const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned long) numberB ? numberA : numberB); }
        constexpr inline long double number__maximum(unsigned long const numberA, long double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline double number__maximum(unsigned long const numberA, short const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned long) numberB ? numberA : numberB); }
        constexpr inline double number__maximum(unsigned long const numberA, unsigned int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline unsigned long number__maximum(unsigned long const numberA, unsigned long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline unsigned long number__maximum(unsigned long const numberA, unsigned short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        inline wide number__maximum(unsigned long const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return (wide::wide_signed_type) numberB < 0L ? numberA : (numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_signed_type) numberB);
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__maximum(unsigned short const numberA, double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline float number__maximum(unsigned short const numberA, float const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline long number__maximum(unsigned short const numberA, int const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned short) numberB ? numberA : numberB); }
        constexpr inline long number__maximum(unsigned short const numberA, long const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned short) numberB ? numberA : numberB); }
        constexpr inline long double number__maximum(unsigned short const numberA, long double const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline int number__maximum(unsigned short const numberA, short const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned short) numberB ? numberA : numberB); }
        constexpr inline unsigned int number__maximum(unsigned short const numberA, unsigned int const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline unsigned long number__maximum(unsigned short const numberA, unsigned long const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        constexpr inline unsigned short number__maximum(unsigned short const numberA, unsigned short const numberB) noexcept { return numberA > numberB ? numberA : numberB; }
        inline wide number__maximum(unsigned short const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return (wide::wide_signed_type) numberB < 0L ? numberA : (numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_signed_type) numberB);
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        inline long double number__maximum(wide const numberA, double const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) > numberB ? (wide::wide_signed_type) numberA : numberB;
            else return ((wide::wide_unsigned_type) numberA) > numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline long double number__maximum(wide const numberA, float const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) > numberB ? (wide::wide_signed_type) numberA : numberB;
            else return ((wide::wide_unsigned_type) numberA) > numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__maximum(wide const numberA, int const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) > numberB ? (wide::wide_signed_type) numberA : numberB;
            else if (numberB < 0) return numberA;
            else return ((wide::wide_unsigned_type) numberA) > (unsigned int) numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__maximum(wide const numberA, long const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) > numberB ? (wide::wide_signed_type) numberA : numberB;
            else if (numberB < 0L) return numberA;
            else return ((wide::wide_unsigned_type) numberA) > (unsigned int) numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline long double number__maximum(wide const numberA, long double const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) > numberB ? (wide::wide_signed_type) numberA : numberB;
            else return ((wide::wide_unsigned_type) numberA) > numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__maximum(wide const numberA, short const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) > numberB ? (wide::wide_signed_type) numberA : numberB;
            else if (numberB < 0) return numberA;
            else return ((wide::wide_unsigned_type) numberA) > (unsigned int) numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__maximum(wide const numberA, unsigned int const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return numberB;
            else return ((wide::wide_unsigned_type) numberA) > numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__maximum(wide const numberA, unsigned long const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return numberB;
            else return ((wide::wide_unsigned_type) numberA) > numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__maximum(wide const numberA, unsigned short const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return numberB;
            else return ((wide::wide_unsigned_type) numberA) > numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__maximum(wide const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) {
                if ((wide::wide_signed_type) numberB < 0L) return (wide::wide_signed_type) numberA > (wide::wide_signed_type) numberB ? numberA : numberB;
                else return numberB;
            }

            else {
                if ((wide::wide_signed_type) numberB < 0L) return numberA;
                else return (wide::wide_unsigned_type) numberA > (wide::wide_unsigned_type) numberB ? numberA : numberB;
            }
        }

        // Minimum --- CHECKPOINT (Lapys) -> `fmin` and `min` functions.
        constexpr inline double number__minimum(double const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(double const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(double const numberA, int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(double const numberA, long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(double const numberA, long double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(double const numberA, short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(double const numberA, unsigned int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(double const numberA, unsigned long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(double const numberA, unsigned short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        inline long double number__minimum(double const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA < (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__minimum(float const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(float const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(float const numberA, int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(float const numberA, long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(float const numberA, long double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(float const numberA, short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(float const numberA, unsigned int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(float const numberA, unsigned long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(float const numberA, unsigned short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        inline long double number__minimum(float const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA < (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__minimum(int const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(int const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline int number__minimum(int const numberA, int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(int const numberA, long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(int const numberA, long double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline int number__minimum(int const numberA, short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(int const numberA, unsigned int const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned int) numberA < numberB ? numberA : numberB); }
        constexpr inline double number__minimum(int const numberA, unsigned long const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned int) numberA < numberB ? numberA : numberB); }
        constexpr inline long number__minimum(int const numberA, unsigned short const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned int) numberA < numberB ? numberA : numberB); }
        inline wide number__minimum(int const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA < (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < 0 ? (wide::wide_unsigned_type) numberB : ((unsigned int) numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB);
        }
        constexpr inline double number__minimum(long const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(long const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(long const numberA, int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(long const numberA, long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long const numberA, long double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(long const numberA, short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(long const numberA, unsigned int const numberB) noexcept { return numberA < 0L ? numberB : ((unsigned long) numberA < numberB ? numberA : numberB); }
        constexpr inline double number__minimum(long const numberA, unsigned long const numberB) noexcept { return numberA < 0L ? numberB : ((unsigned long) numberA < numberB ? numberA : numberB); }
        constexpr inline double number__minimum(long const numberA, unsigned short const numberB) noexcept { return numberA < 0L ? numberB : ((unsigned long) numberA < numberB ? numberA : numberB); }
        inline long double number__minimum(long const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA < (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < 0 ? (wide::wide_unsigned_type) numberB : ((unsigned long) numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB);
        }
        constexpr inline long double number__minimum(long double const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long double const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long double const numberA, int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long double const numberA, long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long double const numberA, long double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long double const numberA, short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long double const numberA, unsigned int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long double const numberA, unsigned long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(long double const numberA, unsigned short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        inline long double number__minimum(long double const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA < (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__minimum(short const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(short const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline int number__minimum(short const numberA, int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(short const numberA, long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long double number__minimum(short const numberA, long double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline short number__minimum(short const numberA, short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(short const numberA, unsigned int const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned short) numberA < numberB ? numberA : numberB); }
        constexpr inline double number__minimum(short const numberA, unsigned long const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned short) numberA < numberB ? numberA : numberB); }
        constexpr inline int number__minimum(short const numberA, unsigned short const numberB) noexcept { return numberA < 0 ? numberB : ((unsigned short) numberA < numberB ? numberA : numberB); }
        inline long double number__minimum(short const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return numberA < (wide::wide_signed_type) numberB ? numberA : (wide::wide_signed_type) numberB;
            else return numberA < 0 ? (wide::wide_unsigned_type) numberB : ((unsigned short) numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB);
        }
        constexpr inline double number__minimum(unsigned int const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(unsigned int const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(unsigned int const numberA, int const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned int) numberB ? numberA : numberB); }
        constexpr inline long number__minimum(unsigned int const numberA, long const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned int) numberB ? numberA : numberB); }
        constexpr inline long double number__minimum(unsigned int const numberA, long double const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned int) numberB ? numberA : numberB); }
        constexpr inline long number__minimum(unsigned int const numberA, short const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned int) numberB ? numberA : numberB); }
        constexpr inline unsigned int number__minimum(unsigned int const numberA, unsigned int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline unsigned long number__minimum(unsigned int const numberA, unsigned long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline unsigned int number__minimum(unsigned int const numberA, unsigned short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        inline wide number__minimum(unsigned int const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return (wide::wide_signed_type) numberB < 0L ? numberA : (numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_signed_type) numberB);
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__minimum(unsigned long const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(unsigned long const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(unsigned long const numberA, int const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned long) numberB ? numberA : numberB); }
        constexpr inline double number__minimum(unsigned long const numberA, long const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned long) numberB ? numberA : numberB); }
        constexpr inline long double number__minimum(unsigned long const numberA, long double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline double number__minimum(unsigned long const numberA, short const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned long) numberB ? numberA : numberB); }
        constexpr inline double number__minimum(unsigned long const numberA, unsigned int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline unsigned long number__minimum(unsigned long const numberA, unsigned long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline unsigned long number__minimum(unsigned long const numberA, unsigned short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        inline wide number__minimum(unsigned long const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return (wide::wide_signed_type) numberB < 0L ? numberA : (numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_signed_type) numberB);
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        constexpr inline double number__minimum(unsigned short const numberA, double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline float number__minimum(unsigned short const numberA, float const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline long number__minimum(unsigned short const numberA, int const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned short) numberB ? numberA : numberB); }
        constexpr inline long number__minimum(unsigned short const numberA, long const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned short) numberB ? numberA : numberB); }
        constexpr inline long double number__minimum(unsigned short const numberA, long double const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline int number__minimum(unsigned short const numberA, short const numberB) noexcept { return numberB < 0 ? numberA : (numberA > (unsigned short) numberB ? numberA : numberB); }
        constexpr inline unsigned int number__minimum(unsigned short const numberA, unsigned int const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline unsigned long number__minimum(unsigned short const numberA, unsigned long const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        constexpr inline unsigned short number__minimum(unsigned short const numberA, unsigned short const numberB) noexcept { return numberA < numberB ? numberA : numberB; }
        inline wide number__minimum(unsigned short const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberB < 0L) return (wide::wide_signed_type) numberB < 0L ? numberA : (numberA > (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_signed_type) numberB);
            else return numberA < (wide::wide_unsigned_type) numberB ? numberA : (wide::wide_unsigned_type) numberB;
        }
        inline long double number__minimum(wide const numberA, double const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) < numberB ? (wide::wide_signed_type) numberA : numberB;
            else return ((wide::wide_unsigned_type) numberA) < numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline long double number__minimum(wide const numberA, float const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) < numberB ? (wide::wide_signed_type) numberA : numberB;
            else return ((wide::wide_unsigned_type) numberA) < numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__minimum(wide const numberA, int const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) < numberB ? (wide::wide_signed_type) numberA : numberB;
            else if (numberB < 0) return numberA;
            else return ((wide::wide_unsigned_type) numberA) < (unsigned int) numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__minimum(wide const numberA, long const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) < numberB ? (wide::wide_signed_type) numberA : numberB;
            else if (numberB < 0L) return numberA;
            else return ((wide::wide_unsigned_type) numberA) < (unsigned int) numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline long double number__minimum(wide const numberA, long double const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) < numberB ? (wide::wide_signed_type) numberA : numberB;
            else return ((wide::wide_unsigned_type) numberA) < numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__minimum(wide const numberA, short const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return ((wide::wide_signed_type) numberA) < numberB ? (wide::wide_signed_type) numberA : numberB;
            else if (numberB < 0) return numberA;
            else return ((wide::wide_unsigned_type) numberA) < (unsigned int) numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__minimum(wide const numberA, unsigned int const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return numberB;
            else return ((wide::wide_unsigned_type) numberA) < numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__minimum(wide const numberA, unsigned long const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return numberB;
            else return ((wide::wide_unsigned_type) numberA) < numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__minimum(wide const numberA, unsigned short const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) return numberB;
            else return ((wide::wide_unsigned_type) numberA) < numberB ? (wide::wide_unsigned_type) numberA : numberB;
        }
        inline wide number__minimum(wide const numberA, wide const numberB) noexcept {
            if ((wide::wide_signed_type) numberA < 0L) {
                if ((wide::wide_signed_type) numberB < 0L) return (wide::wide_signed_type) numberA < (wide::wide_signed_type) numberB ? numberA : numberB;
                else return numberB;
            }

            else {
                if ((wide::wide_signed_type) numberB < 0L) return numberA;
                else return (wide::wide_unsigned_type) numberA > (wide::wide_unsigned_type) numberB ? numberA : numberB;
            }
        }

        // Modulus --- CHECKPOINT (Lapys)
        inline double number__modulus(double const number, double const denominator) noexcept { ::fmod(number, denominator); }

        // Random
        inline int number__random(void) noexcept { return ::rand(); }

        // Round --- CHECKPOINT (Lapys) -> Update this...
        constexpr inline double number__round(double const number) noexcept { return ::round(number); }
        constexpr inline float number__round(float const number) noexcept {
            #if cpp__version >= 2011uL
                return ::round(number);
            #elif c__version >= 1999uL
                return ::roundf(number);
            #else
                float const integer = number__floor(number);
                return number - integer >= 0.5f ? integer + 1.0f : integer;
            #endif
        }
        constexpr inline int number__round(int const number) noexcept { return number; }
        constexpr inline long number__round(long const number) noexcept { return number; }
        constexpr inline long double number__round(long double const number) noexcept {
            #if cpp__version >= 2011uL
                return ::round(number);
            #elif c__version >= 1999uL
                return ::roundl(number);
            #else
                long double const integer = number__floor(number);
                return number - integer >= 0.50 ? integer + 1.00 : integer;
            #endif
        }
        constexpr inline short number__round(short const number) noexcept { return number; }
        constexpr inline unsigned int number__round(unsigned int const number) noexcept { return number; }
        constexpr inline unsigned long number__round(unsigned long const number) noexcept { return number; }
        constexpr inline unsigned short number__round(unsigned short const number) noexcept { return number; }
        inline wide number__round(wide const number) noexcept { return number; }

        // Root
        inline long double number__root(double const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline long double number__root(double const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline double number__root(double const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline double number__root(double const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number__create_non_computable(); }
        inline long double number__root(double const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline double number__root(double const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline double number__root(double const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline double number__root(double const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number__create_non_computable(); }
        inline double number__root(double const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline double number__root(double const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number__create_non_computable(); }
        inline double number__root(float const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline double number__root(float const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline float number__root(float const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline float number__root(float const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number__create_non_computable(); }
        inline long double number__root(float const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline float number__root(float const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline float number__root(float const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline float number__root(float const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number__create_non_computable(); }
        inline float number__root(float const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline float number__root(float const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number__create_non_computable(); }
        inline long double number__root(int const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline double number__root(int const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline int number__root(int const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline int number__root(int const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline long double number__root(int const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline int number__root(int const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline int number__root(int const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline int number__root(int const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline int number__root(int const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline int number__root(int const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number; }
        inline long double number__root(long const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline double number__root(long const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline long number__root(long const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline long number__root(long const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline long double number__root(long const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline long number__root(long const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline long number__root(long const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline long number__root(long const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline long number__root(long const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline long number__root(long const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number; }
        inline long double number__root(long double const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number__create_non_computable(); }
        inline long double number__root(long double const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number__create_non_computable(); }
        inline double number__root(short const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline float number__root(short const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline short number__root(short const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline short number__root(short const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline long double number__root(short const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline short number__root(short const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline short number__root(short const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline short number__root(short const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline short number__root(short const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline short number__root(short const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number; }
        inline long double number__root(unsigned int const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline double number__root(unsigned int const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline int number__root(unsigned int const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline int number__root(unsigned int const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline long double number__root(unsigned int const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline long number__root(unsigned int const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned int number__root(unsigned int const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned int number__root(unsigned int const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline unsigned int number__root(unsigned int const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned int number__root(unsigned int const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number; }
        inline long double number__root(unsigned long const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline long double number__root(unsigned long const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline unsigned long number__root(unsigned long const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned long number__root(unsigned long const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline long double number__root(unsigned long const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline unsigned long number__root(unsigned long const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned long number__root(unsigned long const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned long number__root(unsigned long const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline unsigned long number__root(unsigned long const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned long number__root(unsigned long const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number; }
        inline double number__root(unsigned short const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline double number__root(unsigned short const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline unsigned short number__root(unsigned short const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned short number__root(unsigned short const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline long double number__root(unsigned short const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline unsigned short number__root(unsigned short const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned short number__root(unsigned short const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned short number__root(unsigned short const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline unsigned short number__root(unsigned short const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline unsigned short number__root(unsigned short const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number; }
        inline long double number__root(wide const number, double const exponent) { if (2.0 == exponent) return number__square_root(number); else if (3.0 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / exponent); return number__create_non_computable(); }
        inline long double number__root(wide const number, float const exponent) { if (2.0f == exponent) return number__square_root(number); else if (3.0f == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / exponent); return number__create_non_computable(); }
        inline wide number__root(wide const number, int const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline wide number__root(wide const number, long const exponent) { if (2L == exponent) return number__square_root(number); else if (3L == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline long double number__root(wide const number, long double const exponent) { if (2.00 == exponent) return number__square_root(number); else if (3.00 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.00 / exponent); return number__create_non_computable(); }
        inline wide number__root(wide const number, short const exponent) { if (2 == exponent) return number__square_root(number); else if (3 == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline wide number__root(wide const number, unsigned int const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline wide number__root(wide const number, unsigned long const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0 / (double) exponent); return number; }
        inline wide number__root(wide const number, unsigned short const exponent) { if (2u == exponent) return number__square_root(number); else if (3u == exponent) return number__cube_root(number); else if (exponent) return number__exponentiate(number, 1.0f / (float) exponent); return number; }
        inline wide number__root(wide const number, wide const exponent) { if (2uL == exponent) return number__square_root(number); else if (3uL == exponent) return number__cube_root(number); else if (exponent) { if ((wide::wide_signed_type) exponent < 0L) return number__exponentiate(number, 1.00 / (long double) (wide::wide_signed_type) exponent); else return number__exponentiate(number, 1.00 / (long double) (wide::wide_unsigned_type) exponent); } return number; }

        // Sine
        constexpr inline double number__sine(double const number) { return ::sin(number); }
        constexpr inline float number__sine(float const number) {
            #if c__version >= 1990uL
                return ::sinf(number);
            #elif cpp__version >= 1997uL
                return ::sin(number);
            #else
                return number__sine((double) number);
            #endif
        }
        constexpr inline float number__sine(int const number) {
            #if cpp__version >= 2011uL
                return ::sin(number);
            #else
                return number__sine((float) number);
            #endif
        }
        constexpr inline double number__sine(long const number) {
            #if cpp__version >= 2011uL
                return ::sin(number);
            #else
                return number__sine((double) number);
            #endif
        }
        inline long double number__sine(long double const number) {
            #if c__version >= 1990uL
                return ::sinl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
                else return number__arc_tangent((double) number);
            #elif cpp__version >= 1997uL
                return ::sin(number);
            #endif
        }
        constexpr inline float number__sine(short const number) {
            #if cpp__version >= 2011uL
                return ::sin(number);
            #else
                return number__sine((float) number);
            #endif
        }
        constexpr inline float number__sine(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::sin(number);
            #else
                return number__sine((float) number);
            #endif
        }
        constexpr inline double number__sine(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::sin(number);
            #else
                return number__sine((double) number);
            #endif
        }
        constexpr inline float number__sine(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::sin(number);
            #else
                return number__sine((float) number);
            #endif
        }
        inline long double number__sine(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::sin((wide::wide_signed_type) number);
                else return ::sin((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__sine((long double) (wide::wide_signed_type) number);
                else return number__sine((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // Square Root
        constexpr inline double number__square_root(double const number) noexcept {
            #if c__version >= 1990uL || cpp__version >= 1998uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.5);
            #endif
        }
        constexpr inline float number__square_root(float const number) noexcept {
            #if c__version >= 1999uL
                return ::sqrtf(number);
            #elif cpp__version >= 1998uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        constexpr inline int number__square_root(int const number) noexcept {
            #if cpp__version >= 2011uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        constexpr inline long number__square_root(long const number) noexcept {
            #if cpp__version >= 2011uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.5);
            #endif
        }
        constexpr inline long double number__square_root(long double const number) noexcept {
            #if c__version >= 1999uL
                return ::sqrtl(number);
            #elif cpp__version >= 1998uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.50);
            #endif
        }
        constexpr inline short number__square_root(short const number) noexcept {
            #if cpp__version >= 2011uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        constexpr inline unsigned int number__square_root(unsigned int const number) noexcept {
            #if cpp__version >= 2011uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        constexpr inline unsigned long number__square_root(unsigned long const number) noexcept {
            #if cpp__version >= 2011uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.5);
            #endif
        }
        constexpr inline unsigned short number__square_root(unsigned short const number) noexcept {
            #if cpp__version >= 2011uL
                return ::sqrt(number);
            #else
                return number__exponentiate(number, 0.5f);
            #endif
        }
        inline wide number__square_root(wide const number) noexcept {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::sqrt((wide::wide_signed_type) number);
                else return ::sqrt((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__exponentiate((wide::wide_signed_type) number, 0.50);
                else return number__exponentiate((wide::wide_unsigned_type) number, 0.50);
            #endif
        }

        // Tangent
        constexpr inline double number__tangent(double const number) { return ::tan(number); }
        constexpr inline float number__tangent(float const number) {
            #if c__version >= 1990uL
                return ::tanf(number);
            #elif cpp__version >= 1997uL
                return ::tan(number);
            #else
                return number__tangent((double) number);
            #endif
        }
        constexpr inline float number__tangent(int const number) {
            #if cpp__version >= 2011uL
                return ::tan(number);
            #else
                return number__tangent((float) number);
            #endif
        }
        constexpr inline double number__tangent(long const number) {
            #if cpp__version >= 2011uL
                return ::tan(number);
            #else
                return number__tangent((double) number);
            #endif
        }
        inline long double number__tangent(long double const number) {
            #if c__version >= 1990uL
                return ::tanl(number);
            #elif c__version
                if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
                else return number__arc_tangent((double) number);
            #elif cpp__version >= 1997uL
                return ::tan(number);
            #endif
        }
        constexpr inline float number__tangent(short const number) {
            #if cpp__version >= 2011uL
                return ::tan(number);
            #else
                return number__tangent((float) number);
            #endif
        }
        constexpr inline float number__tangent(unsigned int const number) {
            #if cpp__version >= 2011uL
                return ::tan(number);
            #else
                return number__tangent((float) number);
            #endif
        }
        constexpr inline double number__tangent(unsigned long const number) {
            #if cpp__version >= 2011uL
                return ::tan(number);
            #else
                return number__tangent((double) number);
            #endif
        }
        constexpr inline float number__tangent(unsigned short const number) {
            #if cpp__version >= 2011uL
                return ::tan(number);
            #else
                return number__tangent((float) number);
            #endif
        }
        inline long double number__tangent(wide const number) {
            #if cpp__version >= 2011uL
                if ((wide::wide_signed_type) number < 0L) return ::tan((wide::wide_signed_type) number);
                else return ::tan((wide::wide_unsigned_type) number);
            #else
                if ((wide::wide_signed_type) number < 0L) return number__tangent((long double) (wide::wide_signed_type) number);
                else return number__tangent((long double) (wide::wide_unsigned_type) number);
            #endif
        }

        // To Integer
        inline double number__to_integer(double number) noexcept {
            #if c__version >= 1990uL
                ::modf(number, &number); return number;
            #elif c__version >= 1999uL || cpp__version >= 1998uL
                return ::trunc(number);
            #else
                if (number < 0.0) return -number__to_integer(-number); else { double integer = 0.0; for (wide increment = 1uL, overflow = 0uL; increment; overflow = 0uL) { for (increment = 1uL; integer + increment <= number && increment > overflow; increment <<= 1uL) overflow = increment; increment = increment == 1uL || increment <= overflow ? 0uL; increment >> 1uL; integer += increment; } return integer; }
            #endif
        }
        inline float number__to_integer(float number) noexcept {
            #if cpp__version >= 1998uL
                ::modff(number, &number); return number;
            #elif c__version >= 1999uL
                return ::truncf(number);
            #elif cpp__version >= 2011uL
                return ::trunc(number);
            #else
                if (number < 0.0f) return -number__to_integer(-number); else { float integer = 0.0f; for (unsigned long increment = 1uL, overflow = 0uL; increment; overflow = 0uL) { for (increment = 1uL; integer + increment <= number && increment > overflow; increment <<= 1uL) overflow = increment; increment = increment == 1uL || increment <= overflow ? 0uL; increment >> 1uL; integer += increment; } return integer; }
            #endif
        }
        inline int number__to_integer(int const number) noexcept {
            #if cpp__version >= 2011uL
                return ::trunc(number);
            #else
                return number;
            #endif
        }
        inline long number__to_integer(long const number) noexcept {
            #if cpp__version >= 2011uL
                return ::trunc(number);
            #else
                return number;
            #endif
        }
        inline long double number__to_integer(long double number) noexcept {
            #if cpp__version >= 1998uL
                ::modfl(number, &number); return number;
            #elif c__version >= 1999uL
                return ::truncl(number);
            #elif cpp__version >= 2011uL
                return ::trunc(number);
            #else
            #else
                if (number < 0.0) return -number__to_integer(-number); else { long double integer = 0.0; for (wide increment = 1uL, overflow = 0uL; increment; overflow = 0uL) { for (increment = 1uL; integer + increment <= number && increment > overflow; increment <<= 1uL) overflow = increment; increment = increment == 1uL || increment <= overflow ? 0uL; increment >> 1uL; integer += increment; } return 0.0 == integer ? number < 0 ? -((long double) (wide::wide_unsigned_type) -number) : (long double) (wide::wide_unsigned_type) number : integer; }
            #endif
        }
        inline short number__to_integer(short const number) noexcept {
            #if cpp__version >= 2011uL
                return ::trunc(number);
            #else
                return number;
            #endif
        }
        inline unsigned int number__to_integer(unsigned int const number) noexcept {
            #if cpp__version >= 2011uL
                return ::trunc(number);
            #else
                return number;
            #endif
        }
        inline unsigned long number__to_integer(unsigned long const number) noexcept {
            #if cpp__version >= 2011uL
                return ::trunc(number);
            #else
                return number;
            #endif
        }
        inline unsigned short number__to_integer(unsigned short const number) noexcept {
            #if cpp__version >= 2011uL
                return ::trunc(number);
            #else
                return number;
            #endif
        }
        inline wide number__to_integer(wide const number) noexcept {
            #if cpp__version >= 2011uL
                return (wide::wide_signed_type) number < 0L ? ::trunc((wide::wide_signed_type) number) : ::trunc((wide::wide_unsigned_type) number);
            #else
                return number;
            #endif
        }

        // To Mantissa
        inline double number__to_mantissa(double const number) noexcept {
            #if c__version >= 1990uL || cpp__version >= 1998uL
                return ::modf(number, &number);
            #else
                return number - number__to_integer(number);
            #endif
        }
        inline float number__to_mantissa(float const number) noexcept {
            #if c__version >= 1999uL
                return ::modff(number, &number);
            #elif cpp__version >= 1998uL
                return ::modf(number, &number);
            #else
                return number - number__to_integer(number);
            #endif
        }
        inline int number__to_mantissa(int const number) noexcept {
            #if cpp__version >= 2011uL
                double integer; return (int) ::modf(number, &integer);
            #else
                return 0;
            #endif
        }
        inline long number__to_mantissa(long const number) noexcept {
            #if cpp__version >= 2011uL
                double integer; return (long) ::modf(number, &integer);
            #else
                return 0L;
            #endif
        }
        inline long double number__to_mantissa(long double const number) noexcept {
            #if c__version >= 1999uL
                return ::modfl(number, &number);
            #elif cpp__version >= 1998uL
                return ::modf(number, &number);
            #else
                return number - number__to_integer(number);
            #endif
        }
        inline short number__to_mantissa(short const number) noexcept {
            #if cpp__version >= 2011uL
                double integer; return (short) ::modf(number, &integer);
            #else
                return 0;
            #endif
        }
        inline unsigned int number__to_mantissa(unsigned int const number) noexcept {
            #if cpp__version >= 2011uL
                double integer; return (unsigned int) ::modf(number, &integer);
            #else
                return 0u;
            #endif
        }
        inline unsigned long number__to_mantissa(unsigned long const number) noexcept {
            #if cpp__version >= 2011uL
                double integer; return (unsigned long) ::modf(number, &integer);
            #else
                return 0uL;
            #endif
        }
        inline unsigned short number__to_mantissa(unsigned short const number) noexcept {
            #if cpp__version >= 2011uL
                double integer; return (unsigned short) ::modf(number, &integer);
            #else
                return 0u;
            #endif
        }
        inline wide number__to_mantissa(wide const number) noexcept {
            #if cpp__version >= 2011uL
                double integer; return (wide) ((wide::wide_signed_type) number < 0L ? ::modf((wide::wide_signed_type) number, &integer) : ::modf((wide::wide_unsigned_type) number, &integer));
            #else
                return 0uL;
            #endif
        }

        // To String --- CHECKPOINT (Lapys) --- WARN (Lapys) -> Allocated memory is unto the stack.
        inline char const* number__to_string(double const number) noexcept { return NULL; }
        inline char const* number__to_string(float const number) noexcept { return NULL; }
        inline char const* number__to_string(int const number) noexcept { return NULL; }
        inline char const* number__to_string(long const number) noexcept { return NULL; }
        inline char const* number__to_string(long double const number) noexcept { return NULL; }
        inline char const* number__to_string(short const number) noexcept { return NULL; }
        inline char const* number__to_string(unsigned int const number) noexcept { return NULL; }
        inline char const* number__to_string(unsigned long const number) noexcept { return NULL; }
        inline char const* number__to_string(unsigned short const number) noexcept { return NULL; }
        inline char const* number__to_string(wide const number) noexcept { return NULL; }

    /* Pointer */
        // Allocate Heap Memory
        struct pointer__allocate_heap_memory { private: void * const value; public:
            inline pointer__allocate_heap_memory(size_t const size) : value{
                #if environment__is_windows
                    ::HeapAlloc(::GetProcessHeap(), 0x0, size)
                #else
                    ::malloc(size)
                #endif
            } {}
            template <typename type> inline operator type*(void) const noexcept { return (type*) (this -> value); }
        };

        // Allocate Stack Memory --- WARN (Lapys) -> Allocated memory is freed once the function returns.
        struct pointer__allocate_stack_memory { private: void * const value; public:
            constexpr inline pointer__allocate_stack_memory(size_t const size) : value{
                #if environment__is_linux
                    ::alloca(size)
                #elif environment__is_windows
                    ::_alloca(size)
                #endif
            } {}
            template <typename type> inline operator type*(void) const noexcept { return (type*) (this -> value); }
        };

        // Free Heap Memory
        template <typename type> inline void pointer__free_heap_memory(type* const pointer) noexcept {
            #if environment__is_windows
                ::HeapFree(::GetProcessHeap(), 0x0, (void*) pointer);
            #else
                ::free((void*) pointer);
            #endif
        }

        // Free Stack Memory --- NOTE (Lapys) -> Passes onto the `_free` function.
        template <typename type> constexpr inline void pointer__free_stack_memory(type* const) noexcept {}

        // Map Heap Memory --- REDACT (Lapys)
        struct pointer__map_heap_memory { private: void *value; public:
            template <typename type> inline pointer__map_heap_memory(type* const pointer, size_t const size) : value{NULL} {
                #if environment__is_linux
                    int const descriptor = ::open(::tmpnam(NULL), O_CREAT | O_RDWR);

                    if (-1 == descriptor) this -> value = ::mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
                    else { this -> value = ::mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, descriptor, 0); ::close(descriptor); }

                    if (MAP_FAILED == this -> value) this -> value = NULL;
                #elif environment__is_windows
                    ::VirtualAllocEx(::GetCurrentProcess(), NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
                #endif
            }
            template <typename type> inline operator type*(void) const noexcept { return (type*) (this -> value); }
        };

        // Reallocate Heap Memory
        struct pointer__reallocate_heap_memory { private: void * const value; public:
            template <typename type> constexpr inline pointer__reallocate_heap_memory(type* const pointer, size_t const size) : value{
                #if environment__is_windows
                    ::HeapReAlloc(::GetProcessHeap(), 0x0, (void*) pointer, size)
                #else
                    ::realloc((void*) pointer, size)
                #endif
            } {}
            template <typename type> inline operator type*(void) const noexcept { return (type*) (this -> value); }
        };

        // Reallocate Stack Memory --- REDACT (Lapys) --- WARN (Lapys) -> Allocated memory is freed once the function returns.
        struct pointer__reallocate_stack_memory { public:
            template <typename type> constexpr inline pointer__reallocate_stack_memory(type* const, size_t const) {}
            template <typename type> inline operator type*(void) const noexcept { return NULL; }
        };

        // Source Copy
        template <typename type> inline void pointer__source_copy_memory(type* const source, type* const pointer, size_t const size) noexcept { ::memmove((void*) source, (void*) pointer, size); }

        // Source Move
        template <typename type> inline void pointer__source_move_memory(type* const source, type* const pointer, size_t const size) noexcept { ::memcpy((void*) source, (void*) pointer, size); }

        // Unmap Heap Memory
        template <typename type>
        inline void pointer__unmap_heap_memory(type* const pointer, size_t const size) noexcept {
            #if environment__is_linux
                ::munmap((void*) pointer, size);
            #elif environment__is_windows
                ::VirtualFree((void*) pointer, size, MEM_RELEASE);
            #endif
        }

        // Zero Memory
        template <typename type> inline void pointer__zero_memory(type* const pointer, size_t const size) noexcept { ::memset((void*) pointer, 0u, size); }

    /* String */
        // Concatenate --- NOTE (Lapys) -> Allocates memory onto the heap.
        void string__concatenate(void) noexcept {}

        // Copy --- NOTE (Lapys) -> Allocates memory onto the heap.
        void string__copy(void) noexcept {}

        // Create --- NOTE (Lapys) -> Allocates memory onto the heap.
        void string__create(void) noexcept {}

        // Ends With
        void string__ends_with(void) noexcept {}

        // Free Heap Memory
        void string__free_heap_memory(void) noexcept {}

        // Includes
        void string__includes(void) noexcept {}

        // Index --- NOTE (Lapys) -> Custom searching algorithm.
        void string__index(void) noexcept {}

        // Index From Back
        void string__index_from_back(void) noexcept {}

        // Index From Front
        void string__index_from_front(void) noexcept {}

        // Is Empty
        inline bool string__is_empty(char* const string) noexcept { return NULL == string || '\0' == *string; }
        inline bool string__is_empty(char const* const string) noexcept { return NULL == string || '\0' == *string; }
        template <size_t length> inline bool string__is_empty(char (&string)[length]) noexcept { return length && '\0' == *string; }
        template <size_t length> inline bool string__is_empty(char const (&string)[length]) noexcept { return length && '\0' == *string; }
        inline bool string__is_empty(char8_t* const string) noexcept { return NULL == string || 0u == *string; }
        inline bool string__is_empty(char8_t const* const string) noexcept { return NULL == string || 0u == *string; }
        template <size_t length> inline bool string__is_empty(char8_t (&string)[length]) noexcept { return length && 0u == *string; }
        template <size_t length> inline bool string__is_empty(char8_t const (&string)[length]) noexcept { return length && 0u == *string; }
        inline bool string__is_empty(char16_t* const string) noexcept { return NULL == string || 0u == *string; }
        inline bool string__is_empty(char16_t const* const string) noexcept { return NULL == string || 0u == *string; }
        template <size_t length> inline bool string__is_empty(char16_t (&string)[length]) noexcept { return length && 0u == *string; }
        template <size_t length> inline bool string__is_empty(char16_t const (&string)[length]) noexcept { return length && 0u == *string; }
        inline bool string__is_empty(char32_t* const string) noexcept { return NULL == string || 0u == *string; }
        inline bool string__is_empty(char32_t const* const string) noexcept { return NULL == string || 0u == *string; }
        template <size_t length> inline bool string__is_empty(char32_t (&string)[length]) noexcept { return length && 0u == *string; }
        template <size_t length> inline bool string__is_empty(char32_t const (&string)[length]) noexcept { return length && 0u == *string; }
        inline bool string__is_empty(wchar_t* const string) noexcept { return NULL == string || L'\0' == *string; }
        inline bool string__is_empty(wchar_t const* const string) noexcept { return NULL == string || L'\0' == *string; }
        template <size_t length> inline bool string__is_empty(wchar_t (&string)[length]) noexcept { return length && L'\0' == *string; }
        template <size_t length> inline bool string__is_empty(wchar_t const (&string)[length]) noexcept { return length && L'\0' == *string; }

        // Length --- NOTE (Lapys) -> Counts the characters until a null-terminal is reached for raw pointers.
        constexpr inline size_t string__length(char* const string) noexcept { return string__length((char const*) string); }
        constexpr inline size_t string__length(char const* const string) noexcept { return NULL == string ? 0u : ::strlen(string); }
        template <size_t length> inline size_t string__length(char (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && ('\0' ^ *(string + evaluation))) ++evaluation; return evaluation; } else return length; }
        template <size_t length> inline size_t string__length(char const (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && ('\0' ^ *(string + evaluation))) ++evaluation; return evaluation; } else return length; }
        inline size_t string__length(char8_t* const string) noexcept { return string__length((char8_t const*) string); }
        inline size_t string__length(char8_t const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        template <size_t length> inline size_t string__length(char8_t (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && *(string + evaluation)) ++evaluation; return evaluation; } else return length; }
        template <size_t length> inline size_t string__length(char8_t const (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && *(string + evaluation)) ++evaluation; return evaluation; } else return length; }
        inline size_t string__length(char16_t* const string) noexcept { return string__length((char16_t const*) string); }
        inline size_t string__length(char16_t const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        template <size_t length> inline size_t string__length(char16_t (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && *(string + evaluation)) ++evaluation; return evaluation; } else return length; }
        template <size_t length> inline size_t string__length(char16_t const (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && *(string + evaluation)) ++evaluation; return evaluation; } else return length; }
        inline size_t string__length(char32_t* const string) noexcept { return string__length((char32_t const*) string); }
        inline size_t string__length(char32_t const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        template <size_t length> inline size_t string__length(char32_t (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && *(string + evaluation)) ++evaluation; return evaluation; } else return length; }
        template <size_t length> inline size_t string__length(char32_t const (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && *(string + evaluation)) ++evaluation; return evaluation; } else return length; }
        constexpr inline size_t string__length(wchar_t* const string) noexcept { return string__length((wchar_t const*) string); }
        constexpr inline size_t string__length(wchar_t const* const string) noexcept { return NULL == string ? 0u : ::wcslen(string); }
        template <size_t length> inline size_t string__length(wchar_t (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && (L'\0' ^ *(string + evaluation))) ++evaluation; return evaluation; } else return length; }
        template <size_t length> inline size_t string__length(wchar_t const (&string)[length]) noexcept { if (length) { size_t evaluation = 0u; while ((evaluation ^ length) && (L'\0' ^ *(string + evaluation))) ++evaluation; return evaluation; } else return length; }

        // Remove
        void string__remove(void) noexcept {}

        // Repeat
        void string__repeat(void) noexcept {}

        // Replace
        void string__replace(void) noexcept {}

        // Resize --- WARN (Lapys) -> Assumes the array is heap-allocated.
        void string__resize_heap_memory(void) noexcept {}

        // Slice
        void string__slice(void) noexcept {}

        // Splice
        void string__splice(void) noexcept {}

        // Source Concatenate
        void string__source_concatenate(void) noexcept {}

        // Source Copy
        void string__source_copy(void) noexcept {}

        // Starts With
        void string__starts_with(void) noexcept {}

        // To Lowercase
        void string__to_lowercase(void) noexcept {}

        // To Lowercase
        void string__to_uppercase(void) noexcept {}

        // Trim
        void string__trim(void) noexcept {}

        // Trim End
        void string__trim_end(void) noexcept {}

        // Trim Start
        void string__trim_start(void) noexcept {}

/* Modification */
    /* Boolean */
        // [Constructor]
        constexpr inline boolean::boolean(bool const argument) : value{argument ? boolean::boolean_true : boolean::boolean_false} {}
        constexpr inline boolean::boolean(void) : value{boolean::boolean_false} {}
        constexpr inline boolean::boolean(boolean& argument) : value{argument.value} {}
        constexpr inline boolean::boolean(boolean&& argument) : value{argument.value} {}
        constexpr inline boolean::boolean(boolean const& argument) : value{argument.value} {}
        constexpr inline boolean::boolean(boolean const&& argument) : value{argument.value} {}

        // [Operator] > ...
        inline boolean& boolean::operator =(bool const argument) noexcept { this -> value = argument ? boolean::boolean_true : boolean::boolean_false; return *this; }
        inline boolean& boolean::operator =(boolean& argument) noexcept { this -> value = argument.value; return *this; }
        inline boolean& boolean::operator =(boolean&& argument) noexcept { this -> value = argument.value; return *this; }
        inline boolean& boolean::operator =(boolean const& argument) noexcept { this -> value = argument.value; return *this; }
        inline boolean& boolean::operator =(boolean const&& argument) noexcept { this -> value = argument.value; return *this; }

        inline boolean::operator bool(void) const noexcept { return boolean::boolean_true == this -> value; }

    /* Character */
        // [Constructor]
        constexpr inline character::character(char const argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(char8_t const argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(char16_t const argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(char32_t const argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(signed char const argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(unsigned char const argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(wchar_t const argument) : value{(character::character_type) argument} {}
        constexpr inline character::character(character& argument) : value{argument.value} {}
        constexpr inline character::character(character&& argument) : value{argument.value} {}
        constexpr inline character::character(character const& argument) : value{argument.value} {}
        constexpr inline character::character(character const&& argument) : value{argument.value} {}

        // [Operator] > ...
        inline character& character::operator =(char const argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(char8_t const argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(char16_t const argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(char32_t const argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(signed char const argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(unsigned char const argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(wchar_t const argument) noexcept { this -> value = (character::character_type) argument; return *this; }
        inline character& character::operator =(character& argument) noexcept { this -> value = argument.value; return *this; }
        inline character& character::operator =(character&& argument) noexcept { this -> value = argument.value; return *this; }
        inline character& character::operator =(character const& argument) noexcept { this -> value = argument.value; return *this; }
        inline character& character::operator =(character const&& argument) noexcept { this -> value = argument.value; return *this; }

        inline character::operator character_type(void) const noexcept { return this -> value; }

    /* Integral */
        // [Constructor]
        inline integral::integral(int const argument) : type{integral::integral__int__type}, value{} { this -> value.integral__int__value = argument; }
        inline integral::integral(long const argument) : type{integral::integral__long__type}, value{} { this -> value.integral__long__value = argument; }
        inline integral::integral(short const argument) : type{integral::integral__short__type}, value{} { this -> value.integral__short__value = argument; }
        inline integral::integral(unsigned int const argument) : type{integral::integral__int__type}, value{} { this -> value.integral__int__value = argument; }
        inline integral::integral(unsigned long const argument) : type{integral::integral__long__type}, value{} { this -> value.integral__long__value = argument; }
        inline integral::integral(unsigned short const argument) : type{integral::integral__short__type}, value{} { this -> value.integral__short__value = argument; }
        inline integral::integral(wide const argument) : type{integral::integral__wide__type}, value{} { this -> value.integral__wide__value = argument; }
        inline integral::integral(integral& argument) : type{argument.type}, value{} { switch (this -> type) {
            case integral::integral__int__type: this -> value.integral__int__value = argument.value.integral__int__value; break;
            case integral::integral__long__type: this -> value.integral__long__value = argument.value.integral__long__value; break;
            case integral::integral__short__type: this -> value.integral__short__value = argument.value.integral__short__value; break;
            case integral::integral__wide__type: this -> value.integral__wide__value = argument.value.integral__wide__value; break;
        } }
        inline integral::integral(integral&& argument) : type{argument.type}, value{} { switch (this -> type) {
            case integral::integral__int__type: this -> value.integral__int__value = argument.value.integral__int__value; break;
            case integral::integral__long__type: this -> value.integral__long__value = argument.value.integral__long__value; break;
            case integral::integral__short__type: this -> value.integral__short__value = argument.value.integral__short__value; break;
            case integral::integral__wide__type: this -> value.integral__wide__value = argument.value.integral__wide__value; break;
        } }
        inline integral::integral(integral const& argument) : type{argument.type}, value{} { switch (this -> type) {
            case integral::integral__int__type: this -> value.integral__int__value = argument.value.integral__int__value; break;
            case integral::integral__long__type: this -> value.integral__long__value = argument.value.integral__long__value; break;
            case integral::integral__short__type: this -> value.integral__short__value = argument.value.integral__short__value; break;
            case integral::integral__wide__type: this -> value.integral__wide__value = argument.value.integral__wide__value; break;
        } }
        inline integral::integral(integral const&& argument) : type{argument.type}, value{} { switch (this -> type) {
            case integral::integral__int__type: this -> value.integral__int__value = argument.value.integral__int__value; break;
            case integral::integral__long__type: this -> value.integral__long__value = argument.value.integral__long__value; break;
            case integral::integral__short__type: this -> value.integral__short__value = argument.value.integral__short__value; break;
            case integral::integral__wide__type: this -> value.integral__wide__value = argument.value.integral__wide__value; break;
        } }

        // [Operator] > ...
        inline integral& integral::operator =(int const argument) noexcept { this -> type = integral::integral__int__type; this -> value.integral__int__value = argument; return *this; }
        inline integral& integral::operator =(long const argument) noexcept { this -> type = integral::integral__long__type; this -> value.integral__long__value = argument; return *this; }
        inline integral& integral::operator =(short const argument) noexcept { this -> type = integral::integral__short__type; this -> value.integral__short__value = argument; return *this; }
        inline integral& integral::operator =(unsigned int const argument) noexcept { this -> type = integral::integral__int__type; this -> value.integral__int__value = argument; return *this; }
        inline integral& integral::operator =(unsigned long const argument) noexcept { this -> type = integral::integral__long__type; this -> value.integral__long__value = argument; return *this; }
        inline integral& integral::operator =(unsigned short const argument) noexcept { this -> type = integral::integral__short__type; this -> value.integral__short__value = argument; return *this; }
        inline integral& integral::operator =(wide const argument) noexcept { this -> type = integral::integral__wide__type; this -> value.integral__wide__value = argument; return *this; }
        inline integral& integral::operator =(integral& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case integral::integral__int__type: this -> value.integral__int__value = argument.value.integral__int__value; break;
            case integral::integral__long__type: this -> value.integral__long__value = argument.value.integral__long__value; break;
            case integral::integral__short__type: this -> value.integral__short__value = argument.value.integral__short__value; break;
            case integral::integral__wide__type: this -> value.integral__wide__value = argument.value.integral__wide__value; break;
        } return *this; }
        inline integral& integral::operator =(integral&& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case integral::integral__int__type: this -> value.integral__int__value = argument.value.integral__int__value; break;
            case integral::integral__long__type: this -> value.integral__long__value = argument.value.integral__long__value; break;
            case integral::integral__short__type: this -> value.integral__short__value = argument.value.integral__short__value; break;
            case integral::integral__wide__type: this -> value.integral__wide__value = argument.value.integral__wide__value; break;
        } return *this; }
        inline integral& integral::operator =(integral const& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case integral::integral__int__type: this -> value.integral__int__value = argument.value.integral__int__value; break;
            case integral::integral__long__type: this -> value.integral__long__value = argument.value.integral__long__value; break;
            case integral::integral__short__type: this -> value.integral__short__value = argument.value.integral__short__value; break;
            case integral::integral__wide__type: this -> value.integral__wide__value = argument.value.integral__wide__value; break;
        } return *this; }
        inline integral& integral::operator =(integral const&& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case integral::integral__int__type: this -> value.integral__int__value = argument.value.integral__int__value; break;
            case integral::integral__long__type: this -> value.integral__long__value = argument.value.integral__long__value; break;
            case integral::integral__short__type: this -> value.integral__short__value = argument.value.integral__short__value; break;
            case integral::integral__wide__type: this -> value.integral__wide__value = argument.value.integral__wide__value; break;
        } return *this; }

        inline integral::operator wide(void) const noexcept { switch (this -> type) {
            case integral::integral__int__type: return this -> value.integral__int__value;
            case integral::integral__long__type: return this -> value.integral__long__value;
            case integral::integral__short__type: return this -> value.integral__short__value;
            case integral::integral__wide__type: return this -> value.integral__wide__value;
        } }

    /* Null Pointer */
        // [Constructor]
        constexpr inline null_pointer::null_pointer(void) : pointer() {}
        constexpr inline null_pointer::null_pointer(null_pointer&) : pointer() {}
        constexpr inline null_pointer::null_pointer(null_pointer&&) : pointer() {}
        constexpr inline null_pointer::null_pointer(null_pointer const&) : pointer() {}
        constexpr inline null_pointer::null_pointer(null_pointer const&&) : pointer() {}

        // [Operator] > ...
        template <typename type> inline null_pointer::operator type*(void) const noexcept { return NULL; }

    /* Number */
        // [Constructor]
        inline number::number(integral const argument) : type{number::number__integral__type}, value{} { this -> value.number__integral__value = argument; }
        inline number::number(rational const argument) : type{number::number__rational__type}, value{} { this -> value.number__rational__value = argument; }
        inline number::number(number& argument) : type{argument.type}, value{} { switch (this -> type) {
            case number::number__integral__type: this -> value.number__integral__value = argument.value.number__integral__value; break;
            case number::number__rational__type: this -> value.number__rational__value = argument.value.number__rational__value; break;
        } }
        inline number::number(number&& argument) : type{argument.type}, value{} { switch (this -> type) {
            case number::number__integral__type: this -> value.number__integral__value = argument.value.number__integral__value; break;
            case number::number__rational__type: this -> value.number__rational__value = argument.value.number__rational__value; break;
        } }
        inline number::number(number const& argument) : type{argument.type}, value{} { switch (this -> type) {
            case number::number__integral__type: this -> value.number__integral__value = argument.value.number__integral__value; break;
            case number::number__rational__type: this -> value.number__rational__value = argument.value.number__rational__value; break;
        } }
        inline number::number(number const&& argument) : type{argument.type}, value{} { switch (this -> type) {
            case number::number__integral__type: this -> value.number__integral__value = argument.value.number__integral__value; break;
            case number::number__rational__type: this -> value.number__rational__value = argument.value.number__rational__value; break;
        } }

        // [Operator] > ...
        inline number& number::operator =(integral const argument) noexcept { this -> type = number::number__integral__type; this -> value.number__integral__value = argument; return *this; }
        inline number& number::operator =(rational const argument) noexcept { this -> type = number::number__rational__type; this -> value.number__rational__value = argument; return *this; }
        inline number& number::operator =(number& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case number::number__integral__type: this -> value.number__integral__value = argument.value.number__integral__value; break;
            case number::number__rational__type: this -> value.number__rational__value = argument.value.number__rational__value; break;
        } return *this; }
        inline number& number::operator =(number&& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case number::number__integral__type: this -> value.number__integral__value = argument.value.number__integral__value; break;
            case number::number__rational__type: this -> value.number__rational__value = argument.value.number__rational__value; break;
        } return *this; }
        inline number& number::operator =(number const& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case number::number__integral__type: this -> value.number__integral__value = argument.value.number__integral__value; break;
            case number::number__rational__type: this -> value.number__rational__value = argument.value.number__rational__value; break;
        } return *this; }
        inline number& number::operator =(number const&& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case number::number__integral__type: this -> value.number__integral__value = argument.value.number__integral__value; break;
            case number::number__rational__type: this -> value.number__rational__value = argument.value.number__rational__value; break;
        } return *this; }

        inline number::operator double(void) noexcept { return (long double) this -> value.number__rational__value; }
        inline number::operator float(void) noexcept { return (long double) this -> value.number__rational__value; }
        inline number::operator int(void) noexcept { return (wide) this -> value.number__integral__value; }
        inline number::operator long(void) noexcept { return (wide) this -> value.number__integral__value; }
        inline number::operator long double(void) noexcept { return this -> value.number__rational__value; }
        inline number::operator short(void) noexcept { return (wide) this -> value.number__integral__value; }
        inline number::operator unsigned int(void) noexcept { return (wide) this -> value.number__integral__value; }
        inline number::operator unsigned long(void) noexcept { return (wide) this -> value.number__integral__value; }
        inline number::operator unsigned short(void) noexcept { return (wide) this -> value.number__integral__value; }
        inline number::operator wide(void) noexcept { return this -> value.number__integral__value; }

    /* Pointer */
        // [Constructor]
        constexpr inline pointer::pointer(void) {}
        constexpr inline pointer::pointer(pointer&) {}
        constexpr inline pointer::pointer(pointer&&) {}
        constexpr inline pointer::pointer(pointer const&) {}
        constexpr inline pointer::pointer(pointer const&&) {}

    /* Primitive */
        // [Constructor]
        inline primitive::primitive(number const argument) : type{primitive::primitive__number__type}, value{} { this -> value.primitive__number__value = argument; }
        inline primitive::primitive(raw_pointer const argument) : type{primitive::primitive__pointer__type}, value{} { this -> value.primitive__pointer__value = argument; }
        inline primitive::primitive(primitive& argument) : type{argument.type}, value{} { switch (this -> type) {
            case primitive::primitive__number__type: this -> value.primitive__number__value = argument.value.primitive__number__value; break;
            case primitive::primitive__pointer__type: this -> value.primitive__pointer__value = argument.value.primitive__pointer__value; break;
        } }
        inline primitive::primitive(primitive&& argument) : type{argument.type}, value{} { switch (this -> type) {
            case primitive::primitive__number__type: this -> value.primitive__number__value = argument.value.primitive__number__value; break;
            case primitive::primitive__pointer__type: this -> value.primitive__pointer__value = argument.value.primitive__pointer__value; break;
        } }
        inline primitive::primitive(primitive const& argument) : type{argument.type}, value{} { switch (this -> type) {
            case primitive::primitive__number__type: this -> value.primitive__number__value = argument.value.primitive__number__value; break;
            case primitive::primitive__pointer__type: this -> value.primitive__pointer__value = argument.value.primitive__pointer__value; break;
        } }
        inline primitive::primitive(primitive const&& argument) : type{argument.type}, value{} { switch (this -> type) {
            case primitive::primitive__number__type: this -> value.primitive__number__value = argument.value.primitive__number__value; break;
            case primitive::primitive__pointer__type: this -> value.primitive__pointer__value = argument.value.primitive__pointer__value; break;
        } }

        // [Operator] > ...
        inline primitive& primitive::operator =(number const argument) noexcept { this -> type = primitive::primitive__number__type; this -> value.primitive__number__value = argument; return *this; }
        inline primitive& primitive::operator =(raw_pointer const argument) noexcept { this -> type = primitive::primitive__pointer__type; this -> value.primitive__pointer__value = argument; return *this; }
        inline primitive& primitive::operator =(primitive& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case primitive::primitive__number__type: this -> value.primitive__number__value = argument.value.primitive__number__value; break;
            case primitive::primitive__pointer__type: this -> value.primitive__pointer__value = argument.value.primitive__pointer__value; break;
        } return *this; }
        inline primitive& primitive::operator =(primitive&& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case primitive::primitive__number__type: this -> value.primitive__number__value = argument.value.primitive__number__value; break;
            case primitive::primitive__pointer__type: this -> value.primitive__pointer__value = argument.value.primitive__pointer__value; break;
        } return *this; }
        inline primitive& primitive::operator =(primitive const& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case primitive::primitive__number__type: this -> value.primitive__number__value = argument.value.primitive__number__value; break;
            case primitive::primitive__pointer__type: this -> value.primitive__pointer__value = argument.value.primitive__pointer__value; break;
        } return *this; }
        inline primitive& primitive::operator =(primitive const&& argument) noexcept { this -> type = argument.type; switch (this -> type) {
            case primitive::primitive__number__type: this -> value.primitive__number__value = argument.value.primitive__number__value; break;
            case primitive::primitive__pointer__type: this -> value.primitive__pointer__value = argument.value.primitive__pointer__value; break;
        } return *this; }

        inline primitive::operator number(void) noexcept { return this -> value.primitive__number__value; }
        inline primitive::operator pointer(void) noexcept { return this -> value.primitive__pointer__value; }

    /* Rational */
        // [Constructor]
        inline rational::rational(double const argument) : type{rational::rational__double__type}, value{} { this -> value.rational__double__value = argument; }
        inline rational::rational(float const argument) : type{rational::rational__float__type}, value{} { this -> value.rational__float__value = argument; }
        inline rational::rational(long double const argument) : type{rational::rational__long_double__type}, value{} { this -> value.rational__long_double__value = argument; }
        constexpr inline rational::rational(rational& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline rational::rational(rational&& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline rational::rational(rational const& argument) : type{argument.type}, value{argument.value} {}
        constexpr inline rational::rational(rational const&& argument) : type{argument.type}, value{argument.value} {}

        // [Operator] > ...
        inline rational& rational::operator =(double const argument) noexcept { this -> type = rational::rational__double__type; this -> value.rational__double__value = argument; return *this; }
        inline rational& rational::operator =(float const argument) noexcept { this -> type = rational::rational__float__type; this -> value.rational__float__value = argument; return *this; }
        inline rational& rational::operator =(long double const argument) noexcept { this -> type = rational::rational__long_double__type; this -> value.rational__long_double__value = argument; return *this; }
        inline rational& rational::operator =(rational& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline rational& rational::operator =(rational&& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline rational& rational::operator =(rational const& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }
        inline rational& rational::operator =(rational const&& argument) noexcept { this -> type = argument.type; this -> value = argument.value; return *this; }

        inline rational::operator long double(void) const noexcept { switch (this -> type) {
            case rational::rational__double__type: return this -> value.rational__double__value;
            case rational::rational__float__type: return this -> value.rational__float__value;
            case rational::rational__long_double__type: return this -> value.rational__long_double__value;
        } }

    /* Raw Pointer */
        // [Constructor]
        constexpr inline raw_pointer::raw_pointer(raw_pointer& argument) : pointer(), value{argument.value} {}
        constexpr inline raw_pointer::raw_pointer(raw_pointer&& argument) : pointer(), value{argument.value} {}
        constexpr inline raw_pointer::raw_pointer(raw_pointer const& argument) : pointer(), value{argument.value} {}
        constexpr inline raw_pointer::raw_pointer(raw_pointer const&& argument) : pointer(), value{argument.value} {}
        template <typename type> constexpr inline raw_pointer::raw_pointer(type* argument) : pointer(), value{argument} {}

        // [Operator] > ...
        inline raw_pointer& raw_pointer::operator =(raw_pointer& argument) noexcept { this -> value = argument.value; return *this; }
        inline raw_pointer& raw_pointer::operator =(raw_pointer&& argument) noexcept { this -> value = argument.value; return *this; }
        inline raw_pointer& raw_pointer::operator =(raw_pointer const& argument) noexcept { this -> value = argument.value; return *this; }
        inline raw_pointer& raw_pointer::operator =(raw_pointer const&& argument) noexcept { this -> value = argument.value; return *this; }
        template <typename type> inline raw_pointer& raw_pointer::operator =(type* const argument) noexcept { this -> value = (void*) argument; return *this; }

        template <typename type> inline raw_pointer::operator type*(void) const noexcept { return this -> value; }

    /* String */
        // [Constructor] --- MINIFY (Lapys)
        inline string::string(char* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(char const* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(char8_t* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(char8_t const* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(char16_t* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(char16_t const* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(char32_t* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(char32_t const* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(signed char* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(signed char const* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(unsigned char* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(unsigned char const* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(wchar_t* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(wchar_t const* const argument) : length{0u}, value{NULL} { if (argument) { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } } }
        inline string::string(string& argument) : length{argument.length}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); pointer__source_move_memory(this -> value, argument.value, this -> length * sizeof(character)); } }
        inline string::string(string&& argument) : length{argument.length}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); pointer__source_move_memory(this -> value, argument.value, this -> length * sizeof(character)); } }
        inline string::string(string const& argument) : length{argument.length}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); pointer__source_move_memory(this -> value, argument.value, this -> length * sizeof(character)); } }
        inline string::string(string const&& argument) : length{argument.length}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); pointer__source_move_memory(this -> value, argument.value, this -> length * sizeof(character)); } }
        template <size_t argumentLength> inline string::string(char (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(char const (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(char8_t (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(char8_t const (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(char16_t (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(char16_t const (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(char32_t (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(char32_t const (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(signed char (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(signed char const (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(unsigned char (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(unsigned char const (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(wchar_t (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }
        template <size_t argumentLength> inline string::string(wchar_t const (&argument)[argumentLength]) : length{0u}, value{NULL} { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__allocate_heap_memory(argumentLength); while (((this -> length) ^ argumentLength) && *(argument + (this -> length))) { *(this -> value + (this -> length)) = *(argument + (this -> length)); ++(this -> length); } } }

        // [Destructor]
        string::~string(void) { pointer__free_heap_memory(this -> value); }

        // [Operator] > ... --- MINIFY (Lapys)
        inline string& string::operator =(char* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(char const* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(char8_t* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(char8_t const* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(char16_t* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(char16_t const* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(char32_t* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(char32_t const* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(signed char* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(signed char const* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(unsigned char* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(unsigned char const* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(wchar_t* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(wchar_t const* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(string& argument) noexcept { if (this != &argument) { this -> length = argument.length; if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); pointer__source_copy_memory(this -> value, argument.value, this -> length * sizeof(character)); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } } return *this; }
        inline string& string::operator =(string&& argument) noexcept { if (this != &argument) { this -> length = argument.length; if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); pointer__source_copy_memory(this -> value, argument.value, this -> length * sizeof(character)); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } } return *this; }
        inline string& string::operator =(string const& argument) noexcept { if (this != &argument) { this -> length = argument.length; if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); pointer__source_copy_memory(this -> value, argument.value, this -> length * sizeof(character)); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } } return *this; }
        inline string& string::operator =(string const&& argument) noexcept { if (this != &argument) { this -> length = argument.length; if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> value, this -> length * sizeof(character)); pointer__source_copy_memory(this -> value, argument.value, this -> length * sizeof(character)); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } } return *this; }
        template <size_t argumentLength> inline string& string::operator =(char (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(char const (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(char8_t (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(char8_t const (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(char16_t (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(char16_t const (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(char32_t (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(char32_t const (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(signed char (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(signed char const (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(unsigned char (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(unsigned char const (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(wchar_t (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }
        template <size_t argumentLength> inline string& string::operator =(wchar_t const (&argument)[argumentLength]) noexcept { if (argumentLength && !string__is_empty(argument)) { this -> value = pointer__reallocate_heap_memory(this -> value, argumentLength); for (this -> length = 0u; ((this -> length) ^ argumentLength) && *(argument + (this -> length)); ++(this -> length)) *(this -> value + (this -> length)) = *(argument + (this -> length)); } return *this; }

        inline string::operator char*(void) const noexcept { return (char*) this -> value; }
        inline string::operator char const*(void) const noexcept { return (char const*) this -> value; }
        inline string::operator char8_t*(void) const noexcept { return (char8_t*) this -> value; }
        inline string::operator char8_t const*(void) const noexcept { return (char8_t const*) this -> value; }
        inline string::operator char16_t*(void) const noexcept { return (char16_t*) this -> value; }
        inline string::operator char16_t const*(void) const noexcept { return (char16_t const*) this -> value; }
        inline string::operator char32_t*(void) const noexcept { return (char32_t*) this -> value; }
        inline string::operator char32_t const*(void) const noexcept { return (char32_t const*) this -> value; }
        inline string::operator signed char*(void) const noexcept { return (signed char*) this -> value; }
        inline string::operator signed char const*(void) const noexcept { return (signed char const*) this -> value; }
        inline string::operator unsigned char*(void) const noexcept { return (unsigned char*) this -> value; }
        inline string::operator unsigned char const*(void) const noexcept { return (unsigned char const*) this -> value; }
        inline string::operator void*(void) const noexcept { return (void*) this -> value; }
        inline string::operator void const*(void) const noexcept { return (void const*) this -> value; }
        inline string::operator wchar_t*(void) const noexcept { return (wchar_t*) this -> value; }
        inline string::operator wchar_t const*(void) const noexcept { return (wchar_t const*) this -> value; }
        inline string::operator boolean(void) const noexcept { return NULL != this -> value && *(this -> value); }

    /* Wide */
        // [Constructor]
        constexpr inline wide::wide(void) : value{} {}
        template <typename type> constexpr inline wide::wide(type argument) : value{argument} {}

        // [Operator] > ...
        template <typename type> inline wide& wide::operator =(type argument) noexcept { this -> value = argument; return *this; }
        template <typename type> inline wide& wide::operator +=(type argument) noexcept { this -> value += argument; return *this; }
        template <typename type> inline wide& wide::operator -=(type argument) noexcept { this -> value -= argument; return *this; }
        template <typename type> inline wide& wide::operator *=(type argument) noexcept { this -> value *= argument; return *this; }
        template <typename type> inline wide& wide::operator /=(type argument) noexcept { this -> value /= argument; return *this; }
        template <typename type> inline wide& wide::operator %=(type argument) noexcept { this -> value %= argument; return *this; }
        template <typename type> inline wide& wide::operator ^=(type argument) noexcept { this -> value ^= argument; return *this; }
        template <typename type> inline wide& wide::operator &=(type argument) noexcept { this -> value &= argument; return *this; }
        template <typename type> inline wide& wide::operator |=(type argument) noexcept { this -> value |= argument; return *this; }
        template <typename type> inline wide& wide::operator >>=(type argument) noexcept { return this -> value >>= argument; return *this; }
        template <typename type> inline wide& wide::operator <<=(type argument) noexcept { return this -> value <<= argument; return *this; }
        inline wide wide::operator ++(int const) noexcept { (this -> value)++; return *this; }
        inline wide& wide::operator ++(void) noexcept { ++(this -> value); return *this; }
        inline wide wide::operator --(int const) noexcept { (this -> value)--; return *this; }
        inline wide& wide::operator --(void) noexcept { --(this -> value); return *this; }

        constexpr inline wide::operator wide_unsigned_type(void) const noexcept { return this -> value; }
