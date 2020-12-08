// Copyright 2020 JGMax

#include "MyString.h"


char *MyString::get() {
    return str;
}

int MyString::length() {
    return size;
}

MyString MyString::operator+(const MyString &obj) {
    return MyString(std::string(this->str) + std::string(obj.str));
}

MyString MyString::operator-(const MyString &obj) {
    int idx;
    std::string str = this->str;
    for (int i = 0; i < obj.size; i++) {
        idx = str.find(obj[i]);
        while (idx >= 0) {
            str.erase(idx, 1);
            idx = str.find(obj[i]);
        }
    }
    return MyString(str);
}

MyString MyString::operator*(const unsigned int n) {
    std::string sum;
    for (int i = 0; i < n; i++)
        sum += str;
    return MyString(sum);
}

MyString &MyString::operator=(const MyString &obj) {
    delete str;
    size = obj.size;
    str = new char[size];
    strcpy(str, obj.str);
    return *this;
}

MyString &MyString::operator=(MyString &&obj) noexcept {
    delete str;
    size = obj.size;
    str = obj.str;
    obj.str = nullptr;
    obj.size = 0;
    return *this;
}

bool MyString::operator==(const MyString &obj) const {
    std::string a = str;
    std::string b = obj.str;
    return a == b;
}

bool MyString::operator!=(const MyString &obj) const {
    std::string a = str;
    std::string b = obj.str;
    return a != b;
}

bool MyString::operator>=(const MyString &obj) const {
    std::string a = str;
    std::string b = obj.str;
    return a >= b;
}

bool MyString::operator<=(const MyString &obj) const {
    std::string a = str;
    std::string b = obj.str;
    return a <= b;
}

bool MyString::operator>(const MyString &obj) const {
    std::string a = str;
    std::string b = obj.str;
    return a > b;
}

bool MyString::operator<(const MyString &obj) const {
    std::string a = str;
    std::string b = obj.str;
    return a < b;
}

MyString MyString::operator!() {
    for (int i = 0; i < size; i++) {
        str[i] = std::isupper(str[i]) ? std::tolower(str[i]) : std::toupper(str[i]);
    }
    return *this;
}

char &MyString::operator[](int i) const {
    if (i >= 0 && i < size)
        return str[i];
    else if (i < 0 && i >= -size)
        return str[size + i];
    else
        throw "Index out of range";
}

int MyString::operator()(const char *p_str) {
    return strstr(str, p_str) - str;
}

std::ostream &operator<<(std::ostream &stream, MyString &obj) {
    return stream << obj.str;
}

std::istream &operator>>(std::istream &stream, MyString &obj) {
    return stream >> obj.str;
}
