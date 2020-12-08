// Copyright by Stanislav on 07/12/2020.

#include <tuple>
#include "../include/MyString.h"

MyString::MyString(const char *characters) : characters{nullptr}, size{0} {
  if (characters != nullptr) {
    this->characters = new char[std::strlen(characters) + 1];
    std::strncpy(this->characters, characters, size);
  } else {
    this->characters = new char[1];
    memset(this->characters, 0, 1);
  }
}

MyString::MyString(const std::string &string) : characters{nullptr}, size{0}{
  this->characters = new char[string.length() + 1];
  std::strncpy(this->characters, string.c_str(), size);
}

MyString::MyString(const MyString &string) : characters{nullptr}, size{0}{
  this->characters = new char[string.length() + 1];
  std::strncpy(this->characters, string.characters, size);
}

MyString::MyString(MyString &&string) noexcept : characters{nullptr}, size{0} {
  this->characters = new char[string.length() + 1];
  std::strncpy(this->characters, string.characters, size);
  this->~MyString();
}

MyString::~MyString() {
  free(this->characters);
  this->size = 0;
}

size_t MyString::length() const {
  return strlen(this->get());
}

char *MyString::get() const {
  return this->characters;
}

MyString MyString::operator+(const MyString &string) const {
  std::string temp(this->get());
  temp.append(string.get());
  return MyString(temp);
}

MyString MyString::operator-(const MyString &string) const {
  std::string temp(this->get());
  for (char c : std::string(string.get()))
    while (temp.find(c) != -1)
      temp.erase(temp.find(c), 1);
  return MyString(temp);
}

MyString MyString::operator*(size_t factor) const {
  std::string result;
  for (size_t i = 0; i < factor; ++i) result.append(this->get());
  return MyString(result);
}

MyString &MyString::operator=(const MyString &string) {
  if (&string != this) {
    delete this->characters;
    this->characters = strdup(string.get());
    this->size = string.size;
  }
  return *this;
}

MyString &MyString::operator=(MyString &&string) noexcept {
  delete this->characters;
  this->characters = string.get();
  this->size = string.size;
  string.characters = nullptr;
  string.size = 0;
  return *this;
}

bool MyString::operator==(const MyString &string) const {
  return std::tie(characters, size) == std::tie(string.characters, string.size);
}

bool MyString::operator!=(const MyString &string) const {
  return !(string == *this);
}

bool MyString::operator>(const MyString &string) const {
  return 1 == strcmp(this->get(), string.get());
}

bool MyString::operator<(const MyString &string) const {
  return -1 == strcmp(this->get(), string.get());
}

bool MyString::operator>=(const MyString &string) const {
  return -1 != strcmp(this->get(), string.get());
}

bool MyString::operator<=(const MyString &string) const {
  return 1 != strcmp(this->get(), string.get());
}

MyString MyString::operator!() {
  for (int i = 0; i < this->length(); i++)
    if (std::isupper(this->characters[i]))
      this->characters[i] = std::tolower(this->characters[i]);
    else
      this->characters[i] = std::toupper(this->characters[i]);
  return *this;
}

char &MyString::operator[](size_t index) {
  if (index <= this->size)
    return this->characters[index];
  else
    throw std::out_of_range("IndexOutOfBoundsException");
}

int32_t MyString::operator()(const char *string) const {
  return strstr(this->get(), string) != nullptr
         ? strstr(this->get(), string) - this->get()
         : -1;
}

std::istream &operator>>(std::istream &in, MyString &string) {
  return in >> string.get();
}

std::ostream &operator<<(std::ostream &out, MyString &string) {
  return out << string.get();
}
