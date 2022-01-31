/* Import > ... */
#include "includes.hpp"

/* ... */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* Function > ... */
    allocated_t allocateHeap(std::size_t const size) noexcept {
      return Memory::allocateHeap(size, Math::minimum(Math::bit_ceil(size), static_cast<std::size_t>(LAPYS_MAX_BUILTIN_ALIGNMENT)));
    }

    allocated_t allocateHeap(std::size_t const size, std::size_t const alignment) noexcept {
      return Memory::allocateHeap(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), size, alignment);
    }

    allocated_t allocateHeap(control_parameter const control, std::size_t const size) noexcept {
      return Memory::allocateHeap(control, size, Math::minimum(Math::bit_ceil(size), static_cast<std::size_t>(LAPYS_MAX_BUILTIN_ALIGNMENT)));
    }

    allocated_t allocateHeap(control_parameter const control, std::size_t size, std::size_t const alignment) noexcept {
      if (0u == size)
      return static_cast<void*>(NULL);

      // ...
      void *allocation = NULL;

      size += sizeof(allocation_information);

      // ...
      #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
        if (control & Traits::EXECUTABLE) {
          allocation = ::VirtualAllocEx(::GetCurrentProcess(), static_cast<LPVOID>(NULL), size + alignment, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
          if (NULL != allocation) return Memory::align(1 + new (allocation) allocation_information(Memory::MICROSOFT_WINDOWS__VIRTUAL, size + alignment), alignment, size, allocation);
        }

        else {
          HANDLE const heap = Memory::getHeap();

          // ...
          if (NULL != heap) allocation = ::HeapAlloc(heap, control & Traits::ZERO ? HEAP_ZERO_MEMORY : 0x0u, size + (alignment * (MEMORY_ALLOCATION_ALIGNMENT != alignment)));
          if (NULL != allocation) return Memory::align(1 + new (allocation) allocation_information(Memory::MICROSOFT_WINDOWS__HEAP), alignment, size, allocation);

          allocation = ::VirtualAllocEx(::GetCurrentProcess(), static_cast<LPVOID>(NULL), size + alignment, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
          if (NULL != allocation) return Memory::align(1 + new (allocation) allocation_information(Memory::MICROSOFT_WINDOWS__VIRTUAL, size + alignment), alignment, size, allocation);
        }
      #endif

      #if CPP_VENDOR & CPP__UNIX__VENDOR
        allocation = ::mmap(NULL, size, PROT_READ | PROT_WRITE | (control & Traits::EXECUTABLE ? PROT_EXEC : 0x0), MAP_ANONYMOUS | MAP_PRIVATE, -1, 0L);
        if (NULL != allocation) return Memory::align(1 + new (allocation) allocation_information(Memory::UNIX, size), alignment, size + alignment, allocation);
      #endif

      if (control & Traits::EXECUTABLE)
      return static_cast<void*>(NULL);

      if (control & Traits::ZERO) {
        allocation = std::calloc(size + (alignment * (LAPYS_MAX_BUILTIN_ALIGNMENT != alignment)), sizeof(byte));
        if (NULL != allocation) return Memory::align(1 + new (allocation) allocation_information(Memory::C_STANDARD), alignment, size, allocation);
      }

      allocation = std::malloc(size + (alignment * (LAPYS_MAX_BUILTIN_ALIGNMENT != alignment)));
      if (NULL != allocation) {
        if (control & Traits::ZERO) std::memset(allocation, 0x0, size);
        return Memory::align(1 + new (allocation) allocation_information(Memory::C_STANDARD), alignment, size, allocation);
      }

      allocation = ::operator new(size + alignment, std::nothrow); // --> % __STDCPP_DEFAULT_NEW_ALIGNMENT__
      if (NULL != allocation) {
        if (control & Traits::ZERO) std::fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0));
        return Memory::align(1 + new (allocation) allocation_information(Memory::CPP_STANDARD), alignment, size, allocation);
      }

      // ...
      return allocation;
    }
  }
}
