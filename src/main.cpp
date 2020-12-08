// Copyright 2020 Dolgopolov Alexey
//
// Created by sharg on 09.12.2020.
//


#include "MyString.h"


int main() {
    MyString StrArr;
    std::cout << StrArr.length() << std::endl;
    MyString StrArr_2("YourGodDamnRight");
    std::cout << StrArr_2.length() << std::endl;
    std::cout << StrArr_2.get() << std::endl;
    MyString copyStrArr(StrArr_2);
    std::cout << copyStrArr.length() << std::endl;
    std::cout << copyStrArr.get() << std::endl;
    MyString temp1("INeedMorePower");
    std::cout << copyStrArr.operator+(temp1).get() << std::endl;
    std::cout << copyStrArr.operator-(temp1).get() << std::endl;
    MyString a("242");
    MyString b;
    MyString c;
    c = a + b;
    std::cout << a.get() << std::endl;
    std::cout << c.get() << std::endl;
    return 0;
}
