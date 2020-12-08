struct Exception { friend __MAIN__;
    private: String const message;
    protected:
        // Method > ... --- CHECKPOINT (Lapys)
        constexpr static void raiseException(int const = SIGABRT) noexcept;

        constexpr inline static resetErrorIndicator(void) noexcept { errno = 0x0; }
        constexpr inline static setErrorIndicator(int const indicator) noexcept { errno = indicator; }

        constexpr static void terminateCurrentProcess(int const = EXIT_SUCCESS) noexcept;

        #if includes__floating_point_environment_library
            constexpr bool allowsFloatingPointErrorIndicator(void) noexcept { return math_errhandling & MATH_ERRNO; }
            constexpr bool allowsFloatingPointException(void) noexcept { return math_errhandling & MATH_ERREXCEPT; }

            constexpr static void raiseFloatingPointException(int const = FE_ALL_EXCEPT) noexcept;
        #endif

    public:
        // [Constructor]
        constexpr Exception(void);

        // Method > Get Message
        constexpr String const& getMessage(void) const noexcept;
};
