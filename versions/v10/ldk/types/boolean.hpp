/* Class > Boolean */
struct boolean {
    /* ... */
    friend character;
    friend fraction;
    friend integer;
    friend null_pointer;
    friend number;
    friend pointer;
    friend primitive;
    friend raw_pointer;
    friend shared_smart_pointer;
    friend size;
    friend smart_pointer;
    friend string;
    friend unique_smart_pointer;
    friend wide;

    // [...]
    private:
        // Definition > Value
        enum boolean_value {boolean_false, boolean_true} value : 1;

    // [...]
    public:
        // [Constructor]
        constexpr inline boolean(const boolean_value argument) : value{argument} {}
        constexpr inline boolean(void) : value{boolean_false} {}

        constexpr inline boolean(boolean&& argument) : value{argument.value} {}
        constexpr inline boolean(const boolean& argument) : value{argument.value} {}

        // [Operator] > ...
    #if defined(__cplusplus) || (defined(__bool_true_false_are_defined) || defined(_Bool) || defined(_STDBOOL_H))
            inline operator bool(void) const noexcept { return this -> boolean_true == this -> value; }
        #else
            inline operator unsigned char(void) const noexcept { return this -> boolean_true == this -> value; }
        #endif
};
