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
        unsigned int len = strlen(str);
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
    this->string = nullptr;
    this->len = 0;
    if (str.length() != 0) {
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
}

MyString::MyString(const MyString& str) {
    this->len = str.len;
    this->string = new char[len + 1];
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
    str.string = nullptr;
    str.len = 0;
}

MyString::~MyString() {
    delete[] this->string;
}

unsigned int MyString::length() {
    if (string) return strlen(this->string);
    else return 0;
}

char* MyString::get() {
    return this->string;
}

MyString MyString::operator+(const MyString& str) {
    unsigned int len1 = this->length();
    unsigned int len2 = str.len;
    char* new_str = new char[len1 + len2 + 1];
    int i = 0;
    for (i; i < len1; i++) {
        new_str[i] = this->string[i];
    }
    int j = 0;
    for (i; i < (len1 + len2); i++) {
        new_str[i] = str.string[j];
        j++;
    }
    new_str[i] = '\0';
    MyString new_str_n(new_str);
    return new_str_n;
}

MyString MyString::operator-(const MyString& str) {
    if (this->string) {
        std::string temp = (std::string(this->string));

        int i = 0;
        while (i < str.len) {
            while (temp.find(str.string[i]) != -1) {
                temp.erase(temp.find(str.string[i]), 1);
            }
            i++;
        }
        MyString new_str_n(temp);
        return new_str_n;
    }
    else {
        MyString new_str_n(nullptr);
        return new_str_n;
    }
}

MyString MyString::operator*(const int a) {
    if (this->string) {
        int i = 0;
        unsigned int new_len = a * this->len;
        char* new_str = new char[new_len + 1];
        while (i < new_len) {
            new_str[i] = this->string[i % this->len];
            i++;
        }
        new_str[i] = '\0';
        MyString new_str_n(new_str);
        return new_str_n;
    }
    else {
        MyString new_str_n(nullptr);
        return new_str_n;
    }
}

MyString& MyString::operator=(const MyString& str) {
    MyString new_str(str.string);
    return *this;
}

MyString& MyString::operator=(MyString&& str) {
    MyString new_str = std::move(str);
    return *this;
}