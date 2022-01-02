/* Class > Error --- NOTE (Lapys) -> Message strings are strictly in the ANSI character set. */
class Error : protected object {
    // [...]
    private:
        // Initialization > Message Value
        char *messageValue;

    // [...]
    protected:
        // Phase > Terminate
        void terminate() {
            std::cout << "[DEBUG : Error]" << std::endl;
            stringFree(this -> messageValue);
        }

    // [...]
    public:
        // Initialization > Message
        const struct ErrorMessage { friend Error;
            private: const Error *error;
            public:
                // [Constructor]
                inline ErrorMessage() : error{(Error*) (void*) null} {}
                inline ErrorMessage(const Error* error) : error{error} {}

                // [Operator] > [...]
                operator char*() const { return stringClone(this -> error -> messageValue); }
        } message;

        // [Constructor]
        inline Error(char message[]) : messageValue{stringConcatenate("Error: ", message)}, message{this} {}
        inline Error(const char message[]) : messageValue{stringConcatenate("Error: ", message)}, message{this} {}
        inline Error(void) : messageValue{stringClone("Error")}, message{this} {}

        // [Destructor]
        ~Error() { this -> terminate(); }

        // [Operator] > [...]
        operator char*() const { return stringClone(this -> messageValue); }
};
