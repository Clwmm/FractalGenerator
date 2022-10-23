#include <iostream>
#include "FractalGenerator.h"

int main()
{
    int verticles = 3, nrpoints = 100, windowSize = 400;
    float x = 1, y = 2;
    std::cout << "Enter the number of vertices[max: 1000]: ";
    std::cin >> verticles;
    std::cout << "Enter the number of points: ";
    std::cin >> nrpoints;
    std::cout << "Enter the quotient of the displacement [x/y]:\nx: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "Enter size of window: ";
    std::cin >> windowSize;
    FractalGenerator a(verticles, nrpoints, x, y, windowSize);

    // e = 2.718 - podstawa logarytmu naturalnego
    // ? = 3.141 - pi
    // ? = 1.618 - z³oty podzia³
    // ? = 0.577 - sta³a Eulera
    // ? = 4.669 - Sta³a Feigenbauma
    // https://pl.wikipedia.org/wiki/Lista_sta%C5%82ych_matematycznych

    /*float a[25] = { 0.577, 1, 1.618, 2, 2.718, 3, 3.142, 4, 4.669, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    for (int v = 3; v < 6; v++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (a[j] < a[i])
                {
                    float x = a[j], y = a[i];
                    std::cout << "x: " << x << " y: " << y << std::endl;
                    FractalGenerator a(v, 100000, x, y, 900);
                }
                else
                    break;
            }
        }
    }*/
   

    return 0;
}