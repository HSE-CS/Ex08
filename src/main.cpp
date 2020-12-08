// Copyright 2020 Igumnova Natasha
#include "MyString.h"

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    size_t len = s3.length();
    std::cout <<len;
    s3 = s1 + s2;
    std::cout << s3;
    std::cout << s3("ll");  // 2
    std::cout << s3("mama");  // -1
    MyString a;
    MyString a1("hello");
    MyString a2("123");
    MyString b(a2);
    MyString a3("123");
    MyString b(a3);
    MyString c;
    c = a + b;
    MyString a4("123");
    MyString b3;
    MyString c1;
    c1 = a4 + b3;
    MyString a5(std::string("Hello"));
    MyString a6("123456789");
    MyString b4("2468");
    MyString c2;
    c2 = a6 - b4;
    MyString a7("123");
    int b5 = 3;
    MyString c3;
    MyString a8("454545");
    std::cout<< a8("33");
}
