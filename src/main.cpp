// Copyright 2020 Vladimir Uspensky

#include "MyString.h"

using namespace std;

int main(){

    MyString a("123456789");
    MyString b("2468");
    MyString c;
    c = a - b;
    cout << c << endl;

    return 0;
}