// Copyright 2020 Vladimir Uspensky

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>
#include <vector>
#include <iostream>


class MyString {
 private:
    char *my_string{};
    int str_length{};

 public:
    explicit MyString(const char *string = nullptr);
    explicit MyString(const std::string&);
    MyString(const MyString &);
    MyString(MyString &&);
    ~MyString();
    int length() const;
    char *get() const;
    MyString operator+(const MyString &);
    MyString operator-(const MyString &);
    MyString operator*(int num);
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
    friend std::istream &operator>>(std::istream &input, MyString &string);
    friend std::ostream &operator<<(std::ostream &output, MyString &string);
};

#endif  // INCLUDE_MYSTRING_H_
