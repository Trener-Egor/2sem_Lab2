#include <iostream>
#include <fstream>
#include "Vector.hpp"

int main()
{   
    double db[3] = { 1.,2.,3. };

    vector a(db,3);
    std::cin >> a;
    std::cout << "a: " << a << "\n";
    vector b(a);
    std::cin >> b;
    std::cout << "b: " << b << "\n";
    vector c = b;
    std::cout << "c: " << c << "\n";
    vector d = std::move(c);
    c.~vector();
    std::cout << "d: " << d << "\n";

    const vector ca = vector(db, 2);
    std::cout << "const vector[1]: " << ca[1] << std::endl;


    std::ifstream file("input.txt");

    if(!file.is_open())
    {
        std::cout << "errror: file not open \n";
        return 1;
    }

    int dim;
    file >> dim;
    vector v1(dim);
    double* v2 = new double [dim];
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
    vector v2v(v2, dim);
    std::cout << v2v << "\n";

    vector v3 = v1 + v2;
    std::cout << "result\n";
    for(int i = 0;i<v3.get_dim();++i)
    {
        std::cout << v3[i] << ' ';
    }
    std::cout << "\n";
    std::ofstream out("out.txt");

    if (!out.is_open())
    {
        std::cout << "errror: file not open \n";
        return 1;
    }
    out << "operator+: " << v3 << "\n";

    file.close();
    out.close();
    delete[] v2;
}
