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
    typeA* align(typeA* address, std::size_t const alignment, std::size_t size, typeB* const buffer) noexcept {
      if (alignment == alignmentof(byte))
      return address;

      // ...
      #if CPP_VENDOR & CPP__UNIX__VENDOR
        if (0u != alignment && 0u == (alignment & (alignment - 1u))) {
          void *aligned = address;

          if (0x0 == ::posix_memalign(&aligned, alignment, size))
          return static_cast<typeA*>(aligned);
        }
      #endif

      #if CPP_VERSION >= 2011uL
        if (0u != alignment && 0u == (alignment & (alignment - 1u))) {
          void *aligned = address;

          if (NULL != std::align(alignment, size, aligned, size))
          return static_cast<typeA*>(aligned);
        }
      #endif

      if (0 == static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(buffer))) - static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))))
      return static_cast<typeA*>(static_cast<void*>(alignment + static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address)))));

      while (0u != (static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(buffer))) - static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address)))) % alignment)
      address = static_cast<typeA*>(static_cast<void*>(1 + static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address)))));

      // ...
      static_cast<void>(size);
      return static_cast<typeA*>(address);
    }

    // ...
    template <typename type>
    bool releaseHeap(type* const pointer) noexcept {
      if (NULL == pointer)
      return true;

      // ...
      allocation_information *const allocation = static_cast<allocation_information*>(const_cast<void*>(static_cast<void const volatile*>(pointer))) - 1;

      switch (allocation -> getParameter()) {
        case C_STANDARD                : return std::free(allocation), true;
        case CPP_STANDARD              : return ::operator delete(allocation, std::nothrow), true;
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case MICROSOFT_WINDOWS__HEAP   : return FALSE != ::HeapFree(Memory::getHeap(), 0x0u, allocation);
          case MICROSOFT_WINDOWS__VIRTUAL: return FALSE != ::VirtualFreeEx(::GetCurrentProcess(), allocation, 0u, MEM_RELEASE); // --> NULL != allocation
        #endif
        #if CPP_VENDOR & CPP__UNIX__VENDOR
          case UNIX: std::size_t const size = allocation -> getSize(); return 0u != size && 0 == ::munmap(allocation, size);
        #endif
        default: break;
      }

      return false;
    }

    template <typename type>
    bool releaseHeap(type* const pointer, std::size_t const size) noexcept {
      if (NULL == pointer) return true;
      if (0u   == size)    return Memory::releaseHeap(pointer);

      // ...
      allocation_information *const allocation = static_cast<allocation_information*>(const_cast<void*>(static_cast<void const volatile*>(pointer))) - 1;

      switch (allocation -> getParameter()) {
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          case MICROSOFT_WINDOWS__VIRTUAL: return FALSE != ::VirtualFreeEx(::GetCurrentProcess(), allocation, size, MEM_DECOMMIT); // --> NULL != allocation
        #endif
        #if CPP_VENDOR & CPP__UNIX__VENDOR
          case UNIX: return 0 == ::munmap(allocation, size);
        #endif
        default: return Memory::releaseHeap(pointer);
      }

      return false;
    }
  }
}
