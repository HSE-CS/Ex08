//  Copyright 2020 Nikita Naumov

#include "../include/MyString.h"

int main() {
    MyString test1;  //  Create an empty string
    MyString test2("aaaa");  //  Create an 'aaaa' string
    MyString test3("bbba");  //  One more string

    std::cout << "what will happen if I make test1 + test2?" << std::endl;
    std::cout << "Answer: " << test1+test2 << std::endl;

    MyString test4(test2);  //  I want to make test4 by copy
    std::cout << "=========================================================\n";
    MyString test5 = test3 * 3;  //  triple bbba
    std::cout << test5.get() << std::endl;
    std::cout << "=========================================================\n";
    std::cout << "Let's seek for 'bb' substring in previous string\n";
    std::cout << "First position of 'bb' is "<< test5("bb") << std::endl;
    
    std::cout << "=========================================================\n";
    MyString test6("Hello! Nice to see you! 123");
    std::cout << "Let's delete all 'e' letters from " << test6.get() << '\n';
    MyString test7("e");
    std::cout << test6 - test7 << std::endl;
    std::cout << "=========================================================\n";
    std::cout << "Now I wanna show you how i can change register is phrase\n";
    std::cout << !test6 << std::endl;

    std::cout << "=========================================================\n";
    std::cout << "Now some comparings\ntrue - 1, false - 0\n";
    std::cout << "aaaa > bbba ? " << (test2 > test3) << std::endl;
    std::cout << "bbba * 3>Hello! Nice to see you! 123 ? " << (test5 > test6);
    std::cout << std::endl;
    std::cout << "aaaa >= aaaa ? " << (test2 >= test2) << std::endl;
    std::cout << "aaaa != bbba ? " << (test2 != test3) << std::endl;
    std::cout << "aaaa != aaaa ? " << (test2 != test2) << std::endl;
    std::cout << "aaaa == aaaa ? " << (test2 == test2) << std::endl;
    return 0;
}
