/* Modification */
    /* Function Pointer */
        // [Constructor]
        constexpr inline function_pointer::function_pointer(void) : value{NULL} {}
        template <class type, class... types> constexpr inline function_pointer::function_pointer(type (*const value)(types...)) : value{(void (*)(void)) value} {}
        template <class type, class... types> constexpr inline function_pointer::function_pointer(type (*const value)(types..., ...)) : value{(void (*)(void)) value} {}
        constexpr inline function_pointer::function_pointer(function_pointer const& pointer) : value{pointer.value} {}
        constexpr inline function_pointer::function_pointer(function_pointer&& pointer) : value{pointer.value} {}

        // [Operator] > ...
        template <class type, class... types> constexpr inline function_pointer& function_pointer::operator =(type (*const value)(types...)) noexcept { this -> value = (void (*)(void)) value; return *this; }
        template <class type, class... types> constexpr inline function_pointer& function_pointer::operator =(type (*const value)(types..., ...)) noexcept { this -> value = (void (*)(void)) value; return *this; }
        constexpr inline function_pointer& function_pointer::operator =(function_pointer const& pointer) noexcept { this -> value = pointer.value; return *this; }
        constexpr inline function_pointer& function_pointer::operator =(function_pointer&& pointer) noexcept { this -> value = pointer.value; return *this; }

        constexpr inline function_pointer::operator void*(void) const noexcept { return (void*) this -> value; }
        template <class type> constexpr inline function_pointer::operator type*(void) const noexcept { return (type*) (void*) this -> value; }

    /* Object Pointer */
        // [Constructor]
        constexpr inline object_pointer::object_pointer(void) : value{NULL} {}
        template <class type> constexpr inline object_pointer::object_pointer(type* const value) : value{(void*) value} {}
        constexpr inline object_pointer::object_pointer(object_pointer const& pointer) : value{pointer.value} {}
        constexpr inline object_pointer::object_pointer(object_pointer&& pointer) : value{pointer.value} {}

        // [Operator] > ...
        template <class type> constexpr inline object_pointer& object_pointer::operator =(type* const value) noexcept { this -> value = (void*) value; return *this; }
        constexpr inline object_pointer& object_pointer::operator =(object_pointer const& pointer) noexcept { this -> value = pointer.value; return *this; }
        constexpr inline object_pointer& object_pointer::operator =(object_pointer&& pointer) noexcept { this -> value = pointer.value; return *this; }

        template <class type> constexpr inline object_pointer::operator type*(void) const noexcept { return (type*) this -> value; }
