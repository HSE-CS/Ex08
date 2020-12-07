// Copyright 2020 <Jiiijyyy>
#include "MyString.h"

MyString::MyString() {
    this->string = nullptr;
    this->len = 0;
}

MyString::MyString(const char* str) {
    this->string = nullptr;
    this->len = 0;
    if (str) {
        int len = strlen(str);
        this->len = len;
        this->string = new char[len + 1];
        int i = 0;
        while (i < len) {
            this->string[i] = str[i];
            i++;
        }
        this->string[i] = '\0';
    }
}
MyString::MyString(std::string str) {
    int len = str.length();
    this->len = len;
    this->string = new char[len + 1];
    int i = 0;
    while (i < len) {
        this->string[i] = str[i];
        i++;
    }
    this->string[i] = '\0';
}

MyString::MyString(const MyString& str) {
    this->len = str.len;
    this->string = new char[this->len + 1];
    int i = 0;
    while (i < this->len) {
        this->string[i] = str.string[i]; //After input operator[] rename
        i++;
    }
    this->string[i] = '\0';
}

MyString::MyString(MyString&& str) {
    this->len = str.len;
    this->string = new char[this->len + 1];
    int i = 0;
    while (i < this->len) {
        this->string[i] = str.string[i]; //After input operator[] rename
        i++;
    }
    this->string[i] = '\0';
    str.~MyString();
}

MyString::~MyString() {
    delete[] this->string;
    this->string = nullptr;
    this->len = 0;
}

unsigned int MyString::length() {
    return this->len;
}