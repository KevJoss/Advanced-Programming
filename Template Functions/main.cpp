#include <iostream>
#include "Challenge-L09.hpp"

int main(){

    // Task 1.1: Write a Simple Template Function
    std::cout << "\n";
    std::cout << "Simple Template Function\n";
    std::cout << "Max value between 5 and 3: " << maxValue(5, 3) << '\n';
    std::cout << "Max value between 5.5 and 3.3: " << maxValue(5.5, 3.3) << '\n';
    std::cout << "Max value between water and headphones: "  << maxValue("water", "headphones") << '\n'; 

    // Task 1.2: Overload a Template Function
    std::cout << "\n";
    std::cout << "Overload Template Function\n";
    std::cout << "Max value between 10, 27 and 89: " << maxValue(10, 27, 89) << '\n';
    std::cout << "Max value between 10.5, 27.3 and 89.1: " << maxValue(10.5, 27.3, 89.1) << '\n';

    // Task 2.1 Concepts
    std::cout << '\n';
    std::cout << "Concepts\n";
    std::cout << "The result of 18 + 27: "<< add(18, 27) << std::endl;      
    std::cout << "The result of 0.5 + 15.1: " << add(0.5, 15.1) << std::endl;   

    // Task 3.1 Write a Variadic Template Function
    std::cout << "\n";
    std::cout << "Variadic Template Function\n";

    printAll(1, 2.5, "Orange", 'h', 3.14, 5);
    // Task 3.2: Variadic Template for Summation
    std::cout << "\n";
    std::cout << "Variadic Template for Summation\n";
    std::cout << "The result of 7 + 12 + 783 + 1 + 9012 = " << sum(7, 12, 783, 1, 9012) << '\n';            
    std::cout <<  "The result of 1.7 + 28.9 + 14.2 = "  << sum(1.7, 28.9, 14.2) << '\n';  

    // Task 4.1: Compile-Time Factorial Using Templates
    std::cout << "\n";
    std::cout << "Compile-Time Factorial Using Templates\n";
    constexpr int result = Factorial<12>::value;
    std::cout << "The factorial of 12: "<<result << std::endl; 

    //  Task 4.2: Fibonacci Series Using Template Metaprogramming
    std::cout << "\n";
    std::cout << "Fibonacci Series Using Template Metaprogramming\n";
    constexpr int resultFibo = Fibonacci<15>::value;
    std::cout << "The 15th in the Fibonacci sequence is: "<< resultFibo << std::endl;
}   
