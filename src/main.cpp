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
    MyString str_12("The level of education is in direct correlation with your salary ");
    MyString str_13("is in direct correlation with your salary ");
    str_12 = str_12 - str_13;
    std::cout << str_12.get() << std::endl;
    std::cout << (str_12 != str_13) << std::endl;
    MyString str_14("When today is over, it will never come back");
    MyString str_15("Even now, your enemies are eagerly flipping through books");
    std::cout << (str_14 < str_15) << std::endl;
    std::cout << (str_15 < str_14) << std::endl;
    MyString str_16("If you fall asleep now, you will dream. If you study now, you will live your dream");
    MyString str_17("When you think it’s too late, the truth is, it’s still early");
    std::cout << (str_16 > str_17) << std::endl;
    std::cout << (str_17 > str_16) << std::endl;
    MyString str_18("Studying is not about time. It’s about effort");
    MyString str_19("Life is not all about studying. But if you can’t even conquer this little part of life, then what else can you possibly do? ");
    std::cout << (str_18 >= str_19) << std::endl;
    std::cout << (str_19 >= str_18) << std::endl;
    MyString str_20("Not everyone can truly succeed in everything. But success only comes with self-management and determination ");
    MyString str_21("If you don’t walk today, you’ll have to run tomorrow");
    std::cout << (str_20 <= str_21) << std::endl;
    std::cout << (str_21 <= str_20) << std::endl;
	return 0;
}