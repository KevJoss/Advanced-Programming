#include <iostream>
#include <vector>
#include <utility>
#include <chrono>
#include "L013-KS.hpp"

int main() {
    Buffer b1(100);

    // Medir el tiempo del constructor de copia
    {
        auto start_copy = std::chrono::high_resolution_clock::now();
        Buffer b2 = b1; // Llama al constructor de copia
        auto end_copy = std::chrono::high_resolution_clock::now();
        std::cout << "Copy Constructor Duration: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count()
                  << " us\n";
    }

    // Medir el tiempo del move constructor
    {
        auto start_move = std::chrono::high_resolution_clock::now();
        Buffer b3 = std::move(b1); // Llama al move constructor
        auto end_move = std::chrono::high_resolution_clock::now();
        std::cout << "Move Constructor Duration: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count()
                  << " us\n";
    }

    // Medir el tiempo del operador de asignación por movimiento
    {
        Buffer b4(50);
        auto start_move_assign = std::chrono::high_resolution_clock::now();
        b4 = std::move(b1); // Llama al operador de asignación por movimiento
        auto end_move_assign = std::chrono::high_resolution_clock::now();
        std::cout << "Move Assignment Duration: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end_move_assign - start_move_assign).count()
                  << " us\n";
    }

    return 0;
}