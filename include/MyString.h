// Copyright 2020 VadMack

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>

class MyString {
 private:
  char *str;

 public:
  explicit MyString(const char *str = nullptr);
  explicit MyString(std::string str);
  MyString(MyString&&);
  MyString(const MyString&);
  char *get();
  int length();
  MyString operator+(MyString);
  MyString operator-(MyString);
  MyString operator*(int n);
  int operator==(const MyString&);
  int operator!=(const MyString&);
  int operator>=(const MyString&);
  int operator<=(const MyString&);
  int operator>(const MyString&);
  int operator<(const MyString&);
  MyString& operator=(const MyString&);
  MyString& operator=(MyString&&);
  MyString& operator!();
  char operator[](int n);
  int operator()(const char*);
};

#endif  // INCLUDE_MYSTRING_H_
