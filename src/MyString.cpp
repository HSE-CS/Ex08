// Copyright 2020 dash
#include "MyString.h"
#include <string>

MyString::MyString(const char* first_str) {
    if (first_str == nullptr) {
        str = nullptr;
        len = 0;
    } else {
        len = strlen(first_str);
        str = new char[len + 1];
        snprintf(str, len + 1, "%s", first_str);
    }
}

MyString::MyString(std::string first_str) {
    len = first_str.size();
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = first_str[i];
    }
    str[len] = '\0';
}

MyString::MyString(const MyString& first_class) {
    len = first_class.len;
    str = new char[len + 1];
    snprintf(str, len + 1, "%s", first_class.str);
}

MyString::MyString(MyString&& second_class) {
    str = second_class.str;
    len = second_class.len;
    second_class.str = nullptr;
    second_class.len = 0;
}

MyString::~MyString() {
    delete str;
    len = 0;
}

size_t MyString::length() const {
    return len;
}

char* MyString::get() const {
    return str;
}

MyString MyString::operator+(const MyString& second_str) {
    size_t new_len = len + second_str.length();
    char* new_str = new char[new_len + 1];
    snprintf(new_str, len + 1, "%s", str);
    snprintf(new_str + len, second_str.length() + 1, "%s", second_str.get());
    return MyString(new_str);
}

MyString MyString::operator-(const MyString& string) {
    std::string new_str(str, len + str);
    for (int i = 0; i < string.len; i++) {
        new_str.erase(std::remove(new_str.begin(), new_str.end(), string[i]),
            new_str.end());
    }
    return MyString(new_str);
}

MyString MyString::operator*(const size_t count) {
    std::string new_str;
    for (int i = 0; i < count; i++) {
        new_str += std::string(str);
    }
    return MyString(new_str);
}

MyString &MyString::operator=(const MyString& string) {
    len = string.len;
    str = new char[len + 1];
    snprintf(str, len+1, "%s", string.str);
    return *this;
}

MyString &MyString::operator=(MyString&& string) {
    len = string.len;
    str = string.str;
    string.str = nullptr;
    string.len = 0;
    return *this;
}

bool MyString::operator==(const MyString& string) {
    if (strcmp(str, string.str) == 0) {
        return true;
    } else {
        return false;
    }
}

bool MyString::operator!=(const MyString& string) {
    if (strcmp(str, string.str) == 0) {
        return false;
    } else {
        return true;
    }
}

bool MyString::operator>(const MyString& string) {
    if (strcmp(str, string.str) > 0) {
        return true;
    } else {
        return false;
    }
}

bool MyString::operator<(const MyString& string) {
    if (strcmp(str, string.str) < 0) {
        return true;
    } else {
        return false;
    }
}

bool MyString::operator>=(const MyString& string) {
    if (strcmp(str, string.str) >= 0) {
        return true;
    } else {
        return false;
    }
}

bool MyString::operator<=(const MyString& string) {
    if (strcmp(str, string.str) <= 0) {
        return true;
    } else {
        return false;
    }
}

MyString MyString::operator!() {
    char* s_new = new char[len + 1];
    snprintf(s_new, len + 1, "%s", str);
    for (int i = 0; i < len; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            s_new += 32;
        } else {
            if (str[i] <= 'z' && str[i] >= 'a') {
                s_new[i] -= 32;
            }
        }
    }
    return MyString(s_new);
}

char& MyString::operator[](const size_t ind) const {
    return str[ind];
}

int MyString::operator()(const char* string) {
    char* point = strstr(str, string);
    if (point == nullptr) {
        return -1;
    } else {
        return point - str;
    }
}

std::ostream& operator<<(std::ostream& out, MyString& string) {
    return out << string.get();
}

std::istream& operator>>(std::istream& in, MyString& string) {
    return in >> string.get();
}
