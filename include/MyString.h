// Copyright 2020 FOM

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <cstring>

class MyString {
 private:
    char* string;
    unsigned int lenght;
 public:
    MyString();
    explicit MyString(const char*);
    explicit MyString(std::string str);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    unsigned int length();
    char* get();
    MyString operator+(const MyString&);
    MyString operator-(const MyString&);
    MyString operator*(const int);
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
