/* Import */
#include "lapys.hpp" // Lapys
#include <iostream>

/* ... Lapys::Main(ArgumentList const); */
int main(void) {
    class Object final { public:
        struct string_t {
            private: char const *value;
            public:
                constexpr string_t(char const value[]) noexcept : value{value} {}
                // inline string_t& operator =(char const value[]) noexcept { return (this -> value = value), *this; }

                constexpr inline char const* operator +(void) const noexcept { return +(this -> value); }
                // inline char const* operator +(void) noexcept { return ++(this -> value); }
                constexpr operator char const*&(void) const noexcept { return const_cast<char const*&>(this -> value); }
        };

        Lapys::property_accessor<Object, string_t> name;
        Lapys::property_accessor<Object, string_t> subname;

        constexpr string_t& getName(void) const noexcept { return const_cast<string_t&>(static_cast<string_t const&>(this -> name)); }
        constexpr string_t& getSubname(void) const noexcept { return const_cast<string_t&>(static_cast<string_t const&>(this -> subname)); }
    } object = {"Lapys", "Gyrnet"};

    {} std::cout << "[...]: " << object.name << std::endl;
    {} std::cout << "[...]: " << +object.name << std::endl;
    // {} std::cout << "[...]: " << (object.name + 1) << std::endl;
    // {} std::cout << "[...]: " << (1 + object.name) << std::endl;
    // { ++object.name; } std::cout << "[...]: " << object.name << std::endl;
    // { object.name = "Jyrsper"; } std::cout << "[...]: " << object.name << std::endl;
    // { object.name = object.subname; } std::cout << "[...]: " << object.name << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
