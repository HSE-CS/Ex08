// Copyright 10.12.20 KostinAndrej
#include<iostream>
#include"MyString.h"

int main() {
//    MyString string("Hello World!");
//    MyString string1("WoRLDDd");
//    MyString string2("World");
//    MyString string3;
//    MyString kk;
//    bool kiki = string != string2;
//    kk = !string;
//    std::cin >> string3;
//    std::cout << string3 << std::endl;
//    std::cout << "leng " << string3.length() << std::endl;
//    std::cout << string2("oki");
//    std::cout << std::endl;
//    std::cout << kk.get() << std::endl;
//    std::cout <<  kiki;
    MyString a("abc123");
    MyString b;
    b = !a;
    std::cout<< b.get();
}
