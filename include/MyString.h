// Copyright 2020 <Jiiijyyy>
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>

class MyString {
 private:
    char* string;
    unsigned int len;
 public:
    MyString();
    MyString(const char*);
    MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    unsigned int length();
    char* get();
    MyString operator+(const MyString&);
    MyString operator-(const MyString&);
    MyString operator*(const int a);
    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&);
    bool operator==(const MyString&);
    bool operator!= (const MyString&);
    bool operator> (const MyString&);
    bool operator< (const MyString&);
    bool operator>= (const MyString&);
    bool operator<= (const MyString&);
    MyString operator!();
    char& operator[](int);
    int operator()(const char*);
    friend std::ostream& operator<<(std::ostream&, MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
};
#endif  // INCLUDE_MYSTRING_H_

