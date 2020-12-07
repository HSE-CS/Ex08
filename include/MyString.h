// Copyright 2020 Ex08 TiNa
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <string>
#include <iostream>

class MyString {
 private:
  char* symb;
  int len;
  public:
  explicit MyString(const char* = nullptr);
  explicit MyString(std::string);
  explicit MyString(const MyString&);
  explicit MyString(MyString&&);
  ~MyString();
  int length() const;
  char* get() const;
  MyString operator+(const MyString& str);
  MyString operator-(const MyString& str);
  MyString operator*(const int num);
  MyString& operator=(const MyString& str);
  MyString& operator=(MyString&& str);
  bool operator==(const MyString& str);
  bool operator!=(const MyString& str);
  bool operator>(const MyString& str);
  bool operator<(const MyString& str);
  bool operator>=(const MyString& str);
  bool operator<=(const MyString& str);
  MyString operator!();
  char& operator[](int num);
  int operator()(const char* str);
  friend std::ostream& operator<<(std::ostream& os, MyString& str);
  friend std::istream& operator>>(std::istream& is, MyString& str);
};

#endif  // INCLUDE_MYSTRING_H_
