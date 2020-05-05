/* Class > String */
class String : protected object {
    /* Definition > Character */
    typedef unsigned long Character;

    // [...]
    private:
        // Initialization > (Heap, Stack) Value (Length)
        Character *heapValue;
        Character stackValue[15] {0}; // NOTE (Lapys) -> Can this be re-allocated?

        unsigned long valueLength;

    // [...]
    public:
        // [Constructor]
        String(char argument[]) {}
        String(const char argument[]) {}
        String(char8_t argument[]) {}
        String(const char8_t argument[]) {}
        String(Character argument[]) {}
        String(const Character argument[]) {}
        String(char16_t argument[]) {}
        String(const char16_t argument[]) {}
        String(char32_t argument[]) {}
        String(const char32_t argument[]) {}
        String(void) {}
        String(wchar_t argument[]) {}
        String(const wchar_t argument[]) {}
};
