/* Constant */
    // Infinity
    const struct {
        // [...]
        public:
            // [Operator] > ...
            inline double operator +() const { return INFINITY; }
            inline double operator -() const { return -INFINITY; }

            inline operator double() const { return INFINITY; }
    } Infinity;

    // Not-a-Number
    const struct {
        // [...]
        public:
            // [Operator] > [...]
            inline operator double() const { return std::nan(""); }
            inline operator float() const { return std::nanf(""); }
            inline operator long double() const { return std::nanl(""); }
    } NaN;

    // PI
    const long double PI = M_PI;
