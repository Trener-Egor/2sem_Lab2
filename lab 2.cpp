#include <iostream>
#include <fstream>
#include "Vector.hpp"

int main()
{   
    /*std::cout<<sizeof vector<< "\n";
    vector a(3);
    std::cin >> a;
    std::cout << "a: " << a << "\n";
    vector b(a);
    std::cin >> b;
    std::cout << "b: " << b << "\n";
    vector c = b;
    std::cout << "c: " << c << "\n";
    vector d = std::move(c);
    c.~vector();
    std::cout << "d: " << d << "\n";*/

    std::ifstream file("input.txt");

    if(!file.is_open())
    {
        std::cout << "errror: file not open \n";
        return 1;
    }

    int dim;
    file >> dim;
    vector v1(dim);
    vector v2(dim);
    for(int i =0;i<dim;++i)
    {
        file >> v1[i];
    }
    for (int i = 0; i < dim; ++i)
    {
        file >> v2[i];
    }
    std::cout << "vector1 :\n";
    std::cout << v1 << "\n";

    std::cout << "vector2 :\n";
    std::cout << v2 << "\n";
    double sk = v1 * v2;
    std::ofstream out("out.txt");

    if (!out.is_open())
    {
        std::cout << "errror: file not open \n";
        return 1;
    }
    out << "dot product: " << sk << "\n";
}
