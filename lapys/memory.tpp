/* ... */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* Function > ... */
    // Heap + stack combo (realloc in place only) for capacity-based allocator

    template <typename base, std::size_t capacity>
    constfunc(false) typename conditional<is_void<base>::value, Allocation, base*>::type Allocator<base, capacity>::allocate(control_parameter const control, std::size_t const count) const volatile noexcept {
      constvar std::size_t const alignment = alignmentof(typeof((instanceof<typename conditional<is_void<type>::value, byte, type>::type>())));
      std::size_t          const size      = count * sizeof(typename conditional<is_void<base>::value, byte, base>::type);

      // ...
      if (false == Allocation::assertSize(size))
      return static_cast<base*>(NULL);

      if (control & Traits::EXECUTABLE) {
      this -> reserve(size + alignment);

        if (NULL == this -> heap) {
          this -> allocate(size + alignment);
          this -> heap = Memory::allocate(control, size + alignment + (3u * sizeof(Allocation)), alignmentof(Allocation));

          if (NULL == this -> heap)
          return static_cast<base*>(NULL);

          if (Allocation::KIND_INCOMPLETE_REFERENCE == Memory::inspectHeap(this -> heap) -> getKind()) {
            new (bit_cast<Allocation*>(this -> heap) + 0) Allocation(size + alignment + (3u * sizeof(Allocation)));
            new (bit_cast<Allocation*>(this -> heap) + 1) Allocation(size + alignment);
            new (bit_cast<byte*>(this -> heap) + size + alignment + sizeof(Allocation)) Allocation(0u);
          }

          else {
            new (this -> heap) Allocation(size + alignment);
            new (bit_cast<byte*>(this -> heap) + size + alignment) Allocation(0u);
          }

          return bit_cast<base*>(Memory::align(1 + new (this -> heap) Allocation(size), alignment, size, this -> heap));
        }

        else {
          Memory::inspect();
        }
      }

      // this -> heap
      // this -> stack
    }

    // ...
    // template <typename base, std::size_t capacity>
    // constfunc(true) typename conditional<is_void<base>::value, Allocation, base*>::type Allocator<base, capacity>::reallocate(control_parameter const, base* const, std::size_t const) const volatile noexcept;

    // ...
    // template <typename base, std::size_t capacity>
    // constfunc(true) bool Allocator<base, capacity>::release(base* const) const volatile noexcept;

    // template <typename base, std::size_t capacity>
    // constfunc(true) inline bool Allocator<base, capacity>::release(base* const, std::size_t const) const volatile noexcept;

    // ...
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
          void       *aligned = bit_cast<void*>(address);
          std::size_t space   = size + (bit_cast<byte*>(buffer) - bit_cast<byte*>(address));

          if (NULL != std::align(alignment, size, aligned, space)) {
            if (static_cast<byte*>(aligned) < bit_cast<byte*>(address) + alignment)
            return static_cast<typeA*>(aligned);
          }
        }
      #endif

      while (0u != static_cast<std::size_t>(bit_cast<byte*>(buffer) - bit_cast<byte*>(address)) % alignment)
      address = bit_cast<typeA*>(1 + bit_cast<byte*>(address));

      // ...
      static_cast<void>(size);
      return address;
    }

    // ...
    template <typename type>
    Allocation reallocate(type* const address, std::size_t const resize) noexcept {
      return Memory::reallocate(Traits::CLEARED, address, resize);
    }

    template <typename type>
    Allocation reallocate(control_parameter const control, type* const address, std::size_t resize) noexcept {
      if (NULL == address) return Memory::allocate(control, resize, alignmentof(typeof((instanceof<typename conditional<is_void<type>::value, byte, type>::type>()))));

      Allocation const *const metadata = Allocation::inspectHeap(address);
      Allocation::kind  const kind     = metadata -> getKind();
      std::size_t const size         = Allocation::KIND_INCOMPLETE_REFERENCE != kind ? metadata -> getSize() : 0u;
      void             *reallocation = NULL;
      std::size_t const offset       = Allocation::KIND_INCOMPLETE_REFERENCE == kind ? metadata -> getOffset() : 0u;
      void       *const allocation   = bit_cast<byte*>(metadata) - offset;

      // ...
      switch (kind) {
        case Allocation::C_STANDARD: {
          if (false == (control & Traits::EXECUTABLE) && false == (control & Traits::NON_DYNAMIC)) {
            reallocation = std::realloc(allocation, offset + resize);

            if (NULL != reallocation) {
              if ((control & Traits::CLEARED) && resize > size)
              std::memset(static_cast<typename uint_byte_t::type*>(reallocation) + offset + size, 0x0, resize - size);
            }
          }
        } break;

        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case Allocation::MICROSOFT_WINDOWS__HEAP: {
            if (false == (control & Traits::EXECUTABLE))
            reallocation = ::HeapReAlloc(Memory::getHeap(), (control & Traits::NON_DYNAMIC ? HEAP_REALLOC_IN_PLACE_ONLY : 0x0) | (control & Traits::CLEARED ? HEAP_ZERO_MEMORY : 0x0), allocation, offset + resize);
          } break;
        #endif

        default: break;
      }

      if (NULL != reallocation) {
        if (Allocation::KIND_INCOMPLETE_REFERENCE != kind)
        new (allocation) Allocation(kind, resize);

        return static_cast<byte*>(reallocation) + offset;
      }

      if (control & Traits::NON_DYNAMIC)
      return static_cast<void*>(NULL);

      // ...
      void *const readdress = Memory::reallocate(control, NULL, resize);

      if (NULL != readdress) {
        Allocation::CPP_STANDARD == Allocation::inspectHeap(readdress) -> getKind()
        ? std::uninitialized_copy(bit_cast<byte*>(address), bit_cast<byte*>(address) + resize, static_cast<byte*>(readdress))
        : std::memcpy(readdress, bit_cast<void*>(address), resize);

        Allocation::KIND_INCOMPLETE_REFERENCE != kind
        ? Allocation::release(address, size)
        : Allocation::release(address);
      }

      return readdress;
    }

    // ...
    template <typename type>
    bool release(type* const address) noexcept {
      if (NULL == address) return true;

      Allocation const *const metadata = Allocation::inspectHeap(address);
      Allocation::kind  const kind     = metadata -> getKind();
      std::size_t const offset     = Allocation::KIND_INCOMPLETE_REFERENCE == kind ? metadata -> getOffset() : 0u;
      void       *const allocation = bit_cast<byte*>(metadata) - offset;

      // ...
      switch (kind) {
        case Allocation::C_STANDARD: std::free(allocation); return true;
        case Allocation::CPP_STANDARD: ::operator delete(allocation, std::nothrow); return true;

        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case Allocation::MICROSOFT_WINDOWS__HEAP   : return FALSE != ::HeapFree(Memory::getHeap(), 0x0u, allocation);
          case Allocation::MICROSOFT_WINDOWS__VIRTUAL: return FALSE != ::VirtualFreeEx(::GetCurrentProcess(), allocation, 0u, MEM_RELEASE);
        #endif

        #if CPP_VENDOR & CPP__UNIX__VENDOR
          case Allocation::UNIX__MAPPED: {
            if (Allocation::KIND_INCOMPLETE_REFERENCE != kind)
            return 0 == ::munmap(allocation, metadata -> getSize() + offset);
          } break;
        #endif

        default: return false;
      }

      return false;
    }

    template <typename type>
    bool release(type* const address, std::size_t size) noexcept {
      if (NULL == address || 0u == size) return Memory::release(address);

      Allocation const *const metadata = Allocation::inspectHeap(address);
      Allocation::kind  const kind     = metadata -> getKind();
      std::size_t const offset     = Allocation::KIND_INCOMPLETE_REFERENCE == kind ? metadata -> getOffset() : 0u;
      void       *const allocation = bit_cast<byte*>(metadata) - offset;

      // ...
      switch (kind) {
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case Allocation::MICROSOFT_WINDOWS__VIRTUAL:
          return FALSE != ::VirtualFreeEx(::GetCurrentProcess(), allocation, offset + size, MEM_DECOMMIT);
        #endif

        #if CPP_VENDOR & CPP__UNIX__VENDOR
          case Allocation::UNIX__MAPPED:
          return 0 == ::munmap(allocation, offset + size);
        #endif

        default: return false;
      }

      return false;
    }
  }
}
