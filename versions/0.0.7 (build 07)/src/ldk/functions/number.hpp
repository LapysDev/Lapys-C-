/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Function > Number ... */
        // Is Infinite
        inline boolean number__is_infinite(const double number) { return std::isinf(number); }
        inline boolean number__is_infinite(const float number) { return std::isinf(number); }
        inline boolean number__is_infinite(const int) { return false; }
        inline boolean number__is_infinite(const long) { return false; }
        inline boolean number__is_infinite(const long double number) { return std::isinf(number); }
        inline boolean number__is_infinite(const long long) { return false; }
        inline boolean number__is_infinite(const short) { return false; }
        inline boolean number__is_infinite(const unsigned int) { return false; }
        inline boolean number__is_infinite(const unsigned long) { return false; }
        inline boolean number__is_infinite(const unsigned long long) { return false; }
        inline boolean number__is_infinite(const unsigned short) { return false; }

        // Is Finite
        inline boolean number__is_finite(const double number) { return !number__is_infinite(number); }
        inline boolean number__is_finite(const float number) { return !number__is_infinite(number); }
        inline boolean number__is_finite(const int) { return true; }
        inline boolean number__is_finite(const long) { return true; }
        inline boolean number__is_finite(const long double number) { return !number__is_infinite(number); }
        inline boolean number__is_finite(const long long) { return true; }
        inline boolean number__is_finite(const short) { return true; }
        inline boolean number__is_finite(const unsigned int) { return true; }
        inline boolean number__is_finite(const unsigned long) { return true; }
        inline boolean number__is_finite(const unsigned long long) { return true; }
        inline boolean number__is_finite(const unsigned short) { return true; }

        // Is Not-A-Number
        inline boolean number__is_nan(const double number) { return std::isnan(number); }
        inline boolean number__is_nan(const float number) { return std::isnan(number); }
        inline boolean number__is_nan(const int) { return false; }
        inline boolean number__is_nan(const long) { return false; }
        inline boolean number__is_nan(const long double number) { return std::isnan(number); }
        inline boolean number__is_nan(const long long) { return false; }
        inline boolean number__is_nan(const short) { return false; }
        inline boolean number__is_nan(const unsigned int) { return false; }
        inline boolean number__is_nan(const unsigned long) { return false; }
        inline boolean number__is_nan(const unsigned long long) { return false; }
        inline boolean number__is_nan(const unsigned short) { return false; }
#endif
