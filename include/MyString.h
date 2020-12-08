// Copyright 2020 SmirnovGrigory
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include<iostream>
#include<cstring>

class MyString {
 private:
   char* str = nullptr;
   size_t len = 0;
 public:
   MyString(const char* = nullptr);
   MyString(std::string);
   MyString(const MyString&);
   MyString(MyString&&);
   ~MyString();
   size_t length();
   char* get();
};

#endif  // INCLUDE_MYSTRING_H_
