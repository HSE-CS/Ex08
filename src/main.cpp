// Copyright 2020 <Jiiijyyy>
#include "MyString.h"

int main() {
    MyString a;
    MyString b("aaa");
    a = b;
    std::cout << a << "\n";
    a = b * 3;
    std::cout << b.get() << "\n";
    b = a + a * 3;
    std::cout << b.get() << "\n";
    std::cout << b.length() << "\n";
    MyString c("My mood - ");
    c = c + b;
    std::cout << c << "\n";
    std::cout << c[0] << "\n";
    std::cout << (a == b) << "\n";
    MyString d("aAaAaAaAaA");
    std::cout << (d == c) << "\n";
    MyString e;
    e = std::move(d);
    std::cout << e << "\n";
    c = c - b;
    b = !b;
    c = c + b;
    std::cout << c << "\n";
    return 0;
}
