// Copyright 2020 Bodrov Egor

#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

MyString::MyString(const char* str) {
    if (str != nullptr) {
        string = new char[strlen(str) + 1];
        strncpy(string, str, strlen(str) + 1);
    } else {
        string = new char[1];
        string[0] = '\0';
    }
}

MyString::MyString(std::string str) {
    string = new char[str.size() + 1];
    for (int i = 0; i < str.size(); i++)
        string[i] = str[i];
    string[str.size()] = '\0';
}

MyString::MyString(const MyString& str) {
    string = new char[str.length() + 1];
    strncpy(string, str.string, str.length() + 1);
}

MyString::MyString(MyString&& str) {
    string = str.string;
    str.string = nullptr;
}

MyString::~MyString() {
    delete[] string;
}

unsigned MyString::length() const {
    return strlen(string);
}

char* MyString::get() const {
    return string;
}

MyString MyString::operator+(MyString str) {
    return MyString(std::string(this->get()) + std::string(str.get()));
}

MyString MyString::operator-(MyString str) {
    int len = this->length();
    char* s = new char[len + 1];
    int k = 0;
    for (int i = 0; i < len; i++) {
        bool flag = true;
        for (int j = 0; j < str.length(); j++) {
            if (str.string[j] == string[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            s[k++] = string[i];
        }
    }
    s[k] = '\0';
    return MyString(s);
}

MyString MyString::operator*(int n) {
    std::string s = string;
    std::string res = "";
    for (int i = 0; i < n; i++)
        res += s;
    return MyString(res);
}

MyString MyString::operator=(const MyString& str) {
    string = str.string;
    return *this;
}

MyString MyString::operator=(MyString&& str) {
    string = str.string;
    str.string = nullptr;
    return *this;
}

bool MyString::operator==(MyString str) {
    return !strcmp(string, str.get());
}

bool MyString::operator!=(MyString str) {
    return strcmp(string, str.get());
}

bool MyString::operator>(MyString str) {
    return (strcmp(string, str.get()) == 1);
}

bool MyString::operator<(MyString str) {
    return (strcmp(string, str.get()) == -1);
}

bool MyString::operator>=(MyString str) {
    return (strcmp(string, str.get()) != -1);
}

bool MyString::operator<=(MyString str) {
    return (strcmp(string, str.get()) != 1);
}

MyString MyString::operator!() {
    for (int i = 0; i < this->length(); i++) {
        if (std::isupper(string[i])) {
            string[i] = std::tolower(string[i]);
        } else {
            string[i] = std::toupper(string[i]);
        }
    }
    return *this;
}

char& MyString::operator[](int n) {
    return string[n];
}

int MyString::operator()(const char* str) {
    return (std::string(string).find(std::string(str)));
}

std::ostream& operator<<(std::ostream& stream, MyString str) {
    return stream << str.get();
}

std::istream& operator>>(std::istream& stream, MyString str) {
    return stream >> str.get();
}
