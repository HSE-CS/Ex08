#pragma once
#ifndef _MYSTRING_H
#define _MYSTRING_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class MyString
{
private:
	char* str;
	size_t len;
public:
	MyString(size_t);
	MyString(const char* = nullptr);
	MyString(std::string);
	MyString(const MyString&);
	MyString(MyString&&);
	~MyString();
	size_t length();
	char* get();

	MyString operator + (MyString);
	MyString operator - (MyString);
	MyString operator * (size_t);
	MyString& operator = (const MyString&); 
	MyString& operator = (MyString&&);  
	bool operator == (MyString);
	bool operator != (MyString);
	bool operator < (MyString);
	bool operator > (MyString);
	bool operator >= (MyString);
	bool operator <= (MyString);
	MyString operator!();
	char operator[] (size_t);
	int operator() (const char*);
	friend std::ostream& operator<< (std::ostream&, MyString&);  
	friend std::istream& operator>> (std::istream&, MyString&); 
	
};

//std::ostream& operator<< (std::ostream&, MyString);
//std::istream& operator>> (std::istream&, MyString);
char* sdvig(char*, size_t);
int podstroka(char*, const char*);
#endif // !_MYSTRING_H
