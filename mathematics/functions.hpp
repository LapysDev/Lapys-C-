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

    Infinity;
    NaN;
} namespace Math = Mathematics;

/* Modification > Mathematics --- CHECKPOINT (Lapys) -> Check for exceptions; not only in custom implementations. Co-tangents? */
// : [Exponent & Logarithm]
    // Binary Exponentiate -> 2 ** x
    constexpr inline double binary_exponentiate(double const exponent) noexcept { return ::exp2(exponent); }
    constexpr inline double binary_exponentiate(int const exponent) noexcept { return Math::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(short const exponent) noexcept { return Math::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(signed char const exponent) noexcept { return Math::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(unsigned char const exponent) noexcept { return Math::binary_exponentiate((unsigned long) exponent); }
    constexpr inline double binary_exponentiate(unsigned int const exponent) noexcept { return Math::binary_exponentiate((unsigned long) exponent); }
    constexpr inline double binary_exponentiate(unsigned short const exponent) noexcept { return Math::binary_exponentiate((unsigned long) exponent); }

    #if c__version >= 1990uL
        constexpr inline float binary_exponentiate(float const exponent) noexcept { return ::exp2f(exponent); }
        constexpr inline long double binary_exponentiate(long double const exponent) noexcept { return ::exp2l(exponent); }
    #elif cpp__version >= 2011uL
        constexpr inline float binary_exponentiate(float const exponent) noexcept { return ::exp2(exponent); }
        constexpr inline long double binary_exponentiate(long double const exponent) noexcept { return ::exp2(exponent); }
    #else
        constexpr inline double binary_exponentiate(double const exponent) noexcept { return Math::exponentiate(2.0, exponent); }
        constexpr inline float binary_exponentiate(float const exponent) noexcept { return Math::exponentiate(2.0f, exponent); }
        constexpr inline long double binary_exponentiate(long double const exponent) noexcept { return Math::exponentiate(2.0L, exponent); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double binary_exponentiate(long const exponent) noexcept { return ::exp2(exponent); }
        constexpr inline double binary_exponentiate(unsigned long const exponent) noexcept { return ::exp2(exponent); }
    #else
        constexpr inline double binary_exponentiate(long const exponent) noexcept { return Math::exponentiate(2L, exponent); }
        constexpr inline double binary_exponentiate(long const exponent) noexcept { return Math::exponentiate(2uL, exponent); }
    #endif

    // Binary Logarithm -> log2(x)
    constexpr inline double binary_logarithm(int const number) noexcept { return Math::binary_logarithm((long) number); }
    constexpr inline double binary_logarithm(short const number) noexcept { return Math::binary_logarithm((long) number); }
    constexpr inline double binary_logarithm(signed char const number) noexcept { return Math::binary_logarithm((long) number); }
    constexpr inline double binary_logarithm(unsigned char const number) noexcept { return Math::binary_logarithm((unsigned long) number); }
    constexpr inline double binary_logarithm(unsigned int const number) noexcept { return Math::binary_logarithm((unsigned long) number); }
    constexpr inline double binary_logarithm(unsigned short const number) noexcept { return Math::binary_logarithm((unsigned long) number); }

    #if c__version >= 1990uL
        constexpr inline double binary_logarithm(double const number) noexcept { return ::log2(number); }
        constexpr inline float binary_logarithm(float const number) noexcept { return ::log2f(number); }
        constexpr inline long double binary_logarithm(long double const number) noexcept { return ::log2l(number); }
    #elif cpp__version >= 2011uL
        constexpr inline double binary_logarithm(double const number) noexcept { return ::log2(number); }
        constexpr inline float binary_logarithm(float const number) noexcept { return ::log2(number); }
        constexpr inline long double binary_logarithm(long double const number) noexcept { return ::log2(number); }
    #else
        constexpr inline double binary_logarithm(double const number) noexcept { return Math::LOG2E * Math::natural_logarithm(number); }
        constexpr inline float binary_logarithm(float const number) noexcept { return Math::LOG2E * Math::natural_logarithm(number); }
        constexpr inline long double binary_logarithm(long double const number) noexcept { return Math::LOG2E * Math::natural_logarithm(number); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double binary_logarithm(long const number) noexcept { return ::log2(number); }
        constexpr inline double binary_logarithm(unsigned long const number) noexcept { return ::log2(number); }
    #else
        constexpr inline double binary_logarithm(long const number) noexcept { return Math::LOG2E * Math::natural_logarithm(number); }
        constexpr inline double binary_logarithm(unsigned long const number) noexcept { return Math::LOG2E * Math::natural_logarithm(number); }
    #endif

    // Denary Logarithm -> log10(x)
    constexpr inline double denary_logarithm(int const number) noexcept { return Math::denary_logarithm((long) number); }
    constexpr inline double denary_logarithm(short const number) noexcept { return Math::denary_logarithm((long) number); }
    constexpr inline double denary_logarithm(signed char const number) noexcept { return Math::denary_logarithm((long) number); }
    constexpr inline double denary_logarithm(unsigned char const number) noexcept { return Math::denary_logarithm((unsigned long) number); }
    constexpr inline double denary_logarithm(unsigned int const number) noexcept { return Math::denary_logarithm((unsigned long) number); }
    constexpr inline double denary_logarithm(unsigned short const number) noexcept { return Math::denary_logarithm((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1997uL
        constexpr inline double denary_logarithm(double const number) noexcept { return ::log10(number); }
    #else
        constexpr inline double denary_logarithm(double const number) noexcept { return Math::LOG10E * Math::natural_logarithm(number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float denary_logarithm(float const number) noexcept { return ::log10f(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return ::log10l(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float denary_logarithm(float const number) noexcept { return ::log10(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return ::log10(number); }
    #else
        constexpr inline float denary_logarithm(float const number) noexcept { return Math::LOG10E * Math::natural_logarithm(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return Math::LOG10E * Math::natural_logarithm(number); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline long denary_logarithm(long const number) noexcept { return ::log10(number); }
        constexpr inline unsigned long denary_logarithm(unsigned long const number) noexcept { return ::log10(number); }
    #else
        constexpr inline double denary_logarithm(long const number) noexcept { return Math::LOG10E * Math::natural_logarithm(number); }
        constexpr inline double denary_logarithm(unsigned long const number) noexcept { return Math::LOG10E * Math::natural_logarithm(number); }
    #endif

    // Natural Exponentiate -> E ** x
    constexpr inline double natural_exponentiate(int const number) noexcept { return Math::natural_exponentiate((long) number); }
    constexpr inline double natural_exponentiate(short const number) noexcept { return Math::natural_exponentiate((long) number); }
    constexpr inline double natural_exponentiate(signed char const number) noexcept { return Math::natural_exponentiate((long) number); }
    constexpr inline double natural_exponentiate(unsigned char const number) noexcept { return Math::natural_exponentiate((unsigned long) number); }
    constexpr inline double natural_exponentiate(unsigned int const number) noexcept { return Math::natural_exponentiate((unsigned long) number); }
    constexpr inline double natural_exponentiate(unsigned short const number) noexcept { return Math::natural_exponentiate((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1997uL
        constexpr inline double natural_exponentiate(double const number) noexcept { return ::exp(number); }
    #else
        constexpr inline double natural_exponentiate(double const number) noexcept { return Math::exponentiate(Math::E, number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float natural_exponentiate(float const number) noexcept { return ::expf(number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept { return ::expl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float natural_exponentiate(float const number) noexcept { return ::exp(number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept { return ::exp(number); }
    #else
        constexpr inline float natural_exponentiate(float const number) noexcept { return Math::exponentiate(Math::E, number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept { return Math::exponentiate(Math::E, number); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double natural_exponentiate(long const number) noexcept { return ::exp(number); }
        constexpr inline double natural_exponentiate(unsigned long const number) noexcept { return ::exp(number); }
    #else
        constexpr inline double natural_exponentiate(long const number) noexcept { return Math::exponentiate(Math::E, number); }
        constexpr inline double natural_exponentiate(unsigned long const number) noexcept { return Math::exponentiate(Math::E, number); }
    #endif

    // Natural Logarithm -> ln(x)
    constexpr inline double natural_logarithm(int const number) noexcept { return Math::natural_logarithm((long) number); }
    constexpr inline double natural_logarithm(short const number) noexcept { return Math::natural_logarithm((long) number); }
    constexpr inline double natural_logarithm(signed char const number) noexcept { return Math::natural_logarithm((long) number); }
    constexpr inline double natural_logarithm(unsigned char const number) noexcept { return Math::natural_logarithm((unsigned long) number); }
    constexpr inline double natural_logarithm(unsigned int const number) noexcept { return Math::natural_logarithm((unsigned long) number); }
    constexpr inline double natural_logarithm(unsigned short const number) noexcept { return Math::natural_logarithm((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1997uL
        constexpr inline double natural_logarithm(double const number) noexcept { return ::log(number); }
    #else
        constexpr inline double natural_logarithm(double const number) noexcept { return (double) Math::natural_logarithm((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float natural_logarithm(float const number) noexcept { return ::logf(number); }
        constexpr inline long double natural_logarithm(long double const number) noexcept { return ::logl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float natural_logarithm(float const number) noexcept { return ::log(number); }
        constexpr inline long double natural_logarithm(long double const number) noexcept { return ::log(number); }
    #else
        constexpr inline float natural_logarithm(float const number) noexcept { return Math::natural_logarithm((long double) number); }
        constexpr inline long double natural_logarithm(long double const number) noexcept {
            // Logic > ... --- ERROR (Lapys) ->
            if (number < -0.0L) { // Domain error.
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

            else if (Infinity == number) return Infinity;
            else if (NaN == number) return NaN;

            // Initialization > (Count, Evaluation)
            size_t const count = Math::exponentiate(10u, Math::characteristics_length(number));
            long double evaluation = 0.0L;

            // Loop > Update > Evaluation
            for (unsigned char iterator = 0u; count ^ iterator; ++iterator)
            evaluation += (
                (1.0L / ((iterator * 2.0L) + 1.0L)) *
                Math::exponentiate((number - 1.0L) / (number + 1.0L), (iterator * 2u) + 1u)
            );

            // Return
            return evaluation * 2.0L;
        }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double natural_logarithm(long const number) noexcept { return ::log(number); }
        constexpr inline double natural_logarithm(unsigned long const number) noexcept { return ::log(number); }
    #else
        constexpr inline double natural_logarithm(long const number) noexcept { return (double) Math::natural_logarithm((long double) number); }
        constexpr inline double natural_logarithm(unsigned long const number) noexcept { return (double) Math::natural_logarithm((long double) number); }
    #endif

// : [Hyperbole]
    // Area Hyperbolic Cosine -> cosh-1(x)
    constexpr inline double area_hyperbolic_cosine(int const number) noexcept { return Math::area_hyperbolic_cosine((long) number); }
    constexpr inline double area_hyperbolic_cosine(short const number) noexcept { return Math::area_hyperbolic_cosine((long) number); }
    constexpr inline double area_hyperbolic_cosine(signed char const number) noexcept { return Math::area_hyperbolic_cosine((long) number); }
    constexpr inline double area_hyperbolic_cosine(unsigned char const number) noexcept { return Math::area_hyperbolic_cosine((unsigned long) number); }
    constexpr inline double area_hyperbolic_cosine(unsigned int const number) noexcept { return Math::area_hyperbolic_cosine((unsigned long) number); }
    constexpr inline double area_hyperbolic_cosine(unsigned short const number) noexcept { return Math::area_hyperbolic_cosine((unsigned long) number); }

    #if c__version >= 1999uL
        constexpr inline double area_hyperbolic_cosine(double const number) noexcept { return ::acosh(number); }
        constexpr inline float area_hyperbolic_cosine(float const number) noexcept { return ::acoshf(number); }
        constexpr inline long double area_hyperbolic_cosine(long double const number) noexcept { return ::acoshl(number); }
    #elif cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_cosine(double const number) noexcept { return ::acosh(number); }
        constexpr inline float area_hyperbolic_cosine(float const number) noexcept { return ::acosh(number); }
        constexpr inline long double area_hyperbolic_cosine(long double const number) noexcept { return ::acosh(number); }
    #else
        constexpr inline double area_hyperbolic_cosine(double const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) - 1.0)); }
        constexpr inline float area_hyperbolic_cosine(float const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) - 1.0f)); }
        constexpr inline long double area_hyperbolic_cosine(long double const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) - 1.0L)); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_cosine(long const number) noexcept { return ::acosh(number); }
        constexpr inline double area_hyperbolic_cosine(unsigned long const number) noexcept { return ::acosh(number); }
    #else
        constexpr inline double area_hyperbolic_cosine(long const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) - 1L)); }
        constexpr inline double area_hyperbolic_cosine(unsigned long const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) - 1uL)); }
    #endif

    // Area Hyperbolic Sine -> sinh-1(x)
    constexpr inline double area_hyperbolic_sine(int const number) noexcept { return Math::area_hyperbolic_sine((long) number); }
    constexpr inline double area_hyperbolic_sine(short const number) noexcept { return Math::area_hyperbolic_sine((long) number); }
    constexpr inline double area_hyperbolic_sine(signed char const number) noexcept { return Math::area_hyperbolic_sine((long) number); }
    constexpr inline double area_hyperbolic_sine(unsigned char const number) noexcept { return Math::area_hyperbolic_sine((unsigned long) number); }
    constexpr inline double area_hyperbolic_sine(unsigned int const number) noexcept { return Math::area_hyperbolic_sine((unsigned long) number); }
    constexpr inline double area_hyperbolic_sine(unsigned short const number) noexcept { return Math::area_hyperbolic_sine((unsigned long) number); }

    #if c__version >= 1999uL
        constexpr inline double area_hyperbolic_sine(double const number) noexcept { return ::asinh(number); }
        constexpr inline float area_hyperbolic_sine(float const number) noexcept { return ::asinhf(number); }
        constexpr inline long double area_hyperbolic_sine(long double const number) noexcept { return ::asinhl(number); }
    #elif cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_sine(double const number) noexcept { return ::asinh(number); }
        constexpr inline float area_hyperbolic_sine(float const number) noexcept { return ::asinh(number); }
        constexpr inline long double area_hyperbolic_sine(long double const number) noexcept { return ::asinh(number); }
    #else
        constexpr inline double area_hyperbolic_sine(double const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) + 1.0)); }
        constexpr inline float area_hyperbolic_sine(float const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) + 1.0f)); }
        constexpr inline long double area_hyperbolic_sine(long double const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) + 1.0L)); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_sine(long const number) noexcept { return ::asinh(number); }
        constexpr inline double area_hyperbolic_sine(unsigned long const number) noexcept { return ::asinh(number); }
    #else
        constexpr inline double area_hyperbolic_sine(long const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) + 1L)); }
        constexpr inline double area_hyperbolic_sine(unsigned long const number) noexcept { return Math::natural_logarithm(number + Math::square_root((number * number) + 1uL)); }
    #endif

    // Area Hyperbolic Tangent -> tanh-1(x)
    constexpr inline double area_hyperbolic_tangent(int const number) noexcept { return Math::area_hyperbolic_tangent((long) number); }
    constexpr inline double area_hyperbolic_tangent(short const number) noexcept { return Math::area_hyperbolic_tangent((long) number); }
    constexpr inline double area_hyperbolic_tangent(signed char const number) noexcept { return Math::area_hyperbolic_tangent((long) number); }
    constexpr inline double area_hyperbolic_tangent(unsigned char const number) noexcept { return Math::area_hyperbolic_tangent((unsigned long) number); }
    constexpr inline double area_hyperbolic_tangent(unsigned int const number) noexcept { return Math::area_hyperbolic_tangent((unsigned long) number); }
    constexpr inline double area_hyperbolic_tangent(unsigned short const number) noexcept { return Math::area_hyperbolic_tangent((unsigned long) number); }

    #if c__version >= 1999uL
        constexpr inline double area_hyperbolic_tangent(double const number) noexcept { return ::atanh(number); }
        constexpr inline float area_hyperbolic_tangent(float const number) noexcept { return ::atanhf(number); }
        constexpr inline long double area_hyperbolic_tangent(long double const number) noexcept { return ::atanhl(number); }
    #elif cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_tangent(double const number) noexcept { return ::atanh(number); }
        constexpr inline float area_hyperbolic_tangent(float const number) noexcept { return ::atanh(number); }
        constexpr inline long double area_hyperbolic_tangent(long double const number) noexcept { return ::atanh(number); }
    #else
        constexpr inline double area_hyperbolic_tangent(double const number) noexcept { return Math::natural_logarithm((1.0 + number) / (1.0 - number)) / 2.0; }
        constexpr inline float area_hyperbolic_tangent(float const number) noexcept { return Math::natural_logarithm((1.0f + number) / (1.0f - number)) / 2.0f; }
        constexpr inline long double area_hyperbolic_tangent(long double const number) noexcept { return Math::natural_logarithm((1.0L + number) / (1.0L - number)) / 2.0L; }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double area_hyperbolic_tangent(long const number) noexcept { return ::atanh(number); }
        constexpr inline double area_hyperbolic_tangent(unsigned long const number) noexcept { return ::atanh(number); }
    #else
        constexpr inline double area_hyperbolic_tangent(long const number) noexcept { return Math::natural_logarithm((1L + number) / (1L - number)) / 2L; }
        constexpr inline double area_hyperbolic_tangent(unsigned long const number) noexcept { return Math::natural_logarithm((1uL + number) / (1uL - number)) / 2uL; }
    #endif

    // Hyperbolic Cosine -> cosh(x)
    constexpr inline double hyperbolic_cosine(int const number) noexcept { return Math::hyperbolic_cosine((long) number); }
    constexpr inline double hyperbolic_cosine(short const number) noexcept { return Math::hyperbolic_cosine((long) number); }
    constexpr inline double hyperbolic_cosine(signed char const number) noexcept { return Math::hyperbolic_cosine((long) number); }
    constexpr inline double hyperbolic_cosine(unsigned char const number) noexcept { return Math::hyperbolic_cosine((unsigned long) number); }
    constexpr inline double hyperbolic_cosine(unsigned int const number) noexcept { return Math::hyperbolic_cosine((unsigned long) number); }
    constexpr inline double hyperbolic_cosine(unsigned short const number) noexcept { return Math::hyperbolic_cosine((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1999uL
        constexpr inline double hyperbolic_cosine(double const number) noexcept { return ::cosh(number); }
    #else
        constexpr inline double hyperbolic_cosine(double const number) noexcept { return Math::hyperbolic_cosine((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float hyperbolic_cosine(float const number) noexcept { return ::coshf(number); }
        constexpr inline long double hyperbolic_cosine(long double const number) noexcept { return ::coshl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float hyperbolic_cosine(float const number) noexcept { return ::cosh(number); }
        constexpr inline long double hyperbolic_cosine(long double const number) noexcept { return ::cosh(number); }
    #else
        constexpr inline float hyperbolic_cosine(float const number) noexcept { return Math::hyperbolic_cosine((long double) number); }
        constexpr inline long double hyperbolic_cosine(long double const number) noexcept { return (Math::exponentiate(Math::E, number) / 2.0L) + (Math::exponentiate(Math::E, -number) / 2.0L); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double hyperbolic_cosine(long const number) noexcept { return ::cosh(number); }
        constexpr inline double hyperbolic_cosine(unsigned long const number) noexcept { return ::cosh(number); }
    #else
        constexpr inline double hyperbolic_sine(long const number) noexcept { return (Math::exponentiate(Math::E, number) / 2L) + (Math::exponentiate(Math::E, -number) / 2L); }
        constexpr inline double hyperbolic_sine(unsigned long const number) noexcept { return (Math::exponentiate(Math::E, number) / 2uL) + (Math::exponentiate(Math::E, -number) / 2uL); }
    #endif

    // Hyperbolic Sine -> sinh(x)
    constexpr inline double hyperbolic_sine(int const number) noexcept { return Math::hyperbolic_sine((long) number); }
    constexpr inline double hyperbolic_sine(short const number) noexcept { return Math::hyperbolic_sine((long) number); }
    constexpr inline double hyperbolic_sine(signed char const number) noexcept { return Math::hyperbolic_sine((long) number); }
    constexpr inline double hyperbolic_sine(unsigned char const number) noexcept { return Math::hyperbolic_sine((unsigned long) number); }
    constexpr inline double hyperbolic_sine(unsigned int const number) noexcept { return Math::hyperbolic_sine((unsigned long) number); }
    constexpr inline double hyperbolic_sine(unsigned short const number) noexcept { return Math::hyperbolic_sine((unsigned long) number); }

    #if c__version >= 1990uL || cpp__version >= 1999uL
        constexpr inline double hyperbolic_sine(double const number) noexcept { return ::sinh(number); }
    #else
        constexpr inline double hyperbolic_sine(double const number) noexcept { return Math::hyperbolic_sine((long double) number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float hyperbolic_sine(float const number) noexcept { return ::sinhf(number); }
        constexpr inline long double hyperbolic_sine(long double const number) noexcept { return ::sinhl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float hyperbolic_sine(float const number) noexcept { return ::sinh(number); }
        constexpr inline long double hyperbolic_sine(long double const number) noexcept { return ::sinh(number); }
    #else
        constexpr inline float hyperbolic_sine(float const number) noexcept { return Math::hyperbolic_sine((long double) number); }
        constexpr inline long double hyperbolic_sine(long double const number) noexcept { return (Math::exponentiate(Math::E, number) / 2.0L) - (Math::exponentiate(Math::E, -number) / 2.0L); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double hyperbolic_sine(long const number) noexcept { return ::sinh(number); }
        constexpr inline double hyperbolic_sine(unsigned long const number) noexcept { return ::sinh(number); }
    #else
        constexpr inline double hyperbolic_sine(long const number) noexcept { return (Math::exponentiate(Math::E, number) / 2L) - (Math::exponentiate(Math::E, -number) / 2L); }
        constexpr inline double hyperbolic_sine(unsigned long const number) noexcept { return (Math::exponentiate(Math::E, number) / 2uL) - (Math::exponentiate(Math::E, -number) / 2uL); }
    #endif

    // Hyperbolic Tangent -> tanh(x)
    constexpr inline double hyperbolic_tangent(int const number) noexcept { return Math::hyperbolic_tangent((long) number); }
    constexpr inline double hyperbolic_tangent(short const number) noexcept { return Math::hyperbolic_tangent((long) number); }
    constexpr inline double hyperbolic_tangent(signed char const number) noexcept { return Math::hyperbolic_tangent((long) number); }
    constexpr inline double hyperbolic_tangent(unsigned char const number) noexcept { return Math::hyperbolic_tangent((unsigned long) number); }
    constexpr inline double hyperbolic_tangent(unsigned int const number) noexcept { return Math::hyperbolic_tangent((unsigned long) number); }
    constexpr inline double hyperbolic_tangent(unsigned short const number) noexcept { return Math::hyperbolic_tangent((unsigned long) number); }
    #if cpp__version
        constexpr inline double hyperbolic_tangent(double const number) noexcept { return ::tanh(number); }
        constexpr inline float hyperbolic_tangent(float const number) noexcept { return ::tanh(number); }
        constexpr inline double hyperbolic_tangent(long const number) noexcept { return ::tanh(number); }
        constexpr inline long double hyperbolic_tangent(long double const number) noexcept { return ::tanh(number); }
        constexpr inline double hyperbolic_tangent(unsigned long const number) noexcept { return ::tanh(number); }
    #else
        constexpr inline double hyperbolic_tangent(long const number) noexcept { return Math::hyperbolic_sine(number) / Math::hyperbolic_cosine(number); }
        constexpr inline double hyperbolic_tangent(unsigned long const number) noexcept { return Math::hyperbolic_sine(number) / Math::hyperbolic_cosine(number); }

        #if c__version >= 1999uL
            constexpr inline double hyperbolic_tangent(double const number) noexcept { return ::tanh(number); }
            constexpr inline float hyperbolic_tangent(float const number) noexcept { return ::tanhf(number); }
            constexpr inline long double hyperbolic_tangent(long double const number) noexcept { return ::tanhl(number); }
        #elif c__version >= 1990uL
            constexpr inline double hyperbolic_tangent(double const number) noexcept { return ::tanh(number); }
            constexpr inline float hyperbolic_tangent(float const number) noexcept { return Math::hyperbolic_sine(number) / Math::hyperbolic_cosine(number); }
            constexpr inline long double hyperbolic_tangent(long double const number) noexcept { return Math::hyperbolic_sine(number) / Math::hyperbolic_cosine(number); }
        #else
            constexpr inline double hyperbolic_tangent(double const number) noexcept { return Math::hyperbolic_tangent((long double) number); }
            constexpr inline float hyperbolic_tangent(float const number) noexcept { return Math::hyperbolic_tangent((long double) number); }
            constexpr inline long double hyperbolic_tangent(long double const number) noexcept { return Math::hyperbolic_sine(number) / Math::hyperbolic_cosine(number); }
        #endif
    #endif

// : [Power]
    // Square Root --- CHECKPOINT (Lapys)
    constexpr inline long double square_root(long double const number) noexcept {
        // Initialization > (Evaluation, Precision, (Greater, Lower))
        long double evaluation = 0.0L;
        long double const precision = 0.000000000000000001L;
        long double greater = 1.0L, lower = 1.0L;

        // Update > (Greater, Lower)
        number < 1.0L ? lower = number : greater = number;
        while (precision < greater - lower) {
            evaluation = (greater + lower) / 2.0L;
            number > evaluation * evaluation ? lower = approximation : greater = approximation;
        }

        // Return
        return (greater + lower) / 2.0L;
    }

void cube_root(...);
void exponentiate(...);
void hypotenuse(...);
void root(...);
void square_root(...);

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
unsigned char characteristics_length(...);
void characteristics_of(...);
unsigned char mantissa_length(...);
void mantissa_of(...);

isfinite
isinf
isnan
