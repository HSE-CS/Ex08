// Copyright 2020 Ilya Tatsenko
#pragma once
#include<iostream>
#include<string>

class MyString {
 private:
    char* str;

 public:
    MyString();
    explicit MyString(const char*s);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    int length();
    char* get();
    MyString operator+(const MyString &x);
    MyString operator-(const MyString& x);
    MyString operator*(int x);
    MyString operator=(const MyString& x);
    MyString operator=(MyString&& x);
    bool operator==(const MyString& x);
    bool operator!=(const MyString& x);
    bool operator>(const MyString& x);
    bool operator<(const MyString& x);
    bool operator>=(const MyString& x);
    bool operator<=(const MyString& x);
    MyString operator!();

    char operator[](int x);
    int operator()(const char* x);

    friend std::ostream& operator<<(std::ostream&, const MyString &x);
    friend std::istream& operator>>(std::istream&, MyString& x);
};
