// Copyright 2020 BekusovMikhail

#include <iostream>
#include "MyString.h"

int main() {
    MyString a;
    std::cout << a.length() << std::endl;
    MyString b("hello");
    std::cout << b.length() << std::endl;
    MyString c("123");
    MyString d(c);
    std::cout << d.get() << std::endl;
    MyString e = d + c;
    std::cout << e.get() << std::endl;
    MyString z(e * 3);
    std::cout << z << std::endl;
}
