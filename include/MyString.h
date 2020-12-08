// Copyright 2020 Bulatov D.
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

class MyString {
 private:
	 char* str;
     size_t len;
 public:
	 explicit MyString(const char* s = nullptr);
	 explicit MyString(string s);
	 MyString(const MyString& s);
	 MyString(MyString&& s);
	 ~MyString();
	 size_t length();
	 char* get();
	 MyString operator+(const MyString& s);
	 MyString operator-(const MyString& s);
	 MyString operator*(size_t n);
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
	 int operator()(const char* s);
	 friend ostream& operator>>(ostream& os, MyString& str);
	 friend istream& operator>>(istream& is, MyString& str);
};

#endif  // INCLUDE_MYSTRING_H_
