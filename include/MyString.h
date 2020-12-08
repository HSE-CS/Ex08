// Copyright 2020 Tyulin Igor
#include <iostream>
#include <string>
#include <cstring>

class MyString{
private:
    char* str;
    size_t len;
public:
    explicit MyString(const char* val = nullptr);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    size_t length() const;
    char* get() const;
    MyString operator+(const MyString&);
    MyString operator-(const MyString&);
    MyString operator*(int n);
    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&);
    bool operator==(const MyString&);
    bool operator!=(const MyString&);
    bool operator>(const MyString&);
    bool operator<(const MyString&);
    bool operator>=(const MyString&);
    bool operator<=(const MyString&);
    MyString operator!();
    char& operator[](int);
    int operator()(const char*);
    friend std::ostream& operator<<(std::ostream&, MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
};

#endif