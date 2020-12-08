// Copyright 2020 Nikita Stifeev
#include "MyString.h"

MyString::MyString(const char* str) {
    if (str == nullptr) {
        size = 0;
        capacity = 0;
        chars = new char[1];
        chars[0] = '\0';
        return;
    }
    size = 0;
    while (str[size])
        size++;
    capacity = size;
    chars = new char[size + 1];
    for (size_t i = 0; i <= size; i++)
        chars[i] = str[i];
}

MyString::MyString(const std::string& str) {
    size = str.length();
    capacity = size;
    chars = new char[size + 1];
    for (size_t i = 0; i < size; i++)
        chars[i] = str[i];
    chars[size] = '\0';
}

MyString::MyString(const MyString& str) {
    size = str.size;
    capacity = str.capacity;
    chars = new char[capacity + 1];
    for (size_t i = 0; i <= size; i++)
        chars[i] = str.chars[i];
}

MyString::MyString(MyString&& str) {
    size = str.size;
    capacity = str.capacity;
    chars = std::move(str.chars);
}

MyString& MyString::operator=(const MyString& str) {
    if (this == &str)
        return *this;
    delete[] chars;
    size = str.size;
    capacity = str.capacity;
    chars = new char[capacity + 1];
    for (size_t i = 0; i <= size; i++)
        chars[i] = str.chars[i];
    return *this;
}

MyString& MyString::operator=(MyString&& str) {
    if (this == &str)
        return *this;
    delete[] chars;
    size = str.size;
    capacity = str.capacity;
    chars = str.chars;
    str.chars = nullptr;
    return *this;
}

MyString& MyString::operator+=(char c) {
    if (size >= capacity) {
        capacity = capacity ? capacity * 2 : 1;
        char* tmp = new char[capacity + 1];
        for (size_t i = 0; i < size; i++)
            tmp[i] = chars[i];
        delete[] chars;
        chars = tmp;
    }
    chars[size++] = c;
    chars[size] = '\0';
    return *this;
}

size_t MyString::length() const {
    return size;
}

char* MyString::get() const {
    return chars;
}

MyString MyString::operator+(const MyString& str) const {
    MyString result;
    for (size_t i = 0; i < size; i++)
        result += chars[i];
    for (size_t i = 0; i < str.size; i++)
        result += str.chars[i];
    return result;
}

MyString MyString::operator-(const MyString& str) const {
    MyString result;
    for (size_t i = 0; i < size; i++) {
        size_t j = 0;
        while (j < str.size && str.chars[j] != chars[i])
            j++;
        if (j == str.size)
            result += chars[i];
    }
    return result;
}

MyString MyString::operator*(int count) const {
    MyString result;
    for (int i = 0; i < count; i++)
        for (int j = 0; j < size; j++)
            result += chars[j];
    return result;
}

bool MyString::operator==(const MyString& str) const {
    if (size != str.size)
        return false;
    for (size_t i = 0; i < size; i++)
        if (chars[i] != str.chars[i])
            return false;
    return true;
}

bool MyString::operator!=(const MyString& str) const {
    return !(*this == str);
}

bool MyString::operator>(const MyString& str) const {
    for (size_t i = 0; i <= size && i <= str.size; i++)
        if (chars[i] != str.chars[i])
            return chars[i] > str.chars[i];
    return false;
}

bool MyString::operator<(const MyString& str) const {
    for (size_t i = 0; i <= size && i <= str.size; i++)
        if (chars[i] != str.chars[i])
            return chars[i] < str.chars[i];
    return false;
}

bool MyString::operator>=(const MyString& str) const {
    return *this > str || *this == str;
}

bool MyString::operator<=(const MyString& str) const {
    return *this < str || *this == str;
}

MyString MyString::operator!() const {
    MyString result(*this);
    for (size_t i = 0; i < size; i++) {
        if (chars[i] >= 'A' && chars[i] <= 'Z') {
            result.chars[i] += 'a' - 'A';
        }
        else if (chars[i] >= 'a' && chars[i] <= 'z') {
            result.chars[i] += 'A' - 'a';
        }
    }
    return result;
}

char MyString::operator[](int index) const {
    return chars[index];
}

char& MyString::operator[](int index) {
    return chars[index];
}

int MyString::operator()(const MyString& str) const {
    if (str.size > size)
        return -1;
    for (size_t i = 0; i < size; i++) {
        size_t j = 0;
        while (i < size && j < str.size && chars[i + j] == str.chars[j])
            j++;
        if (j == str.size)
            return i;
    }
    return -1;
}

MyString::~MyString() {
    delete[] chars;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    str.size = 0;
    str.chars[0] = '\0';
    for (char c = is.get(); c != EOF && c != '\n'; c = is.get())
        str += c;
    return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    return os << str.chars;
}
