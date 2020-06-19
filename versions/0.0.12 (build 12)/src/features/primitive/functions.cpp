/* Function > ... --- REDACT (Lapys) */
    // [Number]
    constexpr inline double number__absolute(double const number) noexcept { return ::fabs(number); }
    constexpr inline float number__absolute(float const number) noexcept {
        #if cpp__version >= 2011uL
            return ::fabsf(number);
        #else
            return ::fabs(number);
        #endif
    }
    constexpr inline int number__absolute(int const number) noexcept { return ::abs(number); }
    inline long number__absolute(long const number) noexcept {
        #if cpp__version >= 1997uL
            return ::abs(number);
        #else
            return number < 0L ? -number : number;
        #endif
    }
    constexpr inline long double number__absolute(long double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::fabsl(number);
        #else
            return ::fabs(number);
        #endif
    }
    constexpr inline short number__absolute(short const number) noexcept { return number < 0 ? -number : number; }
    constexpr inline unsigned int number__absolute(unsigned int const number) noexcept { return number; }
    constexpr inline unsigned long number__absolute(unsigned long const number) noexcept { return number; }
    constexpr inline unsigned short number__absolute(unsigned short const number) noexcept { return number; }

    constexpr inline double number__arc_cosine(double const number) { return ::acos(number); }
    constexpr inline float number__arc_cosine(float const number) {
        #if c__version >= 1990uL
            return ::acosf(number);
        #elif c__version
            return number__arc_cosine((double) number);
        #else
            return ::acos(number);
        #endif
    }
    constexpr inline float number__arc_cosine(int const number) {
        #if cpp__version >= 2011uL
            return ::acos(number);
        #else
            return number__arc_cosine((float) number);
        #endif
    }
    constexpr inline double number__arc_cosine(long const number) {
        #if cpp__version >= 2011uL
            return ::acos(number);
        #else
            return number__arc_cosine((double) number);
        #endif
    }
    constexpr inline long double number__arc_cosine(long double const number) {
        #if c__version <= 1999uL
            return ::acosl(number);
        #elif c__version
            if (number > DBL_MAX) return number__arc_cosine(number - DBL_MAX);
            else return number__arc_cosine((double) number);
        #else
            return ::acos(number);
        #endif
    }
    constexpr inline float number__arc_cosine(short const number) {
        #if cpp__version >= 2011uL
            return ::acos(number);
        #else
            return number__arc_cosine((float) number);
        #endif
    }
    constexpr inline float number__arc_cosine(unsigned int const number) {
        #if cpp__version >= 2011uL
            return ::acos(number);
        #else
            return number__arc_cosine((float) number);
        #endif
    }
    constexpr inline double number__arc_cosine(unsigned long const number) {
        #if cpp__version >= 2011uL
            return ::acos(number);
        #else
            return number__arc_cosine((double) number);
        #endif
    }
    constexpr inline float number__arc_cosine(unsigned short const number) {
        #if cpp__version >= 2011uL
            return ::acos(number);
        #else
            return number__arc_cosine((float) number);
        #endif
    }

    constexpr inline double number__arc_sine(double const number) { return ::asin(number); }
    constexpr inline float number__arc_sine(float const number) {
        #if c__version >= 1990uL
            return ::asinf(number);
        #elif c__version
            return number__arc_sine((double) number);
        #else
            return ::asin(number);
        #endif
    }
    constexpr inline float number__arc_sine(int const number) {
        #if cpp__version >= 2011uL
            return ::asin(number);
        #else
            return number__arc_sine((float) number);
        #endif
    }
    constexpr inline double number__arc_sine(long const number) {
        #if cpp__version >= 2011uL
            return ::asin(number);
        #else
            return number__arc_sine((double) number);
        #endif
    }
    constexpr inline long double number__arc_sine(long double const number) {
        #if c__version <= 1999uL
            return ::asinl(number);
        #elif c__version
            if (number > DBL_MAX) return number__arc_sine(number - DBL_MAX);
            else return number__arc_sine((double) number);
        #else
            return ::asin(number);
        #endif
    }
    constexpr inline float number__arc_sine(short const number) {
        #if cpp__version >= 2011uL
            return ::asin(number);
        #else
            return number__arc_sine((float) number);
        #endif
    }
    constexpr inline float number__arc_sine(unsigned int const number) {
        #if cpp__version >= 2011uL
            return ::asin(number);
        #else
            return number__arc_sine((float) number);
        #endif
    }
    constexpr inline double number__arc_sine(unsigned long const number) {
        #if cpp__version >= 2011uL
            return ::asin(number);
        #else
            return number__arc_sine((double) number);
        #endif
    }
    constexpr inline float number__arc_sine(unsigned short const number) {
        #if cpp__version >= 2011uL
            return ::asin(number);
        #else
            return number__arc_sine((float) number);
        #endif
    }

    constexpr inline double number__arc_tangent(double const number) { return ::atan(number); }
    constexpr inline float number__arc_tangent(float const number) {
        #if c__version >= 1990uL
            return ::atanf(number);
        #elif c__version
            return number__arc_tangent((double) number);
        #else
            return ::atan(number);
        #endif
    }
    constexpr inline float number__arc_tangent(int const number) {
        #if cpp__version >= 2011uL
            return ::atan(number);
        #else
            return number__arc_tangent((float) number);
        #endif
    }
    constexpr inline double number__arc_tangent(long const number) {
        #if cpp__version >= 2011uL
            return ::atan(number);
        #else
            return number__arc_tangent((double) number);
        #endif
    }
    constexpr inline long double number__arc_tangent(long double const number) {
        #if c__version <= 1999uL
            return ::atanl(number);
        #elif c__version
            if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
            else return number__arc_tangent((double) number);
        #else
            return ::atan(number);
        #endif
    }
    constexpr inline float number__arc_tangent(short const number) {
        #if cpp__version >= 2011uL
            return ::atan(number);
        #else
            return number__arc_tangent((float) number);
        #endif
    }
    constexpr inline float number__arc_tangent(unsigned int const number) {
        #if cpp__version >= 2011uL
            return ::atan(number);
        #else
            return number__arc_tangent((float) number);
        #endif
    }
    constexpr inline double number__arc_tangent(unsigned long const number) {
        #if cpp__version >= 2011uL
            return ::atan(number);
        #else
            return number__arc_tangent((double) number);
        #endif
    }
    constexpr inline float number__arc_tangent(unsigned short const number) {
        #if cpp__version >= 2011uL
            return ::atan(number);
        #else
            return number__arc_tangent((float) number);
        #endif
    }

    constexpr inline double number__area_hyperbolic_cosine(double const number) {
        #if c__version <= 1999uL
            return ::acosh(number);
        #elif cpp__version >= 2011uL
            return ::acosh(number);
        #endif
        return NAN;
    }
    constexpr inline float number__area_hyperbolic_cosine(float const number) {
        #if c__version <= 1999uL
            return ::acosf(number);
        #elif cpp__version >= 2011uL
            return ::acosh(number);
        #endif
        return NANF;
    }
    constexpr inline float number__area_hyperbolic_cosine(int const number) {
        #if cpp__version >= 2011uL
            return ::acosh(number);
        #else
            return number__area_hyperbolic_cosine((float) number);
        #endif
    }
    constexpr inline double number__area_hyperbolic_cosine(long const number) {
        #if cpp__version >= 2011uL
            return ::acosh(number);
        #else
            return number__area_hyperbolic_cosine((double) number);
        #endif
    }
    constexpr inline long double number__area_hyperbolic_cosine(long double const number) {
        #if c__version <= 1999uL
            return ::acosl(number);
        #elif cpp__version >= 2011uL
            return ::acosh(number);
        #endif
        return NANL;
    }
    constexpr inline float number__area_hyperbolic_cosine(short const number) {
        #if cpp__version >= 2011uL
            return ::acosh(number);
        #else
            return number__area_hyperbolic_cosine((float) number);
        #endif
    }
    constexpr inline float number__area_hyperbolic_cosine(unsigned int const number) {
        #if cpp__version >= 2011uL
            return ::acosh(number);
        #else
            return number__area_hyperbolic_cosine((float) number);
        #endif
    }
    constexpr inline double number__area_hyperbolic_cosine(unsigned long const number) {
        #if cpp__version >= 2011uL
            return ::acosh(number);
        #else
            return number__area_hyperbolic_cosine((double) number);
        #endif
    }
    constexpr inline float number__area_hyperbolic_cosine(unsigned short const number) {
        #if cpp__version >= 2011uL
            return ::acosh(number);
        #else
            return number__area_hyperbolic_cosine((float) number);
        #endif
    }

    constexpr inline double number__area_hyperbolic_sine(double const number) {
        #if c__version <= 1999uL
            return ::asinh(number);
        #elif cpp__version >= 2011uL
            return ::asinh(number);
        #endif
        return NAN;
    }
    constexpr inline float number__area_hyperbolic_sine(float const number) {
        #if c__version <= 1999uL
            return ::asinhf(number);
        #elif cpp__version >= 2011uL
            return ::asinh(number);
        #endif
        return NANF;
    }
    constexpr inline float number__area_hyperbolic_sine(int const number) {
        #if cpp__version >= 2011uL
            return ::asinh(number);
        #else
            return number__area_hyperbolic_sine((float) number);
        #endif
    }
    constexpr inline double number__area_hyperbolic_sine(long const number) {
        #if cpp__version >= 2011uL
            return ::asinh(number);
        #else
            return number__area_hyperbolic_sine((double) number);
        #endif
    }
    constexpr inline long double number__area_hyperbolic_sine(long double const number) {
        #if c__version <= 1999uL
            return ::asinhl(number);
        #elif cpp__version >= 2011uL
            return ::asinh(number);
        #endif
        return NANL;
    }
    constexpr inline float number__area_hyperbolic_sine(short const number) {
        #if cpp__version >= 2011uL
            return ::asinh(number);
        #else
            return number__area_hyperbolic_sine((float) number);
        #endif
    }
    constexpr inline float number__area_hyperbolic_sine(unsigned int const number) {
        #if cpp__version >= 2011uL
            return ::asinh(number);
        #else
            return number__area_hyperbolic_sine((float) number);
        #endif
    }
    constexpr inline double number__area_hyperbolic_sine(unsigned long const number) {
        #if cpp__version >= 2011uL
            return ::asinh(number);
        #else
            return number__area_hyperbolic_sine((double) number);
        #endif
    }
    constexpr inline float number__area_hyperbolic_sine(unsigned short const number) {
        #if cpp__version >= 2011uL
            return ::asinh(number);
        #else
            return number__area_hyperbolic_sine((float) number);
        #endif
    }

    constexpr inline double number__area_hyperbolic_tangent(double const number) {
        #if c__version <= 1999uL
            return ::atanh(number);
        #elif cpp__version >= 2011uL
            return ::atanh(number);
        #endif
        return NAN;
    }
    constexpr inline float number__area_hyperbolic_tangent(float const number) {
        #if c__version <= 1999uL
            return ::atanhf(number);
        #elif cpp__version >= 2011uL
            return ::atanh(number);
        #endif
        return NANF;
    }
    constexpr inline float number__area_hyperbolic_tangent(int const number) {
        #if cpp__version >= 2011uL
            return ::atanh(number);
        #else
            return number__area_hyperbolic_tangent((float) number);
        #endif
    }
    constexpr inline double number__area_hyperbolic_tangent(long const number) {
        #if cpp__version >= 2011uL
            return ::atanh(number);
        #else
            return number__area_hyperbolic_tangent((double) number);
        #endif
    }
    constexpr inline long double number__area_hyperbolic_tangent(long double const number) {
        #if c__version <= 1999uL
            return ::atanhl(number);
        #elif cpp__version >= 2011uL
            return ::atanh(number);
        #endif
        return NANL;
    }
    constexpr inline float number__area_hyperbolic_tangent(short const number) {
        #if cpp__version >= 2011uL
            return ::atanh(number);
        #else
            return number__area_hyperbolic_tangent((float) number);
        #endif
    }
    constexpr inline float number__area_hyperbolic_tangent(unsigned int const number) {
        #if cpp__version >= 2011uL
            return ::atanh(number);
        #else
            return number__area_hyperbolic_tangent((float) number);
        #endif
    }
    constexpr inline double number__area_hyperbolic_tangent(unsigned long const number) {
        #if cpp__version >= 2011uL
            return ::atanh(number);
        #else
            return number__area_hyperbolic_tangent((double) number);
        #endif
    }
    constexpr inline float number__area_hyperbolic_tangent(unsigned short const number) {
        #if cpp__version >= 2011uL
            return ::atanh(number);
        #else
            return number__area_hyperbolic_tangent((float) number);
        #endif
    }

    constexpr inline double number__ceiling(double const number) noexcept { return ::ceil(number); }
    constexpr inline float number__ceiling(float const number) noexcept {
        #if c__version >= 1990uL
            return ::ceilf(number);
        #elif cpp__version >= 1997uL
            return ::ceil(number);
        #else
            float const integer = number__truncate(number);
            return number - integer ? integer + (number > 0.0f) : number;
        #endif
    }
    constexpr inline int number__ceiling(int const number) noexcept {
        #if cpp__version >= 2011uL
            return ::ceil(number);
        #else
            return number;
        #endif
    }
    constexpr inline long number__ceiling(long const number) noexcept {
        #if cpp__version >= 2011uL
            return ::ceil(number);
        #else
            return number;
        #endif
    }
    constexpr inline long double number__ceiling(long double const number) noexcept {
        #if c__version >= 1990uL
            return ::ceill(number);
        #elif cpp__version >= 1997uL
            return ::ceil(number);
        #else
            long double const integer = number__truncate(number);
            return number - integer ? integer + (number > 0.0L) : number;
        #endif
    }
    constexpr inline short number__ceiling(short const number) noexcept {
        #if cpp__version >= 2011uL
            return ::ceil(number);
        #else
            return number;
        #endif
    }
    constexpr inline unsigned int number__ceiling(unsigned int const number) noexcept {
        #if cpp__version >= 2011uL
            return ::ceil(number);
        #else
            return number;
        #endif
    }
    constexpr inline unsigned long number__ceiling(unsigned long const number) noexcept {
        #if cpp__version >= 2011uL
            return ::ceil(number);
        #else
            return number;
        #endif
    }
    constexpr inline unsigned short number__ceiling(unsigned short const number) noexcept {
        #if cpp__version >= 2011uL
            return ::ceil(number);
        #else
            return number;
        #endif
    }

    inline double number__compute_indeterminate(void) noexcept { constexpr static unsigned long const evaluation[2] = {0x00000000, 0xFFF80000}; return *((double const*) evaluation); } // NOTE (Lapys) -> IEEE-754 hexadecimal form.
    constexpr inline float number__compute_infinity(void) noexcept { return INFINITY; }
    constexpr inline double number__compute_nan(void) noexcept { return NAN; }

    constexpr inline double number__cosine(double const number) { return ::cos(number); }
    constexpr inline float number__cosine(float const number) {
        #if c__version >= 1990uL
            return ::cosf(number);
        #elif cpp__version >= 1997uL
            return ::cos(number);
        #else
            return number__cosine((double) number);
        #endif
    }
    constexpr inline float number__cosine(int const number) {
        #if cpp__version >= 2011uL
            return ::cos(number);
        #else
            return number__cosine((float) number);
        #endif
    }
    constexpr inline double number__cosine(long const number) {
        #if cpp__version >= 2011uL
            return ::cos(number);
        #else
            return number__cosine((double) number);
        #endif
    }
    inline long double number__cosine(long double const number) {
        #if c__version >= 1990uL
            return ::cosl(number);
        #elif c__version
            if (number > DBL_MAX) return number__arc_tangent(number - DBL_MAX);
            else return number__arc_tangent((double) number);
        #elif cpp__version >= 1997uL
            return ::cos(number);
        #endif
    }
    constexpr inline float number__cosine(short const number) {
        #if cpp__version >= 2011uL
            return ::cos(number);
        #else
            return number__cosine((float) number);
        #endif
    }
    constexpr inline float number__cosine(unsigned int const number) {
        #if cpp__version >= 2011uL
            return ::cos(number);
        #else
            return number__cosine((float) number);
        #endif
    }
    constexpr inline double number__cosine(unsigned long const number) {
        #if cpp__version >= 2011uL
            return ::cos(number);
        #else
            return number__cosine((double) number);
        #endif
    }
    constexpr inline float number__cosine(unsigned short const number) {
        #if cpp__version >= 2011uL
            return ::cos(number);
        #else
            return number__cosine((float) number);
        #endif
    }

    constexpr inline double number__cube_root(double const number) noexcept {
        #if c__version >= 1990uL || cpp__version >= 1998uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.0 / 3.0);
        #endif
    }
    constexpr inline float number__cube_root(float const number) noexcept {
        #if c__version >= 1999uL
            return ::cbrtf(number);
        #elif cpp__version >= 1998uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.0f / 3.0f);
        #endif
    }
    constexpr inline int number__cube_root(int const number) noexcept {
        #if cpp__version >= 2011uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.0f / 3.0f);
        #endif
    }
    constexpr inline long number__cube_root(long const number) noexcept {
        #if cpp__version >= 2011uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.0 / 3.0);
        #endif
    }
    constexpr inline long double number__cube_root(long double const number) noexcept {
        #if c__version >= 1999uL
            return ::cbrtl(number);
        #elif cpp__version >= 1998uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.00L / 3.00L);
        #endif
    }
    constexpr inline short number__cube_root(short const number) noexcept {
        #if cpp__version >= 2011uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.0f / 3.0f);
        #endif
    }
    constexpr inline unsigned int number__cube_root(unsigned int const number) noexcept {
        #if cpp__version >= 2011uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.0f / 3.0f);
        #endif
    }
    constexpr inline unsigned long number__cube_root(unsigned long const number) noexcept {
        #if cpp__version >= 2011uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.0 / 3.0);
        #endif
    }
    constexpr inline unsigned short number__cube_root(unsigned short const number) noexcept {
        #if cpp__version >= 2011uL
            return ::cbrt(number);
        #else
            return number__exponentiate(number, 1.0f / 3.0f);
        #endif
    }

    void number__exponentiate(int, ...) noexcept; // CHECKPOINT (Lapys)

    constexpr inline double number__exponentiate_eulers_number(double const number) { return ::exp(number); }
    constexpr inline float number__exponentiate_eulers_number(float const number) {
        #if c__version >= 1990uL
            return ::expf(number);
        #elif cpp__version >= 1997uL
            return ::exp(number);
        #else
            return number__exponentiate_eulers_number((double) number);
        #endif
    }
    constexpr inline float number__exponentiate_eulers_number(int const number) {
        #if cpp__version >= 2011uL
            return ::exp(number);
        #else
            return number__exponentiate_eulers_number((float) number);
        #endif
    }
    inline long double number__exponentiate_eulers_number(long const number) {
        #if cpp__version >= 2011uL
            return ::exp(number);
        #else
            return number__exponentiate_eulers_number((long double) number);
        #endif
    }
    inline long double number__exponentiate_eulers_number(long double const number) {
        #if c__version >= 1990uL
            return ::expl(number);
        #elif cpp__version >= 1997uL
            return ::exp(number);
        #else
            if (number > DBL_MAX) return number__exponentiate_eulers_number(number - DBL_MAX);
            else return number__exponentiate_eulers_number((double) number);
        #endif
    }
    constexpr inline float number__exponentiate_eulers_number(short const number) {
        #if cpp__version >= 2011uL
            return ::exp(number);
        #else
            return number__exponentiate_eulers_number((float) number);
        #endif
    }
    constexpr inline float number__exponentiate_eulers_number(unsigned int const number) {
        #if cpp__version >= 2011uL
            return ::exp(number);
        #else
            return number__exponentiate_eulers_number((float) number);
        #endif
    }
    inline long double number__exponentiate_eulers_number(unsigned long const number) {
        #if cpp__version >= 2011uL
            return ::exp(number);
        #else
            return number__exponentiate_eulers_number((long double) number);
        #endif
    }
    constexpr inline float number__exponentiate_eulers_number(unsigned short const number) {
        #if cpp__version >= 2011uL
            return ::exp(number);
        #else
            return number__exponentiate_eulers_number((float) number);
        #endif
    }

    inline double number__floor(double const number) noexcept {
        #if c__version >= 1990uL
            return ::floorf(number);
        #elif cpp__version >= 1997uL
            return ::floor(number);
        #else
        #endif
    }
    inline float number__floor(float const number) noexcept {
        #if c__version >= 1990uL
            return ::floorf(number);
        #elif cpp__version >= 1997uL
            return ::floor(number);
        #else
        #endif
    }
    constexpr inline int number__floor(int const number) noexcept { return number; }
    constexpr inline long number__floor(long const number) noexcept { return number; }
    inline long double number__floor(long double const number) noexcept {
        #if c__version >= 1990uL
            return ::floorl(number);
        #elif cpp__version >= 1997uL
            return ::floor(number);
        #else
        #endif
    }
    constexpr inline short number__floor(short const number) noexcept { return number; }
    constexpr inline unsigned int number__floor(unsigned int const number) noexcept { return number; }
    constexpr inline unsigned long number__floor(unsigned long const number) noexcept { return number; }
    constexpr inline unsigned short number__floor(unsigned short const number) noexcept { return number; }

    inline bool number__is_approximate_zero(double const number, double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(double const number, float const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(double const number, int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(double const number, long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(double const number, long double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(double const number, short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(double const number, unsigned int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(double const number, unsigned long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(double const number, unsigned short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, float const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, long double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, unsigned int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, unsigned long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(float const number, unsigned short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    constexpr inline bool number__is_approximate_zero(int const number, double const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(int const number, float const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(int const number, int const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(int const number, long const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(int const number, long double const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(int const number, short const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(int const number, unsigned int const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(int const number, unsigned long const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(int const number, unsigned short const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(long const number, double const) noexcept { return 0L == number; }
    constexpr inline bool number__is_approximate_zero(long const number, float const) noexcept { return 0L == number; }
    constexpr inline bool number__is_approximate_zero(long const number, int const) noexcept { return 0L == number; }
    constexpr inline bool number__is_approximate_zero(long const number, long const) noexcept { return 0L == number; }
    constexpr inline bool number__is_approximate_zero(long const number, long double const) noexcept { return 0L == number; }
    constexpr inline bool number__is_approximate_zero(long const number, short const) noexcept { return 0L == number; }
    constexpr inline bool number__is_approximate_zero(long const number, unsigned int const) noexcept { return 0L == number; }
    constexpr inline bool number__is_approximate_zero(long const number, unsigned long const) noexcept { return 0L == number; }
    constexpr inline bool number__is_approximate_zero(long const number, unsigned short const) noexcept { return 0L == number; }
    inline bool number__is_approximate_zero(long double const number, double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(long double const number, float const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(long double const number, int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(long double const number, long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(long double const number, long double const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(long double const number, short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(long double const number, unsigned int const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(long double const number, unsigned long const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    inline bool number__is_approximate_zero(long double const number, unsigned short const tolerance) noexcept { return number__absolute(number) <= tolerance; }
    constexpr inline bool number__is_approximate_zero(short const number, double const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(short const number, float const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(short const number, int const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(short const number, long const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(short const number, long double const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(short const number, short const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(short const number, unsigned int const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(short const number, unsigned long const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(short const number, unsigned short const) noexcept { return 0 == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, double const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, float const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, int const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, long const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, long double const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, short const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, unsigned int const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, unsigned long const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned int const number, unsigned short const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, double const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, float const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, int const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, long const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, long double const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, short const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, unsigned int const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, unsigned long const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned long const number, unsigned short const) noexcept { return 0uL == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, double const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, float const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, int const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, long const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, long double const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, short const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, unsigned int const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, unsigned long const) noexcept { return 0u == number; }
    constexpr inline bool number__is_approximate_zero(unsigned short const number, unsigned short const) noexcept { return 0u == number; }

    constexpr inline bool number__is_computable(double const number) noexcept { return false == number__is_uncomputable(number); }
    constexpr inline bool number__is_computable(float const number) noexcept { return false == number__is_uncomputable(number); }
    constexpr inline bool number__is_computable(int const) noexcept { return true; }
    constexpr inline bool number__is_computable(long const) noexcept { return true; }
    constexpr inline bool number__is_computable(long double const number) noexcept { return false == number__is_uncomputable(number); }
    constexpr inline bool number__is_computable(short const) noexcept { return true; }
    constexpr inline bool number__is_computable(unsigned int const) noexcept { return true; }
    constexpr inline bool number__is_computable(unsigned long const) noexcept { return true; }
    constexpr inline bool number__is_computable(unsigned short const) noexcept { return true; }

    inline bool number__is_determinate(double const number) noexcept { return number == number && number != number__compute_indeterminate(); }
    inline bool number__is_determinate(float const number) noexcept { return number__is_determinate((double) number); }
    constexpr inline bool number__is_determinate(int const) noexcept { return true; }
    constexpr inline bool number__is_determinate(long const) noexcept { return true; }
    inline bool number__is_determinate(long double const number) noexcept { if (number > DBL_MAX) return number__is_determinate(number - DBL_MAX); else return number__is_determinate((double) number); }
    constexpr inline bool number__is_determinate(short const) noexcept { return true; }
    constexpr inline bool number__is_determinate(unsigned int const) noexcept { return true; }
    constexpr inline bool number__is_determinate(unsigned long const) noexcept { return true; }
    constexpr inline bool number__is_determinate(unsigned short const) noexcept { return true; }

    inline bool number__is_finite(double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isfinite(number);
        #else
            return isfinite(number);
        #endif
    }
    inline bool number__is_finite(float const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isfinite(number);
        #else
            return isfinite(number);
        #endif
    }
    constexpr inline bool number__is_finite(int const) noexcept { return true; }
    constexpr inline bool number__is_finite(long const) noexcept { return true; }
    inline bool number__is_finite(long double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isfinite(number);
        #else
            return isfinite(number);
        #endif
    }
    constexpr inline bool number__is_finite(short const) noexcept { return true; }
    constexpr inline bool number__is_finite(unsigned int const) noexcept { return true; }
    constexpr inline bool number__is_finite(unsigned long const) noexcept { return true; }
    constexpr inline bool number__is_finite(unsigned short const) noexcept { return true; }

    constexpr inline bool number__is_infinite(double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isinf(number);
        #else
            return isinf(number);
        #endif
    }
    constexpr inline bool number__is_infinite(float const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isinf(number);
        #else
            return isinf(number);
        #endif
    }
    constexpr inline bool number__is_infinite(int const) noexcept { return false; }
    constexpr inline bool number__is_infinite(long const) noexcept { return false; }
    constexpr inline bool number__is_infinite(long double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isinf(number);
        #else
            return isinf(number);
        #endif
    }
    constexpr inline bool number__is_infinite(short const) noexcept { return false; }
    constexpr inline bool number__is_infinite(unsigned int const) noexcept { return false; }
    constexpr inline bool number__is_infinite(unsigned long const) noexcept { return false; }
    constexpr inline bool number__is_infinite(unsigned short const) noexcept { return false; }

    inline bool number__is_normalized(double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isnormal(number);
        #else
            return isnormal(number);
        #endif
    }
    inline bool number__is_normalized(float const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isnormal(number);
        #else
            return isnormal(number);
        #endif
    }
    constexpr inline bool number__is_normalized(int const) noexcept { return true; }
    constexpr inline bool number__is_normalized(long const) noexcept { return true; }
    inline bool number__is_normalized(long double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isnormal(number);
        #else
            return isnormal(number);
        #endif
    }
    constexpr inline bool number__is_normalized(short const) noexcept { return true; }
    constexpr inline bool number__is_normalized(unsigned int const) noexcept { return true; }
    constexpr inline bool number__is_normalized(unsigned long const) noexcept { return true; }
    constexpr inline bool number__is_normalized(unsigned short const) noexcept { return true; }

    inline bool number__is_safe(double const number) noexcept { return number__is_computable(number) && number__is_determinate(number) && number__is_finite(number) && number__is_normalized(number); }
    inline bool number__is_safe(float const number) noexcept { return number__is_computable(number) && number__is_determinate(number) && number__is_finite(number) && number__is_normalized(number); }
    constexpr inline bool number__is_safe(int const number) noexcept { return INT_MAX ^ number; }
    constexpr inline bool number__is_safe(long const number) noexcept { return LONG_MAX ^ number; }
    inline bool number__is_safe(long double const number) noexcept { return number__is_computable(number) && number__is_determinate(number) && number__is_finite(number) && number__is_normalized(number); }
    constexpr inline bool number__is_safe(short const number) noexcept { return SHRT_MAX ^ number; }
    constexpr inline bool number__is_safe(unsigned int const number) noexcept { return UINT_MAX ^ number; }
    constexpr inline bool number__is_safe(unsigned long const number) noexcept { return ULONG_MAX ^ number; }
    constexpr inline bool number__is_safe(unsigned short const) noexcept { return true; } // FLAG (Lapys) -> This is safe, right? Yeah, let`s ignore `USHRT_MAX`...

    constexpr inline bool number__is_uncomputable(double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isnan(number);
        #else
            return isnan(number);
        #endif
    }
    constexpr inline bool number__is_uncomputable(float const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isnan(number);
        #else
            return isnan(number);
        #endif
    }
    constexpr inline bool number__is_uncomputable(int const) noexcept { return false; }
    constexpr inline bool number__is_uncomputable(long const) noexcept { return false; }
    constexpr inline bool number__is_uncomputable(long double const number) noexcept {
        #if cpp__version >= 2011uL
            return ::isnan(number);
        #else
            return isnan(number);
        #endif
    }
    constexpr inline bool number__is_uncomputable(short const) noexcept { return false; }
    constexpr inline bool number__is_uncomputable(unsigned int const) noexcept { return false; }
    constexpr inline bool number__is_uncomputable(unsigned long const) noexcept { return false; }
    constexpr inline bool number__is_uncomputable(unsigned short const) noexcept { return false; }

    template <unsigned char base> inline double number__logarithm(double const number) noexcept { return number__logarithm<base>((long double) number); }
    template <unsigned char base>
    constexpr inline long double number__logarithm(long double const number) {
        #if c__version <= 1999uL
            return ::logl(number);
        #elif cpp__version >= 1997uL
            return ::log(number);
        #endif
    }
    void number__maximum(int, ...) noexcept; // CHECKPOINT (Lapys)
    void number__minimum(int, ...) noexcept; // CHECKPOINT (Lapys)
    void number__modulo(int, ...) noexcept; // CHECKPOINT (Lapys)
    void number__modulo_fraction(...) noexcept;
    void number__random(...) noexcept;
    void number__root(int, ...) noexcept;
    void number__sine(...) noexcept;
    void number__square_root(...) noexcept;
    void number__tangent(...) noexcept;
    void number__to_string(...) noexcept;
    void number__truncate(...) noexcept;

    // [Pointer]
    void pointer__allocate_heap_memory(...) noexcept;
    void pointer__allocate_stack_memory(...) noexcept;
    void pointer__free_heap_memory(...) noexcept;
    void pointer__free_stack_memory(...) noexcept;
    void pointer__map_heap_memory(...) noexcept;
    void pointer__reallocate_heap_memory(...) noexcept;
    void pointer__reallocate_stack_memory(...) noexcept;
    void pointer__source_copy_memory(...) noexcept;
    void pointer__source_move_memory(...) noexcept;
    void pointer__unmap_heap_memory(...) noexcept;
    void pointer__zero_memory(...) noexcept;

    // [String]
    void string__end(...) noexcept;
    void string__is_empty(...) noexcept;
    void string__length(...) noexcept;
    void string__start(...) noexcept;
