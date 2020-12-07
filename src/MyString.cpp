// Copyright 2020 VadMack

#include <MyString.h>
#include <cstring>

MyString::MyString(const char *str) {
  if (str != nullptr) {
    char *newStr = new char[strlen(str)];
    for (int i = 0; i < strlen(str); ++i) {
      newStr[i] = str[i];
    }
    this->str = newStr;
  } else {
    char *newStr = new char[0];
    this->str = newStr;
  }
}

MyString::MyString(std::string str) {
  char *newStr = new char[str.length()];
  for (int i = 0; i < str.length(); ++i) {
    newStr[i] = str[i];
  }
  this->str = newStr;
}

MyString::MyString(const MyString &originalStr) {
  str = originalStr.str;
}

MyString::MyString(MyString &&) {
}

char *MyString::get() {
  return str;
}

int MyString::length() {
  return strlen(this->str);
}

MyString MyString::operator+(MyString addStr) {
  char *newStr = new char[this->length() + addStr.length()];
  snprintf(newStr, this->length() + 1, "%s", this->str);
  snprintf(newStr + this->length(), this->length() + 1, "%s", addStr.str);

  MyString newMyStr(newStr);
  return newMyStr;
}

MyString MyString::operator-(MyString minStr) {
  char *newStr = new char[this->length()];
  int index = 0;
  for (int i = 0; i < this->length(); ++i) {
    bool found = false;
    for (int j = 0; j < minStr.length(); ++j) {
      if (minStr.str[j] == this->str[i]) {
        found = true;
      }
    }
    if (!found) {
      newStr[index] = this->str[i];
      index++;
    }
  }
  MyString newMyStr(newStr);
  return newMyStr;
}

MyString &MyString::operator=(const MyString &otherStr) {
  this->str = otherStr.str;
  return *this;
}

MyString MyString::operator*(int n) {
  char *newStr = new char[this->length() * n];
  int index = 0;
  for (int i = 0; i < this->length() * n; ++i) {
    newStr[i] = this->str[index];
    index++;
    if (index == this->length()) {
      index = 0;
    }
  }
  MyString newMyStr(newStr);
  return newMyStr;
}

int MyString::operator==(const MyString &otherStr) {
  int isEq = strcmp(this->str, otherStr.str);
  return !isEq;
}

int MyString::operator!=(const MyString &otherStr) {
  int isEq = strcmp(this->str, otherStr.str);
  return !isEq;
}
