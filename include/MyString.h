// Copyright 2020 Kasyanov

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <cstring>
#include <string>

class MyString {
    friend std::istream &operator>>(std::istream &inp, MyString &s);
    friend std::ostream &operator<<(std::ostream &out, MyString &s);

 private:
    char *str;
    int len;
    bool CharInString(char c) const;

 public:
    explicit MyString(const char *new_str = nullptr);
    explicit MyString(std::string);
    MyString(const MyString &);
    MyString(MyString &&);
    ~MyString();
    int length() const;
    char *get() const;
    MyString operator+(const MyString &);
    MyString operator-(const MyString &);
    MyString operator*(int n);
    MyString &operator=(const MyString &);
    MyString &operator=(MyString &&);
    bool operator==(const MyString &);
    bool operator!=(const MyString &);
    bool operator>(const MyString &);
    bool operator<(const MyString &);
    bool operator>=(const MyString &);
    bool operator<=(const MyString &);
    MyString operator!();
    char &operator[](int i);
    int operator()(const char *);
};

char *AddCharResize(char *, char);

#endif  // INCLUDE_MYSTRING_H_
