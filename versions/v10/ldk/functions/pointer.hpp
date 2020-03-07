/* Function */
    // Copy
    template <typename typeA, typename typeB>
    inline void pointer__copy(typeA*& pointer, typeB* sourcePointer, const std::size_t size) noexcept { ::memcpy(pointer, (void*) sourcePointer, size); }

    // Create Array
    template <const std::size_t length, typename type>
    template <typename... types>
    constexpr inline pointer__create_array<length, type>::pointer__create_array(types... arguments) : value{new type[length]{arguments...}} {}

    // Create Object
    template <typename type>
    template <typename... types>
    constexpr inline pointer__create_object<type>::pointer__create_object(types... arguments) : value{new type{arguments...}} {}

    // Delete Array
    template <typename type>
    constexpr inline void pointer__delete_array(type* array) noexcept { delete[] array; }

    // Delete Object
    template <typename type>
    constexpr inline void pointer__delete_object(type* object) noexcept { delete object; }

    // Get Allocation Size
    inline std::size_t pointer__get_allocation_size(const std::size_t size) noexcept {
        // Initialization > Allocation Size
        std::size_t allocationSize = 2u;
        std::size_t recentAllocationSize;

        // Update > ... Allocation Size
        while (allocationSize < size) {
            recentAllocationSize = allocationSize;
            allocationSize <<= 1u;
        } allocationSize = recentAllocationSize;

        // Logic
        if (allocationSize < size) {
            // Constant > System Page Size
            const std::size_t systemPageSize = LDKF::system__get_page_size();

            // Logic > Loop > Update > Allocation Size
            if (allocationSize < systemPageSize) while (allocationSize < size) allocationSize += sizeof(std::size_t);
            else while (allocationSize < size) allocationSize += systemPageSize;
        }

        // (Loop > )Update > Allocation Size
        if (allocationSize > sizeof(std::size_t)) { allocationSize -= sizeof(std::size_t); if (allocationSize < size) allocationSize += sizeof(std::size_t); }
        while (allocationSize % sizeof(unsigned char)) ++allocationSize;

        // Return
        return allocationSize;
    }

    // Heap Allocate
    constexpr inline pointer__heap_allocate::pointer__heap_allocate(const std::size_t size, const bool STRICT_SIZE) : value{(const void*) ::malloc(STRICT_SIZE ? size : LDKF::pointer__get_allocation_size(size))} {}

    // Heap Contiguous Allocate
    template <typename type>
    inline pointer__heap_contiguous_allocate::pointer__heap_contiguous_allocate_structure::operator type*(void) const noexcept { return ::calloc(this -> size / sizeof(type), sizeof(type)); }

    // Heap Free
    template <typename type>
    inline void pointer__heap_free(type* pointer) noexcept { ::free(pointer); }

    // Heap Map
    #if ldk__detected_platform == ldk_platform__android || ldk__detected_platform == ldk_platform__linux
        inline pointer__map::pointer__map(const std::size_t size, const bool STRICT_SIZE) : value{(const void*) ::mmap(NULL, size ? (STRICT_SIZE ? size : LDKF::pointer__get_allocation_size(size)) : 2u, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)} {}
    #elif ldk__detected_platform == ldk_platform__windows
        inline pointer__map::pointer__map(const std::size_t size, const bool STRICT_SIZE) : value{NULL} { const std::size_t systemPageSize = LDKF::system__get_page_size(); this -> value = ::VirtualAlloc(0x0, size < systemPageSize ? (STRICT_SIZE ? size : LDKF::pointer__get_allocation_size(size)) : systemPageSize, MEM_COMMIT, PAGE_READWRITE); }
    #endif

    // Heap Reallocate
    template <typename type>
    constexpr inline pointer__heap_reallocate::pointer__heap_reallocate(type* pointer, const std::size_t size, const bool STRICT_SIZE) : value{(const void*) ::realloc(pointer, STRICT_SIZE ? size : LDKF::pointer__get_allocation_size(size))} {}

    // Heap Unmap --- NOTE (Lapys) -> Unlike freeing memory, un-mapping memory requires a size parameter (to assert how much memory is un-mapped).
    #if ldk__detected_platform == ldk_platform__android || ldk__detected_platform == ldk_platform__linux
        template <typename type>
        inline void pointer__unmap(type* pointer, const std::size_t size) noexcept { ::munmap(pointer, size); }
    #elif ldk__detected_platform == ldk_platform__windows
        template <typename type>
        inline void pointer__unmap(type* pointer, const std::size_t size) noexcept { ::VirtualFree(pointer, size, MEM_RELEASE); }
    #endif

    // Stack Allocate
    inline pointer__stack_allocate::pointer__stack_allocate(const std::size_t size, const bool STRICT_SIZE) :
        #if ldk__detected_platform == ldk_platform__android || ldk__detected_platform == ldk_platform__linux
            value{(const void*) ::alloca(STRICT_SIZE ? size : LDKF::pointer__get_allocation_size(size))}
        #elif ldk__detected_platform == ldk_platform__windows
            value{(const void*) ::_malloca(STRICT_SIZE ? size : LDKF::pointer__get_allocation_size(size))}
        #endif
    {}

    // Stack Free
    template <typename type>
    inline void pointer__stack_free(type* pointer) noexcept {
        // Logic > Deletion
        #if ldk__detected_platform == ldk_platform__windows
            ::_freea(pointer);
        #endif
    }

    // Stack Reallocate
    template <typename type>
    constexpr inline pointer__stack_reallocate::pointer__stack_reallocate(type* pointer, const std::size_t size, const bool STRICT_SIZE) : value{NULL} { type *pointerCopy; LDKF::pointer__copy(pointerCopy, pointer, size); LDKF::pointer__stack_free(pointer); LDKF::pointer__copy(pointer, pointerCopy, size); LDKF::pointer__stack_free(pointerCopy); this -> value = pointer; }

    // To Number
    template <typename type>
    inline int pointer__to_number(type* pointer) noexcept { return pointer; }

    // To String
    template <typename type>
    inline const char* pointer__to_string(type* pointer) noexcept {
        // Evaluation > Character String
        char *characterString;

        // Initialization > Pointer (Address, Size)
        int pointerAddress = LDKF::pointer__to_number(pointer);
        const unsigned char pointerSize = sizeof(void*);

        // Update > Character String
        characterString = LDKF::pointer__heap_allocate((pointerSize + 3u) * sizeof(char));

        *characterString = '0';
        (characterString + 1) = 'x';
        (characterString + (pointerSize + 2u)) = '\0';

        // Loop > Update > (Character String, ...)
        for (unsigned char iterator = 0u; iterator ^ pointerSize; ++iterator) {
            *(characterString + ((pointerSize + 1u) - iterator)) = pointerAddress % 10;
            pointerAddress /= 10;
        }

        // Return
        return characterString;
    }
