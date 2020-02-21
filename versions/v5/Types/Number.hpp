/* Class > ... Number --- NOTE (Lapys) -> Base: `long double`. */
class Number {
    // ...
    private:
        // Initialization > (Overflown, Value)
        Boolean overflown;
        void *value; // NOTE (Lapys) -> Base: `long double` then `BigNumber`.

    // ...
    public:
        // [Constructor]
        inline Number() : overflown(false), value(NULL) {}
        Number(const long double argument) : overflown(false) { this -> value = std::malloc(sizeof(argument)); *((long double*) (this -> value)) = argument; }
        Number(BigNumber& argument) : overflown(true) { this -> value = std::malloc(sizeof(argument)); *((BigNumber*) (this -> value)) = argument; }
        Number(const BigNumber& argument) : overflown(true) { this -> value = std::malloc(sizeof(argument)); *((BigNumber*) (this -> value)) = argument; }

        Number(Number& argument) { std::free(this -> value); if (this -> overflown = argument.overflown) { BigNumber& value = *((BigNumber*) (argument.value)); this -> value = std::malloc(sizeof(value)); *((BigNumber*) (this -> value)) = value; } else { this -> value = std::malloc(sizeof(long double)); *((long double*) (this -> value)) = *((long double*) (argument.value)); } }
        Number(const Number& argument) { std::free(this -> value); if (this -> overflown = argument.overflown) { BigNumber& value = *((BigNumber*) (argument.value)); this -> value = std::malloc(sizeof(value)); *((BigNumber*) (this -> value)) = value; } else { this -> value = std::malloc(sizeof(long double)); *((long double*) (this -> value)) = *((long double*) (argument.value)); } }

        // [Destructor]
        ~Number() { this -> overflown = false; std::free(this -> value); }

        // [Operator]
            // [+]
            // [-]
            // [*]
            // [/]
            // [%]
            // [^]
            // [&]
            // [|]
            // [~]
            // [!]
            // [=]
            const Number& operator =(Number& argument) { std::free(this -> value); if (this -> overflown = argument.overflown) { BigNumber& value = *((BigNumber*) (argument.value)); this -> value = std::malloc(sizeof(value)); *((BigNumber*) (this -> value)) = value; } else { this -> value = std::malloc(sizeof(long double)); *((long double*) (this -> value)) = *((long double*) (argument.value)); } return *this; }
            const Number& operator =(const Number& argument) { std::free(this -> value); if (this -> overflown = argument.overflown) { BigNumber& value = *((BigNumber*) (argument.value)); this -> value = std::malloc(sizeof(value)); *((BigNumber*) (this -> value)) = value; } else { this -> value = std::malloc(sizeof(long double)); *((long double*) (this -> value)) = *((long double*) (argument.value)); } return *this; }

            // [<]
            // [>]
            // [<=]
            // [>=]
            // [++]
            // [--]
            // [==]
            // [!=]
            // [+=]
            // [-=]
            // [/=]
            // [%=]
            // [^=]
            // [&=]
            // [|=]
            // [*=]

            // ...
            operator long double() const { return this -> valueOf(); }

            operator Boolean() const;
            inline operator Number() const { return *this; }
            operator String() const;

        // Method > ...
        const Number toInteger() const { if (this -> overflown) {} else { long double& value = *((long double*) (this -> value)); return value - LDKM::mod(value, 1.00); } }
        const String toString() const;

        const long double valueOf() const { return this -> overflown ? std::nanl("") : *((long double*) (this -> value)); }
};
