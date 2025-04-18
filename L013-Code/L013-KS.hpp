#include <iostream>
#include <cstddef> 

class Buffer {
    private:
        int* data;       // Puntero al arreglo dinámico
        size_t size;     // Tamaño del arreglo
    
    public:
        // Constructor
        Buffer(size_t s);
    
        // Destructor
        ~Buffer();
    
        // Copy Constructor
        Buffer(const Buffer& other);

        // Copy Assigment
        Buffer& operator=(const Buffer& other);

        // Move Constructor
        Buffer(Buffer&& other) noexcept;

        // Move Assigment
        Buffer& operator=(Buffer&& other) noexcept;
};
