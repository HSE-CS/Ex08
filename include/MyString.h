// Copyright 2020 GHA created by Klykov Anton

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <cstring>
#include <iostream>
#include <fstream>

class MyString{
 private:
    unsigned int _length;
    char* _string;

 public:
    explicit MyString(const char* = nullptr);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&) noexcept ;
    ~MyString();
    unsigned int length();
    char* get();
    MyString operator+(const MyString&);
    MyString operator-(const MyString&);
    MyString operator*(int);
    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&);
    bool operator==(const MyString&);
    bool operator!=(const MyString&);
    bool operator>(const MyString&);
    bool operator<(const MyString&);
    bool operator>=(const MyString&);
    bool operator<=(const MyString&);
    MyString operator!();
    char& operator[](const int);
    int operator()(const char*);
    friend std::ostream& operator<<(std::ostream& out, MyString& c);
    friend std::istream& operator>>(std::istream& is, MyString& c);
};

#endif  // INCLUDE_MYSTRING_H_
