#define INCLUDE_MYSTRING_H_

#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

class mystring {
private:
    char* str;
    size_t len;

public:
    friend std::ostream& operator<<(std::ostream& os, mystring&);
    friend std::istream& operator>>(std::istream& is, mystring&);
    explicit mystring(const char* first_str = nullptr);
    explicit mystring(std::string);
    mystring(const mystring&);
    mystring(mystring&&);
    ~mystring();
    size_t length() const;
    char* get() const;
    mystring operator+(const mystring&);
    mystring operator-(const mystring& s);
    mystring operator*(const size_t);
    mystring& operator=(const mystring&);
    mystring& operator=(mystring&&);
    bool operator==(const mystring&);
    bool operator!=(const mystring&);
    bool operator>(const mystring&);
    bool operator<(const mystring&);
    bool operator>=(const mystring&);
    bool operator<=(const mystring&);
    mystring operator!();
    char& operator[](const size_t) const;
    int operator()(const char*);
};

