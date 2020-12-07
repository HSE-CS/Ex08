// Copyright by Stanislav on 07/12/2020.

#include <tuple>
#include "../include/MyString.h"

MyString::MyString(const char *characters) {
  this->size = strlen(characters);
  this->characters = strdup(characters);
}

MyString::MyString(const std::string &string) {
  this->size = string.length();
  this->characters = strdup(string.c_str());
}

MyString::MyString(const MyString &string) {
  this->size = string.size;
  this->characters = strdup(string.characters);
}

MyString::MyString(MyString &&string) noexcept {
  this->size = string.size;
  this->characters = strdup(string.characters);
  this->~MyString();
}

MyString::~MyString() {
  free(this->characters);
  this->size = 0;
}

size_t MyString::length() const {
  return this->size;
}

char *MyString::get() {
  return this->characters;
}

bool MyString::operator==(const MyString &string) const {
  return std::tie(characters, size) == std::tie(string.characters, string.size);
}

bool MyString::operator!=(const MyString &string) const {
  return !(string == *this);
}
