// Copyright 2020 Bugrov
#include "MyString.h"
int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = !s1 + !s2;
    std::cout << s1+ s2<<'\n';
    std::cout << s3 << '\n';
    s3 = s3 * 5;
    std::cout << s3 << '\n';
    std::cout << s1("llo,")<<'\n';   // 2
    std::cout << s3("mama")<<'\n'; // -1

    return 0;
}