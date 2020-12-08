// Copyright 2020 Igumnova Natasha
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

MyString::MyString(const char* str) {
    if (str != nullptr) {
        this->string = new char[strlen(str) + 1];
        snprintf(this->string, strlen(str) + 1, "%s", str);
        this->string[strlen(str)] = '\0';
    }
    else {
        this->string = new char[1];
        memset(string, 0, 1);
    }
}

MyString::MyString(std::string str) {
    char* newstr = new char[str.size()+1];
    snprintf(newstr, str.size() + 1, "%s", str.c_str());
    this->string = newstr;
    this->string[str.size()] = '\0';
}

MyString::MyString(const MyString& str) {
    this->string = new char[str.length() + 1];
    snprintf(this->string, str.length() + 1, "%s", str.string);
}

MyString::MyString(MyString&& str) {
    this->string = str.string;
    str.string = nullptr;
}

MyString::~MyString() {
    delete string;
}

size_t MyString::length() const {
    return strlen(this->string);
}

char* MyString::get() const {
    return this->string;
}

MyString MyString::operator+(const MyString& str) {
    std::string res = std::string(this->get()) + std::string(str.get());
    return MyString(res);
}

MyString MyString::operator-(const MyString& str) {
    std::string res(this->get());
    int i = 0;
    while (i < str.length()) {
        while (res.find(str.string[i]) != -1) {
            res.erase(res.find(str.string[i]), 1);
        }
        i++;
    }
    return MyString(res);
}

MyString MyString::operator*(int n) {
    std::string res;
    for (int i = 0; i < n;i++) {
        res.append(this->get());
    }
    return MyString(res);
}

MyString& MyString::operator=(const MyString& str) {
    puts(this->string);
    if (this->string != nullptr)
        delete this->string;
    this->string = new char[strlen(str.string) + 1];
    snprintf(this->string, strlen(str.string) + 1, "%s", str.string);
    this->string[strlen(str.string)] = '\0';
    return *this;
}

MyString& MyString::operator=(MyString&& str) {
    if (this->string != nullptr)
        delete this->string;
    this->string = str.get();
    str.string = nullptr;
    return *this;
}

bool MyString::operator==(const MyString& str) {
    return strcmp(this->string, str.get()) == 0;
}

bool MyString::operator!=(const MyString& str) {
    return strcmp(this->string, str.get()) != 0;
}

bool MyString::operator>(const MyString& str) {
    return strcmp(this->string, str.get()) == 1;
}

bool MyString::operator<(const MyString& str) {
    return strcmp(this->string, str.get()) == -1;
}

bool MyString::operator>=(const MyString& str) {
    return strcmp(this->string, str.get()) != -1;
}

bool MyString::operator<=(const MyString& str) {
    return strcmp(this->string, str.get()) != 1;
}

MyString MyString::operator!() {
    for (int i = 0;i < strlen(string);i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 'a';
            string[i] += 'A';
        }
    }
    return *this;
}

char MyString::operator[](int index) {
    if (index > 0 && index < strlen(string)) {
        return string[index];
    }
    else {
        throw "Error, index out of range";
    }
}

int MyString::operator()(const char* str) {
    std::string my_str = this->get();
    int i = 0;
    return  my_str.find(str, i);
}


std::ostream& operator<<(std::ostream& os, MyString& str) {
    return os << str.get();
}

std::istream& operator>>(std::istream& is, MyString& str) {
    return is >> str.get();
}
