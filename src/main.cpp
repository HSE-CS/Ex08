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
    MyString a("hello");
    MyString a("123");
    MyString b(a);
    MyString a("123");
    MyString b(a);
    MyString c;
    c = a + b;
    MyString a("123");
    MyString b;
    MyString c;
    c = a + b;
    MyString a(std::string("Hello"));
    MyString a("123456789");
    MyString b("2468");
    MyString c;
    c = a - b;
    MyString a("123");
    int b = 3;
    MyString c;
    MyString a("454545");
    std::cout<< a("33");
}
