/* Namespace > Mathematics */
namespace Mathematics {
    /* Declarations > Mathematics */
    void cosine(...);
    void sine(...);
    void tangent(...);
    void arc_cosine(...);
    void arc_sine(...);
    void arc_tangent(...);
    void hyperbolic_cosine(...);
    void hyperbolic_sine(...);
    void hyperbolic_tangent(...);
    void area_hyperbolic_cosine(...);
    void area_hyperbolic_sine(...);
    void area_hyperbolic_tangent(...);
    void natural_exponentiate(...);
    void natural_logarithm(...);
    void denary_logarithm(...);
    void modulo(...);
    void binary_exponentiate(...);
    void binary_logarithm(...);
    void exponentiate(...);
    void root(...);
    void square_root(...);
    void cube_root(...);
    void hypotenuse(...);
    void round_down(...);
    void round_near(...);
    void round_up(...);
    void modulo(...);
    void truncate(...);
    void round_integral(...);
    void next_representable(...);
    void maximum(...);
    void difference(...);
    void minimum(...);
    void absolute(...);
} namespace Math = Mathematics;

/* Modification > Mathematics
        --- CHECKPOINT (Lapys) -> Cross-check versions, Check for exceptions; not only in custom implementations. Co-tangents?
        --- WARN (Lapys) -> Does not explicitly cast between decimal and integer types, defer to the `recompose(x)` & `truncate(x)` or `characteristics_of(x)` & `mantissa_of(x)` utilities.
*/
// : [Exponent & Logarithm]
    // Binary Exponentiate -> 2 ** x
    constexpr inline double binary_exponentiate(double const exponent) noexcept { return ::exp2(exponent); }
    constexpr inline double binary_exponentiate(int const exponent) noexcept { return Mathematics::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(short const exponent) noexcept { return Mathematics::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(signed char const exponent) noexcept { return Mathematics::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(unsigned char const exponent) noexcept { return Mathematics::binary_exponentiate((unsigned long) exponent); }
    constexpr inline double binary_exponentiate(unsigned int const exponent) noexcept { return Mathematics::binary_exponentiate((unsigned long) exponent); }
    constexpr inline double binary_exponentiate(unsigned short const exponent) noexcept { return Mathematics::binary_exponentiate((unsigned long) exponent); }

    #if c__version >= 1990uL
        constexpr inline float binary_exponentiate(float const exponent) noexcept { return ::exp2f(exponent); }
        constexpr inline long double binary_exponentiate(long double const exponent) noexcept { return ::exp2l(exponent); }
    #elif cpp__version >= 2011uL
        constexpr inline float binary_exponentiate(float const exponent) noexcept { return ::exp2(exponent); }
        constexpr inline long double binary_exponentiate(long double const exponent) noexcept { return ::exp2(exponent); }
    #else
        constexpr inline double binary_exponentiate(double const exponent) noexcept { return Mathematics::exponentiate(2.0, exponent); }
        constexpr inline float binary_exponentiate(float const exponent) noexcept { return Mathematics::exponentiate(2.0f, exponent); }
        constexpr inline long double binary_exponentiate(long double const exponent) noexcept { return Mathematics::exponentiate(2.0L, exponent); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double binary_exponentiate(long const exponent) noexcept { return ::exp2(exponent); }
        constexpr inline double binary_exponentiate(unsigned long const exponent) noexcept { return ::exp2(exponent); }
    #else
        constexpr inline double binary_exponentiate(long const exponent) noexcept { return Mathematics::exponentiate(2L, exponent); }
        constexpr inline double binary_exponentiate(long const exponent) noexcept { return Mathematics::exponentiate(2uL, exponent); }
    #endif

    // Binary Logarithm -> log2(x)
    constexpr inline double binary_logarithm(int const number) noexcept { return Mathematics::binary_logarithm((long) number); }
    constexpr inline double binary_logarithm(short const number) noexcept { return Mathematics::binary_logarithm((long) number); }
    constexpr inline double binary_logarithm(signed char const number) noexcept { return Mathematics::binary_logarithm((long) number); }
    constexpr inline double binary_logarithm(unsigned char const number) noexcept { return Mathematics::binary_logarithm((unsigned long) number); }
    constexpr inline double binary_logarithm(unsigned int const number) noexcept { return Mathematics::binary_logarithm((unsigned long) number); }
    constexpr inline double binary_logarithm(unsigned short const number) noexcept { return Mathematics::binary_logarithm((unsigned long) number); }

    #if c__version >= 1990uL
        constexpr inline double binary_logarithm(double const number) noexcept { return ::log2(number); }
        constexpr inline float binary_logarithm(float const number) noexcept { return ::log2f(number); }
        constexpr inline long double binary_logarithm(long double const number) noexcept { return ::log2l(number); }
    #elif cpp__version >= 2011uL
        constexpr inline double binary_logarithm(double const number) noexcept { return ::log2(number); }
        constexpr inline float binary_logarithm(float const number) noexcept { return ::log2(number); }
        constexpr inline long double binary_logarithm(long double const number) noexcept { return ::log2(number); }
    #else
        constexpr inline double binary_logarithm(double const number) noexcept { return Mathematics::LOG2E * Mathematics::natural_logarithm(number); }
        constexpr inline float binary_logarithm(float const number) noexcept { return Mathematics::LOG2E * Mathematics::natural_logarithm(number); }
        constexpr inline long double binary_logarithm(long double const number) noexcept { return Mathematics::LOG2E * Mathematics::natural_logarithm(number); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double binary_logarithm(long const number) noexcept { return ::log2(number); }
        constexpr inline double binary_logarithm(unsigned long const number) noexcept { return ::log2(number); }
    #else
        constexpr inline double binary_logarithm(long const number) noexcept { return Mathematics::LOG2E * Mathematics::natural_logarithm(number); }
        constexpr inline double binary_logarithm(unsigned long const number) noexcept { return Mathematics::LOG2E * Mathematics::natural_logarithm(number); }
    #endif

    // Denary Logarithm -> log10(x)
    constexpr inline double denary_logarithm(int const number) noexcept { return Mathematics::denary_logarithm((long) number); }
    constexpr inline double denary_logarithm(short const number) noexcept { return Mathematics::denary_logarithm((long) number); }
    constexpr inline double denary_logarithm(signed char const number) noexcept { return Mathematics::denary_logarithm((long) number); }
    constexpr inline double denary_logarithm(unsigned char const number) noexcept { return Mathematics::denary_logarithm((unsigned long) number); }
    constexpr inline double denary_logarithm(unsigned int const number) noexcept { return Mathematics::denary_logarithm((unsigned long) number); }
    constexpr inline double denary_logarithm(unsigned short const number) noexcept { return Mathematics::denary_logarithm((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1997uL
        constexpr inline double denary_logarithm(double const number) noexcept { return ::log10(number); }
    #else
        constexpr inline double denary_logarithm(double const number) noexcept { return Mathematics::LOG10E * Mathematics::natural_logarithm(number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float denary_logarithm(float const number) noexcept { return ::log10f(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return ::log10l(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float denary_logarithm(float const number) noexcept { return ::log10(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return ::log10(number); }
    #else
        constexpr inline float denary_logarithm(float const number) noexcept { return Mathematics::LOG10E * Mathematics::natural_logarithm(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return Mathematics::LOG10E * Mathematics::natural_logarithm(number); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline long denary_logarithm(long const number) noexcept { return ::log10(number); }
        constexpr inline unsigned long denary_logarithm(unsigned long const number) noexcept { return ::log10(number); }
    #else
        constexpr inline double denary_logarithm(long const number) noexcept { return Mathematics::LOG10E * Mathematics::natural_logarithm(number); }
        constexpr inline double denary_logarithm(unsigned long const number) noexcept { return Mathematics::LOG10E * Mathematics::natural_logarithm(number); }
    #endif

    // Natural Exponentiate -> E ** x
    constexpr inline double natural_exponentiate(int const number) noexcept { return Mathematics::natural_exponentiate((long) number); }
    constexpr inline double natural_exponentiate(short const number) noexcept { return Mathematics::natural_exponentiate((long) number); }
    constexpr inline double natural_exponentiate(signed char const number) noexcept { return Mathematics::natural_exponentiate((long) number); }
    constexpr inline double natural_exponentiate(unsigned char const number) noexcept { return Mathematics::natural_exponentiate((unsigned long) number); }
    constexpr inline double natural_exponentiate(unsigned int const number) noexcept { return Mathematics::natural_exponentiate((unsigned long) number); }
    constexpr inline double natural_exponentiate(unsigned short const number) noexcept { return Mathematics::natural_exponentiate((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1997uL
        constexpr inline double natural_exponentiate(double const number) noexcept { return ::exp(number); }
    #else
        constexpr inline double natural_exponentiate(double const number) noexcept { return Mathematics::exponentiate((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float natural_exponentiate(float const number) noexcept { return ::expf(number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept { return ::expl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float natural_exponentiate(float const number) noexcept { return ::exp(number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept { return ::exp(number); }
    #else
        constexpr inline float natural_exponentiate(float const number) noexcept { return Mathematics::exponentiate((long double) number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept {
            size_t const count = Mathematics::exponentiate(100uL, Mathematics::characteristics_length(number));
            long double evaluation = 0.0L;

            for (unsigned char iterator = 0u; count ^ iterator; ++iterator)
            evaluation += Mathematics::exponentiate(Mathematics::recompose(number), iterator) / Mathematics::factorial(iterator);

            return evaluation;
        }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double natural_exponentiate(long const number) noexcept { return ::exp(number); }
        constexpr inline double natural_exponentiate(unsigned long const number) noexcept { return ::exp(number); }
    #else
        constexpr inline double natural_exponentiate(long const number) noexcept { return Mathematics::exponentiate(Mathematics::recompose(number)); }
        constexpr inline double natural_exponentiate(unsigned long const number) noexcept { return Mathematics::exponentiate(Mathematics::recompose(number)); }
    #endif

    // Natural Logarithm -> ln(x)
    constexpr inline double natural_logarithm(int const number) noexcept { return Mathematics::natural_logarithm((long) number); }
    constexpr inline double natural_logarithm(short const number) noexcept { return Mathematics::natural_logarithm((long) number); }
    constexpr inline double natural_logarithm(signed char const number) noexcept { return Mathematics::natural_logarithm((long) number); }
    constexpr inline double natural_logarithm(unsigned char const number) noexcept { return Mathematics::natural_logarithm((unsigned long) number); }
    constexpr inline double natural_logarithm(unsigned int const number) noexcept { return Mathematics::natural_logarithm((unsigned long) number); }
    constexpr inline double natural_logarithm(unsigned short const number) noexcept { return Mathematics::natural_logarithm((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1997uL
        constexpr inline double natural_logarithm(double const number) noexcept { return ::log(number); }
    #else
        constexpr inline double natural_logarithm(double const number) noexcept { return (double) Mathematics::natural_logarithm((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float natural_logarithm(float const number) noexcept { return ::logf(number); }
        constexpr inline long double natural_logarithm(long double const number) noexcept { return ::logl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float natural_logarithm(float const number) noexcept { return ::log(number); }
        constexpr inline long double natural_logarithm(long double const number) noexcept { return ::log(number); }
    #else
        constexpr inline float natural_logarithm(float const number) noexcept { return Mathematics::natural_logarithm((long double) number); }
        constexpr inline long double natural_logarithm(long double const number) noexcept {
            // Logic > ... --- ERROR (Lapys) ->
            if (number < +0.0L) { // Domain error.
                #if includes__floating_point_environment_library
                    if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_INVALID);
                    if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM);
                #endif
                return NaN;
            }

            else if (0.0L == number) { // Pole error.
                #if includes__floating_point_environment_library
                    if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_DIVBYZERO);
                    if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(ERANGE);
                #endif
                return -Infinity;
            }

            else if (Infinity.is(number)) return Infinity;
            else if (NaN.is(number)) return NaN;

            // Initialization > (Count, Evaluation)
            size_t const count = Mathematics::exponentiate(100uL, Mathematics::characteristics_length(number));
            long double evaluation = 0.0L;

            // Loop > Update > Evaluation
            for (unsigned char iterator = 0u; count ^ iterator; ++iterator)
            evaluation += (
                (1.0L / ((iterator * 2.0L) + 1.0L)) *
                Mathematics::exponentiate((number - 1.0L) / (number + 1.0L), (iterator * 2u) + 1u)
            );

            // Return
            return evaluation * 2.0L;
        }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double natural_logarithm(long const number) noexcept { return ::log(number); }
        constexpr inline double natural_logarithm(unsigned long const number) noexcept { return ::log(number); }
    #else
        constexpr inline double natural_logarithm(long const number) noexcept { return (double) Mathematics::natural_logarithm((long double) number); }
        constexpr inline double natural_logarithm(unsigned long const number) noexcept { return (double) Mathematics::natural_logarithm((long double) number); }
    #endif

// : [Hyperbole]
    // Area Hyperbolic Cosine -> cosh-1(x)
    constexpr inline double area_hyperbolic_cosine(int const number) noexcept { return Mathematics::area_hyperbolic_cosine((long) number); }
    constexpr inline double area_hyperbolic_cosine(short const number) noexcept { return Mathematics::area_hyperbolic_cosine((long) number); }
    constexpr inline double area_hyperbolic_cosine(signed char const number) noexcept { return Mathematics::area_hyperbolic_cosine((long) number); }
    constexpr inline double area_hyperbolic_cosine(unsigned char const number) noexcept { return Mathematics::area_hyperbolic_cosine((unsigned long) number); }
    constexpr inline double area_hyperbolic_cosine(unsigned int const number) noexcept { return Mathematics::area_hyperbolic_cosine((unsigned long) number); }
    constexpr inline double area_hyperbolic_cosine(unsigned short const number) noexcept { return Mathematics::area_hyperbolic_cosine((unsigned long) number); }

    #if c__version >= 1999uL
        constexpr inline double area_hyperbolic_cosine(double const number) noexcept { return ::acosh(number); }
        constexpr inline float area_hyperbolic_cosine(float const number) noexcept { return ::acoshf(number); }
        constexpr inline long double area_hyperbolic_cosine(long double const number) noexcept { return ::acoshl(number); }
    #elif cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_cosine(double const number) noexcept { return ::acosh(number); }
        constexpr inline float area_hyperbolic_cosine(float const number) noexcept { return ::acosh(number); }
        constexpr inline long double area_hyperbolic_cosine(long double const number) noexcept { return ::acosh(number); }
    #else
        constexpr inline double area_hyperbolic_cosine(double const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) - 1.0)); }
        constexpr inline float area_hyperbolic_cosine(float const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) - 1.0f)); }
        constexpr inline long double area_hyperbolic_cosine(long double const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) - 1.0L)); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_cosine(long const number) noexcept { return ::acosh(number); }
        constexpr inline double area_hyperbolic_cosine(unsigned long const number) noexcept { return ::acosh(number); }
    #else
        constexpr inline double area_hyperbolic_cosine(long const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) - 1L)); }
        constexpr inline double area_hyperbolic_cosine(unsigned long const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) - 1uL)); }
    #endif

    // Area Hyperbolic Sine -> sinh-1(x)
    constexpr inline double area_hyperbolic_sine(int const number) noexcept { return Mathematics::area_hyperbolic_sine((long) number); }
    constexpr inline double area_hyperbolic_sine(short const number) noexcept { return Mathematics::area_hyperbolic_sine((long) number); }
    constexpr inline double area_hyperbolic_sine(signed char const number) noexcept { return Mathematics::area_hyperbolic_sine((long) number); }
    constexpr inline double area_hyperbolic_sine(unsigned char const number) noexcept { return Mathematics::area_hyperbolic_sine((unsigned long) number); }
    constexpr inline double area_hyperbolic_sine(unsigned int const number) noexcept { return Mathematics::area_hyperbolic_sine((unsigned long) number); }
    constexpr inline double area_hyperbolic_sine(unsigned short const number) noexcept { return Mathematics::area_hyperbolic_sine((unsigned long) number); }

    #if c__version >= 1999uL
        constexpr inline double area_hyperbolic_sine(double const number) noexcept { return ::asinh(number); }
        constexpr inline float area_hyperbolic_sine(float const number) noexcept { return ::asinhf(number); }
        constexpr inline long double area_hyperbolic_sine(long double const number) noexcept { return ::asinhl(number); }
    #elif cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_sine(double const number) noexcept { return ::asinh(number); }
        constexpr inline float area_hyperbolic_sine(float const number) noexcept { return ::asinh(number); }
        constexpr inline long double area_hyperbolic_sine(long double const number) noexcept { return ::asinh(number); }
    #else
        constexpr inline double area_hyperbolic_sine(double const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) + 1.0)); }
        constexpr inline float area_hyperbolic_sine(float const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) + 1.0f)); }
        constexpr inline long double area_hyperbolic_sine(long double const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) + 1.0L)); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_sine(long const number) noexcept { return ::asinh(number); }
        constexpr inline double area_hyperbolic_sine(unsigned long const number) noexcept { return ::asinh(number); }
    #else
        constexpr inline double area_hyperbolic_sine(long const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) + 1L)); }
        constexpr inline double area_hyperbolic_sine(unsigned long const number) noexcept { return Mathematics::natural_logarithm(number + Mathematics::square_root((number * number) + 1uL)); }
    #endif

    // Area Hyperbolic Tangent -> tanh-1(x)
    constexpr inline double area_hyperbolic_tangent(int const number) noexcept { return Mathematics::area_hyperbolic_tangent((long) number); }
    constexpr inline double area_hyperbolic_tangent(short const number) noexcept { return Mathematics::area_hyperbolic_tangent((long) number); }
    constexpr inline double area_hyperbolic_tangent(signed char const number) noexcept { return Mathematics::area_hyperbolic_tangent((long) number); }
    constexpr inline double area_hyperbolic_tangent(unsigned char const number) noexcept { return Mathematics::area_hyperbolic_tangent((unsigned long) number); }
    constexpr inline double area_hyperbolic_tangent(unsigned int const number) noexcept { return Mathematics::area_hyperbolic_tangent((unsigned long) number); }
    constexpr inline double area_hyperbolic_tangent(unsigned short const number) noexcept { return Mathematics::area_hyperbolic_tangent((unsigned long) number); }

    #if c__version >= 1999uL
        constexpr inline double area_hyperbolic_tangent(double const number) noexcept { return ::atanh(number); }
        constexpr inline float area_hyperbolic_tangent(float const number) noexcept { return ::atanhf(number); }
        constexpr inline long double area_hyperbolic_tangent(long double const number) noexcept { return ::atanhl(number); }
    #elif cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_tangent(double const number) noexcept { return ::atanh(number); }
        constexpr inline float area_hyperbolic_tangent(float const number) noexcept { return ::atanh(number); }
        constexpr inline long double area_hyperbolic_tangent(long double const number) noexcept { return ::atanh(number); }
    #else
        constexpr inline double area_hyperbolic_tangent(double const number) noexcept { return Mathematics::natural_logarithm((1.0 + number) / (1.0 - number)) / 2.0; }
        constexpr inline float area_hyperbolic_tangent(float const number) noexcept { return Mathematics::natural_logarithm((1.0f + number) / (1.0f - number)) / 2.0f; }
        constexpr inline long double area_hyperbolic_tangent(long double const number) noexcept { return Mathematics::natural_logarithm((1.0L + number) / (1.0L - number)) / 2.0L; }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_tangent(long const number) noexcept { return ::atanh(number); }
        constexpr inline double area_hyperbolic_tangent(unsigned long const number) noexcept { return ::atanh(number); }
    #else
        constexpr inline double area_hyperbolic_tangent(long const number) noexcept { return Mathematics::natural_logarithm((1L + number) / (1L - number)) / 2L; }
        constexpr inline double area_hyperbolic_tangent(unsigned long const number) noexcept { return Mathematics::natural_logarithm((1uL + number) / (1uL - number)) / 2uL; }
    #endif

    // Hyperbolic Cosine -> cosh(x)
    constexpr inline double hyperbolic_cosine(int const number) noexcept { return Mathematics::hyperbolic_cosine((long) number); }
    constexpr inline double hyperbolic_cosine(short const number) noexcept { return Mathematics::hyperbolic_cosine((long) number); }
    constexpr inline double hyperbolic_cosine(signed char const number) noexcept { return Mathematics::hyperbolic_cosine((long) number); }
    constexpr inline double hyperbolic_cosine(unsigned char const number) noexcept { return Mathematics::hyperbolic_cosine((unsigned long) number); }
    constexpr inline double hyperbolic_cosine(unsigned int const number) noexcept { return Mathematics::hyperbolic_cosine((unsigned long) number); }
    constexpr inline double hyperbolic_cosine(unsigned short const number) noexcept { return Mathematics::hyperbolic_cosine((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1999uL
        constexpr inline double hyperbolic_cosine(double const number) noexcept { return ::cosh(number); }
    #else
        constexpr inline double hyperbolic_cosine(double const number) noexcept { return Mathematics::hyperbolic_cosine((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float hyperbolic_cosine(float const number) noexcept { return ::coshf(number); }
        constexpr inline long double hyperbolic_cosine(long double const number) noexcept { return ::coshl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float hyperbolic_cosine(float const number) noexcept { return ::cosh(number); }
        constexpr inline long double hyperbolic_cosine(long double const number) noexcept { return ::cosh(number); }
    #else
        constexpr inline float hyperbolic_cosine(float const number) noexcept { return Mathematics::hyperbolic_cosine((long double) number); }
        constexpr inline long double hyperbolic_cosine(long double const number) noexcept { return (Mathematics::exponentiate(Mathematics::E, number) / 2.0L) + (Mathematics::exponentiate(Mathematics::E, -number) / 2.0L); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double hyperbolic_cosine(long const number) noexcept { return ::cosh(number); }
        constexpr inline double hyperbolic_cosine(unsigned long const number) noexcept { return ::cosh(number); }
    #else
        constexpr inline double hyperbolic_sine(long const number) noexcept { return (Mathematics::exponentiate(Mathematics::E, number) / 2L) + (Mathematics::exponentiate(Mathematics::E, -number) / 2L); }
        constexpr inline double hyperbolic_sine(unsigned long const number) noexcept { return (Mathematics::exponentiate(Mathematics::E, number) / 2uL) + (Mathematics::exponentiate(Mathematics::E, -number) / 2uL); }
    #endif

    // Hyperbolic Sine -> sinh(x)
    constexpr inline double hyperbolic_sine(int const number) noexcept { return Mathematics::hyperbolic_sine((long) number); }
    constexpr inline double hyperbolic_sine(short const number) noexcept { return Mathematics::hyperbolic_sine((long) number); }
    constexpr inline double hyperbolic_sine(signed char const number) noexcept { return Mathematics::hyperbolic_sine((long) number); }
    constexpr inline double hyperbolic_sine(unsigned char const number) noexcept { return Mathematics::hyperbolic_sine((unsigned long) number); }
    constexpr inline double hyperbolic_sine(unsigned int const number) noexcept { return Mathematics::hyperbolic_sine((unsigned long) number); }
    constexpr inline double hyperbolic_sine(unsigned short const number) noexcept { return Mathematics::hyperbolic_sine((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1999uL
        constexpr inline double hyperbolic_sine(double const number) noexcept { return ::sinh(number); }
    #else
        constexpr inline double hyperbolic_sine(double const number) noexcept { return Mathematics::hyperbolic_sine((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float hyperbolic_sine(float const number) noexcept { return ::sinhf(number); }
        constexpr inline long double hyperbolic_sine(long double const number) noexcept { return ::sinhl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float hyperbolic_sine(float const number) noexcept { return ::sinh(number); }
        constexpr inline long double hyperbolic_sine(long double const number) noexcept { return ::sinh(number); }
    #else
        constexpr inline float hyperbolic_sine(float const number) noexcept { return Mathematics::hyperbolic_sine((long double) number); }
        constexpr inline long double hyperbolic_sine(long double const number) noexcept { return (Mathematics::exponentiate(Mathematics::E, number) / 2.0L) - (Mathematics::exponentiate(Mathematics::E, -number) / 2.0L); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double hyperbolic_sine(long const number) noexcept { return ::sinh(number); }
        constexpr inline double hyperbolic_sine(unsigned long const number) noexcept { return ::sinh(number); }
    #else
        constexpr inline double hyperbolic_sine(long const number) noexcept { return (Mathematics::exponentiate(Mathematics::E, number) / 2L) - (Mathematics::exponentiate(Mathematics::E, -number) / 2L); }
        constexpr inline double hyperbolic_sine(unsigned long const number) noexcept { return (Mathematics::exponentiate(Mathematics::E, number) / 2uL) - (Mathematics::exponentiate(Mathematics::E, -number) / 2uL); }
    #endif

    // Hyperbolic Tangent -> tanh(x)
    constexpr inline double hyperbolic_tangent(int const number) noexcept { return Mathematics::hyperbolic_tangent((long) number); }
    constexpr inline double hyperbolic_tangent(short const number) noexcept { return Mathematics::hyperbolic_tangent((long) number); }
    constexpr inline double hyperbolic_tangent(signed char const number) noexcept { return Mathematics::hyperbolic_tangent((long) number); }
    constexpr inline double hyperbolic_tangent(unsigned char const number) noexcept { return Mathematics::hyperbolic_tangent((unsigned long) number); }
    constexpr inline double hyperbolic_tangent(unsigned int const number) noexcept { return Mathematics::hyperbolic_tangent((unsigned long) number); }
    constexpr inline double hyperbolic_tangent(unsigned short const number) noexcept { return Mathematics::hyperbolic_tangent((unsigned long) number); }
    #if cpp__version
        constexpr inline double hyperbolic_tangent(double const number) noexcept { return ::tanh(number); }
        constexpr inline float hyperbolic_tangent(float const number) noexcept { return ::tanh(number); }
        constexpr inline double hyperbolic_tangent(long const number) noexcept { return ::tanh(number); }
        constexpr inline long double hyperbolic_tangent(long double const number) noexcept { return ::tanh(number); }
        constexpr inline double hyperbolic_tangent(unsigned long const number) noexcept { return ::tanh(number); }
    #else
        constexpr inline double hyperbolic_tangent(long const number) noexcept { return Mathematics::hyperbolic_sine(number) / Mathematics::hyperbolic_cosine(number); }
        constexpr inline double hyperbolic_tangent(unsigned long const number) noexcept { return Mathematics::hyperbolic_sine(number) / Mathematics::hyperbolic_cosine(number); }

        #if c__version >= 1999uL
            constexpr inline double hyperbolic_tangent(double const number) noexcept { return ::tanh(number); }
            constexpr inline float hyperbolic_tangent(float const number) noexcept { return ::tanhf(number); }
            constexpr inline long double hyperbolic_tangent(long double const number) noexcept { return ::tanhl(number); }
        #elif c__version >= 1990uL
            constexpr inline double hyperbolic_tangent(double const number) noexcept { return ::tanh(number); }
            constexpr inline float hyperbolic_tangent(float const number) noexcept { return Mathematics::hyperbolic_sine(number) / Mathematics::hyperbolic_cosine(number); }
            constexpr inline long double hyperbolic_tangent(long double const number) noexcept { return Mathematics::hyperbolic_sine(number) / Mathematics::hyperbolic_cosine(number); }
        #else
            constexpr inline double hyperbolic_tangent(double const number) noexcept { return Mathematics::hyperbolic_tangent((long double) number); }
            constexpr inline float hyperbolic_tangent(float const number) noexcept { return Mathematics::hyperbolic_tangent((long double) number); }
            constexpr inline long double hyperbolic_tangent(long double const number) noexcept { return Mathematics::hyperbolic_sine(number) / Mathematics::hyperbolic_cosine(number); }
        #endif
    #endif

// : [Power]
    // Cube Root
    #if c__version >= 1999uL || cpp__version >= 2011uL
        constexpr inline double cube_root(double const number) noexcept { return ::cbrt(number); }
    #else
        constexpr inline double cube_root(double const number) noexcept { return Mathematics::cube_root((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float cube_root(float const number) noexcept { return ::cbrtf(number); }
        constexpr inline long double cube_root(long double const number) noexcept { return ::cbrtl(number); }
    #elif cpp__version >= 2011uL
        constexpr inline float cube_root(float const number) noexcept { return ::cbrt(number); }
        constexpr inline long double cube_root(long double const number) noexcept { return ::cbrt(number); }
    #else
        constexpr inline float cube_root(float const number) noexcept { return Mathematics::cube_root((long double) number); }
        constexpr inline long double cube_root(long double const number) noexcept { // NOTE (Lapys) -> Binary search algorithm.
            // Logic > ... --- ERROR (Lapys) ->
            if (number < +0.0L) { // Domain Error.
                #if includes__floating_point_environment_library
                    if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_INVALID);
                    if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM);
                #endif
                return NaN;
            }
            else if (0.0L == number || Infinity.is(number)) return number;
            else if (NaN.is(number)) return NaN;

            // Initialization > (Evaluation, Precision, (Greater, Lower))
            long double evaluation = 0.0L;
            long double const precision = 0.000000000000000001L;
            long double greater = 1.0L, lower = 1.0L;

            // (Loop > )Update > (Greater, Lower)
            number < 1.0L ? lower = number : greater = number;
            while (precision < greater - lower) {
                evaluation = (greater + lower) / 2.0L;
                number > evaluation * evaluation * evaluation ? lower = approximation : greater = approximation;
            }

            // Return
            return (greater + lower) / 2.0L;
        }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double cube_root(long const number) noexcept { return ::cbrt(number); }
        constexpr inline double cube_root(unsigned long const number) noexcept { return ::cbrt(number); }
    #else
        constexpr inline double cube_root(long const number) noexcept {
            // Logic > ... --- ERROR (Lapys) ->
            if (number < 0L) { // Domain Error.
                #if includes__floating_point_environment_library
                    if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_INVALID);
                    if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM);
                #endif
                return NaN;
            }

            // Return
            return Mathematics::cube_root((unsigned long) number);
        }
        constexpr inline long double cube_root(unsigned long const number) noexcept {
            // Logic > Return
            if (0uL == number) return number;

            // Initialization > (Approximation, Evaluation, Shift)
            unsigned long approximation = 1uL;
            unsigned long evaluation = 0uL;
            unsigned long const shift = 64uL - Mathematics::bit_length(number);

            // Update > Approximation
            // : Loop
            approximation <<= (number + 2uL) / 3uL; // -> `ceil(number / 3)`
            do {
                // Update > (Evaluation, Approximation)
                evaluation = approximation;
                approximation = (2uL * evaluation + number / (evaluation * evaluation)) / 3uL;
            } while (approximation < evaluation);

            // Return
            return evaluation;
        }
    #endif

    // Exponentiate --- CHECKPOINT (Lapys) -> Fix the goddamn int-to-int pow()
    constexpr inline double exponentiate(double const base, float const exponent) noexcept { return Mathematics::exponentiate(base, (double) exponent); }
    constexpr inline double exponentiate(double const base, long const exponent) noexcept { return Mathematics::exponentiate(base, (double) Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(double const base, long double const exponent) noexcept { return Mathematics::exponentiate<double>((long double) base, exponent); }
    constexpr inline double exponentiate(double const base, short const exponent) noexcept { return Mathematics::exponentiate(base, (double) Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(double const base, signed char const exponent) noexcept { return Mathematics::exponentiate(base, (double) Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(double const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(base, (double) Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(double const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(base, (double) Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(double const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(base, (double) Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(double const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(base, (double) Mathematics::recompose(exponent)); }

    constexpr inline float exponentiate(float const base, double const exponent) noexcept { return Mathematics::exponentiate<float>((double) base, exponent); }
    constexpr inline float exponentiate(float const base, int const exponent) noexcept { return Mathematics::exponentiate(base, (float) Mathematics::recompose(exponent)); }
    constexpr inline float exponentiate(float const base, long const exponent) noexcept { return Mathematics::exponentiate<float>((double) base, (double) Mathematics::recompose(exponent)); }
    constexpr inline float exponentiate(float const base, long double const exponent) noexcept { return Mathematics::exponentiate<float>((long double) base, exponent); }
    constexpr inline float exponentiate(float const base, short const exponent) noexcept { return Mathematics::exponentiate(base, (float) Mathematics::recompose(exponent)); }
    constexpr inline float exponentiate(float const base, signed char const exponent) noexcept { return Mathematics::exponentiate(base, (float) Mathematics::recompose(exponent)); }
    constexpr inline float exponentiate(float const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(base, (float) Mathematics::recompose(exponent)); }
    constexpr inline float exponentiate(float const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(base, (float) Mathematics::recompose(exponent)); }
    constexpr inline float exponentiate(float const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(base, (float) Mathematics::recompose(exponent)); }
    constexpr inline float exponentiate(float const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(base, (float) Mathematics::recompose(exponent)); }

    constexpr inline double exponentiate(int const base, double const exponent) noexcept { return Mathematics::exponentiate<int>((double) Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(int const base, float const exponent) noexcept { return Mathematics::exponentiate((float) Mathematics::recompose(base), exponent); }
    constexpr inline double exponentiate(int const base, long const exponent) noexcept { return Mathematics::exponentiate((long) base, exponent); }
    constexpr inline double exponentiate(int const base, long double const exponent) noexcept { return Mathematics::exponentiate((float) Mathematics::recompose(base), exponent); }
    constexpr inline double exponentiate(int const base, short const exponent) noexcept { return Mathematics::exponentiate(base, (int) exponent); }
    constexpr inline double exponentiate(int const base, signed char const exponent) noexcept { return Mathematics::exponentiate(base, (int) exponent); }
    constexpr inline double exponentiate(int const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(base, (int) exponent); }
    constexpr inline double exponentiate(int const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate((long) base, (long) exponent); }
    constexpr inline double exponentiate(int const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(base, exponent); }
    constexpr inline double exponentiate(int const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(base, exponent); }

    constexpr inline double exponentiate(long const base, double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(long const base, float const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(long const base, int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(long const base, short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(long const base, signed char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(long const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(long const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(long const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(long const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }

    constexpr inline long double exponentiate(long double const base, double const exponent) noexcept { return Mathematics::exponentiate(base, (long double) exponent); }
    constexpr inline long double exponentiate(long double const base, float const exponent) noexcept { return Mathematics::exponentiate(base, (long double) exponent); }
    constexpr inline long double exponentiate(long double const base, short const exponent) noexcept { return Mathematics::exponentiate(base, Mathematics::recompose(exponent)); }
    constexpr inline long double exponentiate(long double const base, signed char const exponent) noexcept { return Mathematics::exponentiate(base, Mathematics::recompose(exponent)); }
    constexpr inline long double exponentiate(long double const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(base, Mathematics::recompose(exponent)); }
    constexpr inline long double exponentiate(long double const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(base, Mathematics::recompose(exponent)); }
    constexpr inline long double exponentiate(long double const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(base, Mathematics::recompose(exponent)); }

    constexpr inline double exponentiate(short const base, double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(short const base, float const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(short const base, int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(short const base, long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(short const base, long double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), exponent); }
    constexpr inline double exponentiate(short const base, signed char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(short const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(short const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(short const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(short const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }

    constexpr inline double exponentiate(signed char const base, double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(signed char const base, float const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(signed char const base, int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(signed char const base, long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(signed char const base, long double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), exponent); }
    constexpr inline double exponentiate(signed char const base, short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(signed char const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(signed char const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(signed char const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(signed char const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }

    constexpr inline double exponentiate(unsigned char const base, double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(unsigned char const base, float const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(unsigned char const base, int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned char const base, long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned char const base, long double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), exponent); }
    constexpr inline double exponentiate(unsigned char const base, short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned char const base, signed char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned char const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned char const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned char const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }

    constexpr inline double exponentiate(unsigned int const base, double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(unsigned int const base, float const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(unsigned int const base, int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned int const base, long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned int const base, long double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), exponent); }
    constexpr inline double exponentiate(unsigned int const base, short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned int const base, signed char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned int const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned int const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned int const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }

    constexpr inline double exponentiate(unsigned long const base, double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(unsigned long const base, float const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(unsigned long const base, int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned long const base, long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned long const base, short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned long const base, signed char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned long const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned long const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned long const base, unsigned short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }

    constexpr inline double exponentiate(unsigned short const base, double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(unsigned short const base, float const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), (long double) exponent); }
    constexpr inline double exponentiate(unsigned short const base, int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned short const base, long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned short const base, long double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), exponent); }
    constexpr inline double exponentiate(unsigned short const base, short const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned short const base, signed char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned short const base, unsigned char const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned short const base, unsigned int const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }
    constexpr inline double exponentiate(unsigned short const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), Mathematics::recompose(exponent)); }

    #if c__version >= 1990uL || cpp__version >= 1997uL
        constexpr inline double exponentiate(double const base, double const exponent) noexcept { return ::pow(base, exponent); }
    #else
        constexpr inline double exponentiate(double const base, double const exponent) noexcept { return Mathematics::exponentiate<double>((long double) base, (long double) exponent); }
    #endif

    #if c__version >= 1999uL
        constexpr inline double exponentiate(double const base, int const exponent) noexcept { return Mathematics::exponentiate((double) base, (double) Mathematics::recompose(exponent)); }
        constexpr inline float exponentiate(float const base, float const exponent) noexcept { return ::powf(base, exponent); }
        constexpr inline long double exponentiate(long double const base, long double const exponent) noexcept { return ::powl(base, exponent); }
        constexpr inline long double exponentiate(long double const base, int const exponent) noexcept { return Mathematics::exponentiate(base, (long double) Mathematics::recompose(exponent)); }
    #elif cpp__version >= 1997uL
        constexpr inline double exponentiate(double const base, int const exponent) noexcept { return ::pow(base, exponent); }
        constexpr inline float exponentiate(float const base, float const exponent) noexcept { return ::pow(base, exponent); }
        constexpr inline long double exponentiate(long double const base, long double const exponent) noexcept { return ::pow(base, exponent); }
        constexpr inline long double exponentiate(long double const base, int const exponent) noexcept { return ::pow(base, exponent); }
    #else
        template <class type = long double>
        constexpr inline long double exponentiate(long double const base, long double const exponent) noexcept {
            // Logic ...
            if ((base < +0.0L && Infinity.isnt(base)) && (Infinity.isnt(exponent) && Mathematics::mantissa_of(exponent))) {
                // Logic > Error; Return --- ERROR (Lapys) ->
                #if c__version >= 1990uL // (Domain, Range) Error.
                    return Mathematics::exponentiate(-0.1, 0.1);
                #elif includes__floating_point_environment_library // Domain Error.
                    if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_DIVBYZERO); // CONSIDER (Lapys)
                    if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM);
                #endif
                return -(long double) NaN;
            }

            else if (base + exponent == 0.0L) {
                // Logic; Return --- ERROR (Lapys) -> Domain Error.
                #if c__version >= 1990uL
                    // Return
                    return Mathematics::exponentiate(0.0, 0.0);
                #endif
                return 1.0L;
            }

            else if (0.0L == base) {
                // Logic
                if (exponent < +0.0L) {
                    // Logic; Return --- ERROR (Lapys) -> (Domain | Pole) Error.
                    #if c__version >= 1990uL
                        if (Infinity.is(exponent)) Mathematics::exponentiate(0.0, -Infinity);
                        else return Mathematics::exponentiate(0.0, -1.0);
                    #endif
                    return Infinity;
                }

                else if (Mathematics::odd(exponent)) {
                    // Logic > ... Return
                    if (exponent < +0.0L) {
                        #if includes__floating_point_environment_library
                            if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_DIVBYZERO);
                            if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM); // CONSIDER (Lapys)
                        #endif
                        return +0.0L == base ? Infinity : -Infinity;
                    } else return base;
                }

                else if (Mathematics::even(exponent) || Mathematics::mantissa_of(exponent)) {
                    // Logic > ... Return
                    if (false == exponent < +0.0L) return 0.0L;
                    else if (exponent < +0.0L && Infinity.isnt(exponent)) {
                        #if includes__floating_point_environment_library
                            if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_DIVBYZERO);
                            if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM); // CONSIDER (Lapys)
                        #endif
                        return +Infinity;
                    }
                }
            }

            else if (0.0L == exponent) return 1.0L;
            else if (1.0L == base) return 1.0L;
            else if (-1.0L == base && Infinity.is(exponent)) return 1.0L;
            else if (Infinity.is(base)) {
                // Logic > ... Return
                if (base < +0.0L) {
                    if (Mathematics::odd(exponent)) return exponent < +0.0L ? -0.0L : -Infinity;
                    else if (Mathematics::even(exponent) || Mathematics::mantissa_of(exponent)) return exponent < +0.0L ? +0.0L : +Infinity;
                }
                else if (exponent < +0.0L) return +0.0L;
                else return +Infinity;
            }

            else if (Infinity.is(exponent)) {
                // Constant > Absolute Base
                long double const absoluteBase = Mathematics::absolute(base);

                // Logic > ... Return
                if (exponent < +0.0L) { if (absoluteBase < 1.0L) return Infinity; else if (absoluteBase > 1.0L) return 0.0L; }
                else { if (absoluteBase < 1.0L) return 0.0L; else if (absoluteBase > 1.0L) return Infinity; }
            }

            else if ((base < +0.0L && Infinity.isnt(base)) && (Infinity.isnt(exponent) && Mathematics::mantissa_of(exponent))) {
                // Logic > Error; Return --- ERROR (Lapys)
                #if includes__floating_point_environment_library
                    if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_INVALID);
                    if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM); // CONSIDER (Lapys)
                #endif
                return NaN;
            }

            else if (NaN.is(base) || NaN.is(exponent)) return NaN;
            else if (0.0L == exponent) return 1.0L;
            else if (exponent < +0.0L) return Mathematics::exponentiate(1.0L / base, -exponent);

            else {
                // Constant > Evaluation
                long double const evaluation = Mathematics::natural_exponentiate(exponent * Mathematics::natural_logarithm(base));

                // Logic > Error --- ERROR (Lapys) -> Range Error.
                if (
                    is_same_t<type, double> ? evaluation > DBL_MAX || evaluation < DBL_MIN :
                    is_same_t<type, int> ? evaluation > INT_MAX || evaluation < INT_MIN :
                    is_same_t<type, short> ? evaluation > DBL_MAX || evaluation < DBL_MIN :
                    is_same_t<type, float> ? evaluation > FLT_MAX || evaluation < FLT_MIN :
                    evaluation > LDBL_MAX || evaluation < LDBL_MIN
                ) {
                    #if includes__floating_point_environment_library
                        if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(evaluation > LDBL_MAX ? FE_OVERFLOW : FE_UNDERFLOW);
                        if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(ERANGE);
                    #endif
                }

                // Return
                return evaluation;
            }

            // Return
            return NaN;
        }

        constexpr inline double exponentiate(double const base, int const exponent) noexcept { return Mathematics::exponentiate(base, (double) Mathematics::recompose(exponent)); }
        constexpr inline float exponentiate(float const base, float const exponent) noexcept { return Mathematics::exponentiate<float>((long double) base, (long double) exponent); }
        constexpr inline long double exponentiate(long double const base, int const exponent) noexcept { return Mathematics::exponentiate(base, (long double) Mathematics::recompose(exponent)); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double exponentiate(long const base, long const exponent) noexcept { return ::pow(base, exponent); }
        constexpr inline double exponentiate(long const base, long double const exponent) noexcept { return ::pow(base, exponent); }
        constexpr inline long double exponentiate(long double const base, long const exponent) noexcept { return ::pow(base, exponent); }

        constexpr inline double exponentiate(unsigned long const base, unsigned long const exponent) noexcept { return ::pow(base, exponent); }
        constexpr inline double exponentiate(unsigned long const base, long double const exponent) noexcept { return ::pow(base, exponent); }
        constexpr inline long double exponentiate(long double const base, unsigned long const exponent) noexcept { return ::pow(base, exponent); }
    #else
        constexpr inline double exponentiate(long const base, long const exponent) noexcept {
            [Custom code]
            int ipow(int base, int exp) {
                int result = 1;
                for (;;)
                {
                    if (exp & 1)
                        result *= base;
                    exp >>= 1;
                    if (!exp)
                        break;
                    base *= base;
                }

                return result;
            }
        }
        constexpr inline double exponentiate(long const base, long double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), exponent); }
        constexpr inline long double exponentiate(long double const base, long const exponent) noexcept { return Mathematics::exponentiate(base, Mathematics::recompose(exponent)); }

        constexpr inline double exponentiate(unsigned long const base, unsigned long const exponent) noexcept {
            [Custom code]
        }
        constexpr inline double exponentiate(unsigned long const base, long double const exponent) noexcept { return Mathematics::exponentiate(Mathematics::recompose(base), exponent); }
        constexpr inline long double exponentiate(long double const base, unsigned long const exponent) noexcept { return Mathematics::exponentiate(base, Mathematics::recompose(exponent)); }
    #endif

    // Square Root
    constexpr inline double square_root(int const number) { return Mathematics::square_root((long) number); }
    constexpr inline double square_root(short const number) { return Mathematics::square_root((long) number); }square_root
    constexpr inline double square_root(signed char const number) { return Mathematics::square_root((long) number); }
    constexpr inline double square_root(unsigned char const number) { return Mathematics::square_root((unsigned long) number); }
    constexpr inline double square_root(unsigned int const number) { return Mathematics::square_root((unsigned long) number); }
    constexpr inline double square_root(unsigned short const number) { return Mathematics::square_root((unsigned long) number); }

    #if c__version >= 1990uL
        constexpr inline double square_root(double const number) noexcept { return ::sqrt(number); }
    #else
        constexpr inline double square_root(double const number) noexcept { return Mathematics::square_root((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float square_root(float const number) noexcept { return ::sqrtf(number); }
        constexpr inline long double square_root(long double const number) noexcept { return ::sqrtl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float square_root(float const number) noexcept { return ::sqrt(number); }
        constexpr inline long double square_root(long double const number) noexcept { return ::sqrt(number); }
    #else
        constexpr inline float square_root(float const number) noexcept { return Mathematics::square_root((long double) number); }
        constexpr inline long double square_root(long double const number) noexcept { // NOTE (Lapys) -> Newton-Raphson method.
            // Logic > ... --- ERROR (Lapys) ->
            if (number < +0.0L) { // Domain Error.
                #if includes__floating_point_environment_library
                    if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_INVALID);
                    if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM);
                #endif
                return NaN;
            }
            else if (0.0L == number || Infinity.is(number)) return number;
            else if (NaN.is(number)) return NaN;

            // Initialization > (Evaluation, Precision, (Greater, Lower))
            long double evaluation = 0.0L;
            long double const precision = 0.000000000000000001L;
            long double greater = 1.0L, lower = 1.0L;

            // (Loop > )Update > (Greater, Lower)
            number < 1.0L ? lower = number : greater = number;
            while (precision < greater - lower) {
                evaluation = (greater + lower) / 2.0L;
                number > evaluation * evaluation ? lower = approximation : greater = approximation;
            }

            // Return
            return (greater + lower) / 2.0L;
        }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double square_root(long const number) noexcept { return ::sqrt(number); }
        constexpr inline double square_root(unsigned long const number) noexcept { return ::sqrt(number); }
    #else
        constexpr inline double square_root(long const number) noexcept {
            // Logic > ... --- ERROR (Lapys) ->
            if (number < 0L) { // Domain Error.
                #if includes__floating_point_environment_library
                    if (Exception::allowsFloatingPointException()) Exception::raiseFloatingPointException(FE_INVALID);
                    if (Exception::allowsFloatingPointErrorIndicator()) Exception::setErrorIndicator(EDOM);
                #endif
                return NaN;
            }

            // Return
            return Mathematics::square_root((unsigned long) number);
        }
        constexpr inline double square_root(unsigned long const number) noexcept {
            // Logic > Return
            if (0uL == number) return number;

            // Initialization > (Evaluation, Shift)
            unsigned long evaluation = 0uL;
            unsigned long shift = Mathematics::bit_length(number);

            // Loop > Update > Shift --- NOTE (Lapys) -> To the nearest multiple of `2`.
            shift += shift & 1uL;

            // Loop
            do {
                // Update > (Shift, Evaluation) --- NOTE (Lapys) ->
                shift -= 2uL;

                evaluation <<= 1uL; // Allocate space for the next bit.
                evaluation |= 1uL; // Assert the next bit is `1`.
                evaluation ^= (evaluation * evaluation) > (number >> shift); // Revert if the guess was too great.
            } while (shift);

            // Return
            return evaluation;
        }
    #endif

void exponentiate(...);
void hypotenuse(...);
void root(...);

// : [Remainder & Round]
void modulo(...);
void next_representable(...);
void round_down(...);
void round_integral(...);
void round_near(...);
void round_up(...);
void truncate(...);

// : [Trigonometry]
void arc_cosine(...);
void arc_sine(...);
void arc_tangent(...);
void cosine(...);
void sine(...);
void tangent(...);

// : [Utility]
void difference(...);
void maximum(...);
void minimum(...);

// : ...
void absolute(...);
unsigned char bit_length(...) {}
unsigned char characteristics_length(...);
void characteristics_of(...); // basically truncate :p
unsigned char mantissa_length(...);
void mantissa_of(...);
void factorial(...);
long double mantissa_of(...);
long double recompose(...); // convert int to long double / long to float

template <class> struct maxof {};
template <> struct maxof<int> { constexpr inline int value = INT_MAX; };

Math::maxof_t<int>

maxof<>
minof<>
isfinite
isinf
isnan
odd()
even()
