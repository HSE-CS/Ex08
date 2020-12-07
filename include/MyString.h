// Copyright 2020 FOM

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>

class MyString {
private:
    char* str;
    unsigned int len;
public:
    MyString();
    MyString(const char*);
    MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    unsigned int length();
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
#endif  // INCLUDE_MYSTRING_H_
