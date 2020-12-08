// Copyright 2020 Khoroshavina Ekaterina
#include "MyString.h"
#include <iostream>

int main() {
    MyString test1("Hello ");
    MyString test2("world");
    MyString test3;
    test3 = test1 + test2;
    std::cout << test3.get() << std::endl;
    test3 = test1 - test2;
    std::cout << test3.get() << std::endl;
    test3 = test1 * 3;
    std::cout << test3.get() << std::endl;
    bool test = test1 == test2;
    std::cout << test << std::endl;
    test = test1 > test2;
    std::cout << test << std::endl;
    test = test1 < test2;
    std::cout << test << std::endl;
}
