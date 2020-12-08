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
  MyString( const char* x=nullptr);
  MyString( std::string );
  MyString( const MyString& );
  MyString( MyString&& );
  ~MyString();
  int length() const;
  const char* get() const;
  MyString operator+(const MyString&);
  MyString operator-(const MyString&);
  MyString operator*(int);
  MyString& operator=(const MyString&);
  MyString& operator=( MyString&&);
  char& operator[] (const int);
  const char* operator()(const char*);
  const char* operator()(std::string);
  MyString& operator! ();
  friend bool operator== (const MyString&, const MyString&);
  friend bool operator!= (const MyString&, const MyString&);
  friend bool operator> (const MyString&, const MyString&);
  friend bool operator< (const MyString&, const MyString&);
  friend bool operator>= (const MyString&, const MyString&);
  friend bool operator<= (const MyString&, const MyString&);
  friend std::ostream& operator<<(std::ostream&, MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
};

#endif  // INCLUDE_MYSTRING_H_


