#include <iostream>
#include "FractalGenerator.h"

int main()
{
    int verticles = 3, nrpoints = 100, windowSize = 400;
    float x = 1, y = 2;
    std::cout << "\t[Enter only natural numbers]" << std::endl;
    std::cout << "Enter the number of vertices[max: 1000]: ";
    std::cin >> verticles;
    std::cout << "\t[Enter only natural numbers]" << std::endl;
    std::cout << "Enter the number of points: ";
    std::cin >> nrpoints;
    std::cout << "Enter the quotient of the displacement [x/y]:\nx: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "\t[Enter only natural numbers]" << std::endl;
    std::cout << "Enter size of window: ";
    std::cin >> windowSize;
    FractalGenerator a(verticles, nrpoints, x, y, windowSize);
    return 0;
}