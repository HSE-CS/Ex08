// Copyright 2020 Bogomazov Mikhail
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <string>

class MyString {
 private:
    char* string;

 public:
    MyString();
    explicit MyString(const char*);
    explicit MyString(std::string);
    MyString(const MyString& s);
    MyString(MyString&& s);
    ~MyString();
    size_t length();
    char* get();
    MyString operator+(const MyString& s);
    MyString operator-(const MyString& s);
    MyString operator*(size_t num);
    MyString& operator=(const MyString& s);
    MyString& operator=(MyString&& s);
    bool operator== (const MyString& s);
    bool operator!= (const MyString& s);
    bool operator> (const MyString& s);
    bool operator< (const MyString& s);
    bool operator>= (const MyString& s);
    bool operator<= (const MyString& s);
    MyString operator!();
    char& operator[](const size_t ind) const;
    int operator()(const char* s);
    friend std::ostream& operator<<(std::ostream &os, MyString& s);
    friend std::istream& operator>>(std::istream &is, MyString& s);
};

#endif  //  INCLUDE_MYSTRING_H_
