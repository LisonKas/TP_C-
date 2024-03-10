#include <iostream>
#include "fraction.hpp"
#include "utils.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    // f1.display();
    std::cout << f1;
    std::cout << " f2 = ";
    // f2.display();
    std::cout << f2;
    std::cout << std::endl;

    Fraction f3 { f1+f2 };

    std::cout << "add(f1, f2) = ";
    // f3.display(); << std::endl
    std::cout << f3;

    std::cout << std::endl << "sub(f1, f2) = ";
    // (f1-f2).display();
    std::cout << f1-f2;

    std::cout << std::endl << "mul(f1, f2) = ";
    // (f1*f2).display();
    std::cout << f1*f2;

    std::cout << std::endl << "div(f1, f2) = ";
    std::cout << f1/f2;
    std::cout << std::endl;

    //EXO 3
    std::cout << std::endl << "f1 == f2 ? ";
    std::cout << (f1==f2);
    std::cout << std::endl << "f1 != f2 ? ";
    std::cout << (f1!=f2);
    std::cout << std::endl;

    std::cout << std::endl << "f1 == f1 ? ";
    std::cout << (f1==f1);
    std::cout << std::endl << "f1 != f1 ? ";
    std::cout << (f1!=f1);
    std::cout << std::endl;

    std::cout << std::endl << "add(1/6, 2/6) = ";
    std::cout << (Fraction{1, 6}+Fraction{2, 6}) << std::endl;


    //EXO 4
    std::cout << std::endl << "f1 < f2 ? ";
    std::cout << (f1<f2);
    std::cout << std::endl << "f2 < f1 ? ";
    std::cout << (f2<f1);
    std::cout << std::endl << "f1 < f1 ? ";
    std::cout << (f1<f1);
    std::cout << std::endl;


    std::cout << std::endl << "f1 > f2 ? ";
    std::cout << (f1>f2);
    std::cout << std::endl << "f2 > f1 ? ";
    std::cout << (f2>f1);
    std::cout << std::endl << "f1 > f1 ? ";
    std::cout << (f1>f1);
    std::cout << std::endl;


    std::cout << std::endl << "f1 <= f2 ? ";
    std::cout << (f1<=f2);
    std::cout << std::endl << "f2 <= f1 ? ";
    std::cout << (f2<=f1);
    std::cout << std::endl << "f1 <= f1 ? ";
    std::cout << (f1<=f1);
    std::cout << std::endl;


    std::cout << std::endl << "f1 >= f2 ? ";
    std::cout << (f1>=f2);
    std::cout << std::endl << "f2 >= f1 ? ";
    std::cout << (f2>=f1);
    std::cout << std::endl << "f1 >= f1 ? ";
    std::cout << (f1>=f1);
    std::cout << std::endl;


    //EXO 5
    std::cout << std::endl;
    std::cout << "f1 += f2 , f1 = " << simplify(f1 += f2) << std::endl;
    std::cout << "f1 -= f2 , f1 = " << simplify(f1 -= f2) << std::endl;
    std::cout << "f1 *= f2 , f1 = " << simplify(f1 *= f2) << std::endl;
    std::cout << "f1 /= f2 , f1 = " << simplify(f1 /= f2) << std::endl;

    return 0;
}