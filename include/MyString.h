// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>
#include <string.h>
#include <iostream>
#include <sstream>

class MyString {
 public:
  MyString();
    explicit MyString(const char*);
    explicit MyString(std::string);
    MyString(const MyString&);
    ~MyString();
    MyString(MyString&&);

    char* get() const;
    size_t length() const;

    MyString operator+(const MyString&);
    MyString operator-(const MyString&);
    MyString operator*(size_t);
    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&);

    bool operator==(const MyString&) const;
    bool operator!=(const MyString&) const;
    bool operator>(const MyString&) const;
    bool operator<(const MyString&) const;
    bool operator>=(const MyString&) const;
    bool operator<=(const MyString&) const;

    MyString operator!();
    char& operator[](size_t) const;
    int operator()(const char*);

    friend std::ostream& operator<<(std::ostream&, MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);

 private:
	char *str;
};
#endif  // INCLUDE_MYSTRING_H_



