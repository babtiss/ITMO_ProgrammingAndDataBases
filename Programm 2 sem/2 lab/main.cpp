#include <iostream>
#include <vector>
#include "kek.h"

int main() {


    std::vector<int> v = {3, 2};
    std::vector<int> d = {8, 9, 10};
    Polynomial a1(2, v);
    Polynomial a2(3, d);
    Polynomial a3=a2*3;
    a3[0]=10000;


    std::cout << a3 <<std::endl;


    return 0;
};
