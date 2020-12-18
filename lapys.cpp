/* Import */
#include <iostream>
#include "lapys.hpp" // Lapys

/* ... Lapys::Main(ArgumentList const); */
int main(void) {
    class Object final { public:
        struct string_t final {
            private: char const *value;
            public:
                constexpr string_t(char const value[]) noexcept : value{value} {}
                inline string_t& operator =(char const value[]) noexcept { return (this -> value = value), *this; }

                constexpr inline char const* operator +(void) const noexcept { return "\"[immutable]\""; }
                // inline char const* operator +(void) noexcept { return (this -> value = "\"[mutable]\""); }
                constexpr operator char const*&(void) const noexcept { return const_cast<char const*&>(this -> value); }
        };

        Lapys::property_accessor<Object, string_t> name;
        Lapys::property_accessor<Object, string_t> const subname;

        constexpr string_t& getName(void) const noexcept { return const_cast<string_t&>(static_cast<string_t const&>(this -> name)); }
        constexpr string_t& getSubname(void) const noexcept { return const_cast<string_t&>(static_cast<string_t const&>(this -> subname)); }

        inline char const* getPrefix(void) noexcept { return this -> name.operator +(); }
    } object = {"Lapys", "Gyrnet"};

    // constexpr Object::string_t string = "Hello, World!";
    // std::cout << "[...]: " << string.operator +() << std::endl;

    static_cast<void>(object);
    {} std::cout << "[...]: " << object.name << std::endl;
    // {} std::cout << "[...]: " << object.name.operator +() << std::endl;
    // {} std::cout << "[...]: " << object.getPrefix() << std::endl;
    // {} std::cout << "[...]: " << (object.name + 1) << std::endl;
    // {} std::cout << "[...]: " << (1 + object.name) << std::endl;
    // { ++object.name; } std::cout << "[...]: " << object.name << std::endl;
    // { object.name = "Jyrsper"; } std::cout << "[...]: " << object.name << std::endl;
    // { object.name = object.subname; } std::cout << "[...]: " << object.name << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
