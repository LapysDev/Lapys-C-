/* ... */
namespace Lapys {
  /* Namespace */
  namespace Math {
    constvar long double const E    = 2.7182818284590450L;
    constvar long double const ETA  = 1.5707963267948966L;
    constvar long double const LN10 = 2.3025850929940460L;
    constvar long double const PI   = 3.1415926535897930L;
    constenum(unsigned, ONE , 1u);
    constenum(unsigned, ZERO, 0u);

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
    template <typename type>                       noignore constfunc(true) inline type nodecay maximum(type nodecay, type nodecay) noexcept;
    template <typename type, std::size_t capacity> noignore constfunc(true) inline type nodecay minimum(type nodecayparam(emtpy())[capacity]) noexcept;
    template <typename type>                       noignore constfunc(true) inline type nodecay minimum(type nodecay, type nodecay) noexcept;
  }
}

#include "mathematics.tpp"
