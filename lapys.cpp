/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

// ...
enum Enumeration { ANY = 1337 };
int function(void) { return 0x45; }
union Object { public: int identity; inline Object(void) : identity(420) {} };
struct String {
    String(char const[] = NULL, ...) {}

    inline char const* operator =(char const[]) const { return "\"Hello, World!\""; }
    inline char const* operator =(String const&) const { return "\"Lorem ipsum\""; }
    inline int operator +(void) const { return 42; }
};

/* Main */
class Dummy {
    private:
        // static char const* get_string(String&) { return "Red sus..."; }

    public:
        Lapys::Utility::property<Dummy, String> name;
        // Lapys::Utility::property<Dummy, String, char const* (String&), &get_string> name;
        inline Dummy(...) : name() {}
};
void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    // ...
    std::cout << "[...]: " << +(Dummy("Lapys").name) << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
