// Copyright 2020 _
#pragma once
#include <iostream>
#include <string>

class MyString {
 private:
  char* inner;
  size_t len;

 public:
  // Constructors
  MyString(const char* = nullptr);
  MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();
  // Unility
  size_t length();
  char* get();
  // Operators
  MyString operator+(MyString&);
  MyString operator-(MyString&);
  MyString operator*(size_t);
  MyString operator=(MyString&);
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