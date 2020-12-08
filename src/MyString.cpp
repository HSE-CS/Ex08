// Copyright 2020 Ozhiganova Polina
#include <cstring>
#include <algorithm>
#include "MyString.h"

MyString::MyString(const char *str) {
  if (str != nullptr) {
    size_t length = strlen(str) + 1;
    this->st = new char[length];
    strncpy(this->st, str, length);
  } else {
    this->st = new char[1];
    memset(this->st, 0, 1);
  }
}

MyString::MyString(const std::string &str) {
  size_t length = str.size() + 1;
  this->st = new char[length];
  char buf[length];
  strcpy(buf, str.c_str());
  strncpy(this->st, buf, length);
}

MyString::MyString(const MyString &new_str) {
  size_t length = new_str.length() + 1;
  this->st = new char[length];
  strncpy(this->st, new_str.get(), length);
}

MyString::MyString(MyString &&str) {
  this->st = str.st;
  str.st = nullptr;
}

MyString::~MyString() {
  delete[] this->st;
}

size_t MyString::length() const {
  return strlen(this->st);
}

char *MyString::get() const {
  return this->st;
}

MyString MyString::operator+(const MyString &new_str) {
  return MyString(std::string(this->get()) + std::string(new_str.get()));
}

MyString MyString::operator-(const MyString &new_str) {
  std::string s1 = std::string(this->st);
  std::string s2 = std::string(new_str.st);
  std::string result;
  for (auto ch:s2) {
    std::remove_copy(s1.begin(), s1.end(), std::back_inserter(result), ch);
    s1 = result;
    result = "";
  }
  return MyString(s1);
}

MyString MyString::operator*(size_t size) const {
  std::string result;
  for (unsigned int i = 0; i < size; ++i) {
    result.append(this->get());
  }
  return MyString(result);
}

MyString MyString::operator=(const MyString &new_str) {
  if (this->st != nullptr) {
    delete this->st;
  }
  size_t length = new_str.length() + 1;
  this->st = new char[length];
  strncpy(this->st, new_str.get(), length);
  return *this;
}

MyString MyString::operator=(MyString &&new_str) {
  if (this->st != nullptr) {
    delete this->st;
  }
  this->st = new_str.get();
  new_str.st = nullptr;
  return *this;
}

bool MyString::operator==(const MyString &new_str) const {
  return !strcmp(this->get(), new_str.get());
}

bool MyString::operator!=(const MyString &new_str) const {
  return strcmp(this->get(), new_str.get());
}

bool MyString::operator>(const MyString &new_str) const {
  return strcmp(this->get(), new_str.get()) == 1;
}

bool MyString::operator<(const MyString &new_str) const {
  return -1 == strcmp(this->get(), new_str.get());
}

bool MyString::operator>=(const MyString &new_str) const {
  return strcmp(this->get(), new_str.get()) >= 0;
}

bool MyString::operator<=(const MyString &new_str) const {
  return strcmp(this->get(), new_str.get()) < 1;
}

MyString MyString::operator!() {
  for (int i = 0; i < (this->length()); i++) {
    if (this->st[i] == std::isupper(this->st[i])) {
      this->st[i] = std::tolower(this->st[i]);
    } else {
      this->st[i] = std::toupper(this->st[i]);
    }
  }
  return *this;
}

char &MyString::operator[](size_t ind) const {
  if (this->length() < ind) {
    throw "Out of range!";
  }
  return this->st[ind];
}

int MyString::operator()(char *new_str) {
  std::string s1 = std::string(this->st);
  std::string s2 = std::string(new_str);
  return s1.find(s2);
}

std::ostream & operator<<(std::ostream &stream, MyString &new_str) {
  stream << new_str.get();
  return stream << new_str.get();
}

std::istream & operator>>(std::istream &stream, MyString &new_str) {
  return stream >> new_str.get();
}