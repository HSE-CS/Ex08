// Copyright 2020 JGMax

#include <iostream>
#include "MyString.h"

int main() {
    std::string str = "asd";
    MyString string("abca");
    MyString string1(str);
    std::cout << string << std::endl;
    std::cout << string1 << std::endl;

    MyString string2 = string1 + string;
    std::cout << string2 << std::endl;

    string2 = string1 - string;
    std::cout << string2 << std::endl;
    string2 = string2*3;
    std::cout << string2 << std::endl;
    string2 = string1;

    bool isEqual = string1 == string2;
    std::cout << isEqual << std::endl;
    isEqual = string2 == string;
    std::cout << isEqual << std::endl;

    bool a = string1 > string;
    std::cout << a << std::endl;

    string2 = !string;
    std::cout << string2 << std::endl;

    std::cout << string2[1] << std::endl;
    std::cout << string2[-2] << std::endl;
    std::cout << string2("CA") << std::endl;

    return 0;
}
