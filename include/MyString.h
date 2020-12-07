// Copyright by Stanislav on 07/12/2020.

#ifndef EX08_SRC_MYSTRING_H_
#define EX08_SRC_MYSTRING_H_

#include <iostream>
#include <string.h>
#include <string>

class MyString {
 private:

  char *inner;
  size_t len;

 public:

  MyString(const char *characters);
  MyString(const std::string& string);
  MyString(const MyString &string);
  MyString(MyString &&string);

  ~MyString();

  size_t length() const;
  char *get();

  MyString operator+(MyString &string);
  MyString operator-(MyString &string);
  MyString operator*(size_t factor);
  MyString operator=(MyString &string);
  MyString operator=(MyString &&string);

  bool operator==(const MyString &string);
  bool operator!=(const MyString &string);
  bool operator>(const MyString &string);
  bool operator<(const MyString &string);
  bool operator>=(const MyString &string);
  bool operator<=(const MyString &string);

  MyString operator!();
  char operator[](size_t index);
  int32_t operator()(const char *string);
  friend std::istream &operator>>(std::istream &in, MyString &string);
  friend std::ostream &operator<<(std::ostream &out, MyString &string);

};

#endif //EX08_SRC_MYSTRING_H_
