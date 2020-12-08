// Copyright 2020 Igumnova Natasha
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <string.h>
#include <iostream>
#include <string>


class MyString {
 private:
  char* string;

 public:
  explicit MyString(const char* str = nullptr);
  explicit MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();
  size_t length() const;
  char* get() const;
  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(int n);
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
  friend std::ostream& operator<<(std::ostream&, MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
};

#endif  // INCLUDE_MYSTRING_H_

