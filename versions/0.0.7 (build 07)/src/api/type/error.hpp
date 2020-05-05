/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Class > Error */
    class Error : protected LDKT::object {
        // ...
        friend LapysDevelopmentKit::Types::boolean;
        friend LapysDevelopmentKit::Types::object;
        friend LapysDevelopmentKit::Types::primitive;
        friend LapysDevelopmentKit::Types::size;

        // [...]
        private:
            // Initialization > Message
            char *message;

        // [...]
        public:
            // [Constructor]
            inline Error() noexcept : message{NULL} {}
            Error(const char message[]) : message{(char*) "Error: "} { this -> message = LDKF::string__source_concatenate(this -> message, message); }

            inline Error(Error& error) noexcept;
            inline Error(Error&& error) noexcept;
            inline Error(const Error& error) noexcept;
            inline Error(const Error&& error) noexcept;

            // [Destructor]
            ~Error() noexcept { LDKF::string__free(this -> message); }

            // [Operator]
                // [=]
                inline Error& operator =(Error&) noexcept;
                inline Error& operator =(Error&&) noexcept;
                inline Error& operator =(const Error&) noexcept;
                inline Error& operator =(const Error&&) noexcept;

                // [...]
                inline operator char*() const { return NULL == this -> message ? (char*) "Error" : this -> message; }
    };
#endif
