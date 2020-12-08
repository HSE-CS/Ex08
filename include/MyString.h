// Copyright 2020 Bulatov D.
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
 char* str;
 size_t len;
public:
 explicit MyString(const char* ptr= nullptr);
 explicit MyString(string);
 MyString(const MyString&);
 MyString(MyString&&);
 ~MyString();
 size_t length();
 char* get();
 MyString operator+(const MyString&);
 MyString operator-(const MyString&);
 MyString operator*(size_t);
 MyString& operator=(const MyString&);
 MyString& operator=(MyString&&);
 bool operator==(const MyString&);
 bool operator!=(const MyString&);
 bool operator>(const MyString&);
 bool operator<(const MyString&);
 bool operator>=(const MyString&);
 bool operator<=(const MyString&);
 MyString operator!();
 char operator[](size_t);
 int operator()(const char*);
 friend ostream& operator>>(ostream& os, MyString& str);
 friend istream& operator>>(istream& is, MyString& str);
};

#endif  // INCLUDE_MYSTRING_H_
