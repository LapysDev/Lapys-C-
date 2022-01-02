/* Class > Big Number */
class BigNumber {
    // ...
    private:
        // Initialization > Value
        char *value;

    // ...
    public:
        // [Constructor]
        inline BigNumber() : value(NULL) {}
        inline BigNumber(const double argument) {}
        inline BigNumber(const float argument) {}
        inline BigNumber(const int argument) {}
        inline BigNumber(const long argument) {}
        inline BigNumber(const long double argument) {}
        inline BigNumber(const long long argument) {}
        inline BigNumber(const short argument) {}
        inline BigNumber(const unsigned int argument) {}
        inline BigNumber(const unsigned long argument) {}
        inline BigNumber(const unsigned long long argument) {}
        inline BigNumber(const unsigned short argument) {}

        // [Destructor]
        ~BigNumber() { std::free(this -> value); }

        // Method > ...
        inline const char* toString() const { return NULL == this -> value ? "0" : this -> value; }
};
