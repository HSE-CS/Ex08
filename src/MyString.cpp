// Copyright 2020 GHA Test Team
#include "MyString.h"
#include <cctype>

MyString::MyString(char *str) {
  string = new char[strlen(str)];
  sprintf(string, "%s", str);
}

MyString::MyString(std::string str) {
  string = new char[str.size()];
  sprintf(string, "%s", str.c_str());
}

MyString::MyString(const MyString &str) {
  string = new char[strlen(str.string)];
  sprintf(string, "%s", str.string);
}

MyString::MyString(MyString &&str) {
  string = new char[strlen(str.string)];
  string = str.string;
  str.string = NULL;
}

MyString::~MyString() {
  delete string;
}

int MyString::length() {
  return strlen(string);
}

char *MyString::get() {
  return string;
}

MyString MyString::operator+(const MyString &str) {
  std::string tmp;
  tmp.append(string);
  tmp.append(str.string);
  return MyString(tmp);
}

MyString MyString::operator-(const MyString &str) {
  char *newStr = new char[strlen(string)];
  int index = 0;
  for (int i = 0; i < strlen(string); i++) {
    bool found = false;
    for (int j = 0; j < strlen(str.string); i++) {
      if (str.string[j] == string[i]) {
        found = true;
      }
    }
    if (!found) {
      newStr[index] = string[i];
      index++;
    }
  }
  return MyString(newStr);
}

MyString MyString::operator*(const size_t count) {
  MyString ans(string);
  for (int i = 0; i < count - 1; i++) {
    ans = ans + *this;
  }
  return ans;
}

MyString &MyString::operator=(const MyString &str) {
  string = new char[strlen(str.string)];
  sprintf(string, "%s", str.string);
  return *this;
}

MyString &MyString::operator=(MyString &&str) {
  string = str.string;
  str.string = NULL;
  return *this;
}

bool MyString::operator==(const MyString &str) {
  return !strcmp(string, str.string);
}

bool MyString::operator!=(const MyString &str) {
  return strcmp(string, str.string);
}

bool MyString::operator>(const MyString &str) {
  return strcmp(string, str.string) == 1;
}

bool MyString::operator<(const MyString &str) {
  return strcmp(string, str.string) == -1;
}

bool MyString::operator>=(const MyString &str) {
  return strcmp(string, str.string) != -1;
}

bool MyString::operator<=(const MyString &str) {
  return strcmp(string, str.string) != 1;
}

MyString MyString::operator!() {
  std::string tmp;
  for (int i = 0; i < strlen(string); i++) {
    if (isupper(string[i]))
      tmp.push_back(tolower(string[i]));
    else
      tmp.push_back(toupper(string[i]));
  }
  return MyString(tmp);
}

char &MyString::operator[](const size_t ind) const {
  return string[ind];
}

int MyString::operator()(const char *str) {
  char *p_find = strstr(buf, s);
  if (nullptr == p_find)
    return -1;
  else
    return p_find - buf;
}

std::ostream &operator<<(std::ostream &os, MyString &str) {
  return os << str.string;
}

std::istream &operator>>(std::istream &is, MyString &str) {
  return is >> str.string;
}
