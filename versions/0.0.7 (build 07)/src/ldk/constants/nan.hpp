/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Constant > Not-A-Number */
    const struct {
        // [...]
        public:
            // [Operator]
                // [==]
                inline boolean operator ==(const double number) const { return number__is_nan(number); }
                inline boolean operator ==(const float number) const { return number__is_nan(number); }
                inline boolean operator ==(const int number) const { return number__is_nan(number); }
                inline boolean operator ==(const long number) const { return number__is_nan(number); }
                inline boolean operator ==(const long double number) const { return number__is_nan(number); }
                inline boolean operator ==(const long long number) const { return number__is_nan(number); }
                inline boolean operator ==(const short number) const { return number__is_nan(number); }
                inline boolean operator ==(const unsigned int number) const { return number__is_nan(number); }
                inline boolean operator ==(const unsigned long number) const { return number__is_nan(number); }
                inline boolean operator ==(const unsigned long long number) const { return number__is_nan(number); }
                inline boolean operator ==(const unsigned short number) const { return number__is_nan(number); }

                // [!=]
                inline boolean operator !=(const double number) const { return !number__is_nan(number); }
                inline boolean operator !=(const float number) const { return !number__is_nan(number); }
                inline boolean operator !=(const int number) const { return !number__is_nan(number); }
                inline boolean operator !=(const long number) const { return !number__is_nan(number); }
                inline boolean operator !=(const long double number) const { return !number__is_nan(number); }
                inline boolean operator !=(const long long number) const { return !number__is_nan(number); }
                inline boolean operator !=(const short number) const { return !number__is_nan(number); }
                inline boolean operator !=(const unsigned int number) const { return !number__is_nan(number); }
                inline boolean operator !=(const unsigned long number) const { return !number__is_nan(number); }
                inline boolean operator !=(const unsigned long long number) const { return !number__is_nan(number); }
                inline boolean operator !=(const unsigned short number) const { return !number__is_nan(number); }

                // [...]
                inline operator double() const { return std::nan(""); }
                inline operator float() const { return std::nanf(""); }
                inline operator long double() const { return std::nanl(""); }
    } NaN;
#endif
