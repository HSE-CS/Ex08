// Copyright 2020 PolinaP
#include <iostream>
#include "MyString.h"
#include <string>
#include <cstring>

int main() {
    MyString b("Privet");
    std::string str = "Andrey";
    MyString c(str);
    MyString d(c);
    MyString a;
    a = b + c;
    std::cout << b.get() << "\t" << b.length() << std::endl;
    std::cout << c.get() << "\t" << c.length() << std::endl;
    std::cout << d.get() << "\t" << d.length() << std::endl;
    std::cout << (b + c).get() << "\t" << (b + c).length() << std::endl;
    std::cout << (b - c).get() << "\t" << (b - c).length() << std::endl;
    std::cout << (b * 3).get() << "\t" << (b * 3).length() << std::endl;
    std::cout << a.get() << "\t" << a.length() << std::endl;
    if (d == c)
        std::cout << "Equal" << std::endl;
    else
        std::cout << "Not equal" << std::endl;
    if (d != b)
        std::cout << "Not Equal" << std::endl;
    else
        std::cout << "Equal" << std::endl;
    std::cout << (!b).get() << "\t" << (!b).length() << std::endl;
    MyString aa("123");
    MyString bb;
    MyString cc;
    cc = aa + bb;
    std::cout << cc << std::endl;
    return 0;