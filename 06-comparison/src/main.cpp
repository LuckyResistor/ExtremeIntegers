// https://luckyresistor.me Learn C++


#include <TypeInfo.hpp>


enum class [[nodiscard]] Ordering {
    Equal,
    Less,
    Greater
};


template<typename A, typename B>
constexpr auto compareInt(A a, B b) noexcept -> Ordering {
    static_assert(std::is_integral_v<A> && std::is_integral_v<B>);
    if constexpr (std::is_signed_v<A> == std::is_signed_v<B>) {
        using C = typename std::common_type_t<A, B>;
        const auto ca = static_cast<C>(a);
        const auto cb = static_cast<C>(b);
        return (ca <= cb) ? ((ca == cb) ? Ordering::Equal : Ordering::Greater) : Ordering::Less;
    } else if constexpr (std::is_signed_v<B>) {
        using C = typename std::common_type_t<A, std::make_unsigned_t<B>>;
        const auto ca = static_cast<C>(a);
        const auto cb = static_cast<C>(b);
        return (b < 0) ? Ordering::Less :
               ((ca <= cb) ? ((ca == cb) ? Ordering::Equal : Ordering::Greater) : Ordering::Less);
    } else {
        using C = std::common_type_t<std::make_unsigned_t<A>, B>;
        const auto ca = static_cast<C>(a);
        const auto cb = static_cast<C>(b);
        return (a < 0) ? Ordering::Greater :
               ((ca <= cb) ? ((ca == cb) ? Ordering::Equal : Ordering::Greater) : Ordering::Less);
    }
}


template<typename A, typename B>
void printIsEqual(A a, B b) {
    const bool isEqual = (a == b);
    std::cout << TypeInfo(a).str() << " == " << TypeInfo(b).str() << " => " << std::boolalpha << isEqual << "\n";
}


template<typename A, typename B>
void printIsLess(A a, B b) {
    const bool isEqual = (a < b);
    std::cout << TypeInfo(a).str() << " < " << TypeInfo(b).str() << " => " << std::boolalpha << isEqual << "\n";
}


template<typename A, typename B>
void printCompareInt(A a, B b) {
    const auto result = compareInt(a, b);
    std::cout << "compareInt(" << TypeInfo(a).str() << ", " << TypeInfo(b).str() << ") => ";
    switch (result) {
        case Ordering::Equal: std::cout << "Equal"; break;
        case Ordering::Less: std::cout << "Less"; break;
        case Ordering::Greater: std::cout << "Greater"; break;
    }
    std::cout << "\n";
}


void languageComparisons() {
    std::cout << "\nC++ Comparisons:\n";
    printIsEqual(0, 0);
    printIsEqual(std::numeric_limits<int32_t>::min(), 0x80000000u);
    printIsEqual(-1, 0xffffffffu);
    printIsLess(-1, 0u);
}


void comparisonsWithCompareInt() {
    std::cout << "\ncompareInt() Comparisons:\n";
    printCompareInt(0, 0);
    printCompareInt(std::numeric_limits<int32_t>::min(), 0x80000000u);
    printCompareInt(-1, 0xffffffffu);
    printCompareInt(-1, 0u);
}


auto main() -> int {
    languageComparisons();
    comparisonsWithCompareInt();
    return 0;
}

