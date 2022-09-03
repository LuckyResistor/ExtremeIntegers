// https://luckyresistor.me Learn C++


#include <TypeInfo.hpp>


void literals() {
    std::cout << "Unexpected Side Effects:\n";
    auto int8a = std::numeric_limits<int8_t>::min();
    auto int8b = -128;
    int8_t int8c = -128;
    std::cout << "int8a = " << TypeInfo(int8a).str() << "\n";
    std::cout << "int8b = " << TypeInfo(int8b).str() << "\n";
    std::cout << "int8c = " << TypeInfo(int8c).str() << "\n\n";

    auto int16a = std::numeric_limits<int16_t>::min();
    auto int16b = -32'768;
    int16_t int16c = -32'768;
    std::cout << "int16a = " << TypeInfo(int16a).str() << "\n";
    std::cout << "int16b = " << TypeInfo(int16b).str() << "\n";
    std::cout << "int16c = " << TypeInfo(int16c).str() << "\n\n";

    auto int32a = std::numeric_limits<int32_t>::min();
    auto int32b = -2'147'483'648;
    int32_t int32c = -2'147'483'648;
    std::cout << "int32a = " << TypeInfo(int32a).str() << "\n";
    std::cout << "int32b = " << TypeInfo(int32b).str() << "\n";
    std::cout << "int32c = " << TypeInfo(int32c).str() << "\n\n";

    auto int64a = std::numeric_limits<int64_t>::min();
    auto int64b = -9'223'372'036'854'775'808ll;
    int64_t int64c = -9'223'372'036'854'775'808ll;
    std::cout << "int64a = " << TypeInfo(int64a).str() << "\n";
    std::cout << "int64b = " << TypeInfo(int64b).str() << "\n";
    std::cout << "int64c = " << TypeInfo(int64c).str() << "\n\n";
}

void sideEffects() {
    std::cout << "Side Effects:\n";
    auto r1 = -9'223'372'036'854'775'808ll / 10'000'000;
    std::cout << "-9'223'372'036'854'775'808ll / 10'000'000 = " << TypeInfo(r1).str() << "\n";
    int64_t r2 = -9'223'372'036'854'775'808ll / 10'000'000;
    std::cout << "int64_t{-9'223'372'036'854'775'808ll / 10'000'000} = " << TypeInfo(r2).str() << "\n";
    auto r3 = std::numeric_limits<int64_t>::min() / 10'000'000;
    std::cout << "std::numeric_limits<int64_t>::min() / 10'000'000 = " << TypeInfo(r3).str() << "\n";
}

auto main() -> int {
    literals();
    sideEffects();
    return 0;
}

