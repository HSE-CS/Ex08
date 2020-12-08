// Copyright 2020 Shelby Ltd.
#pragma once

#include <cstring>
#include <iostream>
#include <string>

class MyString {
 private:
  char *str;

 public:
  explicit MyString(const char * = nullptr);
  explicit MyString(std::string);
  MyString(const MyString &);
  MyString(MyString &&);
  ~MyString();
  int length() const;
  char *get() const;
  MyString operator+(const MyString &);
  MyString operator-(const MyString &);
  MyString operator*(int);
  MyString &operator=(const MyString &);
  MyString &operator=(MyString &&);
  bool operator==(const MyString &);
  bool operator!=(const MyString &);
  bool operator>(const MyString &);
  bool operator<(const MyString &);
  bool operator>=(const MyString &);
  bool operator<=(const MyString &);
  MyString operator!();
  char &operator[](int);
  int operator()(const char *);
  friend std::ostream &operator<<(std::ostream &, MyString &);
  friend std::istream &operator>>(std::istream &, MyString &);
};
