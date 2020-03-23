// + - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >>
// >>= <<= == != <= >= <=> (since C++20) && || ++ -- , ->* -> ( ) [ ]

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
        /* Namespace > ... */
        namespace Constants {}
        namespace Mathematics {}
        namespace Functions {}
        namespace Types {}

        /* Modification */
            /* Types */
            namespace Types {
                /* Definition > ... */
                typedef struct boolean boolean; // NOTE (Lapys) -> Boolean value abstraction.
                typedef struct character character; // NOTE (Lapys) -> Native character type wrapper.
                typedef struct fraction fraction; // NOTE (Lapys) -> Native non-integral & numeric type wrapper.
                typedef struct integer integer; // NOTE (Lapys) -> Native integral & numeric type wrapper.
                typedef struct null_pointer null_pointer; // NOTE (Lapys) -> Structural constant representation of null pointers.
                typedef struct number number; // NOTE (Lapys) -> Native numeric type wrapper.
                typedef struct object object; // NOTE (Lapys) -> Generic autonomously managed object type.
                typedef struct pointer pointer; // note (Lapys) -> Base representation of custom pointer classes.
                typedef struct primitive primitive; // NOTE (Lapys) -> Native type wrapper.
                typedef struct raw_pointer raw_pointer; // NOTE (Lapys) -> Native pointer (memory) type wrapper.
                                                                                        // WARN (Lapys) -> Only utilize as a store of value.
                typedef struct shared_smart_pointer shared_smart_pointer; // NOTE (Lapys) -> Frees pointer memory once all references are unfounded.
                                                                                                                            // WARN (Lapys) -> Only utilize as a store of value.
                typedef struct size size;
                typedef struct string string; // NOTE (Lapys) -> Native character array type wrapper.
                typedef struct unique_smart_pointer unique_smart_pointer; // NOTE (Lapys) -> Frees pointer memory.
                                                                                                                            // WARN (Lapys) -> Only utilize as a store of value.
            }

            /* Functions */
            namespace Functions {
                /* Definition > ... */
                enum array__memory_allocation_chunk_method {DOUBLING, FIBONACCI, LINEAR};
                enum array__sort_method {BINARY, BUBBLE, INSERT, MERGE, TIM};

                /* Declaration > ... */
                void array__add(...);
                void array__add_to_back(...);
                void array__add_to_front(...);
                void array__cut_at(...);
                void array__free(...);
                void array__index(...);
                void array__index_from_back(...);
                void array__index_from_front(...);
                void array__remove(...);
                void array__remove_from_back(...);
                void array__remove_from_front(...);
                void array__resize(...);
                void array__sort(...);

                inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const double);
                inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const float);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const long);
                inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const long double);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const unsigned int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const unsigned long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const unsigned long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const unsigned short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const LapysDevelopmentKit::Types::size);
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
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const LapysDevelopmentKit::Types::size);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const double);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const float);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const long double);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const unsigned int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const unsigned long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const unsigned long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const unsigned short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const LapysDevelopmentKit::Types::size);
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
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const LapysDevelopmentKit::Types::size);
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
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::boolean number__is_safe(const double);
                inline LapysDevelopmentKit::Types::boolean number__is_safe(const float);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const long);
                inline LapysDevelopmentKit::Types::boolean number__is_safe(const long double);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const unsigned int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const unsigned long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const unsigned long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const unsigned short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const double);
                inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const float);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const long);
                inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const long double);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const unsigned int);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const unsigned long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const unsigned long long);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const unsigned short);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const LapysDevelopmentKit::Types::size);
                void number__to_string(...);
                // x is NaN if and only if x != x.
                // x is NaN or an infinity if and only if x - x != 0.
                // x is a zero or an infinity if and only if x + x == x.
                // x is a zero if and only if x == 0.
                // If FLT_EVAL_METHOD is 0 or 1, then x is an infinity if and only if x + DBL_MAX == x.
                // x is positive infinity if and only if x + infinity == x.

                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&);
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&&);
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&);
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&&);
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&, const LapysDevelopmentKit::Types::size);
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&&, const LapysDevelopmentKit::Types::size);
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&, const LapysDevelopmentKit::Types::size);
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&&, const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&&);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&, const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&&, const LapysDevelopmentKit::Types::size);
                template <typename type> inline type* pointer__allocate_memory(type*&);
                template <typename type> inline type* pointer__allocate_memory(type*&, const LapysDevelopmentKit::Types::size size);
                void pointer__copy_memory(...);
                /*memcpy_s says, "Hmm, before I read from this address, let me verify for myself that it is not a null pointer; and before I write to this address, I shall perform that test again. I shall also compare the number of bytes I have been requested to copy to the claimed size of the destination; if and only if the call passes all these tests shall I perform the copy."

memcpy says "Stuff the destination into a register, stuff the source into a register, stuff the count into a register, perform MOVSB or MOVSW."*/
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(LapysDevelopmentKit::Types::null_pointer&);
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(LapysDevelopmentKit::Types::null_pointer&&);
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(const LapysDevelopmentKit::Types::null_pointer&);
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(const LapysDevelopmentKit::Types::null_pointer&&);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__free_memory(LapysDevelopmentKit::Types::raw_pointer&);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__free_memory(LapysDevelopmentKit::Types::raw_pointer&&);
                template <typename type> inline type* pointer__free_memory(type*&);
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__reallocate_memory(LapysDevelopmentKit::Types::null_pointer&, const LapysDevelopmentKit::Types::size);
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__reallocate_memory(LapysDevelopmentKit::Types::null_pointer&&, const LapysDevelopmentKit::Types::size);
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__reallocate_memory(const LapysDevelopmentKit::Types::null_pointer&, const LapysDevelopmentKit::Types::size);
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__reallocate_memory(const LapysDevelopmentKit::Types::null_pointer&&, const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__reallocate_memory(LapysDevelopmentKit::Types::raw_pointer&, const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__reallocate_memory(LapysDevelopmentKit::Types::raw_pointer&&, const LapysDevelopmentKit::Types::size);
                template <typename type> inline type* pointer__reallocate_memory(type*&, const LapysDevelopmentKit::Types::size);

                void string__clone(...);
                void string__concatenate(...);
                void string__copy(...);
                void string__create(...);
                void string__free(...);
                void string__is_empty(...);
                void string__length(...);
                void string__resize(...);
                void string__source_concatenate(...);
                void string__to_number(...);
                void string__to_ANSI(...);
                void string__to_UTF8(...);
                void string__to_UTF16(...);
                void string__to_UTF32(...);
                void string__to_wide(...);
            }

            /* Mathematics */
            namespace Mathematics {
                /* Declaration > ... */
                void absolute(...);
                void ceiling(...);
                void cosine(...);
                void floor(...);
                void fibonacci(...);
                /*# (Public) Returns F(n).
def fibonacci(n):
    if n < 0:
        raise ValueError("Negative arguments not implemented")
    return _fib(n)[0]


# (Private) Returns the tuple (F(n), F(n+1)).
def _fib(n):
    if n == 0:
        return (0, 1)
    else:
        a, b = _fib(n // 2)
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n % 2 == 0:
            return (c, d)
        else:
            return (d, c + d)*/
                void logarithm__base_2(...);
                void logarithm__base_10(...);
                void modulus(...);
                void power(...);
                void sine(...);
                void root(...);
                void tangent(...);

                void degrees_to_radians(...);
                void radians_to_degrees(...);
            }

            /* Constants */
            namespace Constants {
                /* Constants > ... */
                const unsigned long denormalizedBitRepresentation[2] = {0x00000001, 0x00000000}; // NOTE (Lapys) -> IEEE-754 hexadecimal form.
                const double denormalized  = *(double*) denormalizedBitRepresentation;

                const unsigned long indeterminateBitRepresentation[2] = {0x00000000, 0xFFF80000}; // NOTE (Lapys) -> IEEE-754 hexadecimal form.
                const double indeterminate  = *(double*) indeterminateBitRepresentation;

                const double infinity = INFINITY;
                const double NaN = NAN;
            }
    }

    /* Modification > Lapys Development Kit */
    namespace LapysDevelopmentKit {
        /* Shorthand */
        namespace LDKC = Constants;
        namespace LDKF = Functions;
        namespace LDKM = Mathematics;
        namespace LDKT = Types;

        /* Types */
        inline namespace Types {
            /* Class */
                /* Boolean */
                struct boolean {
                    /* ... */
                    friend character; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;

                    // [...]
                    private:
                        // Definition > Value
                        enum boolean_value : unsigned char {boolean_false = (false == true), boolean_true = !boolean_false} value : 8;

                    // [...]
                    public:
                        // [Constructor]
                        constexpr inline boolean(const unsigned char);
                        constexpr inline boolean(void);
                        constexpr inline boolean(boolean&);
                        constexpr inline boolean(boolean&&);
                        constexpr inline boolean(const boolean&);
                        constexpr inline boolean(const boolean&&);

                        // [Operator] > ...
                        constexpr inline boolean operator !(void) const;
                        constexpr inline boolean& operator =(boolean);

                        constexpr inline operator unsigned char(void) const;
                };

                /* Character */
                struct character {
                    /* ... */
                    friend boolean; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;
                };

                /* Fraction */
                struct fraction {
                    /* ... */
                    friend boolean; friend character; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;
                };

                /* Integer */
                struct integer {
                    /* ... */
                    friend boolean; friend character; friend fraction; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;
                };

                /* Number */
                struct number {
                    /* ... */
                    friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;
                };

                /* Object */
                struct object {
                    /* ... */
                    friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend number; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;
                };

                /* Pointer */
                struct pointer {
                    /* ... */
                    friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;

                    // [...]
                    private:
                        // [Operator] > ([*], [&], [->])
                        inline void operator *(void) const;
                        inline void operator &(void) const;
                        inline void operator ->(void) const;

                    // [...]
                    public:
                        // [Constructor]
                        constexpr inline pointer(void);
                        constexpr inline pointer(pointer&);
                        constexpr inline pointer(pointer&&);
                        constexpr inline pointer(const pointer&);
                        constexpr inline pointer(const pointer&&);

                        // [Operator] > ([=], [...])
                        constexpr inline void operator =(pointer) const;
                        template <typename type> constexpr inline operator type*(void) const;
                };
                    /* Null Pointer */
                    struct null_pointer : pointer {
                        /* ... */
                        friend boolean; friend character; friend fraction; friend integer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;

                        // [...]
                        private:
                            // [Operator] > ([*], [&], [->])
                            constexpr inline void operator *(void) const;
                            constexpr inline void operator &(void) const;
                            constexpr inline void operator ->(void) const;

                            // Declaration > ...
                            constexpr friend inline LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&);
                            constexpr friend inline LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&&);
                            constexpr friend inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&);
                            constexpr friend inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&&);
                            constexpr friend inline LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&, const LapysDevelopmentKit::Types::size);
                            constexpr friend inline LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&&, const LapysDevelopmentKit::Types::size);
                            constexpr friend inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&, const LapysDevelopmentKit::Types::size);
                            constexpr friend inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&&, const LapysDevelopmentKit::Types::size);
                            constexpr friend inline LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__free_memory(LapysDevelopmentKit::Types::null_pointer&);
                            constexpr friend inline LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__free_memory(LapysDevelopmentKit::Types::null_pointer&&);
                            constexpr friend inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__free_memory(const LapysDevelopmentKit::Types::null_pointer&);
                            constexpr friend inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__free_memory(const LapysDevelopmentKit::Types::null_pointer&&);
                            constexpr friend inline LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__reallocate_memory(LapysDevelopmentKit::Types::null_pointer&, const LapysDevelopmentKit::Types::size);
                            constexpr friend inline LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__reallocate_memory(LapysDevelopmentKit::Types::null_pointer&&, const LapysDevelopmentKit::Types::size);
                            constexpr friend inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__reallocate_memory(const LapysDevelopmentKit::Types::null_pointer&, const LapysDevelopmentKit::Types::size);
                            constexpr friend inline const LapysDevelopmentKit::Types::null_pointer& LapysDevelopmentKit::Functions::pointer__reallocate_memory(const LapysDevelopmentKit::Types::null_pointer&&, const LapysDevelopmentKit::Types::size);

                        // [...]
                        public:
                            // [Constructor]
                            constexpr inline null_pointer(void);
                            constexpr inline null_pointer(null_pointer&);
                            constexpr inline null_pointer(null_pointer&&);
                            constexpr inline null_pointer(const null_pointer&);
                            constexpr inline null_pointer(const null_pointer&&);

                            // [Operator] > ...
                            constexpr inline void operator +(const int) const;
                            constexpr friend inline void operator +(const int, null_pointer&);
                            constexpr friend inline void operator +(const int, null_pointer&&);
                            constexpr friend inline void operator +(const int, const null_pointer&);
                            constexpr friend inline void operator +(const int, const null_pointer&&);
                            constexpr inline void operator +(const long) const;
                            constexpr friend inline void operator +(const long, null_pointer&);
                            constexpr friend inline void operator +(const long, null_pointer&&);
                            constexpr friend inline void operator +(const long, const null_pointer&);
                            constexpr friend inline void operator +(const long, const null_pointer&&);
                            constexpr inline void operator +(const long long) const;
                            constexpr friend inline void operator +(const long long, null_pointer&);
                            constexpr friend inline void operator +(const long long, null_pointer&&);
                            constexpr friend inline void operator +(const long long, const null_pointer&);
                            constexpr friend inline void operator +(const long long, const null_pointer&&);
                            constexpr inline void operator +(const short) const;
                            constexpr friend inline void operator +(const short, null_pointer&);
                            constexpr friend inline void operator +(const short, null_pointer&&);
                            constexpr friend inline void operator +(const short, const null_pointer&);
                            constexpr friend inline void operator +(const short, const null_pointer&&);
                            constexpr inline void operator -(const int) const;
                            constexpr friend inline void operator -(const int, null_pointer&);
                            constexpr friend inline void operator -(const int, null_pointer&&);
                            constexpr friend inline void operator -(const int, const null_pointer&);
                            constexpr friend inline void operator -(const int, const null_pointer&&);
                            constexpr inline void operator -(const long) const;
                            constexpr friend inline void operator -(const long, null_pointer&);
                            constexpr friend inline void operator -(const long, null_pointer&&);
                            constexpr friend inline void operator -(const long, const null_pointer&);
                            constexpr friend inline void operator -(const long, const null_pointer&&);
                            constexpr inline void operator -(const long long) const;
                            constexpr friend inline void operator -(const long long, null_pointer&);
                            constexpr friend inline void operator -(const long long, null_pointer&&);
                            constexpr friend inline void operator -(const long long, const null_pointer&);
                            constexpr friend inline void operator -(const long long, const null_pointer&&);
                            constexpr inline void operator -(const short) const;
                            constexpr friend inline void operator -(const short, null_pointer&);
                            constexpr friend inline void operator -(const short, null_pointer&&);
                            constexpr friend inline void operator -(const short, const null_pointer&);
                            constexpr friend inline void operator -(const short, const null_pointer&&);
                            constexpr inline boolean operator !(void) const;
                            constexpr inline void operator =(null_pointer) const;
                            constexpr inline void operator +=(const int) const;
                            constexpr inline void operator +=(const long) const;
                            constexpr inline void operator +=(const long long) const;
                            constexpr inline void operator +=(const short) const;
                            constexpr inline void operator -=(const int) const;
                            constexpr inline void operator -=(const long) const;
                            constexpr inline void operator -=(const long long) const;
                            constexpr inline void operator -=(const short) const;
                            constexpr inline boolean operator ==(null_pointer&) const;
                            constexpr inline boolean operator ==(null_pointer&&) const;
                            constexpr inline boolean operator ==(const null_pointer&) const;
                            constexpr inline boolean operator ==(const null_pointer&&) const;
                            constexpr inline boolean operator ==(raw_pointer&) const;
                            constexpr inline boolean operator ==(raw_pointer&&) const;
                            constexpr inline boolean operator ==(const raw_pointer&) const;
                            constexpr inline boolean operator ==(const raw_pointer&&) const;
                            template <typename type> constexpr inline boolean operator ==(type*) const;
                            template <typename type> constexpr friend inline boolean operator ==(type*, null_pointer&);
                            template <typename type> constexpr friend inline boolean operator ==(type*, null_pointer&&);
                            template <typename type> constexpr friend inline boolean operator ==(type*, const null_pointer&);
                            template <typename type> constexpr friend inline boolean operator ==(type*, const null_pointer&&);
                            constexpr inline boolean operator !=(null_pointer&) const;
                            constexpr inline boolean operator !=(null_pointer&&) const;
                            constexpr inline boolean operator !=(const null_pointer&) const;
                            constexpr inline boolean operator !=(const null_pointer&&) const;
                            constexpr inline boolean operator !=(raw_pointer&) const;
                            constexpr inline boolean operator !=(raw_pointer&&) const;
                            constexpr inline boolean operator !=(const raw_pointer&) const;
                            constexpr inline boolean operator !=(const raw_pointer&&) const;
                            template <typename type> constexpr inline boolean operator !=(type*) const;
                            template <typename type> constexpr friend inline boolean operator !=(type*, null_pointer&);
                            template <typename type> constexpr friend inline boolean operator !=(type*, null_pointer&&);
                            template <typename type> constexpr friend inline boolean operator !=(type*, const null_pointer&);
                            template <typename type> constexpr friend inline boolean operator !=(type*, const null_pointer&&);
                            constexpr inline boolean operator &&(null_pointer&) const;
                            constexpr inline boolean operator &&(null_pointer&&) const;
                            constexpr inline boolean operator &&(const null_pointer&) const;
                            constexpr inline boolean operator &&(const null_pointer&&) const;
                            constexpr inline boolean operator &&(raw_pointer&) const;
                            constexpr inline boolean operator &&(raw_pointer&&) const;
                            constexpr inline boolean operator &&(const raw_pointer&) const;
                            constexpr inline boolean operator &&(const raw_pointer&&) const;
                            template <typename type> constexpr inline boolean operator &&(type) const;
                            template <typename type> constexpr friend inline boolean operator &&(type, null_pointer&);
                            template <typename type> constexpr friend inline boolean operator &&(type, null_pointer&&);
                            template <typename type> constexpr friend inline boolean operator &&(type, const null_pointer&);
                            template <typename type> constexpr friend inline boolean operator &&(type, const null_pointer&&);
                            constexpr inline boolean operator ||(null_pointer&) const;
                            constexpr inline boolean operator ||(null_pointer&&) const;
                            constexpr inline boolean operator ||(const null_pointer&) const;
                            constexpr inline boolean operator ||(const null_pointer&&) const;
                            constexpr inline boolean operator ||(raw_pointer&) const;
                            constexpr inline boolean operator ||(raw_pointer&&) const;
                            constexpr inline boolean operator ||(const raw_pointer&) const;
                            constexpr inline boolean operator ||(const raw_pointer&&) const;
                            template <typename type> constexpr inline boolean operator ||(type) const;
                            template <typename type> constexpr friend inline boolean operator ||(type, null_pointer&);
                            template <typename type> constexpr friend inline boolean operator ||(type, null_pointer&&);
                            template <typename type> constexpr friend inline boolean operator ||(type, const null_pointer&);
                            template <typename type> constexpr friend inline boolean operator ||(type, const null_pointer&&);
                            constexpr inline void operator ++(int) const;
                            constexpr inline void operator ++(void) const;
                            constexpr inline void operator --(int) const;
                            constexpr inline void operator --(void) const;
                            template <typename type> constexpr inline operator type*(void) const;
                    };

                    /* Raw Pointer */
                    struct raw_pointer : pointer {
                        /* ... */
                        friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;

                        // [...]
                        private:
                            // Definition > Value
                            void *value;

                            // Declaration > ...
                            friend inline LapysDevelopmentKit::Types::raw_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&);
                            friend inline LapysDevelopmentKit::Types::raw_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&&);
                            friend inline LapysDevelopmentKit::Types::raw_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&, const LapysDevelopmentKit::Types::size);
                            friend inline LapysDevelopmentKit::Types::raw_pointer& LapysDevelopmentKit::Functions::pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&&, const LapysDevelopmentKit::Types::size);
                            friend inline LapysDevelopmentKit::Types::raw_pointer& LapysDevelopmentKit::Functions::pointer__free_memory(LapysDevelopmentKit::Types::raw_pointer&);
                            friend inline LapysDevelopmentKit::Types::raw_pointer& LapysDevelopmentKit::Functions::pointer__free_memory(LapysDevelopmentKit::Types::raw_pointer&&);
                            friend inline LapysDevelopmentKit::Types::raw_pointer& LapysDevelopmentKit::Functions::pointer__reallocate_memory(LapysDevelopmentKit::Types::raw_pointer&, const LapysDevelopmentKit::Types::size);
                            friend inline LapysDevelopmentKit::Types::raw_pointer& LapysDevelopmentKit::Functions::pointer__reallocate_memory(LapysDevelopmentKit::Types::raw_pointer&&, const LapysDevelopmentKit::Types::size);

                        // [...]
                        public:
                            // [Constructor]
                            constexpr inline raw_pointer(void);
                            constexpr inline raw_pointer(void*);
                            constexpr inline raw_pointer(const void*);
                            template <typename type> constexpr inline raw_pointer(type*);
                            constexpr inline raw_pointer(null_pointer&);
                            constexpr inline raw_pointer(null_pointer&&);
                            constexpr inline raw_pointer(const null_pointer&);
                            constexpr inline raw_pointer(const null_pointer&&);
                            constexpr inline raw_pointer(raw_pointer&);
                            constexpr inline raw_pointer(raw_pointer&&);
                            constexpr inline raw_pointer(const raw_pointer&);
                            constexpr inline raw_pointer(const raw_pointer&&);

                            // [Operator] > ...
                            constexpr inline raw_pointer operator +(const int) const;
                            constexpr friend inline raw_pointer operator +(const int, raw_pointer&);
                            constexpr friend inline raw_pointer operator +(const int, raw_pointer&&);
                            constexpr friend inline raw_pointer operator +(const int, const raw_pointer&);
                            constexpr friend inline raw_pointer operator +(const int, const raw_pointer&&);
                            constexpr inline raw_pointer operator +(const long) const;
                            constexpr friend inline raw_pointer operator +(const long, raw_pointer&);
                            constexpr friend inline raw_pointer operator +(const long, raw_pointer&&);
                            constexpr friend inline raw_pointer operator +(const long, const raw_pointer&);
                            constexpr friend inline raw_pointer operator +(const long, const raw_pointer&&);
                            constexpr inline raw_pointer operator +(const long long) const;
                            constexpr friend inline raw_pointer operator +(const long long, raw_pointer&);
                            constexpr friend inline raw_pointer operator +(const long long, raw_pointer&&);
                            constexpr friend inline raw_pointer operator +(const long long, const raw_pointer&);
                            constexpr friend inline raw_pointer operator +(const long long, const raw_pointer&&);
                            constexpr inline raw_pointer operator +(const short) const;
                            constexpr friend inline raw_pointer operator +(const short, raw_pointer&);
                            constexpr friend inline raw_pointer operator +(const short, raw_pointer&&);
                            constexpr friend inline raw_pointer operator +(const short, const raw_pointer&);
                            constexpr friend inline raw_pointer operator +(const short, const raw_pointer&&);
                            constexpr inline raw_pointer operator -(const int) const;
                            constexpr friend inline raw_pointer operator -(const int, raw_pointer&);
                            constexpr friend inline raw_pointer operator -(const int, raw_pointer&&);
                            constexpr friend inline raw_pointer operator -(const int, const raw_pointer&);
                            constexpr friend inline raw_pointer operator -(const int, const raw_pointer&&);
                            constexpr inline raw_pointer operator -(const long) const;
                            constexpr friend inline raw_pointer operator -(const long, raw_pointer&);
                            constexpr friend inline raw_pointer operator -(const long, raw_pointer&&);
                            constexpr friend inline raw_pointer operator -(const long, const raw_pointer&);
                            constexpr friend inline raw_pointer operator -(const long, const raw_pointer&&);
                            constexpr inline raw_pointer operator -(const long long) const;
                            constexpr friend inline raw_pointer operator -(const long long, raw_pointer&);
                            constexpr friend inline raw_pointer operator -(const long long, raw_pointer&&);
                            constexpr friend inline raw_pointer operator -(const long long, const raw_pointer&);
                            constexpr friend inline raw_pointer operator -(const long long, const raw_pointer&&);
                            constexpr inline raw_pointer operator -(const short) const;
                            constexpr friend inline raw_pointer operator -(const short, raw_pointer&);
                            constexpr friend inline raw_pointer operator -(const short, raw_pointer&&);
                            constexpr friend inline raw_pointer operator -(const short, const raw_pointer&);
                            constexpr friend inline raw_pointer operator -(const short, const raw_pointer&&);
                            constexpr inline boolean operator !(void) const;
                            constexpr inline raw_pointer& operator =(raw_pointer);
                            constexpr inline raw_pointer& operator +=(const int);
                            constexpr inline raw_pointer& operator +=(const long);
                            constexpr inline raw_pointer& operator +=(const long long);
                            constexpr inline raw_pointer& operator +=(const short);
                            constexpr inline raw_pointer& operator -=(const int);
                            constexpr inline raw_pointer& operator -=(const long);
                            constexpr inline raw_pointer& operator -=(const long long);
                            constexpr inline raw_pointer& operator -=(const short);
                            constexpr inline boolean operator ==(null_pointer&) const;
                            constexpr inline boolean operator ==(null_pointer&&) const;
                            constexpr inline boolean operator ==(const null_pointer&) const;
                            constexpr inline boolean operator ==(const null_pointer&&) const;
                            constexpr inline boolean operator ==(raw_pointer&) const;
                            constexpr inline boolean operator ==(raw_pointer&&) const;
                            constexpr inline boolean operator ==(const raw_pointer&) const;
                            constexpr inline boolean operator ==(const raw_pointer&&) const;
                            template <typename type> constexpr inline boolean operator ==(type*) const;
                            template <typename type> constexpr friend inline boolean operator ==(type*, raw_pointer&);
                            template <typename type> constexpr friend inline boolean operator ==(type*, raw_pointer&&);
                            template <typename type> constexpr friend inline boolean operator ==(type*, const raw_pointer&);
                            template <typename type> constexpr friend inline boolean operator ==(type*, const raw_pointer&&);
                            constexpr inline boolean operator !=(null_pointer&) const;
                            constexpr inline boolean operator !=(null_pointer&&) const;
                            constexpr inline boolean operator !=(const null_pointer&) const;
                            constexpr inline boolean operator !=(const null_pointer&&) const;
                            constexpr inline boolean operator !=(raw_pointer&) const;
                            constexpr inline boolean operator !=(raw_pointer&&) const;
                            constexpr inline boolean operator !=(const raw_pointer&) const;
                            constexpr inline boolean operator !=(const raw_pointer&&) const;
                            template <typename type> constexpr inline boolean operator !=(type*) const;
                            template <typename type> constexpr friend inline boolean operator !=(type*, raw_pointer&);
                            template <typename type> constexpr friend inline boolean operator !=(type*, raw_pointer&&);
                            template <typename type> constexpr friend inline boolean operator !=(type*, const raw_pointer&);
                            template <typename type> constexpr friend inline boolean operator !=(type*, const raw_pointer&&);
                            constexpr inline boolean operator &&(null_pointer&) const;
                            constexpr inline boolean operator &&(null_pointer&&) const;
                            constexpr inline boolean operator &&(const null_pointer&) const;
                            constexpr inline boolean operator &&(const null_pointer&&) const;
                            constexpr inline boolean operator &&(raw_pointer&) const;
                            constexpr inline boolean operator &&(raw_pointer&&) const;
                            constexpr inline boolean operator &&(const raw_pointer&) const;
                            constexpr inline boolean operator &&(const raw_pointer&&) const;
                            template <typename type> constexpr inline boolean operator &&(type) const;
                            template <typename type> constexpr friend inline boolean operator &&(type, raw_pointer&);
                            template <typename type> constexpr friend inline boolean operator &&(type, raw_pointer&&);
                            template <typename type> constexpr friend inline boolean operator &&(type, const raw_pointer&);
                            template <typename type> constexpr friend inline boolean operator &&(type, const raw_pointer&&);
                            constexpr inline boolean operator ||(null_pointer&) const;
                            constexpr inline boolean operator ||(null_pointer&&) const;
                            constexpr inline boolean operator ||(const null_pointer&) const;
                            constexpr inline boolean operator ||(const null_pointer&&) const;
                            constexpr inline boolean operator ||(raw_pointer&) const;
                            constexpr inline boolean operator ||(raw_pointer&&) const;
                            constexpr inline boolean operator ||(const raw_pointer&) const;
                            constexpr inline boolean operator ||(const raw_pointer&&) const;
                            template <typename type> constexpr inline boolean operator ||(type) const;
                            template <typename type> constexpr friend inline boolean operator ||(type, raw_pointer&);
                            template <typename type> constexpr friend inline boolean operator ||(type, raw_pointer&&);
                            template <typename type> constexpr friend inline boolean operator ||(type, const raw_pointer&);
                            template <typename type> constexpr friend inline boolean operator ||(type, const raw_pointer&&);
                            constexpr inline raw_pointer& operator ++(int);
                            constexpr inline raw_pointer& operator ++(void);
                            constexpr inline raw_pointer& operator --(int);
                            constexpr inline raw_pointer& operator --(void);
                            template <typename type> constexpr inline operator type*(void) const;
                    };
                        /* Shared Pointer */
                        struct shared_smart_pointer : raw_pointer {
                            /* ... */
                            friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend size; friend string; friend unique_smart_pointer;
                        };

                        /* Unique Pointer */
                        struct unique_smart_pointer : raw_pointer {
                            /* ... */
                            friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend string;
                        };

                /* Primitive */
                struct primitive {
                    /* ... */
                    friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend raw_pointer; friend shared_smart_pointer; friend size; friend string; friend unique_smart_pointer;
                };

                /* Size */
                struct size {
                    /* ... */
                    friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend string; friend unique_smart_pointer;

                    // [...]
                    private:
                        // Definition > Value
                        std::size_t value;

                    // [...]
                    public:
                        // [Constructor]
                        constexpr inline size(const double);
                        constexpr inline size(const float);
                        constexpr inline size(const int);
                        constexpr inline size(const long);
                        constexpr inline size(const long double);
                        constexpr inline size(const long long);
                        constexpr inline size(const short);
                        constexpr inline size(const unsigned int);
                        constexpr inline size(const unsigned long);
                        constexpr inline size(const unsigned long long);
                        constexpr inline size(const unsigned short);
                        constexpr inline size(fraction&);
                        constexpr inline size(fraction&&);
                        constexpr inline size(const fraction&);
                        constexpr inline size(const fraction&&);
                        constexpr inline size(integer&);
                        constexpr inline size(integer&&);
                        constexpr inline size(const integer&);
                        constexpr inline size(const integer&&);
                        constexpr inline size(number&);
                        constexpr inline size(number&&);
                        constexpr inline size(const number&);
                        constexpr inline size(const number&&);
                        constexpr inline size(size&);
                        constexpr inline size(size&&);
                        constexpr inline size(const size&);
                        constexpr inline size(const size&&);

                        // [Operator] > ... --- UPDATE (Lapys)
                        constexpr inline operator std::size_t(void) const;
                };

                /* String */
                struct string {
                    /* ... */
                    friend boolean; friend character; friend fraction; friend integer; friend null_pointer; friend number; friend object; friend pointer; friend primitive; friend raw_pointer; friend shared_smart_pointer; friend size; friend unique_smart_pointer;
                };
        }

        /* Types */
        inline namespace Types {
            /* Modification */
                /* Boolean */
                    // [Constructor]
                    constexpr inline boolean::boolean(const unsigned char argument) : value{argument ? this -> boolean_true : this -> boolean_false} {}
                    constexpr inline boolean::boolean(void) : value{this -> boolean_false} {}
                    constexpr inline boolean::boolean(boolean& argument) : value{argument.value} {}
                    constexpr inline boolean::boolean(boolean&& argument) : value{argument.value} {}
                    constexpr inline boolean::boolean(const boolean& argument) : value{argument.value} {}
                    constexpr inline boolean::boolean(const boolean&& argument) : value{argument.value} {}

                    // [Operator] > ...
                    constexpr inline boolean boolean::operator !(void) const { return this -> value == this -> boolean_false; }
                    constexpr inline boolean& boolean::operator =(boolean argument) { this -> value = argument.value; return *this; }

                    constexpr inline boolean::operator unsigned char(void) const { return this -> boolean_true == this -> value; }

                /* Null Pointer > ([Constructor], [Operator] > ...) */
                constexpr inline null_pointer::null_pointer(void) {}

                constexpr inline boolean null_pointer::operator !(void) const { return false; }
                constexpr inline boolean null_pointer::operator ==(null_pointer&) const { return true; }
                constexpr inline boolean null_pointer::operator ==(null_pointer&&) const { return true; }
                constexpr inline boolean null_pointer::operator ==(const null_pointer&) const { return true; }
                constexpr inline boolean null_pointer::operator ==(const null_pointer&&) const { return true; }
                constexpr inline boolean null_pointer::operator ==(raw_pointer& argument) const { return NULL == argument.value; }
                constexpr inline boolean null_pointer::operator ==(raw_pointer&& argument) const { return NULL == argument.value; }
                constexpr inline boolean null_pointer::operator ==(const raw_pointer& argument) const { return NULL == argument.value; }
                constexpr inline boolean null_pointer::operator ==(const raw_pointer&& argument) const { return NULL == argument.value; }
                template <typename type> constexpr inline boolean null_pointer::operator ==(type* argument) const { return 0x0 == argument; }
                template <typename type> constexpr inline boolean operator ==(type* argumentA, null_pointer&) { return argumentA == 0x0; }
                template <typename type> constexpr inline boolean operator ==(type* argumentA, null_pointer&&) { return argumentA == 0x0; }
                template <typename type> constexpr inline boolean operator ==(type* argumentA, const null_pointer&) { return argumentA == 0x0; }
                template <typename type> constexpr inline boolean operator ==(type* argumentA, const null_pointer&&) { return argumentA == 0x0; }
                constexpr inline boolean null_pointer::operator !=(null_pointer&) const { return false; }
                constexpr inline boolean null_pointer::operator !=(null_pointer&&) const { return false; }
                constexpr inline boolean null_pointer::operator !=(const null_pointer&) const { return false; }
                constexpr inline boolean null_pointer::operator !=(const null_pointer&&) const { return false; }
                constexpr inline boolean null_pointer::operator !=(raw_pointer& argument) const { return NULL != argument.value; }
                constexpr inline boolean null_pointer::operator !=(raw_pointer&& argument) const { return NULL != argument.value; }
                constexpr inline boolean null_pointer::operator !=(const raw_pointer& argument) const { return NULL != argument.value; }
                constexpr inline boolean null_pointer::operator !=(const raw_pointer&& argument) const { return NULL != argument.value; }
                template <typename type> constexpr inline boolean null_pointer::operator !=(type* argument) const { return 0x0 != argument; }
                template <typename type> constexpr inline boolean operator !=(type* argumentA, null_pointer&) { return argumentA == 0x0; }
                template <typename type> constexpr inline boolean operator !=(type* argumentA, null_pointer&&) { return argumentA == 0x0; }
                template <typename type> constexpr inline boolean operator !=(type* argumentA, const null_pointer&) { return argumentA == 0x0; }
                template <typename type> constexpr inline boolean operator !=(type* argumentA, const null_pointer&&) { return argumentA == 0x0; }
                constexpr inline boolean null_pointer::operator &&(null_pointer&) const { return false; }
                constexpr inline boolean null_pointer::operator &&(null_pointer&&) const { return false; }
                constexpr inline boolean null_pointer::operator &&(const null_pointer&) const { return false; }
                constexpr inline boolean null_pointer::operator &&(const null_pointer&&) const { return false; }
                constexpr inline boolean null_pointer::operator &&(raw_pointer&) const { return false; }
                constexpr inline boolean null_pointer::operator &&(raw_pointer&&) const { return false; }
                constexpr inline boolean null_pointer::operator &&(const raw_pointer&) const { return false; }
                constexpr inline boolean null_pointer::operator &&(const raw_pointer&&) const { return false; }
                template <typename type> constexpr inline boolean null_pointer::operator &&(type) const { return false; }
                template <typename type> constexpr inline boolean operator &&(type, null_pointer&) { return false; }
                template <typename type> constexpr inline boolean operator &&(type, null_pointer&&) { return false; }
                template <typename type> constexpr inline boolean operator &&(type, const null_pointer&) { return false; }
                template <typename type> constexpr inline boolean operator &&(type, const null_pointer&&) { return false; }
                constexpr inline boolean null_pointer::operator ||(null_pointer&) const { return false; }
                constexpr inline boolean null_pointer::operator ||(null_pointer&&) const { return false; }
                constexpr inline boolean null_pointer::operator ||(const null_pointer&) const { return false; }
                constexpr inline boolean null_pointer::operator ||(const null_pointer&&) const { return false; }
                constexpr inline boolean null_pointer::operator ||(raw_pointer& argument) const { return NULL != argument.value; }
                constexpr inline boolean null_pointer::operator ||(raw_pointer&& argument) const { return NULL != argument.value; }
                constexpr inline boolean null_pointer::operator ||(const raw_pointer& argument) const { return NULL != argument.value; }
                constexpr inline boolean null_pointer::operator ||(const raw_pointer&& argument) const { return NULL != argument.value; }
                template <typename type> constexpr inline boolean null_pointer::operator ||(type argument) const { return argument; }
                template <typename type> constexpr inline boolean operator ||(type argument, null_pointer&) { return argument; }
                template <typename type> constexpr inline boolean operator ||(type argument, null_pointer&&) { return argument; }
                template <typename type> constexpr inline boolean operator ||(type argument, const null_pointer&) { return argument; }
                template <typename type> constexpr inline boolean operator ||(type argument, const null_pointer&&) { return argument; }
                template <typename type> constexpr inline null_pointer::operator type*(void) const { return 0x0; }

                /* Pointer > [Constructor] */
                constexpr inline pointer::pointer(void) {}

                /* Raw Pointer */
                    // [Constructor]
                    constexpr inline raw_pointer::raw_pointer(void) : value{NULL} {}
                    constexpr inline raw_pointer::raw_pointer(void* argument) : value{argument} {}
                    constexpr inline raw_pointer::raw_pointer(const void* argument) : value{(void*) argument} {}
                    template <typename type> constexpr inline raw_pointer::raw_pointer(type* argument) : value{(void*) argument} {}
                    constexpr inline raw_pointer::raw_pointer(null_pointer&) : value{NULL} {}
                    constexpr inline raw_pointer::raw_pointer(null_pointer&&) : value{NULL} {}
                    constexpr inline raw_pointer::raw_pointer(const null_pointer&) : value{NULL} {}
                    constexpr inline raw_pointer::raw_pointer(const null_pointer&&) : value{NULL} {}
                    constexpr inline raw_pointer::raw_pointer(raw_pointer& argument) : pointer{}, value{argument.value} {}
                    constexpr inline raw_pointer::raw_pointer(raw_pointer&& argument) : pointer{}, value{argument.value} {}
                    constexpr inline raw_pointer::raw_pointer(const raw_pointer& argument) : pointer{}, value{argument.value} {}
                    constexpr inline raw_pointer::raw_pointer(const raw_pointer&& argument) : pointer{}, value{argument.value} {}

                    // [Operator] > ...
                    constexpr inline raw_pointer raw_pointer::operator +(const int argument) const { return ((void**) this -> value) + argument; }
                    constexpr inline raw_pointer operator +(const int argumentA, raw_pointer& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const int argumentA, raw_pointer&& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const int argumentA, const raw_pointer& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const int argumentA, const raw_pointer&& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer raw_pointer::operator +(const long argument) const { return ((void**) this -> value) + argument; }
                    constexpr inline raw_pointer operator +(const long argumentA, raw_pointer& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const long argumentA, raw_pointer&& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const long argumentA, const raw_pointer& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const long argumentA, const raw_pointer&& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer raw_pointer::operator +(const long long argument) const { return ((void**) this -> value) + argument; }
                    constexpr inline raw_pointer operator +(const long long argumentA, raw_pointer& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const long long argumentA, raw_pointer&& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const long long argumentA, const raw_pointer& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const long long argumentA, const raw_pointer&& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer raw_pointer::operator +(const short argument) const { return ((void**) this -> value) + argument; }
                    constexpr inline raw_pointer operator +(const short argumentA, raw_pointer& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const short argumentA, raw_pointer&& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const short argumentA, const raw_pointer& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator +(const short argumentA, const raw_pointer&& argumentB) { return argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer raw_pointer::operator -(const int argument) const { return ((void**) this -> value) + -argument; }
                    constexpr inline raw_pointer operator -(const int argumentA, raw_pointer& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const int argumentA, raw_pointer&& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const int argumentA, const raw_pointer& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const int argumentA, const raw_pointer&& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer raw_pointer::operator -(const long argument) const { return ((void**) this -> value) + -argument; }
                    constexpr inline raw_pointer operator -(const long argumentA, raw_pointer& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const long argumentA, raw_pointer&& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const long argumentA, const raw_pointer& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const long argumentA, const raw_pointer&& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer raw_pointer::operator -(const long long argument) const { return ((void**) this -> value) + -argument; }
                    constexpr inline raw_pointer operator -(const long long argumentA, raw_pointer& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const long long argumentA, raw_pointer&& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const long long argumentA, const raw_pointer& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const long long argumentA, const raw_pointer&& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer raw_pointer::operator -(const short argument) const { return ((void**) this -> value) + -argument; }
                    constexpr inline raw_pointer operator -(const short argumentA, raw_pointer& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const short argumentA, raw_pointer&& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const short argumentA, const raw_pointer& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline raw_pointer operator -(const short argumentA, const raw_pointer&& argumentB) { return -argumentA + (void**) argumentB.value; }
                    constexpr inline boolean raw_pointer::operator !(void) const { return NULL != this -> value; }
                    constexpr inline raw_pointer& raw_pointer::operator =(raw_pointer argument) { this -> value = argument.value; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator +=(const int argument) { this -> value = ((void**) this -> value) + argument; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator +=(const long argument) { this -> value = ((void**) this -> value) + argument; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator +=(const long long argument) { this -> value = ((void**) this -> value) + argument; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator +=(const short argument) { this -> value = ((void**) this -> value) + argument; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator -=(const int argument) { this -> value = ((void**) this -> value) + -argument; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator -=(const long argument) { this -> value = ((void**) this -> value) + -argument; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator -=(const long long argument) { this -> value = ((void**) this -> value) + -argument; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator -=(const short argument) { this -> value = ((void**) this -> value) + -argument; return *this; }
                    constexpr inline boolean raw_pointer::operator ==(null_pointer&) const { return NULL == this -> value; }
                    constexpr inline boolean raw_pointer::operator ==(null_pointer&&) const { return NULL == this -> value; }
                    constexpr inline boolean raw_pointer::operator ==(const null_pointer&) const { return NULL == this -> value; }
                    constexpr inline boolean raw_pointer::operator ==(const null_pointer&&) const { return NULL == this -> value; }
                    constexpr inline boolean raw_pointer::operator ==(raw_pointer& argument) const { return this -> value == argument.value; }
                    constexpr inline boolean raw_pointer::operator ==(raw_pointer&& argument) const { return this -> value == argument.value; }
                    constexpr inline boolean raw_pointer::operator ==(const raw_pointer& argument) const { return this -> value == argument.value; }
                    constexpr inline boolean raw_pointer::operator ==(const raw_pointer&& argument) const { return this -> value == argument.value; }
                    template <typename type> constexpr inline boolean raw_pointer::operator ==(type* argument) const { return this -> value == argument; }
                    template <typename type> constexpr inline boolean operator ==(type* argumentA, raw_pointer& argumentB) { return argumentA == argumentB.value;    }
                    template <typename type> constexpr inline boolean operator ==(type* argumentA, raw_pointer&& argumentB) { return argumentA == argumentB.value; }
                    template <typename type> constexpr inline boolean operator ==(type* argumentA, const raw_pointer& argumentB) { return argumentA == argumentB.value; }
                    template <typename type> constexpr inline boolean operator ==(type* argumentA, const raw_pointer&& argumentB) { return argumentA == argumentB.value; }
                    constexpr inline boolean raw_pointer::operator !=(null_pointer&) const { return NULL == this -> value; }
                    constexpr inline boolean raw_pointer::operator !=(null_pointer&&) const { return NULL == this -> value; }
                    constexpr inline boolean raw_pointer::operator !=(const null_pointer&) const { return NULL == this -> value; }
                    constexpr inline boolean raw_pointer::operator !=(const null_pointer&&) const { return NULL == this -> value; }
                    constexpr inline boolean raw_pointer::operator !=(raw_pointer& argument) const { return this -> value == argument.value; }
                    constexpr inline boolean raw_pointer::operator !=(raw_pointer&& argument) const { return this -> value == argument.value; }
                    constexpr inline boolean raw_pointer::operator !=(const raw_pointer& argument) const { return this -> value == argument.value; }
                    constexpr inline boolean raw_pointer::operator !=(const raw_pointer&& argument) const { return this -> value == argument.value; }
                    template <typename type> constexpr inline boolean raw_pointer::operator !=(type* argument) const { return this -> value == argument; }
                    template <typename type> constexpr inline boolean operator !=(type* argumentA, raw_pointer& argumentB) { return argumentA == argumentB.value; }
                    template <typename type> constexpr inline boolean operator !=(type* argumentA, raw_pointer&& argumentB) { return argumentA == argumentB.value; }
                    template <typename type> constexpr inline boolean operator !=(type* argumentA, const raw_pointer& argumentB) { return argumentA == argumentB.value; }
                    template <typename type> constexpr inline boolean operator !=(type* argumentA, const raw_pointer&& argumentB) { return argumentA == argumentB.value; }
                    constexpr inline boolean raw_pointer::operator &&(null_pointer&) const { return false; }
                    constexpr inline boolean raw_pointer::operator &&(null_pointer&&) const { return false; }
                    constexpr inline boolean raw_pointer::operator &&(const null_pointer&) const { return false; }
                    constexpr inline boolean raw_pointer::operator &&(const null_pointer&&) const { return false; }
                    constexpr inline boolean raw_pointer::operator &&(raw_pointer& argument) const { return this -> value && argument.value; }
                    constexpr inline boolean raw_pointer::operator &&(raw_pointer&& argument) const { return this -> value && argument.value; }
                    constexpr inline boolean raw_pointer::operator &&(const raw_pointer& argument) const { return this -> value && argument.value; }
                    constexpr inline boolean raw_pointer::operator &&(const raw_pointer&& argument) const { return this -> value && argument.value; }
                    template <typename type> constexpr inline boolean raw_pointer::operator &&(type argument) const { return this -> value && argument; }
                    template <typename type> constexpr inline boolean operator &&(type argumentA, raw_pointer& argumentB) { return argumentA && argumentB.value; }
                    template <typename type> constexpr inline boolean operator &&(type argumentA, raw_pointer&& argumentB) { return argumentA && argumentB.value; }
                    template <typename type> constexpr inline boolean operator &&(type argumentA, const raw_pointer& argumentB) { return argumentA && argumentB.value; }
                    template <typename type> constexpr inline boolean operator &&(type argumentA, const raw_pointer&& argumentB) { return argumentA && argumentB.value; }
                    constexpr inline boolean raw_pointer::operator ||(null_pointer&) const { return NULL != this -> value; }
                    constexpr inline boolean raw_pointer::operator ||(null_pointer&&) const { return NULL != this -> value; }
                    constexpr inline boolean raw_pointer::operator ||(const null_pointer&) const { return NULL != this -> value; }
                    constexpr inline boolean raw_pointer::operator ||(const null_pointer&&) const { return NULL != this -> value; }
                    constexpr inline boolean raw_pointer::operator ||(raw_pointer& argument) const { return this -> value || argument.value; }
                    constexpr inline boolean raw_pointer::operator ||(raw_pointer&& argument) const { return this -> value || argument.value; }
                    constexpr inline boolean raw_pointer::operator ||(const raw_pointer& argument) const { return this -> value || argument.value; }
                    constexpr inline boolean raw_pointer::operator ||(const raw_pointer&& argument) const { return this -> value || argument.value; }
                    template <typename type> constexpr inline boolean raw_pointer::operator ||(type argument) const { return this -> value || argument; }
                    template <typename type> constexpr inline boolean operator ||(type argumentA, raw_pointer& argumentB) { return argumentA || argumentB.value; }
                    template <typename type> constexpr inline boolean operator ||(type argumentA, raw_pointer&& argumentB) { return argumentA || argumentB.value; }
                    template <typename type> constexpr inline boolean operator ||(type argumentA, const raw_pointer& argumentB) { return argumentA || argumentB.value; }
                    template <typename type> constexpr inline boolean operator ||(type argumentA, const raw_pointer&& argumentB) { return argumentA || argumentB.value; }
                    constexpr inline raw_pointer& raw_pointer::operator ++(int) { this -> value = 1 + ((void**) this -> value); return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator ++(void) { this -> value = ((void**) this -> value) + 1; return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator --(int) { this -> value = -1 + ((void**) this -> value); return *this; }
                    constexpr inline raw_pointer& raw_pointer::operator --(void) { this -> value = ((void**) this -> value) + -1; return *this; }
                    template <typename type> constexpr inline raw_pointer::operator type*(void) const { return (type*) this -> value; }
        }

        /* Constants */
        inline namespace Constants {
            /* Constant > Null */
            constexpr const null_pointer null {};
        }

        /* Functions */
        inline namespace Functions {
            /* Function */
                // Number Is ...
                inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const double number) { return number == LapysDevelopmentKit::Constants::denormalized || (number != 0 && std::fabs(number) <= DBL_MIN) || 0 == ::memcmp(&number, &LapysDevelopmentKit::Constants::denormalized, sizeof(double)); }
                inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const float number) { return number == LapysDevelopmentKit::Constants::denormalized || (number != 0 && std::fabs(number) <= FLT_MIN); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const long) { return false; }
                inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const long double number) { return number == LapysDevelopmentKit::Constants::denormalized || (number != 0 && std::fabs(number) <= LDBL_MIN); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const unsigned int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const unsigned long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const unsigned long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const unsigned short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_denormalized(const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::boolean number__is_finite(const double number) { return !LapysDevelopmentKit::Functions::number__is_infinite(number); }
                inline LapysDevelopmentKit::Types::boolean number__is_finite(const float number) { return !LapysDevelopmentKit::Functions::number__is_infinite(number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const int) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const long) { return true; }
                inline LapysDevelopmentKit::Types::boolean number__is_finite(const long double number) { return !LapysDevelopmentKit::Functions::number__is_infinite(number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const long long) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const short) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const unsigned int) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const unsigned long) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const unsigned long long) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const unsigned short) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_finite(const LapysDevelopmentKit::Types::size);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const double number) { return number != number || 0 == ::memcmp(&number, &LapysDevelopmentKit::Constants::indeterminate, sizeof(double)); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const float number) { return number != number || LapysDevelopmentKit::Functions::number__is_indeterminate((double) number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const long double number) { return number != number || LapysDevelopmentKit::Functions::number__is_indeterminate((double) number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const unsigned int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const unsigned long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const unsigned long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const unsigned short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_indeterminate(const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::boolean number__is_infinite(const double number) { return (number == LapysDevelopmentKit::Constants::infinity || number == -LapysDevelopmentKit::Constants::infinity) || (number != 0.0 && number + number == number) || (0 == ::memcmp(&number, &LapysDevelopmentKit::Constants::infinity, sizeof(double))) || std::isinf(number); }
                inline LapysDevelopmentKit::Types::boolean number__is_infinite(const float number) { return (number == LapysDevelopmentKit::Constants::infinity || number == -LapysDevelopmentKit::Constants::infinity) || (number != 0.0f && number + number == number) || std::isinf(number) || LapysDevelopmentKit::Functions::number__is_infinite((double) number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const long) { return false; }
                inline LapysDevelopmentKit::Types::boolean number__is_infinite(const long double number) { return (number == LapysDevelopmentKit::Constants::infinity || number == -LapysDevelopmentKit::Constants::infinity) || (number != 0.00 && number + number == number) || std::isinf(number) || LapysDevelopmentKit::Functions::number__is_infinite((double) number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const unsigned int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const unsigned long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const unsigned long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const unsigned short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_infinite(const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::boolean number__is_nan(const double number) { return number != number || 0 == ::memcmp(&number, &LapysDevelopmentKit::Constants::NaN, sizeof(double)) || std::isnan(number); }
                inline LapysDevelopmentKit::Types::boolean number__is_nan(const float number) { return number != number || std::isnan(number) || LapysDevelopmentKit::Functions::number__is_nan((double) number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const long) { return false; }
                inline LapysDevelopmentKit::Types::boolean number__is_nan(const long double number) { return number != number || std::isnan(number) || LapysDevelopmentKit::Functions::number__is_nan((double) number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const unsigned int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const unsigned long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const unsigned long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const unsigned short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_nan(const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::boolean number__is_safe(const double number) { return !LapysDevelopmentKit::Functions::number__is_denormalized(number) && LapysDevelopmentKit::Functions::number__is_finite(number) && !LapysDevelopmentKit::Functions::number__is_indeterminate(number) && !LapysDevelopmentKit::Functions::number__is_nan(number); }
                inline LapysDevelopmentKit::Types::boolean number__is_safe(const float number) { return !LapysDevelopmentKit::Functions::number__is_denormalized(number) && LapysDevelopmentKit::Functions::number__is_finite(number) && !LapysDevelopmentKit::Functions::number__is_indeterminate(number) && !LapysDevelopmentKit::Functions::number__is_nan(number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const int) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const long) { return true; }
                inline LapysDevelopmentKit::Types::boolean number__is_safe(const long double number) { return !LapysDevelopmentKit::Functions::number__is_denormalized(number) && LapysDevelopmentKit::Functions::number__is_finite(number) && !LapysDevelopmentKit::Functions::number__is_indeterminate(number) && !LapysDevelopmentKit::Functions::number__is_nan(number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const long long) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const short) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const unsigned int) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const unsigned long) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const unsigned long long) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const unsigned short) { return true; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_safe(const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const double number) { return LapysDevelopmentKit::Functions::number__is_denormalized(number) || LapysDevelopmentKit::Functions::number__is_indeterminate(number) || LapysDevelopmentKit::Functions::number__is_infinite(number) || LapysDevelopmentKit::Functions::number__is_nan(number); }
                inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const float number) { return LapysDevelopmentKit::Functions::number__is_denormalized(number) || LapysDevelopmentKit::Functions::number__is_indeterminate(number) || LapysDevelopmentKit::Functions::number__is_infinite(number) || LapysDevelopmentKit::Functions::number__is_nan(number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const long) { return false; }
                inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const long double number) { return LapysDevelopmentKit::Functions::number__is_denormalized(number) || LapysDevelopmentKit::Functions::number__is_indeterminate(number) || LapysDevelopmentKit::Functions::number__is_infinite(number) || LapysDevelopmentKit::Functions::number__is_nan(number); }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const unsigned int) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const unsigned long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const unsigned long long) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const unsigned short) { return false; }
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const LapysDevelopmentKit::Types::fraction);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const LapysDevelopmentKit::Types::integer);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const LapysDevelopmentKit::Types::number);
                constexpr inline LapysDevelopmentKit::Types::boolean number__is_unsafe(const LapysDevelopmentKit::Types::size);

                // Pointer ... Memory
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer& pointer) { return pointer; }
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&& pointer) { return pointer; }
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer& pointer) { return pointer; }
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&& pointer) { return pointer; }
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer& pointer, const LapysDevelopmentKit::Types::size) { return pointer; }
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::null_pointer&& pointer, const LapysDevelopmentKit::Types::size) { return pointer; }
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer& pointer, const LapysDevelopmentKit::Types::size) { return pointer; }
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__allocate_memory(const LapysDevelopmentKit::Types::null_pointer&& pointer, const LapysDevelopmentKit::Types::size) { return pointer; }
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer& pointer) { pointer.value = std::malloc(0u); return pointer; }
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&& pointer) { pointer.value = std::malloc(0u); return pointer; }
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&, const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__allocate_memory(LapysDevelopmentKit::Types::raw_pointer&&, const LapysDevelopmentKit::Types::size);
                template <typename type> inline type* pointer__allocate_memory(type*& pointer) { return (pointer = (type*) std::malloc(0u)); }
                template <typename type> inline type* pointer__allocate_memory(type*&, const LapysDevelopmentKit::Types::size size);
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(LapysDevelopmentKit::Types::null_pointer& pointer) { return pointer; }
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(LapysDevelopmentKit::Types::null_pointer&& pointer) { return pointer; }
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(const LapysDevelopmentKit::Types::null_pointer& pointer) { return pointer; }
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__free_memory(const LapysDevelopmentKit::Types::null_pointer&& pointer) { return pointer; }
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__free_memory(LapysDevelopmentKit::Types::raw_pointer& pointer) { std::free(pointer.value); pointer.value = NULL; return pointer; }
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__free_memory(LapysDevelopmentKit::Types::raw_pointer&& pointer) { std::free(pointer.value); pointer.value = NULL; return pointer; }
                template <typename type> inline type* pointer__free_memory(type*& pointer) { std::free(pointer); return (pointer = NULL); }
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__reallocate_memory(LapysDevelopmentKit::Types::null_pointer& pointer, const LapysDevelopmentKit::Types::size) { return pointer; }
                constexpr inline LapysDevelopmentKit::Types::null_pointer& pointer__reallocate_memory(LapysDevelopmentKit::Types::null_pointer&& pointer, const LapysDevelopmentKit::Types::size) { return pointer; }
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__reallocate_memory(const LapysDevelopmentKit::Types::null_pointer& pointer, const LapysDevelopmentKit::Types::size) { return pointer; }
                constexpr inline const LapysDevelopmentKit::Types::null_pointer& pointer__reallocate_memory(const LapysDevelopmentKit::Types::null_pointer&& pointer, const LapysDevelopmentKit::Types::size) { return pointer; }
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__reallocate_memory(LapysDevelopmentKit::Types::raw_pointer&, const LapysDevelopmentKit::Types::size);
                inline LapysDevelopmentKit::Types::raw_pointer& pointer__reallocate_memory(LapysDevelopmentKit::Types::raw_pointer&&, const LapysDevelopmentKit::Types::size);
                template <typename type> inline type* pointer__reallocate_memory(type*&, const LapysDevelopmentKit::Types::size);
        }

        /* Mathematics */
        inline namespace Mathematics {
            /* Constant > ... */
            constexpr const number E {};
            constexpr const number PI {};

            /* Function */
        }
    }
#endif
