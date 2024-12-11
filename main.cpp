#include <iostream>
#include "Monom.h"

int main(){
    Monom a1 = Monom(10, 3, new int16_t[3]{1, 2, 3});
    Monom a2 = Monom(10, 3, new int16_t[3]{1, 2, 3});
    Monom a3 = a1 + a2;
    a3.Print();
    std::cout<<std::endl;
    a3 = a1 - a2;
    a3.Print();
    std::cout<<std::endl;
    a3 = a1 / a2;
    a3.Print();
    std::cout<<std::endl;
    
    return 0;

}
