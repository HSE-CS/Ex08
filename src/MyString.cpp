// Copyright 2020 mkhorosh
#include "MyString.h"
#include <string>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>

MyString::MyString(const char *nstring) { // pointer
  if (nstring != nullptr) {
    this->string = new char[1 + strlen(nstring)];
    strncpy(this->string, nstring, 1 + strlen(nstring));
  } else {
    this->string = new char[1];
    memset(this->string, 0, 1);
  }
}

MyString::MyString(const std::string &nstring) { // string
  this->string = new char[1 + nstring.length()];
  strncpy(this->string, nstring.c_str(), 1 + nstring.length());
}

MyString::MyString(const MyString &nstring) { // copy
  int size = nstring.length();
  this->string = new char[1 + size];
  strncpy(this->string, nstring.string, 1 + size);
}

MyString::MyString(MyString &&nstring) { // moving(r-value)
  this->string = new char[1 + nstring.length()];
  strncpy(this->string, nstring.string, 1 + nstring.length());
}

MyString::~MyString() { // destruct
  delete this->string;
}

int MyString::length() const { // string length
  return strlen(this->string);
}

char *MyString::get() const { // get pointer
  return this->string;
}

MyString MyString::operator+(const MyString &str) const { // concatenation
  MyString ans(std::string(this->get()) + std::string(str.get()));
  return ans;
}

MyString MyString::operator-(const MyString &str) const {
  std::string first = this->string;
  std::string second = str.string;
  for (int i = 0; i < second.length(); i++) {
    first.erase(std::remove(first.begin(), first.end(), second[i]), first.end());
  }
  MyString anstr(first);
  return anstr;
}

MyString MyString::operator*(int n) const {
  std::string ans;
  for (int i = 0; i < n; i++) {
    ans.append(this->get());
  }
  MyString anstr(ans);
  return anstr;
}

MyString &MyString::operator=(const MyString &str) { // копирующее присваивание
  delete this->string;
  this->string = new char[str.length() + 1];
  strncpy(this->string, str.get(), str.length() + 1);
  return *this;
}

MyString &MyString::operator=(MyString &&str) { // перемещающее присваивание
  delete this->string;
  this->string = str.get();
  str.string = nullptr;
  return *this;
}

bool MyString::operator==(const MyString &str) const { // сравнение на равенство
  return !strcmp(this->get(), str.get());
}

bool MyString::operator!=(const MyString &str) const { // сравнение на неравенство
  return strcmp(this->get(), str.get());
}

bool MyString::operator>(const MyString &str) const { // лексографическое сравнение
  return strcmp(this->get(), str.get()) == 1;
}

bool MyString::operator<(const MyString &str) const { // лексографическое сравнение
  return strcmp(this->get(), str.get()) == -1;
}

bool MyString::operator>=(const MyString &str) const { // лексографическое сравнение
  return strcmp(this->get(), str.get()) >= 0;
}

bool MyString::operator<=(const MyString &str) const { // лексографическое сравнение
  return strcmp(this->get(), str.get()) < 1;
}

MyString &MyString::operator!() { // у латинских букв меняется регистр
  for (int i = 0; i < (this->length()); i++) {
    if (this->string[i] == std::isupper(this->string[i])) {
      this->string[i] = std::tolower(this->string[i]);
    } else {
      this->string[i] = std::toupper(this->string[i]);
    }
  }
  return *this;
}

char MyString::operator[](int i) const { // доступ к символу по индексу
  return this->string[i];
}

int MyString::operator()(const char *ss) { // поиск подстроки
  std::string s1 = this->string;
  std::string s2 = ss;
  return s1.find(s2);
}

std::ostream &operator<<(std::ostream &stream, MyString &str) { // запись в поток
  return stream << str.get();
}

std::istream &operator>>(std::istream &stream, MyString &str) { // чтение из потока
  return stream >> str.get();
}
