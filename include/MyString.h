// Copyright 2020 test
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>


class MyString {
 private:
     char* str;
     size_t len;
 public:
     MyString(const char* ptr = nullptr);
     MyString(std::string s);
     MyString(const MyString& s);
     MyString(MyString&& s);
     ~MyString();
     size_t length();
     char* get();
     MyString operator+(const MyString& s);
     MyString operator-(const MyString& s);
     MyString operator*(size_t num);
     MyString& operator=(const MyString& s);
     MyString& operator=(MyString&& s);
     bool operator== (const MyString& s);
     bool operator!= (const MyString& s);
     bool operator> (const MyString& s);
     bool operator< (const MyString& s);
     bool operator>= (const MyString& s);
     bool operator<= (const MyString& s);
     MyString operator!();
     char& operator[](int ind);
     int operator()(const char* s);
     friend std::ostream& operator<<(std::ostream &os, MyString& s);
     friend std::istream& operator>>(std::istream &is, MyString& s);
};

#endif // INCLUDE_MYSTRING_H_
