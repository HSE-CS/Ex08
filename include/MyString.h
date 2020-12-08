// Copyright 2020 Dumarevskaya
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSRTING_H_

#include <iostream>
#include <string>

class MyString {
 private:
  char* str = nullptr;
  size_t len = 0;
 public:
  MyString(const char* = nullptr);
  MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();
  size_t length();
  char* get();
  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(const size_t n);
  MyString& operator=(const MyString&);
  MyString& operator=( MyString&&);
  bool operator==(const MyString&);
  bool operator!=(const MyString&);
  bool operator>(const MyString&);
  bool operator<(const MyString&);
  bool operator>=(const MyString&);
  bool operator<=(const MyString&);
  MyString operator!();
  char operator[](const size_t);
  int operator()(const char*);
  friend std::ostream& operator<<(std::ostream&, MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
};

#endif // !INCLUDE_MYSTRING_H_
