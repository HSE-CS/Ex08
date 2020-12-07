#pragma once
#include <iostream>
#include <string>

class MyString {
 private:
  char* inner;
  size_t len;

 public:
  // Constructors
  explicit MyString(const char* = nullptr);
  explicit MyString(const std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();
  // Unility
  size_t length();
  char* get();
  // Operators
  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(size_t);
  MyString operator=(const MyString&);
  MyString operator=(MyString&&);
  bool operator==(const MyString&);
  bool operator!=(const MyString&);
  bool operator>(const MyString&);
  bool operator<(const MyString&);
  bool operator>=(const MyString&);
  bool operator<=(const MyString&);
  MyString operator!();
  char operator[](size_t);
  int32_t operator()(const char* other);
  friend std::istream& operator>>(std::istream& other, MyString& str);
  friend std::ostream& operator<<(std::ostream& other, MyString& str);
};
