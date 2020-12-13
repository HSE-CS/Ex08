// Copyright 2020 sccc
#include <string>
#include <iostream>
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

class MyString {
 private:
        char * string;
        int size;

 public:
        ~MyString();
        MyString();
        MyString(const char* str = nullptr);
        explicit MyString(std::string str);
        MyString(const MyString& str);
        MyString(MyString&& str);
        int length();
        char* get();
        MyString operator+(const MyString& str);
        MyString operator-(const MyString& str);
        MyString operator*(const int n);
        bool operator==(const MyString& str);
        bool operator!=(const MyString& str);
        bool operator>(const MyString& str);
        bool operator>=(const MyString& str);
        bool operator<(const MyString& str);
        bool operator<=(const MyString& str);
        MyString operator!();
        char operator[](const int& index);
        int operator()(const MyString& str);
        friend std::ostream& operator<<(std::ostream& os, MyString& str);
        friend std::istream& operator>>(std::istream& is, MyString& str);
        MyString& operator=(const MyString& str);
        MyString& operator=(MyString&& str);
};

#endif  // INCLUDE_MYSTRING_H_

