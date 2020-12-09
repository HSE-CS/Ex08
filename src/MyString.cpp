// Copyright 2020 Ksuvot
#include "MyString.h"

MyString::MyString(const char *str) {
  if (str) {
    this->str = new char[strlen(str) + 1];
    snprintf(this->str, strlen(str) + 1, "%str", str);
  } else {
    this->str = new char[1];
    this->str[0] = '\0';
  }
}
MyString::MyString(std::string str) {
  this->str = new char[str.length() + 1];
  snprintf(this->str, str.length() + 1, "%str", str.c_str());
}
MyString::MyString(const MyString &str) {
  this->str = new char[str.length() + 1];
  snprintf(this->str, str.length() + 1, "%str", str.get());
}
MyString::MyString(MyString &&str) {
  str.str = this->str;
  this->str = nullptr;
}
MyString::~MyString() { delete[] str; }

int MyString::length() const { return strlen(str); }

char *MyString::get() const { return str; }

MyString MyString::operator+(const MyString &str) {
  char *string = new char[this->length() + str.length() + 1];
  snprintf(string, strlen(this->str) + 1, "%str", this->str);
  snprintf(string + this->length(), strlen(str.str) + 1, "%str", str.str);
  return MyString(string);
}
MyString MyString::operator-(const MyString &str) {
  char *string = new char[this->length() + str.length() + 1];
  int count = 0;
  for (int i = 0; i < this->length(); i++) {
    bool isName = false;
    for (int j = 0; j < str.length(); j++) {
      if (this->str[i] == str.str[j]) {
        isName = true;
        break;
      }
    }
    if (!isName) {
      string[count] = this->str[i];
      count++;
    }
  }
  string[count] = '\0';
  return MyString(string);
}

MyString MyString::operator*(int num) {
  char *string = new char(this->length() * num + 1);
  for (int i = 0; i < num; i++) {
    snprintf(string + i * this->length(), strlen(this->str) + 1, "%s", this->str);
  }
  return MyString(string);
}

MyString &MyString::operator=(const MyString &str) {
  this->str = new char[str.length() + 1];
  snprintf(this->str, strlen(str.str) + 1, "%str", str.str);
  return *this;
}

MyString &MyString::operator=(MyString &&str) {
  this->str = str.str;
  str.str = nullptr;
  return *this;
}

bool MyString::operator==(const MyString &str) {
  return !strcmp(this->str, str.str) ? true : false;
}

bool MyString::operator!=(const MyString &str) {
  return strcmp(this->str, str.str) ? true : false;
}

bool MyString::operator>(const MyString &str) { return strcmp(this->str, str.str) > 0; }

bool MyString::operator<(const MyString &str) { return strcmp(this->str, str.str) < 0; }

bool MyString::operator>=(const MyString &str) { return strcmp(this->str, str.str) >= 0; }

bool MyString::operator<=(const MyString &str) { return strcmp(this->str, str.str) <= 0; }

MyString MyString::operator!() {
  char *str = new char[this->length() + 1];
  snprintf(str, strlen(this->str) + 1, "%s", this->str);
  for (int i = 0; i < this->length(); i++) {
    if (str[i] >= 65 && str[i] <= 90) {
      str[i] = str[i] + 32;
      continue;
    }
    if (str[i] >= 97 && str[i] <= 122) {
      str[i] = str[i] - 32;
      continue;
    }
  }
  return MyString(str);
}

char &MyString::operator[](int index) { return str[index]; }

int MyString::operator()(const char *str) {
  int i = 0;
  while (i < this->length()) {
    int j = 0;
    while (this->str[i + j] == str[j] && i + j < this->length() && j < strlen(str)) {
      j++;
    }
    if (j == strlen(str)) {
      return i;
    }
    i++;
  }
  return -1;
}

std::ostream &operator<<(std::ostream &ostream, MyString &str) {
  return ostream << str.get();
}
std::istream &operator>>(std::istream &istream, MyString &str) {
  return istream >> str.get();
}
