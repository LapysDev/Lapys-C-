/* Function
    --- NOTE ---
        #Lapys:
            - Each function ,ay dynamically heap allocate memory if required.
            - Pointers may also be considered arrays.
*/
    // At --- WARN (Lapys) -> Assumes the index is valid.
    template <typename type>
    constexpr inline type& array__at(type array[], const std::size_t index) noexcept { return *(array + index); }

    // Clone
    template <typename type>
    type* array__clone(type array[], const std::size_t length) noexcept { if (array) { type *arrayClone = LDKF::pointer__heap_allocate(length * sizeof(type)); LDKF::pointer__copy(arrayClone, array, length * sizeof(type)); return arrayClone; } else return NULL; }

    // Copy
    template <typename type>
    type* array__copy(type array[], type arraySource[], const std::size_t length) noexcept { if (arraySource && length) { LDKF::pointer__copy(array, arraySource, length * sizeof(type)); return array; } else return NULL; }

    template <const std::size_t length, typename type>
    type* array__copy(type (&array)[length], type arraySource[], const std::size_t arraySourceLength) noexcept { if (arraySource && arraySourceLength) { LDKF::pointer__copy(array, arraySource, (arraySourceLength < length ? arraySourceLength : length) * sizeof(type)); return array; } else return NULL; }

    // Create
    template <const std::size_t length, typename type, typename... types>
    inline type* array__create(types... arguments) noexcept { return LDKF::pointer__create_array<length, type>(arguments...); }

    // Cut
    inline void array__cut(...) noexcept {}

    // Cut From End
    inline void array__cut_from_end(...) noexcept {}

    // Cut From Start
    inline void array__cut_from_start(...) noexcept {}

    // Fill
    inline void array__fill(...) noexcept {}

    // Free
    inline void array__free(...) noexcept {}

    // Index
    inline void array__index(...) noexcept {}

    // Index From End
    inline void array__index_from_end(...) noexcept {}

    // Index From Start
    inline void array__index_from_start(...) noexcept {}

    // Length
    template <const std::size_t length, typename type> constexpr inline std::size_t array__length(type (&array)[length]) noexcept { return length; }
    inline void array__length(...) noexcept {}

    // Pop
    inline void array__pop(...) noexcept {}

    // Push
    inline void array__push(...) noexcept {}

    // Remove
    inline void array__remove(...) noexcept {}

    // Replace
    inline void array__replace(...) noexcept {}

    // Resize
    inline void array__resize(...) noexcept {}

    // Size Of
    inline void array__sizeof(...) noexcept {}

    // Slice
    inline void array__slice(...) noexcept {}
