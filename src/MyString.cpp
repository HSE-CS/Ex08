// Copyright 2020 Egor Buzanov

#include "../include/MyString.h"

MyString::MyString(const char *string_to_copy) {
  if (string_to_copy != nullptr) {
    len = strlen(string_to_copy);
    str = new char[len + 1];
    snprintf(str, len + 1, "%s", string_to_copy);
  } else {
    str = nullptr;
    len = 0;
  }
}

MyString::MyString(std::string string_to_copy) {
  len = string_to_copy.size();
  str = new char[len + 1];
  for (size_t num = 0; num < len; ++num) {
    str[num] = string_to_copy[num];
  }
  str[len] = '\0';
}

MyString::MyString(const MyString &class_to_copy) {
  len = class_to_copy.len;
  str = new char[len + 1];
  snprintf(str, len + 1, "%s", class_to_copy.str);
}

MyString::MyString(MyString &&class_to_replace) {
  str = class_to_replace.str;
  len = class_to_replace.len;
  class_to_replace.str = nullptr;
  class_to_replace.len = 0;
}

MyString::~MyString() {
  delete str;
  len = 0;
}

size_t MyString::length() const { return len; }

char *MyString::get() const { return str; }

MyString MyString::operator+(const MyString &second_string) {
  size_t new_len = len + second_string.length();
  char *new_str = new char[new_len + 1];
  snprintf(new_str, len, "%s", str);
  snprintf(new_str + len, second_string.length() + 1, "%s",
           second_string.get());
  return MyString(new_str);
}

MyString MyString::operator-(const MyString &string) {
  std::string new_str(str, str + len);
  for (size_t i = 0; i < string.len; i++) {
    new_str.erase(std::remove(new_str.begin(), new_str.end(), string[i]),
                  new_str.end());
  }
  return MyString(new_str);
}

MyString MyString::operator*(const size_t count) {
  std::string new_str;
  for (size_t i = 0; i < count; ++i) {
    new_str += std::string(str);
  }
  return MyString(new_str);
}

MyString &MyString::operator=(const MyString &string) {
  len = string.len;
  str = new char[len + 1];
  snprintf(str, len + 1, "%s", string.str);
  return *this;
}

MyString &MyString::operator=(MyString &&string) {
  len = string.len;
  str = string.str;
  string.str = nullptr;
  string.len = 0;
  return *this;
}

bool MyString::operator==(const MyString &string) {
  return (strcmp(str, string.str) == 0);
}

bool MyString::operator!=(const MyString &string) {
  return strcmp(str, string.str);
}

bool MyString::operator>(const MyString &string) {
  return (strcmp(str, string.str) > 0);
}

bool MyString::operator<(const MyString &string) {
  return (strcmp(str, string.str) < 0);
}

bool MyString::operator>=(const MyString &string) {
  return (strcmp(str, string.str) >= 0);
}

bool MyString::operator<=(const MyString &string) {
  return (strcmp(str, string.str) <= 0);
}

MyString MyString::operator!() {
  char *new_str = new char[len + 1];
  snprintf(new_str, len + 1, "%s", str);
  for (size_t i = 0; i < len; i++) {
    if (str[i] <= 'Z' && str[i] >= 'A') {
      new_str += 32;
    } else {
      if (str[i] <= 'z' && str[i] >= 'a') {
        new_str[i] -= 32;
      }
    }
  }
  return MyString(new_str);
}

char &MyString::operator[](const size_t index) const { return str[index]; }

int MyString::operator()(const char *string) {
  char *position = strstr(str, string);
  if (position == nullptr) {
    return -1;
  } else {
    return position - str;
  }
}

std::ostream &operator<<(std::ostream &out, MyString &string) {
  return out << string.get();
}

std::istream &operator>>(std::istream &in, MyString &string) {
  return in >> string.get();
}
