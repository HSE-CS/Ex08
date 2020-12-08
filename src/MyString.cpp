// Copyright 2020 GHA Test Team
#include "MyString.h"
#include <cstring>
#include <string>
#include <iostream>

MyString::MyString(const char* x) {
    if (x) {
      len = 0;
      str = nullptr;
    } else {
      len = strlen(x);
      str = new char[len+1];
      strcpy(str, x);
    }
}

MyString::MyString(std::string x ) {
    len = strlen(x.c_str());
    str = new char[len+1];
    strcpy(str, x.c_str());
}

MyString::MyString(const MyString& s) {
    len = s.len;
    str = new char[len+1];
    strcpy(str, s.str);    
}

MyString::MyString(MyString&& s) {
    len = s.len;
    str = s.str;
    s.str = nullptr;
    s.len = 0;
}

MyString::~MyString() {
    len = 0;
    delete[]str;
}

int MyString::length() const {
    return len;
}

const char* MyString::get() const {
    return str;
}

MyString MyString::operator+(const MyString& s) {
    unsigned l = len+s.len;
    char* buf = new char[l+1];
    strcpy(buf, this->str);
    strcat(buf, s.str);
    MyString ret(buf);
    delete[] buf;
    return ret;
}

MyString MyString::operator-(const MyString& s) {
    std::string res(this->get());
    size_t i = 0;
    while (i < s.length()) {
      while (res.find(s.str[i]) != -1) {
        res.erase(res.find(s.str[i]), 1);
      }
      i++;
    }
    return MyString(res);
}

MyString MyString::operator*(int x) {
    unsigned l = len*x;
    char* buf = new char[l+1];
    if (x > 0) {
    strcpy(buf, str);
    for (int i=0; i < x-1; ++i)
    strcat(buf, str);
    }
    MyString ret(buf);
    delete[] buf;
    return ret;
}

MyString& MyString::operator=(const MyString& s) {
    len = s.len;
    delete[] str;
    str = new char[len+1];
    strcpy(str, s.str);
    return *this;
}

MyString& MyString::operator=(MyString&& s) {
    len = s.len;
    delete[] str;
    str = new char[len+1];
    strcpy(str, s.str);
    s.len = 0;
    s.str = nullptr;
    return *this;
}

bool MyString::operator!=(const MyString& s) {
    if (strcmp(this->get, s.get()))
      return true;
    else
      return false;
}

bool MyString::operator==(const MyString& s) {
    return !(this != s);
}

bool MyString::operator>(const MyString& s) {
    if (strcmp(this->get, s.get()) > 0)
      return true;
    else
      return false;
}

bool MyString::operator<(const MyString& s) {
    if (strcmp(this->get, s.get()) < 0)
      return true;
    else
      return false;
}

bool MyString::operator>=(const MyString& s) {
    return ((this >  s) || (this == s));
}

bool MyString::operator<=(const MyString& s) {
    return ((this < s) || (this == s));
}

std::ostream& MyString::operator<<(std::ostream& os, MyString& s) {
    return os << s.str;
}

std::istream& MyString::operator>>(std::istream& is, MyString& s) {
    return is >> s.str;
}

char& MyString::operator[] (const int index) {
    return str[index];
}

const char*  MyString::operator()(const char* s) {
    return strstr(str, s);
}

const char* MyString::operator()(std::string s) {
    return strstr(str, s.c_str());
}

MyString& MyString::operator! () {
    for (size_t i=0; i < len; i++) {
      if ((str[i] > 64) && (str[i] < 91))
        str[i] = str[i]+32;
      if ((str[i] > 96) && (str[i] < 123))
        str[i] = str-32;
    }
    return *this;
}

