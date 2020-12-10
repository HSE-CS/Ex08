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
    strcpy(str, x.c_str());
    str[length] = '\0';
}
MyString::MyString(const MyString& x) {
    int length = strlen(x.str);

    str = new char[length + 1];
    strcpy(str, x.str);
    str[length] = '\0';
}
MyString::MyString(MyString&& x) {
    str = new char[strlen(x.str) +1];
    strcpy(str, x.str);
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
    strcpy( t.str, str);
    strcat(t.str, x.str);
    // MyString t_n = t;
    return t;
}
MyString MyString::operator-(const MyString& x) {
    std::string x_array = std::string(x.str);
    std::string str_array = std::string(str);
    int pos1 = str_array.find(x_array);

    std::string res = str_array.substr(0, pos1 - 1) + str_array.substr(pos1 + x_array.size(), std::string::npos);

    return MyString(res);
}
MyString MyString::operator*(int x) {
    MyString t;
    t.str = new char[strlen(str) * x + 1];
    for (int i = 0; i < x; i++) {
        if (i == 0) {
            strcpy(t.str, str); continue;
        }
        strcat(t.str, str);
    }
    t.str[strlen(str) * x] = '\0';
    return t;
}
MyString MyString::operator=(const MyString& x) {
    str = new char[strlen(x.str) + 1];
    strcpy(str, x.str);
    return *this;
}
MyString MyString::operator=( MyString&& x) {
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
            str[i] = (char)tolower(str[i]); continue;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char)toupper(str[i]); continue;
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
    strcpy(x.str, str1);
    x.str[strlen(str1)] = '\0';
    delete[] str1;
    // x.str = str1;
    return tr;
}