// Copyright 2020 Dmitry Vargin
#include <iostream>
#include "MyString.h"]

int main() {
    MyString myString("Hello, world");
    std::cout << "str.get() = " << myString.get() << std::endl;
    std::cout << "str.length() = " << myString.length() << std::endl;
    std::cout << std::endl;
    MyString s1;
    std::cout << "Enter s1(test cin >>): ";
    std::cin >> s1;
    std::cout << std::endl;
    MyString s2("ASD");
    myString = s1 + s2;
    std::cout << s1 << " + " << s2 << " = " << myString << std::endl;
    std::cout << s1 << " == " << s2 << " = " << (s1 == s2) << std::endl;
    std::cout << "s1[1]" << " = " << s1[1] << std::endl;
    std::cout << "myString(s2)" << " = " << myString("ASD") << std::endl;
    s1 = !myString;
    std::cout << "!myString = " << myString << std::endl;

    return 0;
}
