// Copyright 2020 Shelby Ltd.
#include "MyString.h"

MyString::MyString(const char *s) {
  if (s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
  } else {
    str = new char[1];
    str[0] = '\0';
  }
}
MyString::MyString(std::string &s) {
  str = new char[s.length() + 1];
  strcpy(str, s.c_str());
}
MyString::MyString(const MyString &s) {
  str = new char[s.length() + 1];
  strcpy(str, s.get());
}
MyString::MyString(MyString &&s) {
  s.str = str;
  str = nullptr;
}
MyString::~MyString() { delete[] str; }
int MyString::length() const { return strlen(str); }
char *MyString::get() const { return str; }
MyString MyString::operator+(const MyString &s) {
  char *string = new char[this->length() + s.length() + 1];
  strcpy(string, str);
  strcpy(string + this->length(), s.str);
  return MyString(string);
}
MyString MyString::operator-(const MyString &s) {
  char *string = new char[this->length() + s.length() + 1];
  int c = 0;
  for (int i = 0; i < this->length(); i++) {
    bool f = false;
    for (int j = 0; j < s.length(); j++) {
      if (str[i] == s.str[j]) {
        f = true;
        break;
      }
    }
    if (!f) {
      string[c] = str[i];
      c++;
    }
  }
  string[c] = '\0';
  return MyString(string);
}

MyString MyString::operator*(int n) {
  char *string = new char(this->length() * n + 1);
  for (int i = 0; i < n; i++) {
    strcpy(string + i * this->length(), str);
  }
  return MyString(string);
}

MyString &MyString::operator=(const MyString &s) {
  str = new char[s.length() + 1];
  strcpy(str, s.str);
  return *this;
}

MyString &MyString::operator=(MyString &&s) {
  str = s.str;
  s.str = nullptr;
  return *this;
}

bool MyString::operator==(const MyString &s) {
  return !strcmp(str, s.str) ? true : false;
}

bool MyString::operator!=(const MyString &s) {
  return strcmp(str, s.str) ? true : false;
}

bool MyString::operator>(const MyString &s) { return strcmp(str, s.str) > 0; }

bool MyString::operator<(const MyString &s) { return strcmp(str, s.str) < 0; }

bool MyString::operator>=(const MyString &s) { return strcmp(str, s.str) >= 0; }

bool MyString::operator<=(const MyString &s) { return strcmp(str, s.str) <= 0; }

MyString MyString::operator!() {
  char *string = new char[this->length() + 1];
  strcpy(string, str);
  for (int i = 0; i < this->length(); i++) {
    if (string[i] >= 65 && string[i] <= 90) {
      string[i] = string[i] + 32;
      continue;
    }
    if (string[i] >= 97 && string[i] <= 122) {
      string[i] = string[i] - 32;
      continue;
    }
  }
  return MyString(string);
}

char &MyString::operator[](int n) { return str[n]; }
int MyString::operator()(const char *s) {
  int i = 0;
  while (i < this->length()) {
    int j = 0;
    while (str[i + j] == s[j] && i + j < this->length() && j < strlen(s)) {
      j++;
    }
    if (j == strlen(s)) {
      return i;
    }
    i++;
  }
  return -1;
}

std::ostream &operator<<(std::ostream &st, MyString &s) {
  return st << s.get();
}
std::istream &operator>>(std::istream &st, MyString &s) {
  return st >> s.get();
}
