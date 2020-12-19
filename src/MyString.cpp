// Copyright 2020 Bugrov
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <string.h>

MyString::MyString(const char* new_str) {
	if (new_str == nullptr) {
		len = 0;
		str = nullptr;
	}
	else {
		len = strlen(new_str);
		str = new char[len + 1];
		for (size_t i = 0; i <= len; ++i)
			str[i] = new_str[i];
	}
}

MyString::MyString(std::string new_str) {
	len = new_str.size();
	str = new char[len + 1];
	for (size_t i = 0; i <= len; ++i)
		str[i] = new_str[i];
}

MyString::MyString(const MyString& new_str) {
	len = new_str.len;
	str = new char[len + 1];
	for (size_t i = 0; i <= len; ++i)
		str[i] = new_str.str[i];
}

MyString::MyString(MyString&& new_str) {
	len = new_str.len;
	str = new_str.str;
	new_str.len = 0;
	new_str.str = nullptr;
}

MyString::~MyString() {
	len = 0;
	delete[] str;
}

int MyString::length() {
	return len; 
}

char *MyString::get() {
	return str; 
}



MyString MyString::operator+(const MyString& add_str) {
	unsigned int len1 = this->length();
	unsigned int len2 = add_str.len;
	char* new_str = new char[len1 + len2 + 1];
	int i = 0;
	for (i; i < len1; i++) {
		new_str[i] = str[i];
	}
	int j = 0;
	for (i; i < (len1 + len2); i++) {
		new_str[i] = add_str.str[j];
		j++;
	}
	new_str[i] = '\0';
	MyString new_str_n(new_str);
	return new_str_n;
}

MyString MyString::operator-(const MyString& new_str) {
	if (new_str.str == nullptr)
		return *this;
	MyString temp_str;
	temp_str.len = 0;
	for (size_t i = 0; i < this->len; ++i) {
		bool check = true;
		for (size_t j = 0; j < new_str.len; ++j)
			if (str[i] == new_str.str[j])
				check = false;
		if (check)
			temp_str.len++;
	}
	temp_str.str = new char[temp_str.len + 1];
	size_t pointer = 0;
	for (size_t i = 0; i < len; ++i) {
		bool check = true;
		for (size_t j = 0; j < new_str.len; ++j)
			if (str[i] == new_str.str[j])
				check = false;
		if (check) {
			temp_str.str[pointer] = str[i];
			pointer++;
		}
	}
	temp_str.str[pointer] = '\0';
	return temp_str;
}

MyString MyString::operator*(int n) {
	if (n < 0)
		throw "Wrong multiplier";
	char* buffer = new char[n * len + 1];
	size_t pointer = 0;
	for (int count = 0; count < n; ++count)
		for (size_t i = 0; i < len; ++i) {
			buffer[pointer] = str[i];
			pointer++;
		}
	buffer[pointer] = '\0';
	return MyString(buffer);
}

MyString& MyString::operator=(const MyString& new_str) {
	len = new_str.len;
	str = new_str.str;
	return *this;
}
MyString& MyString::operator=(MyString&& new_str) {
	len = new_str.len;
	str = new_str.str;
	return *this;
}

bool MyString::operator==(const MyString& new_str) {
	return strcmp(str, new_str.str) == 0;
}

bool MyString::operator!=(const MyString& new_str) {
	return strcmp(str, new_str.str) != 0;
}

bool MyString::operator>(const MyString& new_str) {
	return strcmp(str, new_str.str) == 1;
}

bool MyString::operator<(const MyString& new_str) {
	return strcmp(str, new_str.str) == -1;
}

bool MyString::operator>=(const MyString& new_str) {
	return strcmp(str, new_str.str) != -1;
}

bool MyString::operator<=(const MyString& new_str) {
	return strcmp(str, new_str.str) != 1;
}

MyString MyString::operator!() {
	for (size_t i = 0; i < len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 'a' - 'A';
		}
	}
	return MyString(str);
}

char &MyString::operator[](int i){
	return str[i]; }

int MyString::operator()(const char *new_str) {
	int len_substr = strlen(new_str);
	for (int i = 0; i < len - len_substr + 1; ++i) {
		bool flag = true;
		for (int j = 0; j < len_substr; ++j) {
			if (str[i + j] != new_str[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return i;
		}
	}
	return -1;
}


std::istream& operator>>(std::istream& inp, MyString& new_str) {
	return inp >> new_str.get();
}
std::ostream& operator<<(std::ostream& out, MyString& new_str) {
	return out << new_str.get();
}