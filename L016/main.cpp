#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "L016.hpp"

int main(int argc, char* argv[]) {
    try {
        std::string filename = "Online Retail.csv";
        std::vector<DataFrame> data = readFile(filename);

        std::unordered_map<std::string, int> country_count;
        for (const auto& row : data) {
            country_count[row.Country]++;
        }

        if (argc == 2) {
            std::string country = argv[1];
            auto it = country_count.find(country);
            if (it != country_count.end()) {
                std::cout << "Transacciones para " << country << ": " << it->second << std::endl;
            } else {
                std::cout << "El pais '" << country << "' no existe en la base de datos." << std::endl;
            }
        } else if (argc == 1) {
            int total = 0;
            for (const auto& pair : country_count) {
                total += pair.second;
            }
            std::cout << "Transacciones totales: " << total << std::endl;
            std::cout << "Transacciones por país:\n";
            for (const auto& pair : country_count) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
        } else {
            std::cout << "Uso: " << argv[0] << " [Country]" << std::endl;
        }

    bool only_uk = false;
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--only-uk") {
            only_uk = true;
            break;
        }
    }

    double total_amount = 0.0;
    for (const auto& row : data) {
        try {
            int qty = std::stoi(row.Quantity);
            double price = std::stod(row.UnitPrice);
            if (!only_uk || row.Country == "United Kingdom") {
                total_amount += qty * price;
            }
        } catch (...) {
        }
    }

    if (only_uk) {
        std::cout << "Total de ventas para United Kingdom: " << total_amount << std::endl;
    } else {
        std::cout << "Total de ventas (todos los paises): " << total_amount << std::endl;
    }    
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}