/* Class > Exception --- REDACT (Lapys) */
struct Exception { friend __MAIN__;
    private: String const message;
    protected: constexpr static void terminate(int const = EXIT_SUCCESS) noexcept;
    public:
        // [Constructor]
        constexpr Exception(void);
        template <class... types> constexpr Exception(types... arguments);

        // Method > Get Message
        constexpr String const& getMessage(void) const noexcept;
};

/* Class > ... */
// [Logic]
class LogicException : public Exception { friend __MAIN__; }; // NOTE (Lapys) -> Syntactical errors.
    class DomainException : public LogicException { friend __MAIN__; };
        class InvalidArgumentException : public DomainException { friend __MAIN__; }; // NOTE (Lapys) -> ...
        class InvalidFormatException : public DomainException { friend __MAIN__; }; // NOTE (Lapys) -> Including regular expression formats.
        class RangeException : public DomainException { friend __MAIN__; }; // NOTE (Lapys) -> Errors caused by invalid indexing or lengths.
        class RegexException : public DomainException { friend __MAIN__; };

// [Arithmetic]
class MathException : public Exception { friend __MAIN__; };
    class ArithmeticOverflowException : public MathException { friend __MAIN__; };
    class ArithmeticUnderflowException : public MathException { friend __MAIN__; };

    class FloatingPointException : public MathException { friend __MAIN__; };

// [Programmatic]
class ReferenceException : public Exception { friend __MAIN__; }; // NOTE (Lapys) -> ...
class TypeException : public Exception { friend __MAIN__; }; // NOTE (Lapys) -> Static type errors caused by result of casting, slicing, e.t.c.

// [Systematic]
class SystemException : public Exception { friend __MAIN__; };
    class IOException : public SystemException { friend __MAIN__; }; // NOTE (Lapys) -> Input-output errors.
        class DeviceException : public IOException { friend __MAIN__; };
        class FileException : public IOException { friend __MAIN__; };

    class MemoryException : public SystemException { friend __MAIN__; };
        class AccessViolationException : public MemoryException { friend __MAIN__; };
        class AllocationException : public MemoryException { friend __MAIN__; };
