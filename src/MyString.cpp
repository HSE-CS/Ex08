// Copyright 2020 GHA Test Team
#include "MyString.h"
#include <cctype>


MyString::MyString(const char* str) {
  if (str == nullptr) {
    string = new char[1];
    memset(string, 0, 1);
  } else {
    string = new char[strlen(str) + 1];
    memcpy(string, str, strlen(str) + 1);
  }
}

MyString::MyString(std::string str) {
  string = new char[str.length() + 1];
  memcpy(string, str.c_str(), str.length() + 1);
}

MyString::MyString(const MyString &str) {
  string = new char[strlen(str.string) + 1];
  snprintf(string, strlen(str.string) + 1, "%s", str.string);
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
  unsigned int my_len = strlen(string);
  unsigned int other_len = strlen(str.string);
  char* buf = new char[my_len + 1];
  unsigned int new_index = 0;
  for (unsigned int my_index = 0; my_index < my_len; my_index++) {
    bool is_consist = false;
    for (unsigned int other_index = 0; other_index < other_len; other_index++)
      if (string[my_index] == str.string[other_index]) {
        is_consist = true;
        break;
      }
    if (!is_consist) {
      buf[new_index++] = string[my_index];
    }
  }
    return MyString(buf);
}

MyString MyString::operator*(const size_t count) {
  MyString ans(string);
  for (int i = 0; i < count - 1; i++) {
    ans = ans + *this;
  }
  return ans;
}

MyString &MyString::operator=(const MyString &str) {
  string = new char[strlen(str.string) + 1];
  snprintf(string, strlen(str.string) + 1, "%s", str.string);
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
  unsigned int sub_index = 0;
  unsigned int len = strlen(string);
  for (int my_index = 0; my_index < len; my_index++) {
    if (string[my_index] == str[sub_index]) {
      sub_index += 1;
      if (sub_index >= strlen(str))
        return my_index - strlen(str) + 1;
    } else {
      sub_index = 0;
    }
  }
  return -1;
}

std::ostream &operator<<(std::ostream &os, MyString &str) {
  return os << str.string;
}

std::istream &operator>>(std::istream &is, MyString &str) {
  return is >> str.string;
}
