/* ... */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* Function > ... */
    template <typename type>
    type* align(type* const address, std::size_t const alignment, std::size_t const size) noexcept {
      return Memory::align(address, alignment, size, address);
    }

    template <typename typeA, typename typeB>
    typeA* align(typeA* address, std::size_t const alignment, std::size_t const size, typeB* const buffer) noexcept {
      if (alignment == alignmentof(byte))
      return address;

      // ...
      #if CPP_VERSION >= 2011uL
        if (0u != alignment && 0u == (alignment & (alignment - 1u))) {
          void       *aligned = const_cast<void*>(static_cast<void const volatile*>(address));
          std::size_t space   = size + (static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(buffer))) - static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))));

          if (NULL != std::align(alignment, size, aligned, space)) {
            if (static_cast<byte*>(aligned) < static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))) + alignment)
            return static_cast<typeA*>(aligned);
          }
        }
      #endif

      while (0u != static_cast<std::size_t>(static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(buffer))) - static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address)))) % alignment)
      address = static_cast<typeA*>(static_cast<void*>(1 + static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address)))));

      // ...
      static_cast<void>(size);
      return address;
    }

    // ...
    template <typename type>
    Allocation reallocateHeap(type* const address, std::size_t const resize) noexcept {
      return Memory::reallocateHeap(Traits::ZERO, address, resize);
    }

    template <typename type>
    Allocation reallocateHeap(control_parameter const control, type* const address, std::size_t resize) noexcept {
      if (NULL == address) return Memory::allocateHeap(control, resize, alignmentof(typeof((instanceof<typename conditional<is_void<type>::value, byte, type>::type>()))));
      Allocation const *const metadata = Allocation::inspectHeap(address);

      if (NULL == metadata) return static_cast<void*>(NULL);
      Allocation::kind const kind = metadata -> getKind();
      void       *const allocation   = static_cast<byte*>(const_cast<void*>(static_cast<void const*>(metadata))) - (Allocation::KIND_INCOMPLETE_REFERENCE == kind ? metadata -> getOffset() : 0u);
      std::size_t const offset       = static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))) - static_cast<byte*>(allocation);
      void             *reallocation = NULL;
      std::size_t const size         = Allocation::KIND_INCOMPLETE_REFERENCE != kind ? metadata -> getSize() : 0u;

      // ...
      switch (kind) {
        case Allocation::C_STANDARD:
        case Allocation::UNIX__ALIGNED: {
          if (false == (control & Traits::EXECUTABLE)) {
            reallocation = std::realloc(allocation, offset + resize);

            if (NULL != reallocation && (control & Traits::ZERO) && resize > size)
            std::memset(static_cast<typename byte::type*>(reallocation) + offset + size, 0x0, resize - size);
          }
        } break;
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case Allocation::MICROSOFT_WINDOWS__HEAP: {
            if (false == (control & Traits::EXECUTABLE))
            reallocation = ::HeapReAlloc(Memory::getHeap(), control & Traits::ZERO ? HEAP_ZERO_MEMORY : 0x0, allocation, offset + resize);
          } break;
        #endif
        default: break;
      }

      if (NULL != reallocation)
      return static_cast<byte*>(reallocation) + offset;

      // ...
      void             *const readdress  = Memory::allocateHeap(control, resize, alignmentof(typeof((instanceof<typename conditional<is_void<type>::value, byte, type>::type>()))));
      Allocation const *const remetadata = Allocation::inspectHeap(reallocation);

      if (NULL != readdress) {
        #if LAPYS_DEBUG
          if (NULL == remetadata) {
            Memory::releaseHeap(readdress, resize);
            return static_cast<void*>(NULL);
          }
        #endif

        Allocation::CPP_STANDARD == remetadata -> getKind()
        ? std::uninitialized_copy(static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))), static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))) + Math::minimum(resize, size), static_cast<byte*>(readdress))
        : std::memcpy(readdress, const_cast<void*>(static_cast<void const volatile*>(address)), Math::minimum(resize, size));
      }

      return readdress;
    }

    // ...
    template <typename type>
    bool releaseHeap(type* const address) noexcept {
      if (NULL == address) return true;
      Allocation const *const metadata = Allocation::inspectHeap(address);

      if (NULL == metadata) return false; // WARN (Lapys) -> Leaked memory
      Allocation::kind const kind = metadata -> getKind();
      void *const allocation = static_cast<byte*>(const_cast<void*>(static_cast<void const*>(metadata))) - (Allocation::KIND_INCOMPLETE_REFERENCE == kind ? metadata -> getOffset() : 0u);

      // ...
      switch (kind) {
        case Allocation::C_STANDARD: case Allocation::UNIX__ALIGNED: std::free(allocation); return true;
        case Allocation::CPP_STANDARD: ::operator delete(allocation, std::nothrow); return true;
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case Allocation::MICROSOFT_WINDOWS__HEAP   : return FALSE != ::HeapFree(Memory::getHeap(), 0x0u, allocation);
          case Allocation::MICROSOFT_WINDOWS__VIRTUAL: return FALSE != ::VirtualFreeEx(::GetCurrentProcess(), allocation, 0u, MEM_RELEASE);
        #endif
        #if CPP_VENDOR & CPP__UNIX__VENDOR
          case Allocation::UNIX__MAPPED: {
            std::size_t const offset = static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))) - static_cast<byte*>(allocation);
            std::size_t const size   = Allocation::KIND_INCOMPLETE_REFERENCE != kind ? metadata -> getSize() : 0u;

            return 0u != size && 0 == ::munmap(allocation, offset + size);
          } break;
        #endif
        default: return false;
      }

      return false;
    }

    template <typename type>
    bool releaseHeap(type* const address, std::size_t size) noexcept {
      if (NULL == address || 0u == size) return Memory::releaseHeap(address);
      Allocation const *const metadata = Allocation::inspectHeap(address);

      if (NULL == metadata) return false; // WARN (Lapys) -> Leaked memory
      Allocation::kind const kind = metadata -> getKind();
      void       *const allocation = static_cast<byte*>(const_cast<void*>(static_cast<void const*>(metadata))) - (Allocation::KIND_INCOMPLETE_REFERENCE == kind ? metadata -> getOffset() : 0u);
      std::size_t const offset     = static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))) - static_cast<byte*>(allocation);

      // ...
      switch (kind) {
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case Allocation::MICROSOFT_WINDOWS__VIRTUAL: return FALSE != ::VirtualFreeEx(::GetCurrentProcess(), allocation, offset + size, MEM_DECOMMIT);
        #endif
        #if CPP_VENDOR & CPP__UNIX__VENDOR
          case Allocation::UNIX__MAPPED: return 0 == ::munmap(allocation, offset + size);
        #endif
        default: return false;
      }

      return false;
    }
  }
}
