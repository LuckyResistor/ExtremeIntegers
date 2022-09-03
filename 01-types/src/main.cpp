// https://luckyresistor.me Learn C++


#include <TypeInfo.hpp>


auto main() -> int {
    std::cout << "Fundamental Language Types:\n";
    printTypeInfo<char              >("char");
    printTypeInfo<wchar_t           >("wchar_t");
    printTypeInfo<signed char       >("signed char");
    printTypeInfo<unsigned char     >("unsigned char");
    printTypeInfo<signed short      >("signed short");
    printTypeInfo<unsigned short    >("unsigned short");
    printTypeInfo<signed int        >("signed int");
    printTypeInfo<unsigned int      >("unsigned int");
    printTypeInfo<signed long       >("signed long");
    printTypeInfo<unsigned long     >("unsigned long");
    printTypeInfo<signed long long  >("signed long long");
    printTypeInfo<unsigned long long>("unsigned long long");
    printTypeInfo<float             >("float");
    printTypeInfo<double            >("double");
    printTypeInfo<long double       >("long double");
    printTypeInfo<bool              >("bool");
    std::cout << "\nDefinitions from <cstdint>:\n";
    printTypeInfo<int8_t            >("int8_t");
    printTypeInfo<uint8_t           >("uint8_t");
    printTypeInfo<int16_t           >("int16_t");
    printTypeInfo<uint16_t          >("uint16_t");
    printTypeInfo<int32_t           >("int32_t");
    printTypeInfo<uint32_t          >("uint32_t");
    printTypeInfo<int64_t           >("int64_t");
    printTypeInfo<uint64_t          >("uint64_t");
    std::cout << "\nMore Definitions from <cstdint>:\n";
    printTypeInfo<int_fast8_t       >("int_fast8_t");
    printTypeInfo<uint_fast8_t      >("uint_fast8_t");
    printTypeInfo<int_fast16_t      >("int_fast16_t");
    printTypeInfo<uint_fast16_t     >("uint_fast16_t");
    printTypeInfo<int_fast32_t      >("int_fast32_t");
    printTypeInfo<uint_fast32_t     >("uint_fast32_t");
    printTypeInfo<int_fast64_t      >("int_fast64_t");
    printTypeInfo<uint_fast64_t     >("uint_fast64_t");
    printTypeInfo<int_least8_t      >("int_least8_t");
    printTypeInfo<uint_least8_t     >("uint_least8_t");
    printTypeInfo<int_least16_t     >("int_least16_t");
    printTypeInfo<uint_least16_t    >("uint_least16_t");
    printTypeInfo<int_least32_t     >("int_least32_t");
    printTypeInfo<uint_least32_t    >("uint_least32_t");
    printTypeInfo<int_least64_t     >("int_least64_t");
    printTypeInfo<uint_least64_t    >("uint_least64_t");
    printTypeInfo<intptr_t          >("intmax_t");
    printTypeInfo<uintptr_t         >("uintmax_t");
    printTypeInfo<intmax_t          >("intmax_t");
    printTypeInfo<uintmax_t         >("uintmax_t");
    return 0;
}

