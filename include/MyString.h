// Copyright 08.12.20 DenisKabanov

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

class MyString {
 private:
    char* string;
    int lenofstr;
 
 public:
    explicit MyString(const char* string = nullptr);
    explicit MyString(std::string string);
    MyString(const MyString& prevstring);
    MyString(MyString&& prevstring);
    ~MyString();
    int length();
    char* get();
    MyString operator+ (const MyString& astring);
    MyString operator- (const MyString& mstring);
    MyString operator* (const int number);
    MyString& operator=(const MyString& prevstring);
    MyString& operator=(MyString&& prevstring);
    bool operator== (const MyString& string);
    bool operator!= (const MyString& string);
    bool operator> (const MyString& string);
    bool operator< (const MyString& string);
    bool operator>= (const MyString& string);
    bool operator<= (const MyString& string);
    MyString operator! ();
    char operator[] (const int number);
    int operator() (const char* string);
    friend std::istream& operator>>(std::istream& is, MyString& string) {
        return is >> string.get();
    }
    friend std::ostream& operator<<(std::ostream& os, MyString& string) {
        return os << string.get();
    }
};

#endif  // INCLUDE_MYSTRING_H_
