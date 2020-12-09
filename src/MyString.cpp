// Copyright 2020 Shirokov Alexander

#include <iostream>
#include "MyString.h"

MyString::MyString() {
  data = nullptr;
  len = 0;
}

MyString::MyString(const char* str) {
  data = nullptr;
  len = 0;
  if (str != nullptr) {
	int len = strlen(str);
  this->len = len;
  data = new char[len + 1];
  for (int i = 0; i < len; i++)
    data[i] = str[i];
  data[len] = '\0';
  }
}

MyString::MyString(std::string str) {
  data = nullptr;
  len = 0;
  if (str.length() != 0) {
    int len = str.length();
	this->len = len;
	data = new char[len + 1];
	for (int i = 0; i < len; i++)
	  data[i] = str[i];
	data[len] = '\0';
  }
}

MyString::MyString(const MyString& str) {
  len = str.len;
  data = new char[len + 1];
  for (int i = 0; i < len; i++)
    data[i] = str[i];
  data[len] = '\0';
}

MyString::MyString(MyString&& str) {
  len = str.len;
  data = new char[len + 1];
  for (int i = 0; i < len; i++)
	data[i] = str[i];
  data[len] = '\0';
  str.~MyString();
  str.data = nullptr;
  str.len = 0;
}

MyString::~MyString() {
  delete this->data;
}

int MyString::length() {
  return len;
}

char* MyString::get() {
  return data;
}

MyString MyString::operator+(const MyString& str) {
  int len1 = str.len;
  MyString str1;
  str1.len = len + len1;
  str1.data = new char[len + len1 + 1];
  int i = 0;
  for (i; i < len; i++)
    str1.data[i] = data[i];
  for (i; i < len + len1; i++)
	str1.data[i] = str.data[i - len];
  str1.data[i] = '\0';
  return str1;
}

MyString MyString::operator-(const MyString& str) {
  if (data) {
    std::string temp = (std::string(data));
    int i = 0;
	while (i < str.len) {
	  while (temp.find(str.data[i]) != -1) {
		temp.erase(temp.find(str.data[i]), 1);
	  }
	  i++;
	}
	MyString str1(temp);
	return str1;
  } else {
    MyString str1(nullptr);
	return str1;
  }
}

MyString MyString::operator*(const int a) {
  if (data) {
	MyString str;
	str.len = len * a;
	str.data = new char[len * a + 1];
	for (int i = 0; i < a; i++) {
	  for (int j = 0; j < len; j++)
	    str.data[i * len + j] = data[j];
	}
	str.data[len * a] = '\0';
	return str;
  } else {
	MyString str(nullptr);
	return str;
  }
}

MyString& MyString::operator=(const MyString& str) {
  len = str.len;
  data = new char[len + 1];
  int i = 0;
  for (int i = 0; i < len; i++)
	data[i] = str[i];
  data[len] = '\0';
  return *this;
}

MyString& MyString::operator=(MyString&& str) {
  len = str.len;
  data = str.data;
  str.len = 0;
  str.data = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& str) {
  return !strcmp(data, str.data);
}

bool MyString::operator!=(const MyString& str) {
  return strcmp(data, str.data);
}

bool MyString::operator>(const MyString& str) {
  return (strcmp(data, str.data) == 1);
}

bool MyString::operator<(const MyString& str) {
  return (strcmp(data, str.data) == -1);
}

bool MyString::operator>=(const MyString& str) {
  return (strcmp(data, str.data) > 1);
}

bool MyString::operator<=(const MyString& str) {
  return (strcmp(data, str.data) < 1);
}

MyString MyString::operator!() {
  if (data == nullptr)
	return MyString(nullptr);
  char* str = new char[len + 1];
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (data[i] >= 'a' && data[i] <= 'z')
	  str[j] = data[i] - 32;
	else {
	  if (data[i] >= 'A' && data[i] <= 'Z')
	    str[j] = data[i] + 32;
	  else 
		str[j] = data[i];
	}
	j++;
  }
  str[j] = '\0';
  return MyString(str);
}

char& MyString::operator[](int index) const {
  if (index < 0 || index > len || data == nullptr)
    throw "Index out of range";
  return data[index];
}

int MyString::operator()(const char* str) {
  if (str == nullptr || data == nullptr)
	throw "Incorrect data";
  char* search = strstr(data, str);
  if (search == nullptr)
	return -1;
  else
	return search - data;
}

std::ostream& operator<<(std::ostream& stream, MyString& str) {
  return stream << str.get();
}

std::istream& operator>>(std::istream& stream, MyString& str) {
  return stream >> str.get();
}