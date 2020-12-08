//  Copyright 2020 Trutnev Alexey

#include "MyString.h"

int main() {
    MyString a;
    MyString b("Press");
    MyString c("F");
    std::cout << b << std::endl;        // output

    MyString d("to pay respect");
    MyString temp(" ");
    a = b + temp + c + temp + d;
    std::cout << a << std::endl;        // concatenation

    a = b + temp + c * 15 + temp + d;
    std::cout << a.get() << std::endl;  // get function and operator*

    a = !a;                             // changing registers
    std::cout << a << std::endl;
    std::cout << a.length() << std::endl;
    std::cout << a[0] << std::endl;
    std::cout << (b == c) << std::endl;
}
