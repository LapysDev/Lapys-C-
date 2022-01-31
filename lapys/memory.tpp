/* ... */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* Function > ... */
    template <typename type>
    type* align(type* const address, std::size_t const alignment, std::size_t const size) noexcept {
      return Memory::align(address, alignment, size, address);
    }

    template <typename type>
    type* align(type* address, std::size_t const alignment, std::size_t size, type* const buffer) noexcept {
      if (alignment == alignmentof(byte))
      return address;

      // ...
      #if CPP_VENDOR & CPP__UNIX__VENDOR
        if (0u != alignment && 0u == (alignment & (alignment - 1u))) {
          void *aligned = address;

          if (0x0 == ::posix_memalign(&aligned, alignment, size))
          return static_cast<type*>(aligned);
        }
      #endif

      #if CPP_VERSION >= 2011uL
        if (0u != alignment && 0u == (alignment & (alignment - 1u))) {
          void *aligned = address;

          if (NULL != std::align(alignment, size, aligned, size))
          return static_cast<type*>(aligned);
        }
      #endif

      if (0 == static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(buffer))) - static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))))
      return static_cast<type*>(alignment + static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))));

      while (0u != (static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(buffer))) - static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address)))) % alignment)
      address = 1 + static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address)));

      // ...
      static_cast<void>(size);
      return static_cast<type*>(address);
    }

    // ...
    template <typename type>
    void releaseHeap(type* const pointer) noexcept {
      static_cast<void>(pointer);
    }
  }
}
