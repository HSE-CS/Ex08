// Copyright 2020 Nikita Stifeev
#include "MyString.h"

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s3(\"ll\"): " << s3("ll") << std::endl;
    std::cout << "s3(\"mama\"): " << s3("mama") << std::endl;
    std::cout << "s3.length(): " << s3.length() << std::endl;
    std::cout << "s3[0]: " << s3[0] << std::endl;
    std::cout << "s3[2]: " << s3[2] << std::endl;
    std::cout << "s3[5]: " << s3[5] << std::endl;
    std::cout << "!s3: " << !s3 << std::endl;
    std::cout << "s1 * 3: " << (s1 * 3) << std::endl;
    std::cout << "s1 - s2: " << (s1 - s2) << std::endl;
    std::cout << "s1 == s2: " << (s1 == s2 ? "yes" : "no") << std::endl;
    std::cout << "s1 != s2: " << (s1 != s2 ? "yes" : "no") << std::endl;
    std::cout << "s1 < s2: " << (s1 < s2 ? "yes" : "no") << std::endl;
    std::cout << "s1 > s2: " << (s1 > s2 ? "yes" : "no") << std::endl;
    std::cout << "s1 <= s2: " << (s1 <= s2 ? "yes" : "no") << std::endl;
    std::cout << "s1 >= s2: " << (s1 >= s2 ? "yes" : "no") << std::endl;
    std::cout << "Enter s1: ";
    std::cin >> s1;
    std::cout << "readed s1: " << s1 << std::endl;
}
