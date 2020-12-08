// Copyright 2020 OsmanovIslam
#include "MyString.h"
#include <iostream>
int main() {
    MyString s1("Hello,");
    std::cout << s1.get() << std::endl;
    MyString s2("world!");
    MyString s3;

    std::cout << (s1+s2).get() std::<< endl;
    s3 = s1;
    s3 = s3 + s2;
    std::cout << s3;
    std::cout << s3("ll");
    std::cout << s3("mama");
    MyString s4("123");
    int b = 3;
    s3 = s4 * 3;
}
