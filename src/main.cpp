#include "MyString.h"
#include <iostream>
using namespace std;
int main()
{
    MyString s1("Hello,");
    cout<<s1.get()<<endl;
    MyString s2("world!");
    MyString s3;

    cout<<(s1+s2).get()<<endl;
    s3 = s1;
    s3 = s3 + s2;
    std::cout << s3;
    std::cout << s3("ll");   // 2
    std::cout << s3("mama"); // -1
}

