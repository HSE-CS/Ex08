// Copyright 2020 GHA Test Team
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>
#include <iostream>

class MyString{
 private:
  char * str;
  unsigned len;

 public:
  explicit MyString(const char* x = nullptr);
  explicit MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();
  int length() const;
  char* get() const;
  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(int);
  MyString& operator=(const MyString&);
  MyString& operator=(MyString&&);
  char& operator[] (const int);
  const char* operator()(const char*);
  MyString& operator! ();
  bool operator==(const MyString&);
  bool operator!=(const MyString&);
  bool operator>(const MyString&);
  bool operator<(const MyString&);
  bool operator>=(const MyString&);
  bool operator<=(const MyString&);
  friend std::ostream& operator<<(std::ostream&, MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
};

#endif  // INCLUDE_MYSTRING_H_


