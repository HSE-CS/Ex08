// Copyright 2020 Kuznetsov Mikhail
#include "MyString.h"
MyString::MyString(const char* s) {
  len = strlen(s);
  buf = new char[len + 1];
  sprintf(buf, "%s", s);
  buf[len] = 0;
}

MyString::MyString(std::string s) {
  len = s.size();
  buf = new char[len + 1];
  sprintf(buf, "%s", s.c_str());
  buf[len] = 0;
}

MyString::MyString(const MyString &s) {
  len = s.len;
  buf = new char[len + 1];
  sprintf(buf, "%s", s.buf);
  buf[len] = 0;
}

MyString::MyString(MyString &&s) {
  len = s.len;
  buf = s.buf;
  s.len = 0;
  s.buf = nullptr;
}

MyString::~MyString() {
  delete []buf;
}

size_t MyString::length() const {
  return len;
}

char* MyString::get() const {
  return buf;
}

MyString MyString::operator+(const MyString &s) {
  size_t new_len = len + s.length();
  char * ans = new char[new_len + 1];
  sprintf(ans, "%s", buf);
  sprintf(ans + len, "%s", s.get());
  ans[new_len] = 0;
  return MyString(ans);
}

MyString MyString::operator-(const MyString &s) {
  std::string buf_str = std::string(buf, buf + len);
  for (size_t i = 0; i < s.length(); i++)
    buf_str.erase(std::remove(buf_str.begin(), buf_str.end(), s[i]),
                  buf_str.end());
  return MyString(buf_str);
}

MyString MyString::operator*(const size_t cnt) {
  MyString ans;
  for (size_t i = 0; i < cnt; i++) {
    ans = *this + ans;
  }
  return ans;
}

MyString& MyString::operator=(const MyString &s) {
  len = s.len;
  buf = new char[len + 1];
  sprintf(buf, "%s", s.buf);
  buf[len] = 0;
  return *this;
}

MyString& MyString::operator=(MyString &&s) {
  len = s.len;
  buf = s.buf;
  s.len = 0;
  s.buf = nullptr;
  return *this;
}

bool MyString::operator==(const MyString &s) {
  return !strcmp(buf, s.get());
}

bool MyString::operator!=(const MyString &s) {
  return strcmp(buf, s.get());
}

bool MyString::operator>(const MyString &s) {
  return (1 == strcmp(buf, s.get()));
}

bool MyString::operator<(const MyString &s) {
  return (-1 == strcmp(buf, s.get()));
}

bool MyString::operator>=(const MyString &s) {
  return (-1 != strcmp(buf, s.get()));
}

bool MyString::operator<=(const MyString &s) {
  return (1 != strcmp(buf, s.get()));
}

MyString MyString::operator!() {
  char * ans = new char[len + 1];
  sprintf(ans, "%s", buf);
  ans[len] = 0;
  for (size_t i = 0; i < len; i++) {
    if (ans[i] >= 'a' && ans[i] <= 'z')
      ans[i] += 'A' - 'a';
    else if (ans[i] >= 'A' && ans[i] <= 'Z')
      ans[i] += 'a' - 'A';
  }
  return MyString(ans);
}

char & MyString::operator[](const size_t ind) const {
  return buf[ind];
}

int MyString::operator()(const MyString &s) {
  char* p_find = strstr(buf, s.get());
  if (nullptr == p_find)
    return -1;
  else
    return p_find - buf;
}

std::ostream& operator<<(std::ostream& os, MyString &s) {
  return os << s.get();
}

std::istream& operator>>(std::istream& is, MyString &s) {
  return is >> s.get();
}
