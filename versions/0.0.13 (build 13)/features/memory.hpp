/* Namespace > Memory */
namespace Memory {
    /* Class > Memory Interface --- REDACT (Lapys) */
    namespace {
    struct memory__interface {
        private:
            static void *value;
            constexpr memory__interface(void* const);
        public: template <class type> constexpr operator type&(void) const noexcept;
    };
    }

    /* Definition > Stack ... --- WARN (Lapys) -> Raises a stack-overflow exception rather than a `NULL` pointer if the invocation fails. */
    #if environment__is_windows
    #  define stack_allocate(size) (_malloca(size))
    #else
    #  define stack_allocate(size) (alloca(size))
    #endif

    /* Initialization > ... */
    struct heap_allocator : public memory__interface { public: constexpr heap_allocator(size_t const); } heap_allocate;
    struct heap_mapper : public memory__interface {
        private: constexpr static void* heap_map(size_t const);
        public: constexpr heap_mapper(size_t const);
    } heap_map;
    struct heap_reallocator : public memory__interface { public: template <class type> constexpr heap_reallocator(type* const, size_t const); } heap_reallocate;

    /* Function > ... */
    template <class type, size_t, class... types> constexpr type* heap_contiguous_create(types...);
    template <class type> constexpr type* heap_contiguous_delete(type* const);
    template <class type, class... types> constexpr type* heap_create(types...);
    template <class type> constexpr type* heap_delete(type* const);
    template <class type> constexpr void heap_free(type* const) noexcept;
    template <class type> constexpr type* heap_unmap(type *const, size_t const);
}

/* Class > Memory Buffer */
class MemoryBuffer {};

/* Import > Memory */
#include "memory.cpp"
