//  Copyright 2020 AndreyBakurskii
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_


#include <iostream>
#include <string>
#include <cstring>
#include <sstream>



class MyString {
 private:
  size_t size;
  char* array;

 public:
  explicit MyString(const char* = nullptr);
  explicit MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();

  size_t length() const;
  char* get() const;

  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(size_t);

  MyString& operator=(const MyString&);
  MyString& operator=(MyString&&);

  bool operator==(const MyString&);
  bool operator!=(const MyString&);
  bool operator>(const MyString&);
  bool operator<(const MyString&);
  bool operator>=(const MyString&);
  bool operator<=(const MyString&);

  MyString operator!();

  char& operator[](const size_t) const;

  int operator()(const char*);

  friend std::ostream& operator<<(std::ostream&, MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
};

#endif  // INCLUDE_MYSTRING_H_
