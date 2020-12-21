// Copyright 2020 Alexey Tatsenko
#pragma once
#include<iostream>
#include<string>

class MyString {
 private:
    char* stroka;

 public:
    MyString();
    explicit MyString(const char*);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    int length();
    char* get();
    MyString operator+(const MyString &);
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
    char operator[](int);
    int operator()(const char*);
    friend std::ostream& operator<<(std::ostream&, const MyString &);
    friend std::istream& operator>>(std::istream&, MyString&);
};
