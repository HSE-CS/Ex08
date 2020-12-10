// Copyright [2020] <Olesya Nikolaeva>

#include "MyString.h"

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    std::cout << s3("ll");
    std::cout << s3("mama");
}
