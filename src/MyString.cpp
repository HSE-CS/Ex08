// Copyright 2020 PolinaP
#include "MyString.h"
#include <iostream>

MyString::MyString(const char* other) : mystr{ nullptr }, size{ 0 } {
    if (other != nullptr) {
        this->size = strlen(other);
        this->mystr = new char[size + 1];
        memset(this->mystr, 0, size + 1);
        memcpy(this->mystr, other, this->size);
    }
    else {
        this->size = 0;
        this->mystr = nullptr;
    }
}

MyString::MyString(std::string other) : mystr{ nullptr }, size{ 0 } {
    this->size = other.length();
    mystr = new char[other.length() + 1];
    memset(this->mystr, 0, size + 1);
    memcpy(this->mystr, other.c_str(), this->size);
}

MyString::~MyString() {
    this->size = 0;
    delete[] mystr;
}

MyString::MyString(const MyString& other) : mystr{ nullptr }, size{ 0 } {
    this->size = other.size;
    this->mystr = new char[size + 1];
    memset(this->mystr, 0, size + 1);
    memcpy(this->mystr, other.get(), this->size);
}

MyString::MyString(MyString&& other) : mystr{ nullptr }, size{ 0 } {
    this->size = other.length();
    this->mystr = other.get();
    other.size = 0;
    other.mystr = nullptr;
}

size_t MyString::length() const {
    return this->size;
}

char* MyString::get() const {
    return this->mystr;
}

MyString MyString::operator+(const MyString& other) {
    if (other.get() == nullptr)
        return MyString(std::string(this->get()));
    return MyString(std::string(this->get()) + std::string(other.get()));
}

MyString MyString::operator-(const MyString& other) {
    std::string res(this->get());
    size_t i = 0;
    while (i < other.length()) {
        if (res.find(other.mystr[i]) != -1)
            res.erase(res.find(other.mystr[i]), 1);
        ++i;
    }
    return MyString(res);
}

MyString MyString::operator*(const size_t value) const {
    std::string res(this->get());
    for (size_t i = 0; i < value - 1; ++i) {
        res += std::string(this->mystr);
    }
    return MyString(res);
}

MyString MyString::operator=(const MyString& other) {
    this->size = other.length();
    if (this->mystr != nullptr)
        delete[] this->mystr;
    this->mystr = new char[size + 1];
    memset(this->mystr, 0, size + 1);
    memcpy(this->mystr, other.get(), this->size);
    return *this;
}

MyString& MyString::operator=(MyString&& other) {
    this->size = other.length();
    if (this->mystr != nullptr)
        delete this->mystr;
    this->mystr = other.get();
    other.size = 0;
    other.mystr = nullptr;
    return *this;
}

bool MyString::operator==(const MyString& other) {
    if (this->size != other.size)
        return false;
    if (!strcmp(this->mystr, other.mystr))
        return true;
    else
        return false;
}

bool MyString::operator!=(const MyString& other) {
    if (this->size != other.size)
        return true;
    return strcmp(this->mystr, other.mystr);
}

bool MyString::operator<(const MyString& other) {
    return (strcmp(this->mystr, other.mystr) == -1);
}

bool MyString::operator>(const MyString& other) {
    return (strcmp(this->mystr, other.mystr) == 1);
}

bool MyString::operator<=(const MyString& other) {
    return (strcmp(this->mystr, other.mystr) != -1);
}

bool MyString::operator>=(const MyString& other) {
    return (strcmp(this->mystr, other.mystr) != 1);
}

MyString MyString::operator!() {
    std::string result(this->get());
    for (size_t pos = 0; pos < result.length(); pos++) {
        char letter = result[pos];
        if ('a' <= letter && letter <= 'z')
            result[pos] -= 'a' - 'A';
        else if ('A' <= letter && letter <= 'Z')
            result[pos] += 'a' - 'A';
    }
    return MyString(result);
}

char& MyString::operator[](size_t i) const {
    if (i >= this->size)
        throw "Index is out of bounds!";
    return this->mystr[i];
}

int MyString::operator()(const char* substring) {
    char* ptr_substring = strstr(this->get(), substring);
    if (ptr_substring == nullptr) return -1;
    return ptr_substring - this->get();
}

std::ostream& operator<<(std::ostream& os, MyString& output) {
    return os << output.get();
}

std::istream& operator>>(std::istream& is, MyString& input) {
    return is >> input.get();
}