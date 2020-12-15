// Copyright 2020 Dumarevsaya
#include "MyString.h"

MyString::MyString(const char* _str) {
  if (_str == nullptr) {
    str = new char[1];
  } else {
    len = strlen(_str);
    str = new char[len + 1];
    snprintf(str, len + 1, "%s", _str);
  }
}

MyString::MyString(std::string _str) {
  len = _str.length();
  str = new char[len + 1];
  snprintf(str, len + 1, "%s", _str.c_str());
}

MyString::MyString(const MyString& other_str) {
  len = strlen(other_str.str);
  str = new char[len + 1];
  snprintf(str, len + 1, "%s", other_str.str);
}

MyString::MyString(MyString&& other_str) {
  len = other_str.len;
  str = other_str.str;
  other_str.str = nullptr;
}

MyString::~MyString() {
  delete[] str;
  len = 0;
}

size_t MyString::length() {
  return len;
}

char* MyString::get() {
  return str;
}

MyString MyString::operator+(const MyString& other_str) {
  MyString new_str;
  new_str.len = len + other_str.len;
  new_str.str = new char[new_str.len + 1];
  size_t i = 0;
  for (; i < len; i++) {
    new_str.str[i] = str[i];
  }
  for (size_t j = 0; j < other_str.len; j++, i++) {
    new_str.str[i] = other_str.str[j];
  }
  new_str.str[new_str.len] = '\0';
  return new_str;
}

MyString MyString::operator-(const MyString& other_str) {
  MyString new_str;
  new_str.str = new char[len + 1];
  size_t i = 0, j = 0;
  while (i <= len) {
    char letter = str[i];
    bool f = 1;
    if (strchr(other_str.str, letter)) {
      f = 0;
    }
    if (f) {
       new_str.str[j] = letter;
       j++;
    }
    i++;
  }
  new_str.str[j] = '\0';
  return new_str;
}

MyString MyString::operator*(const size_t n) {
  std::string new_str;
  for (unsigned int i = 0; i < n; i++)
    new_str.append(str);
  return MyString(new_str);
}

MyString& MyString::operator=(const MyString& other_str) {
  if (str != nullptr) {
    delete[] str;
  }
  len = other_str.len;
  str = new char[len + 1];
  for (size_t i = 0; i < len; i++) {
    this->str[i] = other_str.str[i];
  }
  str[len] = '\0';
  return *this;
}

MyString& MyString::operator=(MyString&& other_str) {
  if (str != nullptr) {
    delete[] str;
  }
  len = other_str.len;
  str = other_str.str;
  other_str.str = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& other_str) {
  return !(strcmp(str, other_str.str));
}

bool MyString::operator!=(const MyString& other_str) {
  return (strcmp(str, other_str.str));
}

bool MyString::operator>(const MyString& other_str) {
  return (strcmp(str, other_str.str) > 0);
}

bool MyString::operator<(const MyString& other_str) {
  return (strcmp(str, other_str.str) < 0);
}

bool MyString::operator>=(const MyString& other_str) {
  return (strcmp(str, other_str.str) >= 0);
}

bool MyString::operator<=(const MyString& other_str) {
  return (strcmp(str, other_str.str) <= 0);
}

MyString MyString::operator!() {
  for (size_t i = 0; i < len; i++)
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
  return *this;
}

char MyString::operator[](const size_t index) {
  if (index >= len) throw "index out of range";
  return str[index];
}

int MyString::operator()(const char* _str) {
  std::string s = str;
  return s.find(_str);
}

std::ostream& operator<<(std::ostream& out, MyString& _str) {
  return out << _str.str;
}

std::istream& operator>>(std::istream& in, MyString& _str) {
  return in >> _str.str;
}
