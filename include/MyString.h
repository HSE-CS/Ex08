// Copyright 2020 Dev-will-work
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <string>
class MyString {
 private:
  char* string = nullptr;

 public:
  explicit MyString(const char* str = nullptr);  // default - nullptr
  explicit MyString(std::string);
  MyString(const MyString& str);  // copy constructor
  MyString(MyString&& str) : string(str.string)
  { str.string = nullptr; }  // move constructor
  ~MyString();
  size_t length();
  char* get();  // return char* string
  MyString operator+(MyString);  // concatenation
  MyString operator-(MyString);  // filter 1st string by chars in 2nd
  MyString operator*(int);  // creates a new string from repeated old
  MyString& operator=(const MyString&);  // copy assignment
  MyString& operator=(MyString&&);  // move assignment
  bool operator==(MyString);
  bool operator!=(MyString);
  bool operator>(MyString);  // lexicographic comparison
  bool operator<(MyString);  // lexicographic comparison
  bool operator>=(MyString);  // lexicographic comparison
  bool operator<=(MyString);  // lexicographic comparison
  MyString operator!();  // creates news string with inverted registers
  char operator[](int);  // get by index
  int operator()(const char*);  // substring search (kind of naive)
  friend std::ostream& operator<<(std::ostream& out, MyString& str);  // write
  friend std::istream& operator>>(std::istream& in, MyString& str);  // read
};
#endif  // INCLUDE_MYSTRING_H_
