// Copyright 2020 GHA Test Team
#include <iostream>
#include "MyString.h"

MyString::MyString(const char *new_string) {
  if (new_string != nullptr) {
    string = new char[strlen(new_string) + 1];
    snprintf(string, strlen(new_string) + 1, "%s", new_string);
  } else {
    string = new char[1];
    memset(string, 0, 1);
  }
}

MyString::MyString(std::string new_string) {
  string = new char[new_string.size() + 1];
  snprintf(string, new_string.size() + 1, "%s", new_string.c_str());
}

MyString::MyString(const MyString &str) {
  string = new char[str.len + 1];
  snprintf(string, str.len + 1, "%s", str.string);
}

MyString::MyString(MyString &&str) {
  len = str.len;
  string = str.string;
  str.string = nullptr;
  str.len = 0;
}

MyString::~MyString() {
    len = 0;
    delete[] string;
}

size_t MyString::length() {
    return len;
}

char* MyString::get() {
    return string;
}

MyString MyString::operator+(const MyString &add_str) {
  std::string tmp;
  tmp.append(string);
  tmp.append(add_str.string);
  return MyString(tmp);
}

MyString MyString::operator-(const MyString& str) {
    std::string new_string;
    for (int i = 0; i <= strlen(string); i++) {
        bool check = true;
        for (int j = 0; j < strlen(str.string); j++) {
            if (string[i] == str.string[j])
                check = false;
        }
        if (check)
            new_string += string[i];
    }
    return MyString(new_string);
}

MyString MyString::operator*(size_t n) {
    std::string str;
    for (int i = 0; i < n; i++)
        str += get();
    return MyString(str);
}

MyString &MyString::operator=(const MyString &str) {
  string = str.string;
  len = str.len;
  return *this;
}

MyString &MyString::operator=(MyString &&str) {
  string = str.string;
  str.string = nullptr;
  len = str.len;
  str.len = 0;
  return *this;
}

bool MyString::operator==(const MyString &s) {
  return (strcmp(string, s.string) == 0 ? 1 : 0);
}

bool MyString::operator!=(const MyString &s) {
  return (strcmp(string, s.string) != 0 ? 1 : 0);
}

bool MyString::operator>(const MyString &s) {
  return (strcmp(string, s.string) <= 0 ? 0 : 1);
}

bool MyString::operator<(const MyString &s) {
  return (strcmp(string, s.string) >= 0 ? 0 : 1);
}

bool MyString::operator>=(const MyString &s) {
  return (strcmp(string, s.string) < 0 ? 0 : 1);
}

bool MyString::operator<=(const MyString &s) {
  return (strcmp(string, s.string) > 0 ? 0 : 1);
}

MyString MyString::operator!() {
    MyString result(*this);
    for (int i = 0; i < result.len; i++) {
        if ((result.string[i] >= 'a') && (result.string[i] <= 'z'))
            result.string[i] -= 'a' - 'A';
        else
            if ((result.string[i] >= 'A') && (result.string[i] <= 'Z'))
                result.string[i] += 'a' - 'A';
    }
    return result;
}

char& MyString::operator[](int i) {
    return string[i];
}

int MyString::operator()(const char* str) {
    char* pstr = strstr(get(), str);
    return (pstr != nullptr ? (pstr - get()) : -1);
}

std::istream &operator>>(std::istream &input, MyString &s) {
  return input >> s.get();
}

std::ostream &operator<<(std::ostream &output, MyString &s) {
  return output << s.get();
}
