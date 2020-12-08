// Copyright 2020 SharunovEvgenya
//
// Created by sharg on 08.12.2020.
//

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_


#include <iostream>
#include <string>
#include <cstring>

class MyString {
 private:
     char *stringArray;

 public:
     explicit MyString(const char *valueSringArray = nullptr);

     explicit MyString(const std::string &valueSringArray);

     MyString(MyString &&existString);

     ~MyString();

     MyString(const MyString &existString);

     char *get() const;

     unsigned int length() const;

     MyString operator+(const MyString &valueSringArray);

     MyString operator-(const MyString &valueSringArray) const;

     MyString operator*(unsigned int lenght) const;

     MyString &operator=(const MyString &);

     MyString &operator=(MyString &&);

     MyString &operator!();

     bool operator>(const MyString &);

     bool operator<(const MyString &);

     bool operator==(const MyString &) const;

     bool operator!=(const MyString &) const;

     bool operator>=(const MyString &);

     bool operator<=(const MyString &);

     char &operator[](unsigned int number) const;

     int operator()(const char *valueStringArray) const;

     friend std::ostream &operator<<(std::ostream &valueStream, MyString &valueString);

     friend std::istream &operator>>(std::istream &valueStream, MyString &valueString);
};

#endif  // INCLUDE_MYSTRING_H_

