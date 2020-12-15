// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class MyString {
 private:
    char* mystr = nullptr;
    int size = 0;
 public:
    explicit MyString(const char* str = nullptr);
    explicit MyString(std::string str);
    MyString(const MyString& copy);
    MyString(MyString&& move);
    ~MyString();
    size_t length();
    char* get();
    MyString operator+(const MyString& arg);
    MyString operator-(const MyString& arg);
    MyString operator*(unsigned int n);
    MyString operator=(const MyString& arg);
    MyString operator=(MyString&& arg);
    bool operator==(const MyString& arg);
    bool operator!=(const MyString& arg);
    bool operator>(const MyString& arg);
    bool operator<(const MyString& arg);
    bool operator>=(const MyString& arg);
    bool operator<=(const MyString& arg);
    MyString operator!();
    char operator[](unsigned int index);
    int operator()(const char* arg);
    friend std::ostream& operator<<(std::ostream& output, MyString& arg);
    friend std::istream& operator>>(std::istream& input, MyString& arg);
};

#endif  // INCLUDE_MYSTRING_H_
