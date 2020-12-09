// Copyright 2020 milalupehina

#include <iostream>
#include <string>

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

class MyString {
 private:
    char *str = new char;

 public:
    explicit MyString(const char * = nullptr);
    explicit MyString(const std::string&);
    MyString(const MyString &);
    MyString(MyString &&);
    ~MyString();
    int length() const;
    char* get() const;

    MyString operator+(const MyString &);
    MyString operator-(const MyString &);
    MyString operator*(int);
    MyString &operator=(const MyString &);
    MyString &operator=(MyString &&);

    char &operator[](int) const;
    int operator()(const char *);

    friend std::ostream &operator<<(std::ostream &, MyString &);
    friend std::istream &operator>>(std::istream &, MyString &);

    bool operator==(const MyString &) const;
    bool operator!=(const MyString &) const;
    bool operator>(const MyString &) const;
    bool operator<(const MyString &) const;
    bool operator>=(const MyString &) const;
    bool operator<=(const MyString &) const;

    MyString operator!();    //  - у латинских букв меняется регистр.
};

#endif  // INCLUDE_MYSTRING_H_
