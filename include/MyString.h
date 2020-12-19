// Copyright 2020 Bugrov
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>

class MyString {
 private:
	char* str;
	unsigned len;

 public:
	explicit MyString(const char *new_str = nullptr);
	explicit MyString(std::string);
	MyString(const MyString &);
	MyString(MyString &&);
	~MyString();
	int length();
	char *get();
	MyString operator+(const MyString &);
	MyString operator-(const MyString &);
	MyString operator*(int);
	MyString &operator=(const MyString &);
	MyString &operator=(MyString &&);
	bool operator==(const MyString &);
	bool operator!=(const MyString &);
	bool operator>(const MyString &);
	bool operator<(const MyString &);
	bool operator>=(const MyString &);
	bool operator<=(const MyString &);
	MyString operator!();
	char &operator[](int);
	int operator()(const char *);

	friend std::istream &operator>>(std::istream &inp, MyString &new_str);
	friend std::ostream &operator<<(std::ostream &out, MyString &new_str);
};
#endif  // INCLUDE_MYSTRING_H_