#include "MyString.h"

#include <string.h>

#include <iostream>
#include <string>

MyString::MyString(const char* raw_str) {
  if (!raw_str) {
    this->len = 0;
    char* raw_str = reinterpret_cast<char*>(calloc(1, sizeof(char)));
    if (!raw_str) exit(1);
    this->inner = raw_str;
  } else {
    this->len = strlen(raw_str);
    this->inner = strdup(raw_str);
  }
}

MyString::MyString(const std::string std_str) {
  this->len = std_str.length();
  this->inner = strdup(std_str.c_str());
}

MyString::MyString(const MyString& other) {
  this->len = other.len;
  this->inner = strdup(other.inner);
}

MyString::MyString(MyString&& other) {
  this->len = other.len;
  this->inner = strdup(other.inner);
}

MyString::~MyString() { free(this->inner); }

size_t MyString::length() { return this->len; }

char* MyString::get() { return this->inner; }

MyString MyString::operator+(const MyString& other) {
  char* raw_str =
      reinterpret_cast<char*>(calloc(this->len + other.len + 1, sizeof(char)));
  if (!raw_str) exit(1);
  strcat(raw_str, this->inner);
  strcat(raw_str + this->len, other.inner);
  MyString new_str = MyString(raw_str);
  free(raw_str);
  return new_str;
}

MyString MyString::operator-(const MyString& other) {
  char* raw_str = reinterpret_cast<char*>(calloc(this->len + 1, sizeof(char)));
  if (!raw_str) exit(1);
  size_t k = 0;
  bool found = false;
  for (size_t i = 0; i < this->len; ++i) {
    found = false;
    for (size_t j = 0; j < other.len; ++j) {
      if (other.inner[j] == this->inner[i]) {
        found = true;
        break;
      }
    }
    if (!found) {
      raw_str[k] = this->inner[i];
      k += 1;
    }
  }
  MyString new_str = MyString(raw_str);
  free(raw_str);
  return new_str;
}

MyString MyString::operator*(size_t times) {
  char* raw_str =
      reinterpret_cast<char*>(calloc(this->len * times + 1, sizeof(char)));
  if (!raw_str) exit(1);
  for (size_t i = 0; i < times; ++i) {
    strcpy(raw_str + this->len * i, this->inner);
  }
  MyString new_str = MyString(raw_str);
  free(raw_str);
  return new_str;
}

MyString& MyString::operator=(const MyString& other) {
  this->len = other.len;
  this->inner = strdup(other.inner);
  return *this;
}
MyString& MyString::operator=(MyString&& other) {
  this->len = other.len;
  this->inner = strdup(other.inner);
  return *this;
}
bool MyString::operator==(const MyString& other) {
  int x = strcmp(this->inner, other.inner);
  return x == 0;
}
bool MyString::operator!=(const MyString& other) { return !(*this == other); }
bool MyString::operator>(const MyString& other) {
  return strcmp(this->inner, other.inner) > 0;
}
bool MyString::operator<(const MyString& other) {
  return strcmp(this->inner, other.inner) < 0;
}
bool MyString::operator>=(const MyString& other) {
  return strcmp(this->inner, other.inner) >= 0;
}
bool MyString::operator<=(const MyString& other) {
  return strcmp(this->inner, other.inner) <= 0;
}
MyString MyString::operator!() {
  MyString copy(*this);
  for (size_t i = 0; i < copy.len; ++i) {
    if (copy.inner[i] >= 'a' && copy.inner[i] <= 'z') {
      copy.inner[i] -= 'a' - 'A';
    } else if (copy.inner[i] >= 'A' && copy.inner[i] <= 'Z') {
      copy.inner[i] += 'a' - 'A';
    }
  }
  return copy;
}
char MyString::operator[](size_t i) { return this->inner[i]; }
int32_t MyString::operator()(const char* other) {
  char* ptr = strstr(this->inner, other);
  return ptr != NULL ? ptr - this->inner : -1;
}
std::istream& operator>>(std::istream& other, MyString& str) {
  return other >> str.get();
}
std::ostream& operator<<(std::ostream& other, MyString& str) {
  return other << str.get();
}
