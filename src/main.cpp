// Copyright 2020 by Sozinov Kirill
#include <iostream>
#include "MyString.h"
#include <string>
#include <cstring>

int main() {
    MyString b("Privet");
    std::string ss = "Andrey";
    MyString c(ss);
    MyString d(c);
    MyString a;
    MyString inp;
    a = b;
    
    std::cout << b.get() << "\t" << b.length() << std::endl;
    std::cout << c.get() << "\t" << c.length() << std::endl;
    std::cout << d.get() << "\t" << d.length() << std::endl;
    std::cout << (b + c).get() << "\t" << (b + c).length() << std::endl;
    std::cout << (b - c).get() << "\t" << (b - c).length() << std::endl;
    std::cout << (b * 3).get() << "\t" << (b * 3).length() << std::endl;
    std::cout << a.get() << "\t" << a.length() << std::endl;
    if (d == c)
        std::cout << "Equal" << std::endl;
    else std::cout << "Not equal" << std::endl;
    if (d != b)
        std::cout << "Not Equal" << std::endl;
    else std::cout << "Equal" << std::endl;
    std::cout << (!b).get() << "\t" << (!b).length() << std::endl;
    std::cin >> inp;
    std::cout << inp << std::endl;
    return 0;
}
