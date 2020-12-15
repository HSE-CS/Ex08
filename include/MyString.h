// Copyright 10.12.20 KostinAndrej

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <cstring>

class MyString{
 private:
    char *lenofstr;
 public:
    explicit MyString(const char* String = nullptr);
    explicit MyString(const std::string &String);
    MyString( const MyString& existString);
    MyString( MyString&& existString);
    ~MyString();

    char *get() const;
    unsigned int length() const;

    MyString operator+(const MyString& String) const;
    MyString operator-(const MyString& String) const;
    MyString operator*(unsigned int lenght) const;
    MyString & operator=(const MyString& existString);
    MyString & operator=(MyString&& existString);
    MyString & operator! ();

    bool operator== (const MyString& existString) const;
    bool operator!= (const MyString& existString) const;
    bool operator> (const MyString& existString);
    bool operator< (const MyString& existString);
    bool operator>= (const MyString& existString);
    bool operator<= (const MyString& existString);

    char &operator[] (unsigned  int number) const;
    long operator() (const char* String) const;
    friend std::ostream& operator<<(std::ostream& valueStream,  MyString& valueString);
    friend std::istream& operator>>(std::istream& valueStream, MyString& valueString);

};

#endif  // INCLUDE_MYSTRING_H_