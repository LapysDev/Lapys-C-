// File -> LocalFile
// File copy
// File Status -> read and write
// File extensions
// File name
// Time
// File type ->
//    none = /* unspecified */,
//    not_found = /* unspecified */,
//    regular = /* unspecified */,
//    directory = /* unspecified */,
//    symlink = /* unspecified */,
//    block = /* unspecified */,
//    character = /* unspecified */,
//    fifo = /* unspecified */,
//    socket = /* unspecified */,
//    unknown = /* unspecified */,
// File properties
// file path exists
// resize file by zero-filling?

/* Class > Entry */
class Entry { friend __MAIN__; };
    /* Directory --- NOTE (Lapys) -> Really just a namespace. */
    class Directory : public Entry { friend __MAIN__;
        // [...]
        public:
            // Method > ... --- NOTE (Lapys) -> Strings represent the directory.
            static bool createSymbolicLink(String const& path);
            static bool directoryExists(String const& path);
            static DynamicArray<File> getDirectoryFiles(String const& path);
            static bool isDirectoryPath(String const& path);
            static bool removeDirectory(String const& path);
            static bool removeDirectoryFiles(String const& path);
            static bool renameDirectory(String const& path);
    };

    /* File
            --- NOTE (Lapys) -> Container for file information.
            --- WARN (Lapys) -> Does not manage file data or state. Does not manage non-ASCII character data (types) explicitly.
    */
    class File : public Entry { friend __MAIN__;
        // [...]
        private:
            // Definition > (Attribute, Buffer, Stream, ...)
            Attribute attribute;
            char *bufferString;
            FILE *stream;

            file__input_binary_stream_interface read;

            // Class > (Attribute, Buffer, Seek Anchor, ...)
            enum Attribute {APPEND = 0x0, APPENDUPDATE, EXCLUSIVE, READ, READUPDATE, READWRITE, WRITE, WRITEUPDATE};
            enum Buffer {FULL = 0x0, LINE};
            enum SeekAnchor {BEGIN, CURRENT, END};

            struct file__input_binary_stream_interface { friend __MAIN__; friend File;
                // [...]
                private:
                    // Definition > (Count, File, Invoked, Multi-Thread Safe)
                    unsigned count;
                    File const* file;
                    bool invoked;
                    bool multithreadSafe;

                // [...]
                public:
                    // [Constructor]
                    file__input_binary_stream_interface(File const* const);

                    // [Operator] > ...
                    file__input_binary_stream_interface& operator ()(bool const = false);
                    file__input_binary_stream_interface& operator ()(unsigned const, bool const = false);

                    operator void*(void) const;
                    operator void const*(void) const;
                    template <class type> operator DynamicArray<type>&(void);
                    operator String&(void);
                    template <class type> operator type*(void);
            };

            // Method > ...
            static String attributeToString(Attribute const) noexcept;
            static bool clearStreamError(FILE* const, bool const = false) noexcept;
            static bool closeDescriptor(int const) noexcept;
            static bool closeStream(FILE* const, bool const = false) noexcept;
            static bool removePath(String const&, bool const = false) noexcept;
            static bool renamePath(String const&, String const&) noexcept;
            constexpr static int translateBuffer(Buffer const) noexcept;
            constexpr static int translateSeekAnchor(SeekAnchor const) noexcept;

        // [...]
        public:
            // [Constructor]
            constexpr File(void);
            constexpr File(String const&, Attribute const);

            // [Destructor]
            ~File(void);

            // Method > ...
            bool buffer(size_t const, Buffer const) const;
            static bool bufferFile(File const&, size_t const, Buffer const);

            bool close(bool const = false);
            static bool closeFile(File&, bool const = false);

            static bool createFile(String const&, Attribute const = File::WRITE);

            bool debuff(void) const;
            static bool debuffFile(File const&);

            bool flush(bool const = false) const;
            static bool flushFile(File const&, bool const = false);

            String getAbsolutePath(void) const;
            static String getFileAbsolutePath(File const&);

            Attribute getAttribute(void) const;
            static Attribute getFileAttribute(File const&);

            String getAttributeAsString(void) const;
            static String getFileAttributeAsString(File const&);

            int getDescriptor(bool const = false) const;
            static int getFileDescriptor(File const&, bool const = false);

            #if environment__is_windows
            HANDLE getHandle(void) const;
            static HANDLE getFileHandle(File const&);
            #endif

            long getLength(void) const;
            static long getFileLength(File const&);

            long getPosition(bool const = false) const;
            static long getFilePosition(File const&, bool const = false);

            String getRelativePath(void) const;
            static String getFileRelativePath(File const&);

            long getSize(void) const;
            static long getFileSize(File const&);

            FILE* getStream(void) const;
            static FILE* getFileStream(File const&);

            bool isClosed(void) const noexcept;
            static bool isClosedFile(File const&) noexcept;

            bool isOpen(void) const noexcept;
            static bool isOpenFile(File const&) noexcept;

            constexpr bool open(String const&, Attribute const) const;
            constexpr static bool openFile(File const&, String const&, Attribute const);
            constexpr static File openFile(String const&, Attribute const);

            static file__input_binary_stream_interface& readFromFile(File const&, bool const = false);
            static file__input_binary_stream_interface& readFromFile(File const&, unsigned const, bool const = false);

            String readLine(bool const = false) const;
            static String readLineFromFile(File const&, bool const = false);

            String readUntilMatch(String const&, bool const = false) const;
            static String readUntilMatchFromFile(File const&, String const&, bool const = false);

            String readUntilMatch(String::Character const&, bool const = false) const;
            static String readUntilMatchFromFile(File const&, String::Character const&, bool const = false);

            bool reopen(String const&, Attribute const) const;
            static bool reopenFile(File const&, String const&, Attribute const);

            bool remove(bool const = false) const;
            static bool removeFile(File const&, bool const = false);

            bool rename(String const&) const;
            bool renameFile(File const&, String const&);

            bool seek(long const, SeekAnchor const = File::CURRENT, bool const = false) const;
            static bool seekFile(File const&, long const, SeekAnchor const = File::CURRENT, bool const = false);

            bool seekTo(long const, bool const = false) const;
            static bool seekFileTo(File const&, long const, bool const = false);

            bool seekToBeginning(void) const noexcept;
            static bool seekFileToBeginning(File const&) noexcept;

            bool seekToEnd(bool const = false) const;
            static bool seekFileToEnd(File const&, bool const = false);

            template <class type> bool write(DynamicArray<type> const&, bool const = false) const;
            template <class type> static bool writeToFile(File const&, DynamicArray<type> const&, bool const = false);

            bool write(String const&, bool const = false) const;
            static bool writeToFile(File const&, String const&, bool const = false);

            bool write(void* const, unsigned const, bool const = false) const;
            static bool writeToFile(File const&, void* const, unsigned const, bool const = false);

            bool write(void const* const, unsigned const, bool const = false) const;
            static bool writeToFile(File const&, void const* const, unsigned const, bool const = false);

            template <class type> bool write(type* const, unsigned const, bool const = false) const;
            template <class type> static bool writeToFile(File const&, type* const, unsigned const, bool const = false);
    };
