/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Constant > Null */
    const struct {
        // [...]
        private: inline void operator &() const;
        public: template <typename type> inline operator type*() const { return 0; }
    } null;
#endif
