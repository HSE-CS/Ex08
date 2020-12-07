// Copyright 2020 GHA Test Team
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>

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
  MyString& operator=(const MyString&&);
  friend bool operator== (const MyString&, const MyString&);
  friend bool operator!= (const MyString&, const MyString&);
  friend bool operator> (const MyString&, const MyString&);
  friend bool operator< (const MyString&, const MyString&);
  friend bool operator>= (const MyString&, const MyString&);
  friend bool operator<= (const MyString&, const MyString&);
  friend ostream& operator<<(ostream&, MyString&);
  friend istream& operator>>(istream&, MyString&);
};

#endif  // INCLUDE_MYSTRING_H_
