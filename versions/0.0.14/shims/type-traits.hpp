/* Definition > ... */
template <class> struct as_signed_t;
template <> struct as_signed_t<signed char>;
template <> struct as_signed_t<signed char const>;
template <> struct as_signed_t<signed char const&>;
template <> struct as_signed_t<signed char const&&>;
template <> struct as_signed_t<signed char const volatile>;
template <> struct as_signed_t<signed char const volatile&>;
template <> struct as_signed_t<signed char const volatile&&>;
template <> struct as_signed_t<signed char volatile>;
template <> struct as_signed_t<signed char volatile&>;
template <> struct as_signed_t<signed char volatile&&>;
template <> struct as_signed_t<signed int>;
template <> struct as_signed_t<signed int const>;
template <> struct as_signed_t<signed int const&>;
template <> struct as_signed_t<signed int const&&>;
template <> struct as_signed_t<signed int const volatile>;
template <> struct as_signed_t<signed int const volatile&>;
template <> struct as_signed_t<signed int const volatile&&>;
template <> struct as_signed_t<signed int volatile>;
template <> struct as_signed_t<signed int volatile&>;
template <> struct as_signed_t<signed int volatile&&>;
template <> struct as_signed_t<signed long>;
template <> struct as_signed_t<signed long const>;
template <> struct as_signed_t<signed long const&>;
template <> struct as_signed_t<signed long const&&>;
template <> struct as_signed_t<signed long const volatile>;
template <> struct as_signed_t<signed long const volatile&>;
template <> struct as_signed_t<signed long const volatile&&>;
template <> struct as_signed_t<signed long volatile>;
template <> struct as_signed_t<signed long volatile&>;
template <> struct as_signed_t<signed long volatile&&>;
template <> struct as_signed_t<signed short>;
template <> struct as_signed_t<signed short const>;
template <> struct as_signed_t<signed short const&>;
template <> struct as_signed_t<signed short const&&>;
template <> struct as_signed_t<signed short const volatile>;
template <> struct as_signed_t<signed short const volatile&>;
template <> struct as_signed_t<signed short const volatile&&>;
template <> struct as_signed_t<signed short volatile>;
template <> struct as_signed_t<signed short volatile&>;
template <> struct as_signed_t<signed short volatile&&>;
#if cpp__version >= 2011uL
    template <> struct as_signed_t<signed long long>;
    template <> struct as_signed_t<signed long long const>;
    template <> struct as_signed_t<signed long long const&>;
    template <> struct as_signed_t<signed long long const&&>;
    template <> struct as_signed_t<signed long long const volatile>;
    template <> struct as_signed_t<signed long long const volatile&>;
    template <> struct as_signed_t<signed long long const volatile&&>;
    template <> struct as_signed_t<signed long long volatile>;
    template <> struct as_signed_t<signed long long volatile&>;
    template <> struct as_signed_t<signed long long volatile&&>;
#endif

template <class> struct as_const_t;
template <class> struct as_reference_t;
template <class> struct as_temporary_t;
template <class> struct as_pointer_t;

template <class type> struct as_unsigned_t;
template <> struct as_unsigned_t<unsigned char>;
template <> struct as_unsigned_t<unsigned char const>;
template <> struct as_unsigned_t<unsigned char const&>;
template <> struct as_unsigned_t<unsigned char const&&>;
template <> struct as_unsigned_t<unsigned char const volatile>;
template <> struct as_unsigned_t<unsigned char const volatile&>;
template <> struct as_unsigned_t<unsigned char const volatile&&>;
template <> struct as_unsigned_t<unsigned char volatile>;
template <> struct as_unsigned_t<unsigned char volatile&>;
template <> struct as_unsigned_t<unsigned char volatile&&>;
template <> struct as_unsigned_t<unsigned int>;
template <> struct as_unsigned_t<unsigned int const>;
template <> struct as_unsigned_t<unsigned int const&>;
template <> struct as_unsigned_t<unsigned int const&&>;
template <> struct as_unsigned_t<unsigned int const volatile>;
template <> struct as_unsigned_t<unsigned int const volatile&>;
template <> struct as_unsigned_t<unsigned int const volatile&&>;
template <> struct as_unsigned_t<unsigned int volatile>;
template <> struct as_unsigned_t<unsigned int volatile&>;
template <> struct as_unsigned_t<unsigned int volatile&&>;
template <> struct as_unsigned_t<unsigned long>;
template <> struct as_unsigned_t<unsigned long const>;
template <> struct as_unsigned_t<unsigned long const&>;
template <> struct as_unsigned_t<unsigned long const&&>;
template <> struct as_unsigned_t<unsigned long const volatile>;
template <> struct as_unsigned_t<unsigned long const volatile&>;
template <> struct as_unsigned_t<unsigned long const volatile&&>;
template <> struct as_unsigned_t<unsigned long volatile>;
template <> struct as_unsigned_t<unsigned long volatile&>;
template <> struct as_unsigned_t<unsigned long volatile&&>;
template <> struct as_unsigned_t<unsigned short>;
template <> struct as_unsigned_t<unsigned short const>;
template <> struct as_unsigned_t<unsigned short const&>;
template <> struct as_unsigned_t<unsigned short const&&>;
template <> struct as_unsigned_t<unsigned short const volatile>;
template <> struct as_unsigned_t<unsigned short const volatile&>;
template <> struct as_unsigned_t<unsigned short const volatile&&>;
template <> struct as_unsigned_t<unsigned short volatile>;
template <> struct as_unsigned_t<unsigned short volatile&>;
template <> struct as_unsigned_t<unsigned short volatile&&>;
#if cpp__version >= 2011uL
    template <> struct as_unsigned_t<unsigned long long>;
    template <> struct as_unsigned_t<unsigned long long const>;
    template <> struct as_unsigned_t<unsigned long long const&>;
    template <> struct as_unsigned_t<unsigned long long const&&>;
    template <> struct as_unsigned_t<unsigned long long const volatile>;
    template <> struct as_unsigned_t<unsigned long long const volatile&>;
    template <> struct as_unsigned_t<unsigned long long const volatile&&>;
    template <> struct as_unsigned_t<unsigned long long volatile>;
    template <> struct as_unsigned_t<unsigned long long volatile&>;
    template <> struct as_unsigned_t<unsigned long long volatile&&>;
#endif

template <class> struct as_volatile_t;

template <bool, class, class > struct assert_t;
template <class true_t, class false_t> struct assert_t<false, true_t, false_t>;

template <bool> struct boolean_v;
template <> struct boolean_v<true>;

typedef boolean_v<false> false_v;
#if defined(__cplusplus) || defined(_MSC_EXTENSIONS) || defined(__STDC__) // CONSIDER (Lapys) -> Ignored through most of the code base..
    typedef void generic_t;
#else
    typedef char generic_t;
#endif
template <class, type> struct integer_v;

template <class> struct is_array_t;
template <> template <class type> struct is_array_t<type[]>;
template <> template <size_t length, class type> struct is_array_t<type[length]>;

template <class, class> struct is_baseof_t;

template <class> struct is_bounded_array_t;
template <> template <class type> struct is_bounded_array_t<type[]>;
template <> template <size_t length, class type> struct is_bounded_array_t<type[length]>;

template <class> struct is_character_t;
template <> struct is_character_t<char>;
template <> struct is_character_t<char8_t>;
template <> struct is_character_t<char16_t>;
template <> struct is_character_t<char32_t>;
template <> struct is_character_t<wchar_t>;

template <class> struct is_class_t;

template <class> struct is_const_t;
template <> template <class type> struct is_const_t<type const>;

template <class> struct is_decimal_t;
template <> struct is_decimal_t<double>;
template <> struct is_decimal_t<float>;
template <> struct is_decimal_t<long double>;

template <class> struct is_function_t;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)&&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...)&& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const&&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const&& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile&&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) const volatile&& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile&&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types...) volatile&& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)&&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...)&& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const&&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const&& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile&&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) const volatile&& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile& noexcept>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile&&>;
template <> template <class return_t, class... types> struct is_function_t<return_t (types..., ...) volatile&& noexcept>;

template <class> struct is_integer_t;
template <> struct is_integer_t<int>;
template <> struct is_integer_t<long>;
template <> struct is_integer_t<short>;
template <> struct is_integer_t<signed char>;
template <> struct is_integer_t<unsigned char>;
template <> struct is_integer_t<unsigned int>;
template <> struct is_integer_t<unsigned long>;
template <> struct is_integer_t<unsigned short>;
#if cpp__version >= 2011uL
    template <> struct is_integer_t<long long>;
    template <> struct is_integer_t<unsigned long long>;
#endif

template <class> struct is_member_pointer_t;
template <> template <class member_t, class object> struct is_member_pointer_t<member_t object::*>;

template <class> struct is_member_function_pointer_t;
template <> template <class member_t, class object> struct is_member_function_pointer_t<member_t object::*>;

template <class> struct is_member_object_pointer;

template <class> struct is_numeric_t;
template <> struct is_numeric_t<double>;
template <> struct is_numeric_t<float>;
template <> struct is_numeric_t<int>;
template <> struct is_numeric_t<long>;
template <> struct is_numeric_t<long double>;
template <> struct is_numeric_t<short>;
template <> struct is_numeric_t<signed char>;
template <> struct is_numeric_t<unsigned char>;
template <> struct is_numeric_t<unsigned int>;
template <> struct is_numeric_t<unsigned long>;
template <> struct is_numeric_t<unsigned short>;
#if cpp__version >= 2011uL
    template <> struct is_numeric_t<long long>;
    template <> struct is_numeric_t<unsigned long long>;
#endif

template <class> struct is_pointer_t;
template <> template <class type> struct is_pointer_t<type*>;

template <class> struct is_primitive_t;
template <> struct is_primitive_t<char>;
template <> struct is_primitive_t<char8_t>;
template <> struct is_primitive_t<char16_t>;
template <> struct is_primitive_t<char32_t>;
template <> struct is_primitive_t<double>;
template <> struct is_primitive_t<float>;
template <> struct is_primitive_t<int>;
template <> struct is_primitive_t<long>;
template <> struct is_primitive_t<long double>;
template <> struct is_primitive_t<short>;
template <> struct is_primitive_t<signed char>;
template <> struct is_primitive_t<unsigned char>;
template <> struct is_primitive_t<unsigned int>;
template <> struct is_primitive_t<unsigned long>;
template <> struct is_primitive_t<unsigned short>;
template <> struct is_primitive_t<wchar_t>;
template <> struct is_primitive_t<void>;
template <> template <class type> struct is_primitive_t<type*>;
#if cpp__version >= 2011uL
    template <> struct is_primitive_t<long long>;
    template <> struct is_primitive_t<unsigned long long>;
#endif

template <class> struct is_reference_t;
template <> template <class type> struct is_reference_t<type&>;

template <class, class> struct is_same_t;
template <class type> struct is_same_t<type, type>;

template <class> struct is_signed_t;
template <> struct is_signed_t<signed char>;
template <> struct is_signed_t<signed int>;
template <> struct is_signed_t<signed long>;
template <> struct is_signed_t<signed short>;
#if cpp__version >= 2011uL
    template <> struct is_signed_t<signed long long>;
#endif

template <class> struct is_temporary_t;
template <> template <class type> struct is_temporary_t<type&&>;

template <class> struct is_unbounded_array_t;
template <> template <class type> struct is_unbounded_array_t<type[]>;
template <> template <size_t length, class type> struct is_unbounded_array_t<type[length]>;

template <class> struct is_unsigned_t;
template <> struct is_unsigned_t<unsigned char>;
template <> struct is_unsigned_t<unsigned int>;
template <> struct is_unsigned_t<unsigned long>;
template <> struct is_unsigned_t<unsigned short>;
#if cpp__version >= 2011uL
    template <> struct is_unsigned_t<unsigned long long>;
#endif

template <class> struct is_void_t;
template <> struct is_void_t<void>;

template <class> struct is_volatile_t;
template <> template <class type> struct is_volatile_t<type volatile>;

template <class> struct lengthof_t;
template <class> template <size_t length, class type> struct lengthof_t<type[length]>;

template <class> struct non_const_t;
template <> template <class type> struct non_const_t<type const>;

template <class> struct non_pointer_t;
template <> template <class type> struct non_pointer_t<type*>;

template <class> struct non_qualified_t;
template <> template <class type> struct non_qualified_t<type&>;
template <> template <class type> struct non_qualified_t<type&&>;
template <> template <class type> struct non_qualified_t<type const>;
template <> template <class type> struct non_qualified_t<type const&>;
template <> template <class type> struct non_qualified_t<type const&&>;
template <> template <class type> struct non_qualified_t<type const volatile>;
template <> template <class type> struct non_qualified_t<type const volatile&>;
template <> template <class type> struct non_qualified_t<type const volatile&&>;
template <> template <class type> struct non_qualified_t<type volatile>;
template <> template <class type> struct non_qualified_t<type volatile&>;
template <> template <class type> struct non_qualified_t<type volatile&&>;

template <class> struct non_temporary_t;
template <> template <class type> struct non_temporary_t<type&&>;

template <class> struct non_reference_t;
template <> template <class type> struct non_reference_t<type&>;

template <class> struct non_volatile_t;
template <> template <class type> struct non_volatile_t<type volatile>;

template <class> struct rankof_t;
template <> template <class type> struct rankof_t<type[]>;
template <> template <size_t length, class type> struct rankof_t<type[length]>;

typedef boolean_v<true> true_v;
template <class> struct type_t;

#if cpp__version >= 2011uL
    typedef unsigned long long uwide_t;
    typedef signed long long wide_t;
#else
    typedef unsigned long uwide_t;
    typedef signed long wide_t;
#endif

#define unique_t integer_v<uwide_t, __COUNTER__>
