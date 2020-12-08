// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

class MyString {
 private:
  char* arString;

 public:
  explicit MyString(const char* str = nullptr);
  explicit MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();

  int length() const;
  char* get() const;

  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(int);

  MyString& operator=(const MyString&);
  MyString& operator=(MyString&&);

  bool operator==(const MyString&) const;
  bool operator!=(const MyString&) const;
  bool operator>(const MyString&) const;
  bool operator<(const MyString&) const;
  bool operator>=(const MyString&) const;
  bool operator<=(const MyString&) const;

  MyString operator!();
  char& operator[](int) const;
  int operator()(const char*);
  friend std::ostream& operator<<(std::ostream&, MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
};
#endif  // INCLUDE_MYSTRING_H_
