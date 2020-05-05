/* Class > Object (List) */
struct object;
struct object_list;

/* Class > Object */
typedef struct object {
    // ...
    friend object_list;

    // [...]
    private:
        // Initialization > ID
        unsigned id;

    // [...]
    protected:
        /* Phase > ... */
        inline void initiate() const {}
        inline void reset() const {}
        inline void update() const {}
        inline void terminate() const { std::cout << "[DEBUG : object]" << std::endl; }

    // [...]
    public:
        // [Constructor], [Destructor]
        object(void); ~object(void);
} object;

/* Global > Objects --- NOTE (Lapys) -> A sort of a "garbage collector" for custom types built off the `object` data type. */
struct object_list {
    // ...
    friend object;

    // [...]
    private:
        // Initialization > (Length, Value)
        unsigned length = 0u;
        object *value;

    // [...]
    public:
        // [Constructor]
        inline object_list(void) : value{(object*) (void*) null} {}

        // [Destructor]
        ~object_list(void) { this -> free(); }

        /* Function > (Add, Free, Remove) */
        void add(object* _object) { std::cout << "[ADD]" << std::endl; this -> value = (object*) (pointerIsNull((void*) this -> value) ? pointerAllocateMemory(this -> value, sizeof(object)) : pointerReallocateMemory(this -> value, (this -> length + 1u) * sizeof(object))); *(this -> value + (this -> length)) = *_object; this -> length += 1u; _object -> id = this -> length; }
        void free() { if (this -> length) { std::cout << "[FREE]" << std::endl; while (this -> length) { this -> length -= 1u; (this -> value + (this -> length)) -> terminate(); } this -> length = 0u; (this -> value) -> terminate(); this -> value = (object*) pointerFreeMemory((void*) this -> value); } }
        void remove(object* _object) { if (this -> length) { std::cout << "[REMOVE]" << std::endl; for (unsigned iterator = 0u; iterator ^ (this -> length); iterator += 1u) { if (_object -> id == (this -> value + iterator) -> id) { this -> length -= 1u; while (iterator ^ (this -> length)) { *(this -> value + iterator) = *(this -> value + iterator + 1u); iterator += 1u; } this -> value = (object*) (this -> length ? pointerReallocateMemory((void*) this -> value, this -> length * sizeof(object)) : pointerFreeMemory((void*) this -> value) ); _object -> terminate(); break; } } } }
} objects;

/* Modification > Object > ([Constructor], [Destructor]) */
object::object(void) { objects.add(this); }
object::~object(void) { objects.remove(this); }
