// Copyright 2020 Bodrov Egor

#include "MyString.h"
#include <iostream>

int main() {
    MyString a1("hELLO");
    MyString b1;
    b1 = !a1;
    std::cout << b1.get() << std::endl;  // Hello

    MyString a2("ABCD");
    MyString b2(a2);
    MyString c2;
    c2 = a2 - b2;
    std::cout << c2.length() << std::endl;  // 0

    MyString a3;
    a3 = a1 * 3;
    std::cout << a3.get() << std::endl;  // HelloHelloHello

    MyString b3;
    b3 = a3 - a1;
    std::cout << (b3 <= a3) << std::endl;   // true

    MyString c3(a3);
    std::cout << c3("oHello") << std::endl;  // 4

    std::cout << b1[4] << std::endl;    // o

    return 0;
}
