#include <concepts>
template <typename T>
T maxValue(T a, T b){
    return (a > b) ? a : b;
}

template <typename T>
T maxValue(T a, T b, T c) {
    return maxValue(maxValue(a, b), c);
}

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// Function using the Numeric concept
template <Numeric T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
void printAll(T t) {
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void printAll(T t, Args... args) {
    std::cout << t << " ";
    printAll(args...);
}

template <typename T>
T sum(T t) {
    return t;
}

template <typename T, typename... Args>
T sum(T t, Args... args) {
    return t + sum(args...);
}

template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr int value = 1;
};
template <int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};