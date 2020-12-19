// Copyright 2020 DBarinov

#include "MyString.h"
MyString::MyString(const char* c_str) {
  if (c_str == nullptr)  {
    this->size = 0;
    this->array = new char[1];
    memset(this->array, 0, 1);
    return;
  }
  this->size = strlen(c_str);
  this->array = new char[this->size + 1];
  snprintf(this->array, this->size + 1, "%s", c_str);
}

MyString::MyString(std::string str) {
  this->size = str.length();
  this->array = new char[this->size + 1];
  snprintf(this->array, this->size + 1, "%s", str.c_str());
}

MyString::MyString(const MyString& str) {
  this->size = str.length();
  this->array = new char[this->size + 1];
  snprintf(this->array, this->size + 1, "%s", str.get());
}

MyString::MyString(MyString&& str) {
  this->size = str.size;
  this->array = str.array;
  str.array = nullptr;
  str.size = 0;
}

MyString::~MyString() {
  delete this->array;
}

size_t MyString::length() const {
  return this->size;
}

char* MyString::get() const {
  return this->array;
}

MyString MyString::operator+(const MyString& str) {
  std::string a(this->get());
  std::string b(str.get());
  return MyString(a + b);
}

MyString MyString::operator-(const MyString& str) {
  std::string result;
  std::string a(this->get());
  for (size_t i = 0; i < str.length(); i++) {
    while (a.find(str[i]) != std::string::npos) {
      a.erase(a.find(str[i]), 1);
    }
  }
  return MyString(a);
}

MyString MyString::operator*(size_t n) {
  std::string a;
  size_t i = 0;
  while (i < n) {
    a.append(this->get());
    i++;
  }
  return MyString(a);
}

MyString& MyString::operator=(const MyString& str) {
  if (this->array != nullptr) delete this->array;
  this->size =  str.length();
  this->array = new char[this->size + 1];
  snprintf(this->array, this->size + 1, "%s", str.get());
  return *this;
}

MyString& MyString::operator=(MyString&& str) {
  if (this->array != nullptr) delete this->array;
  this->size = str.length();
  this->array = str.get();
  str.array = nullptr;
  str.size = 0;
  return *this;
}

bool MyString::operator==(const MyString& str) {
  return (strcmp(this->get(), str.get()) == 0);
}

bool MyString::operator!=(const MyString& str) {
  return (strcmp(this->get(), str.get()) != 0);
}

bool MyString::operator>(const MyString& str) {
  return (strcmp(this->get(), str.get()) > 0);
}

bool MyString::operator>=(const MyString& str) {
  return (strcmp(this->get(), str.get()) >= 0);
}

bool MyString::operator<(const MyString& str) {
  return (strcmp(this->get(), str.get()) < 0);
}

bool MyString::operator<=(const MyString& str) {
  return (strcmp(this->get(), str.get()) <= 0);
}

MyString MyString::operator!() {
  std::string str(this->get());
  int length = str.length();
  for (int i = 0; i < length; i++) {
    int c = str[i];
    if (islower(c)) {
      str[i] = toupper(c);
    } else if (isupper(c)) {
      str[i] = tolower(c);
    }
  }
  return MyString(str);
}

char& MyString::operator[](const size_t ind) const {
  if (ind >= this->size) {
    throw "Index is wrong";
  }
  return this->array[ind];
}

int MyString::operator()(const char* str) {
  char* p_str = strstr(this->get(), str);
  if (p_str == nullptr) {
    return -1;
  }
  return p_str - this->get();
}

std::ostream& operator<<(std::ostream& os, MyString& str) {
  return os << str.get();
}

std::istream& operator>>(std::istream& is, MyString& str) {
  return is >> str.get();
}

