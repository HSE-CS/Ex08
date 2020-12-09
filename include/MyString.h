// Copyright 2020 Shirokov Alexander

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

class MyString {

 private:
  char* data;
  int len;
 public:
  MyString();
  explicit MyString(const char*);
  explicit MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();
  int length();
  char* get();

  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(const int a);
  MyString& operator=(const MyString&);
  MyString& operator=(MyString&&);

  bool operator==(const MyString&);
  bool operator!=(const MyString&);
  bool operator>(const MyString&);
  bool operator<(const MyString&);
  bool operator>=(const MyString&);
  bool operator<=(const MyString&);

  MyString operator!();
  char& operator[](int) const;
  int operator()(const char*);

  friend std::ostream& operator<<(std::ostream&, MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
};

#endif  // INCLUDE_MYSTRING_H_
