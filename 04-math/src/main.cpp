// https://luckyresistor.me Learn C++


#include <TypeInfo.hpp>


template<typename T>
constexpr auto unsignedAbs(T value) -> std::make_unsigned_t<T> {
    static_assert(std::is_integral_v<T>);
    if constexpr (std::is_signed_v<T>) {
        using R = std::make_unsigned_t<T>;
        return (value == std::numeric_limits<T>::min()) ?
            (static_cast<R>(std::numeric_limits<T>::max()) + R{1u}) :
            static_cast<R>(std::abs(value));
    } else {
        return value;
    }
}


template<typename T>
constexpr auto unsignedAbs_undefined(T value) -> std::make_unsigned_t<T> {
    // THIS IS BAD CODE! IT RELIES ON UNDEFINED COMPILER BEHAVIOUR!
    static_assert(std::is_integral_v<T>);
    return static_cast<std::make_unsigned_t<T>>(std::abs(value));
}


void makePositive() {
    std::cout << "Make Positive:\n";
    int8_t r1 = std::numeric_limits<int8_t>::min() * int8_t{-1};
    std::cout << "int8_t r1 = std::numeric_limits<int8_t>::min() * int8_t{-1}; r1 = " << TypeInfo(r1).str() << "\n";
    int32_t r2 = std::numeric_limits<int32_t>::min() * -1;
    std::cout << "int32_t r2 = std::numeric_limits<int32_t>::min() * -1; r2 = " << TypeInfo(r2).str() << "\n";
    int8_t r3 = std::abs(std::numeric_limits<int8_t>::min());
    std::cout << "int8_t r3 = std::abs(std::numeric_limits<int8_t>::min()); r3 = " << TypeInfo(r3).str() << "\n";
    int32_t r4 = std::abs(std::numeric_limits<int32_t>::min());
    std::cout << "int32_t r4 = std::abs(std::numeric_limits<int32_t>::min()); r4 = " << TypeInfo(r4).str() << "\n\n";
}


void makePositiveWithAuto() {
    std::cout << "Make Positive Using 'auto':\n";
    auto r1 = std::numeric_limits<int8_t>::min() * int8_t{-1};
    std::cout << "auto r1 = std::numeric_limits<int8_t>::min() * int8_t{-1}; r1 = " << TypeInfo(r1).str() << "\n";
    auto r2 = std::numeric_limits<int32_t>::min() * -1;
    std::cout << "auto r2 = std::numeric_limits<int32_t>::min() * -1; r2 = " << TypeInfo(r2).str() << "\n";
    auto r3 = std::abs(std::numeric_limits<int8_t>::min());
    std::cout << "auto r3 = std::abs(std::numeric_limits<int8_t>::min()); r3 = " << TypeInfo(r3).str() << "\n";
    auto r4 = std::abs(std::numeric_limits<int32_t>::min());
    std::cout << "auto r4 = std::abs(std::numeric_limits<int32_t>::min()); r4 = " << TypeInfo(r4).str() << "\n";
    auto r5 = static_cast<uint32_t>(std::abs(std::numeric_limits<int32_t>::min()));
    std::cout << "auto r5 = static_cast<uint32_t>(std::abs(std::numeric_limits<int32_t>::min())); r5 = " << TypeInfo(r5).str() << "\n\n";
}


void makeUnsignedPositive() {
    std::cout << "Make Unsigned Positive:\n";
    auto r1 = unsignedAbs(std::numeric_limits<int8_t>::min());
    std::cout << "auto r1 = unsignedAbs(std::numeric_limits<int8_t>::min()); r1 = " << TypeInfo(r1).str() << "\n";
    auto r2 = unsignedAbs(std::numeric_limits<int16_t>::min());
    std::cout << "auto r2 = unsignedAbs(std::numeric_limits<int16_t>::min()); r2 = " << TypeInfo(r2).str() << "\n";
    auto r3 = unsignedAbs(std::numeric_limits<int32_t>::min());
    std::cout << "auto r3 = unsignedAbs(std::numeric_limits<int32_t>::min()); r3 = " << TypeInfo(r3).str() << "\n";
    auto r4 = unsignedAbs(std::numeric_limits<int64_t>::min());
    std::cout << "auto r4 = unsignedAbs(std::numeric_limits<int64_t>::min()); r4 = " << TypeInfo(r4).str() << "\n\n";
}


void makeUnsignedPositiveUndefinedBehaviour() {
    std::cout << "Make Unsigned Positive (undefined behaviour):\n";
    auto r1 = unsignedAbs_undefined(std::numeric_limits<int8_t>::min());
    std::cout << "auto r1 = unsignedAbs_undefined(std::numeric_limits<int8_t>::min()); r1 = " << TypeInfo(r1).str() << "\n";
    auto r2 = unsignedAbs_undefined(std::numeric_limits<int16_t>::min());
    std::cout << "auto r2 = unsignedAbs_undefined(std::numeric_limits<int16_t>::min()); r2 = " << TypeInfo(r2).str() << "\n";
    auto r3 = unsignedAbs_undefined(std::numeric_limits<int32_t>::min());
    std::cout << "auto r3 = unsignedAbs_undefined(std::numeric_limits<int32_t>::min()); r3 = " << TypeInfo(r3).str() << "\n";
    auto r4 = unsignedAbs_undefined(std::numeric_limits<int64_t>::min());
    std::cout << "auto r4 = unsignedAbs_undefined(std::numeric_limits<int64_t>::min()); r4 = " << TypeInfo(r4).str() << "\n\n";
}


auto main() -> int {
    makePositive();
    makePositiveWithAuto();
    makeUnsignedPositive();
    makeUnsignedPositiveUndefinedBehaviour();
    return 0;
}

