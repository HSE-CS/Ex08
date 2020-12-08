// Copyright 2020 Bulatov D.
#include "MyString.h"

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    s3 = s1 + s2;
    cout << s3.get() << endl;
    cout << s3("ll") << endl;   // 2
    cout << s3("mama") << endl;  // -1
    MyString s4("1");
    MyString s5("123");
    cout << (s4 != s5) << endl;
    MyString s6("1");
    cout << (s4 != s6) << endl;
    MyString s7("123");
    MyString s8("1234");
    cout << (s7 >= s8) << endl;  // s8>=s7
    cout << (s7 <= s8) << endl;  // s8<=s7
    MyString s9;
    s9 = !s1;
    cout << s9.get() << endl;
}
