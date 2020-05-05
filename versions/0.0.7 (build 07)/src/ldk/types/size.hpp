/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Definition > Size
        --- NOTE ---
            #Lapys:
                - Explicitly meant for progressively arithmetic counting only.
                - Records positive overflows as part of its intrinsic value.

        --- WARN ---
            #Lapys:
                - Division is integer-based and iterative.
                - Multiplication is iterative addition.
                - Only addition and subtraction operations are optimized.
                - Works only as a bounded unsigned integer.
                - Works only with native unsigned integral types.
    */
    typedef struct size {
        // ...
        friend LapysDevelopmentKit::Types::boolean;
        friend LapysDevelopmentKit::Types::object;
        friend LapysDevelopmentKit::Types::primitive;

        // [...]
        private:
            // Initialization > (Current, First) --- REDACT (Lapys)
            struct exponent { public:
                exponent *next; std::size_t value;
                inline operator std::size_t() const { return this -> value; }
            } *current, *first;

            /* Function */
                // Add
                void add(const std::size_t value) {
                    // Logic
                    if (value) {
                        // Constant > Evaluation
                        const std::size_t evaluation = this -> current -> value + value;

                        // Logic
                        if (evaluation < value || evaluation < this -> current -> value) {
                            // Modification > (Target > Current) > Value
                            this -> current -> value = std::size_t(-1);

                            // : Update > (Target > Current)
                            // : Modification > (Target > Current) > (Next, Value)
                            this -> current = pointer__allocate_memory(this -> current -> next, sizeof(exponent));
                            this -> current -> next = NULL;
                            this -> current -> value = evaluation ? evaluation : 1u;
                        }

                        else
                            // Modification > (Target > Current) > Value
                            this -> current -> value = evaluation;
                    }
                }
                void add(const size& size) {
                    // Update > Target
                    for (exponent *current = size.first; current; current = current -> next)
                    this -> add(current -> value);
                }

                // Copy
                void copy(const size& size) {
                    // (Loop > )Update > Target
                    this -> reset(0u);
                    for (exponent *current = size.first; NULL != current; current = current -> next) this -> add(current -> value);
                }

                // Decrement
                void decrement() {
                    // Logic
                    if (this -> current -> value)
                        // Modification > (Target > Current) > Value
                        (this -> current -> value)--;

                    else if (NULL == this -> first -> next)
                        // Modification > (Target > Current) > Value
                        this -> current -> value = 0u;

                    else {
                        // Initialization > (Current, Recent)
                        exponent *current = this -> first, *recent;

                        // (Loop > )Update > ...
                        for (; current != this -> current; current = current -> next) recent = current;
                        this -> current = recent;

                        // Modification > (Target > Current) > (Next, Value)
                        this -> current -> next = NULL;
                        this -> current -> value = std::size_t(-1);

                        // Deletion
                        pointer__free_memory(current);
                    }
                }

                // Divide
                void divide(const std::size_t value) {
                    // Logic
                    if (value)
                        // Logic
                        if (this -> lesserThan(value))
                            // Update > Target
                            this -> reset(0u);

                        else if (this -> equals(value))
                            // Update > Target
                            this -> reset(1u);

                        else {
                            // Initialization > (Carry, Evaluation)
                            size carry = 0u, evaluation = 0u;

                            // Loop
                            for (exponent *current = this -> first; NULL != current; current = current -> next) {
                                // : Loop > (Modification > Current > Value, Update > Evaluation)
                                // : Logic > Update > Carry
                                while (current -> value >= value) { current -> value -= value; evaluation++; }
                                if (current -> value) carry += current -> value;
                            }

                            while (carry >= value) {
                                // Update > (Carry, Evaluation)
                                carry -= value;
                                evaluation++;
                            }

                            // Update > Target
                            this -> copy(evaluation);
                        }

                    else if (value ^ 1u)
                        // Modification > (Target > Current) > Value
                        this -> current -> value /= value;
                }

                // Equals
                inline boolean equals(const size& size) const {
                    // Initialization > Size (Current)
                    exponent *current = this -> first, *sizeCurrent = size.first;

                    // Loop > Update > Size (Current)
                    while (NULL != current && NULL != sizeCurrent) { current = current -> next; sizeCurrent = sizeCurrent -> next; }

                    // Return
                    return (NULL == current && NULL == sizeCurrent) && (this -> current -> value == size.current -> value);
                }

                // Greater Than
                inline boolean greaterThan(const size& size) const {
                    // Initialization > Size (Current)
                    exponent *current = this -> first, *sizeCurrent = size.first;

                    // Loop > Update > Size (Current)
                    while (NULL != current && NULL != sizeCurrent) { current = current -> next; sizeCurrent = sizeCurrent -> next; }

                    // Return
                    return (NULL != current && NULL == sizeCurrent) || ((NULL == current && NULL == sizeCurrent) && (this -> current -> value > size.current -> value));
                }

                // Increment
                void increment() {
                    // Logic
                    if (this -> current -> value + 1u)
                        // Modification > (Target > Current) > Value
                        (this -> current -> value)++;

                    else {
                        // Modification > (Target > Current) > Value
                        this -> current -> value = std::size_t(-1);

                        // : Update > (Target > Current)
                        // : Modification > (Target > Current) > (Next, Value)
                        this -> current = pointer__allocate_memory(this -> current -> next, sizeof(exponent));
                        this -> current -> next = NULL;
                        this -> current -> value = 1u;
                    }
                }

                // Lesser Than
                inline boolean lesserThan(const size& size) const {
                    // Initialization > Size (Current)
                    exponent *current = this -> first, *sizeCurrent = size.first;

                    // Loop > Update > Size (Current)
                    while (NULL != current && NULL != sizeCurrent) { current = current -> next; sizeCurrent = sizeCurrent -> next; }

                    // Return
                    return (NULL == current && NULL != sizeCurrent) || ((NULL == current && NULL == sizeCurrent) && (this -> current -> value < size.current -> value));
                }

                // Modulo
                void modulo(const std::size_t value) {
                    // Logic
                    if (value)
                        // Logic
                        if (this -> equals(value))
                            // Update > Target
                            this -> reset(0u);

                        else {
                            // Initialization > Evaluation
                            size evaluation = 0u;

                            // Loop
                            for (exponent *current = this -> first; NULL != current; current = current -> next) {
                                // : Loop > Modification > Current > Value
                                // : Logic > Update > Evaluation
                                while (current -> value >= value) current -> value -= value;
                                if (current -> value) evaluation += current -> value;
                            }

                            // Loop > Update > Evaluation
                            while (evaluation >= value)  evaluation -= value;

                            // Update > Target
                            this -> copy(evaluation);
                        }

                    else if (value == 1u)
                        // Update > Target
                        this -> reset(0u);

                    else
                        // Modification > (Target > Current) > Value
                        this -> current -> value %= value;
                }

                // Multiply
                void multiply(std::size_t value) {
                    // Logic
                    if (NULL != this -> first -> next && this -> current -> value) {
                        // Logic
                        if (value) {
                            // Logic > Loop > Update > Target
                            if (value -= 1u)
                            for (const size currentValue = *this; value; value -= 1u) this -> add(currentValue);
                        }

                        else
                            // Reset
                            this -> reset(0u);
                    }
                }

                // Subtract
                void subtract(const std::size_t value) {
                    // Logic
                    if (value) {
                        // Logic
                        if (value > this -> current -> value)
                            // Logic
                            if (NULL == this -> first -> next)
                                // Modification > (Target > Current) > Value
                                this -> current -> value = 0u;

                            else {
                                // Initialization > (Current, Recent)
                                exponent *current = this -> first, *recent;

                                // (Loop > )Update > ...
                                for (; current != this -> current; current = current -> next) recent = current;
                                this -> current = recent;

                                // Modification > (Target > Current) > (Next, Value)
                                this -> current -> next = NULL;
                                this -> current -> value = std::size_t(-1) - (value - this -> current -> value);

                                // Deletion
                                pointer__free_memory(current);
                            }

                        else
                            // Modification > (Target > Current) > Value
                            this -> current -> value -= value;
                    }
                }
                void subtract(const size& size) {
                    // Update > Target
                    for (exponent *current = size.first; current; current = current -> next)
                    this -> subtract(current -> value);
                }

        // [...]
        protected:
            /* Phase > ... */
            void initiate(const std::size_t argument) { this -> first = pointer__allocate_memory(this -> current, sizeof(exponent)); this -> current -> next = NULL; this -> current -> value = argument; }
            void reset(const std::size_t argument) { this -> terminate(); this -> initiate(argument); }
            void terminate() { while (NULL != this -> first) { exponent *next = this -> first -> next; pointer__free_memory(this -> first); this -> first = next; } }

        // [...]
        public:
            // [Constructor]
            size(const std::size_t argument = 0u) { this -> initiate(argument); }

            size(size& argument) { this -> initiate(0u); this -> copy((const size&) argument); }
            size(size&& argument) { this -> initiate(0u); this -> copy((const size&) argument); }
            size(const size& argument) { this -> initiate(0u); this -> copy(argument); }
            size(const size&& argument) { this -> initiate(0u); this -> copy((const size&) argument); }

            size(boolean&); size(boolean&&); size(const boolean&); size(const boolean&&);
            size(primitive&); size(primitive&&); size(const primitive&); size(const primitive&&);

            // [Destructor]
            ~size() { this -> terminate(); }

            // [Operator]
                // [+]
                inline size operator +(const std::size_t argument) const { size evaluation = *this; evaluation += argument; return evaluation; }
                friend inline size operator +(const std::size_t argumentA, size& argumentB) { size evaluation = argumentA; evaluation += argumentB; return evaluation; }
                friend inline size operator +(const std::size_t argumentA, size&& argumentB) { size evaluation = argumentA; evaluation += argumentB; return evaluation; }
                friend inline size operator +(const std::size_t argumentA, const size& argumentB) { size evaluation = argumentA; evaluation += argumentB; return evaluation; }
                friend inline size operator +(const std::size_t argumentA, const size&& argumentB) { size evaluation = argumentA; evaluation += argumentB; return evaluation; }
                inline size operator +(size& argument) const { size evaluation = *this; evaluation += argument; return evaluation; }
                inline size operator +(size&& argument) const { size evaluation = *this; evaluation += argument; return evaluation; }
                inline size operator +(const size& argument) const { size evaluation = *this; evaluation += argument; return evaluation; }
                inline size operator +(const size&& argument) const { size evaluation = *this; evaluation += argument; return evaluation; }

                // [-]
                inline size operator -(const std::size_t argument) const { size evaluation = *this; evaluation -= argument; return evaluation; }
                friend inline size operator -(const std::size_t argumentA, size& argumentB) { size evaluation = argumentA; evaluation -= argumentB; return evaluation; }
                friend inline size operator -(const std::size_t argumentA, size&& argumentB) { size evaluation = argumentA; evaluation -= argumentB; return evaluation; }
                friend inline size operator -(const std::size_t argumentA, const size& argumentB) { size evaluation = argumentA; evaluation -= argumentB; return evaluation; }
                friend inline size operator -(const std::size_t argumentA, const size&& argumentB) { size evaluation = argumentA; evaluation -= argumentB; return evaluation; }
                inline size operator -(size& argument) const { size evaluation = *this; evaluation -= argument; return evaluation; }
                inline size operator -(size&& argument) const { size evaluation = *this; evaluation -= argument; return evaluation; }
                inline size operator -(const size& argument) const { size evaluation = *this; evaluation -= argument; return evaluation; }
                inline size operator -(const size&& argument) const { size evaluation = *this; evaluation -= argument; return evaluation; }

                // [*]
                inline size operator *(const std::size_t argument) const { size evaluation = *this; evaluation *= argument; return evaluation; }
                friend inline size operator *(const std::size_t argumentA, size& argumentB) { size evaluation = argumentA; evaluation *= argumentB; return evaluation; }
                friend inline size operator *(const std::size_t argumentA, size&& argumentB) { size evaluation = argumentA; evaluation *= argumentB; return evaluation; }
                friend inline size operator *(const std::size_t argumentA, const size& argumentB) { size evaluation = argumentA; evaluation *= argumentB; return evaluation; }
                friend inline size operator *(const std::size_t argumentA, const size&& argumentB) { size evaluation = argumentA; evaluation *= argumentB; return evaluation; }
                inline size operator *(size& argument) const { size evaluation = *this; evaluation *= argument; return evaluation; }
                inline size operator *(size&& argument) const { size evaluation = *this; evaluation *= argument; return evaluation; }
                inline size operator *(const size& argument) const { size evaluation = *this; evaluation *= argument; return evaluation; }
                inline size operator *(const size&& argument) const { size evaluation = *this; evaluation *= argument; return evaluation; }

                // [/]
                inline size operator /(const std::size_t argument) const { size evaluation = *this; evaluation /= argument; return evaluation; }
                friend inline size operator /(const std::size_t argumentA, size& argumentB) { size evaluation = argumentA; evaluation /= argumentB; return evaluation; }
                friend inline size operator /(const std::size_t argumentA, size&& argumentB) { size evaluation = argumentA; evaluation /= argumentB; return evaluation; }
                friend inline size operator /(const std::size_t argumentA, const size& argumentB) { size evaluation = argumentA; evaluation /= argumentB; return evaluation; }
                friend inline size operator /(const std::size_t argumentA, const size&& argumentB) { size evaluation = argumentA; evaluation /= argumentB; return evaluation; }
                inline size operator /(size& argument) const { size evaluation = *this; evaluation /= argument; return evaluation; }
                inline size operator /(size&& argument) const { size evaluation = *this; evaluation /= argument; return evaluation; }
                inline size operator /(const size& argument) const { size evaluation = *this; evaluation /= argument; return evaluation; }
                inline size operator /(const size&& argument) const { size evaluation = *this; evaluation /= argument; return evaluation; }

                // [%]
                inline size operator %(const std::size_t argument) const { size evaluation = *this; evaluation %= argument; return evaluation; }
                friend inline size operator %(const std::size_t argumentA, size& argumentB) { size evaluation = argumentA; evaluation %= argumentB; return evaluation; }
                friend inline size operator %(const std::size_t argumentA, size&& argumentB) { size evaluation = argumentA; evaluation %= argumentB; return evaluation; }
                friend inline size operator %(const std::size_t argumentA, const size& argumentB) { size evaluation = argumentA; evaluation %= argumentB; return evaluation; }
                friend inline size operator %(const std::size_t argumentA, const size&& argumentB) { size evaluation = argumentA; evaluation %= argumentB; return evaluation; }
                inline size operator %(size& argument) const { size evaluation = *this; evaluation %= argument; return evaluation; }
                inline size operator %(size&& argument) const { size evaluation = *this; evaluation %= argument; return evaluation; }
                inline size operator %(const size& argument) const { size evaluation = *this; evaluation %= argument; return evaluation; }
                inline size operator %(const size&& argument) const { size evaluation = *this; evaluation %= argument; return evaluation; }

                // [^]
                inline size operator ^(const std::size_t argument) const { size evaluation = *this; evaluation ^= argument; return evaluation; }
                friend inline size operator ^(const std::size_t argumentA, size& argumentB) { size evaluation = argumentA; evaluation ^= argumentB; return evaluation; }
                friend inline size operator ^(const std::size_t argumentA, size&& argumentB) { size evaluation = argumentA; evaluation ^= argumentB; return evaluation; }
                friend inline size operator ^(const std::size_t argumentA, const size& argumentB) { size evaluation = argumentA; evaluation ^= argumentB; return evaluation; }
                friend inline size operator ^(const std::size_t argumentA, const size&& argumentB) { size evaluation = argumentA; evaluation ^= argumentB; return evaluation; }
                inline size operator ^(size& argument) const { size evaluation = *this; evaluation ^= argument; return evaluation; }
                inline size operator ^(size&& argument) const { size evaluation = *this; evaluation ^= argument; return evaluation; }
                inline size operator ^(const size& argument) const { size evaluation = *this; evaluation ^= argument; return evaluation; }
                inline size operator ^(const size&& argument) const { size evaluation = *this; evaluation ^= argument; return evaluation; }

                // [&]
                inline size operator &(const std::size_t argument) const { size evaluation = *this; evaluation &= argument; return evaluation; }
                friend inline size operator &(const std::size_t argumentA, size& argumentB) { size evaluation = argumentA; evaluation &= argumentB; return evaluation; }
                friend inline size operator &(const std::size_t argumentA, size&& argumentB) { size evaluation = argumentA; evaluation &= argumentB; return evaluation; }
                friend inline size operator &(const std::size_t argumentA, const size& argumentB) { size evaluation = argumentA; evaluation &= argumentB; return evaluation; }
                friend inline size operator &(const std::size_t argumentA, const size&& argumentB) { size evaluation = argumentA; evaluation &= argumentB; return evaluation; }
                inline size operator &(size& argument) const { size evaluation = *this; evaluation &= argument; return evaluation; }
                inline size operator &(size&& argument) const { size evaluation = *this; evaluation &= argument; return evaluation; }
                inline size operator &(const size& argument) const { size evaluation = *this; evaluation &= argument; return evaluation; }
                inline size operator &(const size&& argument) const { size evaluation = *this; evaluation &= argument; return evaluation; }

                // [|]
                inline size operator |(const std::size_t argument) const { size evaluation = *this; evaluation |= argument; return evaluation; }
                friend inline size operator |(const std::size_t argumentA, size& argumentB) { size evaluation = argumentA; evaluation |= argumentB; return evaluation; }
                friend inline size operator |(const std::size_t argumentA, size&& argumentB) { size evaluation = argumentA; evaluation |= argumentB; return evaluation; }
                friend inline size operator |(const std::size_t argumentA, const size& argumentB) { size evaluation = argumentA; evaluation |= argumentB; return evaluation; }
                friend inline size operator |(const std::size_t argumentA, const size&& argumentB) { size evaluation = argumentA; evaluation |= argumentB; return evaluation; }
                inline size operator |(size& argument) const { size evaluation = *this; evaluation |= argument; return evaluation; }
                inline size operator |(size&& argument) const { size evaluation = *this; evaluation |= argument; return evaluation; }
                inline size operator |(const size& argument) const { size evaluation = *this; evaluation |= argument; return evaluation; }
                inline size operator |(const size&& argument) const { size evaluation = *this; evaluation |= argument; return evaluation; }

                // [!]
                inline boolean operator !() const { return NULL == this -> first -> next && !(this -> current -> value); }

                // [=]
                inline size& operator =(const std::size_t argument) { this -> reset(argument); return *this; }
                size& operator =(size& argument) { this -> copy((const size&) argument); return *this; }
                size& operator =(size&& argument) { this -> copy((const size&) argument); return *this; }
                size& operator =(const size& argument) { this -> copy(argument); return *this; }
                size& operator =(const size&& argument) { this -> copy((const size&) argument); return *this; }

                size& operator =(boolean&); size& operator =(boolean&&);
                size& operator =(const boolean&); size& operator =(const boolean&&);

                size& operator =(primitive&); size& operator =(primitive&&);
                size& operator =(const primitive&); size& operator =(const primitive&&);

                // [<]
                inline boolean operator <(const std::size_t argument) const { return NULL == this -> first -> next && this -> current -> value < argument; }
                friend inline boolean operator <(const std::size_t argumentA, size& argumentB) { return argumentA < argumentB.current -> value; }
                friend inline boolean operator <(const std::size_t argumentA, size&& argumentB) { return argumentA < argumentB.current -> value; }
                friend inline boolean operator <(const std::size_t argumentA, const size& argumentB) { return argumentA < argumentB.current -> value; }
                friend inline boolean operator <(const std::size_t argumentA, const size&& argumentB) { return argumentA < argumentB.current -> value; }
                inline boolean operator <(size& argument) const { return this -> lesserThan((const size&) argument); }
                inline boolean operator <(size&& argument) const { return this -> lesserThan((const size&) argument); }
                inline boolean operator <(const size& argument) const { return this -> lesserThan(argument); }
                inline boolean operator <(const size&& argument) const { return this -> lesserThan((const size&) argument); }

                // [>]
                inline boolean operator >(const std::size_t argument) const { return NULL != this -> first -> next || this -> current -> value > argument; }
                friend inline boolean operator >(const std::size_t argumentA, size& argumentB) { return NULL == argumentB.first -> next && argumentA > argumentB.current -> value; }
                friend inline boolean operator >(const std::size_t argumentA, size&& argumentB) { return NULL == argumentB.first -> next && argumentA > argumentB.current -> value; }
                friend inline boolean operator >(const std::size_t argumentA, const size& argumentB) { return NULL == argumentB.first -> next && argumentA > argumentB.current -> value; }
                friend inline boolean operator >(const std::size_t argumentA, const size&& argumentB) { return NULL == argumentB.first -> next && argumentA > argumentB.current -> value; }
                inline boolean operator >(size& argument) const { return this -> greaterThan((const size&) argument); }
                inline boolean operator >(size&& argument) const { return this -> greaterThan((const size&) argument); }
                inline boolean operator >(const size& argument) const { return this -> greaterThan(argument); }
                inline boolean operator >(const size&& argument) const { return this -> greaterThan((const size&) argument); }

                // [+=]
                size& operator +=(const std::size_t argument) { this -> add(argument); return *this; }
                friend inline unsigned char& operator +=(unsigned char& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned char& operator +=(unsigned char& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned char& operator +=(unsigned char& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned char& operator +=(unsigned char& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned char& operator +=(unsigned char&& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned char& operator +=(unsigned char&& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned char& operator +=(unsigned char&& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned char& operator +=(unsigned char&& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned int& operator +=(unsigned int& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned int& operator +=(unsigned int& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned int& operator +=(unsigned int& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned int& operator +=(unsigned int& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned int& operator +=(unsigned int&& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned int& operator +=(unsigned int&& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned int& operator +=(unsigned int&& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned int& operator +=(unsigned int&& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long& operator +=(unsigned long& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long& operator +=(unsigned long& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long& operator +=(unsigned long& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long& operator +=(unsigned long& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long& operator +=(unsigned long&& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long& operator +=(unsigned long&& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long& operator +=(unsigned long&& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long& operator +=(unsigned long&& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long long& operator +=(unsigned long long& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long long& operator +=(unsigned long long& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long long& operator +=(unsigned long long& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long long& operator +=(unsigned long long& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long long& operator +=(unsigned long long&& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long long& operator +=(unsigned long long&& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long long& operator +=(unsigned long long&& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned long long& operator +=(unsigned long long&& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned short& operator +=(unsigned short& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned short& operator +=(unsigned short& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned short& operator +=(unsigned short& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned short& operator +=(unsigned short& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned short& operator +=(unsigned short&& argumentA, size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned short& operator +=(unsigned short&& argumentA, size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned short& operator +=(unsigned short&& argumentA, const size& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                friend inline unsigned short& operator +=(unsigned short&& argumentA, const size&& argumentB) {for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA += current -> value; return argumentA; }
                size& operator +=(size& argument) { this -> add(argument); return *this; }
                size& operator +=(size&& argument) { this -> add(argument); return *this; }
                size& operator +=(const size& argument) { this -> add(argument); return *this; }
                size& operator +=(const size&& argument) { this -> add(argument); return *this; }

                // [-=]
                size& operator -=(const std::size_t argument) { this -> subtract(argument); return *this; }
                friend inline unsigned char& operator -=(unsigned char& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned char& operator -=(unsigned char& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned char& operator -=(unsigned char& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned char& operator -=(unsigned char& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned char& operator -=(unsigned char&& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned char& operator -=(unsigned char&& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned char& operator -=(unsigned char&& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned char& operator -=(unsigned char&& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned int& operator -=(unsigned int& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned int& operator -=(unsigned int& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned int& operator -=(unsigned int& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned int& operator -=(unsigned int& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned int& operator -=(unsigned int&& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned int& operator -=(unsigned int&& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned int& operator -=(unsigned int&& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned int& operator -=(unsigned int&& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long& operator -=(unsigned long& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long& operator -=(unsigned long& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long& operator -=(unsigned long& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long& operator -=(unsigned long& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long& operator -=(unsigned long&& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long& operator -=(unsigned long&& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long& operator -=(unsigned long&& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long& operator -=(unsigned long&& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long long& operator -=(unsigned long long& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long long& operator -=(unsigned long long& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long long& operator -=(unsigned long long& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long long& operator -=(unsigned long long& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long long& operator -=(unsigned long long&& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long long& operator -=(unsigned long long&& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long long& operator -=(unsigned long long&& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned long long& operator -=(unsigned long long&& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned short& operator -=(unsigned short& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned short& operator -=(unsigned short& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned short& operator -=(unsigned short& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned short& operator -=(unsigned short& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned short& operator -=(unsigned short&& argumentA, size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned short& operator -=(unsigned short&& argumentA, size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned short& operator -=(unsigned short&& argumentA, const size& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                friend inline unsigned short& operator -=(unsigned short&& argumentA, const size&& argumentB) { for (exponent *current = argumentB.first; NULL != current; current = current -> next) argumentA -= current -> value; return argumentA; }
                size& operator -=(size& argument) { this -> subtract((const size&) argument); return *this; }
                size& operator -=(size&& argument) { this -> subtract((const size&) argument); return *this; }
                size& operator -=(const size& argument) { this -> subtract(argument); return *this; }
                size& operator -=(const size&& argument) { this -> subtract((const size&) argument); return *this; }

                // [*=]
                size& operator *=(const std::size_t argument) { this -> multiply(argument); return *this; }
                friend inline unsigned char& operator *=(unsigned char& argumentA, size& argumentB) { const unsigned char argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned char iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned char& operator *=(unsigned char& argumentA, size&& argumentB) { const unsigned char argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned char iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned char& operator *=(unsigned char& argumentA, const size& argumentB) { const unsigned char argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned char iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned char& operator *=(unsigned char& argumentA, const size&& argumentB) { const unsigned char argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned char iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned char& operator *=(unsigned char&& argumentA, size& argumentB) { const unsigned char argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned char iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned char& operator *=(unsigned char&& argumentA, size&& argumentB) { const unsigned char argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned char iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned char& operator *=(unsigned char&& argumentA, const size& argumentB) { const unsigned char argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned char iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned char& operator *=(unsigned char&& argumentA, const size&& argumentB) { const unsigned char argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned char iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned int& operator *=(unsigned int& argumentA, size& argumentB) { const unsigned int argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned int iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned int& operator *=(unsigned int& argumentA, size&& argumentB) { const unsigned int argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned int iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned int& operator *=(unsigned int& argumentA, const size& argumentB) { const unsigned int argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned int iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned int& operator *=(unsigned int& argumentA, const size&& argumentB) { const unsigned int argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned int iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned int& operator *=(unsigned int&& argumentA, size& argumentB) { const unsigned int argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned int iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned int& operator *=(unsigned int&& argumentA, size&& argumentB) { const unsigned int argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned int iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned int& operator *=(unsigned int&& argumentA, const size& argumentB) { const unsigned int argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned int iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned int& operator *=(unsigned int&& argumentA, const size&& argumentB) { const unsigned int argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned int iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long& operator *=(unsigned long& argumentA, size& argumentB) { const unsigned long argumentAValue = argumentA; argumentA = 0uL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long& operator *=(unsigned long& argumentA, size&& argumentB) { const unsigned long argumentAValue = argumentA; argumentA = 0uL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long& operator *=(unsigned long& argumentA, const size& argumentB) { const unsigned long argumentAValue = argumentA; argumentA = 0uL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long& operator *=(unsigned long& argumentA, const size&& argumentB) { const unsigned long argumentAValue = argumentA; argumentA = 0uL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long& operator *=(unsigned long&& argumentA, size& argumentB) { const unsigned long argumentAValue = argumentA; argumentA = 0uL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long& operator *=(unsigned long&& argumentA, size&& argumentB) { const unsigned long argumentAValue = argumentA; argumentA = 0uL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long& operator *=(unsigned long&& argumentA, const size& argumentB) { const unsigned long argumentAValue = argumentA; argumentA = 0uL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long& operator *=(unsigned long&& argumentA, const size&& argumentB) { const unsigned long argumentAValue = argumentA; argumentA = 0uL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long long& operator *=(unsigned long long& argumentA, size& argumentB) { const unsigned long long argumentAValue = argumentA; argumentA = 0uLL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long long& operator *=(unsigned long long& argumentA, size&& argumentB) { const unsigned long long argumentAValue = argumentA; argumentA = 0uLL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long long& operator *=(unsigned long long& argumentA, const size& argumentB) { const unsigned long long argumentAValue = argumentA; argumentA = 0uLL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long long& operator *=(unsigned long long& argumentA, const size&& argumentB) { const unsigned long long argumentAValue = argumentA; argumentA = 0uLL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long long& operator *=(unsigned long long&& argumentA, size& argumentB) { const unsigned long long argumentAValue = argumentA; argumentA = 0uLL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long long& operator *=(unsigned long long&& argumentA, size&& argumentB) { const unsigned long long argumentAValue = argumentA; argumentA = 0uLL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long long& operator *=(unsigned long long&& argumentA, const size& argumentB) { const unsigned long long argumentAValue = argumentA; argumentA = 0uLL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned long long& operator *=(unsigned long long&& argumentA, const size&& argumentB) { const unsigned long long argumentAValue = argumentA; argumentA = 0uLL; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned long long iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned short& operator *=(unsigned short& argumentA, size& argumentB) { const unsigned short argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned short iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned short& operator *=(unsigned short& argumentA, size&& argumentB) { const unsigned short argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned short iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned short& operator *=(unsigned short& argumentA, const size& argumentB) { const unsigned short argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned short iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned short& operator *=(unsigned short& argumentA, const size&& argumentB) { const unsigned short argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned short iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned short& operator *=(unsigned short&& argumentA, size& argumentB) { const unsigned short argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned short iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned short& operator *=(unsigned short&& argumentA, size&& argumentB) { const unsigned short argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned short iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned short& operator *=(unsigned short&& argumentA, const size& argumentB) { const unsigned short argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned short iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                friend inline unsigned short& operator *=(unsigned short&& argumentA, const size&& argumentB) { const unsigned short argumentAValue = argumentA; argumentA = 0u; for (exponent *current = argumentB.first; NULL != current; current = current -> next) for (unsigned short iterator = 0u; iterator ^ current -> value; iterator++) argumentA += argumentAValue; return argumentA; }
                size& operator *=(size&); size& operator *=(size&&);
                size& operator *=(const size&); size& operator *=(const size&&);

                // [/=]
                size& operator /=(const std::size_t argument) { this -> divide(argument); return *this; }
                friend inline unsigned char& operator /=(unsigned char& argumentA, size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned char& operator /=(unsigned char& argumentA, size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned char& operator /=(unsigned char& argumentA, const size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned char& operator /=(unsigned char& argumentA, const size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned int& operator /=(unsigned int& argumentA, size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned int& operator /=(unsigned int& argumentA, size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned int& operator /=(unsigned int& argumentA, const size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned int& operator /=(unsigned int& argumentA, const size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned long& operator /=(unsigned long& argumentA, size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0uL; return argumentA; }
                friend inline unsigned long& operator /=(unsigned long& argumentA, size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0uL; return argumentA; }
                friend inline unsigned long& operator /=(unsigned long& argumentA, const size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0uL; return argumentA; }
                friend inline unsigned long& operator /=(unsigned long& argumentA, const size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0uL; return argumentA; }
                friend inline unsigned long long& operator /=(unsigned long long& argumentA, size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0uLL; return argumentA; }
                friend inline unsigned long long& operator /=(unsigned long long& argumentA, size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0uLL; return argumentA; }
                friend inline unsigned long long& operator /=(unsigned long long& argumentA, const size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0uLL; return argumentA; }
                friend inline unsigned long long& operator /=(unsigned long long& argumentA, const size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0uLL; return argumentA; }
                friend inline unsigned short& operator /=(unsigned short& argumentA, size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned short& operator /=(unsigned short& argumentA, size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned short& operator /=(unsigned short& argumentA, const size& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                friend inline unsigned short& operator /=(unsigned short& argumentA, const size&& argumentB) { if (NULL == argumentB.first -> next) argumentA /= argumentB.current -> value; else argumentA = 0u; return argumentA; }
                size& operator /=(size&); size& operator /=(size&&);
                size& operator /=(const size&); size& operator /=(const size&&);

                // [%=]
                size& operator %=(const std::size_t argument) { this -> modulo(argument); return *this; }
                friend inline unsigned char& operator %=(unsigned char& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned char& operator %=(unsigned char& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned char& operator %=(unsigned char& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned char& operator %=(unsigned char& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned char& operator %=(unsigned char&& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned char& operator %=(unsigned char&& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned char& operator %=(unsigned char&& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned char& operator %=(unsigned char&& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned int& operator %=(unsigned int& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned int& operator %=(unsigned int& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned int& operator %=(unsigned int& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned int& operator %=(unsigned int& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned int& operator %=(unsigned int&& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned int& operator %=(unsigned int&& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned int& operator %=(unsigned int&& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned int& operator %=(unsigned int&& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long& operator %=(unsigned long& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long& operator %=(unsigned long& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long& operator %=(unsigned long& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long& operator %=(unsigned long& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long& operator %=(unsigned long&& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long& operator %=(unsigned long&& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long& operator %=(unsigned long&& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long& operator %=(unsigned long&& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long long& operator %=(unsigned long long& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long long& operator %=(unsigned long long& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long long& operator %=(unsigned long long& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long long& operator %=(unsigned long long& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long long& operator %=(unsigned long long&& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long long& operator %=(unsigned long long&& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long long& operator %=(unsigned long long&& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned long long& operator %=(unsigned long long&& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned short& operator %=(unsigned short& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned short& operator %=(unsigned short& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned short& operator %=(unsigned short& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned short& operator %=(unsigned short& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned short& operator %=(unsigned short&& argumentA, size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned short& operator %=(unsigned short&& argumentA, size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned short& operator %=(unsigned short&& argumentA, const size& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                friend inline unsigned short& operator %=(unsigned short&& argumentA, const size&& argumentB) { if (NULL != argumentB.first -> next) argumentA %= argumentB.current -> value; return argumentA; }
                size& operator %=(size&); size& operator %=(size&&);
                size& operator %=(const size&); size& operator %=(const size&&);

                // [^=] --- UPDATE (Lapys) -> Algorithm required.
                size& operator ^=(const std::size_t);
                friend inline unsigned char& operator ^=(unsigned char&, size&); friend inline unsigned char& operator ^=(unsigned char&, size&&);
                friend inline unsigned char& operator ^=(unsigned char&, const size&); friend inline unsigned char& operator ^=(unsigned char&, const size&&);
                friend inline unsigned char& operator ^=(unsigned char&&, size&); friend inline unsigned char& operator ^=(unsigned char&&, size&&);
                friend inline unsigned char& operator ^=(unsigned char&&, const size&); friend inline unsigned char& operator ^=(unsigned char&&, const size&&);
                friend inline unsigned int& operator ^=(unsigned int&, size&); friend inline unsigned int& operator ^=(unsigned int&, size&&);
                friend inline unsigned int& operator ^=(unsigned int&, const size&); friend inline unsigned int& operator ^=(unsigned int&, const size&&);
                friend inline unsigned int& operator ^=(unsigned int&&, size&); friend inline unsigned int& operator ^=(unsigned int&&, size&&);
                friend inline unsigned int& operator ^=(unsigned int&&, const size&); friend inline unsigned int& operator ^=(unsigned int&&, const size&&);
                friend inline unsigned long& operator ^=(unsigned long&, size&); friend inline unsigned long& operator ^=(unsigned long&, size&&);
                friend inline unsigned long& operator ^=(unsigned long&, const size&); friend inline unsigned long& operator ^=(unsigned long&, const size&&);
                friend inline unsigned long& operator ^=(unsigned long&&, size&); friend inline unsigned long& operator ^=(unsigned long&&, size&&);
                friend inline unsigned long& operator ^=(unsigned long&&, const size&); friend inline unsigned long& operator ^=(unsigned long&&, const size&&);
                friend inline unsigned long long& operator ^=(unsigned long long&, size&); friend inline unsigned long long& operator ^=(unsigned long long&, size&&);
                friend inline unsigned long long& operator ^=(unsigned long long&, const size&); friend inline unsigned long long& operator ^=(unsigned long long&, const size&&);
                friend inline unsigned long long& operator ^=(unsigned long long&&, size&); friend inline unsigned long long& operator ^=(unsigned long long&&, size&&);
                friend inline unsigned long long& operator ^=(unsigned long long&&, const size&); friend inline unsigned long long& operator ^=(unsigned long long&&, const size&&);
                friend inline unsigned short& operator ^=(unsigned short&, size&); friend inline unsigned short& operator ^=(unsigned short&, size&&);
                friend inline unsigned short& operator ^=(unsigned short&, const size&); friend inline unsigned short& operator ^=(unsigned short&, const size&&);
                friend inline unsigned short& operator ^=(unsigned short&&, size&); friend inline unsigned short& operator ^=(unsigned short&&, size&&);
                friend inline unsigned short& operator ^=(unsigned short&&, const size&); friend inline unsigned short& operator ^=(unsigned short&&, const size&&);
                size& operator ^=(size&); size& operator ^=(size&&);
                size& operator ^=(const size&); size& operator ^=(const size&&);

                // [&=] --- UPDATE (Lapys) -> Algorithm required.
                size& operator &=(const std::size_t);
                friend inline unsigned char& operator &=(unsigned char&, size&); friend inline unsigned char& operator &=(unsigned char&, size&&);
                friend inline unsigned char& operator &=(unsigned char&, const size&); friend inline unsigned char& operator &=(unsigned char&, const size&&);
                friend inline unsigned char& operator &=(unsigned char&&, size&); friend inline unsigned char& operator &=(unsigned char&&, size&&);
                friend inline unsigned char& operator &=(unsigned char&&, const size&); friend inline unsigned char& operator &=(unsigned char&&, const size&&);
                friend inline unsigned int& operator &=(unsigned int&, size&); friend inline unsigned int& operator &=(unsigned int&, size&&);
                friend inline unsigned int& operator &=(unsigned int&, const size&); friend inline unsigned int& operator &=(unsigned int&, const size&&);
                friend inline unsigned int& operator &=(unsigned int&&, size&); friend inline unsigned int& operator &=(unsigned int&&, size&&);
                friend inline unsigned int& operator &=(unsigned int&&, const size&); friend inline unsigned int& operator &=(unsigned int&&, const size&&);
                friend inline unsigned long& operator &=(unsigned long&, size&); friend inline unsigned long& operator &=(unsigned long&, size&&);
                friend inline unsigned long& operator &=(unsigned long&, const size&); friend inline unsigned long& operator &=(unsigned long&, const size&&);
                friend inline unsigned long& operator &=(unsigned long&&, size&); friend inline unsigned long& operator &=(unsigned long&&, size&&);
                friend inline unsigned long& operator &=(unsigned long&&, const size&); friend inline unsigned long& operator &=(unsigned long&&, const size&&);
                friend inline unsigned long long& operator &=(unsigned long long&, size&); friend inline unsigned long long& operator &=(unsigned long long&, size&&);
                friend inline unsigned long long& operator &=(unsigned long long&, const size&); friend inline unsigned long long& operator &=(unsigned long long&, const size&&);
                friend inline unsigned long long& operator &=(unsigned long long&&, size&); friend inline unsigned long long& operator &=(unsigned long long&&, size&&);
                friend inline unsigned long long& operator &=(unsigned long long&&, const size&); friend inline unsigned long long& operator &=(unsigned long long&&, const size&&);
                friend inline unsigned short& operator &=(unsigned short&, size&); friend inline unsigned short& operator &=(unsigned short&, size&&);
                friend inline unsigned short& operator &=(unsigned short&, const size&); friend inline unsigned short& operator &=(unsigned short&, const size&&);
                friend inline unsigned short& operator &=(unsigned short&&, size&); friend inline unsigned short& operator &=(unsigned short&&, size&&);
                friend inline unsigned short& operator &=(unsigned short&&, const size&); friend inline unsigned short& operator &=(unsigned short&&, const size&&);
                size& operator &=(size&); size& operator &=(size&&);
                size& operator &=(const size&); size& operator &=(const size&&);

                // [|=] --- UPDATE (Lapys) -> Algorithm required.
                size& operator |=(const std::size_t);
                friend inline unsigned char& operator |=(unsigned char&, size&); friend inline unsigned char& operator |=(unsigned char&, size&&);
                friend inline unsigned char& operator |=(unsigned char&, const size&); friend inline unsigned char& operator |=(unsigned char&, const size&&);
                friend inline unsigned char& operator |=(unsigned char&&, size&); friend inline unsigned char& operator |=(unsigned char&&, size&&);
                friend inline unsigned char& operator |=(unsigned char&&, const size&); friend inline unsigned char& operator |=(unsigned char&&, const size&&);
                friend inline unsigned int& operator |=(unsigned int&, size&); friend inline unsigned int& operator |=(unsigned int&, size&&);
                friend inline unsigned int& operator |=(unsigned int&, const size&); friend inline unsigned int& operator |=(unsigned int&, const size&&);
                friend inline unsigned int& operator |=(unsigned int&&, size&); friend inline unsigned int& operator |=(unsigned int&&, size&&);
                friend inline unsigned int& operator |=(unsigned int&&, const size&); friend inline unsigned int& operator |=(unsigned int&&, const size&&);
                friend inline unsigned long& operator |=(unsigned long&, size&); friend inline unsigned long& operator |=(unsigned long&, size&&);
                friend inline unsigned long& operator |=(unsigned long&, const size&); friend inline unsigned long& operator |=(unsigned long&, const size&&);
                friend inline unsigned long& operator |=(unsigned long&&, size&); friend inline unsigned long& operator |=(unsigned long&&, size&&);
                friend inline unsigned long& operator |=(unsigned long&&, const size&); friend inline unsigned long& operator |=(unsigned long&&, const size&&);
                friend inline unsigned long long& operator |=(unsigned long long&, size&); friend inline unsigned long long& operator |=(unsigned long long&, size&&);
                friend inline unsigned long long& operator |=(unsigned long long&, const size&); friend inline unsigned long long& operator |=(unsigned long long&, const size&&);
                friend inline unsigned long long& operator |=(unsigned long long&&, size&); friend inline unsigned long long& operator |=(unsigned long long&&, size&&);
                friend inline unsigned long long& operator |=(unsigned long long&&, const size&); friend inline unsigned long long& operator |=(unsigned long long&&, const size&&);
                friend inline unsigned short& operator |=(unsigned short&, size&); friend inline unsigned short& operator |=(unsigned short&, size&&);
                friend inline unsigned short& operator |=(unsigned short&, const size&); friend inline unsigned short& operator |=(unsigned short&, const size&&);
                friend inline unsigned short& operator |=(unsigned short&&, size&); friend inline unsigned short& operator |=(unsigned short&&, size&&);
                friend inline unsigned short& operator |=(unsigned short&&, const size&); friend inline unsigned short& operator |=(unsigned short&&, const size&&);
                size& operator |=(size&); size& operator |=(size&&);
                size& operator |=(const size&); size& operator |=(const size&&);

                // [<<] --- UPDATE (Lapys) -> `<<=` operator overload required.
                size operator <<(const std::size_t) const;
                friend unsigned char& operator <<(unsigned char&, size&); friend unsigned char& operator <<(unsigned char&, size&&);
                friend unsigned char& operator <<(unsigned char&, const size&); friend unsigned char& operator <<(unsigned char&, const size&&);
                friend unsigned char& operator <<(unsigned char&&, size&); friend unsigned char& operator <<(unsigned char&&, size&&);
                friend unsigned char& operator <<(unsigned char&&, const size&); friend unsigned char& operator <<(unsigned char&&, const size&&);
                friend unsigned int& operator <<(unsigned int&, size&); friend unsigned int& operator <<(unsigned int&, size&&);
                friend unsigned int& operator <<(unsigned int&, const size&); friend unsigned int& operator <<(unsigned int&, const size&&);
                friend unsigned int& operator <<(unsigned int&&, size&); friend unsigned int& operator <<(unsigned int&&, size&&);
                friend unsigned int& operator <<(unsigned int&&, const size&); friend unsigned int& operator <<(unsigned int&&, const size&&);
                friend unsigned long& operator <<(unsigned long&, size&); friend unsigned long& operator <<(unsigned long&, size&&);
                friend unsigned long& operator <<(unsigned long&, const size&); friend unsigned long& operator <<(unsigned long&, const size&&);
                friend unsigned long& operator <<(unsigned long&&, size&); friend unsigned long& operator <<(unsigned long&&, size&&);
                friend unsigned long& operator <<(unsigned long&&, const size&); friend unsigned long& operator <<(unsigned long&&, const size&&);
                friend unsigned long long& operator <<(unsigned long long&, size&); friend unsigned long long& operator <<(unsigned long long&, size&&);
                friend unsigned long long& operator <<(unsigned long long&, const size&); friend unsigned long long& operator <<(unsigned long long&, const size&&);
                friend unsigned long long& operator <<(unsigned long long&&, size&); friend unsigned long long& operator <<(unsigned long long&&, size&&);
                friend unsigned long long& operator <<(unsigned long long&&, const size&); friend unsigned long long& operator <<(unsigned long long&&, const size&&);
                friend unsigned short& operator <<(unsigned short&, size&); friend unsigned short& operator <<(unsigned short&, size&&);
                friend unsigned short& operator <<(unsigned short&, const size&); friend unsigned short& operator <<(unsigned short&, const size&&);
                friend unsigned short& operator <<(unsigned short&&, size&); friend unsigned short& operator <<(unsigned short&&, size&&);
                friend unsigned short& operator <<(unsigned short&&, const size&); friend unsigned short& operator <<(unsigned short&&, const size&&);
                size operator <<(size&) const; size operator <<(size&&) const;
                size operator <<(const size&) const; size operator <<(const size&&) const;

                // [>>] --- UPDATE (Lapys) -> `>>=` operator overload required.
                size operator >>(const std::size_t) const;
                friend unsigned char& operator >>(unsigned char&, size&); friend unsigned char& operator >>(unsigned char&, size&&);
                friend unsigned char& operator >>(unsigned char&, const size&); friend unsigned char& operator >>(unsigned char&, const size&&);
                friend unsigned char& operator >>(unsigned char&&, size&); friend unsigned char& operator >>(unsigned char&&, size&&);
                friend unsigned char& operator >>(unsigned char&&, const size&); friend unsigned char& operator >>(unsigned char&&, const size&&);
                friend unsigned int& operator >>(unsigned int&, size&); friend unsigned int& operator >>(unsigned int&, size&&);
                friend unsigned int& operator >>(unsigned int&, const size&); friend unsigned int& operator >>(unsigned int&, const size&&);
                friend unsigned int& operator >>(unsigned int&&, size&); friend unsigned int& operator >>(unsigned int&&, size&&);
                friend unsigned int& operator >>(unsigned int&&, const size&); friend unsigned int& operator >>(unsigned int&&, const size&&);
                friend unsigned long& operator >>(unsigned long&, size&); friend unsigned long& operator >>(unsigned long&, size&&);
                friend unsigned long& operator >>(unsigned long&, const size&); friend unsigned long& operator >>(unsigned long&, const size&&);
                friend unsigned long& operator >>(unsigned long&&, size&); friend unsigned long& operator >>(unsigned long&&, size&&);
                friend unsigned long& operator >>(unsigned long&&, const size&); friend unsigned long& operator >>(unsigned long&&, const size&&);
                friend unsigned long long& operator >>(unsigned long long&, size&); friend unsigned long long& operator >>(unsigned long long&, size&&);
                friend unsigned long long& operator >>(unsigned long long&, const size&); friend unsigned long long& operator >>(unsigned long long&, const size&&);
                friend unsigned long long& operator >>(unsigned long long&&, size&); friend unsigned long long& operator >>(unsigned long long&&, size&&);
                friend unsigned long long& operator >>(unsigned long long&&, const size&); friend unsigned long long& operator >>(unsigned long long&&, const size&&);
                friend unsigned short& operator >>(unsigned short&, size&); friend unsigned short& operator >>(unsigned short&, size&&);
                friend unsigned short& operator >>(unsigned short&, const size&); friend unsigned short& operator >>(unsigned short&, const size&&);
                friend unsigned short& operator >>(unsigned short&&, size&); friend unsigned short& operator >>(unsigned short&&, size&&);
                friend unsigned short& operator >>(unsigned short&&, const size&); friend unsigned short& operator >>(unsigned short&&, const size&&);
                size operator >>(size&) const; size operator >>(size&&) const;
                size operator >>(const size&) const; size operator >>(const size&&) const;

                // [>>=] --- UPDATE (Lapys) -> Algorithm required.
                size& operator >>=(const std::size_t);
                friend inline unsigned char& operator >>=(unsigned char&, size&); friend inline unsigned char& operator >>=(unsigned char&, size&&);
                friend inline unsigned char& operator >>=(unsigned char&, const size&); friend inline unsigned char& operator >>=(unsigned char&, const size&&);
                friend inline unsigned char& operator >>=(unsigned char&&, size&); friend inline unsigned char& operator >>=(unsigned char&&, size&&);
                friend inline unsigned char& operator >>=(unsigned char&&, const size&); friend inline unsigned char& operator >>=(unsigned char&&, const size&&);
                friend inline unsigned int& operator >>=(unsigned int&, size&); friend inline unsigned int& operator >>=(unsigned int&, size&&);
                friend inline unsigned int& operator >>=(unsigned int&, const size&); friend inline unsigned int& operator >>=(unsigned int&, const size&&);
                friend inline unsigned int& operator >>=(unsigned int&&, size&); friend inline unsigned int& operator >>=(unsigned int&&, size&&);
                friend inline unsigned int& operator >>=(unsigned int&&, const size&); friend inline unsigned int& operator >>=(unsigned int&&, const size&&);
                friend inline unsigned long& operator >>=(unsigned long&, size&); friend inline unsigned long& operator >>=(unsigned long&, size&&);
                friend inline unsigned long& operator >>=(unsigned long&, const size&); friend inline unsigned long& operator >>=(unsigned long&, const size&&);
                friend inline unsigned long& operator >>=(unsigned long&&, size&); friend inline unsigned long& operator >>=(unsigned long&&, size&&);
                friend inline unsigned long& operator >>=(unsigned long&&, const size&); friend inline unsigned long& operator >>=(unsigned long&&, const size&&);
                friend inline unsigned long long& operator >>=(unsigned long long&, size&); friend inline unsigned long long& operator >>=(unsigned long long&, size&&);
                friend inline unsigned long long& operator >>=(unsigned long long&, const size&); friend inline unsigned long long& operator >>=(unsigned long long&, const size&&);
                friend inline unsigned long long& operator >>=(unsigned long long&&, size&); friend inline unsigned long long& operator >>=(unsigned long long&&, size&&);
                friend inline unsigned long long& operator >>=(unsigned long long&&, const size&); friend inline unsigned long long& operator >>=(unsigned long long&&, const size&&);
                friend inline unsigned short& operator >>=(unsigned short&, size&); friend inline unsigned short& operator >>=(unsigned short&, size&&);
                friend inline unsigned short& operator >>=(unsigned short&, const size&); friend inline unsigned short& operator >>=(unsigned short&, const size&&);
                friend inline unsigned short& operator >>=(unsigned short&&, size&); friend inline unsigned short& operator >>=(unsigned short&&, size&&);
                friend inline unsigned short& operator >>=(unsigned short&&, const size&); friend inline unsigned short& operator >>=(unsigned short&&, const size&&);
                size& operator >>=(size&); size& operator >>=(size&&);
                size& operator >>=(const size&); size& operator >>=(const size&&);

                // [<<=] --- UPDATE (Lapys) -> Algorithm required.
                size& operator <<=(const std::size_t);
                friend inline unsigned char& operator <<=(unsigned char&, size&); friend inline unsigned char& operator <<=(unsigned char&, size&&);
                friend inline unsigned char& operator <<=(unsigned char&, const size&); friend inline unsigned char& operator <<=(unsigned char&, const size&&);
                friend inline unsigned char& operator <<=(unsigned char&&, size&); friend inline unsigned char& operator <<=(unsigned char&&, size&&);
                friend inline unsigned char& operator <<=(unsigned char&&, const size&); friend inline unsigned char& operator <<=(unsigned char&&, const size&&);
                friend inline unsigned int& operator <<=(unsigned int&, size&); friend inline unsigned int& operator <<=(unsigned int&, size&&);
                friend inline unsigned int& operator <<=(unsigned int&, const size&); friend inline unsigned int& operator <<=(unsigned int&, const size&&);
                friend inline unsigned int& operator <<=(unsigned int&&, size&); friend inline unsigned int& operator <<=(unsigned int&&, size&&);
                friend inline unsigned int& operator <<=(unsigned int&&, const size&); friend inline unsigned int& operator <<=(unsigned int&&, const size&&);
                friend inline unsigned long& operator <<=(unsigned long&, size&); friend inline unsigned long& operator <<=(unsigned long&, size&&);
                friend inline unsigned long& operator <<=(unsigned long&, const size&); friend inline unsigned long& operator <<=(unsigned long&, const size&&);
                friend inline unsigned long& operator <<=(unsigned long&&, size&); friend inline unsigned long& operator <<=(unsigned long&&, size&&);
                friend inline unsigned long& operator <<=(unsigned long&&, const size&); friend inline unsigned long& operator <<=(unsigned long&&, const size&&);
                friend inline unsigned long long& operator <<=(unsigned long long&, size&); friend inline unsigned long long& operator <<=(unsigned long long&, size&&);
                friend inline unsigned long long& operator <<=(unsigned long long&, const size&); friend inline unsigned long long& operator <<=(unsigned long long&, const size&&);
                friend inline unsigned long long& operator <<=(unsigned long long&&, size&); friend inline unsigned long long& operator <<=(unsigned long long&&, size&&);
                friend inline unsigned long long& operator <<=(unsigned long long&&, const size&); friend inline unsigned long long& operator <<=(unsigned long long&&, const size&&);
                friend inline unsigned short& operator <<=(unsigned short&, size&); friend inline unsigned short& operator <<=(unsigned short&, size&&);
                friend inline unsigned short& operator <<=(unsigned short&, const size&); friend inline unsigned short& operator <<=(unsigned short&, const size&&);
                friend inline unsigned short& operator <<=(unsigned short&&, size&); friend inline unsigned short& operator <<=(unsigned short&&, size&&);
                friend inline unsigned short& operator <<=(unsigned short&&, const size&); friend inline unsigned short& operator <<=(unsigned short&&, const size&&);
                size& operator <<=(size&); size& operator <<=(size&&);
                size& operator <<=(const size&); size& operator <<=(const size&&);

                // [==]
                inline boolean operator ==(const std::size_t argument) const { return NULL == this -> first -> next && this -> current -> value == argument; }
                friend inline boolean operator ==(const std::size_t argumentA, size& argumentB) { return NULL == argumentB.first -> next && argumentA == argumentB.current -> value; }
                friend inline boolean operator ==(const std::size_t argumentA, size&& argumentB) { return NULL == argumentB.first -> next && argumentA == argumentB.current -> value; }
                friend inline boolean operator ==(const std::size_t argumentA, const size& argumentB) { return NULL == argumentB.first -> next && argumentA == argumentB.current -> value; }
                friend inline boolean operator ==(const std::size_t argumentA, const size&& argumentB) { return NULL == argumentB.first -> next && argumentA == argumentB.current -> value; }
                inline boolean operator ==(size& argument) const { return this -> equals((const size&) argument); }
                inline boolean operator ==(size&& argument) const { return this -> equals((const size&) argument); }
                inline boolean operator ==(const size& argument) const { return this -> equals(argument); }
                inline boolean operator ==(const size&& argument) const { return this -> equals((const size&) argument); }

                // [!=]
                inline boolean operator !=(const std::size_t argument) const { return NULL != this -> first -> next || (this -> current -> value ^ argument); }
                friend inline boolean operator !=(const std::size_t argumentA, size& argumentB) { return NULL != argumentB.first -> next || (argumentA ^ argumentB.current -> value); }
                friend inline boolean operator !=(const std::size_t argumentA, size&& argumentB) { return NULL != argumentB.first -> next || (argumentA ^ argumentB.current -> value); }
                friend inline boolean operator !=(const std::size_t argumentA, const size& argumentB) { return NULL != argumentB.first -> next || (argumentA ^ argumentB.current -> value); }
                friend inline boolean operator !=(const std::size_t argumentA, const size&& argumentB) { return NULL != argumentB.first -> next || (argumentA ^ argumentB.current -> value); }
                inline boolean operator !=(size& argument) const { return !(this -> equals((const size&) argument)); }
                inline boolean operator !=(size&& argument) const { return !(this -> equals((const size&) argument)); }
                inline boolean operator !=(const size& argument) const { return !(this -> equals(argument)); }
                inline boolean operator !=(const size&& argument) const { return !(this -> equals((const size&) argument)); }

                // [<=]
                inline boolean operator <=(const std::size_t argument) const { return NULL == this -> first -> next && this -> current -> value <= argument; }
                friend inline boolean operator <=(const std::size_t argumentA, size& argumentB) { return NULL != argumentB.first -> next || argumentA <= argumentB.current -> value; }
                friend inline boolean operator <=(const std::size_t argumentA, size&& argumentB) { return NULL != argumentB.first -> next || argumentA <= argumentB.current -> value; }
                friend inline boolean operator <=(const std::size_t argumentA, const size& argumentB) { return NULL != argumentB.first -> next || argumentA <= argumentB.current -> value; }
                friend inline boolean operator <=(const std::size_t argumentA, const size&& argumentB) { return NULL != argumentB.first -> next || argumentA <= argumentB.current -> value; }
                inline boolean operator <=(size& argument) const { return this -> equals((const size&) argument) || this -> lesserThan((const size&) argument); }
                inline boolean operator <=(size&& argument) const { return this -> equals((const size&) argument) || this -> lesserThan((const size&) argument); }
                inline boolean operator <=(const size& argument) const { return this -> equals(argument) || this -> lesserThan(argument); }
                inline boolean operator <=(const size&& argument) const { return this -> equals((const size&) argument) || this -> lesserThan((const size&) argument); }

                // [>=]
                inline boolean operator >=(const std::size_t argument) const { return NULL != this -> first -> next || this -> current -> value >= argument; }
                friend inline boolean operator >=(const std::size_t argumentA, size& argumentB) { return NULL == argumentB.first -> next && argumentA >= argumentB.current -> value; }
                friend inline boolean operator >=(const std::size_t argumentA, size&& argumentB) { return NULL == argumentB.first -> next && argumentA >= argumentB.current -> value; }
                friend inline boolean operator >=(const std::size_t argumentA, const size& argumentB) { return NULL == argumentB.first -> next && argumentA >= argumentB.current -> value; }
                friend inline boolean operator >=(const std::size_t argumentA, const size&& argumentB) { return NULL == argumentB.first -> next && argumentA >= argumentB.current -> value; }
                inline boolean operator >=(size& argument) const { return this -> equals((const size&) argument) || this -> greaterThan((const size&) argument); }
                inline boolean operator >=(size&& argument) const { return this -> equals((const size&) argument) || this -> greaterThan((const size&) argument); }
                inline boolean operator >=(const size& argument) const { return this -> equals(argument) || this -> greaterThan(argument); }
                inline boolean operator >=(const size&& argument) const { return this -> equals((const size&) argument) || this -> greaterThan((const size&) argument); }

                // [&&]
                inline boolean operator &&(const std::size_t argument) const { return (this -> current -> value || NULL != this -> first -> next) && argument; }
                friend inline boolean operator &&(const std::size_t argumentA, size& argumentB) { return argumentA && (argumentB.current -> value || NULL != argumentB.first -> next); }
                friend inline boolean operator &&(const std::size_t argumentA, size&& argumentB) { return argumentA && (argumentB.current -> value || NULL != argumentB.first -> next); }
                friend inline boolean operator &&(const std::size_t argumentA, const size& argumentB) { return argumentA && (argumentB.current -> value || NULL != argumentB.first -> next); }
                friend inline boolean operator &&(const std::size_t argumentA, const size&& argumentB) { return argumentA && (argumentB.current -> value || NULL != argumentB.first -> next); }
                inline boolean operator &&(size& argument) const { return (this -> current -> value || NULL != this -> first -> next) && (argument.current -> value || NULL != argument.first -> next); }
                inline boolean operator &&(size&& argument) const { return (this -> current -> value || NULL != this -> first -> next) && (argument.current -> value || NULL != argument.first -> next); }
                inline boolean operator &&(const size& argument) const { return (this -> current -> value || NULL != this -> first -> next) && (argument.current -> value || NULL != argument.first -> next); }
                inline boolean operator &&(const size&& argument) const { return (this -> current -> value || NULL != this -> first -> next) && (argument.current -> value || NULL != argument.first -> next); }

                // [||]
                inline boolean operator ||(const std::size_t argument) const { return (this -> current -> value || NULL != this -> first -> next) || argument; }
                friend inline boolean operator ||(const std::size_t argumentA, size& argumentB) { return argumentA || (argumentB.current -> value || NULL != argumentB.first -> next); }
                friend inline boolean operator ||(const std::size_t argumentA, size&& argumentB) { return argumentA || (argumentB.current -> value || NULL != argumentB.first -> next); }
                friend inline boolean operator ||(const std::size_t argumentA, const size& argumentB) { return argumentA || (argumentB.current -> value || NULL != argumentB.first -> next); }
                friend inline boolean operator ||(const std::size_t argumentA, const size&& argumentB) { return argumentA || (argumentB.current -> value || NULL != argumentB.first -> next); }
                inline boolean operator ||(size& argument) const { return (this -> current -> value || NULL != this -> first -> next) || (argument.current -> value || NULL != argument.first -> next); }
                inline boolean operator ||(size&& argument) const { return (this -> current -> value || NULL != this -> first -> next) || (argument.current -> value || NULL != argument.first -> next); }
                inline boolean operator ||(const size& argument) const { return (this -> current -> value || NULL != this -> first -> next) || (argument.current -> value || NULL != argument.first -> next); }
                inline boolean operator ||(const size&& argument) const { return (this -> current -> value || NULL != this -> first -> next) || (argument.current -> value || NULL != argument.first -> next); }

                // [++]
                size& operator ++() { this -> increment(); return *this; }
                size& operator ++(int) { this -> increment(); return *this; }

                // [--]
                size& operator --() { this -> decrement(); return *this; }
                size& operator --(int) { this -> decrement(); return *this; }

                // [...] --- WARN (Lapys) -> Returns the current exponent value.
                inline operator std::size_t() const { return this -> current -> value; }
    } size;
#endif
