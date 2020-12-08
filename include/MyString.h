// Copyright Nikolaev Ivan


#ifndef INCLUDE_MYSTRING_H_ 
#define MYSTRING_H_
#include <string>
#include <iostream>

class MyString {
 private:
    char* str;

 public:
    explicit MyString(const char* str = nullptr);
    explicit MyString(std::string str);
    MyString(const MyString &string);
    MyString(MyString &&str);
    ~MyString();
    int length();
    char* get();

    MyString operator+(MyString& myString);
    MyString operator-(MyString& myString);
    MyString operator*(int num);
    MyString operator=(MyString& myString);
    MyString operator=(MyString&& myString);
    bool operator==(MyString& myString);
    bool operator!=(MyString& myString);
    bool operator>(MyString& myString);
    bool operator<(MyString& myString);
    bool operator>=(MyString& myString);
    bool operator<=(MyString& myString);
    MyString operator!();
    char operator[](int index);
    int operator()(const char* str);
    friend std::ostream& operator<<(std::ostream& stream, MyString& str);
    friend std::istream& operator>>(std::istream& stream, MyString& str);
};

#endif INCLUDE_MYSTRING_H_ // INCLUDE_MYSTRING_H_
