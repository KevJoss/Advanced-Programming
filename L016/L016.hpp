#pragma once
#include <string>
#include <vector>

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

std::vector<DataFrame> readFile(const std::string& filename);