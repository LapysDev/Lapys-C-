/* ... Class > Boolean --- REDACT (Lapys) */
#ifdef __bool_true_false_are_defined
    struct boolean {
        private: bool value : 1;
        public:
            constexpr boolean(bool const = false);

            inline boolean& operator =(boolean const argument) noexcept { this -> value = argument; return *this; }
            inline boolean& operator +=(boolean const argument) noexcept { this -> value += argument; return *this; }
            inline boolean& operator -=(boolean const argument) noexcept { this -> value -= argument; return *this; }
            inline boolean& operator *=(boolean const argument) noexcept { this -> value *= argument; return *this; }
            inline boolean& operator /=(boolean const argument) noexcept { this -> value /= argument; return *this; }
            inline boolean& operator %=(boolean const argument) noexcept { this -> value %= argument; return *this; }
            inline boolean& operator ^=(boolean const argument) noexcept { this -> value ^= argument; return *this; }
            inline boolean& operator &=(boolean const argument) noexcept { this -> value &= argument; return *this; }
            inline boolean& operator |=(boolean const argument) noexcept { this -> value |= argument; return *this; }
            inline boolean operator ++(int const) noexcept { (this -> value)++; return *this; }
            inline boolean& operator ++(void) noexcept { ++(this -> value); return *this; }
            constexpr inline operator bool(void) const noexcept { return this -> value; }
    };

    /* Import > Boolean */
    #include "boolean.cpp"
#else
    enum boolean {false = 0, true = !false};
#endif
