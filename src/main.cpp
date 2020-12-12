// Copyright 2020 Bogomazov Mikhail
#include <iostream>
#include "../include/MyString.h"

int main() {
    MyString s;
    std::cout << s.get() << std::endl;
    MyString a("123");
    MyString b;
    MyString c;
    c = a + b;
    return 0;
}
