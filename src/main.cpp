// Copyright Mushka Nikita 2020

#include "MyString.h"
#include <iostream>

int main() {

    MyString null;
    std::cout << null.length() << '\n';

    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    std::cout << s3 << '\n';
    std::cout << s3("ll") << '\n';   // 2
    std::cout << s3("mama") << '\n'; // -1

    MyString str1("123456789");
    MyString str2("457");
    MyString str3 = str2;

    std::cout << str3 << '\n';

    std::cout << (str1 + str2).get() << '\n';
    std::cout << (str1 - str2).get() << '\n';
    std::cout << (str1 * 3).get() << '\n';
    std::cout << (str1 == str2) << '\n';
    std::cout << (str1 != str2) << '\n';
    std::cout << (str1 > str2) << '\n';
    std::cout << (str1 <= str2) << '\n';
    std::cout << (str1[3]) << '\n';
    std::cout << str1("234") << '\n';
}
