// Copyright 2020 GN
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
class MyString {
 private:
    char* mystring;
    int len;

 public:
    explicit MyString(const char* = nullptr);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(const MyString&&);
    ~MyString();
    int length();
    char* get();
    MyString operator+(const MyString& str);
    MyString operator-(const MyString& str);
    MyString operator*(const int n);
    MyString& operator=(const MyString& str);
    MyString& operator=(MyString&& str);
    bool operator==(const MyString& str);
    bool operator!=(const MyString& str);
    bool operator>(const MyString& str);
    bool operator<(const MyString& str);
    bool operator>=(const MyString& str);
    bool operator<=(const MyString& str);
    MyString operator!();
    char operator[](int n);
    int operator()(const char*);
    friend std::ostream& operator>>(std::ostream& os, MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
};
#endif  // INCLUDE_MYSTRING_H_
