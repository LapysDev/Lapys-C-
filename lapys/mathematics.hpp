/* Namespace */
namespace Lapys {
  /* Namespace */
  namespace Math {
    constvar long double const E    = 2.7182818284590450L;
    constvar long double const ETA  = 1.5707963267948966L;
    constvar long double const LN10 = 2.3025850929940460L;
    constvar long double const PI   = 3.1415926535897930L;
    constenum(unsigned, ONE , 1u);
    constenum(unsigned, ZERO, 0u); // UPDATE (Lapys) -> Constant math expressions `operate<add, Math::E, fraction<2, 5>::value, decimal<5, 4>::value>`

    // ...
    template <typename base>
    class Constant final {
      public:
        static base const E;
        static base const ETA;
        static base const LN10;
        static base const ONE;
        static base const PI;
        static base const ZERO;
    };

    // ...
    template <typename type, typename operation>                       noignore constfunc(true) inline type nodecay accumulate(type nodecay, typename remove_reference<type nodecay>::type[], std::size_t const, operation const) noexcept;
    template <typename type, std::size_t capacity, typename operation> noignore constfunc(true) inline type nodecay accumulate(type nodecayparam(emtpy())[capacity], operation const) noexcept;

    template <typename type> noignore constfunc(true) typename remove_reference<type>::type bit_ceil (type nodecay) noexcept;
    template <typename type> noignore constfunc(true) typename remove_reference<type>::type bit_floor(type nodecay) noexcept;

    template <typename type, std::size_t capacity> noignore constfunc(true) inline type nodecay maximum(type nodecayparam(emtpy())[capacity]) noexcept;
    template <typename typeA, typename typeB>      noignore constfunc(true) inline typeof(instanceof<typeB nodecay>() > instanceof<typeA nodecay>() ? instanceof<typeB nodecay>() : instanceof<typeA nodecay>()) maximum(typeA nodecay, typeA nodecay) noexcept;

    template <typename type, std::size_t capacity> noignore constfunc(true) inline type nodecay minimum(type nodecayparam(emtpy())[capacity]) noexcept;
    template <typename typeA, typename typeB>      noignore constfunc(true) inline std::size_t minimum(typeA nodecay, typeB nodecay) noexcept;

    constfunc(true) inline void abs(...) noexcept;
    constfunc(true) inline void acos(...) noexcept;
    constfunc(true) inline void acosh(...) noexcept;
    constfunc(true) inline void acot(...) noexcept;
    constfunc(true) inline void acoth(...) noexcept;
    constfunc(true) inline void acsc(...) noexcept;
    constfunc(true) inline void acsch(...) noexcept;
    constfunc(true) inline void asec(...) noexcept;
    constfunc(true) inline void asech(...) noexcept;
    constfunc(true) inline void asin(...) noexcept;
    constfunc(true) inline void asinh(...) noexcept;
    constfunc(true) inline void atan(...) noexcept;
    constfunc(true) inline void atanh(...) noexcept;
    constfunc(true) inline void beta(...) noexcept;
    constfunc(true) inline void cbrt(...) noexcept;
    constfunc(true) inline void ceil(...) noexcept;
    constfunc(true) inline void clamp(...) noexcept;
    constfunc(true) inline void cos(...) noexcept;
    constfunc(true) inline void cot(...) noexcept;
    constfunc(true) inline void coth(...) noexcept;
    constfunc(true) inline void csc(...) noexcept;
    constfunc(true) inline void csch(...) noexcept;
    constfunc(true) inline void cyl_bessel(...) noexcept;
    constfunc(true) inline void cyl_neumann(...) noexcept;
    constfunc(true) inline void ellint(...) noexcept;
    constfunc(true) inline void exp(...) noexcept;
    constfunc(true) inline void expint(...) noexcept;
    constfunc(true) inline void fact(...) noexcept;
    constfunc(true) inline void floor(...) noexcept;
    constfunc(true) inline void hermite(...) noexcept;
    constfunc(true) inline void iabs(...) noexcept;
    constfunc(true) inline void icbrt(...) noexcept;
    constfunc(true) inline void ipow(...) noexcept;
    constfunc(true) inline void iroot(...) noexcept;
    constfunc(true) inline void isqrt(...) noexcept;
    constfunc(true) inline void jsf(...) noexcept;
    constfunc(true) inline void knuth_b(...) noexcept;
    constfunc(true) inline void laguerre(...) noexcept;
    constfunc(true) inline void lcg(...) noexcept;
    constfunc(true) inline void legendre(...) noexcept;
    constfunc(true) inline void lerp(...) noexcept;
    constfunc(true) inline void ln(...) noexcept;
    constfunc(true) inline void log(...) noexcept;
    constfunc(true) inline void mod(...) noexcept;
    constfunc(true) inline void mt(...) noexcept;
    constfunc(true) inline void mt32(...) noexcept;
    constfunc(true) inline void mt64(...) noexcept;
    constfunc(true) inline void mulberry(...) noexcept;
    constfunc(true) inline void mulberry32(...) noexcept;
    constfunc(true) inline void perc(...) noexcept;
    constfunc(true) inline void pow(...) noexcept;
    constfunc(true) inline void randint(...) noexcept;
    constfunc(true) inline void random(...) noexcept;
    constfunc(true) inline void riemann_zeta(...) noexcept;
    constfunc(true) inline void root(...) noexcept;
    constfunc(true) inline void round(...) noexcept;
    constfunc(true) inline void sec(...) noexcept;
    constfunc(true) inline void sech(...) noexcept;
    constfunc(true) inline void sin(...) noexcept;
    constfunc(true) inline void sinh(...) noexcept;
    constfunc(true) inline void sph_bessel(...) noexcept;
    constfunc(true) inline void sph_legendre(...) noexcept;
    constfunc(true) inline void sph_neumann(...) noexcept;
    constfunc(true) inline void sqrt(...) noexcept;
    constfunc(true) inline void tan(...) noexcept;
    constfunc(true) inline void tanh(...) noexcept;
    constfunc(true) inline void trunc(...) noexcept;
    constfunc(true) inline void wrap(...) noexcept;
    constfunc(true) inline void xorshift(...) noexcept;
    constfunc(true) inline void xorshift_s(...) noexcept;
    constfunc(true) inline void xorshift128(...) noexcept;
    constfunc(true) inline void xorshift128_s(...) noexcept;
    constfunc(true) inline void xorshift256_p(...) noexcept;
    constfunc(true) inline void xorshift_p(...) noexcept;
    constfunc(true) inline void xorshift128_p(...) noexcept;
    constfunc(true) inline void xorshift_ss(...) noexcept;
    constfunc(true) inline void xorshift256(...) noexcept;
    constfunc(true) inline void xorshift256_ss(...) noexcept;
    constfunc(true) inline void xorwow(...) noexcept;
  }
}

#include "mathematics.tpp"
