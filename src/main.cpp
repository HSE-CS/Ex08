// Copyright 2020 sccc
#include <iostream>
#include <string>
#include "MyString.h"

int main() {
    MyString str("hello");
    std::cout << str.length() << std::endl;
    MyString str2("123");
    MyString str3 = str + str2;
    std::cout << str3.get() << std::endl;
    MyString a("123456789");
    MyString b("2468");
    MyString c;
    c = a - b;
    MyString d("454545");
    std::cout << d("33") << std::endl;
}
