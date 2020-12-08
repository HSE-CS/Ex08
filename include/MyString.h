// Copyright 2020 Dolgopolov Alexey
//
// Created by sharg on 09.12.2020.
//

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_


#include <iostream>
#include <string>
#include <cstring>

class MyString {
 private:
     char *ArrString;
	 
 public:
     explicit MyString(const char *valueArrString = nullptr);

     explicit MyString(const std::string &valueArrString);

     MyString(MyString &&existString);

     ~MyString();

     MyString(const MyString &existString);

     char *get() const;

     unsigned int length() const;

     MyString operator+(const MyString &valueArrString);

     MyString operator-(const MyString &valueArrString) const;

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

     int operator()(const char *valueArrString) const;

     friend std::ostream &operator<<(std::ostream &vS, MyString &vSt);

     friend std::istream &operator>>(std::istream &vS, MyString &vSt);
};

#endif  // INCLUDE_MYSTRING_H_

