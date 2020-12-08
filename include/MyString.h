// Copyright 2020 Dmitry Vargin
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include<iostream>
#include<cstring>
#include<string>

class MyString {
 private:
  char *str = nullptr;

 public:
  explicit MyString(const char * = nullptr);
  explicit MyString(std::string str);
  MyString(const MyString& str);
  MyString(MyString&& str);

  ~MyString();

  int length() const;
  char *get() const;

  MyString operator+(const MyString&str);
  MyString operator-(const MyString&str);
  MyString operator*(size_t num);

  MyString& operator=(const MyString&str);
  MyString& operator=(MyString&&str);

  MyString& operator!();
  bool operator==(const MyString&str);
  bool operator!=(const MyString&str);
  bool operator>(const MyString&str);
  bool operator<(const MyString&str);
  bool operator>=(const MyString&str);
  bool operator<=(const MyString&str);

  char& operator[](unsigned int index) const;
  int operator()(const char* substring);

  friend std::ostream& operator<<(std::ostream&, MyString&str);
  friend std::istream& operator>>(std::istream&, MyString&str);
};


#endif  // INCLUDE_MYSTRING_H_
