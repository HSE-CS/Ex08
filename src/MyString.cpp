// Copyright 2020 Ryzhova
#include "MyString.h"

MyString::MyString(const char *string) {
  if (string == nullptr) {
    this->string = new char[1];
    memset(this->string, 0, 1);
  } else {
    this->string = new char[strlen(string) + 1];
    strncpy(this->string, string, strlen(string) + 1);
  }
}

MyString::MyString(std::string string) {
    this->string = new char[string.length() + 1];
    memcpy(this->string, string.c_str(), string.length() + 1);
}

MyString::MyString(const MyString& my_string) {
  string = new char[my_string.length() + 1];
  memcpy(string, my_string.get(), my_string.length() + 1);
}

MyString::MyString(MyString&& my_string) {
  string = my_string.string;
  my_string.string = nullptr;
}

MyString::~MyString() {
  delete string;
}

size_t MyString::length() const {
  return strlen(string);
}

char* MyString::get() const {
  return string;
}

MyString MyString::operator+(const MyString& my_string) {
  return MyString(std::string(get()) + std::string(my_string.get()));
}

MyString MyString::operator-(const MyString& my_string) {
  std::string tmp{get()};
  for (size_t i = 0; i < tmp.length(); i++) {
    for (size_t j = 0; j < my_string.length(); j++) {
      if (tmp[i] == my_string[j])
        tmp.erase(i, 1);
    }
  }
  return MyString(tmp);
}

MyString MyString::operator*(int count) {
  std::string tmp;
  for (int i = 0; i < count; i++) {
    tmp += get();
  }
  return MyString(tmp);
}

MyString MyString::operator=(const MyString& my_string) {
  if (string != nullptr) 
    delete string;
  string = new char[my_string.length() + 1];
  memcpy(string, my_string.get(), my_string.length() + 1);
  return *this;
}

MyString MyString::operator=(MyString&& my_string) {
  if (string != nullptr) {
    delete string;
  }
  string = my_string.get();
  my_string.string = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& my_string) {
  return !strcmp(string, my_string.get());
}

bool MyString::operator!=(const MyString& my_string) {
  return strcmp(string, my_string.get());
}

bool MyString::operator>(const MyString& my_string) {
  return strcmp(string, my_string.get()) == 1;
}

bool MyString::operator<(const MyString& my_string) {
  return strcmp(string, my_string.get()) == -1;
}

bool MyString::operator>=(const MyString& my_string) {
  return strcmp(string, my_string.get()) != -1;
}

bool MyString::operator<=(const MyString& my_string) {
  return strcmp(string, my_string.get()) != 1;
}

MyString MyString::operator!() {
  for (size_t i = 0; i < length(); i++) {
    if (string[i] == std::isupper(string[i]))
      string[i] = std::tolower(string[i]);
    else 
      string[i] = std::toupper(string[i]);
  }
  return *this;
}

char MyString::operator[](size_t index) const {
  if (length() < index || index < 0) {
    throw "you mixed something up...";
  }
  return string[index];
}

int MyString::operator()(const char *my_string) {
  return std::string(string).find(std::string(my_string));
}

std::ostream& operator<<(std::ostream& stream, MyString& my_string) {
  return stream << my_string.get();
}

std::istream& operator>>(std::istream& stream, MyString& my_string) {
  return stream >> my_string.get();
}
