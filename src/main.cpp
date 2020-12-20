//  Copyright 2020 TimurZaytsev

#include "MyString.h"

int main() {
    MyString a;
    MyString b("Press");
    MyString c("F");
    std::cout << b << std::endl;        

    MyString d("to pay respect");
    MyString temp(" ");
    a = b + temp + c + temp + d;
    std::cout << a << std::endl;        

    a = b + temp + c * 15 + temp + d;
    std::cout << a.get() << std::endl;  

    a = !a;                             
    std::cout << a << std::endl;
    std::cout << a.length() << std::endl;
    std::cout << a[0] << std::endl;
    std::cout << (b == c) << std::endl;
}