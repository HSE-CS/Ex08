// Copyright 2020 Khoroshavina Ekaterina
#pragma warning(disable : 4996)
#include "MyString.h"
#include <string>
#include <iostream>

MyString::MyString() {
    this->string = new char[1];
    memset(this->string, 0, 1);
    this->len = 0;
}

MyString::MyString(const char* str) {
    this->string = strdup(str);
    this->len = strlen(str);
}

MyString::MyString(const std::string& str) {
    this->string = strdup(str.c_str());
    this->len = str.length();
}

MyString::MyString(const MyString& str) {
    this->string = strdup(str.string);
    this->len = str.len;
}

MyString::MyString(MyString&& str) noexcept {
    this->len = str.len;
    this->string = str.string;
    str.len = 0;
    free(str.string);
}

MyString::~MyString() {
    this->len = 0;
    free(this->string);
}

int MyString::length() const {
    return this->len;
}

char* MyString::get() const {
    return this->string;
}

MyString MyString::operator+(const MyString& str) {
    return MyString(std::string(this->get()) + std::string(str.get()));
}

MyString MyString::operator-(const MyString& str) {
    std::string s(this->get());
    for (char c : std::string(str.get())) {
        while (s.find(c) != -1) {
            s.erase(s.find(c), 1);
        }
    }
    return MyString(s);
}

MyString MyString::operator*(int a) {
    std::string s;
    for (int i = 0; i < a; i++) {
        s.append(this->get());
    }
    return MyString(s);
}

MyString& MyString::operator=(const MyString& str) {
    if (this->string != nullptr) {
        delete this->string;
    }
    this->string = strdup(str.get());
    return *this;
}

MyString& MyString::operator=(MyString&& str) {
    if (this->string != nullptr) {
        delete this->string;
    }
    this->string = str.get();
    str.string = nullptr;
    return *this;
}

bool MyString::operator==(const MyString& str) {
    return !strcmp(this->get(), str.get());
}

bool MyString::operator!=(const MyString& str) {
    return strcmp(this->get(), str.get());
}

bool MyString::operator>(const MyString& str) {
    return (strcmp(this->get(), str.get()) == 1);
}

bool MyString::operator<(const MyString& str) {
    return (strcmp(this->get(), str.get()) == -1);
}

bool MyString::operator>=(const MyString& str) {
    return (strcmp(this->get(), str.get()) > 1);
}

bool MyString::operator<=(const MyString& str) {
    return (strcmp(this->get(), str.get()) < 1);
}

MyString MyString::operator!() {
    for (int i = 0; i < this->length(); i++) {
        if (std::isupper(this->string[i])) {
            this->string[i] = std::tolower(this->string[i]);
        }
        else {
            this->string[i] = std::toupper(this->string[i]);
        }
    }
    return *this;
}

char MyString::operator[](int i) {
    if (i <= this->length()) {
        return this->string[i];
    }
}

int MyString::operator()(const char* str) {
    char* temp = strstr(this->get(), str);
    if (temp == nullptr) {
        return -1;
    }
    else {
        return (temp - this->get());
    }
}

std::istream& operator>>(std::istream& in, MyString& str) {
    return in >> str.get();
}

std::ostream& operator<<(std::ostream& out, MyString& str) {
    return out << str.get();
}