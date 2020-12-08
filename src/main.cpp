// Created by mila on 08.12.2020.
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



int main(){
    //test1
    //MyString a;
    //std::cout << a.length() << "    //0";

    //test2
    //MyString a("hello");
    //EXPECT_EQ(5, a.length());
    //std::cout << a.length() << "    //5";

    //test3
    //MyString a("123");
    //MyString b(a);
    //std::cout << b.get() << "    //123";

    //test4
    //MyString a("123");
    //MyString b(a);
    //MyString c;
    //c = a + b;
    //std::cout << c.get() << "    //123123";

    //test5
    //MyString a("123");
    //MyString b;
    //MyString c;
    //c = a + b;
    //std::cout << c.get() << "    //123";

    //test6
    //MyString a(std::string("Hello"));
    //std::cout << a.get() << "    //Hello";

    //test7
    //MyString a("123456789");
    //MyString b("2468");
    //MyString c;
    //c = a - b;
    //std::cout << c.get() << "    //13579";

    //test8
    //MyString a("123");
    //int b = 3;
    //MyString c;
    //c = a * b;
    //std::cout << c.get() << "   //123123123";

    //test9
    //MyString a("123");
    //MyString b("123");
    //a == b ? std::cout << 1 << "   //1": std::cout << 0;

    //test10
    //MyString a("123");
    //MyString b("1234");
    //a == b ? std::cout << 1 : std::cout << 0 << "    //0";

    //test11
    //MyString a("123");
    //MyString b("1234");
    //a != b ? std::cout << 1 << "    //1" : std::cout << 0;

    //test12
    //MyString a("123");
    //MyString b("1234");
    //b >= a ? std::cout << 1 << "    //1" : std::cout << 0;

    //test13
    //MyString a("45");
    //MyString b("1234");
    //b <= a ? std::cout << 1 << "    //1" : std::cout << 0;

    //test14
    //MyString a("abc");
    //MyString b;
    //b = !a;
    //std::cout << b.get() << "   //ABC";

    //test15
    //MyString a("abc123");
    //MyString b;
    //b = !a;
    //std::cout << b.get() << "   //ABC123";

    //test16   ?
    MyString c("45");
    char d = '5';
    std::cout << c[1] << "   //b";

    //test17
    MyString b("454545");
    std::cout << b("45") << "    //0" << std::endl;

    //test18
    MyString a("454545");
    std::cout << a("33") << "    //-1" ;
}
