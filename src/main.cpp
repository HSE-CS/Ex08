  // Copyright 2020 Bulatov D.
#include "MyString.h"

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    std::cout << s3.get() << std::endl;
    std::cout << s3("ll") << std::endl;   // 2
    std::cout << s3("mama") << std::endl;  // -1
    MyString s4("1");
    MyString s5("123");
    std::cout << (s4 != s5) << std::endl;
    MyString s6("1");
    std::cout << (s4 != s6) << std::endl;
    MyString s7("123");
    MyString s8("1234");
    std::cout << (s7 >= s8) << std::endl;  // s8>=s7
    std::cout << (s7 <= s8) << std::endl;  // s8<=s7
    MyString s9;
    s9 = !s1;
    std::cout << s9.get() << std::endl;
    MyString a("123");
    int b = 3;
    MyString c;
    c = a * b;
    std::cout << c.get() << std::endl;
}
