// Copyright 2020 Alexey Tatsenko
#include<iostream>
#include "MyString.h"

int main() {
    MyString a("111111111");
    MyString b("33333");
    MyString c;
    bool k;
    k = (a >= b);
    std::cout << (a >= b);
}
