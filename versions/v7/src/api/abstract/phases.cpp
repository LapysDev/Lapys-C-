/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Function */
        /* Initiate */
        inline void Initiate(const char programType[]) { Lapys::PROGRAM_TYPE = (char*) programType; }

        /* Reset */
        inline void Reset() {}

        /* Update */
        inline void Update() {}

        /* Terminate --- NOTE (Lapys) -> If invoked as fatal, it will terminate the program (with its specified status) as well. */
        void Terminate(const LDKT::boolean fatal, const int programStatus) {
            // Logic
            if (LDKT::object::count) {
                // : Loop > Terminate
                // : Deletion
                while (LDKT::object::count) (*(LDKT::object::registry + LDKT::object::count--)) -> terminate();
                LDKF::pointer__free_memory(LDKT::object::registry);
            }

            // Logic > Terminate
            if (fatal) std::exit(programStatus);
        }
#endif
