// Copyright 2020 GHA Test Team
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>

class MyString
{
 private:
  char *string;

 public:
  MyString(char *);
  MyString(std::string);
  MyString(const MyString &);
  MyString(MyString &&);
  ~MyString();
  int length();
  char *get();
  MyString operator+(const MyString &);
  MyString operator-(const MyString &);
  MyString operator*(const size_t);
  MyString &operator=(const MyString &);
  MyString &operator=(MyString &&);
  bool operator==(const MyString &);
  bool operator!=(const MyString &);
  bool operator>(const MyString &);
  bool operator<(const MyString &);
  bool operator>=(const MyString &);
  bool operator<=(const MyString &);
  MyString operator!();
  char &operator[](const size_t) const;
  int operator()(const char *);
  friend std::ostream &operator<<(std::ostream &, MyString &);
  friend std::istream &operator>>(std::istream &, MyString &);
};

#endif  //INCLUDE_MYSTRING_H_
