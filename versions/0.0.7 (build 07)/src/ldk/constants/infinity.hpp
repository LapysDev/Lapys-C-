/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Constant > Infinity */
    const struct { public: inline operator double() const { return INFINITY; } } Infinity;
#endif
