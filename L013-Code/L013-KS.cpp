#include <iostream>
#include <algorithm>
#include "L013-KS.hpp"

Buffer::Buffer(size_t s) : size(s), data(new int[s]) {
    std::cout << "Constructor called\n";
}
    
Buffer::~Buffer() {
    delete[] data;
    std::cout << "Destructor called\n";
}
    
// TODO: Add copy constructor and assignment operator
// Copy Constructor
Buffer::Buffer (const Buffer& other) : size(other.size), data(new int[other.size]){
    std::copy(other.data, other.data + size, data);
    std::cout << "Constructor Copy Called\n";
}

// Copy Assigment

Buffer& Buffer::operator=(const Buffer& other){
    if (this != &other){
        delete[] data;
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + size, data);
        std::cout << "Copy Assigment Called\n";   
    }
    return *this;
}

// TODO: Add move constructor and move assignment operator
Buffer::Buffer(Buffer&& other) noexcept : size(other.size), data(other.data){
    std::cout << "Move Constructor Called\n";
    other.data = nullptr;
    other.size = 0;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept{
    if (this != &other){
        delete[] data;
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;
        std::cout << "Move Assigment Called\n";
    }
    return *this;
}
