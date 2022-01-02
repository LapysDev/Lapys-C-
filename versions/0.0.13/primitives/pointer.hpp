/* Class */
    /* Function Pointer */
    struct function_pointer {
        // [...]
        private:
            // Definition > Value
            void (*value)(void);

        // [...]
        public:
            // [Constructor]
            constexpr function_pointer(void);
            template <class type, class... types> constexpr function_pointer(type (*)(types...));
            template <class type, class... types> constexpr function_pointer(type (*)(types..., ...));
            constexpr function_pointer(function_pointer const&);
            constexpr function_pointer(function_pointer&&);

            // [Operator] > ...
            template <class type, class... types> constexpr function_pointer& operator =(type (*)(types...)) noexcept;
            template <class type, class... types> constexpr function_pointer& operator =(type (*)(types..., ...)) noexcept;
            constexpr function_pointer& operator =(function_pointer const&) noexcept;
            constexpr function_pointer& operator =(function_pointer&&) noexcept;

            constexpr operator void*(void) const noexcept;
            template <class type> constexpr operator type*(void) const noexcept;
    };

    /* Object Pointer */
    struct object_pointer {
        // [...]
        private:
            // Definition > Value
            void *value;

        // [...]
        public:
            // [Constructor]
            constexpr object_pointer(void);
            template <class type> constexpr object_pointer(type* const);
            constexpr object_pointer(object_pointer const&);
            constexpr object_pointer(object_pointer&&);

            // [Operator] > ...
            template <class type> constexpr object_pointer& operator =(type* const) noexcept;
            constexpr object_pointer& operator =(object_pointer const&) noexcept;
            constexpr object_pointer& operator =(object_pointer&&) noexcept;
            template <class type> constexpr operator type*(void) const noexcept;
    };

/* Import */
#include "pointer.cpp"
