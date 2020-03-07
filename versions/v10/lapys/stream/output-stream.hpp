/* Class > Output Stream */
class OutputStream : Stream {
    // Class > ...
    static enum OutputStreamMode {ERROR, OUTPUT};

    // [...]
    private:
        // Definition > (Buffer, Console, File)
        string buffer; // NOTE (Lapys) -> Outputs are otherwise sent to this buffer instead.
        static OutputStream console; // NOTE (Lapys) -> Special `OutputStream` object.
        FILE *file; // NOTE (Lapys) -> File to act as an output stream.
        void *handle;
        OutputStreamMode mode;

    // [..]
    protected:
        // Function > (Is Console, Put)
        inline boolean isConsole(void) noexcept { return OutputStream::console == *this; }

        #if ldk__detected_platform == ldk_platform__linux
            void put(char character, const int fileDescriptor) {
                if (OutputStream::isBuffered()) buffer[buffer.length - 1u] = character;
                else ::write(fileDescriptor, &character, 1u);
            }
        #elif ldk__detected_platform == ldk_platform__windows
        #endif

    // [...]
    public:
        // [Constructor]
        constexpr inline OutputStream(const FILE* fileStream) : buffer{}, file{NULL}, handle{NULL}, mode{OutputStreamMode::OUTPUT} {}

        // Function
            // Flush
            void flush(void) noexcept { this -> buffer = ""; }

            // Get Mode
            inline OutputStreamMode getMode(void) const noexcept { return this -> mode; }

            // Has File, Is Buffered
            inline boolean hasFile(void) const noexcept { return this -> file; }
            inline boolean isBuffered(void) const noexcept { return this -> buffer; }

            // Log
            // Print
            // Print Line
            // Put
            void put(void) noexcept {

            }

            // Set Mode
            boolean setMode(const OutputStreamMode mode) noexcept { if (OutputStream::isConsole()) return false; else { this -> mode = mode; return true; } }
};

/* Initialization > ... */
OutputStream OutputStream::console {NULL};

/* Utilization > ... */
using OutputStream::console;
