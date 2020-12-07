//Copyright 2020 Pasmanik Irina
#pragma once
#include <iostream>
#include <string>

class MyString {
private:
	char* str;
	int len;

public:
	MyString();
	MyString(const char*);
	MyString(std::string);
	MyString(const MyString&);
	MyString(MyString&&);
	~MyString();
	int length();
	char* get();

	MyString operator+(const MyString&);
	MyString operator-(const MyString&);
	MyString operator*(const MyString&);
	MyString operator=(const MyString&);
	MyString operator=(const MyString&);
	MyString operator==(const MyString&);
	MyString operator!=(const MyString&);
	MyString operator>(const MyString&);
	MyString operator<(const MyString&);
	MyString operator>=(const MyString&);
	MyString operator<= (const MyString&);
	MyString operator!(const MyString&);
	MyString operator[](const MyString&);
	MyString operator()(const MyString&);
	MyString operator>>(const MyString&);
	MyString operator>>(const MyString&);
};

