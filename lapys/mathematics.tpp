/* ... */
namespace Lapys {
  /* Namespace */
  namespace Math {
    /* Constant > ... */
    template <typename base> base const Constant<base>::E    varinit(Math::E);
    template <typename base> base const Constant<base>::ETA  varinit(Math::ETA);
    template <typename base> base const Constant<base>::LN10 varinit(Math::LN10);
    template <typename base> base const Constant<base>::ONE  varinit(Math::ONE);
    template <typename base> base const Constant<base>::PI   varinit(Math::PI);
    template <typename base> base const Constant<base>::ZERO varinit(Math::ZERO);

    /* Function > ... */
    template <typename type, typename operation>
    constfunc(true) type nodecay accumulate(type nodecay object, typename remove_reference<type nodecay>::type objects[], std::size_t const count, operation const callback) noexcept {
      return count == 1u ? static_cast<type nodecay>(object) : Math::accumulate(callback(static_cast<type nodecay>(objects[0]), static_cast<type nodecay>(objects[1])), objects + 1, count - 1u, callback);
    }

    template <typename type, std::size_t capacity, typename operation>
    constfunc(true) type nodecay accumulate(type nodecayparam(objects)[capacity], operation const callback) noexcept {
      return Math::accumulate(static_cast<type nodecay>(*objects), objects, capacity, callback);
    }

    // ...
    template <typename type>
    constfunc(true) typename remove_reference<type>::type bit_ceil(type nodecay integer) noexcept {
      return integer != Constant<typename remove_reference<type>::type>::ZERO ? Math::bit_ceil<type>(integer >> Constant<typename remove_reference<type>::type>::ONE) << Constant<typename remove_reference<type>::type>::ONE : Constant<typename remove_reference<type>::type>::ONE;
    }

    // ...
    template <typename type>
    constfunc(true) typename remove_reference<type>::type bit_floor(type nodecay integer) noexcept {
      return integer != Constant<typename remove_reference<type>::type>::ZERO ? integer != Constant<typename remove_reference<type>::type>::ONE ? Math::bit_floor<type>(integer >> Constant<typename remove_reference<type>::type>::ONE) << Constant<typename remove_reference<type>::type>::ONE : Constant<typename remove_reference<type>::type>::ONE : Constant<typename remove_reference<type>::type>::ZERO;
    }

    // ...
    template <typename typeA, typename typeB>
    constfunc(true) typeof((instanceof<typeB nodecay>() > instanceof<typeA nodecay>() ? instanceof<typeB nodecay>() : instanceof<typeA nodecay>())) maximum(typeA nodecay numberA, typeB nodecay numberB) noexcept {
      return static_cast<typeof(instanceof<typeB nodecay>() > instanceof<typeA nodecay>() ? instanceof<typeB nodecay>() : instanceof<typeA nodecay>())>(numberB > numberA ? numberB : numberA);
    }

    template <typename type, std::size_t capacity>
    constfunc(true) type nodecay maximum(type nodecayparam(numbers)[capacity]) noexcept {
      return Math::accumulate(static_cast<type nodecayparam(empty())[capacity]>(numbers), static_cast<type nodecay (*)(type nodecay, type nodecay)>(&Math::maximum));
    }

    // ...
    template <typename typeA, typename typeB>
    constfunc(true) std::size_t minimum(typeA nodecay numberA, typeB nodecay numberB) noexcept {
      return static_cast<typeof(instanceof<typeB nodecay>() < instanceof<typeA nodecay>() ? instanceof<typeB nodecay>() : instanceof<typeA nodecay>())>(numberB < numberA ? numberB : numberA);
    }

    template <typename type, std::size_t capacity>
    constfunc(true) type nodecay minimum(type nodecayparam(numbers)[capacity]) noexcept {
      return Math::accumulate(static_cast<type nodecayparam(empty())[capacity]>(numbers), static_cast<type nodecay (*)(type nodecay, type nodecay)>(&Math::minimum));
    }
  }
}

// unsigned ceil(unsigned const number) {
//   return 0u != number ? ceil(number >> 1u) << 1u : 1u;
// }

// unsigned floor(unsigned const number) {
//   return 0u != number ? 1u != number ? floor(number >> 1u) << 1u : 1u : 0u;
// }
