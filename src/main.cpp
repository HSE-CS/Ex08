// Copyright 08.12.20 DenisKabanov

#include "MyString.h"

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    std::cout << s3 << std::endl;
    MyString s4 = s3 * 3;
    std::cout << s4 << std::endl;
    MyString s5("l");
    MyString s6 = s3 - s5;
    std::cout << s6 << std::endl;
    std::cout << s1.get() << "  " << s1.length() << std::endl;
    MyString s7("Hello");
    std::cout << " s7 == s1? " << (s7 == s1) << std::endl;
    MyString s8(",");
    s7 = s7 + s8;
    std::cout << " s7 == s1? " << (s7 == s1) << std::endl;
    MyString s9("Git"), s10("Hub");
    std::cout << " s9 > s10? " << (s9 > s10) << std::endl;
    std::cout << " s9 < s10? " << (s9 < s10) << std::endl;
    std::cout << "Second letter of s10: " << s10[1] << std::endl;
    MyString s11 = s9 + s10;
    std::cout << "substring from: " << s11("tHub") << std::endl;
    MyString s12 = !(s11);
    std::cout << "Reverse " << s12 << std::endl;
    return 0;
}
