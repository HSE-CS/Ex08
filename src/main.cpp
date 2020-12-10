// Copyright 2020 Ilya Tatsenko
#include<iostream>
#include"MyString.h"

int main() {
    MyString st("Hello World");
    MyString str("WoTld");
    MyString str2("World");
    MyString str3;
    // MyString tw;
    MyString tw;
    // tw = st * 3 ;
    bool t = str != str2;
    tw = !str;
    std::cin >> str3;
    std::cout << str3 << std::endl;
    std::cout << "leng " << str3.length() << std::endl;
    // std::cin >> str2;
    std::cout << str2("ok");
    std::cout << std::endl;
    std::cout << tw.get() << std::endl;
    std::cout << t;
    return 0;
}
