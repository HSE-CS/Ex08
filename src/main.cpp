// Copyright 2020 Tyulin Igor

#include "MyString.h"

int main() {
    MyString s1("Hello,");
    std::cout << s1.length() << std::endl;
    MyString s2("world!");
    std::cout << s2.length() << std::endl;
    MyString s3;
    s3 = s1 + s2;
    std::cout << s3 << std::endl;
    std::cout << s3.operator+(s1).get() << std::endl;
    std::cout << s3.operator-(s2).get() << std::endl;
    std::cout << s3.operator*(2).get() << std::endl;
    MyString s4("123");
    MyString s5;
    MyString s6;
    s6 = s4 + s5;
    std::cout << s6;
    return 0;
}
