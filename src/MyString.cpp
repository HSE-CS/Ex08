//Copyright 2020 Pasmanik Irina
#include "MyString.h"
#include <iostream>
#include <string>

MyString::MyString() {
	str = nullptr;
	len = 0; 
}

MyString::MyString(int len) {
	this->len = len;
	str = new char[len];
}

MyString::MyString(const char* str) {}

MyString::MyString(std::string) {}

MyString::MyString(const MyString&){}

MyString::MyString(MyString&&) {}

MyString::~MyString() {
	delete[] str;
	len = 0;
}

int MyString::length() {
	return len;
}

char* MyString::get() {
	return str;
}


MyString MyString::operator+(MyString& a) {
	MyString new_str(len + a.len + 1);
	strcat(new_str.str, str);
	strcat(new_str.str, a.str);
	return new_str;
}

MyString MyString::operator-(MyString& a) {
	char* tmp = new char[len + a.len + 1];
	for (int i = 0; i < a.len; i++) {
		for (int j = 0; j < len; j++) {
			if (a.str[i] == str[j]) {
				for (int k = j + 1; k < len - 1; k++) {
					str[k - 1] = str[k];
				}
			}
		}
	}
}

MyString MyString::operator*(int a) {
	MyString new_str((len * a) + 1);
	for (int i = 0; i < a - 1; a++) {
		strcat(new_str.str, str);
	}
	return new_str;
}

MyString MyString::operator=(const MyString&) {}

MyString MyString::operator=(const MyString&) {}

bool MyString::operator==(MyString& a) {
	if (len != a.len) {
		return false;
	}
	int i = 0;
	for (; i < len; i++) {
		if (a.str[i] != str[i]) {
			return false;
			break;
		}
	}
	if (len == (i - 1)) {
		return true;
	}
}

bool MyString::operator!=(MyString& a) {
	if (len != a.len) {
		return true;
	}
	int i = 0;
	for (; i < len; i++) {
		if (a.str[i] != str[i]) {
			return true;
			break;
		}
	}
	if (len == (i - 1)) {
		return false;
	}
}

bool MyString::operator>(MyString& a) {
	for (int i = 0; i < len; i++) {
		if (a.str[i] != str[i]) {
			return true;
			break;
		}
	}
}

MyString MyString::operator<(const MyString&);
MyString MyString::operator>=(const MyString&);
MyString MyString::operator<= (const MyString&);
MyString MyString::operator!(const MyString&);
MyString MyString::operator[](const MyString&);
MyString MyString::operator()(const MyString&);
MyString MyString::operator>>(const MyString&);
MyString MyString::operator>>(const MyString&);
