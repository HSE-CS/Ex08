// Copyright 2020 Bulatov D.
#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"

MyString::MyString(const char* s) {
    if (s ==nullptr) {
        len = 0;
        str = nullptr;
    }else {
        len = strlen(s);
        str = new char[len + 1];
        for (size_t i = 0; i <= len; i++) {
            str[i] = s[i];
        }
    }
}

MyString::MyString(string s) {
    len = s.size();
    str = new char[len + 1];
    for (size_t i = 0; i <= len; i++) {
        str[i] = s[i];
    }
}

MyString::MyString(const MyString& s) {
    this->len = s.len;
    this->str = new char[len + 1];
    for (size_t i = 0; i <= len; i++) {
        str[i] = s.str[i];
    }
}

MyString::MyString(MyString&& s) {
    this->len = s.len;
    this->str = s.str;
    s.len = 0;
    s.str = nullptr;
}

MyString::~MyString() {
    delete[] this->str;
    this->len = 0;
}

size_t MyString::length() {
    return this->len;
}

char* MyString::get() {
    return this->str;
}

MyString MyString::operator+(const MyString& s) {
    unsigned int len1 = this->length();
    unsigned int len2 = s.len + len1;
    char* new_str = new char[len2 + 1];
    int i = 0;
    for (i; i < len1; i++) {
        new_str[i] = this->str[i];
    }
    int j = 0;
    for (i; i < len2; i++) {
        new_str[i] = s.str[j];
        j++;
    }
    new_str[i] = '\0';
    MyString nstr(new_str);
    return nstr;
}

MyString MyString::operator-(const MyString& s) {
    string temp = (string(this->str));
    int i = 0;
    while (i < s.len) {
        while (temp.find(s.str[i]) != -1) {
            temp.erase(temp.find(s.str[i]), 1);
        }
        i++;
    }
    MyString new_str(temp);
    return new_str;
}

MyString MyString::operator*(size_t n) {
    char* new_str = new char[len * n + 1];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i * len; j < (i + 1) * len; ++j) {
            new_str[j] = str[j - i * len];
        }
    }
    new_str[len * n] = '\0';
    MyString tmp(new_str);
    return tmp;
}

MyString& MyString::operator=(const MyString& s) {
    if (s.str == nullptr) {
        this->len = 0;
        this->str = nullptr;
        return *this;
    }
    this->len = s.len;
    str = new char[s.len + 1];
    for (size_t i = 0; i <= this->len; ++i) {
        this->str[i] = s.str[i];
    }
    return *this;
}

MyString& MyString::operator=(MyString&& s) {
    this->len = s.len;
    this->str = s.str;
    s.len = 0;
    s.str = nullptr;
    return *this;
}

bool MyString::operator==(const MyString& s) {
    if (strcmp(this->str, s.str) == 0) {
        return 1;
    }else {
        return 0;
    }
}

bool MyString::operator!=(const MyString& s) {
    if (strcmp(this->str, s.str) != 0) {
        return 1;
    }else {
        return 0;
    }
}

bool MyString::operator>(const MyString& s) {
    if (strcmp(this->str, s.str) > 0) {
        return 1;
    }else {
        return 0;
    }
}

bool MyString::operator<(const MyString& s) {
    if (strcmp(this->str, s.str) < 0) {
        return 1;
    }else {
        return 0;
    }
}

bool MyString::operator>=(const MyString& s) {
    if (strcmp(this->str, s.str) >= 0) {
        return 1;
    }else {
        return 0;
    }
}

bool MyString::operator<=(const MyString& s) {
    if (strcmp(this->str, s.str) <=0) {
        return 1;
    }else {
        return 0;
    }
}

MyString MyString::operator!() {
    MyString temp(*this);
    for (size_t i = 0; i < temp.len; ++i) {
        if (temp.str[i] >= 'a' && temp.str[i] <= 'z') {
            temp.str[i] -= 'a' - 'A';
        }
        else if (temp.str[i] >= 'A' && temp.str[i] <= 'Z') {
            temp.str[i] += 'a' - 'A';
        }
    }
    return temp;
}

char MyString::operator[](size_t n) {
    return this->str[n];
}

int MyString::operator()(const char* s) {
    if (strstr(this->str, s)==NULL) {
        return -1;
    }else {
        return strstr(this->str, s) - this->str;
    }
}

ostream& operator>>(ostream& os, MyString& s) {
    return os << s.get();
}

istream& operator>>(istream& is, MyString& s) {
    return is >> s.get();
}
