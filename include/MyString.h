// Copyright [2020] <Balayan Roman>

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
#include <string.h>

class MyString {
private:
    char* value;
    unsigned int size;
    unsigned int reserved_size;
public:
    //MyString(const char* val = nullptr);
    MyString();
    MyString(const MyString& val);
    MyString(std::string val);
    //MyString(MyString&& val);
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
    //MyString& operator=(MyString&& val);
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


#endif   // MYSTRING_H_ 