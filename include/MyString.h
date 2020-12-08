// Copyright 2020 Bulatov D.
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>

class MyString {
private:
	char* stroka;
	int len;

public:
	explicit MyString(const char* = nullptr);
	explicit MyString(std::string s);
	MyString(const MyString&);
	MyString(MyString&&);
	~MyString();
	int length();
	char* get();
	MyString operator+(const MyString& s);
	MyString operator-(const MyString& s);
	MyString operator*(const int n);
	MyString& operator=(const MyString& s);
	MyString& operator=(MyString&& s);
	bool operator==(const MyString& s);
	bool operator!=(const MyString& s);
	bool operator>(const MyString& s);
	bool operator<(const MyString& s);
	bool operator>=(const MyString& s);
	bool operator<=(const MyString& s);
	MyString operator!();
	char operator[](int n);
	int operator()(const char*);
	friend std::ostream& operator>>(std::ostream& os, MyString& s);
	friend std::istream& operator>>(std::istream& is, MyString& s);
};

#endif  // INCLUDE_MYSTRING_H_
