_t:
- int type for holding pointers
- wide int type for maximum int size
- byte type

/* Class */
/* : ... */
template <bool> struct boolean_v { public: constexpr static bool const value = false; constexpr inline operator bool(void) const noexcept { return boolean_v::value; } };
template <> struct boolean_v<true> { public: constexpr static bool const value = true; constexpr inline operator bool(void) const noexcept { return boolean_v::value; } };

template <class type, type subvalue> struct integer_v { public: constexpr static type const value = subvalue; constexpr inline operator type(void) const noexcept { return subvalue; } };

template <class, class> struct is_same_t : public false_v {};
template <class type> struct is_same_t<type, type> : public true_v {};

template <class subtype> struct type_t { typedef subtype type; };

/* : ... */
template <class type> struct as_signed_t : public type_t<type> {};
template <> struct as_signed_t<signed char> : public type_t<unsigned char> {};
template <> struct as_signed_t<signed char const> : public type_t<unsigned char const> {};
template <> struct as_signed_t<signed char const&> : public type_t<unsigned char const&> {};
template <> struct as_signed_t<signed char const&&> : public type_t<unsigned char const&&> {};
template <> struct as_signed_t<signed char const volatile> : public type_t<unsigned char const volatile> {};
template <> struct as_signed_t<signed char const volatile&> : public type_t<unsigned char const volatile&> {};
template <> struct as_signed_t<signed char const volatile&&> : public type_t<unsigned char const volatile&&> {};
template <> struct as_signed_t<signed char volatile> : public type_t<unsigned char volatile> {};
template <> struct as_signed_t<signed char volatile&> : public type_t<unsigned char volatile&> {};
template <> struct as_signed_t<signed char volatile&&> : public type_t<unsigned char volatile&&> {};
template <> struct as_signed_t<signed int> : public type_t<unsigned int> {};
template <> struct as_signed_t<signed int const> : public type_t<unsigned int const> {};
template <> struct as_signed_t<signed int const&> : public type_t<unsigned int const&> {};
template <> struct as_signed_t<signed int const&&> : public type_t<unsigned int const&&> {};
template <> struct as_signed_t<signed int const volatile> : public type_t<unsigned int const volatile> {};
template <> struct as_signed_t<signed int const volatile&> : public type_t<unsigned int const volatile&> {};
template <> struct as_signed_t<signed int const volatile&&> : public type_t<unsigned int const volatile&&> {};
template <> struct as_signed_t<signed int volatile> : public type_t<unsigned int volatile> {};
template <> struct as_signed_t<signed int volatile&> : public type_t<unsigned int volatile&> {};
template <> struct as_signed_t<signed int volatile&&> : public type_t<unsigned int volatile&&> {};
template <> struct as_signed_t<signed long> : public type_t<unsigned long> {};
template <> struct as_signed_t<signed long const> : public type_t<unsigned long const> {};
template <> struct as_signed_t<signed long const&> : public type_t<unsigned long const&> {};
template <> struct as_signed_t<signed long const&&> : public type_t<unsigned long const&&> {};
template <> struct as_signed_t<signed long const volatile> : public type_t<unsigned long const volatile> {};
template <> struct as_signed_t<signed long const volatile&> : public type_t<unsigned long const volatile&> {};
template <> struct as_signed_t<signed long const volatile&&> : public type_t<unsigned long const volatile&&> {};
template <> struct as_signed_t<signed long volatile> : public type_t<unsigned long volatile> {};
template <> struct as_signed_t<signed long volatile&> : public type_t<unsigned long volatile&> {};
template <> struct as_signed_t<signed long volatile&&> : public type_t<unsigned long volatile&&> {};
template <> struct as_signed_t<signed short> : public type_t<unsigned short> {};
template <> struct as_signed_t<signed short const> : public type_t<unsigned short const> {};
template <> struct as_signed_t<signed short const&> : public type_t<unsigned short const&> {};
template <> struct as_signed_t<signed short const&&> : public type_t<unsigned short const&&> {};
template <> struct as_signed_t<signed short const volatile> : public type_t<unsigned short const volatile> {};
template <> struct as_signed_t<signed short const volatile&> : public type_t<unsigned short const volatile&> {};
template <> struct as_signed_t<signed short const volatile&&> : public type_t<unsigned short const volatile&&> {};
template <> struct as_signed_t<signed short volatile> : public type_t<unsigned short volatile> {};
template <> struct as_signed_t<signed short volatile&> : public type_t<unsigned short volatile&> {};
template <> struct as_signed_t<signed short volatile&&> : public type_t<unsigned short volatile&&> {};

#if cpp__version >= 2011uL
    template <> struct as_signed_t<signed long long> : public type_t<unsigned long long> {};
    template <> struct as_signed_t<signed long long const> : public type_t<unsigned long long const> {};
    template <> struct as_signed_t<signed long long const&> : public type_t<unsigned long long const&> {};
    template <> struct as_signed_t<signed long long const&&> : public type_t<unsigned long long const&&> {};
    template <> struct as_signed_t<signed long long const volatile> : public type_t<unsigned long long const volatile> {};
    template <> struct as_signed_t<signed long long const volatile&> : public type_t<unsigned long long const volatile&> {};
    template <> struct as_signed_t<signed long long const volatile&&> : public type_t<unsigned long long const volatile&&> {};
    template <> struct as_signed_t<signed long long volatile> : public type_t<unsigned long long volatile> {};
    template <> struct as_signed_t<signed long long volatile&> : public type_t<unsigned long long volatile&> {};
    template <> struct as_signed_t<signed long long volatile&&> : public type_t<unsigned long long volatile&&> {};
#endif

template <class type> struct as_const_t : public type_t<type const> {};
template <class type> struct as_reference_t : public type_t<type&> {};
template <class type> struct as_temporary_t : public type_t<type&&> {};
template <class type> struct as_pointer_t : public type_t<type*> {};

template <class type> struct as_unsigned_t : public type_t<type> {};
template <> struct as_unsigned_t<unsigned char> : public type_t<signed char> {};
template <> struct as_unsigned_t<unsigned char const> : public type_t<signed char const> {};
template <> struct as_unsigned_t<unsigned char const&> : public type_t<signed char const&> {};
template <> struct as_unsigned_t<unsigned char const&&> : public type_t<signed char const&&> {};
template <> struct as_unsigned_t<unsigned char const volatile> : public type_t<signed char const volatile> {};
template <> struct as_unsigned_t<unsigned char const volatile&> : public type_t<signed char const volatile&> {};
template <> struct as_unsigned_t<unsigned char const volatile&&> : public type_t<signed char const volatile&&> {};
template <> struct as_unsigned_t<unsigned char volatile> : public type_t<signed char volatile> {};
template <> struct as_unsigned_t<unsigned char volatile&> : public type_t<signed char volatile&> {};
template <> struct as_unsigned_t<unsigned char volatile&&> : public type_t<signed char volatile&&> {};
template <> struct as_unsigned_t<unsigned int> : public type_t<signed int> {};
template <> struct as_unsigned_t<unsigned int const> : public type_t<signed int const> {};
template <> struct as_unsigned_t<unsigned int const&> : public type_t<signed int const&> {};
template <> struct as_unsigned_t<unsigned int const&&> : public type_t<signed int const&&> {};
template <> struct as_unsigned_t<unsigned int const volatile> : public type_t<signed int const volatile> {};
template <> struct as_unsigned_t<unsigned int const volatile&> : public type_t<signed int const volatile&> {};
template <> struct as_unsigned_t<unsigned int const volatile&&> : public type_t<signed int const volatile&&> {};
template <> struct as_unsigned_t<unsigned int volatile> : public type_t<signed int volatile> {};
template <> struct as_unsigned_t<unsigned int volatile&> : public type_t<signed int volatile&> {};
template <> struct as_unsigned_t<unsigned int volatile&&> : public type_t<signed int volatile&&> {};
template <> struct as_unsigned_t<unsigned long> : public type_t<signed long> {};
template <> struct as_unsigned_t<unsigned long const> : public type_t<signed long const> {};
template <> struct as_unsigned_t<unsigned long const&> : public type_t<signed long const&> {};
template <> struct as_unsigned_t<unsigned long const&&> : public type_t<signed long const&&> {};
template <> struct as_unsigned_t<unsigned long const volatile> : public type_t<signed long const volatile> {};
template <> struct as_unsigned_t<unsigned long const volatile&> : public type_t<signed long const volatile&> {};
template <> struct as_unsigned_t<unsigned long const volatile&&> : public type_t<signed long const volatile&&> {};
template <> struct as_unsigned_t<unsigned long volatile> : public type_t<signed long volatile> {};
template <> struct as_unsigned_t<unsigned long volatile&> : public type_t<signed long volatile&> {};
template <> struct as_unsigned_t<unsigned long volatile&&> : public type_t<signed long volatile&&> {};
template <> struct as_unsigned_t<unsigned short> : public type_t<signed short> {};
template <> struct as_unsigned_t<unsigned short const> : public type_t<signed short const> {};
template <> struct as_unsigned_t<unsigned short const&> : public type_t<signed short const&> {};
template <> struct as_unsigned_t<unsigned short const&&> : public type_t<signed short const&&> {};
template <> struct as_unsigned_t<unsigned short const volatile> : public type_t<signed short const volatile> {};
template <> struct as_unsigned_t<unsigned short const volatile&> : public type_t<signed short const volatile&> {};
template <> struct as_unsigned_t<unsigned short const volatile&&> : public type_t<signed short const volatile&&> {};
template <> struct as_unsigned_t<unsigned short volatile> : public type_t<signed short volatile> {};
template <> struct as_unsigned_t<unsigned short volatile&> : public type_t<signed short volatile&> {};
template <> struct as_unsigned_t<unsigned short volatile&&> : public type_t<signed short volatile&&> {};

#if cpp__version >= 2011uL
    template <> struct as_unsigned_t<unsigned long long> : public type_t<signed long long> {};
    template <> struct as_unsigned_t<unsigned long long const> : public type_t<signed long long const> {};
    template <> struct as_unsigned_t<unsigned long long const&> : public type_t<signed long long const&> {};
    template <> struct as_unsigned_t<unsigned long long const&&> : public type_t<signed long long const&&> {};
    template <> struct as_unsigned_t<unsigned long long const volatile> : public type_t<signed long long const volatile> {};
    template <> struct as_unsigned_t<unsigned long long const volatile&> : public type_t<signed long long const volatile&> {};
    template <> struct as_unsigned_t<unsigned long long const volatile&&> : public type_t<signed long long const volatile&&> {};
    template <> struct as_unsigned_t<unsigned long long volatile> : public type_t<signed long long volatile> {};
    template <> struct as_unsigned_t<unsigned long long volatile&> : public type_t<signed long long volatile&> {};
    template <> struct as_unsigned_t<unsigned long long volatile&&> : public type_t<signed long long volatile&&> {};
#endif

template <class type> struct as_volatile_t : public type_t<type volatile> {};

template <bool, class true_t, class = type_t<true_t>*> struct assert_t : public type_t<true_t> {};
template <class true_t, class false_t = type_t<false_t>*> struct assert_t<false, true_t, false_t> : public type_t<false_t> {};

template <class> struct is_array_t : public false_v {};
template <> template <class type> struct is_array_t<type[]> : public true_v {};
template <> template <size_t length, class type> struct is_array_t<type[length]> : public true_v {};

template <class base_t, class derived_t>
struct is_baseof_t {
    private:
        constexpr inline static bool assert(base_t const* const) noexcept { return true; }
        constexpr inline static bool assert(void const* const) noexcept { return false; }

    public:
        constexpr static bool const value = is_baseof_t::assert((derived_t const*) NULL) && false == is_same_t<base_t, derived_t>::value;
        constexpr inline operator bool(void) const noexcept { return is_baseof_t::value; }
};

template <class> struct is_bounded_array_t : public false_v {};
template <> template <class type> struct is_bounded_array_t<type[]> : public false_v {};
template <> template <size_t length, class type> struct is_bounded_array_t<type[length]> : public true_v {};

template <class> struct is_character_t : public false_v {};
template <> struct is_character_t<char> : public true_v {};
template <> struct is_character_t<char8_t> : public true_v {};
template <> struct is_character_t<char16_t> : public true_v {};
template <> struct is_character_t<char32_t> : public true_v {};
template <> struct is_character_t<wchar_t> : public true_v {};

template <class type> struct is_class_t : public boolean_v<false == (is_array_t<type>::value || is_function_t<type>::value || is_primitive_t<type>::value)> {};

template <class> struct is_const_t : public false_v {};
template <> template <class type> struct is_const_t<type const> : public true_v {};

template <class> struct is_decimal_t : public false_v {};
template <> struct is_decimal_t<double> : public true_v {};
template <> struct is_decimal_t<float> : public true_v {};
template <> struct is_decimal_t<long double> : public true_v {};

template <class> struct is_function_t : public false_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)&&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)&& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const&&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const&& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile&&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile&& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile&&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile&& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)&&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)&& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const&&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const&& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile&&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile&& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile& noexcept> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile&&> : public true_v {};
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile&& noexcept> : public true_v {};

template <class> struct is_integer_t : public false_v {};
template <> struct is_integer_t<int> : public true_v {};
template <> struct is_integer_t<long> : public true_v {};
template <> struct is_integer_t<short> : public true_v {};
template <> struct is_integer_t<signed char> : public true_v {};
template <> struct is_integer_t<unsigned char> : public true_v {};
template <> struct is_integer_t<unsigned int> : public true_v {};
template <> struct is_integer_t<unsigned long> : public true_v {};
template <> struct is_integer_t<unsigned short> : public true_v {};
#if cpp__version >= 2011uL
    template <> struct is_integer_t<long long> : public true_v {};
    template <> struct is_integer_t<unsigned long long> : public true_v {};
#endif

template <class> struct is_member_pointer_t : public false_v {};
template <> template <class member_t, class object> struct is_member_pointer_t<member_t object::*> : public true_v {};

template <class> struct is_member_function_pointer_t : public false_v {};
template <> template <class member_t, class object> struct is_member_function_pointer_t<member_t object::*> : public is_function_t<member_t> {};

template <class type> struct is_member_object_pointer : public boolean_v<is_member_function_pointer_t<type>::value && false == is_member_pointer_t<type>::value> {};

template <class> struct is_numeric_t : public false_v {};
template <> struct is_numeric_t<double> : public true_v {};
template <> struct is_numeric_t<float> : public true_v {};
template <> struct is_numeric_t<int> : public true_v {};
template <> struct is_numeric_t<long> : public true_v {};
template <> struct is_numeric_t<long double> : public true_v {};
template <> struct is_numeric_t<short> : public true_v {};
template <> struct is_numeric_t<signed char> : public true_v {};
template <> struct is_numeric_t<unsigned char> : public true_v {};
template <> struct is_numeric_t<unsigned int> : public true_v {};
template <> struct is_numeric_t<unsigned long> : public true_v {};
template <> struct is_numeric_t<unsigned short> : public true_v {};
#if cpp__version >= 2011uL
    template <> struct is_numeric_t<long long> : public true_v {};
    template <> struct is_numeric_t<unsigned long long> : public true_v {};
#endif

template <class> struct is_pointer_t : public false_v {};
template <> template <class type> struct is_pointer_t<type*> : public true_v {};

template <class> struct is_primitive_t : public false_v {};
template <> struct is_primitive_t<char> : public true_v {};
template <> struct is_primitive_t<char8_t> : public true_v {};
template <> struct is_primitive_t<char16_t> : public true_v {};
template <> struct is_primitive_t<char32_t> : public true_v {};
template <> struct is_primitive_t<double> : public true_v {};
template <> struct is_primitive_t<float> : public true_v {};
template <> struct is_primitive_t<int> : public true_v {};
template <> struct is_primitive_t<long> : public true_v {};
template <> struct is_primitive_t<long double> : public true_v {};
template <> struct is_primitive_t<short> : public true_v {};
template <> struct is_primitive_t<signed char> : public true_v {};
template <> struct is_primitive_t<unsigned char> : public true_v {};
template <> struct is_primitive_t<unsigned int> : public true_v {};
template <> struct is_primitive_t<unsigned long> : public true_v {};
template <> struct is_primitive_t<unsigned short> : public true_v {};
template <> struct is_primitive_t<wchar_t> : public true_v {};
template <> struct is_primitive_t<void> : public true_v {};
template <> template <class type> struct is_primitive_t<type*> : public true_v {};
#if cpp__version >= 2011uL
    template <> struct is_primitive_t<long long> : public true_v {};
    template <> struct is_primitive_t<unsigned long long> : public true_v {};
#endif

template <class> struct is_reference_t : public false_v {};
template <> template <class type> struct is_reference_t<type&> : public true_v {};

template <class> struct is_signed_t : public false_v {};
template <> struct is_signed_t<signed char> : public true_v {};
template <> struct is_signed_t<signed int> : public true_v {};
template <> struct is_signed_t<signed long> : public true_v {};
template <> struct is_signed_t<signed short> : public true_v {};
#if cpp__version >= 2011uL
    template <> struct is_signed_t<signed long long> : public true_v {};
#endif

template <class> struct is_temporary_t : public false_v {};
template <> template <class type> struct is_temporary_t<type&&> : public true_v {};

template <class> struct is_unbounded_array_t : public false_v {};
template <> template <class type> struct is_unbounded_array_t<type[]> : public true_v {};
template <> template <size_t length, class type> struct is_unbounded_array_t<type[length]> : public false_v {};

template <class> struct is_unsigned_t : public false_v {};
template <> struct is_unsigned_t<unsigned char> : public true_v {};
template <> struct is_unsigned_t<unsigned int> : public true_v {};
template <> struct is_unsigned_t<unsigned long> : public true_v {};
template <> struct is_unsigned_t<unsigned short> : public true_v {};
#if cpp__version >= 2011uL
    template <> struct is_unsigned_t<unsigned long long> : public true_v {};
#endif

template <class> struct is_void_t : public false_v {};
template <> struct is_void_t<void> : public true_v {};

template <class> struct is_volatile_t : public false_v {};
template <> template <class type> struct is_volatile_t<type volatile> : public true_v {};

template <class> struct lengthof_t {};
template <class> template <size_t length, class type> struct lengthof_t<type[length]> : public integer_v<size_t, length> {};

template <class type> struct non_const_t : public type_t<type> {};
template <> template <class type> struct non_const_t<type const> : public type_t<type> {};

template <class type> struct non_pointer_t : public type_t<type> {};
template <> template <class type> struct non_pointer_t<type*> : public type_t<type> {};

template <class type> struct non_qualified_t : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type&> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type&&> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type const> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type const&> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type const&&> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type const volatile> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type const volatile&> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type const volatile&&> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type volatile> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type volatile&> : public type_t<type> {};
template <> template <class type> struct non_qualified_t<type volatile&&> : public type_t<type> {};

template <class type> struct non_temporary_t : public type_t<type> {};
template <> template <class type> struct non_temporary_t<type&&> : public type_t<type> {};

template <class type> struct non_reference_t : public type_t<type> {};
template <> template <class type> struct non_reference_t<type&> : public type_t<type> {};

template <class type> struct non_volatile_t : public type_t<type> {};
template <> template <class type> struct non_volatile_t<type volatile> : public type_t<type> {};

template <class> struct rankof_t : public integer_v<unsigned char, 0u> {};
template <> template <class type> struct rankof_t<type[]> : public integer_v<unsigned char, rankof_t<type>::value + 1u> {};
template <> template <size_t length, class type> struct rankof_t<type[length]> : public integer_v<unsigned char, rankof_t<type>::value + 1u> {};
