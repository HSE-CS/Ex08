//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>

class MyString {
 private:
  char* string_container;
    
 public:
  explicit MyString(const char* = nullptr);
  explicit MyString(const std::string mystring_value);
  MyString(const MyString& other_mystring);
  MyString(MyString&& other_mystring);
  ~MyString();

  unsigned int length() const;
  char *get() const;

  MyString operator+(const MyString &other_mystring);
  MyString operator-(const MyString &other_mystring);
  MyString operator*(unsigned int num);
  MyString& operator=(const MyString&);
  MyString& operator=(MyString&&);

  bool operator==(const MyString&) const;
  bool operator!=(const MyString&) const;
  bool operator>(const MyString&) const;
  bool operator<(const MyString&) const;
  bool operator>=(const MyString&) const;
  bool operator<=(const MyString&) const;

  MyString operator!();
  char operator[](unsigned int index) const;
  int operator()(const char *sub_string) const;

  friend std::ostream &operator<<(std::ostream &vS, MyString &vSt);
  friend std::istream &operator>>(std::istream &vS, MyString &vSt);
};


#endif  // INCLUDE_MYSTRING_H_
