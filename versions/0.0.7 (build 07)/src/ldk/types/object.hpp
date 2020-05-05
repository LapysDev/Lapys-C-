/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Definition > Object --- NOTE (Lapys) -> Unable to allocate more than `2uL ** 32uL` objects within the registry. */
    typedef struct object {
        // ...
        friend LapysDevelopmentKit::Types::boolean;
        friend LapysDevelopmentKit::Types::primitive;
        friend LapysDevelopmentKit::Types::size;

        friend void Lapys::Terminate(const LDKT::boolean, const int);

        // [...]
        private:
            // Modification > (Count, Registry)
            static size count;
            static object **registry;

            // Initialization > Identity
            size id;

        // [...]
        protected:
            /* Phases > ... --- UPDATE (Lapys) -> Termination code should be override-able and should invoke any inherited object`s destructor. */
            inline virtual void initiate(void) const {}
            inline virtual void reset(void) const {}
            inline virtual void update(void) const {}
            inline virtual void terminate(void) const {}

        // [...]
        public:
            // [Constructor]
            object() {
                // Logic
                if (object::count < std::size_t(-1) * sizeof(object*)) {
                    // Logic
                    if (NULL == object::registry) {
                        // Logic > Update > (Object > Registry)
                        if (!(object::count % 15u)) pointer__reallocate_memory(object::registry, (object::count + 15u) * sizeof(object*));
                    }

                    else
                        // Update > (Object > Registry)
                        pointer__allocate_memory(object::registry, 15u * sizeof(object*));

                    // : Update > (Object > Registry)
                    // : Modification > Target > ID
                    *(object::registry + object::count) = this;
                    this -> id = object::count++;
                } else { /* WARN (Lapys) -> Exception handling: Objects now created will not be tracked within the registry. */ }
            }

            // [Destructor]
            ~object() {
                // Terminate
                this -> terminate();

                // Loop --- NOTE (Lapys) -> Remove the object from the registry.
                while (this -> id != object::count) {
                    // Update > (Object > Registry)
                    (*(object::registry + this -> id--)) -> id = (*(object::registry + this -> id++)) -> id;
                    (this -> id)++;
                }

                // Modification > Object > Count
                object::count--;
            }
    } object;

    /* Modification > Object > (Count, Registry) */
    size object::count = 0u;
    object **object::registry = NULL;
#endif
