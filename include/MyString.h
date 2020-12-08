// Copyright 2020 Bulatov D.
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <string.h>

class MyString {
 private:
	 char* stroka;
     size_t len;

 public:
	 explicit MyString(const char* = nullptr);
	 explicit MyString(std::string);
	 MyString(const MyString&);
	 MyString(MyString&&);
	 ~MyString();
	 size_t length();
	 char* get();
	 MyString operator+(const MyString& s);
	 MyString operator-(const MyString& s);
	 MyString operator*(const size_t n);
	 MyString& operator=(const MyString& s);
	 MyString& operator=(MyString&& s);
	 bool operator==(const MyString& s);
	 bool operator!=(const MyString& s);
	 bool operator>(const MyString& s);
	 bool operator<(const MyString& s);
	 bool operator>=(const MyString& s);
	 bool operator<=(const MyString& s);
	 MyString operator!();
	 char operator[](size_t n);
	 int operator()(const char*);
	 friend std::ostream& operator>>(std::ostream& os, MyString& s);
	 friend std::istream& operator>>(std::istream& is, MyString& s);
};

#endif  // INCLUDE_MYSTRING_H_
