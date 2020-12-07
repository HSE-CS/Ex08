// Copyright 2020 <Jiiijyyy>
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <cmath>
#include <iostream>
#include <string>


class MyString {
private:
    char* string;
    unsigned int len;
public:
    MyString();
    MyString(const char*);
    MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    unsigned int length();
    char* get();
    MyString operator+(const MyString&);
    MyString operator-(const MyString&);
    MyString operator*(const int a);
    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&);
    //    operator== -��������� �� ���������.
    //    operator!= -��������� �� �����������.
    //    operator> -���������������� ��������� .
    //    operator< -���������������� ���������.
    //    operator>= -���������������� ���������.
    //    operator<= -���������������� ���������.
    //    operator! - � ��������� ���� �������� �������.
    //    operator[] - ������ � ������� �� �������.
    //    operator() - ����� ���������.
    //    operator>> -������ �� ������.
    //    operator>> -������ � �����.
};
#endif  // INCLUDE_MYSTRING_H_
