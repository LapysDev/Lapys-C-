/* Modification > Exception */
    // [Constructor]
    constexpr inline Exception::Exception(void) : message{} { Process::setCurrentProcessTerminateHandler(Exception::terminate); }
    template <class... types> constexpr inline Exception(types... arguments) : message{Console::toString(arguments...)} { Process::setCurrentProcessTerminateHandler(Exception::terminate); }

    // Get Message
    constexpr inline String const& Exception::getMessage(void) const noexcept { return this -> message; }

    /* Terminate --- UPDATE (Lapys) -> `std::tx_exception` exception types not accounted for currently. */
    constexpr inline void Exception::terminate(int const status) noexcept { using Process::Signal;
        // ...; Error Handling
        console.error(Console::RETURN);
        try {
            // Constant > Exception --- NOTE (Lapys) -> Retrieve the `throw`n object instance.
            std::exception_ptr const exception = std::current_exception();

            // Logic > ...
            if (exception) std::rethrow_exception(exception);
            else {
                console.error("Program terminated...", '\0');
                Process::exitCurrentProcess(status);
            }
        }
        catch (InvalidArgumentException const& exception) { console.error("[InvalidArgumentException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (InvalidFormatException const& exception) { console.error("[InvalidFormatException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (RangeException const& exception) { console.error("[RangeException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (RegexException const& exception) { console.error("[RegexException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (DomainException const& exception) { console.error("[DomainException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (LogicException const& exception) { console.error("[LogicException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (ArithmeticOverflowException const& exception) { console.error("[ArithmeticOverflowException]: ", exception.getMessage(), '\0'); if (false == Process::signalCurrentProcess(Signal::MATH_EXCEPTION)) Process::abortCurrentProcess(); }
        catch (ArithmeticUnderflowException const& exception) { console.error("[ArithmeticUnderflowException]: ", exception.getMessage(), '\0'); if (false == Process::signalCurrentProcess(Signal::MATH_EXCEPTION)) Process::abortCurrentProcess(); }
        catch (FloatingPointException const& exception) { console.error("[FloatingPointException]: ", exception.getMessage(), '\0'); if (false == Process::signalCurrentProcess(Signal::MATH_EXCEPTION)) Process::abortCurrentProcess(); }
        catch (MathException const& exception) { console.error("[MathException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (ReferenceException const& exception) { console.error("[ReferenceException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (TypeException const& exception) { console.error("[TypeException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (SystemException const& exception) { console.error("[SystemException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (IOException const& exception) { console.error("[IOException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (DeviceException const& exception) { console.error("[DeviceException]: ", exception.getMessage(), '\0'); if (false == Process::signalCurrentProcess(Signal::INTERRUPT)) Process::abortCurrentProcess(); }
        catch (FileException const& exception) { console.error("[FileException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (AccessViolationException const& exception) { console.error("[AccessViolationException]: ", exception.getMessage(), '\0'); if (false == Process::signalCurrentProcess(Signal::SEGMENTATION_FAULT)) Process::abortCurrentProcess(); }
        catch (AllocationException const& exception) { console.error("[AllocationException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (MemoryException const& exception) { console.error("[MemoryException]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (Exception const& exception) { console.error("[Exception]: ", exception.getMessage(), '\0'); Process::abortCurrentProcess(); }
        catch (std::bad_alloc const& exception) { console.error("[Exception]: Uncaught `std::bad_alloc`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::bad_cast const& exception) { console.error("[Exception]: Uncaught `std::bad_cast`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::bad_exception const& exception) { console.error("[Exception]: Uncaught `std::bad_exception`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::bad_typeid const& exception) { console.error("[Exception]: Uncaught `std::bad_typeid`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::domain_error const& exception) { console.error("[Exception]: Uncaught `std::domain_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::invalid_argument const& exception) { console.error("[Exception]: Uncaught `std::invalid_argument`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::length_error const& exception) { console.error("[Exception]: Uncaught `std::length_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::out_of_range const& exception) { console.error("[Exception]: Uncaught `std::out_of_range`: \"", exception.what(), '"', '\0'); if (false == Process::signalCurrentProcess(Signal::SEGMENTATION_FAULT)) Process::abortCurrentProcess(); }
        catch (std::overflow_error const& exception) { console.error("[Exception]: Uncaught `std::overflow_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::range_error const& exception) { console.error("[Exception]: Uncaught `std::range_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::underflow_error const& exception) { console.error("[Exception]: Uncaught `std::underflow_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        #if cpp__version >= 2011uL
            catch (std::bad_array_new_length const& exception) { console.error("[Exception]: Uncaught `std::bad_array_new_length`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::bad_function_call const& exception) { console.error("[Exception]: Uncaught `std::bad_function_call`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::bad_weak_ptr const& exception) { console.error("[Exception]: Uncaught `std::bad_weak_ptr`: \"", exception.what(), '"', '\0'); if (false == Process::signalCurrentProcess(Signal::SEGMENTATION_FAULT)) Process::abortCurrentProcess(); }
            catch (std::future_error const& exception) { console.error("[Exception]: Uncaught `std::future_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::ios_base::failure const& exception) { console.error("[Exception]: Uncaught `std::ios_base::failure`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::regex_error const& exception) { console.error("[Exception]: Uncaught `std::regex_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::system_error const& exception) { console.error("[Exception]: Uncaught `std::system_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        #endif
        #if cpp__version >= 2017uL
            catch (std::bad_any_cast const& exception) { console.error("[Exception]: Uncaught `std::bad_any_cast`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::bad_optional_access const& exception) { console.error("[Exception]: Uncaught `std::bad_optional_access`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::bad_variant_access const& exception) { console.error("[Exception]: Uncaught `std::bad_variant_access`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::filesystem::filesystem_error const& exception) { console.error("[Exception]: Uncaught `std::filesystem::filesystem_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        #endif
        #if cpp__version >= 2020uL
            catch (std::ambiguous_local_time const& exception) { console.error("[Exception]: Uncaught `std::ambiguous_local_time`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::format_error const& exception) { console.error("[Exception]: Uncaught `std::format_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
            catch (std::nonexistent_local_time const& exception) { console.error("[Exception]: Uncaught `std::nonexistent_local_time`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        #endif
        catch (std::logic_error const& exception) { console.error("[Exception]: Uncaught `std::logic_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::runtime_error const& exception) { console.error("[Exception]: Uncaught `std::runtime_error`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (std::exception const& exception) { console.error("[Exception]: Uncaught `std::exception`: \"", exception.what(), '"', '\0'); Process::abortCurrentProcess(); }
        catch (char const object) { console.error("[Exception]: Uncaught `char`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (char16_t const object) { console.error("[Exception]: Uncaught `char16_t`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (char32_t const object) { console.error("[Exception]: Uncaught `char32_t`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (double const object) { console.error("[Exception]: Uncaught `double`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (float const object) { console.error("[Exception]: Uncaught `float`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (int const object) { console.error("[Exception]: Uncaught `int`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (long const object) { console.error("[Exception]: Uncaught `long`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (long double const object) { console.error("[Exception]: Uncaught `long double`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (short const object) { console.error("[Exception]: Uncaught `short`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (unsigned int const object) { console.error("[Exception]: Uncaught `unsigned int`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (unsigned long const object) { console.error("[Exception]: Uncaught `unsigned long`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (unsigned short const object) { console.error("[Exception]: Uncaught `unsigned short`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (wchar_t const object) { console.error("[Exception]: Uncaught `wchar_t`: ", Console::PRETTY, object, '\0'); Process::abortCurrentProcess(); }
        catch (...) { console.error("[Exception]: Uncaught exception thrown..."); Process::abortCurrentProcess(); }
    }
