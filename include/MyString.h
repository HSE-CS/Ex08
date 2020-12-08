// Copyright 2020 Nikita Stifeev
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>

class MyString {
    size_t size;
    size_t capacity;
    char* chars;
 public:
    MyString(const char* str = nullptr);
    MyString(const std::string& str);
    MyString(const MyString& str);
    MyString(MyString&& str);
    MyString& operator=(const MyString& str);
    MyString& operator=(MyString&& str);
    MyString& operator+=(char c);
    size_t length() const;
    char* get() const;
    MyString operator+(const MyString& str) const;
    MyString operator-(const MyString& str) const;
    MyString operator*(int count) const;
    bool operator==(const MyString& str) const;
    bool operator!=(const MyString& str) const;
    bool operator>(const MyString& str) const;
    bool operator<(const MyString& str) const;
    bool operator<=(const MyString& str) const;
    bool operator>=(const MyString& str) const;
    MyString operator!() const;
    char operator[](int index) const;
    char& operator[](int index);
    int operator()(const MyString& str) const;
    ~MyString();
    friend std::istream& operator>>(std::istream& is, MyString& str);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};

#endif  // INCLUDE_MYSTRING_H_