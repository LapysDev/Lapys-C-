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
    // template <typename type>
    // noignore allocated_t reallocateHeap(type* const address, std::size_t const size) noexcept {
    //   if (NULL == address)
    //   return Memory::allocateHeap(size, alignmentof(type));

    //   // ...
    //   allocation_information const *const allocation = static_cast<allocation_information const*>(const_cast<void*>(static_cast<void const volatile*>(address))) - 1;

    //   switch (allocation -> getParameter()) {
    //     case Memory::C_STANDARD: return std::realloc(allocation, size);
    //     #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
    //       case Memory::MICROSOFT_WINDOWS__HEAP: return ::HeapReAlloc(Memory::getHeap(), HEAP_ZERO_MEMORY, allocation, size);
    //     #endif
    //     default: {
    //       type *const readdress = Memory::allocateHeap(size, alignmentof(type));
    //       if (NULL == readdress) return static_cast<type*>(NULL);

    //       std::size_t previousSize = allocation -> getSize();
    //       if (0u == previousSize) return Memory::releaseHeap(readdress), static_cast<type*>(NULL);

    //       // ...
    //       Memory::CPP_STANDARD == allocation -> getParameter()
    //       ? std::uninitialized_copy(static_cast<byte*>(static_cast<void*>(address)), static_cast<byte*>(static_cast<void*>(address)) + Math::minimum(static_cast<std::size_t>(size), previousSize - sizeof(allocation_information)), static_cast<byte*>(static_cast<void*>(readdress)))
    //       : std::memcpy(readdress, address, Math::minimum(static_cast<std::size_t>(size), previousSize - sizeof(allocation_information)));

    //       if (false == Memory::releaseHeap(allocation))
    //       return Memory::releaseHeap(readdress), static_cast<type*>(NULL);

    //       return readdress;
    //     } break;
    //   }

    //   return static_cast<type*>(NULL);
    // }

    // ...
    template <typename type>
    bool releaseHeap(type* const address) noexcept {
      if (NULL == address) return true;
      Allocation const *const metadata = Allocation::inspectHeap(address);

      if (NULL == metadata) return false; // WARN (Lapys) -> Leaked memory
      Allocation::kind const kind       = metadata -> getKind();
      void            *const allocation = static_cast<byte*>(const_cast<void*>(static_cast<void const*>(metadata))) - (Allocation::KIND_INCOMPLETE_REFERENCE == kind ? metadata -> getOffset() : 0u);

      // ...
      switch (kind) {
        case Allocation::C_STANDARD: case Allocation::UNIX__ALIGNED: std::free(allocation); return true;
        case Allocation::CPP_STANDARD: ::operator delete(allocation, std::nothrow); return true;
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case Allocation::MICROSOFT_WINDOWS__HEAP   : return FALSE != ::HeapFree(Memory::getHeap(), 0x0u, allocation);
          case Allocation::MICROSOFT_WINDOWS__VIRTUAL: return FALSE != ::VirtualFreeEx(::GetCurrentProcess(), allocation, 0u, MEM_RELEASE);
        #endif
        #if CPP_VENDOR & CPP__UNIX__VENDOR
          case Allocation::UNIX__MAPPED: std::size_t const size = Allocation::KIND_INCOMPLETE_REFERENCE != kind ? metadata -> getSize() : 0u; return 0u != size && 0 == ::munmap(allocation, size);
        #endif
        default: return false;
      }

      return false;
    }

    template <typename type> // UPDATE (Lapys) -> `size` must match `Allocation::getSize()`
    bool releaseHeap(type* const address, std::size_t size) noexcept {
      if (NULL == address || 0u == size) return Memory::releaseHeap(address);
      Allocation const *const metadata = Allocation::inspectHeap(address);

      if (NULL == metadata) return false; // WARN (Lapys) -> Leaked memory
      Allocation::kind const kind       = metadata -> getKind();
      void            *const allocation = static_cast<byte*>(const_cast<void*>(static_cast<void const*>(metadata))) - (Allocation::KIND_INCOMPLETE_REFERENCE == kind ? metadata -> getOffset() : 0u);

      // ...
      size += alignmentof(Allocation) + sizeof(Allocation);
      switch (kind) {
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case Allocation::MICROSOFT_WINDOWS__VIRTUAL: return FALSE != ::VirtualFreeEx(::GetCurrentProcess(), allocation, size, MEM_DECOMMIT);
        #endif
        #if CPP_VENDOR & CPP__UNIX__VENDOR
          case Allocation::UNIX__MAPPED: return 0 == ::munmap(allocation, size);
        #endif
        default: return false;
      }

      return false;
    }
  }
}
