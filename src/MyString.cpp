// Copyright 2020 Polina Lukicheva
#include "MyString.h"
#include <cstring>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

MyString::MyString(const char* str) {
  if (str != nullptr) {
    char* newString = new char[strlen(str)];
    snprintf(newString, strlen(str) + 1, "%s", str);
    this->arString = newString;
  } else {
    char* newString = new char[0];
    this->arString = newString;
}
}

MyString::MyString(std::string str) {
  char* newString = new char[str.length()];
  snprintf(newString, str.length() + 1, "%s", str.c_str());
  this->arString = newString;
}

MyString::MyString(const MyString &str) {
  this->arString = str.arString;
}

MyString::MyString(MyString &&str) {
  this->arString = str.arString;
  str.arString = nullptr;
}

MyString::~MyString() {
  delete this->arString;
}

int MyString::length() const {
  return strlen(this->arString);
}

char* MyString::get() const {
  return this->arString;
}

MyString MyString::operator+(const MyString& str) {
  return MyString(std::string(this->get()) + std::string(str.get()));
}

MyString MyString::operator-(const MyString& str) {
  std::string sourceStr(this->arString);
  for (int i = 0; i < str.length(); ++i)
    while (sourceStr.find(str.arString[i]) != -1)
      sourceStr.erase(sourceStr.find(str.arString[i]), 1);
  return MyString(sourceStr);
}

MyString MyString::operator*(int n) {
  std::string sourceStr(this->arString);
  std::string result;
  for (int i = 0; i < n; ++i)
    result += sourceStr;
  return MyString(result);
}

MyString& MyString::operator=(const MyString& str) {
  if (this->arString != nullptr)
    delete (this->arString);
  this->arString = str.arString;
  return *this;
}

MyString& MyString::operator=(MyString&& str) {
  if (this->arString != nullptr)
    delete (this->arString);
  this->arString = str.arString;
  str.arString = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& str) {
  return !(strcmp(this->arString, str.arString));
}

bool MyString::operator!=(const MyString& str) {
  return (strcmp(this->arString, str.arString));
}

bool MyString::operator>(const MyString& str) {
  return strcmp(this->arString, str.arString) > 0;
}

bool MyString::operator<(const MyString& str) {
  return strcmp(this->arString, str.arString) < 0;
}

bool MyString::operator>=(const MyString& str) {
  return strcmp(this->arString, str.arString) > -1;
}

bool MyString::operator<=(const MyString& str) {
  return strcmp(this->arString, str.arString) < 1;
}

MyString MyString::operator!() {
  std::string res(this->arString);
  for (int i = 0; i < res.length(); ++i)
    if (res[i] >= 'a' && res[i] <= 'z')
      res[i] -= 32;
  return MyString(res);
}

char& MyString::operator[](int n) {
  if (n < 0 || n >= this->length()) throw "Index out of range";
  return this->arString[n];
}

int MyString::operator()(const char* substr) {
  char* ptrstr = strstr(this->get(), substr);
  if (ptrstr == nullptr) {
    return -1;
  } else {
    return ptrstr - this->get();
  }
}

std::ostream& operator<<(std::ostream& st, MyString& str) {
  return st << str.get();
}

std::istream& operator>>(std::istream& stream, MyString& str) {
  return stream >> str.get();
}
