/* ... Class > Boolean --- REDACT (Lapys) */
#ifdef __bool_true_false_are_defined
    struct boolean_t {
        private: bool value : 1;
        public:
            constexpr boolean_t(bool const = false);

            inline boolean_t& operator =(boolean_t const argument) noexcept { this -> value = argument; return *this; }
            inline boolean_t& operator +=(boolean_t const argument) noexcept { this -> value += argument; return *this; }
            inline boolean_t& operator -=(boolean_t const argument) noexcept { this -> value -= argument; return *this; }
            inline boolean_t& operator *=(boolean_t const argument) noexcept { this -> value *= argument; return *this; }
            inline boolean_t& operator /=(boolean_t const argument) noexcept { this -> value /= argument; return *this; }
            inline boolean_t& operator %=(boolean_t const argument) noexcept { this -> value %= argument; return *this; }
            inline boolean_t& operator ^=(boolean_t const argument) noexcept { this -> value ^= argument; return *this; }
            inline boolean_t& operator &=(boolean_t const argument) noexcept { this -> value &= argument; return *this; }
            inline boolean_t& operator |=(boolean_t const argument) noexcept { this -> value |= argument; return *this; }
            inline boolean_t operator ++(int const) noexcept { (this -> value)++; return *this; }
            inline boolean_t& operator ++(void) noexcept { ++(this -> value); return *this; }
            constexpr inline operator bool(void) const noexcept { return this -> value; }
    };

    /* Import > Boolean */
    #include "boolean.cpp"
#else
    enum boolean_t {false = 0, true = !false};
#endif
