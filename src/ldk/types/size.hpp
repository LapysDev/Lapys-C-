/* Class > Size */
struct size {
    // [...]
    private:
        // Definition > Value
        std::size_t value;

    // [...]
    public:
        // [Constructor]
        constexpr inline size(const std::size_t size) : value{size} {}

        // [Operator] > ...
        inline operator std::size_t(void) const noexcept { return this -> value; }
};
