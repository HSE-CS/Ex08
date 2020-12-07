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
	MyString(int len);
	MyString(const char*);
	MyString(std::string);
	MyString(const MyString&);
	MyString(MyString&&);
	~MyString();
	int length();
	char* get();

	MyString operator+(MyString& a);
	MyString operator-(MyString& a);
	MyString operator*(int a);
	MyString operator=(const MyString&); //TODO
	MyString operator=(const MyString&); //TODO
	bool operator==(MyString& a);
	bool operator!=(MyString& a);
	bool operator>(MyString& a);
	bool operator<(MyString& a);
	bool operator>=(MyString& a);
	bool operator<= (MyString& a);
	MyString operator!(const MyString&);
	MyString operator[](const MyString&);
	MyString operator()(const MyString&);
	MyString operator>>(const MyString&);
	MyString operator>>(const MyString&);
};

