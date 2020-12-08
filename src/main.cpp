  // Copyright Nikolaev Ivan

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyString.h"


int main() {
    MyString s1;
    MyString s2("S2");
    MyString s22(s2);
    MyString s3("S3");

    std::cout << "s1.length(): " << s1.length() << std::endl;
    std::cout << "s1.get(): " << s1.get() << std::endl;
    std::cout << "s2.length(): " << s2.length() << std::endl;
    std::cout << "s2.get(): " << s2.get() << std::endl;
    std::cout << "s22.length(): " << s22.length() << std::endl;
    std::cout << "s22.get(): " << s22.get() << std::endl;

    MyString s4;
    s4 = s2 + s3;
    std::cout << "s4.get(): " << s4.get() << std::endl;

    s4 = s2 - s3;
    std::cout << "s4.get(): " << s4.get() << std::endl;
    std::cout << "(s4 * 5).get(): " << (s4 * 5).get() << std::endl;

    std::cout << "s2 == s3: " << (s2 == s3) << std::endl;
    std::cout << "s2 != s3: " << (s2 != s3) << std::endl;
    std::cout << "s2 > s3: " << (s2 > s3) << std::endl;
    std::cout << "s2 >= s3: " << (s2 >= s3) << std::endl;
    std::cout << "s2 < s3: " << (s2 < s3) << std::endl;
    std::cout << "s2 <= s3: " << (s2 <= s3) << std::endl;

    MyString s5("lowercase - UPPERCASE");
    std::cout << "s5.get(): " << s5.get() << std::endl;
    std::cout << "(!s5).get(): " << (!s5).get() << std::endl;
    std::cout << "s5[12]: " << s5[12] << std::endl;
    std::cout << "s5(\"UPPER\"): " << s5("UPPER") << std::endl;
    return 0;
}
