// Copyright by Stanislav on 07/12/2020.

#include "../include/MyString.h"

MyString::MyString(const char *characters) {
  this->len = strlen(characters);
  this->inner = strdup(characters);
}

MyString::MyString(const std::string &string) {
  this->len = string.length();
  this->inner = strdup(string.c_str());
}

MyString::MyString(const MyString &string) {
  this->len = string.len;
  this->inner = strdup(string.inner);
}

MyString::MyString(MyString &&string) {
  this->len = string.len;
  this->inner = strdup(string.inner);
}

MyString::~MyString() {
  free(this->inner);
}

size_t MyString::length() const {
  return this->len;
}

char *MyString::get() {
  return this->inner;
}

MyString MyString::operator+(MyString &string) {
  return MyString(nullptr);
}

MyString MyString::operator-(MyString &string) {
  return MyString(nullptr);
}

MyString MyString::operator*(size_t factor) {
  return MyString(nullptr);
}

MyString MyString::operator=(MyString &string) {
  return MyString(nullptr);
}

MyString MyString::operator=(MyString &&string) {
  return MyString(nullptr);
}

bool MyString::operator==(const MyString &string) {
  return false;
}

bool MyString::operator!=(const MyString &string) {
  return false;
}

bool MyString::operator>(const MyString &string) {
  return false;
}

bool MyString::operator<(const MyString &string) {
  return false;
}

bool MyString::operator>=(const MyString &string) {
  return false;
}

bool MyString::operator<=(const MyString &string) {
  return false;
}

MyString MyString::operator!() {
  return MyString(nullptr);
}

char MyString::operator[](size_t index) {
  return 0;
}

int32_t MyString::operator()(const char *string) {
  return 0;
}

std::istream &operator>>(std::istream &in, MyString &string) {
  return <#initializer#>;
}

std::ostream &operator<<(std::ostream &out, MyString &string) {
  return <#initializer#>;
}
