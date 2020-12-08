// Copyright 2020 jswark
#include "MyString.h"

MyString::MyString(const char* str) {
  if (str != nullptr) {
    size_t len = std::strlen(str) + 1;
    this->m_Str = new char[len];
    std::strncpy(this->m_Str, str, len);
  } else {
    this->m_Str = new char[1];
    memset(this->m_Str, 0, 1);
  }
}

MyString::MyString(const std::string& str) {
  size_t len = str.length() + 1;
  this->m_Str = new char[len];
  std::strncpy(this->m_Str, str.c_str(), len);
}

MyString::MyString(const MyString& new_str) {
  size_t len = new_str.length() + 1;
  this->m_Str = new char[len];
  std::strncpy(this->m_Str, new_str.m_Str, len);
}

MyString::MyString(MyString&& str) {
  size_t len = str.length() + 1;
  this-> m_Str = new char[len];
  std::strncpy(this->m_Str, str.m_Str, len);
}

MyString::~MyString() {
  delete this->m_Str;
}

size_t MyString::length() const {
  return strlen(this->m_Str);
}

char* MyString::get() const {
  return this->m_Str;
}

MyString MyString::operator+(const MyString& new_str) const {
  size_t len1 = new_str.length();
  size_t len2 = this->length();
  char* tmp_str = new char[len1 + len2 + 1];
  strncat(tmp_str, this->m_Str, len2);
  strncat(tmp_str, new_str.m_Str, len1);

  return MyString(tmp_str);
}

MyString MyString::operator-(const MyString& new_str) const {
  std::string tmp(this->get());
  size_t len = new_str.length();
  for (size_t i = 0; i < len; ++i) {
    while (tmp.find(new_str.m_Str[i]) != -1)
      tmp.erase(tmp.find(new_str.m_Str[i]), 1);
  }

  return MyString(tmp);
}

MyString MyString::operator*(int k) const {
  std::string tmp;
  for (unsigned int i = 0; i < k; ++i)
    tmp.append(this->m_Str);

  return MyString(tmp);
}

MyString& MyString::operator=(const MyString& new_str) {
    delete(this->m_Str);
    size_t len = new_str.length() + 1;
    char* tmp = new char[len];
    std::strncpy(tmp, new_str.get(), len);

    return *this;
}

MyString& MyString::operator=(MyString&& new_str) {
  delete(this->m_Str);
  this->m_Str = new_str.get();
  new_str.m_Str = nullptr;

  return *this;
}

bool MyString::operator==(const MyString& str) const {
  return !(strcmp(this->m_Str, str.get()));
}

bool MyString::operator!=(const MyString& str) const {
  return (strcmp(this->m_Str, str.get()));
}

bool MyString::operator>(const MyString& str) const {
  return (strcmp(this->m_Str, str.get()) > 0);
}

bool MyString::operator<(const MyString& str) const {
  return (strcmp(this->m_Str, str.get()) < 0);
}

bool MyString::operator>=(const MyString& str) const {
  return (strcmp(this->m_Str, str.get()) >= 0);
}

bool MyString::operator<=(const MyString& str) const {
  return (strcmp(this->m_Str, str.get()) <= 0);
}

MyString& MyString::operator!() {
  unsigned int i = 0;
  while (i != this->length()) {
    this->m_Str[i] = static_cast<char>(toupper(this->m_Str[i]));
    i++;
  }

  return *this;
}

char MyString::operator[](int i) const {
  return this->m_Str[i];
}

int MyString::operator()(const char* str) {
  std::string tmp = this->m_Str;

  return tmp.find(str);
}

std::ostream &operator>>(std::ostream& os, MyString& new_str) {
  return os << new_str.get();
}

std::istream &operator>>(std::istream& is, MyString& new_str) {
  return is >> new_str.get();
}
