// Copyright 2020 GN
#include "MyString.h"
int main() {
    MyString a;
    // std::cout << a.get() << std::endl;
    MyString a1("hello");
    // std::cout << a1.length() << std::endl;
    MyString a2("123");
    MyString b(a2);
    // std::cout << b.get() << std::endl;
    MyString a3("123");
    MyString b2("12");
    MyString c;
    c = a3 - b2;
    // std::cout << c.get() << std::endl;
    MyString a4("123");
    MyString b4;
    MyString c4;
    c4 = a4 + b4;
    // std::cout << c4.get() << std::endl;
    MyString a5("1234");
    MyString b5("123");
    // std::cout << (a5 != b5) << std::endl;
    MyString a6("123");
    MyString b6("1234");
    // std::cout << (b6 >= a6) << std::endl;
    MyString a7("45");
    MyString b7("1234");
    // std::cout << (b7 <= a7) << std::endl;
    MyString a8("ABc");
    MyString b8;
    b8 = !a8;
    // std::cout << b8.get() << std::endl;
    MyString a0("45");
    char b0 = '5';
    // std::cout << a0[1] << std::endl;
    MyString a10("454545");
    // std::cout << a10("32") << std::endl;
    MyString a11("123");
    int b11 = 3;
    MyString c11;
    c11 = a11 * b11;
    // std::cout << c11.get() << std::endl;
}
