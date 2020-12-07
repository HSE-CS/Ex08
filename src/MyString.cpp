// Copyright 2020 Egor Trukhin
#include "MyString.h"

char* resolv(uint32_t size) {
  char* buffer = new char[size];
  memset(buffer, 0, size);
  return buffer;
}

MyString::MyString(const char* c_str) : array{nullptr}, size{0} {
  if (c_str == nullptr) {
    this->array = resolv(1);
    return;
  }
  this->size = strlen(c_str);
  this->array = resolv(this->size + 1);
  memcpy(this->array, c_str, this->size);
}

MyString::MyString(std::string cpp_str) : array{nullptr}, size{0} {
  this->size = cpp_str.length();
  this->array = resolv(this->size + 1);
  memcpy(this->array, cpp_str.c_str(), this->size);
}

MyString::MyString(const MyString& my_str) : array{nullptr}, size{0} {
  this->size = my_str.length();
  this->array = resolv(this->size + 1);
  memcpy(this->array, my_str.get(), this->size);
}

MyString::MyString(MyString&& my_str) : array{nullptr}, size{0} {
  this->size = my_str.length();
  this->array = my_str.get();
  my_str.size = 0;
  my_str.array = nullptr;
}

MyString::~MyString() { delete this->array; }
size_t MyString::length() const { return this->size; }
char* MyString::get() const { return this->array; }

MyString MyString::operator+(const MyString& my_str) {
  return MyString(std::string(this->get()) + std::string(my_str.get()));
}

MyString MyString::operator-(const MyString& my_str) {
  std::string res(this->get());
  for (size_t pos = 0; pos < my_str.length(); pos++)
    res.erase(std::remove(res.begin(), res.end(), my_str[pos]), res.end());
  return MyString(res);
}

MyString MyString::operator*(size_t count) {
  std::string result;
  for (size_t i = 0; i < count; i++) result.append(this->get());
  return MyString(result);
}

MyString& MyString::operator=(const MyString& my_str) {
  this->size = my_str.length();
  if (this->array != nullptr) delete this->array;
  this->array = resolv(this->size + 1);
  memcpy(this->array, my_str.get(), this->size);
  return *this;
}

MyString& MyString::operator=(MyString&& my_str) {
  this->size = my_str.length();
  if (this->array != nullptr) delete this->array;
  this->array = my_str.get();
  my_str.size = 0;
  my_str.array = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& my_str) {
  return !strcmp(this->get(), my_str.get());
}

bool MyString::operator!=(const MyString& my_str) {
  return strcmp(this->get(), my_str.get());
}

bool MyString::operator>(const MyString& my_str) {
  return (1 == strcmp(this->get(), my_str.get()));
}

bool MyString::operator<(const MyString& my_str) {
  return (-1 == strcmp(this->get(), my_str.get()));
}

bool MyString::operator>=(const MyString& my_str) {
  return (-1 != strcmp(this->get(), my_str.get()));
}

bool MyString::operator<=(const MyString& my_str) {
  return (1 != strcmp(this->get(), my_str.get()));
}

MyString MyString::operator!() {
  std::string result(this->get());
  for (size_t pos = 0; pos < result.length(); pos++) {
    char letter = result[pos];
    if ('a' <= letter && letter <= 'z')
      result[pos] -= 'a' - 'A';
    else if ('A' <= letter && letter <= 'Z')
      result[pos] += 'a' - 'A';
  }
  return MyString(result);
}

char& MyString::operator[](size_t index) const {
  if (index > this->size) throw "Index out of bounds!";
  return this->array[index];
}

int MyString::operator()(const char* substring) {
  char* ptr_substring = strstr(this->get(), substring);
  if (ptr_substring == nullptr) return -1;
  return ptr_substring - this->get();
}

std::ostream& operator<<(std::ostream& os, MyString& my_str) {
  return os << my_str.get();
}

std::istream& operator>>(std::istream& is, MyString& my_str) {
  return is >> my_str.get();
}
