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
    MyString a8("454545");
    std::cout<< a8("33");
}
