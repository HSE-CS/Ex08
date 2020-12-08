// Copyright 2020 ArinaMonicheva
#ifndef MYSTRING_MYSTRING_H_
#define MYSTRING_MYSTRING_H_

#include <string>
#include <cstring>
#include <iostream>
#include <cctype>

class MyString {
 private:
  char *myString;

 public:
  MyString();
  explicit MyString(const char* newStr);
  explicit MyString(std::string newStr);
  MyString(const MyString& otherString);
  MyString(MyString&& toShift);
  ~MyString();

  char* get() const;
  size_t length() const;

  MyString operator+(const MyString& otherString);
  MyString operator-(const MyString& otherString);
  MyString operator*(size_t repeat);
  MyString& operator=(const MyString& otherString);
  MyString& operator=(MyString&& toShift);

  bool operator==(const MyString& otherString) const;
  bool operator!=(const MyString& otherString) const;
  bool operator>(const MyString& otherString) const;
  bool operator<(const MyString& otherString) const;
  bool operator>=(const MyString& otherString) const;
  bool operator<=(const MyString& otherString) const;

  MyString operator!();
  char& operator[](size_t index) const;
  int operator()(const char* subString);

  friend std::ostream& operator<<(std::ostream& sout, MyString& toPrint);
  friend std::istream& operator>>(std::istream& sin, MyString& toWrite);
};

#endif // MYSTRING_MYSTRING_H_
