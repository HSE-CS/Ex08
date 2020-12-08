// Copyright 2020 GHA Test Team
#include "MyString.h"
#include <string>
#include <cstring>
#include <iostream>


char* MyString::get() const {
  return my_string;
}

unsigned int MyString::length() const {
  return strlen(my_string);
}

MyString::MyString(const char* initial_string) {
  if (initial_string == nullptr) {
    char* new_str = new char[1];
    my_string = new_str;
  } else {
    unsigned int len = strlen(initial_string) + 1;
    char* new_str = new char[len];
    snprintf(new_str, len, "%s", initial_string);
    my_string = new_str;
  }
}

MyString::MyString(std::string initial_string) {
  unsigned int len = initial_string.length() + 1;
  my_string = new char[len];
  snprintf(my_string, len, "%s", initial_string.c_str());
}

MyString::MyString(const MyString& initial_string) {
  unsigned int str_len = initial_string.length() + 1;
  char* new_str = new char[str_len];
  snprintf(new_str, str_len, "%s", initial_string.get());
  my_string = new_str;
}

MyString::MyString(MyString&& initial_string) noexcept {
  my_string = initial_string.my_string;
  initial_string.my_string = nullptr;
}

MyString::~MyString() {
  delete[] my_string;
}


MyString& MyString::operator=(const MyString& second_string) {
  if (my_string != nullptr)
    delete[] my_string;
  unsigned int str_len = second_string.length() + 1;
  my_string = new char[str_len];
  snprintf(my_string, str_len, "%s", second_string.get());
  return *this;
}

MyString& MyString::operator=(MyString&& second_string) noexcept {
  if (my_string != nullptr)
    delete[] my_string;
  my_string = second_string.get();
  second_string.my_string = nullptr;
  return *this;
}

MyString MyString::operator+(const MyString& second_string) {
  unsigned int str_len1 = length();
  unsigned int str_len2 = second_string.length();
  char* new_str = new char[str_len1 + str_len2 + 1];
  snprintf(new_str, str_len1 + 1, "%s", my_string);
  snprintf(new_str + str_len1, str_len2 + 1, "%s", second_string.my_string);
  return MyString(new_str);
}

MyString MyString::operator-(const MyString& second_string) {
  unsigned int str_len1 = length();
  unsigned int new_str_len = 0;
  std::string str2 = second_string.get();
  char* new_str = new char[str_len1 + 1];
  for (unsigned int i = 0; i < str_len1; i++)
    if (!strchr(str2.c_str(), my_string[i]))
      new_str[new_str_len++] = my_string[i];
  new_str[new_str_len] = '\0';
  return MyString(new_str);
}

MyString MyString::operator*(unsigned int number) {
  std::string new_str;
  unsigned int len = length();
  for (unsigned int i = 0; i < len; i++)
    new_str.append(get());
  return MyString(new_str);
}

MyString& MyString::operator!() {
  unsigned int str_len = length();
  for (unsigned int i = 0; i < str_len; i++)
    if (my_string[i] >= 65 && my_string[i] <= 90)
      my_string[i] = my_string[i] + 32;
    else if (my_string[i] >= 97 && my_string[i] <= 122)
      my_string[i] = my_string[i] - 32;
  return *this;
}


bool MyString::operator==(const MyString& second_string) const {
  return !strcmp(my_string, second_string.get());
}

bool MyString::operator!=(const MyString& second_string) const {
  return strcmp(my_string, second_string.get());
}

bool MyString::operator>(const MyString& second_string) const {
  return strcmp(my_string, second_string.get()) > 0;
}

bool MyString::operator<(const MyString& second_string) const {
  return strcmp(my_string, second_string.get()) < 0;
}
bool MyString::operator>=(const MyString& second_string) const {
  return strcmp(my_string, second_string.get()) >= 0;
}

bool MyString::operator<=(const MyString& second_string) const {
  return strcmp(my_string, second_string.get()) <= 0;
}


char& MyString::operator[](unsigned int index) const {
  if (index >= length()) throw "Number out of range";
  return my_string[index];
}

int MyString::operator()(const char* target_string) {
  std::string str = get();
  return str.find(target_string);
}


std::ostream& operator<<(std::ostream& os, MyString& str) {
  return os << str.get();
}

std::istream& operator>>(std::istream& is, MyString& str) {
  unsigned int len = is.gcount() + 1;
  std::string new_str;
  std::getline(is, new_str);
  str = MyString(new_str);
  return is;
}
