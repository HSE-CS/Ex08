// Copyright 2020 Dmitry Vargin
#include <iostream>
#include "MyString.h"
using namespace std;

int main(){
    MyString myString("Hello, world");

    cout << "str.get() = " << myString.get() << endl;
    cout << "str.length() = " << myString.length() << endl;
    cout << endl;
    MyString s1;
    cout << "Enter s1(test cin >>): ";
    cin >> s1;
    cout << endl;
    MyString s2("ASD");
    myString = s1 + s2;
    cout << s1 << " + " << s2 << " = " << myString << endl;
    cout << s1 << " == " << s2 << " = " << (s1 == s2) << endl;
    cout << "s1[1]" << " = " << s1[1] << endl;
    cout << "myString(s2)" << " = " << myString("ASD") << endl;
    cout << myString << " - " << myString.length() << endl;
    s1 = !myString;
    cout << "!myString = " << myString << endl;

    return 0;
}