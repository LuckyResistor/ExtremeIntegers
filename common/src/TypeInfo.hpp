// https://luckyresistor.me Learn C++
#pragma once


#include "IntegerToString.hpp"

#include <cstdint>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <type_traits>
#include <limits>


template<typename T>
struct TypeInfo {
    T v;
    explicit TypeInfo(const T &v) : v(v) {}

    [[nodiscard]] static auto type() -> std::string {
        std::stringstream ss;
        if constexpr (std::is_integral_v<T>) {
            if constexpr (std::is_unsigned_v<T>) {
                ss << "u";
            }
            ss << "int" << (sizeof(T) * 8u);
        } else if constexpr (std::is_floating_point_v<T>) {
            if constexpr (sizeof(T) == 4) {
                ss << "float";
            } else if constexpr (sizeof(T) == 8){
                ss << "double";
            } else {
                ss << "long double";
            }
        } else if constexpr (std::is_enum_v<T>) {
            ss << "enum";
        } else {
            ss << "??";
        }
        return ss.str();
    }

    [[nodiscard]] auto value() const -> std::string {
        std::stringstream ss;
        if constexpr (std::is_integral_v<T> && sizeof(T) == 1) {
            if (std::is_signed_v<T>) {
                ss << static_cast<int32_t>(v);
            } else {
                ss << static_cast<uint32_t>(v);
            }
        } else if constexpr (std::is_integral_v<T> && sizeof(T) > 8) {
            ss << integerToString(v);
        } else {
            ss << v;
        }
        return ss.str();
    }

    [[nodiscard]] auto str() const -> std::string {
        std::stringstream ss;
        ss << type() << "{" << value() << "}";
        return ss.str();
    }
};


template<typename T>
void printTypeInfo(const std::string &name) {
    std::cout << std::setw(20) << name << ": " << TypeInfo<T>::type() << "\n";
}

