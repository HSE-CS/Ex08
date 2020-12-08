// Copyright 2020 Bekina Svetlana
#include "MyString.h"

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    std::cout << s3 << std::endl;
    std::cout << s3("ll") << std::endl;
    std::cout << s3("mama") << std::endl;
    MyString a("454545");
    std::cout << a("33") << std::endl;
    MyString b(a);
    std::cout << b.get() << std::endl;
}
