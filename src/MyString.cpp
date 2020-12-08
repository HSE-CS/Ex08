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
