/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Definition > Boolean --- NOTE (Lapys) -> Uses `unsigned char` as an intermediary base. */
    typedef struct boolean {
        // ...
        friend LapysDevelopmentKit::Types::object;
        friend LapysDevelopmentKit::Types::primitive;
        friend LapysDevelopmentKit::Types::size;

        // [...]
        private:
            /* Initialization > Value */
            enum boolean_value : unsigned char {boolean_false = (false == true), boolean_true = !boolean_false} value : 8u;

        // [...]
        public:
            // [Constructor]
            inline boolean() : value{this -> boolean_false} {}
            inline boolean(const unsigned char argument) : value{argument ? this -> boolean_true : this -> boolean_false} {}

            inline boolean(boolean& argument) : value{argument.value} {}
            inline boolean(boolean&& argument) : value{argument.value} {}
            inline boolean(const boolean& argument) : value{argument.value} {}
            inline boolean(const boolean&& argument) : value{argument.value} {}

            boolean(object&); boolean(object&&); boolean(const object&); boolean(const object&&);
            boolean(primitive&); boolean(primitive&&); boolean(const primitive&); boolean(const primitive&&);
            boolean(size&); boolean(size&&); boolean(const size&); boolean(const size&&);

            // [Operator]
                // [=]
                inline boolean& operator =(const unsigned char argument) { this -> value = argument ? this -> boolean_true : this -> boolean_false; return *this; }
                inline boolean& operator =(const boolean argument) { this -> value = argument.value; return *this; }

                boolean& operator =(object&); boolean& operator =(object&&);
                boolean& operator =(const object&); boolean& operator =(const object&&);
                boolean& operator =(primitive&); boolean& operator =(primitive&&);
                boolean& operator =(const primitive&); boolean& operator =(const primitive&&);
                boolean& operator =(size&); boolean& operator =(size&&);
                boolean& operator =(const size&); boolean& operator =(const size&&);

                // [+=]
                inline boolean& operator +=(const unsigned char argument) { if (argument) this -> value = this -> boolean_false == this -> value ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator +=(const boolean argument) { if (argument.boolean_true == argument.value) this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }

                // [-=]
                inline boolean& operator -=(const unsigned char argument) { if (argument) this -> value = this -> boolean_false == this -> value ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator -=(const boolean argument) { if (argument.boolean_true == argument.value) this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }

                // [*=]
                inline boolean& operator *=(const unsigned char argument) { if (!argument) this -> value = this -> boolean_false; return *this; }
                inline const boolean& operator *=(const boolean argument) { if (!argument) this -> value = this -> boolean_false; return *this; }

                // [/=]
                inline boolean& operator /=(const unsigned char argument) { this -> value = (argument ? (this -> boolean_true == this -> value) / argument : argument / argument) ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator /=(const boolean argument) { this -> value = (argument ? (this -> boolean_true == this -> value) / (argument.boolean_true == argument.value) : (argument.boolean_true == argument.value) / (argument.boolean_true == argument.value)) ? this -> boolean_true : this -> boolean_false; return *this; }

                // [%=]
                inline boolean& operator %=(const unsigned char argument) { if (!argument) this -> value = argument % argument ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator %=(const boolean argument) { if (argument.boolean_false == argument.value) this -> value = argument.boolean_false % (unsigned char) argument ? this -> boolean_true : this -> boolean_false; return *this; }

                // [^=]
                inline boolean& operator ^=(const unsigned char argument) { this -> value = (this -> boolean_true == this -> value) ^ argument ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator ^=(const boolean argument) { this -> value = (this -> boolean_true == this -> value) ^ (argument.boolean_true == argument.value) ? this -> boolean_true : this -> boolean_false; return *this; }

                // [&=]
                inline boolean& operator &=(const unsigned char argument) { this -> value = (this -> boolean_true == this -> value) & argument ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator &=(const boolean argument) { this -> value = (this -> boolean_true == this -> value) & (argument.boolean_true == argument.value) ? this -> boolean_true : this -> boolean_false; return *this; }

                // [|=]
                inline boolean& operator |=(const unsigned char argument) { this -> value = (this -> boolean_true == this -> value) | argument ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator |=(const boolean argument) { this -> value = (this -> boolean_true == this -> value) | (argument.boolean_true == argument.value) ? this -> boolean_true : this -> boolean_false; return *this; }

                // [>>=]
                inline boolean& operator >>=(const unsigned char argument) { this -> value = (this -> boolean_true == this -> value) >> argument ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator >>=(const boolean argument) { this -> value = (this -> boolean_true == this -> value) >> (argument.boolean_true == argument.value) ? this -> boolean_true : this -> boolean_false; return *this; }

                // [<<=]
                inline boolean& operator <<=(const unsigned char argument) { this -> value = (this -> boolean_true == this -> value) << argument ? this -> boolean_true : this -> boolean_false; return *this; }
                inline const boolean& operator <<=(const boolean argument) { this -> value = (this -> boolean_true == this -> value) << (argument.boolean_true == argument.value) ? this -> boolean_true : this -> boolean_false; return *this; }

                // [++]
                inline boolean& operator ++() { this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }
                inline boolean& operator ++(int) { this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }

                // [--]
                inline boolean& operator --() { this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }
                inline boolean& operator --(int) { this -> value = this -> value == this -> boolean_false ? this -> boolean_true : this -> boolean_false; return *this; }

                // [...]
                inline operator unsigned char() const { return this -> boolean_true == this -> value; }
    } boolean;
#endif
