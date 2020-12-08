// Copyright 2020 Uskova
#include "MyString.h"

#include <string>
#include <cstring>

MyString::MyString(const char* str) {
    if (str != nullptr) {
        this->string = new char[strlen(str) + 1];
        memcpy(this->string, str, strlen(str) + 1);
    } else {
        this->string = new char[1];
        memset(this->string, 0, 1);
    }
}

MyString::MyString(std::string str) {
    this->string = new char[str.size() + 1];
    memcpy(this->string, str.c_str(), str.size() + 1);
}

MyString::MyString(const MyString& str) {
    this->string = new char[str.length() + 1];
    memcpy(this->string, str.get(), str.length() + 1);
}

MyString::MyString(MyString&& str) {
    this->string = str.string;
    str.string = nullptr;
}

MyString::~MyString() {
    delete this->string;
}

size_t MyString::length() const {
    return strlen(this->string);
}

char* MyString::get() const {
    return this->string;
}

MyString MyString::operator+(const MyString& str) {
    std::string str_ = std::string(this->get()) + std::string(str.get());
    return MyString(str_);
}

MyString MyString::operator-(const MyString& str) {
    std::string str_(this->get());
    size_t i;
    size_t j = 0;
    for (i = 0; i < str.length(); i++) {
        j = 0;
        while (j < str_.length()) {
            if (str_[j] == str[i]) {
                str_.erase(j, 1);
            } else {
                j += 1;
            }
        }
    }
    return MyString(str_);
}

MyString MyString::operator*(int num) {
    std::string str;
    for (int i = 0; i < num; i++) {
        str += this->string;
    }
    return MyString(str);
}

MyString& MyString::operator=(const MyString& str) {
    if (this->string != nullptr) {
        delete this->string;
    }
    this->string = new char[str.length() + 1];
    memcpy(this->string, str.get(), str.length() + 1);
    return *this;
}

MyString& MyString::operator=(MyString&& str) {
    if (this->string != nullptr) {
        delete this->string;
    }
    this->string = str.string;
    str.string = nullptr;
    return *this;
}

bool MyString::operator==(const MyString& str) {
    return strcmp(this->string, str.string) == 0;
}

bool MyString::operator!=(const MyString& str) {
    return strcmp(this->string, str.string) != 0;
}

bool MyString::operator>(const MyString& str) {
    return strcmp(this->string, str.string) > 0;
}

bool MyString::operator<(const MyString& str) {
    return strcmp(this->string, str.string) < 0;
}

bool MyString::operator>=(const MyString& str) {
    return strcmp(this->string, str.string) >= 0;
}

bool MyString::operator<=(const MyString& str) {
    return strcmp(this->string, str.string) <= 0;
}

MyString MyString::operator!() {
    std::string str(this->string);
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return MyString(str);
}

char MyString::operator[](size_t num) const {
    if (num < 0 || num >= this->length()) {
        throw "Out of range";
    }
    return this->string[num];
}

int MyString::operator()(const char* str) {
    char* str_ = strstr(this->string, str);
    if (str_ == nullptr) {
        return -1;
    } else {
        return str_ - this->string;
    }
}

std::ostream& operator<<(std::ostream& stream, MyString& str) {
    return stream << str.get();
}

std::istream& operator>>(std::istream& stream, MyString& str) {
    return stream >> str.get();
}
