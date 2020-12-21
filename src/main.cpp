// Copyright 2020 Dyryaev Daniil

#include "../include/MyString.h"

signed main() noexcept {
    auto s = new MyString("I just wanna hit record!");
    auto t = new MyString("Full of never ending stories "
                          "in this never ending universe!");
    auto u = new MyString("I'm blue da ba dee");

    MyString a{"Hello"};
    MyString b(a);
    MyString c;
    c = a + b;
    std::cout << c << '\n';
    MyString res = *s + *t;
    MyString doubled = res * 2;
    MyString reversed = !res;
//    std::cout << s << '\n';
//    std::cout << *s << '\n';
//    std::cout << res << '\n';
//    std::cout << (*u)("d") << '\n';
//    std::cout << doubled << '\n';
//    std::cout << reversed << '\n';
    return 0;
}
