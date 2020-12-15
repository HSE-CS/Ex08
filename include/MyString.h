// Copyright 2020 dash
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

class MyString {
 private:
    char* str;
    size_t len;

 public:
    friend std::ostream& operator<<(std::ostream& os, MyString&);
    friend std::istream& operator>>(std::istream& is, MyString&);
    explicit MyString(const char* first_str = nullptr);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    size_t length() const;
    char* get() const;
    MyString operator+(const MyString&);
    MyString operator-(const MyString& s);
    MyString operator*(const size_t);
    MyString &operator=(const MyString&);
    MyString &operator=(MyString&&);
    bool operator==(const MyString&);
    bool operator!=(const MyString&);
    bool operator>(const MyString&);
    bool operator<(const MyString&);
    bool operator>=(const MyString&);
    bool operator<=(const MyString&);
    MyString operator!();
    char& operator[](const size_t) const;
    int operator()(const char*);
};

#endif  // INCLUDE_MYSTRING_H_
