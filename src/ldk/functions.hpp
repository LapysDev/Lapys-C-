/* Declaration > ... */
inline void array__at() noexcept;
inline void array__clone() noexcept;
inline void array__copy() noexcept;
inline void array__create() noexcept;
inline void array__cut() noexcept;
inline void array__cut_from_end() noexcept;
inline void array__cut_from_start() noexcept;
inline void array__free() noexcept;
inline void array__index() noexcept;
inline void array__index_from_end() noexcept;
inline void array__index_from_start() noexcept;
inline void array__pop() noexcept;
inline void array__push() noexcept;
inline void array__remove() noexcept;
inline void array__replace() noexcept;
inline void array__resize() noexcept;
inline void array__slice() noexcept;

inline void number__is_denormalized() noexcept;
inline void number__is_finite() noexcept;
inline void number__is_indeterminate() noexcept;
inline void number__is_infinite() noexcept;
inline void number__is_nan() noexcept;
inline void number__to_string() noexcept;

template <typename typeA, typename typeB> inline void pointer__copy(typeA*, typeB*, const std::size_t) noexcept;
inline std::size_t pointer__get_allocation_size(const std::size_t) noexcept;
struct pointer__heap_allocate { private: void *value; public: constexpr inline pointer__heap_allocate(const std::size_t, const bool = false); template <typename type> inline operator type*(void) const noexcept { return this -> value; } };
struct pointer__heap_contiguous_allocate { public:
    struct pointer__heap_contiguous_allocate_structure {
        private: const std::size_t size;
        public:
            constexpr inline pointer__heap_contiguous_allocate_structure(const std::size_t size) : size{size} {}
            template <typename type> inline operator type*(void) const noexcept;
    };
    constexpr inline pointer__heap_contiguous_allocate(void) {}
    inline pointer__heap_contiguous_allocate_structure operator ()(const std::size_t size, const bool STRICT_SIZE = false) const noexcept { return STRICT_SIZE ? size : LDKF::pointer__get_allocation_size(size); }
} pointer__heap_contiguous_allocate;
template <typename type> inline void pointer__heap_free(type*) noexcept;
struct pointer__map { private: void *value; public: inline pointer__map(const std::size_t, const bool = false); template <typename type> inline operator type*(void) const noexcept { return this -> value; } };
struct pointer__heap_reallocate { private: void *value; public: template <typename type> constexpr inline pointer__heap_reallocate(type*, const std::size_t, const bool = false); template <typename type> inline operator type*(void) const noexcept { return this -> value; } };
template <typename type> inline void pointer__unmap(type*, const std::size_t = 0u) noexcept;
struct pointer__stack_allocate { private: void *value; public: inline pointer__stack_allocate(const std::size_t, const bool = false); template <typename type> inline operator type*(void) const noexcept { return this -> value; } };
template <typename type> inline void pointer__stack_free(type*) noexcept;
struct pointer__stack_reallocate { private: void *value; public: template <typename type> constexpr inline pointer__stack_reallocate(type*, const std::size_t, const bool = false); template <typename type> inline operator type*(void) const noexcept { return this -> value; } };
template <typename type> inline int pointer__to_number(type*) noexcept;
template <typename type> inline const char* pointer__to_string(type*) noexcept;

inline void string__at() noexcept;
inline void string__clone() noexcept;
inline void string__concatenate() noexcept;
inline void string__copy() noexcept;
inline void string__cut() noexcept;
inline void string__cut_from_end() noexcept;
inline void string__cut_from_start() noexcept;
inline void string__free() noexcept;
inline void string__index() noexcept;
inline void string__index_from_end() noexcept;
inline void string__index_from_start() noexcept;
inline void string__length() noexcept;
inline void string__slice() noexcept;
inline void string__source_concatenate() noexcept;
inline void string__remove() noexcept;
inline void string__replace() noexcept;
inline void string__to_character_string() noexcept;
inline void string__to_number() noexcept;
inline void string__to_signed_character_string() noexcept;
inline void string__to_utf8_character_string() noexcept;
inline void string__to_utf16_character_string() noexcept;
inline void string__to_utf32_character_string() noexcept;
inline void string__to_unsigned_character_string() noexcept;
inline void string__to_wide_character_string() noexcept;

inline std::size_t system__get_page_size(void) noexcept;
