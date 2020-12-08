// Copyright 2020 Konina Tatiana
#include "MyString.h"
MyString::MyString() {
  this->str = new char[1];
  memset(this->str, 0, 1);
}

MyString::MyString(const char*str = nullptr) {
  if (str == nullptr) {
    this->str = new char[1];
    memset(this->str, 0, 1);
  } else {
    this->str = new char[strlen(str) + 1];
    memcpy(this->str, str, strlen(str) + 1);
  }
}

MyString::MyString(std::string str) {
  this->str = new char[str.length() + 1];
  memcpy(this->str, str.c_str(), str.length() + 1);
}

MyString::MyString(const MyString&obj) {
  this->str = new char[obj.length() + 1];
  memcpy(this->str, obj.get(), obj.length() + 1);
}

MyString::~MyString() {
  delete this->str;
}

MyString::MyString(MyString&&obj) {
  this->str = obj.get();
  obj.str = nullptr;
}

char* MyString::get() const {
  return this->str;
}

size_t MyString::length() const {
  return strlen(this->str);
}

MyString MyString::operator+(const MyString& obj) {
  return MyString(std::string(this->get()) + std::string(obj.get()));
}

MyString MyString::operator-(const MyString& obj) {
  int n = 0, pointer;
  std::string tmp(this->get());
  for (int n = 0; n < obj.length(); n++) {
    if (pointer = tmp.find(obj[n])) {
      tmp.erase(pointer, 1);
    }
  }
  return MyString(tmp);
}

MyString MyString::operator*(size_t count) {
  std::string tmp;
  for (size_t i = 0; i < count; i++) {
  tmp+=this->get();
  }
  return MyString(tmp);
}

MyString& MyString::operator=(const MyString& obj) {
  if (this->str != nullptr) {
    delete this->str;
  }
  this->str = new char[obj.length() + 1];
  memcpy(this->str, obj.get(), obj.length() + 1);
  return *this;
}

MyString& MyString::operator=(MyString&& obj) {
  if (this->str != nullptr) {
    delete this->str;
  }
  this->str = obj.get();
  obj.str = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& obj) const {
  return !strcmp(this->get(), obj.get());
}

bool MyString::operator!=(const MyString& obj) const {
  return strcmp(this->get(), obj.get());
}

bool MyString::operator>(const MyString& obj) const {
  return (strcmp(this->get(), obj.get()) == 1);
}

bool MyString::operator<(const MyString& obj) const {
  return (strcmp(this->get(), obj.get()) == -1);
}

bool MyString::operator>=(const MyString& obj) const {
  return (strcmp(this->get(), obj.get()) > 1);
}

bool MyString::operator<=(const MyString& obj) const {
  return (strcmp(this->get(), obj.get()) < 1);
}

MyString MyString::operator!() {
  for (int i = 0; i < this->length(); i++) {
    this->str[i] = std::isupper(this->str[i]) ?
    std::tolower(this->str[i]) : std::toupper(this->str[i]);
  }
  return *this;
}

char& MyString::operator[](size_t index) const {
  if (index > this->length()) {
  throw "OUT OF RANGE";
  }
  return this->str[index];
}

int MyString::operator()(const char* another_str) {
  char* str_res = strstr(this->get(), another_str);
  return str_res == nullptr ? -1 : str_res - this->get();
}

std::ostream& operator<<(std::ostream& stream, MyString& obj) {
  stream << obj.get();
  return stream << obj.get();
}

std::istream& operator>>(std::istream& stream, MyString& obj) {
  return stream >> obj.get();
}


