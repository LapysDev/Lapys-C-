/* ...
        --- UPDATE ---
            #Lapys: Currently do not fully understand the Unicode Transmission Format,
                so for now this type will be a superficial fallback with a base type of `unsigned char`.
*/
typedef struct char8_t {
    // [...]
    private:
        // Initialization > Value
        unsigned char value;

    // [...]
    public:
        // [Constructor]
        inline char8_t() {}
        inline char8_t(const unsigned char argument) : value{argument} {}

        inline char8_t(char8_t& argument) : value{argument.value} {}
        inline char8_t(char8_t&& argument) : value{argument.value} {}
        inline char8_t(const char8_t& argument) : value{argument.value} {}
        inline char8_t(const char8_t&& argument) : value{argument.value} {}

        // [Operator]
            // [=]
            inline char8_t& operator =(const unsigned char argument) { this -> value = argument; return *this; }
            inline char8_t& operator =(const char8_t argument) { this -> value = argument.value; return *this; }

            // [+=]
            inline char8_t& operator +=(const unsigned char argument) { this -> value += argument; return *this; }
            inline char8_t& operator +=(const char8_t argument) { this -> value += argument.value; return *this; }

            // [-=]
            inline char8_t& operator -=(const unsigned char argument) { this -> value -= argument; return *this; }
            inline char8_t& operator -=(const char8_t argument) { this -> value -= argument.value; return *this; }

            // [*=]
            inline char8_t& operator *=(const unsigned char argument) { this -> value *= argument; return *this; }
            inline char8_t& operator *=(const char8_t argument) { this -> value *= argument.value; return *this; }

            // [/=]
            inline char8_t& operator /=(const unsigned char argument) { this -> value /= argument; return *this; }
            inline char8_t& operator /=(const char8_t argument) { this -> value /= argument.value; return *this; }

            // [%=]
            inline char8_t& operator %=(const unsigned char argument) { this -> value %= argument; return *this; }
            inline char8_t& operator %=(const char8_t argument) { this -> value %= argument.value; return *this; }

            // [^=]
            inline char8_t& operator ^=(const unsigned char argument) { this -> value ^= argument; return *this; }
            inline char8_t& operator ^=(const char8_t argument) { this -> value ^= argument.value; return *this; }

            // [&=]
            inline char8_t& operator &=(const unsigned char argument) { this -> value &= argument; return *this; }
            inline char8_t& operator &=(const char8_t argument) { this -> value &= argument.value; return *this; }

            // [|=]
            inline char8_t& operator |=(const unsigned char argument) { this -> value |= argument; return *this; }
            inline char8_t& operator |=(const char8_t argument) { this -> value |= argument.value; return *this; }

            // [>>=]
            inline char8_t& operator >>=(const unsigned char argument) { this -> value >>= argument; return *this; }
            inline char8_t& operator >>=(const char8_t argument) { this -> value >>= argument.value; return *this; }

            // [<<=]
            inline char8_t& operator <<=(const unsigned char argument) { this -> value <<= argument; return *this; }
            inline char8_t& operator <<=(const char8_t argument) { this -> value <<= argument.value; return *this; }

            // [++]
            inline char8_t& operator ++() { (this -> value)++; return *this; }
            inline char8_t& operator ++(int) { ++(this -> value); return *this; }

            // [--]
            inline char8_t& operator --() { (this -> value)--; return *this; }
            inline char8_t& operator --(int) { --(this -> value); return *this; }

            // [...]
            inline operator unsigned char() const { return this -> value; }
} char8_t;
