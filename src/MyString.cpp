// Copyright NikDemoShow 2020
#include "MyString.h"

MyString::MyString(const char* new_str) {
  if (new_str != nullptr) {
  len = strlen(new_str);
  str = new char[len + 1];
  strcpy_s(str, len + 1, new_str);
  } else {
  str = nullptr;
  len = 0;
  }
}

MyString::MyString(std::string new_str) {
  len = new_str.size();
  str = new char[len + 1];
  strcpy_s(str, len + 1, new_str.c_str());
}

MyString::MyString(const MyString& new_str) {
  len = new_str.len;
  str = new char[len + 1];
  strcpy_s(str, len + 1, new_str.str);
}

MyString::MyString(MyString&& new_str) {
  str = new_str.str;
  len = new_str.len;
  new_str.str = nullptr;
  new_str.len = 0;
}

MyString::~MyString() {
  delete[] str;
}

size_t MyString::length() const {
  return len;
}

char* MyString::get() const {
  return str;
}

MyString MyString::operator+(const MyString& s_1) {
  size_t sum_len = len + s_1.length();
  char* sum_str = new char[sum_len + 1];
  strcpy_s(sum_str, len + 1, str);
  strcpy_s(sum_str + len, s_1.length() + 1, s_1.get());
  return MyString(sum_str);
}

MyString MyString::operator-(const MyString& s_1) {
  std::string new_str = std::string(str, str + len);
  for (size_t i{ 0 }; i < s_1.length(); ++i) {
  new_str.erase(std::remove(new_str.begin(), new_str.end(), s_1.get()[i]),
  new_str.end());
  }
  return MyString(new_str);
}

MyString MyString::operator*(const size_t mult) {
  MyString st(*this);
  for (size_t i{ 0 }; i < mult - 1; ++i) {
  st = *this + st;
  }
  return st;
}

MyString& MyString::operator=(const MyString& s_1) {
  len = s_1.length();
  str = new char[len + 1];
  strcpy_s(str, len + 1, s_1.get());
  return *this;
}

MyString& MyString::operator=(MyString&& s_1) {
  len = s_1.len;
  str = s_1.str;
  s_1.len = 0;
  s_1.str = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& s_1) {
  return !strcmp(str, s_1.get());
}

bool MyString::operator!=(const MyString& s_1) {
  return strcmp(str, s_1.get());
}

bool MyString::operator>(const MyString& s_1) {
  return (1 == strcmp(str, s_1.get()));
}

bool MyString::operator<(const MyString& s_1) {
  return (-1 == strcmp(str, s_1.get()));
}

bool MyString::operator>=(const MyString& s_1) {
  return (-1 != strcmp(str, s_1.get()));
}

bool MyString::operator<=(const MyString& s) {
  return (1 != strcmp(str, s.get()));
}

MyString MyString::operator!() {
  char* new_str = new char[len + 1];
  strcpy_s(new_str, len + 1, str);
  for (size_t i = 0; i < len; i++) {
  if (new_str[i] >= 'a' && new_str[i] <= 'z')
  new_str[i] += 'A' - 'a';
  else if (new_str[i] >= 'A' && new_str[i] <= 'Z')
  new_str[i] += 'a' - 'A';
  }
  return MyString(new_str);
}

char& MyString::operator[](const size_t i) {
  return str[i];
}

int MyString::operator()(const char* s_1) {
  char* find = strstr(str, s_1);
  if (nullptr == find)
  return -1;
  else
  return find - str;
}

std::istream& operator>>(std::istream& stream, MyString s) {
  return stream >> s.get();
}

std::ostream& operator<<(std::ostream& stream, MyString s) {
  return stream << s.get();
}
