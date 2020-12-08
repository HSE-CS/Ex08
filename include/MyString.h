// Copyright 2020 Ryzhova
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>
#include <iostream>

class MyString {
 private:
     char* string;
     
 public:
    explicit MyString(const char* = nullptr);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    size_t length() const;
    char* get() const;
    MyString operator+(const MyString&);
    MyString operator-(const MyString&);
    MyString operator*(int);
    MyString operator=(const MyString&);
    MyString operator=(MyString&&);
    bool operator==(const MyString&);
    bool operator!=(const MyString&);
    bool operator>(const MyString&);
    bool operator<(const MyString&);
    bool operator>=(const MyString&);
    bool operator<=(const MyString&);
    MyString operator!();
    char operator[](size_t) const;
    int operator()(const char*);
    friend std::ostream& operator<<(std::ostream&, MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
};

#endif  // INCLUDE_MYSTRING_H_
