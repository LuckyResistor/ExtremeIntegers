// https://luckyresistor.me Learn C++


#include <TypeInfo.hpp>


auto main() -> int {
    std::cout << "Type from Literal:\n";
    std::cout << "100         => " << TypeInfo(100).str() << "\n";
    std::cout << "070         => " << TypeInfo(070).str() << "\n";
    std::cout << "0b10001000  => " << TypeInfo(0b10001000).str() << "\n";
    std::cout << "0b10001000u => " << TypeInfo(0b10001000u).str() << "\n";
    std::cout << "0x1000      => " << TypeInfo(0x1000).str() << "\n";
    std::cout << "0x1000u     => " << TypeInfo(0x1000u).str() << "\n";
    std::cout << "100u        => " << TypeInfo(100u).str() << "\n";
    std::cout << "100l        => " << TypeInfo(100l).str() << "\n";
    std::cout << "100ul       => " << TypeInfo(100ul).str() << "\n";
    std::cout << "100ll       => " << TypeInfo(100ll).str() << "\n";
    std::cout << "100ull      => " << TypeInfo(100ull).str() << "\n";
}

