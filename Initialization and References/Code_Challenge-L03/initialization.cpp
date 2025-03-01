#include <iostream>
#include <map>
#include <utility>

using values = std::pair<std::pair< int , double> , std::pair< std::string , bool>>;
values uniformIni(int a, double b, std::string c, bool d);
struct Point{
    double x;
    double y;
    double z;
};


int main(){
// Initialization

    // Direct Initialization
    int a(10);
    double b(3.14);
    std::string c("Hello");
    bool d(true);
    std::cout << "Direct Initialization" << std::endl;
    std::cout << "int: " << a << ", "
              << "double: " << b << ", "
              << "string: " << c << ", "
              << "bool: " << d << std::endl;


    std::cout << "Uniform Initialization and Binding Structure" << std::endl;


    // Binding Structure
    auto uniform = uniformIni(a, b, c, d); 
    std::cout << "int: " << uniform.first.first << ", "
    << "double: " << uniform.first.second << ", "
    << "string: " << uniform.second.first << ", "
    << "bool: " << uniform.second.second << std::endl;


// References

    int& refa = uniform.first.first;
    double& refb = uniform.first.second;
    std::string& refc = uniform.second.first;
    bool& refd = uniform.second.second;

    refa = 15;
    refb = 5.1231290;
    refc = "Kevin";
    refd = false;

    std::cout << "Changed reference values" << std::endl;
    std::cout << "int: " << uniform.first.first << ", "
    << "double: " << uniform.first.second << ", "
    << "string: " << uniform.second.first << ", "
    << "bool: " << uniform.second.second << std::endl;


// Structured Binding
    double x{3.15};
    double y{7.65};
    double z{9.876};

    Point point {x, y, z};
    std::cout << "Points (x,y,z)" << std::endl;
    std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;

// Identifying l-values and r-values
/*
a is l-value and 42 is r-value
    a = 42; 

a, b and x is l-value but (a+b) is r-value
    int x = a + b;  

&a is r-value
    &a;  

s and c are l-value but World is r-value
    std::string s = c + " World";

x is l-value but refX is r-value
    int& refX = x;

rref is r-value
    int&& rref = 100;
*/
}


// Uniform Initialization function

values uniformIni(int a, double b, std::string c, bool d){
    return {{a , b} , {c ,d}};
}

