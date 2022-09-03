// https://luckyresistor.me Learn C++


#include <TypeInfo.hpp>


#include <cmath>


template<typename T>
constexpr T badSaturatingSubtract(T a, T b) noexcept {
    // BAD CODE! Signed integer overflow is undefined.
    static_assert(std::is_integral_v<T>);
    if (b == 0) return a;
    const T result = a - b;
    if constexpr (std::is_signed_v<T>) {
        if ((result < a) == std::signbit(b)) {
            return std::signbit(b) ? std::numeric_limits<T>::max() : std::numeric_limits<T>::min();
        }
    } else {
        if (result > a) {
            return 0;
        }
    }
    return result;
}


template<typename T>
inline void doShadySaturatingMath(T a, T b) noexcept {
    auto result = badSaturatingSubtract(a, b);
    std::cout << "badSaturatingSubtract(" << TypeInfo(a).str() << ", " << TypeInfo(b).str() << ") = "
              << TypeInfo(result).str() << "\n";
}


template<typename T>
inline void doShadySaturatingMath() noexcept {
    auto a = std::numeric_limits<T>::min();
    auto b = T{1};
    doShadySaturatingMath(a, b);
    a = std::numeric_limits<T>::max();
    b = T{-1};
    doShadySaturatingMath(a, b);
    a = T{-100};
    b = T{-500};
    doShadySaturatingMath(a, b);
}


auto main() -> int {
    std::cout << "\nSigned Math 16-bit:\n";
    doShadySaturatingMath<int16_t>();
    std::cout << "\nSigned Math 32-bit:\n";
    doShadySaturatingMath<int32_t>();
    std::cout << "\nSigned Math 64-bit:\n";
    doShadySaturatingMath<int64_t>();
    return 0;
}

