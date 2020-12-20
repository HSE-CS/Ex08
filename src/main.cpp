// Copyright 2020 Kartseva Masha

#include "MyString.h"

int main() {
    MyString s1("1234");
    MyString s2("12345");
    MyString s3("12345");
    MyString s4 = s1 + s2;
    MyString s5 = s2 - s1;
    MyString s6 = s1 * 2;
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;
    std::cout << s6 << std::endl;
    std::cout << (s1 < s2) << std::endl;
    std::cout << (s1 <= s2) << std::endl;
    std::cout << (s1 > s2) << std::endl;
    std::cout << (s1 >= s2) << std::endl;
    std::cout << (s2 == s3) << std::endl;
    MyString s7 = s1;
    std::cout << s7 << std::endl;
    MyString s8("aaaaa");
    std::cout << s8 << std::endl;
    s8[4] = 'm';
    std::cout << s8 << std::endl;
    MyString a("123");
    int b = 3;
    MyString c;
    c = a * b;
    std::cout << c << std::endl;
    return 0;
}
