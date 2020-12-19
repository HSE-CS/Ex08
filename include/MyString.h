// Copyright 2020 SalakhovRamazan

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>
#include <algorithm>


class MyString {
 private:
  char* string_ptr;
  unsigned len;

 public:
  explicit MyString(const char* new_ptr = nullptr);
  explicit MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&) noexcept;
  ~MyString();
  size_t length() const;
  char* get() const;
  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(size_t);
  MyString& operator=(const MyString&);
  MyString& operator=(MyString&&) noexcept;
  bool operator== (const MyString&);
  bool operator!= (const MyString&);
  bool operator> (const MyString&);
  bool operator< (const MyString&);
  bool operator>= (const MyString&);
  bool operator<= (const MyString&);
  MyString operator!();
  char& operator[](int) const;
  int operator()(const char*) const;
  friend std::ostream& operator<<(std::ostream&, MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
};


#endif  // INCLUDE_MYSTRING_H_

