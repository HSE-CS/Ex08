// Copyright 2020 Uskova
#include "MyString.h"
#include <iostream>

int main() {
    MyString a("Hello");
    std::cout << "Length a = Hello : " << a.length() << std::endl;
    std::cout << "a = " << a.get() << std::endl;
    MyString b(" world!");
    MyString c;
    c = a + b;
    std::cout << "c = a + b : " << c.get() << std::endl;
    MyString d("Hell");
    c = a - d;
    std::cout << "c = Hello - Hell : " << c.get() << std::endl;
    c = a * 2;
    std::cout << "a*2 = " << c.get() << std::endl;
    MyString e("123");
    MyString f("1234");
    std::cout << "123 == 1234 : " << (e == f) << std::endl;
    std::cout << "123 <= 1234 : " << (e <= f) << std::endl;
    c = !a;
    std::cout << "!Hello = " << c.get() << std::endl;
    std::cout << "a[1] = " << a[1] << std::endl;
    MyString k("123");
    int r = 3;
    c = k * r;
    std::cout << "c = k * r : " << c.get() << std::endl;
}
