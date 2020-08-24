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

/* Modification > Mathematics --- CHECKPOINT (Lapys) -> Check for exceptions. */
// : [Exponent & Logarithm]
    // Binary Exponentiate -> 2 ** x
    constexpr inline double binary_exponentiate(int const exponent) noexcept { return Mathematics::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(short const exponent) noexcept { return Mathematics::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(signed char const exponent) noexcept { return Mathematics::binary_exponentiate((long) exponent); }
    constexpr inline double binary_exponentiate(unsigned char const exponent) noexcept { return Mathematics::binary_exponentiate((unsigned long) exponent); }
    constexpr inline double binary_exponentiate(unsigned int const exponent) noexcept { return Mathematics::binary_exponentiate((unsigned long) exponent); }
    constexpr inline double binary_exponentiate(unsigned short const exponent) noexcept { return Mathematics::binary_exponentiate((unsigned long) exponent); }

    #if c__version >= 1990uL
        constexpr inline double binary_exponentiate(double const exponent) noexcept { return ::exp2(exponent); }
        constexpr inline float binary_exponentiate(float const exponent) noexcept { return ::exp2f(exponent); }
        constexpr inline long double binary_exponentiate(long double const exponent) noexcept { return ::exp2l(exponent); }
    #elif cpp__version >= 2011uL
        constexpr inline double binary_exponentiate(double const exponent) noexcept { return ::exp2(exponent); }
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
        constexpr inline double binary_logarithm(double const number) noexcept { return M_LOG2E * Mathematics::natural_logarithm(number); }
        constexpr inline float binary_logarithm(float const number) noexcept { return M_LOG2E * Mathematics::natural_logarithm(number); }
        constexpr inline long double binary_logarithm(long double const number) noexcept { return M_LOG2E * Mathematics::natural_logarithm(number); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double binary_logarithm(long const number) noexcept { return ::log2(number); }
        constexpr inline double binary_logarithm(unsigned long const number) noexcept { return ::log2(number); }
    #else
        constexpr inline double binary_logarithm(long const number) noexcept { return M_LOG2E * Mathematics::natural_logarithm(number); }
        constexpr inline double binary_logarithm(unsigned long const number) noexcept { return M_LOG2E * Mathematics::natural_logarithm(number); }
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
        constexpr inline double denary_logarithm(double const number) noexcept { return M_LOG10E * Mathematics::natural_logarithm(number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float denary_logarithm(float const number) noexcept { return ::log10f(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return ::log10l(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float denary_logarithm(float const number) noexcept { return ::log10(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return ::log10(number); }
    #else
        constexpr inline float denary_logarithm(float const number) noexcept { return M_LOG10E * Mathematics::natural_logarithm(number); }
        constexpr inline long double denary_logarithm(long double const number) noexcept { return M_LOG10E * Mathematics::natural_logarithm(number); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline long denary_logarithm(long const number) noexcept { return ::log10(number); }
        constexpr inline unsigned long denary_logarithm(unsigned long const number) noexcept { return ::log10(number); }
    #else
        constexpr inline double denary_logarithm(long const number) noexcept { return M_LOG10E * Mathematics::natural_logarithm(number); }
        constexpr inline double denary_logarithm(unsigned long const number) noexcept { return M_LOG10E * Mathematics::natural_logarithm(number); }
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
        constexpr inline double natural_exponentiate(double const number) noexcept { return Mathematics::exponentiate(M_E, number); }
    #endif

    #if c__version >= 1999uL
        constexpr inline float natural_exponentiate(float const number) noexcept { return ::expf(number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept { return ::expl(number); }
    #elif cpp__version >= 1997uL
        constexpr inline float natural_exponentiate(float const number) noexcept { return ::exp(number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept { return ::exp(number); }
    #else
        constexpr inline float natural_exponentiate(float const number) noexcept { return Mathematics::exponentiate(M_E, number); }
        constexpr inline long double natural_exponentiate(long double const number) noexcept { return Mathematics::exponentiate(M_E, number); }
    #endif

    #if cpp__version >= 2011uL
        constexpr inline double natural_exponentiate(long const number) noexcept { return ::exp(number); }
        constexpr inline double natural_exponentiate(unsigned long const number) noexcept { return ::exp(number); }
    #else
        constexpr inline double natural_exponentiate(long const number) noexcept { return Mathematics::exponentiate(M_E, number); }
        constexpr inline double natural_exponentiate(unsigned long const number) noexcept { return Mathematics::exponentiate(M_E, number); }
    #endif

    // Natural Logarithm -> logE(x)
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
            size_t const count = Mathematics::exponentiate(10u, Mathematics::characteristics_length(number));
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
void area_hyperbolic_cosine(...);
void area_hyperbolic_sine(...);
void area_hyperbolic_tangent(...);
void hyperbolic_cosine(...);
void hyperbolic_sine(...);
void hyperbolic_tangent(...);

// : [Power]
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
