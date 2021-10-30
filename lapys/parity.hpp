/* ... */
namespace Lapys {
  /* Definition > ... */
  #if CPP_VERSION < 2017uL
    typedef unsigned char byte;
  #else
    typedef std::byte byte;
  #endif

  /* Function > ... */
  #if CPP_VERSION < 2011uL
    template <typename type>
    type& forward(type&       object) throw() {
      return object;
    }

    template <typename type>
    type const& forward(type const& object) throw() {
      return object;
    }
  #else
    template <typename type>
    constexpr type&& forward(typename Traits::remove_reference<type>::type& object) noexcept {
      return static_cast<type&&>(object);
    }

    template <typename type>
    constexpr type&& forward(typename Traits::remove_reference<type>::type&& object) noexcept {
      return static_cast<type&&>(object);
    }
  #endif

  // ...
  #if CPP_VERSION < 2011uL
    template <typename type>
    type instanceof() throw();
  #else
    template <typename type>
    constexpr type&& instanceof() noexcept;
  #endif

  // ...
  #if defined(__cpp_lib_launder) || (CPP_COMPILER == CPP__MSVC__COMPILER && defined(_HAS_LAUNDER)) || CPP_VERSION >= 2017uL
    using std::launder;
  #else
    template <typename type>
    inline type* launder(type* pointer) noexcept {
      #if CPP_COMPILER == CPP__CLANG__COMPILER || (CPP_COMPILER == CPP__GCC__COMPILER && defined(__has_builtin))
      # if __has_builtin(__builtin_launder)
        return __builtin_launder(pointer);
      # else
        return pointer;
      # endif
      #elif CPP_COMPILER == CPP__GCC__COMPILER
        // ->> Force compiler to assume `pointer` was modified because it is used as an input & output.
        __asm__("" : "+r"(pointer));
        return pointer;
      #elif CPP_COMPILER == CPP__MSVC__COMPILER && CPP_VENDOR == CPP__MICROSOFT_WINDOWS__VENDOR && defined(_ReadWriteBarrier)
        // ->> Prevent memory access re-ordering (relies on MSVC not having optimizations for `const` data members)
        _ReadWriteBarrier();
        return pointer;
      #else
        return pointer;
      #endif
    }
  #endif
}
