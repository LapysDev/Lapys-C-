/* Modification */
    /* Directory */
    /* File --- UPDATE (Lapys) -> Update warnings. */
        // [Constructor]
        constexpr inline File::File(void) : attribute{}, bufferString{NULL}, stream{NULL}, read{this} {}
        constexpr inline File::File(String const& path, Attribute const attribute) : attribute{/* attribute */}, bufferString{NULL}, stream{NULL}, read{this} { File::open(path, attribute); }

        // [Destructor]
        inline File::~File(void) { File::close(); }

        /* File Input Binary Stream Interface */
            // [Constructor]
            File::file__input_binary_stream_interface::file__input_binary_stream_interface(File const* const file) : count{0u}, file{file}, invoked{false}, multithreadSafe{false} {}

            // [Operator]
                // [()] --- NOTE (Lapys) -> Set the function arguments.
                inline File::file__input_binary_stream_interface& File::file__input_binary_stream_interface::operator ()(bool const multithreadSafe) {
                    // Logic > Error
                    if (this -> file.isClosed()) throw LogicException("Attempt to read un-opened `File`");

                    // Constant > Length
                    long const length = this -> file.getLength();

                    // Modification > Target > (Count, Invoked, Multi-Thread Safe)
                    this -> count = 0u;
                    this -> invoked = true;
                    this -> multithreadSafe = multithreadSafe;

                    // Logic
                    if (~length) {
                        // Constant > Position
                        // : Logic > Modification > Target > Count
                        long const position = this -> file.getPosition();
                        if (~position && length > position) this -> count = length - position;
                    }

                    // Return
                    return *this;
                }

                inline File::file__input_binary_stream_interface& File::file__input_binary_stream_interface::operator ()(unsigned const count, bool const multithreadSafe) {
                    // Logic > Error
                    if (this -> file.isClosed()) throw LogicException("Attempt to read un-opened `File`");

                    // Modification > Target > (Count, Invoked, Multi-Thread Safe)
                    this -> count = count;
                    this -> invoked = true;
                    this -> multithreadSafe = multithreadSafe;

                    // Return
                    return *this;
                }

                // [...] --- NOTE (Lapys) -> Execute and return the function result.
                inline File::file__input_binary_stream_interface::operator void*(void) const { throw TypeException("Attempt to read incomplete data (type) from `File`"); }
                inline File::file__input_binary_stream_interface::operator void const*(void) const { throw TypeException("Attempt to read incomplete data (type) from `File`"); }

                template <class type> inline File::file__input_binary_stream_interface::operator DynamicArray<type>&(void) { return DynamicArray<type> {this -> count, file__input_binary_stream_interface::operator type*()}; }
                inline File::file__input_binary_stream_interface::operator String&(void) { return String {this -> count, file__input_binary_stream_interface::operator char*()}; }

                template <class type>
                inline File::file__input_binary_stream_interface::operator type*(void) {
                    // Logic > (Error, Return)
                    if (false == this -> invoked) throw TypeException("Attempt to evaluate data pointer from functor type `File::file__input_binary_stream_interface` without calling the functor first");
                    if (0u == this -> count) return NULL;

                    // Initialization > (Content, Elements Read)
                    type *const content = Memory::heap_allocate(this -> count * sizeof(type));
                    size_t elementsRead;

                    // Logic > Update > Elements Read
                    #if environment__is_windows
                        elementsRead = this -> multithreadSafe ? ::_fread_nolock_s(content, this -> count * sizeof(type), sizeof(type), this -> count, this -> file.stream) : ::fread_s(content, this -> count * sizeof(type), sizeof(type), this -> count, this -> file.stream);
                    #else
                        elementsRead = this -> multithreadSafe ? ::fread_unlocked(content, sizeof(type), this -> count, this -> file.stream) : ::fread(content, sizeof(type), this -> count, this -> file.stream);
                    #endif

                    // Logic
                    if (elementsRead ^ count) {
                        // Update > Content
                        content = Memory::heap_free(content);

                        // Logic > Warn ...
                        if (::ferror(this -> file.stream)) {
                            console.warn(Console::RETURN, "[Warning]: Attempt to read from `File` failed", Console::NEWLINE);
                            File::clearStreamError(this -> file.stream);
                        }
                    }

                    // ...; Modification > Target > Invoked
                    this -> file.seek(-(signed) length, File::CURRENT);
                    this -> invoked = false;

                    // Return
                    return content;
                }

        // Method
            // Attribute To String --- NOTE (Lapys) -> Defaults to binary mode.
            constexpr inline String File::attributeToString(Attribute const attribute) noexcept {
                // Logic > Return
                switch (attribute) {
                    case APPEND: return "ab";
                    case APPENDUPDATE: return "ab+";
                    case EXCLUSIVE: return "xb";
                    case READ: return "rb";
                    case READUPDATE: return "rb+";
                    case READWRITE: return NULL;
                    case UNDEFINED: return NULL;
                    case WRITE: return "wb";
                    case WRITEUPDATE: return "wb+";
                }

                // Return
                return NULL;
            }

            // Buffer
            inline bool File::buffer(size_t const length, Buffer const buffer) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to buffer un-opened `File`");

                // ... Return
                Memory::heap_free(this -> bufferString);
                this -> bufferString = Memory::heap_allocate(length * sizeof(char));

                return 0 == ::setvbuf(this -> stream, this -> bufferString, File::translateBuffer(buffer), length * sizeof(char));
            }
            inline bool File::bufferFile(File const& file, size_t const length, Buffer const buffer) { return file.buffer(length, buffer); }

            // Clear Stream Error
            constexpr inline bool clearStreamError(FILE* const stream, bool const multithreadSafe) noexcept {
                // Logic ... > Deletion
                #if environment__is_windows
                    if (false == multithreadSafe)
                    return EINVAL != ::clearerr_s(stream);
                #else
                    if (false == multithreadSafe) ::clearerr(stream);
                    else ::clearerr_unlocked(stream);
                #endif

                // Return
                return true;
            }

            // Close ...
            constexpr inline bool File::close(bool const multithreadSafe) { this -> bufferString = Memory::heap_free(this -> bufferString); if (NULL != this -> stream && File::closeStream(this -> stream, multithreadSafe)) this -> stream = NULL; }
            constexpr inline bool File::closeDescriptor(int const descriptor) noexcept {
                // Logic
                #if environment__is_windows
                if (::_close(descriptor) == -1) {
                #else
                if (::close(descriptor) == -1) {
                #endif
                    // Logic > Warn
                    switch (errno) {
                        case EBADF: console.warn(Console::RETURN, "[Warning]: Attempt to close invalid `int` file descriptor", Console::NEWLINE); break;
                        case EINTR: console.warn(Console::RETURN, "[Warning]: Attempt to close `int` file descriptor interrupted by a program signal", Console::NEWLINE); break;
                        case EIO: console.warn(Console::RETURN, "[Warning]: Attempt to close `int` file descriptor interrupted by an I/O error", Console::NEWLINE); break;
                    }

                    // Return
                    return false;
                }

                // Return
                return true;
            }
            inline bool File::closeFile(File& file, bool const multithreadSafe) { return file.close(multithreadSafe); }
            constexpr inline bool File::closeStream(FILE* const stream, bool const multithreadSafe) noexcept {
                // Logic
                if (EOF == (multithreadSafe ? ::_fclose_nolock(stream) : ::fclose(stream))) {
                    // Logic > Warn
                    // : Return
                    if (EBADF == errno) console.warn(Console::RETURN, "[Warning]: Attempt to close invalid `FILE*` file stream", Console::NEWLINE);
                    return false;
                }

                // Return
                return true;
            }

            // Create File --- NOTE (Lapys) -> Simply creates the file, provides no handles.
            inline bool File::createFile(String const& path, Attribute const attribute) {
                // Initialization > File
                File file;

                // Logic
                if (file.open(path, File::EXCLUSIVE == attribute || File::READ == attribute || File::READUPDATE == attribute || File::READWRITE == attribute ? File::WRITE : attribute)) {
                    // Deletion; Return
                    file.close();
                    return true;
                }

                // Return
                return false;
            }

            // Create Hard Link
            inline bool File::createHardLink(String const& path) const {
                // Logic
                #if environment__is_windows
                    // Return
                    return 0 != ::CreateHardLinkA(path, File::getAbsolutePath());
                #elif environment__is_posix
                    // Logic
                    if (::link(File::getAbsolutePath(), path) == -1) {
                        // Logic > Warn
                        switch (errno) {
                            case EACCES: case EPERM: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link without permission", Console::NEWLINE); break;
                            case EEXIST: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link onto existing file or symbolic link", Console::NEWLINE); break;
                            case ELOOP: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link with unresolved loops in the file path", Console::NEWLINE); break;
                            case EMLINK: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link with an excess link count", Console::NEWLINE); break;
                            case ENAMETOOLONG: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link with excessively long file path", Console::NEWLINE); break;
                            case ENOENT: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link from a non-existing file path", Console::NEWLINE); break;
                            case ENOSPC: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link from non-extend-able file path", Console::NEWLINE); break;
                            case ENOTDIR: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link from invalid file path", Console::NEWLINE); break;
                            case EROFS: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link in a read-only file system", Console::NEWLINE); break;
                            case EXDEV: console.warn(Console::RETURN, "[Warning]: Attempt to create hard link between different file systems or using STREAMS-based files", Console::NEWLINE); break;
                        }

                        // Return
                        return false;
                    }
                #else
                    // Return
                    return false;
                #endif

                // Return
                return true;
            }
            inline bool File::createHardLink(File const& file, String const& path) { return file.createHardLink(path); }

            // Create Symbolic Link --- NOTE (Lapys) -> Does not create an interface for the link.
            inline bool File::createSymbolicLink(String const& path) const {
                // Logic
                #if environment__is_windows
                    // Return
                    return 0 != ::CreateSymbolicLinkA(path, File::getAbsolutePath());
                #elif environment__is_posix
                    // Logic
                    if (::symlink(File::getAbsolutePath(), path) == -1) {
                        // Logic > Warn
                        switch (errno) {
                            case EACCES: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link without permission", Console::NEWLINE); break;
                            case EEXIST: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link onto existing file or symbolic link", Console::NEWLINE); break;
                            case EIO: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link while error or hangup occurred", Console::NEWLINE); break;
                            case ELOOP: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link with unresolved loops in the file path", Console::NEWLINE); break;
                            case ENAMETOOLONG: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link with excessively long file path", Console::NEWLINE); break;
                            case ENOENT: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link from a non-existing file path", Console::NEWLINE); break;
                            case ENOSPC: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link from non-extend-able file path", Console::NEWLINE); break;
                            case ENOTDIR: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link from invalid file path", Console::NEWLINE); break;
                            case EROFS: console.warn(Console::RETURN, "[Warning]: Attempt to create symbolic link in a read-only file system", Console::NEWLINE); break;
                        }

                        // Return
                        return false;
                    }
                #else
                    // Return
                    return false;
                #endif

                // Return
                return true;
            }
            inline bool File::createSymbolicLink(File const& file, String const& path) { return file.createSymbolicLink(path); }

            // Debuff
            inline bool File::debuff(void) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to remove buffer of un-opened `File`");

                // ... Return
                this -> bufferString = Memory::heap_free(this -> bufferString);
                return 0 == ::setvbuf(this -> stream, NULL, _IONBF, 0u);
            }
            inline bool File::debuffFile(File const& file) { return file.debuff(); }

            // Flush
            inline bool File::flush(bool const multithreadSafe) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to flush un-opened `File`");

                // Logic
                #if environment__is_windows
                if (EOF == (multithreadSafe ? ::_fflush_nolock(this -> stream) : ::fflush(this -> stream))) {
                #else
                if (EOF == (multithreadSafe ? ::fflush_unlocked(this -> stream) : ::fflush(this -> stream))) {
                #endif
                    // Logic > Warn
                    // : Return
                    if (EBADF == errno) console.warn(Console::RETURN, "[Warning]: Attempt to flush un-opened `FILE*` file stream", Console::NEWLINE);
                    return false;
                }

                // Return
                return true;
            }
            inline bool File::flushFile(File const& file, bool const multithreadSafe) { return file.flush(multithreadSafe); }

            // Get Absolute Path --- CHECKPOINT (Lapys)
            inline String File::getAbsolutePath(void) const {
                /* MAC */
                #include <sys/syslimits.h>
                #include <fcntl.h>

                char filePath[PATH_MAX];
                if (fcntl(fd, F_GETPATH, filePath) != -1)
                {
                    printf("%s", filePath);
                }

                /* LINUX */
                #include <stdio.h>
                #include <unistd.h>
                #include <limits.h>
                #include <stdlib.h>

                int print_filename(FILE *f) {
                    char buf[PATH_MAX];
                    char fnmbuf[sizeof "/prof/self/fd/0123456789"];
                    sprintf(fnmbuf,"/proc/self/fd/%d", fileno(f));
                    ssize_t nr;
                    if(0>(nr=readlink(fnmbuf, buf, sizeof(buf)))) return -1; // readlink does not null terminate
                    else buf[nr]='\0';
                    return puts(buf);
                }

                /* WINDOWS */
                DWORD GetFinalPathNameByHandleA(HANDLE hFile, LPSTR  lpszFilePath, DWORD  cchFilePath, DWORD  dwFlags);
            }
            inline String File::getFileAbsolutePath(File const& file) { return file.getAbsolutePath(); }

            // Get Attribute ...
            inline Attribute File::getAttribute(void) const {
                // Logic > Error
                // : Return
                if (File::isClosed()) throw LogicException("Attempt to get attribute of un-opened `File`");
                return this -> attribute;
            }
            inline Attribute File::getFileAttribute(File const& file) { return file.getAttribute(); }

            inline String File::getAttributeAsString(void) const {
                // Logic > Error
                // : Return
                if (File::isClosed()) throw LogicException("Attempt to get mode of un-opened `File`");
                return File::attributeToString(this -> attribute);
            }
            inline String File::getFileAttributeAsString(File const& file) { return file.getAttributeAsString(); }

            /* Get Descriptor
                --- NOTE (Lapys) -> Returns a duplicate descriptor of the current file handle.
                --- WARN (Lapys) -> Can not be thread-safe on Microsoft Windows.
            */
            inline int File::getDescriptor(bool const multithreadSafe) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to get integer descriptor of un-opened `File`");

                // Logic
                #if environment__is_windows
                    // Evaluation > Evaluation
                    int evaluation = ::_fileno(this -> stream);

                    // Logic > ...
                    if (~evaluation) evaluation = ::_dup(evaluation);
                    else if (EINVAL == errno) {
                #else
                    // Evaluation > Evaluation
                    int evaluation = multithreadSafe ? ::fileno_unlocked(this -> stream) : ::fileno(this -> stream);

                    // Logic > ...
                    if (~evaluation) evaluation = ::dup(evaluation);
                    else if (EBADF == errno) {
                #endif

                    // Warn; Return
                    console.warn(Console::RETURN, "[Warning]: Attempt to get `int` file descriptor of invalid `FILE*` file stream", Console::NEWLINE);
                    return evaluation;
                }

                // Logic > Warn
                if (evaluation == -1)
                switch (errno) {
                    case EBADF: console.warn(Console::RETURN, "[Warning]: Attempt to duplicate invalid/ un-opened `int` file descriptor", Console::NEWLINE); break;
                    case EMFILE: console.warn(Console::RETURN, "[Warning]: Attempt to duplicate `int` file descriptor without available file descriptors", Console::NEWLINE); break;
                }

                // Return
                return evaluation;
            }
            inline int File::getFileDescriptor(File const& file, bool const multithreadSafe) { return file.getDescriptor(multithreadSafe); }

            // Get Handle
            #if environment__is_windows
            inline HANDLE File::getHandle(void) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to get handle of un-opened `File`");

                // Evaluation > Evaluation
                HANDLE evaluation = NULL;

                // Logic > Update > Evaluation
                #ifdef q4_WCE
                    if (0 != ::FlushFileBuffers((HANDLE) File::getDescriptor()))
                    evaluation = ::CreateFileMapping((HANDLE) File::getDescriptor(), NULL, PAGE_READONLY, 0, File::getLength(), NULL);
                #else
                    if (0 != ::FlushFileBuffers((HANDLE) _get_osfhandle(File::getDescriptor())))
                    evaluation = ::CreateFileMapping((HANDLE) _get_osfhandle(File::getDescriptor()), NULL, PAGE_READONLY, 0, File::getLength(), NULL);
                #endif

                // Return
                return evaluation;
            }
            inline HANDLE File::getFileHandle(File const& file) { return file.getHandle(); }
            #endif

            // Get Length
            inline long File::getLength(void) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to get length of un-opened `File`");

                // Constant > Position; Logic
                long const position = File::getPosition();
                if (~position) {
                    // ...; Return
                    File::seekToEnd(); long const evaluation = File::getPosition();
                    File::seekTo(position); return evaluation;
                }

                // Return
                return -1L;
            }
            inline long File::getFileLength(File const& file) { return file.getLength(); }

            // Get Position
            inline long File::getPosition(bool const multithreadSafe) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to get internal position of un-opened `File`");

                // Evaluation > Evaluation
                long evaluation;

                // Logic ... > Update > Evaluation
                #if environment__is_windows
                    if (multithreadSafe) evaluation = ::_ftell_nolock(this -> stream);
                    else
                #endif
                evaluation = ::ftell(this -> stream);

                // Logic > Warn
                if (EBADF == errno && evaluation == -1L)
                console.warn(Console::RETURN, "[Warning]: Attempt to get internal position of un-seekable `FILE*` file stream", Console::NEWLINE);

                // Return
                return evaluation;
            }
            inline long File::getFilePosition(File const& file, bool const multithreadSafe) { return file.getPosition(multithreadSafe); }

            // Get Relative Path --- CHECKPOINT (Lapys)
            inline String File::getRelativePath(void) const {}
            inline String File::getFileRelativePath(File const& file) { return file.getRelativePath(); }

            // Get Size --- WARN (Lapys) -> Size in bytes, not the size of the file on storage.
            inline long File::getSize(void) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to get size of un-opened `File`");

                // Logic
                #if environment__is_windows
                    // Initialization > Size ... --- WARN (Lapys) -> `GetFileSizeEx` is recommended instead.
                    DWORD sizeHighOrder = 0;
                    DWORD const sizeLowOrder = ::GetFileSize(File::getHandle(), &sizeHighOrder);

                    // Return
                    return INVALID_FILE_SIZE == sizeLowOrder ? -1 : sizeLowOrder + (sizeHighOrder << sizeof(DWORD));
                #elif environment__is_posix
                    // Initialization > Buffer
                    struct stat buffer;

                    // Logic > ...
                    if (~::fstat(File::getDescriptor(), &buffer)) return (intmax_t) buffer.st_size;
                    else switch (errno) {
                        case EBADF: console.warn(Console::RETURN, "[Warning]: Attempt to get byte size of file via invalid `int` file descriptor", Console::NEWLINE); break;
                        case EFAULT: console.warn(Console::RETURN, "[Warning]: Attempt to get byte size of file with bad address", Console::NEWLINE); break;
                        case ENOMEM: console.warn(Console::RETURN, "[Warning]: Attempt to get byte size of file without available memory", Console::NEWLINE); break;
                        case EOVERFLOW: console.warn(Console::RETURN, "[Warning]: Attempt to get byte size of file with a(n) index node number/ number of blocks/ size unrepresentable in `ino_t`, `blkcnt_t`, or `off_t` data types respectively.", Console::NEWLINE); break;
                    }

                    // Return
                    return -1L;
                #else
                    // Return
                    return File::getLength();
                #endif
            }
            inline long File::getFileSize(File const& file) { return file.getSize(); }

            // Get Stream
            inline FILE* File::getStream(void) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to get stream of un-opened `File`");

                // Constant > Descriptor; Logic
                int const descriptor = File::getDescriptor(true);
                if (~descriptor) {
                    // Evaluation > Evaluation
                    FILE *evaluation;

                    // Logic > Update > Evaluation
                    #if environment__is_windows
                        evaluation = ::_fdopen(descriptor, File::getAttributeAsString());
                    #else
                        evaluation = ::fdopen(descriptor, File::getAttributeAsString());
                    #endif

                    // Logic > Warn
                    if (NULL == evaluation)
                    switch (errno) {
                        case EACCES: console.warn(Console::RETURN, "[Warning]: Attempt to get `FILE*` file stream of `int` file descriptor while prohibited by locks in the other processes", Console::NEWLINE); break;
                        case EAGAIN: console.warn(Console::RETURN, "[Warning]: Attempt to get `FILE*` file stream of `int` file descriptor while prohibited because the file is memory-mapped by other processes", Console::NEWLINE);  break;
                        case EBADF: console.warn(Console::RETURN, "[Warning]: Attempt to get `FILE*` file stream of un-opened `int` file descriptor", Console::NEWLINE); break;
                        case EFAULT: console.warn(Console::RETURN, "[Warning]: Attempt to get `FILE*` file stream of `int` file descriptor with lock outside of accessible address space", Console::NEWLINE); break;
                        case EINVAL: console.warn(Console::RETURN, "[Warning]: Attempt to get `FILE*` file stream of `int` file descriptor with invalid mode(s)", Console::NEWLINE); break;
                        case ENOLCK: console.warn(Console::RETURN, "[Warning]: Attempt to get `FILE*` file stream of `int` file descriptor while lock table filled, a remote locking protocol failed, or too many segment locks opened", Console::NEWLINE); break;
                        case EPERM: console.warn(Console::RETURN, "[Warning]: Attempt to get `FILE*` file stream of `int` file descriptor but append attribute could not be cleared on the (append-only) file", Console::NEWLINE); break;
                    }

                    // Deletion; Return
                    File::closeDescriptor(descriptor);
                    return evaluation;
                }

                // Return
                return NULL;
            }
            inline FILE* File::getFileStream(File const& file) { return file.getStream(); }

            // Is (Closed, Open)
            constexpr inline bool File::isClosed(void) const noexcept { return NULL == this -> stream; }
            inline bool File::isClosedFile(File const& file) noexcept { return file.isClosed(); }

            constexpr inline bool File::isOpen(void) const noexcept { return NULL != this -> stream; }
            inline bool File::isOpenFile(File const& file) noexcept { return file.isOpen(); }

            // Open
            constexpr inline bool File::open(String const& path, Attribute const attribute) const {
                // Logic > Error
                if (false == URL::isValid(path)) throw InvalidFormatException("Attempt to open `File` with an invalid directory");

                // Initialization > Stream
                FILE *stream = NULL;

                // Logic > Update > Stream
                #if environment__is_windows
                    stream = ::fopen_s(&stream, path, File::attributeToString(attribute));
                #else
                    stream = ::fopen(path, File::attributeToString(attribute));
                #endif

                // Logic > ...
                if (NULL == stream) {
                    // Logic
                    switch (errno) {
                        case EACCES: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream but access permission is denied or permissively interrupted by a component of a specified argument path prefix", Console::NEWLINE); break;
                        case EAGAIN: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream with on the slave side of a locked pseudo-terminal device", Console::NEWLINE); break;
                        case EEXIST: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream but access permission is denied", Console::NEWLINE); break;
                        case EINTR: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream while signal was caught", Console::NEWLINE); break;
                        case EINVAL: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream does not support synchronized I/O for this file", Console::NEWLINE); break;
                        case EIO: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream while error or hangup occurred", Console::NEWLINE); break;
                        case EISDIR: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream of a directory instead of a file", Console::NEWLINE); break;
                        case ELOOP: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream with unresolved loop in the symbolic links of the file path", Console::NEWLINE); break;
                        case EMFILE: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream with the maximum number of `int` file descriptors (in the process) currently open", Console::NEWLINE); break;
                        case ENAMETOOLONG: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream with excessively long file path", Console::NEWLINE); break;
                        case ENFILE: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream with the maximum number of files (in the system) currently open", Console::NEWLINE); break;
                        case ENOENT: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream while creating un-openable file", Console::NEWLINE); break;
                        case ENOMEM: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream on a STREAMS-based file without allocable resources", Console::NEWLINE); break;
                        case ENOSR: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream on an unallocable STREAMS-based file", Console::NEWLINE); break;
                        case ENOSPC: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream while unable to contain the newly created file", Console::NEWLINE); break;
                        case ENOTDIR: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream with an invalid file path", Console::NEWLINE); break;
                        case ENXIO: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream as a block special or character special file without an associated device", Console::NEWLINE); break;
                        case EOVERFLOW: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream with an unrepresentable size in an `off_t` data type", Console::NEWLINE); break;
                        case EROFS: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream with invalid file mode(s) on a read-only file system", Console::NEWLINE); break;
                        case ETXTBSY: console.warn(Console::RETURN, "[Warning]: Attempt to open `FILE*` file stream of an executing pure procedure (shared text) file", Console::NEWLINE); break;
                    }

                    // Return
                    return false;
                }

                else {
                    // Modification > Target > (Attribute, Stream)
                    this -> attribute = attribute;
                    this -> stream = stream;
                }

                // Return
                return true;
            }

            constexpr inline bool File::openFile(File const& file, String const& path, Attribute const attribute) { return file.open(path, attribute); }
            constexpr inline File File::openFile(String const& path, Attribute const attribute) { return File(path, attribute); }

            // Read
            inline File::file__input_binary_stream_interface& File::read(File const& file, bool const multithreadSafe) { return file.read(multithreadSafe); }
            inline File::file__input_binary_stream_interface& File::readFromFile(File const& file, unsigned const count, bool const multithreadSafe) { return file.read(count, multithreadSafe); }

            // Read Line
            inline String File::readLine(bool const multithreadSafe) const { return File::readUntilMatch(Console::NEWLINE, multithreadSafe); }
            inline String File::readLineFromFile(File const& file, bool const multithreadSafe) { return file.readLine(multithreadSafe); }

            // Read Until Match
            inline String File::readUntilMatch(String const& match, bool const multithreadSafe) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to read un-opened `File`");

                // Constant > Match Length
                String::length_t const& matchLength = match.length;

                // Logic
                if (matchLength == 1u) File::readUntilMatch(match.at(1u));
                else {
                    // Initialization > (Element, Index, Length)
                    int element;
                    String::length_t index = 0u;
                    unsigned length = 0u;

                    // Loop
                    #if environment__is_windows
                    while (EOF ^ (element = multithreadSafe ? ::_getc_nolock(this -> stream) : ::getc(this -> stream))) {
                    #else
                    while (EOF ^ (element = multithreadSafe ? ::getc_unlocked(this -> stream) : ::getc(this -> stream))) {
                    #endif
                        // Update > Length
                        ++length;

                        // Logic > ...
                        if (match.at(index) == (char) element) ++index;
                        if (index == matchLength) break;
                    }

                    // Logic
                    if (EOF == element && ::ferror(this -> stream)) {
                        // Update > Length
                        length = 0u;

                        // Warn ...
                        console.warn(Console::RETURN, "[Warning]: Attempt to read from `File` failed", Console::NEWLINE);
                        File::clearStreamError(this -> file.stream);
                    }

                    // Return
                    return length ? (char*) File::read(length) : NULL;
                }

                // Return
                return NULL;
            }
            inline String File::readUntilMatchFromFile(File const& file, String const& match, bool const multithreadSafe) { return file.readUntilMatch(match, multithreadSafe); }

            inline String File::readUntilMatch(String::Character const& match, bool const multithreadSafe) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to read un-opened `File`");

                // Initialization > (Element, Length)
                int element;
                unsigned length = 0u;

                // Loop
                #if environment__is_windows
                while (EOF ^ (element = multithreadSafe ? ::_getc_nolock(this -> stream) : ::getc(this -> stream))) {
                #else
                while (EOF ^ (element = multithreadSafe ? ::getc_unlocked(this -> stream) : ::getc(this -> stream))) {
                #endif
                    // Update > Length
                    // : Logic > Terminate
                    ++length;
                    if (match == (char) element) break;
                }

                // Logic
                if (EOF == element && ::ferror(this -> stream)) {
                    // Update > Length
                    length = 0u;

                    // Warn ...
                    console.warn(Console::RETURN, "[Warning]: Attempt to read from `File` failed", Console::NEWLINE);
                    File::clearStreamError(this -> file.stream);
                }

                // Return
                return length ? (char*) File::read(length) : NULL;
            }
            inline String File::readUntilMatchFromFile(File const& file, String::Character const& match, bool const multithreadSafe) { return file.readUntilMatch(match, multithreadSafe); }

            // Re-Open
            inline bool File::reopen(String const& path, Attribute const attribute) const { File::close(); return File::open(path, attribute); }
            inline bool File::reopenFile(File const& file, String const& path, Attribute const attribute) { return file.reopen(path, attribute); }

            // Remove ... --- NOTE (Lapys) -> Close the file handler before removing its path.
            inline bool File::remove(bool const multithreadSafe) const { if (File::isClosed()) throw LogicException("Attempt to delete un-opened `File`"); else File::close(); return File::removePath(File::getName(), multithreadSafe); }
            inline bool File::removeFile(File const& file, bool const multithreadSafe) { return file.remove(multithreadSafe); }
            inline bool File::removePath(String const& path, bool const multithreadSafe) noexcept {
                // Logic
                #if environment__is_windows
                    return 0 != ::DeleteFileA(path);
                #elif environment__is_posix
                    if (::unlink(path) == -1)
                #else
                    if (0 != ::remove(path))
                #endif

                {
                    // Logic > Warn
                    switch (errno) {
                        case EACCES: console.warn(Console::RETURN, "[Warning]: Attempt to remove un-permitted file path", Console::NEWLINE); break;
                        case EBUSY: console.warn(Console::RETURN, "[Warning]: Attempt to remove currently used file path or STREAMS-based file", Console::NEWLINE); break;
                        case ELOOP: console.warn(Console::RETURN, "[Warning]: Attempt to remove file path with unresolved loops in its symbolic links", Console::NEWLINE); break;
                        case ENAMETOOLONG: console.warn(Console::RETURN, "[Warning]: Attempt to remove excessively long file path", Console::NEWLINE); break;
                        case ENOENT: console.warn(Console::RETURN, "[Warning]: Attempt to remove non-existing file path", Console::NEWLINE); break;
                        case ENOTDIR: console.warn(Console::RETURN, "[Warning]: Attempt to remove invalid file path", Console::NEWLINE); break;
                        case EPERM: console.warn(Console::RETURN, "[Warning]: Attempt to remove directory, not file path", Console::NEWLINE); break;
                        case EROFS: console.warn(Console::RETURN, "[Warning]: Attempt to remove read-only file of file path", Console::NEWLINE); break;
                        case ETXTBSY: console.warn(Console::RETURN, "[Warning]: Attempt to remove pure procedure (shared text) currently executed file of file path", Console::NEWLINE); break;
                    }

                    // Return
                    return false;
                }

                // Return
                return true;
            }

            // Rename ...
            inline bool File::rename(String const& path) const { if (File::isClosed()) throw LogicException("Attempt to rename un-opened `File`"); return File::renamePath(path, File::getName()); }
            inline bool File::renameFile(File const& file, String const& path) { return file.renamePath(path); }
            inline bool File::renamePath(String const& destinationPath, String const& sourcePath) {
                // Logic
                #if environment__is_windows
                    // Return
                    return 0 != ::MoveFile(sourcePath, destinationPath);
                #else
                    // Logic
                    if (::rename(sourcePath, destinationPath) == -1) {
                        // Logic > Warn
                        switch (errno) {
                            case EACCES: console.warn(Console::RETURN, "[Warning]: Attempt to rename un-permitted file path", Console::NEWLINE); break;
                            case EBUSY: console.warn(Console::RETURN, "[Warning]: Attempt to rename currently used file path", Console::NEWLINE); break;
                            case EEXIST: case ENOTEMPTY: console.warn(Console::RETURN, "[Warning]: Attempt to rename non-existing file path", Console::NEWLINE); break;
                            case EINVAL: console.warn(Console::RETURN, "[Warning]: Attempt to rename self-referencing file path", Console::NEWLINE); break;
                            case EIO: console.warn(Console::RETURN, "[Warning]: Attempt to rename file path while I/O error occurred", Console::NEWLINE); break;
                            case EISDIR: case EPERM: console.warn(Console::RETURN, "[Warning]: Attempt to rename directory, not file path", Console::NEWLINE); break;
                            case ELOOP: console.warn(Console::RETURN, "[Warning]: Attempt to rename file path with unresolved loops in its symbolic links", Console::NEWLINE); break;
                            case EMLINK: console.warn(Console::RETURN, "[Warning]: Attempt to rename file path with an excess link count", Console::NEWLINE); break;
                            case ENAMETOOLONG: console.warn(Console::RETURN, "[Warning]: Attempt to rename excessively long file path", Console::NEWLINE); break;
                            case ENOENT: console.warn(Console::RETURN, "[Warning]: Attempt to rename non-existing file path", Console::NEWLINE); break;
                            case ENOSPC: console.warn(Console::RETURN, "[Warning]: Attempt to rename file path with non-extend-able directory", Console::NEWLINE); break;
                            case ENOTDIR: console.warn(Console::RETURN, "[Warning]: Attempt to rename invalid file path", Console::NEWLINE); break;
                            case EROFS: console.warn(Console::RETURN, "[Warning]: Attempt to rename read-only file of file path", Console::NEWLINE); break;
                            case ETXTBSY: console.warn(Console::RETURN, "[Warning]: Attempt to rename pure procedure (shared text) currently executed file of file path", Console::NEWLINE); break;
                            case EXDEV: console.warn(Console::RETURN, "[Warning]: Attempt to rename file path onto different file systems");
                        }

                        // Return
                        return false;
                    }

                    // Return
                    return true;
                #endif
            }

            // Seek
            inline bool File::seek(long const position, SeekAnchor const anchor, bool const multithreadSafe) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to seek to internal position of un-opened `File`");

                // Initialization > Offset
                int offset = -1;

                // Logic ... > Update > Offset
                #if environment__is_windows
                    if (multithreadSafe) offset = ::_fseek_nolock(this -> stream, offset, File::translateSeekAnchor(anchor));
                    else
                #endif
                offset = ::fseek(this -> stream, offset, File::translateSeekAnchor(anchor));

                // Logic
                if (0 == offset)
                    // Return
                    return true;

                else {
                    // Logic > Warn
                    switch (errno) {
                        case EINVAL: console.warn(Console::RETURN, "[Warning]: Attempt to seek `FILE*` file stream with an invalid anchor or resulting negative file offset", Console::NEWLINE); break;
                        case ESPIPE: console.warn(Console::RETURN, "[Warning]: Attempt to seek `FILE*` file stream on un-seekable file", Console::NEWLINE); break;
                    }
                }

                // Return
                return false;
            }
            inline bool File::seekFile(File const& file, long const position, SeekAnchor const anchor, bool const multithreadSafe) { return file.seek(position, anchor, multithreadSafe); }

            inline bool File::seekTo(long const position, bool const multithreadSafe) const { return File::seek(position, File::BEGIN); }
            inline bool File::seekFileTo(File const& file, long const position, bool const multithreadSafe) { return file.seekTo(position, multithreadSafe); }

            inline bool File::seekToBeginning(void) const noexcept { ::rewind(this -> stream); return true; }
            inline bool File::seekFileToBeginning(File const& file) noexcept { return file.seekToBeginning(); }

            inline bool File::seekToEnd(bool const multithreadSafe) const { File::seek(0L, File::END); }
            inline bool File::seekFileToEnd(File const& file, bool const multithreadSafe) { return file.seekToEnd(multithreadSafe); }

            // Translate Buffer
            constexpr inline int File::translateBuffer(Buffer const buffer) noexcept {
                // Logic > Return
                switch (buffer) {
                    case File::FULL: return _IOFBF;
                    case File::LINE: return _IOLBF;
                }

                // Return
                return _IONBF;
            }

            // Translate Seek Anchor
            constexpr inline int File::translateSeekAnchor(SeekAnchor const anchor) noexcept {
                // Logic > Return
                switch (anchor) {
                    case File::BEGIN: return SEEK_SET;
                    case File::CURRENT: return SEEK_CUR;
                    case File::END: return SEEK_END;
                }

                // Return
                return -1;
            }

            // Write --- WARN (Lapys) -> Data transfer to file is left to C++'s C standard implementation.
            template <class type> inline bool File::write(DynamicArray<type> const& content, bool const multithreadSafe) { return File::write(content.valueOf(), content.length, multithreadSafe); }
            template <class type> inline bool File::writeToFile(File const& file, DynamicArray<type> const& content, bool const multithreadSafe) { return file.write(content, multithreadSafe); }

            inline bool File::write(String const& content, bool const multithreadSafe) { return File::write(content.toASCII(), content.length, multithreadSafe); }
            inline bool File::writeToFile(File const& file, String const& content, bool const multithreadSafe) { return file.write(content, multithreadSafe); }

            inline bool File::write(void* const content, unsigned const, bool const) const { throw TypeException("Attempt to write incomplete data (type) to `File`"); return false; }
            inline bool File::writeToFile(File const& file, void* const content, unsigned const count, bool const multithreadSafe) { return file.write(content, count, multithreadSafe); }

            inline bool File::write(void const* const content, unsigned const, bool const) const { throw TypeException("Attempt to write incomplete data (type) to `File`"); return false; }
            inline bool File::writeToFile(File const& file, void const* const content, unsigned const count, bool const multithreadSafe) { return file.write(content, count, multithreadSafe); }

            template <class type>
            inline bool File::write(type* const content, unsigned const count, bool const multithreadSafe) const {
                // Logic > Error
                if (File::isClosed()) throw LogicException("Attempt to write to un-opened `File`");

                // Initialization > Elements Written
                size_t elementsWritten = 0u;

                // Logic > Update > Elements Written
                #if environment__is_windows
                    elementsWritten = multithreadSafe ? ::_fwrite_nolock(content, sizeof(type), count, this -> stream) : ::fwrite(content, sizeof(type), count, this -> stream);
                #else
                    elementsWritten = multithreadSafe ? ::fwrite_unlocked(content, sizeof(type), count, this -> stream) : ::fwrite(content, sizeof(type), count, this -> stream);
                #endif

                // ...; Logic
                File::seek(-(signed) elementsWritten, File::CURRENT);
                if (elementsWritten ^ count) {
                    // Logic > Warn ...
                    if (::ferror(this -> stream)) {
                        console.warn(Console::RETURN, "[Warning]: Attempt to write to `File` failed", Console::NEWLINE);
                        File::clearStreamError(this -> stream);
                    }

                    // Return
                    return false;
                }

                // Return
                return true;
            }
            template <class type> inline bool File::writeToFile(File const& file, type* const content, unsigned const count, bool const multithreadSafe) { return file.write(content, count, multithreadSafe); }
