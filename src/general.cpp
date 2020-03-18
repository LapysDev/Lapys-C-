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

    /* Wide --- NOTE (Lapys) -> Alias for the largest C++ primitive integral type; Allowed niladic constructor. --- WARN (Lapys) -> Defers value without sign. */
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

            inline operator wide_unsigned_type(void) const noexcept;
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
        void array__create(void) noexcept {}

        // Fill
        void array__fill(void) noexcept {}

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

    /* Number */
        // Is Computable --- NOTE (Lapys) -> Is `NaN`.
        void number__is_computable(void) noexcept {}

        // Is Determinate
        void number__is_determinate(void) noexcept {}

        // Is Finite
        void number__is_finite(void) noexcept {}

        // Is Normalized
        void number__is_normalized(void) noexcept {}

    /* Pointer */
        // Allocate Heap Memory
        struct pointer__allocate_heap_memory { private: void *value; public:
            constexpr inline pointer__allocate_heap_memory(size_t const size) : value{::malloc(size)} {}
            template <typename type> inline operator type*(void) noexcept { return (type*) (this -> value); }
        };

        // Allocate Stack Memory
        void pointer__allocate_stack_memory(void) noexcept {}

        // Free Heap Memory
        template <typename type> inline void pointer__free_heap_memory(type* const pointer) noexcept { ::free(pointer); }

        // Free Stack Memory
        void pointer__free_stack_memory(void) noexcept {}

        // Map Heap Memory
        void pointer__map_heap_memory(void) noexcept {}

        // Reallocate Heap Memory
        struct pointer__reallocate_heap_memory {
            public:
                inline pointer__reallocate_heap_memory& operator ()(size_t const size) { this -> size = size; return *this; }
                friend type* operator =(type*& pointer, pointer__reallocate_heap_memory& function) noexcept {
                    pointer = (type*) ::realloc((void*) pointer, function.size);
                    return pointer;
                }

            template <typename type> inline operator type*(void) noexcept { return NULL == this -> currentValue || this -> currentValue == this -> recentValue ? NULL : this -> currentValue; }
        } pointer__reallocate_heap_memory;

        // Reallocate Stack Memory
        void pointer__reallocate_stack_memory(void) noexcept {}

        // Source Copy
        template <typename type> inline void pointer__source_copy_memory(type* const source, type* const pointer, size_t const size) noexcept { ::memmove((void*) source, (void*) pointer, size); }

        // Source Move
        template <typename type> inline void pointer__source_move_memory(type* const source, type* const pointer, size_t const size) noexcept { ::memcpy((void*) source, (void*) pointer, size); }

        // Unmap Heap Memory
        void pointer__unmap_heap_memory(void) noexcept {}

        // Zero Memory
        void pointer__zero_memory(void) noexcept {}

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

        // Length --- NOTE (Lapys) -> Counts the characters until a null-terminal is reached.
        inline size_t string__length(char* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while ('\0' ^ *(string + length)) ++length; return length; } }
        inline size_t string__length(char const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while ('\0' ^ *(string + length)) ++length; return length; } }
        inline size_t string__length(char8_t* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        inline size_t string__length(char8_t const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        inline size_t string__length(char16_t* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        inline size_t string__length(char16_t const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        inline size_t string__length(char32_t* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        inline size_t string__length(char32_t const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (*(string + length)) ++length; return length; } }
        inline size_t string__length(signed char* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while ('\0' ^ *(string + length)) ++length; return length; } }
        inline size_t string__length(signed char const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while ('\0' ^ *(string + length)) ++length; return length; } }
        inline size_t string__length(unsigned char* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while ('\0' ^ *(string + length)) ++length; return length; } }
        inline size_t string__length(unsigned char const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while ('\0' ^ *(string + length)) ++length; return length; } }
        inline size_t string__length(wchar_t* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (L'\0' ^ *(string + length)) ++length; return length; } }
        inline size_t string__length(wchar_t const* const string) noexcept { if (NULL == string) return 0u; else { size_t length = 0u; while (L'\0' ^ *(string + length)) ++length; return length; } }

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
        template <size_t argumentLength> inline string::string(char (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && ('\0' ^ *(argument + iterator)); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(char const (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && ('\0' ^ *(argument + iterator)); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(char8_t (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && *(argument + iterator); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(char8_t const (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && *(argument + iterator); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(char16_t (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && *(argument + iterator); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(char16_t const (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && *(argument + iterator); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(char32_t (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && *(argument + iterator); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(char32_t const (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && *(argument + iterator); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(signed char (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && ('\0' ^ *(argument + iterator)); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(signed char const (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && ('\0' ^ *(argument + iterator)); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(unsigned char (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && ('\0' ^ *(argument + iterator)); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(unsigned char const (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && ('\0' ^ *(argument + iterator)); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(wchar_t (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && (L'\0' ^ *(argument + iterator)); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }
        template <size_t argumentLength> inline string::string(wchar_t const (&argument)[argumentLength]) : length{argumentLength}, value{NULL} { if (this -> length) { this -> value = pointer__allocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; (iterator ^ (this -> length)) && (L'\0' ^ *(argument + iterator)); ++iterator) *(this -> value + iterator) = *(argument + iterator); } }

        // [Destructor]
        string::~string(void) { pointer__free_heap_memory(this -> value); }

        // [Operator] > ... --- MINIFY (Lapys)
        inline string& string::operator =(char* const argument) noexcept { this -> length = string__length(argument); if (this -> length) { this -> value = pointer__reallocate_heap_memory(this -> length * sizeof(character)); for (size_t iterator = 0u; iterator ^ (this -> length); ++iterator) *(this -> value + iterator) = *(argument + iterator); } else { pointer__free_heap_memory(this -> value); this -> value = NULL; } return *this; }
        inline string& string::operator =(string& argument) noexcept { this -> value = argument.value; return *this; }
        inline string& string::operator =(string&& argument) noexcept { this -> value = argument.value; return *this; }
        inline string& string::operator =(string const& argument) noexcept { this -> value = argument.value; return *this; }
        inline string& string::operator =(string const&& argument) noexcept { this -> value = argument.value; return *this; }

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

        inline wide::operator wide_unsigned_type(void) const noexcept { return this -> value; }
