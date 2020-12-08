//  Copyright 2020 Drobot Elizaveta
#include "MyString.h"

int main() {
    MyString example_1;
    MyString example_2("aaaa");
    MyString example_3("bbba");

    std::cout << "example_1 + example_2 Answer: ";
    std::cout << example_1 + example_2 << "\n";

    MyString example_4(example_2);
    MyString example_5 = example_3 * 3;
    std::cout << example_5.get() << "\n";
    std::cout << "First position 'bb' -  " << example_5("bb") << "\n";

    MyString example_6("Hello, how are you feeling?");
    std::cout << "delete 'e' letters from " << example_6.get() << "\n";
    MyString example_7("e");
    std::cout << example_6 - example_7 << "\n";
    std::cout << !example_6 << "\n";
    std::cout << (example_2 > example_3) << "\n";
    std::cout << (example_5 > example_6) << "\n";
    std::cout << (example_2 >= example_2) << "\n";
    std::cout << (example_2 != example_3) << "\n";
    std::cout << (example_2 != example_2) << "\n";
    std::cout << (example_2 == example_2) << "\n";
    MyString a("123");
    int b = 3;
    MyString c;
    c = a * b;
    std::cout << c.get() << "\n";
    return 0;
}
