/* Namespace > Memory */
namespace Memory {
    // Function > ...
    void thread_allocate(Thread const&);
    void thread_free(Thread const&);
}

/* Class > Process
        --- NOTE (Lapys) -> Container for system process information.
        --- WARN (Lapys) -> Does not manage system process information.
*/
class Process { friend __MAIN__; friend Exception;
    /* Class > (Arguments, Environment ..., Thread ...) */
    class Arguments;
    class EnvironmentStringsList;
    class EnvironmentVariable;
    class Thread;
    class ThreadPool; // CONSIDERATION (Lapys) -> ?

    /* ... */
    #if environment__is_windows
        typedef DWORD id_t;
        typedef DWORD envvar_t;
        typedef BOOL exit_t;
        typedef ULONGLONG iocount_t
        typedef DWORD priority_t;
        typedef struct process_time {
            private: BigUnsignedInteger value;
            public:
                constexpr process_time(FILETIME const&);
                constexpr process_time(FILETIME&&);

                constexpr operator =(FILETIME const&);
                constexpr operator =(FILETIME&&);
                constexpr operator BigUnsignedInteger&(void);
        } time_t;
        tyepdef DWORD sleeptime_t;
        typedef ULONG stack_t;
        typedef DWORD version_t;
    #else
        typedef pid_t id_t;
    #endif

    // [...]
    private:
        // Definition > (Identity, Signal Handler > ...)
        id_t identity;
        class SignalHandler { friend __MAIN__; friend Process; private:
            static void (*const abort)(int);
            static void (*const illegalInstruct)(int);
            static void (*const interrupt)(int);
            static void (*const mathExcept)(int);
            static void (*const segmentationFault)(int);
            static void (*const terminate)(int);

            constexpr inline static void UNDEFINED(int const) noexcept {}
        };

        // [Constructor]
        constexpr Process(Process&&);

        // [Operator] > [=]
        constexpr Process& operator =(Process&&) noexcept;

    // [...]
    public:
        /* Class > Signal */
        enum Signal {ABORT = 0x0, INTERRUPT, MATH_EXCEPTION, ILLEGAL_INSTRUCTION, SEGMENTATION_FAULT, TERMINATE};

        // [Constructor]
        constexpr inline Process(id_t const);

        // Method > ...
        void abort(void) const;
        bool createChild(void) const;
        bool execute(void) const;
        void exit(void) const;
        Process fork(void) const;
        bool flushWriteBuffers(void);
        constexpr Arguments* getArguments(void) const noexcept;
        time_t getCreationTime(void);
        EnvironmentStringsList getEnvironmentStrings(void);
        envvar_t getEnvironmentVariable(void);
        exit_t getExitCode(void);
        time_t getExitTime(void);
        id_t getID(void);
        iocount_t getIORoutineCount(void);
        time_t getKernelModeTime(void);
        iocount_t getMiscellaneousIOOperationCount(void);
        iocount_t getMiscellaneousIOTransferCount(void);
        priority_t getPriorityClass(void);
        iocount_t getReadOperationCount(void);
        iocount_t getReadTransferCount(void);
        time_t getUserModeTime(void);
        size_t getWorkingSetSize(void);
        iocount_t getWriteOperationCount(void);
        iocount_t getWriteTransferCount(void);
        bool isWindowsStoreApplication(void) const;
        bool isWOWApplication(void) const;
        String queryName(void) const;
        bool receivedRecentWOWMessage(void);
        bool setEnvironmentVariable(EnvironmentVariable const&) const;
        bool setWorkingSetSize(size_t const) const;
        bool signal(Signal const) const;
        bool switchThread(Thread const&);
        bool terminate(void) const;
        Process virtualFork(void) const;
        bool wait(void) const;

        static void abortProcess(Process const&);
        static Process createChildProcess(Process const&);
        static Process createProcess(void);
        static Process createProcessAsUser(void);
        static Process createProcessWithLogon(void);
        static Process createProcessWithToken(void);
        static void exitCurrentProcess(int const = EXIT_SUCCESS, bool const = true);
        static void exitProcess(Process const&);
        static bool flushProcessWriteBuffers(Process const&);
        static Process forkProcess(Process const&);
        static bool freeProcessEnvironmentStrings(Process const&);
        static ProcessList getActiveProcesses(void);
        static Process const& getCurrentProcess(void);
        static Arguments* getCurrentProcessArguments(void);
        static id_t getCurrentProcessID(void);
        static id_t getCurrentProcessProcessorNumber(void);
        static time_t const getProcessCreationTime(Process const&);
        static EnvironmentStringsList const getProcessEnvironmentStrings(Process const&);
        static envvar_t getProcessEnvironmentVariable(Process const&);
        static exit_t getProcessExitCode(Process const&);
        static time_t const getProcessExitTime(Process const&);
        static id_t getProcessID(Process const&);
        static iocount_t getProcessIORoutineCount(Process const&);
        static time_t const getProcessKernelModeTime(Process const&);
        static ProcessList getProcesses(void);
        static iocount_t getProcessMiscellaneousIOOperationCount(Process const&);
        static iocount_t getProcessMiscellaneousIOTransferCount(Process const&);
        static priority_t getProcessPriorityClass(Process const&);
        static iocount_t getProcessReadOperationCount(Process const&);
        static iocount_t getProcessReadTransferCount(Process const&);
        static time_t const getProcessUserModeTime(Process const&);
        static size_t getProcessWorkingSetSize(Process const&);
        static iocount_t getProcessWriteOperationCount(Process const&);
        static iocount_t getProcessWriteTransferCount(Process const&);
        static bool isWindowsStoreApplication(Process const&);
        static bool isWOWApplication(Process const&);
        static String queryProcessName(Process const&);
        static bool receivedRecentWOWMessage(Process const&);
        static bool setProcessEnvironmentVariable(Process const&, EnvironmentVariable const&);
        static bool setProcessPriorityClass(Process const&, priority_t const);
        static bool setProcessWorkingSetSize(Process const&, size_t const);
        static bool switchProcessThread(Process const&, Thread const&);
        static bool terminateCurrentProcess(void);
        static bool terminateProcess(Process const&);
        static Process virtualForkProcess(Process const&);

        #if environment__is_windows
            BOOL getHandleCount(void);
            STARTUPINFOA getStartupInformation(void);
            version_t getVersion(void);

            static BOOL getProcessHandleCount(Process const&);
            static STARTUPINFOA getProcessStartupInformation(Process const&);
            static version_t getProcessVersion(Process const&);
        #endif
};
    /* Arguments */
    class Arguments : public StaticArray<String> { friend class Process; friend __MAIN__;
        // [...]
        public:
            // Method > To String
            constexpr char* toString(void) const noexcept;
    };

    /* Environment Strings List */
    class EnvironmentStringsList : public StaticArray<String> { friend class Process; friend __MAIN__; };

    /* Environment Variable */
    class EnvironmentVariable { friend class Process; friend __MAIN__; public: String name; String value; };

    /* Process List */
    class ProcessList : public StaticArray<Process> { friend class Process; friend __MAIN__; };

    /* Thread */
    class Thread { friend class Process; friend __MAIN__;
        // [...]
        public:
            // Method > ...
            bool waitForUserInput(void);

            static Thread createThread(Process const&);
            static void exitThread(Thread const&);
            static Thread getCurrentThread(void);
            static id_t getCurrentThreadID(void);
            static time_t getThreadCreationTime(Thread const&);
            static String getThreadDescription(Thread const&);
            static exit_t getThreadExitCode(Thread const&);
            static time_t getThreadExitTime(Thread const&);
            static id_t getThreadID(Thread const&);
            static time_t getThreadKernelModeTime(Thread const&);
            static int getThreadPriority(Thread const&)
            static time_t getThreadUserModeTime(Thread const&);;
            static bool isPending(Thread const&);
            static bool resumeThread(Thread const&);
            static bool setThreadDescription(Thread const&, String const&);
            static bool setThreadMinimumStackSize(Thread const&, stack_t const);
            static bool sleepThread(Thread const&, sleeptime_t const);
            static bool suspendThread(Thread const&); // NOTE (Lapys) -> Determine if the thread is WOW64.
            static bool terminateThread(Thread const&);
    };

/* Import > Process */
#include "process.cpp"
