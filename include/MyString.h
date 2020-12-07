// Copyright 2020 VadMack

#ifndef EX08_INCLUDE_MYSTRING_H_
#define EX08_INCLUDE_MYSTRING_H_

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
  MyString& operator=(const MyString&);
};

#endif //EX08_INCLUDE_MYSTRING_H_
