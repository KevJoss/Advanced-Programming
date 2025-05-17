#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct DataFrame
{
    std::string InvoiceNo;
    std::string StockCode;
    std::string Description;
    std::string Quantity;
    std::string InvoiceDate;
    std::string UnitPrice;
    std::string CustomerID;
    std::string Country;
};

std::vector<DataFrame> readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + filename);
    }
    std::vector<DataFrame> dataRows;
    std::string line;
    bool first_line = true;
while (std::getline(file, line)) {
    if (first_line) {
        first_line = false; // skip header
        continue;
    }
    std::vector<std::string> columns;
    std::string cell;
    bool in_quotes = false;
    std::string value;
    for (char c : line) {
        if (c == '"') {
            in_quotes = !in_quotes;
        } else if (c == ',' && !in_quotes) {
            columns.push_back(value);
            value.clear();
        } else {
            value += c;
        }
    }
    columns.push_back(value);

    if (columns.size() < 8) continue;
    DataFrame data;
    data.InvoiceNo   = columns[0];
    data.StockCode   = columns[1];
    data.Description = columns[2];
    data.Quantity    = columns[3];
    data.InvoiceDate = columns[4];
    data.UnitPrice   = columns[5];
    data.CustomerID  = columns[6];
    data.Country     = columns[7];
    dataRows.push_back(data);
}
    file.close();
    std::cout << "File reading completed. Total rows: " << dataRows.size() << std::endl;
    return dataRows;
}