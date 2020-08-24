String Process::getCurrentProcessPath(void) noexcept {
    #if environment__is_windows
        // Initialization > (Directory, Size)
        LPTSTR directory;
        DWORD const size = ::GetCurrentDirectory(0u, NULL);

        // Logic
        if (0u == size)
            // Return
            return NULL;

        else {
            // (Logic > )Update > Directory
            directory = Memory::heap_allocate(size * sizeof(TCHAR));

            if (0u == ::GetCurrentDirectory(size, (LPTSTR) directory))
            directory = Memory::heap_free(directory);
        }

        // Return
        return (char*) directory;
    #else
        char *directory = NULL;
        directory = ::getcwd(NULL, 4096u /* WARN (Lapys) -> Arbitrary length. */);

        return directory;
    #endif
}

 Process::getCurrentProcessPath(void) noexcept {
    ::getcwd()

    char *getcwd(char *buf, size_t size);
    wchar_t *_wgetcwd(wchar_t *buffer, int maxlen);

    NULL for errors
    EACCES
    Permission to read or search a component of the filename was denied.

    EFAULT

    buf points to a bad address.

    EINVAL

    The size argument is zero and buf is not a NULL pointer.

    EINVAL

    getwd(): buf is NULL.

    ENAMETOOLONG
    getwd(): The size of the null-terminated absolute pathname string exceeds PATH_MAX bytes.
    ENOENT
    The current working directory has been unlinked.

    ERANGE

    The size argument is less than the length of the absolute pathname of the working directory, including the terminating null byte. You need to allocate a bigger array and try again.

    errno is set either to ENOMEM, indicating that there is insufficient memory to allocate maxlen bytes (when a NULL argument is given as buffer), or to ERANGE, indicating that the path is longer than maxlen characters
}

constexpr inline Process::translateSignal(Signal const signal) noexcept {
    // Logic > Return
    switch (signal) {
        case Signal::ABORT: return SIGABRT;
        case Signal::INTERRUPT: return SIGINT;
        case Signal::MATH_EXCEPTION: return SIGFPE;
        case Signal::ILLEGAL_INSTRUCTION: return SIGILL;
        case Signal::SEGMENTATION_FAULT: return SIGSEGV;
        case Signal::TERMINATE: return SIGTERM;
    }

    // Return
    return SIG_DFL;
}

constexpr inline void Process::abortCurrentProcess(void) noexcept { ::abort(); }
constexpr inline void Process::exitCurrentProcess(int const status, bool const cleanup) noexcept { cleanup ? ::exit(status) : ::quick_exit(status); }
constexpr inline bool Process::signalCurrentProcess(Signal const signal) noexcept { return 0 == ::raise(Process::translateSignal(signal)); }
constexpr inline void Process::terminateCurrentProcess(void) noexcept { std::terminate(); }

constexpr inline void (*Process::getCurrentProcessSignalHandler(Signal const signal))(int) noexcept {
    // Evaluation > Evaluation
    void (*const evaluation)(int) = &::signal(Process::translateSignal(signal), SignalHandler::UNDEFINED);

    // Update > ...
    cached = true;
    ::signal(Process::translateSignal(signal), evaluation);

    // Return
    return evaluation;
}

inline void Process::currentProcessTerminateHandler(void) { Exception::terminate(EXIT_SUCCESS); }

inline void Process::setCurrentProcessSignalHandler(Signal const signal, void (*const handler)(int)) noexcept { ::signal(Process::translateSignal(signal), handler); }
inline void Process::setCurrentProcessTerminateHandler(void (*handler)(void)) noexcept { std::set_terminate(handler); }

constexpr inline void Process::ignoreCurrentProcessSignal(Signal const signal) noexcept { ::signal(Process::translateSignal(signal), SIG_IGN); }

// Process::setCurrentProcessSignalHandler(Signal::INTERRUPT, Exception::terminate);
// Process::setCurrentProcessTerminateHandler(Exception::terminate);

/* Signal Handler > ... */
void (*const Process::SignalHandler::abort)(int) = &Process::getCurrentProcessSignalHandler(Signal::ABORT);
void (*const Process::SignalHandler::illegalInstruct)(int) = &Process::getCurrentProcessSignalHandler(Signal::ILLEGAL_INSTRUCTION);
void (*const Process::SignalHandler::interrupt)(int) = &Process::getCurrentProcessSignalHandler(Signal::INTERRUPT);
void (*const Process::SignalHandler::mathExcept)(int) = &Process::getCurrentProcessSignalHandler(Signal::MATH_EXCEPTION);
void (*const Process::SignalHandler::segmentationFault)(int) = &Process::getCurrentProcessSignalHandler(Signal::SEGMENTATION_FAULT);
void (*const Process::SignalHandler::terminate)(int) = &Process::getCurrentProcessSignalHandler(Signal::TERMINATE);

/* Modification */
    /* Memory */
    void Memory::thread_allocate(Thread const&);
    void Memory::thread_free(Thread const&);

    /* Process */
        // [Constructor]
        constexpr inline Process::Process(id_t const identity) : identity{identity} {}

        // Exists --- CHECKPOINT (Lapys)
        constexpr inline bool Process::exists(id_t const identity) {
            #if environment__is_windows
                HANDLE const process = ::OpenProcess(SYNCHRONIZE, false, identity);

                if (NULL == process) {
                    ::CloseHandle(process);
                    return true;
                }

                return ERROR_ACCESS_DENIED == ::GetLastError()
            #else
            #endif
        }

        // Get Current Process Arguments --- CHECKPOINT (Lapys)
        constexpr inline Arguments* Process::getCurrentProcessArguments(void) {}

        // Get Current Process Identity
        constexpr inline id_t const Process::getCurrentProcessID(void) noexcept {
            // Logic > Return
            #if environment__is_windows
                return ::GetCurrentProcessId();
            #else
                return ::getpid();
            #endif
        }

/* Constant > Application */
Lapys::Process const application {Process::getCurrentProcessID()};
