#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
class MyString {
private:
	char* str;
	size_t len;

public:
	explicit MyString(const char* new_str = nullptr);
	explicit MyString(std::string);
	MyString(const MyString&);
	MyString(MyString&&);
	~MyString();
	size_t length() const;
	char* get() const;

	MyString operator+(const MyString&);
	MyString operator-(const MyString&);
	MyString operator*(const size_t);
	MyString& operator=(const MyString&);
	MyString& operator=(MyString&&);
	bool operator==(const MyString&);
	bool operator!=(const MyString&);
	bool operator>(const MyString&);
	bool operator<(const MyString&);
	bool operator>=(const MyString&);
	bool operator<=(const MyString&);
	MyString operator!();
	char& operator[](const size_t);
	int operator()(const char*);
	friend std::istream& operator>>(std::istream& stream, MyString s);
	friend std::ostream& operator<<(std::ostream& stream, MyString s);
};
#endif  // INCLUDE_MYSTRING_H_