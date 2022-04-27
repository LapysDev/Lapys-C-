// /* Import > ... */
// #include "includes.hpp"

// /* ... */
// namespace Lapys {
//   /* Namespace */
//   namespace Memory {
//     /* Function > ... */
//     void* allocate(std::size_t const size) noexcept {
//       return Memory::allocate(AUTOMATIC, size, 0u);
//     }

//     void* allocate(std::size_t const size, std::size_t const alignment) noexcept {
//       return Memory::allocate(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), size, alignment);
//     }

//     void* allocate(control_parameter const control, std::size_t const size) noexcept {
//       return Memory::allocate(Traits::AUTOMATIC | control, size, 0u);
//     }

//     void* allocate(control_parameter control, std::size_t size, std::size_t const alignment) noexcept {
//       if ((0u == size) || (0u == alignment && false == (control & Traits::AUTOMATIC)) || (alignment > size)) return NULL;

//       void *allocation = NULL;
//       Allocation::kind kind = static_cast<Allocation::kind>(0x0u);

//       // ...
//       size += sizeof(byte) + sizeof(Allocation) + (alignment == sizeof(Allocation) ? 0u : alignment);
//       do {
//         #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
//           if (control & Traits::EXECUTABLE) {
//             allocation = ::VirtualAllocEx(::GetCurrentProcess(), static_cast<LPVOID>(NULL), size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
//             if (NULL != allocation) { kind = Allocation::MICROSOFT_WINDOWS__VIRTUAL; break; }
//           }

//           else {
//             HANDLE const heap = Memory::getHeap();

//             // ...
//             if (NULL != heap) allocation = ::HeapAlloc(heap, control & Traits::CLEARED ? HEAP_ZERO_MEMORY : 0x0u, size); // --> % MEMORY_ALLOCATION_ALIGNMENT
//             if (NULL != allocation) { kind = Allocation::MICROSOFT_WINDOWS__HEAP; break; }

//             allocation = ::VirtualAllocEx(::GetCurrentProcess(), static_cast<LPVOID>(NULL), size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
//             if (NULL != allocation) { kind = Allocation::MICROSOFT_WINDOWS__VIRTUAL; break; }
//           }
//         #endif

//         // ...
//         #if CPP_VENDOR & CPP__UNIX__VENDOR
//           if (false == (control & Traits::EXECUTABLE)) {
//             allocation = ::aligned_alloc(alignmentof(Allocation), size);
//             if (NULL != allocation) { kind = Allocation::C_STANDARD; if (control & Traits::CLEARED) { std::memset(allocation, 0x0, size); } break; }
//           }
//           allocation = ::mmap(NULL, size, PROT_READ | PROT_WRITE | (control & Traits::EXECUTABLE ? PROT_EXEC : 0x0), MAP_ANONYMOUS | MAP_PRIVATE, -1, 0L)
//           if (NULL != allocation) { kind = Allocation::UNIX__MAPPED; break; }
//         #endif

//         // ...
//         if (control & Traits::EXECUTABLE)
//         return static_cast<void*>(NULL);

//         // ...
//         #if CPP_VERSION >= 2017uL
//           allocation = std::aligned_alloc(alignmentof(Allocation), size);
//           if (NULL != allocation) { kind = Allocation::C_STANDARD; if (control & Traits::CLEARED) { std::memset(allocation, 0x0, size); } break; }
//         #endif

//         if (control & Traits::CLEARED) {
//           allocation = std::calloc(size, sizeof(byte)); // --> % alignof(std::max_align_t)
//           if (NULL != allocation) { kind = Allocation::C_STANDARD; break; }
//         }

//         allocation = std::malloc(size); // --> % alignof(std::max_align_t)
//         if (NULL != allocation) { kind = Allocation::C_STANDARD; if (control & Traits::CLEARED) { std::memset(allocation, 0x0, size); } break; }

//         // ...
//         #if CPP_VERSION >= 2017uL
//           allocation = ::operator new(size, static_cast<std::align_val_t>(alignmentof(Allocation)), std::nothrow);
//           if (NULL != allocation) { kind = Allocation::CPP_STANDARD; if (control & Traits::CLEARED) { std::uninitialized_fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0u)); } break; }
//         #endif

//         #ifdef __STDCPP_DEFAULT_NEW_ALIGNMENT__
//           allocation = ::operator new(size, std::nothrow); // --> % __STDCPP_DEFAULT_NEW_ALIGNMENT__
//           if (NULL != allocation) { kind = Allocation::CPP_STANDARD; if (control & Traits::CLEARED) { std::uninitialized_fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0u)); } break; }
//         #else
//           allocation = ::operator new(size, std::nothrow);
//           if (NULL != allocation) { kind = Allocation::CPP_STANDARD; if (control & Traits::CLEARED) { std::uninitialized_fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0u)); } break; }
//         #endif
//       } while (false);

//       if (NULL == allocation)
//       return static_cast<void*>(NULL);

//       ~(1u << CHAR_BIT)

//       widthof<byte>::value

//       // ...
//       byte *const address = Memory::align(new (new (allocation) Allocation(kind, size) + 1) byte(0u) + 1, alignment, size - sizeof(Allocation), allocation);
//       std::ptrdiff_t offset = address - (static_cast<byte*>(allocation) + sizeof(Allocation) + sizeof(byte) + 1);

//       PTRDIFF_MAX >> widthof<typename uint_byte_t::type>::value
//       for (byte const *metadata = address; offset; offset >>= widthof<typename uint_byte_t::type>::value)
//       *--metadata = offset & ~(~0u << widthof<typename uint_byte_t::type>::value);

//       return address;
//     }
//   }
// }
