/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Class > Object
            --- RULES ---
                #Lapys:
                    - Construction code should be kept in its `void initiate(void)` function (or phase).
                    - Destruction code should be kept in its `void terminate(void)` function (or phase).
    */
    class Object : LDKT::object {
        // ...
        friend LapysDevelopmentKit::Types::boolean;
        friend LapysDevelopmentKit::Types::object;
        friend LapysDevelopmentKit::Types::primitive;
        friend LapysDevelopmentKit::Types::size;
    };
#endif
