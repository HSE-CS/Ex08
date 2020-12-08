// Copyright 2020 Khoroshavina Ekaterina
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <string>
#include <cstring>
#include <string.h>

class MyString {
 private:
     char* string;
     int len;
 public:
     MyString(const char* str = nullptr);
     MyString(const std::string& str);
     MyString(const MyString& str);
     MyString(MyString&& str) noexcept;
     ~MyString();
     int length() const;
     char* get() const;
     MyString operator+(const MyString& str);
     MyString operator-(const MyString& str);
     MyString operator*(int a);
     MyString& operator=(const MyString& str);
     MyString& operator=(MyString&& str);
     bool operator==(const MyString& str);
     bool operator!=(const MyString& str);
     bool operator>(const MyString& str);
     bool operator<(const MyString& str);
     bool operator>=(const MyString& str);
     bool operator<=(const MyString& str);
     MyString operator!();
     char operator[](int i);
     int operator()(const char* str);
     friend std::istream& operator>>(std::istream& in, MyString& str);
     friend std::ostream& operator<<(std::ostream& out, MyString& str);
};

#endif  // INCLUDE_MYSTRING_H_
