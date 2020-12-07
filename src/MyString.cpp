// Copyright 2020 GN
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <string.h>
#include <iostream>
#include <string>
MyString::MyString(const char* str) {
    if (!str) {
        this->len = 0;
        char* str = reinterpret_cast<char*>(calloc(1, sizeof(char)));
        this->mystring = str;
    }
    if (str) {
        this->len = strlen(str);
        this->mystring = strdup(str);
    }
}
MyString::MyString(std::string str) {
    this->mystring = nullptr;
    this->len = 0;
    if (str.length() != 0) {
        this->len = str.length();
        this->mystring = new char[str.length() + 1];
        size_t i = 0;
        while (i < str.length()) {
            this->mystring[i] = str[i];
            i++;
        }
        this->mystring[i] = '\0';
    }
}
MyString::MyString(const MyString& str) {
    this->len = str.len;
    this->mystring = new char[str.len + 1];
    int i = 0;
    while (i < this->len) {
        this->mystring[i] = str.mystring[i];
        i++;
    }
    this->mystring[i] = '\0';
}
MyString::MyString(const MyString&& str) {
    this->len = str.len;
    this->mystring = new char[str.len + 1];
    int i = 0;
    while (i < this->len) {
        this->mystring[i] = str.mystring[i];
        i++;
    }
    this->mystring[i] = '\0';
}
MyString::~MyString() {
    delete[] this->mystring;
    this->len = 0;
}
int MyString::length() {
    return this->len;
}
char* MyString::get() {
    return this->mystring;
}
MyString MyString::operator+(const MyString& str) {
    unsigned int len1 = this->length();
    unsigned int len2 = str.len;
    char* new_str = new char[len1 + len2 + 1];
    int i = 0;
    for (i; i < len1; i++) {
        new_str[i] = this->mystring[i];
    }
    int j = 0;
    for (i; i < (len1 + len2); i++) {
        new_str[i] = str.mystring[j];
        j++;
    }
    new_str[i] = '\0';
    MyString new_str_n(new_str);
    return new_str_n;
}
MyString MyString::operator-(const MyString& str) {
    std::string temp = (std::string(this->mystring));
    int i = 0;
    while (i < str.len) {
        while (temp.find(str.mystring[i]) != -1) {
            temp.erase(temp.find(str.mystring[i]), 1);
        }
    i++;
    }
    MyString new_str(temp);
    return new_str;
}
MyString MyString::operator*(int n) {
    char* new_str = new char[len * n + 1];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i * len; j < (i + 1) * len; ++j) {
            new_str[j] = mystring[j - i * len];
        }
    }
    new_str[len * n] = '\0';
    MyString tmp(new_str);
    return tmp;
}
MyString& MyString::operator=(const MyString& str) {
    this->len = str.len;
    this->mystring = strdup(str.mystring);
    return *this;
}
MyString& MyString::operator=(MyString&& str) {
    this->len = str.len;
    this->mystring = strdup(str.mystring);
    return *this;
}
bool MyString::operator==(const MyString& str) {
    int res = (strcmp(this->mystring, str.mystring));
    if (res == 0) {
        return true;
    }
    if (res != 0) {
        return false;
    }
}
bool MyString::operator!=(const MyString& str) {
    int x = (strcmp(this->mystring, str.mystring));
    if (x == 0) {
        return false;
    }
    if (x != 0) {
        return true;
    }
}
bool MyString::operator>(const MyString& str) {
    int x = (strcmp(this->mystring, str.mystring));
    if (x > 0) {
        return true;
    }
    if (x <= 0) {
        return false;
    }
}
bool MyString::operator<(const MyString& str) {
    int x = (strcmp(this->mystring, str.mystring));
    if (x < 0) {
        return true;
    }
    if (x >= 0) {
        return false;
    }
}
bool MyString::operator>=(const MyString& str) {
    int x = (strcmp(this->mystring, str.mystring));
    if (x >= 0) {
        return true;
    }
    if (x < 0) {
        return false;
    }
}
bool MyString::operator<=(const MyString& str) {
    int x = (strcmp(this->mystring, str.mystring));
    if (x <= 0) {
        return true;
    }
    if (x > 0) {
        return false;
    }
}
MyString MyString::operator!() {
    MyString temp(*this);
    for (size_t i = 0; i < temp.len; ++i) {
        if (temp.mystring[i] >= 'a' && temp.mystring[i] <= 'z') {
            temp.mystring[i] -= 'a' - 'A';
        } else if (temp.mystring[i] >= 'A' && temp.mystring[i] <= 'Z') {
                temp.mystring[i] += 'a' - 'A';
            }
    }
    return temp;
}
char MyString::operator[](int n) {
    return this->mystring[n];
}
int MyString::operator()(const char* str) {
    char* ptr = strstr(this->mystring, str);
    if (ptr == NULL) {
        return -1;
    }
    if (ptr != NULL) {
        return ptr-this->mystring;
    }
}
std::ostream& operator>>(std::ostream& os, MyString& str) {
    return os << str.get();
}
std::istream& operator>>(std::istream& is, MyString& str) {
    return is >> str.get();
}
