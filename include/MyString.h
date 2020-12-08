// Copyright 2020 Ozhiganova Polina
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <iostream>
#include <string>

class MyString {
 public:
  explicit MyString(const char *str = nullptr);
  explicit MyString(const std::string &str);
  MyString(const MyString &new_str);
  MyString(MyString &&str);
  ~MyString();
  [[nodiscard]] size_t length() const;
  [[nodiscard]] char *get() const;

  MyString operator+(const MyString &new_str);
  MyString operator-(const MyString &new_str);
  MyString operator*(size_t size) const;
  MyString operator=(const MyString &new_str);
  MyString operator=(MyString &&new_str);
  bool operator==(const MyString &new_str) const;
  bool operator!=(const MyString &new_str) const;
  bool operator>(const MyString &new_str) const;
  bool operator<(const MyString &new_str) const;
  bool operator>=(const MyString &new_str) const;
  bool operator<=(const MyString &new_str) const;
  MyString operator!();
  char &operator[](size_t ind) const;
  int operator()(char *new_str);
  friend std::ostream &operator<<(std::ostream &stream, MyString &new_str);
  friend std::istream &operator>>(std::istream &stream, MyString &new_str);

 private:
  char *st;
};

#endif  // INCLUDE_MYSTRING_H_
