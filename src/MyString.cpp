// Copyright 2020 Ilya Tatsenko
#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
#include<string>
#include"MyString.h"

MyString::MyString() {
    str = nullptr;
}
MyString::MyString(const char* x) {
    int length = strlen(x);
    str = new char[length + 1];
    strncpy(str, x, length + 1);
}
MyString::MyString(std::string x) {
    int length = x.length();
    str = new char[length + 1];
    snprintf(str, length, x.c_str());
    str[length] = '\0';
}
MyString::MyString(const MyString& x) {
    int length = strlen(x.str);

    str = new char[length + 1];
    snprintf(str, length, x.str);
    str[length] = '\0';
}
MyString::MyString(MyString&& x) {
    str = new char[strlen(x.str) +1];
    snprintf(str, strlen(x.str), x.str);
    str[strlen(x.str)] = '\0';
    // str = x.str;
    x.~MyString();
    x.str = nullptr;
    // x.str = nullptr;
}
MyString :: ~MyString() {
    delete[] this->str;
}
int MyString::length() {
    return strlen(str);
}
char* MyString::get() {
    return str;
}

MyString MyString::operator+(const MyString& x) {
    MyString t;
    t.str = new char[strlen(x.str) + strlen(str) + 1];
    snprintf( t.str, strlen(str), str);
    strcat(t.str, x.str);
    // MyString t_n = t;
    return t;
}
MyString MyString::operator-(const MyString& x) {
    std::string x_ = std::string(x.str);
    std::string str_ = std::string(str);
    int pos = str_.find(x_);

    std::string res = str_.substr(0, pos - 1) + str_.substr(pos + x_.size(), std::string::npos);

    return MyString(res);
}
MyString MyString::operator*(int x) {
    MyString t;
    t.str = new char[strlen(str) * x + 1];
    for (int i = 0; i < x; i++) {
        if (i == 0) {
            snprintf(t.str, strlen(str), str); continue;
        }
        strcat(t.str, str);
    }
    t.str[strlen(str) * x] = '\0';
    return t;
}
MyString MyString::operator=(const MyString& x) {
    str = new char[strlen(x.str) + 1];
    snprintf(str, strlen(x.str), x.str);
    return *this;
}
MyString MyString::operator=(MyString&& x) {
    str = x.str;
    x.str = nullptr;
    x.~MyString();
    return *this;
}
bool MyString::operator==(const MyString& x) {
    std::string str1 = std::string(str);
    std::string str2 = std::string(x.str);
    return str1 == str2;
}
bool MyString::operator!=(const MyString& x) {
    std::string str1 = std::string(str);
    std::string str2 = std::string(x.str);
    return str1 != str2;
}

bool MyString::operator>(const MyString& x) {
    std::string str1 = std::string(str);
    std::string str2 = std::string(x.str);
    return str1 > str2;
}
bool MyString::operator<(const MyString& x) {
    std::string str1 = std::string(str);
    std::string str2 = std::string(x.str);
    return str1 < str2;
}
bool MyString::operator>=(const MyString& x) {
    std::string str1 = std::string(str);
    std::string str2 = std::string(x.str);
    return str1 >= str2;
}
bool MyString::operator<=(const MyString& x) {
    std::string str1 = std::string(str);
    std::string str2 = std::string(x.str);
    return str1 <= str2;
}


MyString MyString::operator!() {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = tolower(str[i]); continue;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = toupper(str[i]); continue;
        }
    }
    return MyString(str);
}
char MyString::operator[](int x) {
    return str[x];
}
int MyString::operator()(const char* x) {
    char* mb = strstr(str, x);
    if (mb == NULL) return -1;
    return mb - str;
}

std::ostream& operator<<(std::ostream &tr, const MyString& x) {
    tr <<  x.str;
    return tr;
}

std::istream& operator>>(std::istream &tr, MyString& x) {
    char* str1 = new char[100];
    tr >> str1;
    x.str = new char[strlen(str1) + 1];
    snprintf(x.str, strlen(str1), str1);
    x.str[strlen(str1)] = '\0';
    delete[] str1;
    // x.str = str1;
    return tr;
}
