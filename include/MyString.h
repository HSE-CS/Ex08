// Copyright 2020 Bodrov Egor

#ifndef INCLUDE_MYSTRING_H
#define INCLUDE_MYSTRING_H

#include <string>
#include <cstring>
#include <sstream>

class MyString {
private:
	char* string;

public:
	explicit MyString(const char* = nullptr);
	explicit MyString(std::string str);
	MyString(const MyString&);
	MyString(MyString&&);
	~MyString();
	unsigned length() const;
	char* get() const;
	MyString operator+(MyString);
	MyString operator-(MyString);
	MyString operator*(int);
	MyString operator=(const MyString&);
	MyString operator=(MyString&&);
	bool operator==(MyString);
	bool operator!=(MyString);
	bool operator>(MyString);
	bool operator<(MyString);
	bool operator>=(MyString);
	bool operator<=(MyString);
	MyString operator!();
	char& operator[](int);
	int operator()(const char*);
	friend std::ostream& operator<<(std::ostream&, MyString);
	friend std::istream& operator>>(std::istream&, MyString);

};


#endif // INCLUDE_MYSTRING_H
	