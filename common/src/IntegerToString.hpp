// https://luckyresistor.me Learn C++
#pragma once


#include <array>
#include <limits>
#include <string>
#include <cstdint>


template<typename T>
auto integerToString(T value) noexcept -> std::string {
    static std::array<char, 37> digits{"0123456789abcdefghijklmnopqrstuvwxyz"};
    constexpr std::size_t maximumDigitCount = std::numeric_limits<T>::digits10 + 2;
    if (value == 0) {
        return {"0"};
    }
    char buffer[maximumDigitCount];
    std::size_t index = maximumDigitCount;
    const bool isNegative = value < 0;
    while (value != 0) {
        index--;
        auto digitIndex = static_cast<int32_t>(value % T{10});
        value /= T{10};
        if (std::is_signed_v<T> && isNegative && digitIndex != 0) {
            if (digitIndex < 0) {
                digitIndex = std::abs(digitIndex);
            } else {
                digitIndex = int32_t{10} - digitIndex;
            }
        }
        buffer[index] = digits[digitIndex];
    }
    std::string result;
    if (isNegative) {
        result += '-';
    }
    std::size_t finalSize = maximumDigitCount - index;
    result.append(std::string(buffer + index, finalSize));
    return result;
}

