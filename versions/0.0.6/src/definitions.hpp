/* Definition > ... */
#ifndef addressof
#define addressof(pointer) (&const_cast<int&>(reinterpret_cast<const volatile int&>(pointer)))
#endif

#ifdef __cplusplus
typedef struct boolean {
    // [...]
    private:
        // Initialization > Value
        enum : unsigned char {boolean_false = (0u == 1u), boolean_true = !boolean_false} value : 8;

    // [...]
    public:
        // [Constructor]
        inline boolean(const unsigned char argument) : value{argument ? this -> boolean_true : this -> boolean_false} {}
        inline boolean(void) : value{this -> boolean_false} {}

        inline boolean(boolean& argument) : value{argument.value} {}
        inline boolean(boolean&& argument) : value{argument.value} {}
        inline boolean(const boolean& argument) : value{argument.value} {}
        inline boolean(const boolean&& argument) : value{argument.value} {}

        // [Operator]
            // [=]
            inline unsigned char operator =(const unsigned char argument) { this -> value = argument ? this -> boolean_true : this -> boolean_false; return argument; }

            inline boolean& operator =(boolean& argument) { this -> value = argument.value; return argument; }
            inline boolean& operator =(boolean&& argument) { this -> value = argument.value; return argument; }
            inline const boolean& operator =(const boolean& argument) { this -> value = argument.value; return argument; }
            inline const boolean& operator =(const boolean&& argument) { this -> value = argument.value; return argument; }

            // [+=]
            inline unsigned char operator +=(const unsigned char argument) { if (argument && (argument & 1u)) this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator +=(unsigned char& argumentA, boolean& argumentB) { argumentA += (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator +=(unsigned char& argumentA, boolean&& argumentB) { argumentA += (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator +=(unsigned char& argumentA, const boolean& argumentB) { argumentA += (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator +=(unsigned char& argumentA, const boolean&& argumentB) { argumentA += (unsigned char) argumentB; return argumentB; }

            inline boolean operator +=(const boolean argument) { if (argument.value == argument.boolean_true) this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return argument; }

            // [-=]
            inline unsigned char operator -=(const unsigned char argument) { if (argument && (argument & 1u)) this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator -=(unsigned char& argumentA, boolean& argumentB) { argumentA -= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator -=(unsigned char& argumentA, boolean&& argumentB) { argumentA -= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator -=(unsigned char& argumentA, const boolean& argumentB) { argumentA -= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator -=(unsigned char& argumentA, const boolean&& argumentB) { argumentA -= (unsigned char) argumentB; return argumentB; }

            inline boolean operator -=(const boolean argument) { if (argument.value == argument.boolean_true) this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return argument; }

            // [*=]
            inline unsigned char operator *=(const unsigned char argument) { if (!argument) this -> value = this -> boolean_false; return argument; }
            friend inline boolean& operator *=(unsigned char& argumentA, boolean& argumentB) { argumentA *= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator *=(unsigned char& argumentA, boolean&& argumentB) { argumentA *= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator *=(unsigned char& argumentA, const boolean& argumentB) { argumentA *= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator *=(unsigned char& argumentA, const boolean&& argumentB) { argumentA *= (unsigned char) argumentB; return argumentB; }

            inline boolean operator *=(const boolean argument) { if (argument.value == argument.boolean_false) this -> value = this -> boolean_false; return argument; }

            // [/=]
            inline unsigned char operator /=(const unsigned char argument) { if (!argument) this -> value = (1u / argument) ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator /=(unsigned char& argumentA, boolean& argumentB) { argumentA /= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator /=(unsigned char& argumentA, boolean&& argumentB) { argumentA /= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator /=(unsigned char& argumentA, const boolean& argumentB) { argumentA /= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator /=(unsigned char& argumentA, const boolean&& argumentB) { argumentA /= (unsigned char) argumentB; return argumentB; }

            inline boolean operator /=(const boolean argument) { if (argument.value == argument.boolean_false) this -> value = (1u / (unsigned char) argument) ? this -> boolean_true : this -> boolean_false; return argument; }

            // [%=]
            inline unsigned char operator %=(const unsigned char argument) { if (!argument) this -> value = (1u % argument) ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator %=(unsigned char& argumentA, boolean& argumentB) { argumentA %= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator %=(unsigned char& argumentA, boolean&& argumentB) { argumentA %= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator %=(unsigned char& argumentA, const boolean& argumentB) { argumentA %= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator %=(unsigned char& argumentA, const boolean&& argumentB) { argumentA %= (unsigned char) argumentB; return argumentB; }

            inline boolean operator %=(const boolean argument) { if (argument.value == argument.boolean_false) this -> value = (1u % (unsigned char) argument) ? this -> boolean_true : this -> boolean_false; return argument; }

            // [^=]
            inline unsigned char operator ^=(const unsigned char argument) { this -> value = (((unsigned char) *this) ^ argument) ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator ^=(unsigned char& argumentA, boolean& argumentB) { argumentA ^= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator ^=(unsigned char& argumentA, boolean&& argumentB) { argumentA ^= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator ^=(unsigned char& argumentA, const boolean& argumentB) { argumentA ^= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator ^=(unsigned char& argumentA, const boolean&& argumentB) { argumentA ^= (unsigned char) argumentB; return argumentB; }

            inline boolean operator ^=(const boolean argument) { this -> value = (((unsigned char) *this) ^ (unsigned char) argument) ? this -> boolean_true : this -> boolean_false; return argument; }

            // [&=]
            inline unsigned char operator &=(const unsigned char argument) { this -> value = (((unsigned char) *this) & argument) ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator &=(unsigned char& argumentA, boolean& argumentB) { argumentA &= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator &=(unsigned char& argumentA, boolean&& argumentB) { argumentA &= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator &=(unsigned char& argumentA, const boolean& argumentB) { argumentA &= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator &=(unsigned char& argumentA, const boolean&& argumentB) { argumentA &= (unsigned char) argumentB; return argumentB; }

            inline boolean operator &=(const boolean argument) { this -> value = (((unsigned char) *this) & (unsigned char) argument) ? this -> boolean_true : this -> boolean_false; return argument; }

            // [|=]
            inline unsigned char operator |=(const unsigned char argument) { this -> value = (((unsigned char) *this) | argument) ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator |=(unsigned char& argumentA, boolean& argumentB) { argumentA |= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator |=(unsigned char& argumentA, boolean&& argumentB) { argumentA |= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator |=(unsigned char& argumentA, const boolean& argumentB) { argumentA |= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator |=(unsigned char& argumentA, const boolean&& argumentB) { argumentA |= (unsigned char) argumentB; return argumentB; }

            inline boolean operator |=(const boolean argument) { this -> value = (((unsigned char) *this) | (unsigned char) argument) ? this -> boolean_true : this -> boolean_false; return argument; }

            // [>>=]
            inline unsigned char operator >>=(const unsigned char argument) { this -> value = (((unsigned char) *this) >> argument) ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator >>=(unsigned char& argumentA, boolean& argumentB) { argumentA >>= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator >>=(unsigned char& argumentA, boolean&& argumentB) { argumentA >>= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator >>=(unsigned char& argumentA, const boolean& argumentB) { argumentA >>= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator >>=(unsigned char& argumentA, const boolean&& argumentB) { argumentA >>= (unsigned char) argumentB; return argumentB; }

            inline boolean operator >>=(const boolean argument) { this -> value = (((unsigned char) *this) >> (unsigned char) argument) ? this -> boolean_true : this -> boolean_false; return argument; }

            // [<<=]
            inline unsigned char operator <<=(const unsigned char argument) { this -> value = (((unsigned char) *this) << argument) ? this -> boolean_true : this -> boolean_false; return argument; }
            friend inline boolean& operator <<=(unsigned char& argumentA, boolean& argumentB) { argumentA <<= (unsigned char) argumentB; return argumentB; }
            friend inline boolean& operator <<=(unsigned char& argumentA, boolean&& argumentB) { argumentA <<= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator <<=(unsigned char& argumentA, const boolean& argumentB) { argumentA <<= (unsigned char) argumentB; return argumentB; }
            friend inline const boolean& operator <<=(unsigned char& argumentA, const boolean&& argumentB) { argumentA <<= (unsigned char) argumentB; return argumentB; }

            inline boolean operator <<=(const boolean argument) { this -> value = (((unsigned char) *this) << (unsigned char) argument) ? this -> boolean_true : this -> boolean_false; return argument; }

            // [++]
            inline boolean& operator ++(int) { this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }
            inline boolean& operator ++(void) { this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }

            // [--]
            inline boolean& operator --(int) { this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }
            inline boolean& operator --(void) { this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }

            // [...]
            inline operator unsigned char() const { return this -> value == this -> boolean_true; }
} boolean;
#else
typedef bool boolean;
#endif

#ifndef char8_t
typedef struct char8_t {
    // [...]
    private:
        // Initialization > Value
        unsigned char value;

    // [...]
    public:
        // [Constructor]
        inline char8_t(const char argument) : value{(unsigned char) argument} {}
        inline char8_t(const char16_t argument) : value{(unsigned char) argument} {}
        inline char8_t(const char32_t argument) : value{(unsigned char) argument} {}
        inline char8_t(const double argument) : value{(unsigned char) argument} {}
        inline char8_t(const float argument) : value{(unsigned char) argument} {}
        inline char8_t(const int argument) : value{(unsigned char) argument} {}
        inline char8_t(const long argument) : value{(unsigned char) argument} {}
        inline char8_t(const long double argument) : value{(unsigned char) argument} {}
        inline char8_t(const long long argument) : value{(unsigned char) argument} {}
        inline char8_t(const short argument) : value{(unsigned char) argument} {}
        inline char8_t(const signed char argument) : value{(unsigned char) argument} {}
        inline char8_t(const unsigned char argument) : value{(unsigned char) argument} {}
        inline char8_t(const unsigned int argument) : value{(unsigned char) argument} {}
        inline char8_t(const unsigned long argument) : value{(unsigned char) argument} {}
        inline char8_t(const unsigned long long argument) : value{(unsigned char) argument} {}
        inline char8_t(const unsigned short argument) : value{(unsigned char) argument} {}
        inline char8_t(void) {}
        inline char8_t(void* argument) : value{(unsigned char) (int) argument} {}
        inline char8_t(const void* argument) : value{(unsigned char) (int) argument} {}
        inline char8_t(const wchar_t argument) : value{(unsigned char) argument} {}

        inline char8_t(char8_t& argument) : value{argument.value} {}
        inline char8_t(char8_t&& argument) : value{argument.value} {}
        inline char8_t(const char8_t& argument) : value{argument.value} {}
        inline char8_t(const char8_t&& argument) : value{argument.value} {}

        // [Operator]
            // [+]
            inline unsigned char operator +() const { return this -> value; }

            inline boolean operator +(const boolean argument) const { return this -> value + argument; }
            friend inline boolean operator +(const boolean argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline boolean operator +(const boolean argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline boolean operator +(const boolean argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline boolean operator +(const boolean argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline char operator +(const char argument) const { return this -> value + argument; }
            friend inline char operator +(const char argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline char operator +(const char argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline char operator +(const char argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline char operator +(const char argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline char16_t operator +(const char16_t argument) const { return this -> value + argument; }
            friend inline char16_t operator +(const char16_t argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline char16_t operator +(const char16_t argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline char16_t operator +(const char16_t argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline char16_t operator +(const char16_t argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline char32_t operator +(const char32_t argument) const { return this -> value + argument; }
            friend inline char32_t operator +(const char32_t argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline char32_t operator +(const char32_t argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline char32_t operator +(const char32_t argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline char32_t operator +(const char32_t argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline double operator +(const double argument) const { return this -> value + argument; }
            friend inline double operator +(const double argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline double operator +(const double argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline double operator +(const double argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline double operator +(const double argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline float operator +(const float argument) const { return this -> value + argument; }
            friend inline float operator +(const float argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline float operator +(const float argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline float operator +(const float argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline float operator +(const float argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline int operator +(const int argument) const { return this -> value + argument; }
            friend inline int operator +(const int argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline int operator +(const int argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline int operator +(const int argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline int operator +(const int argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline long operator +(const long argument) const { return this -> value + argument; }
            friend inline long operator +(const long argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline long operator +(const long argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline long operator +(const long argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline long operator +(const long argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline long double operator +(const long double argument) const { return this -> value + argument; }
            friend inline long double operator +(const long double argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline long double operator +(const long double argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline long double operator +(const long double argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline long double operator +(const long double argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline long long operator +(const long long argument) const { return this -> value + argument; }
            friend inline long long operator +(const long long argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline long long operator +(const long long argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline long long operator +(const long long argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline long long operator +(const long long argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline short operator +(const short argument) const { return this -> value + argument; }
            friend inline short operator +(const short argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline short operator +(const short argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline short operator +(const short argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline short operator +(const short argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline signed char operator +(const signed char argument) const { return this -> value + argument; }
            friend inline signed char operator +(const signed char argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline signed char operator +(const signed char argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline signed char operator +(const signed char argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline signed char operator +(const signed char argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline unsigned char operator +(const unsigned char argument) const { return this -> value + argument; }
            friend inline unsigned char operator +(const unsigned char argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned char operator +(const unsigned char argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned char operator +(const unsigned char argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned char operator +(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline unsigned int operator +(const unsigned int argument) const { return this -> value + argument; }
            friend inline unsigned int operator +(const unsigned int argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned int operator +(const unsigned int argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned int operator +(const unsigned int argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned int operator +(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline unsigned long operator +(const unsigned long argument) const { return this -> value + argument; }
            friend inline unsigned long operator +(const unsigned long argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned long operator +(const unsigned long argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned long operator +(const unsigned long argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned long operator +(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline unsigned long long operator +(const unsigned long long argument) const { return this -> value + argument; }
            friend inline unsigned long long operator +(const unsigned long long argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned long long operator +(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned long long operator +(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned long long operator +(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline unsigned short operator +(const unsigned short argument) const { return this -> value + argument; }
            friend inline unsigned short operator +(const unsigned short argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned short operator +(const unsigned short argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned short operator +(const unsigned short argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline unsigned short operator +(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline wchar_t operator +(const wchar_t argument) const { return this -> value + argument; }
            friend inline wchar_t operator +(const wchar_t argumentA, char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline wchar_t operator +(const wchar_t argumentA, char8_t&& argumentB) { return argumentA + argumentB.value; }
            friend inline wchar_t operator +(const wchar_t argumentA, const char8_t& argumentB) { return argumentA + argumentB.value; }
            friend inline wchar_t operator +(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA + argumentB.value; }

            inline char8_t operator +(const char8_t argument) const { return this -> value + argument.value; }

            // [-]
            inline unsigned char operator -() const { return -(this -> value); }

            inline boolean operator -(const boolean argument) const { return this -> value - argument; }
            friend inline boolean operator -(const boolean argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline boolean operator -(const boolean argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline boolean operator -(const boolean argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline boolean operator -(const boolean argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline char operator -(const char argument) const { return this -> value - argument; }
            friend inline char operator -(const char argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline char operator -(const char argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline char operator -(const char argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline char operator -(const char argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline char16_t operator -(const char16_t argument) const { return this -> value - argument; }
            friend inline char16_t operator -(const char16_t argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline char16_t operator -(const char16_t argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline char16_t operator -(const char16_t argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline char16_t operator -(const char16_t argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline char32_t operator -(const char32_t argument) const { return this -> value - argument; }
            friend inline char32_t operator -(const char32_t argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline char32_t operator -(const char32_t argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline char32_t operator -(const char32_t argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline char32_t operator -(const char32_t argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline double operator -(const double argument) const { return this -> value - argument; }
            friend inline double operator -(const double argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline double operator -(const double argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline double operator -(const double argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline double operator -(const double argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline float operator -(const float argument) const { return this -> value - argument; }
            friend inline float operator -(const float argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline float operator -(const float argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline float operator -(const float argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline float operator -(const float argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline int operator -(const int argument) const { return this -> value - argument; }
            friend inline int operator -(const int argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline int operator -(const int argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline int operator -(const int argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline int operator -(const int argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline long operator -(const long argument) const { return this -> value - argument; }
            friend inline long operator -(const long argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline long operator -(const long argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline long operator -(const long argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline long operator -(const long argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline long double operator -(const long double argument) const { return this -> value - argument; }
            friend inline long double operator -(const long double argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline long double operator -(const long double argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline long double operator -(const long double argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline long double operator -(const long double argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline long long operator -(const long long argument) const { return this -> value - argument; }
            friend inline long long operator -(const long long argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline long long operator -(const long long argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline long long operator -(const long long argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline long long operator -(const long long argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline short operator -(const short argument) const { return this -> value - argument; }
            friend inline short operator -(const short argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline short operator -(const short argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline short operator -(const short argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline short operator -(const short argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline signed char operator -(const signed char argument) const { return this -> value - argument; }
            friend inline signed char operator -(const signed char argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline signed char operator -(const signed char argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline signed char operator -(const signed char argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline signed char operator -(const signed char argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline unsigned char operator -(const unsigned char argument) const { return this -> value - argument; }
            friend inline unsigned char operator -(const unsigned char argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned char operator -(const unsigned char argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned char operator -(const unsigned char argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned char operator -(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline unsigned int operator -(const unsigned int argument) const { return this -> value - argument; }
            friend inline unsigned int operator -(const unsigned int argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned int operator -(const unsigned int argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned int operator -(const unsigned int argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned int operator -(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline unsigned long operator -(const unsigned long argument) const { return this -> value - argument; }
            friend inline unsigned long operator -(const unsigned long argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned long operator -(const unsigned long argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned long operator -(const unsigned long argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned long operator -(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline unsigned long long operator -(const unsigned long long argument) const { return this -> value - argument; }
            friend inline unsigned long long operator -(const unsigned long long argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned long long operator -(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned long long operator -(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned long long operator -(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline unsigned short operator -(const unsigned short argument) const { return this -> value - argument; }
            friend inline unsigned short operator -(const unsigned short argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned short operator -(const unsigned short argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned short operator -(const unsigned short argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline unsigned short operator -(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline wchar_t operator -(const wchar_t argument) const { return this -> value - argument; }
            friend inline wchar_t operator -(const wchar_t argumentA, char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline wchar_t operator -(const wchar_t argumentA, char8_t&& argumentB) { return argumentA - argumentB.value; }
            friend inline wchar_t operator -(const wchar_t argumentA, const char8_t& argumentB) { return argumentA - argumentB.value; }
            friend inline wchar_t operator -(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA - argumentB.value; }

            inline char8_t operator -(const char8_t argument) const { return this -> value - argument.value; }

            // [*]
            inline boolean operator *(const boolean argument) const { return this -> value * argument; }
            friend inline boolean operator *(const boolean argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline boolean operator *(const boolean argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline boolean operator *(const boolean argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline boolean operator *(const boolean argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline char operator *(const char argument) const { return this -> value * argument; }
            friend inline char operator *(const char argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline char operator *(const char argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline char operator *(const char argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline char operator *(const char argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline char16_t operator *(const char16_t argument) const { return this -> value * argument; }
            friend inline char16_t operator *(const char16_t argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline char16_t operator *(const char16_t argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline char16_t operator *(const char16_t argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline char16_t operator *(const char16_t argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline char32_t operator *(const char32_t argument) const { return this -> value * argument; }
            friend inline char32_t operator *(const char32_t argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline char32_t operator *(const char32_t argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline char32_t operator *(const char32_t argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline char32_t operator *(const char32_t argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline double operator *(const double argument) const { return this -> value * argument; }
            friend inline double operator *(const double argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline double operator *(const double argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline double operator *(const double argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline double operator *(const double argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline float operator *(const float argument) const { return this -> value * argument; }
            friend inline float operator *(const float argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline float operator *(const float argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline float operator *(const float argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline float operator *(const float argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline int operator *(const int argument) const { return this -> value * argument; }
            friend inline int operator *(const int argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline int operator *(const int argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline int operator *(const int argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline int operator *(const int argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline long operator *(const long argument) const { return this -> value * argument; }
            friend inline long operator *(const long argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline long operator *(const long argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline long operator *(const long argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline long operator *(const long argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline long double operator *(const long double argument) const { return this -> value * argument; }
            friend inline long double operator *(const long double argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline long double operator *(const long double argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline long double operator *(const long double argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline long double operator *(const long double argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline long long operator *(const long long argument) const { return this -> value * argument; }
            friend inline long long operator *(const long long argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline long long operator *(const long long argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline long long operator *(const long long argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline long long operator *(const long long argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline short operator *(const short argument) const { return this -> value * argument; }
            friend inline short operator *(const short argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline short operator *(const short argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline short operator *(const short argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline short operator *(const short argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline signed char operator *(const signed char argument) const { return this -> value * argument; }
            friend inline signed char operator *(const signed char argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline signed char operator *(const signed char argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline signed char operator *(const signed char argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline signed char operator *(const signed char argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline unsigned char operator *(const unsigned char argument) const { return this -> value * argument; }
            friend inline unsigned char operator *(const unsigned char argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned char operator *(const unsigned char argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned char operator *(const unsigned char argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned char operator *(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline unsigned int operator *(const unsigned int argument) const { return this -> value * argument; }
            friend inline unsigned int operator *(const unsigned int argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned int operator *(const unsigned int argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned int operator *(const unsigned int argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned int operator *(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline unsigned long operator *(const unsigned long argument) const { return this -> value * argument; }
            friend inline unsigned long operator *(const unsigned long argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned long operator *(const unsigned long argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned long operator *(const unsigned long argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned long operator *(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline unsigned long long operator *(const unsigned long long argument) const { return this -> value * argument; }
            friend inline unsigned long long operator *(const unsigned long long argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned long long operator *(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned long long operator *(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned long long operator *(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline unsigned short operator *(const unsigned short argument) const { return this -> value * argument; }
            friend inline unsigned short operator *(const unsigned short argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned short operator *(const unsigned short argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned short operator *(const unsigned short argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline unsigned short operator *(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline wchar_t operator *(const wchar_t argument) const { return this -> value * argument; }
            friend inline wchar_t operator *(const wchar_t argumentA, char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline wchar_t operator *(const wchar_t argumentA, char8_t&& argumentB) { return argumentA * argumentB.value; }
            friend inline wchar_t operator *(const wchar_t argumentA, const char8_t& argumentB) { return argumentA * argumentB.value; }
            friend inline wchar_t operator *(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA * argumentB.value; }

            inline char8_t operator *(const char8_t argument) const { return this -> value * argument.value; }

            // [/]
            inline boolean operator /(const boolean argument) const { return this -> value / argument; }
            friend inline boolean operator /(const boolean argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline boolean operator /(const boolean argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline boolean operator /(const boolean argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline boolean operator /(const boolean argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline char operator /(const char argument) const { return this -> value / argument; }
            friend inline char operator /(const char argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline char operator /(const char argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline char operator /(const char argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline char operator /(const char argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline char16_t operator /(const char16_t argument) const { return this -> value / argument; }
            friend inline char16_t operator /(const char16_t argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline char16_t operator /(const char16_t argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline char16_t operator /(const char16_t argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline char16_t operator /(const char16_t argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline char32_t operator /(const char32_t argument) const { return this -> value / argument; }
            friend inline char32_t operator /(const char32_t argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline char32_t operator /(const char32_t argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline char32_t operator /(const char32_t argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline char32_t operator /(const char32_t argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline double operator /(const double argument) const { return this -> value / argument; }
            friend inline double operator /(const double argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline double operator /(const double argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline double operator /(const double argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline double operator /(const double argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline float operator /(const float argument) const { return this -> value / argument; }
            friend inline float operator /(const float argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline float operator /(const float argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline float operator /(const float argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline float operator /(const float argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline int operator /(const int argument) const { return this -> value / argument; }
            friend inline int operator /(const int argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline int operator /(const int argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline int operator /(const int argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline int operator /(const int argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline long operator /(const long argument) const { return this -> value / argument; }
            friend inline long operator /(const long argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline long operator /(const long argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline long operator /(const long argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline long operator /(const long argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline long double operator /(const long double argument) const { return this -> value / argument; }
            friend inline long double operator /(const long double argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline long double operator /(const long double argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline long double operator /(const long double argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline long double operator /(const long double argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline long long operator /(const long long argument) const { return this -> value / argument; }
            friend inline long long operator /(const long long argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline long long operator /(const long long argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline long long operator /(const long long argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline long long operator /(const long long argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline short operator /(const short argument) const { return this -> value / argument; }
            friend inline short operator /(const short argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline short operator /(const short argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline short operator /(const short argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline short operator /(const short argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline signed char operator /(const signed char argument) const { return this -> value / argument; }
            friend inline signed char operator /(const signed char argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline signed char operator /(const signed char argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline signed char operator /(const signed char argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline signed char operator /(const signed char argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline unsigned char operator /(const unsigned char argument) const { return this -> value / argument; }
            friend inline unsigned char operator /(const unsigned char argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned char operator /(const unsigned char argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned char operator /(const unsigned char argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned char operator /(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline unsigned int operator /(const unsigned int argument) const { return this -> value / argument; }
            friend inline unsigned int operator /(const unsigned int argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned int operator /(const unsigned int argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned int operator /(const unsigned int argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned int operator /(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline unsigned long operator /(const unsigned long argument) const { return this -> value / argument; }
            friend inline unsigned long operator /(const unsigned long argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned long operator /(const unsigned long argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned long operator /(const unsigned long argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned long operator /(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline unsigned long long operator /(const unsigned long long argument) const { return this -> value / argument; }
            friend inline unsigned long long operator /(const unsigned long long argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned long long operator /(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned long long operator /(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned long long operator /(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline unsigned short operator /(const unsigned short argument) const { return this -> value / argument; }
            friend inline unsigned short operator /(const unsigned short argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned short operator /(const unsigned short argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned short operator /(const unsigned short argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline unsigned short operator /(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline wchar_t operator /(const wchar_t argument) const { return this -> value / argument; }
            friend inline wchar_t operator /(const wchar_t argumentA, char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline wchar_t operator /(const wchar_t argumentA, char8_t&& argumentB) { return argumentA / argumentB.value; }
            friend inline wchar_t operator /(const wchar_t argumentA, const char8_t& argumentB) { return argumentA / argumentB.value; }
            friend inline wchar_t operator /(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA / argumentB.value; }

            inline char8_t operator /(const char8_t argument) const { return this -> value / argument.value; }

            // [%]
            inline boolean operator %(const boolean argument) const { return this -> value % argument; }
            friend inline boolean operator %(const boolean argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline boolean operator %(const boolean argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline boolean operator %(const boolean argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline boolean operator %(const boolean argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline char operator %(const char argument) const { return this -> value % argument; }
            friend inline char operator %(const char argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline char operator %(const char argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline char operator %(const char argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline char operator %(const char argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline char16_t operator %(const char16_t argument) const { return this -> value % argument; }
            friend inline char16_t operator %(const char16_t argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline char16_t operator %(const char16_t argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline char16_t operator %(const char16_t argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline char16_t operator %(const char16_t argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline char32_t operator %(const char32_t argument) const { return this -> value % argument; }
            friend inline char32_t operator %(const char32_t argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline char32_t operator %(const char32_t argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline char32_t operator %(const char32_t argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline char32_t operator %(const char32_t argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline int operator %(const int argument) const { return this -> value % argument; }
            friend inline int operator %(const int argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline int operator %(const int argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline int operator %(const int argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline int operator %(const int argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline long operator %(const long argument) const { return this -> value % argument; }
            friend inline long operator %(const long argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline long operator %(const long argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline long operator %(const long argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline long operator %(const long argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline long long operator %(const long long argument) const { return this -> value % argument; }
            friend inline long long operator %(const long long argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline long long operator %(const long long argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline long long operator %(const long long argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline long long operator %(const long long argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline short operator %(const short argument) const { return this -> value % argument; }
            friend inline short operator %(const short argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline short operator %(const short argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline short operator %(const short argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline short operator %(const short argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline signed char operator %(const signed char argument) const { return this -> value % argument; }
            friend inline signed char operator %(const signed char argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline signed char operator %(const signed char argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline signed char operator %(const signed char argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline signed char operator %(const signed char argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline unsigned char operator %(const unsigned char argument) const { return this -> value % argument; }
            friend inline unsigned char operator %(const unsigned char argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned char operator %(const unsigned char argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned char operator %(const unsigned char argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned char operator %(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline unsigned int operator %(const unsigned int argument) const { return this -> value % argument; }
            friend inline unsigned int operator %(const unsigned int argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned int operator %(const unsigned int argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned int operator %(const unsigned int argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned int operator %(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline unsigned long operator %(const unsigned long argument) const { return this -> value % argument; }
            friend inline unsigned long operator %(const unsigned long argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned long operator %(const unsigned long argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned long operator %(const unsigned long argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned long operator %(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline unsigned long long operator %(const unsigned long long argument) const { return this -> value % argument; }
            friend inline unsigned long long operator %(const unsigned long long argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned long long operator %(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned long long operator %(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned long long operator %(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline unsigned short operator %(const unsigned short argument) const { return this -> value % argument; }
            friend inline unsigned short operator %(const unsigned short argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned short operator %(const unsigned short argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned short operator %(const unsigned short argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline unsigned short operator %(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline wchar_t operator %(const wchar_t argument) const { return this -> value % argument; }
            friend inline wchar_t operator %(const wchar_t argumentA, char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline wchar_t operator %(const wchar_t argumentA, char8_t&& argumentB) { return argumentA % argumentB.value; }
            friend inline wchar_t operator %(const wchar_t argumentA, const char8_t& argumentB) { return argumentA % argumentB.value; }
            friend inline wchar_t operator %(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA % argumentB.value; }

            inline char8_t operator %(const char8_t argument) const { return this -> value % argument.value; }

            // [^]
            inline boolean operator ^(const boolean argument) const { return this -> value ^ argument; }
            friend inline boolean operator ^(const boolean argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline boolean operator ^(const boolean argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline boolean operator ^(const boolean argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline boolean operator ^(const boolean argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline char operator ^(const char argument) const { return this -> value ^ argument; }
            friend inline char operator ^(const char argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char operator ^(const char argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char operator ^(const char argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char operator ^(const char argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline char16_t operator ^(const char16_t argument) const { return this -> value ^ argument; }
            friend inline char16_t operator ^(const char16_t argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char16_t operator ^(const char16_t argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char16_t operator ^(const char16_t argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char16_t operator ^(const char16_t argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline char32_t operator ^(const char32_t argument) const { return this -> value ^ argument; }
            friend inline char32_t operator ^(const char32_t argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char32_t operator ^(const char32_t argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char32_t operator ^(const char32_t argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline char32_t operator ^(const char32_t argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline int operator ^(const int argument) const { return this -> value ^ argument; }
            friend inline int operator ^(const int argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline int operator ^(const int argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline int operator ^(const int argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline int operator ^(const int argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline long operator ^(const long argument) const { return this -> value ^ argument; }
            friend inline long operator ^(const long argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline long operator ^(const long argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline long operator ^(const long argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline long operator ^(const long argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline long long operator ^(const long long argument) const { return this -> value ^ argument; }
            friend inline long long operator ^(const long long argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline long long operator ^(const long long argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline long long operator ^(const long long argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline long long operator ^(const long long argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline short operator ^(const short argument) const { return this -> value ^ argument; }
            friend inline short operator ^(const short argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline short operator ^(const short argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline short operator ^(const short argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline short operator ^(const short argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline signed char operator ^(const signed char argument) const { return this -> value ^ argument; }
            friend inline signed char operator ^(const signed char argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline signed char operator ^(const signed char argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline signed char operator ^(const signed char argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline signed char operator ^(const signed char argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline unsigned char operator ^(const unsigned char argument) const { return this -> value ^ argument; }
            friend inline unsigned char operator ^(const unsigned char argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned char operator ^(const unsigned char argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned char operator ^(const unsigned char argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned char operator ^(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline unsigned int operator ^(const unsigned int argument) const { return this -> value ^ argument; }
            friend inline unsigned int operator ^(const unsigned int argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned int operator ^(const unsigned int argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned int operator ^(const unsigned int argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned int operator ^(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline unsigned long operator ^(const unsigned long argument) const { return this -> value ^ argument; }
            friend inline unsigned long operator ^(const unsigned long argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned long operator ^(const unsigned long argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned long operator ^(const unsigned long argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned long operator ^(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline unsigned long long operator ^(const unsigned long long argument) const { return this -> value ^ argument; }
            friend inline unsigned long long operator ^(const unsigned long long argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned long long operator ^(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned long long operator ^(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned long long operator ^(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline unsigned short operator ^(const unsigned short argument) const { return this -> value ^ argument; }
            friend inline unsigned short operator ^(const unsigned short argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned short operator ^(const unsigned short argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned short operator ^(const unsigned short argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline unsigned short operator ^(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline wchar_t operator ^(const wchar_t argument) const { return this -> value ^ argument; }
            friend inline wchar_t operator ^(const wchar_t argumentA, char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline wchar_t operator ^(const wchar_t argumentA, char8_t&& argumentB) { return argumentA ^ argumentB.value; }
            friend inline wchar_t operator ^(const wchar_t argumentA, const char8_t& argumentB) { return argumentA ^ argumentB.value; }
            friend inline wchar_t operator ^(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA ^ argumentB.value; }

            inline char8_t operator ^(const char8_t argument) const { return this -> value ^ argument.value; }

            // [&]
            inline boolean operator &(const boolean argument) const { return this -> value & argument; }
            friend inline boolean operator &(const boolean argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline boolean operator &(const boolean argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline boolean operator &(const boolean argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline boolean operator &(const boolean argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline char operator &(const char argument) const { return this -> value & argument; }
            friend inline char operator &(const char argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline char operator &(const char argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline char operator &(const char argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline char operator &(const char argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline char16_t operator &(const char16_t argument) const { return this -> value & argument; }
            friend inline char16_t operator &(const char16_t argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline char16_t operator &(const char16_t argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline char16_t operator &(const char16_t argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline char16_t operator &(const char16_t argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline char32_t operator &(const char32_t argument) const { return this -> value & argument; }
            friend inline char32_t operator &(const char32_t argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline char32_t operator &(const char32_t argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline char32_t operator &(const char32_t argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline char32_t operator &(const char32_t argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline int operator &(const int argument) const { return this -> value & argument; }
            friend inline int operator &(const int argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline int operator &(const int argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline int operator &(const int argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline int operator &(const int argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline long operator &(const long argument) const { return this -> value & argument; }
            friend inline long operator &(const long argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline long operator &(const long argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline long operator &(const long argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline long operator &(const long argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline long long operator &(const long long argument) const { return this -> value & argument; }
            friend inline long long operator &(const long long argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline long long operator &(const long long argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline long long operator &(const long long argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline long long operator &(const long long argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline short operator &(const short argument) const { return this -> value & argument; }
            friend inline short operator &(const short argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline short operator &(const short argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline short operator &(const short argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline short operator &(const short argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline signed char operator &(const signed char argument) const { return this -> value & argument; }
            friend inline signed char operator &(const signed char argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline signed char operator &(const signed char argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline signed char operator &(const signed char argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline signed char operator &(const signed char argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline unsigned char operator &(const unsigned char argument) const { return this -> value & argument; }
            friend inline unsigned char operator &(const unsigned char argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned char operator &(const unsigned char argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned char operator &(const unsigned char argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned char operator &(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline unsigned int operator &(const unsigned int argument) const { return this -> value & argument; }
            friend inline unsigned int operator &(const unsigned int argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned int operator &(const unsigned int argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned int operator &(const unsigned int argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned int operator &(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline unsigned long operator &(const unsigned long argument) const { return this -> value & argument; }
            friend inline unsigned long operator &(const unsigned long argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned long operator &(const unsigned long argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned long operator &(const unsigned long argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned long operator &(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline unsigned long long operator &(const unsigned long long argument) const { return this -> value & argument; }
            friend inline unsigned long long operator &(const unsigned long long argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned long long operator &(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned long long operator &(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned long long operator &(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline unsigned short operator &(const unsigned short argument) const { return this -> value & argument; }
            friend inline unsigned short operator &(const unsigned short argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned short operator &(const unsigned short argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned short operator &(const unsigned short argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline unsigned short operator &(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline wchar_t operator &(const wchar_t argument) const { return this -> value & argument; }
            friend inline wchar_t operator &(const wchar_t argumentA, char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline wchar_t operator &(const wchar_t argumentA, char8_t&& argumentB) { return argumentA & argumentB.value; }
            friend inline wchar_t operator &(const wchar_t argumentA, const char8_t& argumentB) { return argumentA & argumentB.value; }
            friend inline wchar_t operator &(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA & argumentB.value; }

            inline char8_t operator &(const char8_t argument) const { return this -> value & argument.value; }

            // [|]
            inline boolean operator |(const boolean argument) const { return this -> value | argument; }
            friend inline boolean operator |(const boolean argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline boolean operator |(const boolean argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline boolean operator |(const boolean argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline boolean operator |(const boolean argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline char operator |(const char argument) const { return this -> value | argument; }
            friend inline char operator |(const char argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline char operator |(const char argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline char operator |(const char argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline char operator |(const char argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline char16_t operator |(const char16_t argument) const { return this -> value | argument; }
            friend inline char16_t operator |(const char16_t argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline char16_t operator |(const char16_t argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline char16_t operator |(const char16_t argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline char16_t operator |(const char16_t argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline char32_t operator |(const char32_t argument) const { return this -> value | argument; }
            friend inline char32_t operator |(const char32_t argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline char32_t operator |(const char32_t argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline char32_t operator |(const char32_t argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline char32_t operator |(const char32_t argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline int operator |(const int argument) const { return this -> value | argument; }
            friend inline int operator |(const int argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline int operator |(const int argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline int operator |(const int argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline int operator |(const int argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline long operator |(const long argument) const { return this -> value | argument; }
            friend inline long operator |(const long argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline long operator |(const long argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline long operator |(const long argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline long operator |(const long argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline long long operator |(const long long argument) const { return this -> value | argument; }
            friend inline long long operator |(const long long argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline long long operator |(const long long argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline long long operator |(const long long argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline long long operator |(const long long argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline short operator |(const short argument) const { return this -> value | argument; }
            friend inline short operator |(const short argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline short operator |(const short argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline short operator |(const short argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline short operator |(const short argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline signed char operator |(const signed char argument) const { return this -> value | argument; }
            friend inline signed char operator |(const signed char argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline signed char operator |(const signed char argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline signed char operator |(const signed char argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline signed char operator |(const signed char argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline unsigned char operator |(const unsigned char argument) const { return this -> value | argument; }
            friend inline unsigned char operator |(const unsigned char argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned char operator |(const unsigned char argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned char operator |(const unsigned char argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned char operator |(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline unsigned int operator |(const unsigned int argument) const { return this -> value | argument; }
            friend inline unsigned int operator |(const unsigned int argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned int operator |(const unsigned int argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned int operator |(const unsigned int argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned int operator |(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline unsigned long operator |(const unsigned long argument) const { return this -> value | argument; }
            friend inline unsigned long operator |(const unsigned long argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned long operator |(const unsigned long argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned long operator |(const unsigned long argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned long operator |(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline unsigned long long operator |(const unsigned long long argument) const { return this -> value | argument; }
            friend inline unsigned long long operator |(const unsigned long long argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned long long operator |(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned long long operator |(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned long long operator |(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline unsigned short operator |(const unsigned short argument) const { return this -> value | argument; }
            friend inline unsigned short operator |(const unsigned short argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned short operator |(const unsigned short argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned short operator |(const unsigned short argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline unsigned short operator |(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline wchar_t operator |(const wchar_t argument) const { return this -> value | argument; }
            friend inline wchar_t operator |(const wchar_t argumentA, char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline wchar_t operator |(const wchar_t argumentA, char8_t&& argumentB) { return argumentA | argumentB.value; }
            friend inline wchar_t operator |(const wchar_t argumentA, const char8_t& argumentB) { return argumentA | argumentB.value; }
            friend inline wchar_t operator |(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA | argumentB.value; }

            inline char8_t operator |(const char8_t argument) const { return this -> value | argument.value; }

            // [~]
            inline const char8_t operator ~(void) const { return ~(this -> value); }

            // [!]
            inline const char8_t operator !(void) const { return !(this -> value); }

            // [=]
            inline boolean operator =(const boolean argument) { this -> value = (unsigned char) argument; return argument; }
            inline char operator =(const char argument) { this -> value = (unsigned char) argument; return argument; }
            inline char16_t operator =(const char16_t argument) { this -> value = (unsigned char) argument; return argument; }
            inline char32_t operator =(const char32_t argument) { this -> value = (unsigned char) argument; return argument; }
            inline double operator =(const double argument) { this -> value = (unsigned char) argument; return argument; }
            inline float operator =(const float argument) { this -> value = (unsigned char) argument; return argument; }
            inline int operator =(const int argument) { this -> value = (unsigned char) argument; return argument; }
            inline long operator =(const long argument) { this -> value = (unsigned char) argument; return argument; }
            inline long double operator =(const long double argument) { this -> value = (unsigned char) argument; return argument; }
            inline long long operator =(const long long argument) { this -> value = (unsigned char) argument; return argument; }
            inline short operator =(const short argument) { this -> value = (unsigned char) argument; return argument; }
            inline signed char operator =(const signed char argument) { this -> value = (unsigned char) argument; return argument; }
            inline unsigned char operator =(const unsigned char argument) { this -> value = (unsigned char) argument; return argument; }
            inline unsigned int operator =(const unsigned int argument) { this -> value = (unsigned char) argument; return argument; }
            inline unsigned long operator =(const unsigned long argument) { this -> value = (unsigned char) argument; return argument; }
            inline unsigned long long operator =(const unsigned long long argument) { this -> value = (unsigned char) argument; return argument; }
            inline unsigned short operator =(const unsigned short argument) { this -> value = (unsigned char) argument; return argument; }
            inline void* operator =(void* argument) { this -> value = (unsigned char) (int) argument; return argument; }
            inline const void* operator =(const void* argument) { this -> value = (unsigned char) (int) argument; return argument; }
            inline wchar_t operator =(const wchar_t argument) { this -> value = (unsigned char) argument; return argument; }

            inline const char8_t operator =(const char8_t argument) { this -> value = argument.value; return argument; }

            // [<]
            inline boolean operator <(const boolean argument) const { return this -> value < argument; }
            friend inline boolean operator <(const boolean argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const boolean argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const boolean argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const boolean argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const char argument) const { return this -> value < argument; }
            friend inline boolean operator <(const char argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const char16_t argument) const { return this -> value < argument; }
            friend inline boolean operator <(const char16_t argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char16_t argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char16_t argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char16_t argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const char32_t argument) const { return this -> value < argument; }
            friend inline boolean operator <(const char32_t argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char32_t argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char32_t argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const char32_t argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const double argument) const { return this -> value < argument; }
            friend inline boolean operator <(const double argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const double argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const double argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const double argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const float argument) const { return this -> value < argument; }
            friend inline boolean operator <(const float argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const float argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const float argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const float argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const int argument) const { return this -> value < argument; }
            friend inline boolean operator <(const int argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const int argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const int argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const int argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const long argument) const { return this -> value < argument; }
            friend inline boolean operator <(const long argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const long double argument) const { return this -> value < argument; }
            friend inline boolean operator <(const long double argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long double argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long double argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long double argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const long long argument) const { return this -> value < argument; }
            friend inline boolean operator <(const long long argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long long argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long long argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const long long argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const short argument) const { return this -> value < argument; }
            friend inline boolean operator <(const short argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const short argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const short argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const short argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const signed char argument) const { return this -> value < argument; }
            friend inline boolean operator <(const signed char argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const signed char argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const signed char argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const signed char argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const unsigned char argument) const { return this -> value < argument; }
            friend inline boolean operator <(const unsigned char argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned char argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned char argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const unsigned int argument) const { return this -> value < argument; }
            friend inline boolean operator <(const unsigned int argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned int argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned int argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const unsigned long argument) const { return this -> value < argument; }
            friend inline boolean operator <(const unsigned long argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned long argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned long argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const unsigned long long argument) const { return this -> value < argument; }
            friend inline boolean operator <(const unsigned long long argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const unsigned short argument) const { return this -> value < argument; }
            friend inline boolean operator <(const unsigned short argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned short argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned short argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const wchar_t argument) const { return this -> value < argument; }
            friend inline boolean operator <(const wchar_t argumentA, char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const wchar_t argumentA, char8_t&& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const wchar_t argumentA, const char8_t& argumentB) { return argumentA < argumentB.value; }
            friend inline boolean operator <(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA < argumentB.value; }

            inline boolean operator <(const char8_t argument) const { return this -> value < argument.value; }

            // [>]
            inline boolean operator >(const boolean argument) const { return this -> value > argument; }
            friend inline boolean operator >(const boolean argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const boolean argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const boolean argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const boolean argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const char argument) const { return this -> value > argument; }
            friend inline boolean operator >(const char argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const char16_t argument) const { return this -> value > argument; }
            friend inline boolean operator >(const char16_t argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char16_t argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char16_t argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char16_t argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const char32_t argument) const { return this -> value > argument; }
            friend inline boolean operator >(const char32_t argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char32_t argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char32_t argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const char32_t argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const double argument) const { return this -> value > argument; }
            friend inline boolean operator >(const double argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const double argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const double argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const double argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const float argument) const { return this -> value > argument; }
            friend inline boolean operator >(const float argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const float argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const float argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const float argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const int argument) const { return this -> value > argument; }
            friend inline boolean operator >(const int argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const int argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const int argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const int argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const long argument) const { return this -> value > argument; }
            friend inline boolean operator >(const long argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const long double argument) const { return this -> value > argument; }
            friend inline boolean operator >(const long double argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long double argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long double argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long double argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const long long argument) const { return this -> value > argument; }
            friend inline boolean operator >(const long long argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long long argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long long argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const long long argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const short argument) const { return this -> value > argument; }
            friend inline boolean operator >(const short argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const short argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const short argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const short argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const signed char argument) const { return this -> value > argument; }
            friend inline boolean operator >(const signed char argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const signed char argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const signed char argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const signed char argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const unsigned char argument) const { return this -> value > argument; }
            friend inline boolean operator >(const unsigned char argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned char argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned char argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const unsigned int argument) const { return this -> value > argument; }
            friend inline boolean operator >(const unsigned int argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned int argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned int argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const unsigned long argument) const { return this -> value > argument; }
            friend inline boolean operator >(const unsigned long argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned long argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned long argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const unsigned long long argument) const { return this -> value > argument; }
            friend inline boolean operator >(const unsigned long long argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const unsigned short argument) const { return this -> value > argument; }
            friend inline boolean operator >(const unsigned short argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned short argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned short argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const wchar_t argument) const { return this -> value > argument; }
            friend inline boolean operator >(const wchar_t argumentA, char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const wchar_t argumentA, char8_t&& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const wchar_t argumentA, const char8_t& argumentB) { return argumentA > argumentB.value; }
            friend inline boolean operator >(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA > argumentB.value; }

            inline boolean operator >(const char8_t argument) const { return this -> value > argument.value; }

            // [+=]
            inline boolean operator +=(const boolean argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(boolean& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(boolean& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(boolean& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(boolean& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline char operator +=(const char argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(char& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(char& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(char& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(char& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline char16_t operator +=(const char16_t argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(char16_t& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(char16_t& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(char16_t& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(char16_t& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline char32_t operator +=(const char32_t argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(char32_t& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(char32_t& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(char32_t& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(char32_t& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline double operator +=(const double argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(double& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(double& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(double& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(double& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline float operator +=(const float argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(float& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(float& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(float& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(float& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline int operator +=(const int argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(int& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(int& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(int& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(int& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline long operator +=(const long argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(long& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(long& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(long& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(long& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline long double operator +=(const long double argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(long double& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(long double& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(long double& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(long double& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline long long operator +=(const long long argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(long long& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(long long& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(long long& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(long long& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline short operator +=(const short argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(short& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(short& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(short& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(short& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline signed char operator +=(const signed char argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(signed char& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(signed char& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(signed char& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(signed char& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline unsigned char operator +=(const unsigned char argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(unsigned char& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(unsigned char& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned char& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline unsigned int operator +=(const unsigned int argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(unsigned int& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(unsigned int& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned int& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline unsigned long operator +=(const unsigned long argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(unsigned long& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(unsigned long& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned long& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline unsigned long long operator +=(const unsigned long long argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(unsigned long long& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline unsigned short operator +=(const unsigned short argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(unsigned short& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(unsigned short& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned short& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline void* operator +=(void* argument) { this -> value += (int) argument; return argument; }
            inline const void* operator +=(const void* argument) { this -> value += (int) argument; return argument; }

            inline wchar_t operator +=(const wchar_t argument) { this -> value += argument; return argument; }
            friend inline char8_t& operator +=(wchar_t& argumentA, char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline char8_t& operator +=(wchar_t& argumentA, char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(wchar_t& argumentA, const char8_t& argumentB) { argumentA += argumentB.value; return argumentB; }
            friend inline const char8_t& operator +=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA += argumentB.value; return argumentB; }

            inline const char8_t operator +=(const char8_t argument) { this -> value += argument.value; return argument; }

            // [-=]
            inline boolean operator -=(const boolean argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(boolean& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(boolean& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(boolean& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(boolean& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline char operator -=(const char argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(char& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(char& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(char& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(char& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline char16_t operator -=(const char16_t argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(char16_t& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(char16_t& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(char16_t& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(char16_t& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline char32_t operator -=(const char32_t argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(char32_t& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(char32_t& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(char32_t& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(char32_t& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline double operator -=(const double argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(double& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(double& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(double& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(double& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline float operator -=(const float argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(float& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(float& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(float& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(float& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline int operator -=(const int argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(int& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(int& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(int& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(int& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline long operator -=(const long argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(long& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(long& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(long& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(long& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline long double operator -=(const long double argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(long double& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(long double& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(long double& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(long double& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline long long operator -=(const long long argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(long long& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(long long& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(long long& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(long long& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline short operator -=(const short argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(short& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(short& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(short& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(short& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline signed char operator -=(const signed char argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(signed char& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(signed char& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(signed char& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(signed char& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline unsigned char operator -=(const unsigned char argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(unsigned char& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(unsigned char& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned char& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline unsigned int operator -=(const unsigned int argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(unsigned int& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(unsigned int& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned int& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline unsigned long operator -=(const unsigned long argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(unsigned long& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(unsigned long& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned long& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline unsigned long long operator -=(const unsigned long long argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(unsigned long long& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline unsigned short operator -=(const unsigned short argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(unsigned short& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(unsigned short& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned short& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline void* operator -=(void* argument) { this -> value -= (int) argument; return argument; }
            inline const void* operator -=(const void* argument) { this -> value -= (int) argument; return argument; }

            inline wchar_t operator -=(const wchar_t argument) { this -> value -= argument; return argument; }
            friend inline char8_t& operator -=(wchar_t& argumentA, char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline char8_t& operator -=(wchar_t& argumentA, char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(wchar_t& argumentA, const char8_t& argumentB) { argumentA -= argumentB.value; return argumentB; }
            friend inline const char8_t& operator -=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA -= argumentB.value; return argumentB; }

            inline const char8_t operator -=(const char8_t argument) { this -> value -= argument.value; return argument; }

            // [*=]
            inline boolean operator *=(const boolean argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(boolean& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(boolean& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(boolean& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(boolean& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline char operator *=(const char argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(char& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(char& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(char& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(char& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline char16_t operator *=(const char16_t argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(char16_t& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(char16_t& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(char16_t& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(char16_t& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline char32_t operator *=(const char32_t argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(char32_t& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(char32_t& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(char32_t& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(char32_t& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline double operator *=(const double argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(double& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(double& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(double& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(double& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline float operator *=(const float argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(float& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(float& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(float& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(float& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline int operator *=(const int argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(int& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(int& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(int& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(int& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline long operator *=(const long argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(long& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(long& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(long& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(long& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline long double operator *=(const long double argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(long double& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(long double& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(long double& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(long double& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline long long operator *=(const long long argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(long long& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(long long& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(long long& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(long long& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline short operator *=(const short argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(short& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(short& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(short& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(short& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline signed char operator *=(const signed char argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(signed char& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(signed char& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(signed char& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(signed char& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline unsigned char operator *=(const unsigned char argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(unsigned char& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(unsigned char& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned char& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline unsigned int operator *=(const unsigned int argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(unsigned int& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(unsigned int& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned int& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline unsigned long operator *=(const unsigned long argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(unsigned long& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(unsigned long& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned long& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline unsigned long long operator *=(const unsigned long long argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(unsigned long long& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline unsigned short operator *=(const unsigned short argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(unsigned short& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(unsigned short& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned short& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline wchar_t operator *=(const wchar_t argument) { this -> value *= argument; return argument; }
            friend inline char8_t& operator *=(wchar_t& argumentA, char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline char8_t& operator *=(wchar_t& argumentA, char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(wchar_t& argumentA, const char8_t& argumentB) { argumentA *= argumentB.value; return argumentB; }
            friend inline const char8_t& operator *=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA *= argumentB.value; return argumentB; }

            inline const char8_t operator *=(const char8_t argument) { this -> value *= argument.value; return argument; }

            // [/=]
            inline boolean operator /=(const boolean argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(boolean& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(boolean& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(boolean& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(boolean& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline char operator /=(const char argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(char& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(char& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(char& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(char& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline char16_t operator /=(const char16_t argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(char16_t& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(char16_t& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(char16_t& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(char16_t& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline char32_t operator /=(const char32_t argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(char32_t& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(char32_t& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(char32_t& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(char32_t& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline double operator /=(const double argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(double& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(double& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(double& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(double& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline float operator /=(const float argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(float& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(float& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(float& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(float& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline int operator /=(const int argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(int& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(int& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(int& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(int& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline long operator /=(const long argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(long& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(long& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(long& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(long& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline long double operator /=(const long double argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(long double& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(long double& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(long double& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(long double& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline long long operator /=(const long long argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(long long& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(long long& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(long long& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(long long& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline short operator /=(const short argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(short& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(short& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(short& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(short& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline signed char operator /=(const signed char argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(signed char& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(signed char& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(signed char& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(signed char& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline unsigned char operator /=(const unsigned char argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(unsigned char& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(unsigned char& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned char& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline unsigned int operator /=(const unsigned int argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(unsigned int& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(unsigned int& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned int& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline unsigned long operator /=(const unsigned long argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(unsigned long& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(unsigned long& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned long& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline unsigned long long operator /=(const unsigned long long argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(unsigned long long& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline unsigned short operator /=(const unsigned short argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(unsigned short& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(unsigned short& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned short& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline wchar_t operator /=(const wchar_t argument) { this -> value /= argument; return argument; }
            friend inline char8_t& operator /=(wchar_t& argumentA, char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline char8_t& operator /=(wchar_t& argumentA, char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(wchar_t& argumentA, const char8_t& argumentB) { argumentA /= argumentB.value; return argumentB; }
            friend inline const char8_t& operator /=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA /= argumentB.value; return argumentB; }

            inline const char8_t operator /=(const char8_t argument) { this -> value /= argument.value; return argument; }

            // [%=]
            inline boolean operator %=(const boolean argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(boolean& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(boolean& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(boolean& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(boolean& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline char operator %=(const char argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(char& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(char& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(char& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(char& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline char16_t operator %=(const char16_t argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(char16_t& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(char16_t& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(char16_t& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(char16_t& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline char32_t operator %=(const char32_t argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(char32_t& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(char32_t& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(char32_t& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(char32_t& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline int operator %=(const int argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(int& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(int& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(int& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(int& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline long operator %=(const long argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(long& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(long& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(long& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(long& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline long long operator %=(const long long argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(long long& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(long long& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(long long& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(long long& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline short operator %=(const short argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(short& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(short& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(short& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(short& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline signed char operator %=(const signed char argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(signed char& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(signed char& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(signed char& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(signed char& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline unsigned char operator %=(const unsigned char argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(unsigned char& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(unsigned char& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned char& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline unsigned int operator %=(const unsigned int argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(unsigned int& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(unsigned int& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned int& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline unsigned long operator %=(const unsigned long argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(unsigned long& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(unsigned long& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned long& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline unsigned long long operator %=(const unsigned long long argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(unsigned long long& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline unsigned short operator %=(const unsigned short argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(unsigned short& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(unsigned short& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned short& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline wchar_t operator %=(const wchar_t argument) { this -> value %= argument; return argument; }
            friend inline char8_t& operator %=(wchar_t& argumentA, char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline char8_t& operator %=(wchar_t& argumentA, char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(wchar_t& argumentA, const char8_t& argumentB) { argumentA %= argumentB.value; return argumentB; }
            friend inline const char8_t& operator %=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA %= argumentB.value; return argumentB; }

            inline const char8_t operator %=(const char8_t argument) { this -> value %= argument.value; return argument; }

            // [^=]
            inline boolean operator ^=(const boolean argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(boolean& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(boolean& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(boolean& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(boolean& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline char operator ^=(const char argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(char& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(char& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(char& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(char& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline char16_t operator ^=(const char16_t argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(char16_t& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(char16_t& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(char16_t& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(char16_t& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline char32_t operator ^=(const char32_t argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(char32_t& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(char32_t& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(char32_t& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(char32_t& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline int operator ^=(const int argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(int& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(int& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(int& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(int& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline long operator ^=(const long argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(long& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(long& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(long& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(long& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline long long operator ^=(const long long argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(long long& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(long long& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(long long& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(long long& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline short operator ^=(const short argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(short& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(short& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(short& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(short& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline signed char operator ^=(const signed char argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(signed char& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(signed char& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(signed char& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(signed char& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline unsigned char operator ^=(const unsigned char argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(unsigned char& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(unsigned char& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned char& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline unsigned int operator ^=(const unsigned int argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(unsigned int& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(unsigned int& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned int& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline unsigned long operator ^=(const unsigned long argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(unsigned long& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(unsigned long& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned long& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline unsigned long long operator ^=(const unsigned long long argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(unsigned long long& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline unsigned short operator ^=(const unsigned short argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(unsigned short& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(unsigned short& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned short& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline wchar_t operator ^=(const wchar_t argument) { this -> value ^= argument; return argument; }
            friend inline char8_t& operator ^=(wchar_t& argumentA, char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline char8_t& operator ^=(wchar_t& argumentA, char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(wchar_t& argumentA, const char8_t& argumentB) { argumentA ^= argumentB.value; return argumentB; }
            friend inline const char8_t& operator ^=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA ^= argumentB.value; return argumentB; }

            inline const char8_t operator ^=(const char8_t argument) { this -> value ^= argument.value; return argument; }

            // [&=]
            inline boolean operator &=(const boolean argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(boolean& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(boolean& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(boolean& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(boolean& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline char operator &=(const char argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(char& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(char& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(char& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(char& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline char16_t operator &=(const char16_t argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(char16_t& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(char16_t& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(char16_t& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(char16_t& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline char32_t operator &=(const char32_t argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(char32_t& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(char32_t& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(char32_t& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(char32_t& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline int operator &=(const int argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(int& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(int& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(int& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(int& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline long operator &=(const long argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(long& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(long& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(long& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(long& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline long long operator &=(const long long argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(long long& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(long long& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(long long& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(long long& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline short operator &=(const short argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(short& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(short& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(short& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(short& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline signed char operator &=(const signed char argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(signed char& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(signed char& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(signed char& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(signed char& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline unsigned char operator &=(const unsigned char argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(unsigned char& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(unsigned char& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned char& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline unsigned int operator &=(const unsigned int argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(unsigned int& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(unsigned int& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned int& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline unsigned long operator &=(const unsigned long argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(unsigned long& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(unsigned long& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned long& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline unsigned long long operator &=(const unsigned long long argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(unsigned long long& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline unsigned short operator &=(const unsigned short argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(unsigned short& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(unsigned short& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned short& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline wchar_t operator &=(const wchar_t argument) { this -> value &= argument; return argument; }
            friend inline char8_t& operator &=(wchar_t& argumentA, char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline char8_t& operator &=(wchar_t& argumentA, char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(wchar_t& argumentA, const char8_t& argumentB) { argumentA &= argumentB.value; return argumentB; }
            friend inline const char8_t& operator &=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA &= argumentB.value; return argumentB; }

            inline const char8_t operator &=(const char8_t argument) { this -> value &= argument.value; return argument; }

            // [|=]
            inline boolean operator |=(const boolean argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(boolean& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(boolean& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(boolean& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(boolean& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline char operator |=(const char argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(char& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(char& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(char& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(char& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline char16_t operator |=(const char16_t argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(char16_t& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(char16_t& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(char16_t& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(char16_t& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline char32_t operator |=(const char32_t argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(char32_t& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(char32_t& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(char32_t& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(char32_t& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline int operator |=(const int argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(int& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(int& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(int& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(int& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline long operator |=(const long argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(long& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(long& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(long& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(long& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline long long operator |=(const long long argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(long long& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(long long& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(long long& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(long long& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline short operator |=(const short argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(short& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(short& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(short& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(short& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline signed char operator |=(const signed char argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(signed char& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(signed char& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(signed char& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(signed char& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline unsigned char operator |=(const unsigned char argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(unsigned char& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(unsigned char& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned char& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline unsigned int operator |=(const unsigned int argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(unsigned int& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(unsigned int& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned int& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline unsigned long operator |=(const unsigned long argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(unsigned long& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(unsigned long& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned long& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline unsigned long long operator |=(const unsigned long long argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(unsigned long long& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline unsigned short operator |=(const unsigned short argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(unsigned short& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(unsigned short& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned short& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline wchar_t operator |=(const wchar_t argument) { this -> value |= argument; return argument; }
            friend inline char8_t& operator |=(wchar_t& argumentA, char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline char8_t& operator |=(wchar_t& argumentA, char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(wchar_t& argumentA, const char8_t& argumentB) { argumentA |= argumentB.value; return argumentB; }
            friend inline const char8_t& operator |=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA |= argumentB.value; return argumentB; }

            inline const char8_t operator |=(const char8_t argument) { this -> value |= argument.value; return argument; }

            // [<<]
            inline boolean operator <<(const boolean argument) const { return this -> value << argument; }
            friend inline boolean operator <<(const boolean argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline boolean operator <<(const boolean argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline boolean operator <<(const boolean argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline boolean operator <<(const boolean argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline char operator <<(const char argument) const { return this -> value << argument; }
            friend inline char operator <<(const char argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline char operator <<(const char argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline char operator <<(const char argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline char operator <<(const char argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline char16_t operator <<(const char16_t argument) const { return this -> value << argument; }
            friend inline char16_t operator <<(const char16_t argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline char16_t operator <<(const char16_t argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline char16_t operator <<(const char16_t argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline char16_t operator <<(const char16_t argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline char32_t operator <<(const char32_t argument) const { return this -> value << argument; }
            friend inline char32_t operator <<(const char32_t argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline char32_t operator <<(const char32_t argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline char32_t operator <<(const char32_t argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline char32_t operator <<(const char32_t argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline int operator <<(const int argument) const { return this -> value << argument; }
            friend inline int operator <<(const int argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline int operator <<(const int argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline int operator <<(const int argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline int operator <<(const int argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline long operator <<(const long argument) const { return this -> value << argument; }
            friend inline long operator <<(const long argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline long operator <<(const long argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline long operator <<(const long argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline long operator <<(const long argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline long long operator <<(const long long argument) const { return this -> value << argument; }
            friend inline long long operator <<(const long long argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline long long operator <<(const long long argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline long long operator <<(const long long argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline long long operator <<(const long long argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline short operator <<(const short argument) const { return this -> value << argument; }
            friend inline short operator <<(const short argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline short operator <<(const short argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline short operator <<(const short argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline short operator <<(const short argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline signed char operator <<(const signed char argument) const { return this -> value << argument; }
            friend inline signed char operator <<(const signed char argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline signed char operator <<(const signed char argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline signed char operator <<(const signed char argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline signed char operator <<(const signed char argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline unsigned char operator <<(const unsigned char argument) const { return this -> value << argument; }
            friend inline unsigned char operator <<(const unsigned char argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned char operator <<(const unsigned char argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned char operator <<(const unsigned char argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned char operator <<(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline unsigned int operator <<(const unsigned int argument) const { return this -> value << argument; }
            friend inline unsigned int operator <<(const unsigned int argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned int operator <<(const unsigned int argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned int operator <<(const unsigned int argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned int operator <<(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline unsigned long operator <<(const unsigned long argument) const { return this -> value << argument; }
            friend inline unsigned long operator <<(const unsigned long argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned long operator <<(const unsigned long argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned long operator <<(const unsigned long argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned long operator <<(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline unsigned long long operator <<(const unsigned long long argument) const { return this -> value << argument; }
            friend inline unsigned long long operator <<(const unsigned long long argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned long long operator <<(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned long long operator <<(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned long long operator <<(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline unsigned short operator <<(const unsigned short argument) const { return this -> value << argument; }
            friend inline unsigned short operator <<(const unsigned short argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned short operator <<(const unsigned short argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned short operator <<(const unsigned short argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline unsigned short operator <<(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline wchar_t operator <<(const wchar_t argument) const { return this -> value << argument; }
            friend inline wchar_t operator <<(const wchar_t argumentA, char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline wchar_t operator <<(const wchar_t argumentA, char8_t&& argumentB) { return argumentA << argumentB.value; }
            friend inline wchar_t operator <<(const wchar_t argumentA, const char8_t& argumentB) { return argumentA << argumentB.value; }
            friend inline wchar_t operator <<(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA << argumentB.value; }

            inline char8_t operator <<(const char8_t argument) const { return this -> value << argument.value; }

            // [>>]
            inline boolean operator >>(const boolean argument) const { return this -> value >> argument; }
            friend inline boolean operator >>(const boolean argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline boolean operator >>(const boolean argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline boolean operator >>(const boolean argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline boolean operator >>(const boolean argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline char operator >>(const char argument) const { return this -> value >> argument; }
            friend inline char operator >>(const char argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline char operator >>(const char argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline char operator >>(const char argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline char operator >>(const char argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline char16_t operator >>(const char16_t argument) const { return this -> value >> argument; }
            friend inline char16_t operator >>(const char16_t argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline char16_t operator >>(const char16_t argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline char16_t operator >>(const char16_t argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline char16_t operator >>(const char16_t argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline char32_t operator >>(const char32_t argument) const { return this -> value >> argument; }
            friend inline char32_t operator >>(const char32_t argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline char32_t operator >>(const char32_t argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline char32_t operator >>(const char32_t argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline char32_t operator >>(const char32_t argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline int operator >>(const int argument) const { return this -> value >> argument; }
            friend inline int operator >>(const int argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline int operator >>(const int argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline int operator >>(const int argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline int operator >>(const int argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline long operator >>(const long argument) const { return this -> value >> argument; }
            friend inline long operator >>(const long argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline long operator >>(const long argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline long operator >>(const long argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline long operator >>(const long argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline long long operator >>(const long long argument) const { return this -> value >> argument; }
            friend inline long long operator >>(const long long argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline long long operator >>(const long long argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline long long operator >>(const long long argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline long long operator >>(const long long argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline short operator >>(const short argument) const { return this -> value >> argument; }
            friend inline short operator >>(const short argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline short operator >>(const short argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline short operator >>(const short argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline short operator >>(const short argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline signed char operator >>(const signed char argument) const { return this -> value >> argument; }
            friend inline signed char operator >>(const signed char argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline signed char operator >>(const signed char argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline signed char operator >>(const signed char argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline signed char operator >>(const signed char argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline unsigned char operator >>(const unsigned char argument) const { return this -> value >> argument; }
            friend inline unsigned char operator >>(const unsigned char argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned char operator >>(const unsigned char argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned char operator >>(const unsigned char argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned char operator >>(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline unsigned int operator >>(const unsigned int argument) const { return this -> value >> argument; }
            friend inline unsigned int operator >>(const unsigned int argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned int operator >>(const unsigned int argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned int operator >>(const unsigned int argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned int operator >>(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline unsigned long operator >>(const unsigned long argument) const { return this -> value >> argument; }
            friend inline unsigned long operator >>(const unsigned long argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned long operator >>(const unsigned long argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned long operator >>(const unsigned long argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned long operator >>(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline unsigned long long operator >>(const unsigned long long argument) const { return this -> value >> argument; }
            friend inline unsigned long long operator >>(const unsigned long long argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned long long operator >>(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned long long operator >>(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned long long operator >>(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline unsigned short operator >>(const unsigned short argument) const { return this -> value >> argument; }
            friend inline unsigned short operator >>(const unsigned short argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned short operator >>(const unsigned short argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned short operator >>(const unsigned short argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline unsigned short operator >>(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline wchar_t operator >>(const wchar_t argument) const { return this -> value >> argument; }
            friend inline wchar_t operator >>(const wchar_t argumentA, char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline wchar_t operator >>(const wchar_t argumentA, char8_t&& argumentB) { return argumentA >> argumentB.value; }
            friend inline wchar_t operator >>(const wchar_t argumentA, const char8_t& argumentB) { return argumentA >> argumentB.value; }
            friend inline wchar_t operator >>(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA >> argumentB.value; }

            inline char8_t operator >>(const char8_t argument) const { return this -> value >> argument.value; }

            // [>>=]
            inline boolean operator >>=(const boolean argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(boolean& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(boolean& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(boolean& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(boolean& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline char operator >>=(const char argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(char& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(char& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(char& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(char& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline char16_t operator >>=(const char16_t argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(char16_t& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(char16_t& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(char16_t& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(char16_t& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline char32_t operator >>=(const char32_t argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(char32_t& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(char32_t& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(char32_t& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(char32_t& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline int operator >>=(const int argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(int& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(int& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(int& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(int& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline long operator >>=(const long argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(long& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(long& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(long& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(long& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline long long operator >>=(const long long argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(long long& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(long long& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(long long& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(long long& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline short operator >>=(const short argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(short& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(short& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(short& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(short& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline signed char operator >>=(const signed char argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(signed char& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(signed char& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(signed char& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(signed char& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline unsigned char operator >>=(const unsigned char argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(unsigned char& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(unsigned char& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned char& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline unsigned int operator >>=(const unsigned int argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(unsigned int& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(unsigned int& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned int& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline unsigned long operator >>=(const unsigned long argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(unsigned long& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(unsigned long& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned long& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline unsigned long long operator >>=(const unsigned long long argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(unsigned long long& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline unsigned short operator >>=(const unsigned short argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(unsigned short& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(unsigned short& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned short& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline wchar_t operator >>=(const wchar_t argument) { this -> value >>= argument; return argument; }
            friend inline char8_t& operator >>=(wchar_t& argumentA, char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline char8_t& operator >>=(wchar_t& argumentA, char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(wchar_t& argumentA, const char8_t& argumentB) { argumentA >>= argumentB.value; return argumentB; }
            friend inline const char8_t& operator >>=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA >>= argumentB.value; return argumentB; }

            inline const char8_t operator >>=(const char8_t argument) { this -> value >>= argument.value; return argument; }

            // [<<=]
            inline boolean operator <<=(const boolean argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(boolean& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(boolean& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(boolean& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(boolean& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline char operator <<=(const char argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(char& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(char& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(char& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(char& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline char16_t operator <<=(const char16_t argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(char16_t& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(char16_t& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(char16_t& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(char16_t& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline char32_t operator <<=(const char32_t argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(char32_t& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(char32_t& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(char32_t& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(char32_t& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline int operator <<=(const int argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(int& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(int& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(int& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(int& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline long operator <<=(const long argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(long& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(long& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(long& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(long& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline long long operator <<=(const long long argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(long long& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(long long& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(long long& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(long long& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline short operator <<=(const short argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(short& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(short& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(short& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(short& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline signed char operator <<=(const signed char argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(signed char& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(signed char& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(signed char& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(signed char& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline unsigned char operator <<=(const unsigned char argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(unsigned char& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(unsigned char& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned char& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned char& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline unsigned int operator <<=(const unsigned int argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(unsigned int& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(unsigned int& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned int& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned int& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline unsigned long operator <<=(const unsigned long argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(unsigned long& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(unsigned long& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned long& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned long& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline unsigned long long operator <<=(const unsigned long long argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(unsigned long long& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(unsigned long long& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned long long& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned long long& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline unsigned short operator <<=(const unsigned short argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(unsigned short& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(unsigned short& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned short& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(unsigned short& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline wchar_t operator <<=(const wchar_t argument) { this -> value <<= argument; return argument; }
            friend inline char8_t& operator <<=(wchar_t& argumentA, char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline char8_t& operator <<=(wchar_t& argumentA, char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(wchar_t& argumentA, const char8_t& argumentB) { argumentA <<= argumentB.value; return argumentB; }
            friend inline const char8_t& operator <<=(wchar_t& argumentA, const char8_t&& argumentB) { argumentA <<= argumentB.value; return argumentB; }

            inline const char8_t operator <<=(const char8_t argument) { this -> value <<= argument.value; return argument; }

            // [==]
            inline boolean operator ==(const boolean argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const boolean argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const boolean argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const boolean argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const boolean argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const char argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const char argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const char16_t argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const char16_t argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char16_t argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char16_t argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char16_t argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const char32_t argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const char32_t argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char32_t argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char32_t argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const char32_t argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const double argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const double argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const double argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const double argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const double argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const float argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const float argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const float argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const float argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const float argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const int argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const int argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const int argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const int argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const int argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const long argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const long argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const long double argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const long double argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long double argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long double argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long double argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const long long argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const long long argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long long argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long long argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const long long argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const short argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const short argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const short argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const short argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const short argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const signed char argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const signed char argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const signed char argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const signed char argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const signed char argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const unsigned char argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const unsigned char argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned char argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned char argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const unsigned int argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const unsigned int argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned int argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned int argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const unsigned long argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const unsigned long argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned long argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned long argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const unsigned long long argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const unsigned long long argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const unsigned short argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const unsigned short argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned short argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned short argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const wchar_t argument) const { return this -> value == argument; }
            friend inline boolean operator ==(const wchar_t argumentA, char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const wchar_t argumentA, char8_t&& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const wchar_t argumentA, const char8_t& argumentB) { return argumentA == argumentB.value; }
            friend inline boolean operator ==(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA == argumentB.value; }

            inline boolean operator ==(const char8_t argument) const { return this -> value == argument.value; }

            // [!=]
            inline boolean operator !=(const boolean argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const boolean argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const boolean argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const boolean argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const boolean argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const char argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const char argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const char16_t argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const char16_t argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char16_t argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char16_t argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char16_t argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const char32_t argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const char32_t argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char32_t argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char32_t argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const char32_t argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const double argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const double argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const double argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const double argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const double argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const float argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const float argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const float argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const float argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const float argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const int argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const int argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const int argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const int argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const int argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const long argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const long argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const long double argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const long double argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long double argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long double argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long double argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const long long argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const long long argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long long argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long long argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const long long argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const short argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const short argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const short argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const short argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const short argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const signed char argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const signed char argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const signed char argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const signed char argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const signed char argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const unsigned char argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const unsigned char argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned char argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned char argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const unsigned int argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const unsigned int argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned int argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned int argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const unsigned long argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const unsigned long argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned long argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned long argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const unsigned long long argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const unsigned long long argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const unsigned short argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const unsigned short argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned short argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned short argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const wchar_t argument) const { return this -> value != argument; }
            friend inline boolean operator !=(const wchar_t argumentA, char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const wchar_t argumentA, char8_t&& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const wchar_t argumentA, const char8_t& argumentB) { return argumentA != argumentB.value; }
            friend inline boolean operator !=(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA != argumentB.value; }

            inline boolean operator !=(const char8_t argument) const { return this -> value != argument.value; }

            // [<=]
            inline boolean operator <=(const boolean argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const boolean argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const boolean argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const boolean argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const boolean argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const char argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const char argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const char16_t argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const char16_t argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char16_t argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char16_t argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char16_t argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const char32_t argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const char32_t argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char32_t argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char32_t argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const char32_t argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const double argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const double argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const double argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const double argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const double argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const float argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const float argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const float argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const float argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const float argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const int argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const int argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const int argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const int argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const int argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const long argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const long argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const long double argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const long double argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long double argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long double argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long double argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const long long argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const long long argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long long argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long long argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const long long argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const short argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const short argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const short argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const short argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const short argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const signed char argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const signed char argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const signed char argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const signed char argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const signed char argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const unsigned char argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const unsigned char argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned char argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned char argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const unsigned int argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const unsigned int argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned int argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned int argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const unsigned long argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const unsigned long argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned long argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned long argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const unsigned long long argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const unsigned long long argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const unsigned short argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const unsigned short argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned short argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned short argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const wchar_t argument) const { return this -> value <= argument; }
            friend inline boolean operator <=(const wchar_t argumentA, char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const wchar_t argumentA, char8_t&& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const wchar_t argumentA, const char8_t& argumentB) { return argumentA <= argumentB.value; }
            friend inline boolean operator <=(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA <= argumentB.value; }

            inline boolean operator <=(const char8_t argument) const { return this -> value <= argument.value; }

            // [>=]
            inline boolean operator >=(const boolean argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const boolean argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const boolean argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const boolean argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const boolean argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const char argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const char argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const char16_t argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const char16_t argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char16_t argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char16_t argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char16_t argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const char32_t argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const char32_t argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char32_t argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char32_t argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const char32_t argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const double argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const double argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const double argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const double argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const double argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const float argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const float argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const float argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const float argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const float argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const int argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const int argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const int argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const int argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const int argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const long argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const long argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const long double argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const long double argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long double argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long double argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long double argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const long long argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const long long argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long long argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long long argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const long long argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const short argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const short argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const short argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const short argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const short argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const signed char argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const signed char argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const signed char argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const signed char argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const signed char argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const unsigned char argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const unsigned char argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned char argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned char argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const unsigned int argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const unsigned int argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned int argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned int argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const unsigned long argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const unsigned long argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned long argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned long argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const unsigned long long argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const unsigned long long argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const unsigned short argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const unsigned short argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned short argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned short argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const wchar_t argument) const { return this -> value >= argument; }
            friend inline boolean operator >=(const wchar_t argumentA, char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const wchar_t argumentA, char8_t&& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const wchar_t argumentA, const char8_t& argumentB) { return argumentA >= argumentB.value; }
            friend inline boolean operator >=(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA >= argumentB.value; }

            inline boolean operator >=(const char8_t argument) const { return this -> value >= argument.value; }

            // [&&]
            inline boolean operator &&(const boolean argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const boolean argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const boolean argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const boolean argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const boolean argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const char argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const char argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const char16_t argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const char16_t argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char16_t argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char16_t argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char16_t argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const char32_t argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const char32_t argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char32_t argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char32_t argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const char32_t argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const double argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const double argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const double argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const double argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const double argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const float argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const float argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const float argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const float argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const float argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const int argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const int argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const int argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const int argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const int argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const long argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const long argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const long double argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const long double argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long double argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long double argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long double argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const long long argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const long long argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long long argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long long argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const long long argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const short argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const short argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const short argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const short argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const short argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const signed char argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const signed char argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const signed char argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const signed char argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const signed char argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const unsigned char argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const unsigned char argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned char argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned char argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const unsigned int argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const unsigned int argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned int argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned int argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const unsigned long argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const unsigned long argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned long argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned long argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const unsigned long long argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const unsigned long long argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const unsigned short argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const unsigned short argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned short argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned short argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(void* argument) const { return this -> value && argument; }
            friend inline boolean operator &&(void* argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(void* argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(void* argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(void* argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const void* argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const void* argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const void* argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const void* argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const void* argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const wchar_t argument) const { return this -> value && argument; }
            friend inline boolean operator &&(const wchar_t argumentA, char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const wchar_t argumentA, char8_t&& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const wchar_t argumentA, const char8_t& argumentB) { return argumentA && argumentB.value; }
            friend inline boolean operator &&(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA && argumentB.value; }

            inline boolean operator &&(const char8_t argument) const { return this -> value && argument.value; }

            // [||]
            inline boolean operator ||(const boolean argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const boolean argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const boolean argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const boolean argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const boolean argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const char argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const char argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const char16_t argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const char16_t argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char16_t argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char16_t argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char16_t argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const char32_t argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const char32_t argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char32_t argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char32_t argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const char32_t argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const double argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const double argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const double argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const double argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const double argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const float argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const float argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const float argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const float argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const float argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const int argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const int argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const int argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const int argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const int argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const long argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const long argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const long double argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const long double argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long double argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long double argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long double argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const long long argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const long long argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long long argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long long argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const long long argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const short argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const short argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const short argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const short argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const short argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const signed char argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const signed char argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const signed char argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const signed char argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const signed char argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const unsigned char argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const unsigned char argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned char argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned char argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned char argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const unsigned int argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const unsigned int argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned int argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned int argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned int argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const unsigned long argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const unsigned long argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned long argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned long argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned long argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const unsigned long long argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const unsigned long long argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned long long argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned long long argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned long long argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const unsigned short argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const unsigned short argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned short argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned short argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const unsigned short argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(void* argument) const { return this -> value || argument; }
            friend inline boolean operator ||(void* argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(void* argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(void* argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(void* argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const void* argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const void* argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const void* argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const void* argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const void* argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const wchar_t argument) const { return this -> value || argument; }
            friend inline boolean operator ||(const wchar_t argumentA, char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const wchar_t argumentA, char8_t&& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const wchar_t argumentA, const char8_t& argumentB) { return argumentA || argumentB.value; }
            friend inline boolean operator ||(const wchar_t argumentA, const char8_t&& argumentB) { return argumentA || argumentB.value; }

            inline boolean operator ||(const char8_t argument) const { return this -> value || argument.value; }

            // [++]
            inline char8_t& operator ++(int) { ++(this -> value); return *this; }
            inline char8_t& operator ++(void) { (this -> value)++; return *this; }

            // [--]
            inline char8_t& operator --(int) { --(this -> value); return *this; }
            inline char8_t& operator --(void) { (this -> value)--; return *this; }

            // [...]
            inline operator boolean() const { return this -> value; }
            inline operator unsigned char() const { return this -> value; }
} char8_t;
#endif

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC CLK_TCK
#endif

#ifndef INFINITY
#define INFINITY HUGE_VAL
#endif

#if __STDC_VERSION__ < 199901L
#define inline
#endif

#ifndef VK_HANGUL
#define VK_HANGUL VK_HANGUEL
#endif
