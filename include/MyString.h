// Copyright 2020 Longa Bonga
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <string>
class MyString {
 private:
  char* field;
  int len;

 public:
  explicit MyString(const char* = nullptr);
  explicit MyString(const std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();
  int length();
  char* get();

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
  int operator()(const char* other);
  friend std::istream& operator>>(std::istream& other, MyString& str);
  friend std::ostream& operator<<(std::ostream& other, MyString& str);
};

#endif  // INCLUDE_MYSTRING_H_
