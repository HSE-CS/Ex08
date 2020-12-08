// Copyright by Stanislav on 07/12/2020.

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include <tuple>

class MyString {
 private:
  char *characters = new char;

  size_t size{};

 public:
  explicit MyString(const char *characters = nullptr);

  explicit MyString(std::string &string);

  MyString(const MyString &string);

  MyString(MyString &&string) noexcept;

  ~MyString();

  size_t length() const;

  char *get() const;

  MyString operator+(const MyString &string) const;

  MyString operator-(const MyString &string) const;

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

#endif  // INCLUDE_MYSTRING_H_
