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
    /*
    // test1 +++
    MyString a1;
    std::cout << a1.length() << "    //0";


    // test2 +++
    MyString a2("hello");
    std::cout << a2.length() << "    //5";


    // test3 +++
    MyString a3("123");
    MyString b3(a);
    std::cout << b3.get() << "    //123";


    //test4 +++
    MyString a4("123");
    MyString b4(a4);
    MyString c4;
    c4 = a4 + b4;
    std::cout << c4.get() << "    //123123";

    */

    //test5 ---
    MyString a5("123");
    MyString b5;
    MyString c5;
    c5 = a5 + b5;
    std::cout << c5.get() << std::endl;

    /*
    // test6 +++
    MyString a16(std::string("Hello"));
    std::cout << a16.get() << "    //Hello";


    // test7 +++
    MyString a17("123456789");
    MyString b17("2468");
    MyString c17;
    c17 = a17 - b17;
    std::cout << c.get() << "    //13579";
    */

    // test8 ---
    MyString a8("123");
    int b8 = 3;
    MyString c8;
    c8 = a8 * b8;
    std::cout << c8.get() << std::endl;

    /*
    // test9 +++
     MyString a9("123");
    MyString b9("123");
    a9 == b9 ? std::cout << 1 << "   //1": std::cout << 0;


    // test10 +++
     MyString a10("123");
    MyString b10("1234");
    a10 == b10 ? std::cout << 1 : std::cout << 0 << "    //0";


    // test11 +++
     MyString a11("123");
    MyString b11("1234");
    a11 != b11 ? std::cout << 1 << "    //1" : std::cout << 0;


    // test12 +++
     MyString a12("123");
    MyString b12("1234");
    b12 >= a12 ? std::cout << 1 << "    //1" : std::cout << 0;


    // test13 +++
     MyString a13("45");
    MyString b13("1234");
    b13 <= a13 ? std::cout << 1 << "    //1" : std::cout << 0;


    // test14 +++
     MyString a14("abc");
    MyString b14;
    b14 = !a14;
    std::cout << b14.get() << "   //ABC";


    // test15 +++
     MyString a15("abc123");
    MyString b15;
    b15 = !a15;
    std::cout << b15.get() << "   //ABC123";


    // test16 +++
     MyString c16("45");
    char d16 = '5';
    std::cout << c16[1] << "   //b";


    // test17 +++
     MyString b17("454545");
    std::cout << b17("45") << "    //0" << std::endl;


    //test18 +++
    MyString a16("454545");
    std::cout << a16("33") << "    //-1" << std::endl;

    */
}
