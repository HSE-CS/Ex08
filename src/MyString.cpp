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
	this->str = new char[this->len];
}

MyString::MyString(const char* str) {
	this->len = strlen(str);
	this->str = new char[this->len+1];
	int i = 0;
	for (; i < len; i++) {
		this->str[i] = str[i];
	}
	i++;
	this->str[i] = '/0';
}

MyString::MyString(std::string str) {
	this->len = str.length();
	this->str = new char[this->len + 1];
	int i = 0;
	for (; i < len; i++) {
		this->str[i] = str[i];
	}
	i++;
	this->str[i] = '/0';
}

MyString::MyString(const MyString& a){
	this->len = a.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, a.str);
}

MyString::MyString(const MyString&& a) {
	this->len = a.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, a.str);
	a.~MyString();
}

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



MyString MyString::operator+(const MyString& a) {
	MyString new_str(len + a.len + 1);
	strcat(new_str.str, str);
	strcat(new_str.str, a.str);
	return new_str;
}

MyString MyString::operator-(const MyString& a) {
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

MyString MyString::operator=(const MyString& a) {
	MyString new_str(a);
	return new_str;
}

MyString MyString::operator=(const MyString& a) {
	MyString new_str(a);
	a.~MyString();
	return new_str;
}

bool MyString::operator==(const MyString& a) {
	int res = strcmp(str, a.str);
	if (res == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool MyString::operator!=(const MyString& a) {
	int res = strcmp(str, a.str);
	if (res == 0) {
		return false;
	}
	else {
		return true;
	}
}

bool MyString::operator>(const MyString& a) {
	int res = strcmp(str, a.str);
	if (res > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool MyString::operator<(const MyString& a) {
	int res = strcmp(str, a.str);
	if (res < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool MyString::operator>=(const MyString& a) {
	int res = strcmp(str, a.str);
	if (res >= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool MyString::operator<=(const MyString& a) {
	int res = strcmp(str, a.str);
	if (res <= 0) {
		return true;
	}
	else {
		return false;
	}
}

MyString MyString::operator!() {
	MyString new_str(len + 1);
	for (int i = 0; i < len; i++) {
		if (((int)str[i] > 64) && ((int)str[i] < 91)) {
			new_str[i] = tolower(str[i]);
		}
		else if (((int)str[i] > 96) && ((int)str[i] < 123)) {
			new_str[i] = toupper(str[i]);
		}
		else {
			new_str[i] = str[i];
		}
	}
	return new_str;
}

char& MyString::operator[](int idx) {
	return str[idx];
}

MyString MyString::operator()(const MyString& a) {}

MyString MyString::operator>>(const MyString& a) {}

MyString MyString::operator>>(const MyString& a) {}
