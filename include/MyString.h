// Copyright 2020 JGMax

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>
#include <cstring>

#include <iostream>

class MyString {
 private:
    char* str;
    int size;

 public:
    explicit MyString(const char* str = nullptr) {
        if (str != nullptr) {
            size = strlen(str);
            this->str = new char[size + 1];
            memcpy(this->str, str, size + 1);
        } else {
            size = 0;
            this->str = new char[1];
            this->str[0] = 0;
        }
    }

    explicit MyString(std::string str) {
        size = str.length();
        this->str = new char[size + 1];
        memcpy(this->str, str.c_str(), size + 1);
    }

    MyString(const MyString& obj) {
        size = obj.size;
        this->str = new char[size + 1];
        memcpy(this->str, obj.str, size + 1);
    }

    MyString(MyString&& obj) noexcept {
        this->size = obj.size;
        this->str = obj.str;
        obj.str = nullptr;
        obj.size = 0;
    }

    ~MyString() {
        delete this->str;
        this->str = nullptr;
        this->size = 0;
    }

    char* get() const;
    int length() const;

    MyString operator+(const MyString&);
    MyString operator-(const MyString&);
    MyString operator*(unsigned int);

    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&) noexcept;

    bool operator==(const MyString&) const;
    bool operator!=(const MyString&) const;
    bool operator>=(const MyString&) const;
    bool operator<=(const MyString&) const;
    bool operator>(const MyString&) const;
    bool operator<(const MyString&) const;

    MyString operator!();
    char& operator[](int) const;
    int operator()(const char*);

    friend std::ostream& operator<<(std::ostream&, MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
};

#endif  // INCLUDE_MYSTRING_H_
