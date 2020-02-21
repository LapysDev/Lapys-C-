/* Global */
    // Null --- NOTE (Lapys) -> Does not coerce to `int`.
    const struct pointer {
        // [...]
        private:
            // [Operator] > [&]
            inline void operator &() const;

        // [...]
        public:
            // [Operator] > [...]
            inline operator char*() const { return '\0'; }
            inline operator double*() const { return 0; }
            inline operator float*() const { return 0; }
            inline operator int*() const { return 0; }
            inline operator long*() const { return 0L; }
            inline operator short*() const { return 0; }
            inline operator signed char*() const { return 0; }
            inline operator unsigned char*() const { return 0u; }
            inline operator unsigned int*() const { return 0u; }
            inline operator unsigned long*() const { return 0uL; }
            inline operator unsigned short*() const { return 0u; }
            inline operator void*() const { return 0; }
    } null {};
