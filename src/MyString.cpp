// Copyright 2020 Polina Lukicheva
#include "MyString.h"


MyString::MyString(const char* str) {
  if (str != nullptr) {
    char* newString = new char[strlen(str) + 1];
    snprintf(newString, strlen(str) + 1, "%s", str);
    this->arString = newString;
  } else {
    this->arString = new char[1];
    memset(arString, 0, 1);
  }
}

MyString::MyString(std::string str) {
  char* newString = new char[str.length() + 1];
  snprintf(newString, str.length() + 1, "%s", str.c_str());
  this->arString = newString;
}

MyString::MyString(const MyString &str) {
  char* newString = new char[str.length() + 1];
  snprintf(newString, str.length() + 1, "%s", str.get());
  this->arString = newString;
}

MyString::MyString(MyString &&str) {
  char* newString = new char[str.length() + 1];
  snprintf(newString, str.length() + 1, "%s", str.get());
  this->arString = newString;
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
  std::string sourceStr(this->get());
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
  delete (this->arString);
  char* newString = new char[str.length() + 1];
  snprintf(newString, str.length() + 1, "%s", str.get());
  this->arString = newString;
  return *this;
}

MyString& MyString::operator=(MyString&& str) {
  delete (this->arString);
  this->arString = str.get();
  str.arString = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& str) const {
  return !(strcmp(this->arString, str.arString));
}

bool MyString::operator!=(const MyString& str) const {
  return (strcmp(this->arString, str.arString));
}

bool MyString::operator>(const MyString& str) const {
  return strcmp(this->arString, str.arString) > 0;
}

bool MyString::operator<(const MyString& str) const {
  return strcmp(this->arString, str.arString) < 0;
}

bool MyString::operator>=(const MyString& str) const {
  return strcmp(this->arString, str.arString) > -1;
}

bool MyString::operator<=(const MyString& str) const {
  return strcmp(this->arString, str.arString) < 1;
}

MyString MyString::operator!() {
  std::string res(this->arString);
  for (int i = 0; i <= res.length(); ++i)
    if (res[i] >= 'a' && res[i] <= 'z')
      res[i] -= 32;
  return MyString(res);
}

char& MyString::operator[](int n) const {
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
