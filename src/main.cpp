// Copyright 2020 FOM
#include "MyString.h"

int main() {
    MyString str_1("NEVER.");
    MyString str_2("GIVE.");
    MyString str_3("UP.");
    str_3 = str_1 + str_2 + str_3;
    std::cout << str_3 << std::endl;
    MyString str_4("study ");
    MyString str_5("and study again");
    str_5 = str_4 * 2 + str_5;
    std::cout << str_5.get() << std::endl;
    MyString str_6("all ");
    MyString str_7("or nothing ");
    str_7 = (str_6 + str_7) * 5;
    std::cout << str_7.length() << std::endl;
    std::cout << str_7[0] << std::endl;
    MyString str_8("try");
    MyString str_9("try");
    MyString str_10("tr");
    std::cout << (str_8 == str_9) << std::endl;
    std::cout << (str_8 == str_10) << std::endl;
    MyString str_11;
    str_11 = std::move(str_1);
    std::cout << str_11 << std::endl;
    MyString str_12("Isaac Newton");
    MyString str_13("Newton");
    str_12 = str_12 - str_13;
    std::cout << str_12.get() << std::endl;
    std::cout << (str_12 != str_13) << std::endl;
    MyString str_14("Albert Einstein");
    MyString str_15("Albert");
    std::cout << (str_14 < str_15) << std::endl;
    std::cout << (str_15 < str_14) << std::endl;
    MyString str_16("Galileo Galilei");
    MyString str_17("Galileo");
    std::cout << (str_16 > str_17) << std::endl;
    std::cout << (str_17 > str_16) << std::endl;
    MyString str_18("Sklodowska-Curie");
    MyString str_19("Maria Sklodowska-Curie");
    std::cout << (str_18 >= str_19) << std::endl;
    std::cout << (str_19 >= str_18) << std::endl;
    MyString str_20("Tesla");
    MyString str_21("Nikola Tesla");
    std::cout << (str_20 <= str_21) << std::endl;
    std::cout << (str_21 <= str_20) << std::endl;
    return 0;
}
