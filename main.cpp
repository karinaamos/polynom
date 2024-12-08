#include <iostream>
#include "Monom.h"

int main(){
    std::vector<int> num1 = {2, 1, 0};
    std::vector<int> num2 = {2, 1, 0};
    std::vector<int> num3 = {1, 0, 1};

    Monom m1(3.0, num1);
    Monom m2(2.0, num2);
    Monom m3(4.0, num3);


    std::cout << m1 << std::endl;     // 3x_1^2x_2
    std::cout << m2 << std::endl;     // 2x_1^2x_2
    std::cout << m1 + m2 << std::endl; // 5x_1^2x_2
    std::cout << m1 - m2 << std::endl; // 1x_1^2x_2
    std::cout << m1 * m2 << std::endl; // 6x_1^4x_2^2
    std::cout << m1 / m2 << std::endl; // 1.5

    return 0;

}
