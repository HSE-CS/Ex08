// Copyright [2020] <Olesya Nikolaeva>

#include "MyString.h"

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    std::cout << s3("ll") << std::endl;
    std::cout << s3("mama") << std::endl;
    MyString s4;
    MyString s5("hello");
    std::cout << s4.length() << std::endl;
    std::cout << s5.length() << std::endl;
    MyString s6(s5);
    std::cout << s6.get() << std::endl;
    s6 = s5 + s2;
    std::cout << s6.get() << std::endl;
    MyString s7(std::string("Hello"));
    std::cout << s7.get() << std::endl;
    MyString a("123456789");
    MyString b("2468");
    MyString c;
    c = a - b;
    std::cout << c.get() << std::endl;
    MyString d;
    d = c * 3;
    std::cout << d.get() << std::endl;
    MyString e("123");
    int f = 3;
    MyString h;
    h = e * f;
    std::cout << h.get() << std::endl;
    MyString a1("123");
    MyString b1(a1);
    MyString c1;
    c1 = a1 + b1;
    std::cout << c1.get() << std::endl;
}
