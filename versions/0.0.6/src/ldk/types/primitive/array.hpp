/* Class > Array */
class Array : protected object {
    // [...]
    private:
        // Initialization > (Value) (Length, Size)
        void **value;
        unsigned long valueLength;

    // [...]
    public:
        // [Constructor]
        Array(const unsigned long length) {}
};
