// Copyright 2020 OsmanovIslam
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <iostream>
#include <cstring>


class MyString {
 private:
  char* str;

 public:
  MyString(const char* strArray = nullptr);
  MyString(std::string);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();
  char* get() const;
  int length();
  bool operator<=(const MyString&);
  bool operator>=(const MyString&);
  bool operator<(const MyString&);
  bool operator>(const MyString&);
  bool operator!=(const MyString&);
  bool operator==(const MyString&);
  MyString operator!();
  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(const int length);
  MyString& operator=(const MyString&);
  MyString& operator=(MyString&&);
  char operator[](unsigned int num) const;
  int operator()(const char*);
  friend std::ostream& operator<<(std::ostream &valStream , MyString &str);
  friend std::istream& operator>>(std::istream &valStream, MyString &str);

};
#endif //INCLUDE_MYSTRING_H_