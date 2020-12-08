// Copyright by Stanislav on 07/12/2020.

#ifndef EX08_SRC_MYSTRING_H_
#define EX08_SRC_MYSTRING_H_

#include <iostream>
#include <string.h>
#include <string>
#include <cstdint>

class MyString {
 private:

  char *characters;
  size_t size;

 public:

  MyString(const char *characters = nullptr);

  MyString(const std::string &string);

  MyString(const MyString &string);

  MyString(MyString &&string) noexcept;

  ~MyString();

  size_t length() const;

  char *get() const;

  MyString operator+(MyString &string) const;

  MyString operator-(MyString &string) const;

  MyString operator*(size_t factor) const;

  MyString &operator=(const MyString &string);

  MyString &operator=(MyString &&string) noexcept;

  bool operator==(const MyString &string) const;

  bool operator!=(const MyString &string) const;

  bool operator>(const MyString &string) const;

  bool operator<(const MyString &string) const;

  bool operator>=(const MyString &string) const;

  bool operator<=(const MyString &string) const;

  MyString operator!();

  char &operator[](size_t index);

  int32_t operator()(const char *string) const;

  friend std::istream &operator>>(std::istream &in, MyString &string);

  friend std::ostream &operator<<(std::ostream &out, MyString &string);

};

#endif //EX08_SRC_MYSTRING_H_
