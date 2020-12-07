// Copyright 2020 Kuznetsov Mikhail
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>

class MyString{
 private:
    char* buf;
    size_t len = 0;

 public:
    explicit MyString(const char* s = nullptr);
    explicit MyString(std::string);
    MyString(const MyString &);
    MyString(MyString &&);
    ~MyString();
    size_t length() const;
    char* get() const;
    MyString operator+(const MyString &s);
    MyString operator-(const MyString &s);
    MyString operator*(const size_t cnt);
    MyString& operator=(const MyString &s);
    MyString& operator=(MyString &&s);
    bool operator==(const MyString &s);
    bool operator!=(const MyString &s);
    bool operator>(const MyString &s);
    bool operator<(const MyString &s);
    bool operator>=(const MyString &s);
    bool operator<=(const MyString &s);
    MyString operator!();
    char & operator[](const size_t ind) const;
    int operator()(const MyString &s);
    friend std::ostream& operator<<(std::ostream &os, MyString &s);
    friend std::istream& operator>>(std::istream &is, MyString &s);
};
#endif  // INCLUDE_MYSTRING_H_

