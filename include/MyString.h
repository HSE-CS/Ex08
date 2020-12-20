// Copyright [2020] <Balayan Roman>

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <iostream>
#include <string>

class MyString {
 private:
    char* value;
    unsigned int size;
    unsigned int reserved_size;

 public:

    MyString();
    MyString(const MyString& val);
    MyString(std::string val);
    ~MyString();
    void append(const char* val);
    void append(const MyString& val);
    char pop_back();
    void reverse();
    void del(char val);
    unsigned int length();
    void resize(unsigned int size);
    unsigned int get_reserved_size();
    char* get();
    float get_float();
    int* get_date();
    char& operator[](unsigned int i);
    friend std::ostream& operator<<(std::ostream& out, const MyString& val);
    friend std::istream& operator>>(std::istream& in, MyString& val);
    void operator=(const MyString& val);
    void operator=(const char* val);
    void operator+=(const MyString& val);
    void operator+=(const char* val);
    void operator+=(char val);
    bool operator==(const MyString& val);
    bool operator!=(const MyString& val);
    bool operator>=(const MyString& val);
    bool operator<=(const MyString& val);
    bool operator>(const MyString& val);
    bool operator<(const MyString& val);
    MyString operator+(const MyString& val);
    MyString operator-(const MyString& val);
    MyString operator!();
    int operator()(const MyString& val);
    int operator()(const char* val);
};

MyString intToMyString(int val);

#endif   // INCLUDE_MYSTRING_H_
