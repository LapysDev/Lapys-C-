/* Function > ... */
#if CPP_VERSION < 2011uL
  template <typename type> type&       forward(type&       object) throw() { return object; }
  template <typename type> type const& forward(type const& object) throw() { return object; }

  template <typename type> type instanceof() throw();
#else
  // template <typename type> constexpr type&& forward(typename remove_reference<type>::type&  object) noexcept { return static_cast<type&&>(object); }
  // template <typename type> constexpr type&& forward(typename remove_reference<type>::type&& object) noexcept { return static_cast<type&&>(object); }

  // template <typename type> constexpr type&& instanceof() noexcept;
#endif
