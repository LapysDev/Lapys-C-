/* Modification */
    // Heap ...
    template <class type, size_t length, class... types> constexpr inline type* Memory::heap_contiguous_create(types... arguments) { return new type[length] {arguments...}; }
    template <class type> constexpr inline type* Memory::heap_contiguous_delete(type* const buffer) noexcept { delete[] buffer; return NULL; }
    template <class type, class... types> constexpr inline type* Memory::heap_create(types... arguments) { return new type {arguments...}; }
    template <class type> constexpr inline type* Memory::heap_delete(type* const buffer) noexcept { delete buffer; return NULL; }
    template <class type> constexpr inline type* Memory::heap_free(type* const buffer) noexcept { ::free(buffer); return NULL; }

    // Heap ... > [Constructor]
    constexpr inline Memory::heap_allocator::heap_allocator(size_t const size) : memory__interface(::malloc(size)) {}
    template <class type> constexpr inline Memory::heap_reallocator::heap_reallocator(type* const buffer, size_t const size) : memory__interface(::realloc(buffer, size)) {}

    // Heap Map ...
    constexpr inline Memory::heap_mapper::heap_mapper(size_t const size) : memory__interface(heap_mapper::heap_map()) {}
    constexpr inline void* Memory::heap_mapper::heap_map(size_t const size) {
        // Logic > ... Return
        #if environment__is_windows
            return ::VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_NOCACHE /* ? */);
        #else
            int const descriptor = ::open("/dev/zero", O_RDWR);
            void *const evaluation = ::mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, descriptor, 0);
            ::close(descriptor);
            return MAP_FAILED == evaluation ? NULL : evaluation;
        #endif
    }

    // Heap Unmap
    template <class type>
    constexpr inline type* heap_unmap(type *const buffer, size_t const size) {
        // Logic > Return
        #if environment__is_windows
            return FALSE == ::VirtualFree(buffer, 0, MEM_RELEASE) ? buffer : NULL;
        #else
            return ::munmap(buffer, size) == -1 ? buffer : NULL;
        #endif
    }

    // Memory Interface > ...
    void *memory__interface::value = NULL;

    constexpr inline Memory::memory__interface::memory__interface(void* const buffer) { memory__interface::value = buffer; }
    template <class type> constexpr inline Memory::memory__interface::operator type*(void) const noexcept { return (type*) this -> value; }
