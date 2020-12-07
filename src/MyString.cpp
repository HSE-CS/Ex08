// Copyright 2020 Ex08 TiNa
#include "MyString.h"
#include <string>
#include <cstring>
#include <iostream>

MyString::MyString(const char* str) {
  if (str == nullptr) {
    symb = nullptr;
    len = 0;
  } else {
    len = strlen(str);
    symb = new char[len + 1];
    snprintf(symb, len + 1, "%s", str);
  }
}

MyString::MyString(std::string str) {
  len = str.size();
  symb = new char[len + 1];
  snprintf(symb, len + 1, "%s", str.c_str());
}

MyString::MyString(const MyString& str) {
  len = str.len;
  symb = new char[len + 1];
  snprintf(symb, len + 1, "%s", str.symb);
}

MyString::MyString(MyString&& str) {
  len = str.len;
  symb = str.symb;
  str.len = 0;
  str.symb = nullptr;
}

MyString::~MyString() {
  delete[] symb;
}

int MyString::length() const {
  return len;
}

char* MyString::get() const {
  return symb;
}

MyString MyString::operator+(const MyString& str) {
  int newLen = len + str.length();
  char* res = new char[newLen + 1];
  snprintf(res, len + 1, "%s", symb);
  snprintf(res + len, str.length() + 1, "%s", str.get());
  res[newLen] = 0;
  return MyString(res);
}

MyString MyString::operator-(const MyString& str) {
  std::string arr = std::string(symb, symb + len);
  for (int i = 0; i < str.length(); i++)
    while (arr.find(str.symb[i]) != -1)
      arr.erase(arr.find(str.symb[i]), 1);
  return MyString(arr);
}

MyString MyString::operator*(const int num) {
  MyString res;
  for (int i = 0; i < num; i++)
    res = *this + res;
  return res;
}

MyString& MyString::operator=(const MyString& str) {
  len = str.len;
  symb = strdup(str.symb);
  return *this;
}

MyString& MyString::operator=(MyString&& str) {
  len = str.len;
  symb = strdup(str.symb);
  return *this;
}

bool MyString::operator==(const MyString& str) {
  if (strcmp(symb, str.symb) == 0)
    return true;
  else
    return false;
}

bool MyString::operator!=(const MyString& str) {
  return strcmp(symb, str.symb);
}

bool MyString::operator>(const MyString& str) {
  if (strcmp(symb, str.symb) > 0)
    return true;
  else
    return false;
}

bool MyString::operator<(const MyString& str) {
  if (strcmp(symb, str.symb) < 0)
    return true;
  else
    return false;
}

bool MyString::operator>=(const MyString& str) {
  if (strcmp(symb, str.symb) >= 0)
    return true;
  else
    return false;
}

bool MyString::operator<=(const MyString& str) {
  if (strcmp(symb, str.symb) <= 0)
    return true;
  else
    return false;
}

MyString MyString::operator!() {
  MyString res(*this);
  for (int i = 0; i < res.len; i++)
    if (res.symb[i] >= 'a' && res.symb[i] <= 'z')
      res.symb[i] -= 'a' - 'A';
    else
      if (res.symb[i] >= 'A' && res.symb[i] <= 'Z')
          res.symb[i] += 'a' - 'A';
  return res;
}

char& MyString::operator[](int num) {
  return symb[num];
}

int MyString::operator()(const char* str) {
  char* temp = strstr(symb, str);
  if (temp == nullptr)
    return -1;
  else
    return temp - symb;
}

std::ostream& operator<<(std::ostream& os, MyString& str) {
  return os << str.get();
}

std::istream& operator>>(std::istream& is, MyString& str) {
  return is >> str.get();
}
