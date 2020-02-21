/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Function > Pointer ...
            --- MINIFY (Lapys)
            --- WARN (Lapys) -> These are the only set of functions that use C++ templates.
    */
    template <typename type> inline type* pointer__allocate_memory(type*& pointer, const std::size_t size) { pointer = (type*) std::malloc(size); return pointer; }
    template <typename type> inline type* pointer__free_memory(type*& pointer) { std::free((void*) pointer); pointer = NULL; return pointer; }
    template <typename type> inline type* pointer__reallocate_memory(type*& pointer, const std::size_t size) { pointer = (type*) std::realloc((void*) pointer, size); return pointer; }
#endif
