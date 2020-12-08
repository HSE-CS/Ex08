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
	MyString(const MyString&&);
	~MyString();
	int length();
	char* get();

	MyString operator+(const MyString& a);
	MyString operator-(const MyString& a);
	MyString operator*(int a);
	MyString operator=(const MyString&);
	MyString operator=(const MyString&);
	bool operator==(const MyString& a);
	bool operator!=(const MyString& a);
	bool operator>(const MyString& a);
	bool operator<(const MyString& a);
	bool operator>=(const MyString& a);
	bool operator<= (const MyString& a);
	MyString operator!();
	char& operator[](int idx);
	MyString operator()(const MyString& a); //todo
	MyString operator>>(const MyString& a); //todo
	MyString operator>>(const MyString& a); //todo
};
