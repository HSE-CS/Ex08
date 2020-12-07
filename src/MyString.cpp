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