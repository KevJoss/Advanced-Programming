
#include <iostream>
#include <utility>
#include <cmath>

using quadraticSolution = std::pair<bool , std::pair <double , double>>;
quadraticSolution solveQuadratic(double a, double b, double c);

int main(){

    double a , b , c;
    bool existence; //The existence of roots in the formula
    std::cout << "a: "; std::cin >> a;
    std::cout << "b: "; std::cin >> b;
    std::cout << "c: "; std::cin >> c;

    quadraticSolution solution = solveQuadratic(a,b,c);
    if (solution.first){
        
        std::cout << "Root 1: " << solution.second.first << std::endl;
        std::cout << "Root 2: " << solution.second.second << std::endl;
    }
    else {
        std::cout << "No real roots." << std::endl;
    }
}

quadraticSolution solveQuadratic(double a, double b, double c) {
    double root1 , root2;
    double discriminant;
    discriminant = (std::pow(b, 2)) - (4 * a *c);
    
    if (discriminant >= 0) 
    {

        //Define the x formula solution to obtain the roots
        root1  = (-b + std::sqrt((std::pow(b,2)) - (4 * a *c))) / (2 * a);
        root2 = (-b - std::sqrt((std::pow(b,2)) - (4 * a *c))) / (2 * a);
        return {true , {root1 , root2}};
    } else {

        // If the roots don't exist the standard roots are 0
        return {false , {0.0,0.0}};
    }
}