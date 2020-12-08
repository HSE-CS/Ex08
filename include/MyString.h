// Copyright 2020 Bekina Svetlana
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

class MyString {
 public:
    explicit MyString(const char* new_string = nullptr);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    size_t length() const;
    char* get() const;
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
    char operator[](int);
    int operator()(const char*);
    friend std::ostream& operator<<(std::ostream&, const MyString&);
    friend std::istream& operator>>(std::istream&, const MyString&);

 private:
    char* string = nullptr;
};
#endif  // INCLUDE_MYSTRING_H_

