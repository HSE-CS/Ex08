// Copyright 2020 Ilya Tatsenko
#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include"MyString.h"

MyString::MyString() {
    str = nullptr;
}
MyString::MyString(const char* x) {
    int length = strlen(x);
    str = new char[length + 1];
    snprintf(str, length + 1, "%s", x);
    str[length] = '\0';
}
MyString::MyString(std::string x) {
    int length = x.length();
    str = new char[length + 1];
    snprintf(str, length + 1, "%s", x.c_str());
    str[length] = '\0';
}
MyString::MyString(const MyString& x) {
    int length = strlen(x.str);

    str = new char[length + 1];
    snprintf(str, length + 1, "%s", x.str);
    str[length] = '\0';
}
MyString::MyString(MyString&& x) {
    str = new char[strlen(x.str) +1];
    snprintf(str, strlen(x.str), "%s", x.str);
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
    if (str == nullptr) return 0;
    return strlen(str);
}
char* MyString::get() {
    return str;
}

MyString MyString::operator+(const MyString& x) {
    if (x.str == nullptr) {
        std::string this_ = std::string(str);
        return MyString(str);
    } else if (str == nullptr) {
        std::string x_ = std::string(x.str);
        return MyString(x.str);
    } else {
        std::string this_ = std::string(str);
        std::string x_ = std::string(x.str);
        return MyString(this_ + x_);
      }
}
MyString MyString::operator-(const MyString& x) {
    std::string x_array = std::string(x.str);
    std::string str_array = std::string(str);
    std::string res;
    int  k = 0;
    int j;
    for (int i = 0; i < x_array.size(); i++) {
        for (j = 0; j < str_array.size(); j++) {
            if (x_array[i] == str_array[j]) { 
                if (k == 0) {
                    res = res + str_array.substr(k, j - k);
                    k = j;
                } else {
                    res = res + str_array.substr(k + 1, j - k - 1);
                    k = j;
                }
            }
        }
    }
    if (str_array[j-1]) res += str_array.substr(j - 1, str_array.size() - 1);
    return MyString(res);
}
MyString MyString::operator*(int x) {
    std::string this_ = std::string(str);
    std::string result;
    for (int i = 0; i < x; i++) {
        result += this_;
    }
    return MyString(result);
}
MyString MyString::operator=(const MyString& x) {
    str = new char[strlen(x.str) + 1];
    snprintf(str, strlen(x.str), "%s", x.str);
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
    snprintf(x.str, strlen(str1), "%s", str1);
    x.str[strlen(str1)] = '\0';
    delete[] str1;
    // x.str = str1;
    return tr;
}
