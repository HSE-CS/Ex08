// Copyright 2020 SmirnovGrigory
#include "MyString.h"

MyString::MyString(const char* new_str) {
  if (new_str != nullptr)
  {
    len = strlen(new_str);
    str = new char[len + 1];
    snprintf(str, len + 1, "%s", new_str);
  }
}

MyString::MyString(std::string new_str) {
  len = new_str.size();
  str = new char[len + 1];
  snprintf(str, len + 1, "%s", new_str.c_str());
}

MyString::MyString(const MyString& for_copy) {
  if (for_copy.str != nullptr)
  {
    len = for_copy.len;
    str = new char[len + 1];
    snprintf(str, len + 1, "%s", for_copy.str);
  }
}

MyString::~MyString() {
  len = 0;
  delete[]str;
}

MyString::MyString(MyString&& for_replace) {
  if (for_replace.str != nullptr)
  {
    len = for_replace.len;
    str = new char[len + 1];
    snprintf(str, len + 1, "%s", for_replace.str);
    for_replace.~MyString();
  }
}

char* MyString::get() { return str; }

size_t MyString::length() { return len; }

const char* delnullptr(const char* s) {
  if (s == nullptr)
    return "";
  else
    return s;
}

MyString MyString::operator+(const MyString& s) {
  return MyString(std::string(delnullptr(str)) + std::string(delnullptr(s.str)));
  //char* buf = new char[len + s.len];
  //strcpy(buf, delnullptr(str));
  //strcat(buf, delnullptr(s.str));
  //MyString result(buf);
  //delete [] buf;
  //return result;
  //return MyString(buf);
}

MyString MyString::operator-(const MyString& s) {
  if (s.str == nullptr)
    return MyString(str);
  else if (str == nullptr)
    return MyString();
  int cntlen = 0;
  for (int i = 0; i < len; i++)
    if (strchr(s.str, str[i]) == nullptr)
      cntlen++;
  char* buf = new char[cntlen + 1];
  int j = 0;
  for (int i = 0; i < len; i++)
    if (strchr(s.str, str[i]) == nullptr) {
      buf[j] = str[i];
      j++;
    }
  buf[j] = '\0';
  return MyString(buf);
}

MyString MyString::operator*(int rep) {
  std::string part(str);
  std::string buf;
  for (int i = 0; i < rep; i++)
    buf += part;
  return MyString(buf);
}

bool MyString::operator==(const MyString& s) const {
  return !(strcmp(str, s.str));
}

bool MyString::operator!=(const MyString& s) const {
  return (strcmp(str, s.str));
}

bool MyString::operator>(const MyString& s) const {
  return strcmp(str, s.str) > 0;
}

bool MyString::operator<(const MyString& s) const {
  return strcmp(str, s.str) < 0;
}

bool MyString::operator>=(const MyString& s) const {
  return strcmp(str, s.str) >=0;
}

bool MyString::operator<=(const MyString& s) const {
  return strcmp(str, s.str) <= 0;
}

MyString& MyString::operator=(const MyString& s) {
  delete (this->str);
  char* buf = new char[s.len + 1];
  snprintf(buf, s.len + 1, "%s", s.str);
  this->str = buf;
  return *this;
}

MyString& MyString::operator=(MyString&& s) {
  delete (this->str);
  this->str = s.get();
  s.str = nullptr;
  return *this;
}

char& MyString::operator[](int index) {
  if (index < 0 || len == 0 || index >= len)
    throw "index out of range";
  else
    return str[index];
}

std::ostream& operator>>(std::ostream& out, MyString& new_str) {
  return out << new_str.get();
}

std::istream& operator>>(std::istream& input, MyString& new_str) {
  return input >> new_str.get();
}
