/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Function > ... */
    inline void Initiate(const char[]);
    inline void Reset();
    inline void Update();
    void Terminate(const LDKT::boolean fatal = false, const int programStatus = EXIT_SUCCESS);
#endif
