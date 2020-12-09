// Copyright 2020 milalupehina
#include "MyString.h"
#include <string>
#include <cstring>

/*int main()
{
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    std::cout << s3;
    //std::cout << s3("ll");   // 2
    //std::cout << s3("mama"); // -1
}*/



int main() {
    // test1 +++
    /* MyString a;
    std::cout << a.length() << "    //0";
    */

    // test2 +++
    /* MyString a("hello");
    EXPECT_EQ(5, a.length());
    std::cout << a.length() << "    //5";
    */

    // test3 +++
    /* MyString a("123");
    MyString b(a);
    std::cout << b.get() << "    //123";
    */

    //test4 +++
    /* MyString a("123");
    MyString b(a);
    MyString c;
    c = a + b;
    std::cout << c.get() << "    //123123";
    */

    //test5 ---
    MyString a5("123");
    MyString b5;
    MyString c5;
    c5 = a5 + b5;
    std::cout << c5.get() << std::endl;

    // test6 +++
    /* MyString a(std::string("Hello"));
    std::cout << a.get() << "    //Hello";
    */

    // test7 +++
    /* MyString a("123456789");
    MyString b("2468");
    MyString c;
    c = a - b;
    std::cout << c.get() << "    //13579";
    */

    // test8 ---
    MyString a8("123");
    int b8 = 3;
    MyString c8;
    c8 = a8 * b8;
    std::cout << c8.get() << std::endl;

    // test9 +++
    /* MyString a("123");
    MyString b("123");
    a == b ? std::cout << 1 << "   //1": std::cout << 0;
    */

    // test10 +++
    /* MyString a("123");
    MyString b("1234");
    a == b ? std::cout << 1 : std::cout << 0 << "    //0";
    */

    // test11 +++
    /* MyString a("123");
    MyString b("1234");
    a != b ? std::cout << 1 << "    //1" : std::cout << 0;
    */

    // test12 +++
    /* MyString a("123");
    MyString b("1234");
    b >= a ? std::cout << 1 << "    //1" : std::cout << 0;
    */

    // test13 +++
    /* MyString a("45");
    MyString b("1234");
    b <= a ? std::cout << 1 << "    //1" : std::cout << 0;
    */

    // test14 +++
    /* MyString a("abc");
    MyString b;
    b = !a;
    std::cout << b.get() << "   //ABC";
    */

    // test15 +++
    /* MyString a("abc123");
    MyString b;
    b = !a;
    std::cout << b.get() << "   //ABC123";
    */

    // test16 +++
    /* MyString c("45");
    char d = '5';
    std::cout << c[1] << "   //b";
    */

    // test17 +++
    /* MyString b("454545");
    std::cout << b("45") << "    //0" << std::endl;
    */

    //test18 ---
    MyString a16("454545");
    std::cout << a16("33") << "    //-1" << std::endl;
}
