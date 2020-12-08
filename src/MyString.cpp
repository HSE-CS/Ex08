// Copyright 2020 Khoroshavina Ekaterina
#pragma warning(disable : 4996)
#include "MyString.h"
#include <string>
#include <string.h>

MyString::MyString(const char* str) {
	this->len = strlen(str);
	this->string = strdup(str);
}

MyString::MyString(const std::string& str) {
	this->len = str.length();
	this->string = strdup(str.c_str());
}

MyString::MyString(const MyString& str) {
	this->len = str.len;
	this->string = strdup(str.string);
}

MyString::MyString(MyString&& str) noexcept {
	this->len = str.len;
	this->string = str.string;
	str.len = 0;
	free(str.string);
}

MyString::~MyString() {
	this->len = 0;
	free(this->string);
}

int MyString::length() const{
	return this->len;
}

char* MyString::get() const {
	return this->string;
}

MyString MyString::operator+(const MyString& str) {
	return MyString(std::string(this->get()) + std::string(str.get()));
}

MyString MyString::operator-(const MyString& str) {
	std::string s(this->get());
	for (char c : std::string(str.get())) {
		while (s.find(c) != -1) {
			s.erase(s.find(c), 1);
		}
	}
	return MyString(s);
}

MyString MyString::operator*(int a)
{
	std::string s;
	for (int i = 0; i < a; i++) {
		s.append(this->get());
	}
	return MyString(s);
}

