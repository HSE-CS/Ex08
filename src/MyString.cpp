// Copyright 2020 Bulatov D.
#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"
#include <string.h>

MyString::MyString(const char* s) {
    if (s == nullptr) {
        len = 0;
        stroka = nullptr;
    } else {
        len = strlen(s);
        stroka = new char[len + 1];
        for (size_t i = 0; i <= len; i++) {
            stroka[i] = s[i];
        }
    }
}

MyString::MyString(std::string s) {
    len = s.size();
    stroka = new char[len + 1];
    for (size_t i = 0; i <= len; i++) {
        stroka[i] = s[i];
    }
}

MyString::MyString(const MyString& s) {
    this->len = s.len;
    this->stroka = new char[len + 1];
    for (size_t i = 0; i <= len; i++) {
        stroka[i] = s.stroka[i];
    }
}

MyString::MyString(const MyString&& s) {
    this->len = s.len;
    this->stroka = new char[s.len + 1];
    int i = 0;
    while (i < this->len) {
        this->stroka[i] = s.stroka[i];
        i++;
    }
    this->stroka[i] = '\0';
}

MyString::~MyString() {
    delete[] this->stroka;
    this->len = 0;
}

int MyString::length() {
    return this->len;
}

char* MyString::get() {
    return this->stroka;
}

MyString MyString::operator+(const MyString& s) {
    unsigned int len1 = this->length();
    unsigned int len2 = s.len + len1;
    char* new_str = new char[len2 + 1];
    int i = 0;
    for (i; i < len1; i++) {
        new_str[i] = this->stroka[i];
    }
    int j = 0;
    for (i; i < len2; i++) {
        new_str[i] = s.stroka[j];
        j++;
    }
    new_str[i] = '\0';
    MyString nstr(new_str);
    return nstr;
}

MyString MyString::operator-(const MyString& s) {
    std::string temp = (std::string(this->stroka));
    int i = 0;
    while (i < s.len) {
        while (temp.find(s.stroka[i]) != -1) {
            temp.erase(temp.find(s.stroka[i]), 1);
        }
        i++;
    }
    MyString new_str(temp);
    return new_str;
}

MyString MyString::operator*(const size_t n) {
    MyString ans(stroka);
    for (int i = 0; i < n - 1; i++) {
        ans = ans + *this;
    }
    return ans;
}

MyString& MyString::operator=(const MyString& s) {
    if (s.stroka == nullptr) {
        this->len = 0;
        this->stroka = nullptr;
        return *this;
    }
    this->len = s.len;
    stroka = new char[s.len + 1];
    for (size_t i = 0; i <= this->len; ++i) {
        this->stroka[i] = s.stroka[i];
    }
    return *this;
}

MyString& MyString::operator=(MyString&& s) {
    this->len = s.len;
    this->stroka = s.stroka;
    s.len = 0;
    s.stroka = nullptr;
    return *this;
}

bool MyString::operator==(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) == 0) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator!=(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) != 0) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator>(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) > 0) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator<(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) < 0) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator>=(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) >= 0) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator<=(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) <= 0) {
        return 1;
    } else {
        return 0;
    }
}

MyString MyString::operator!() {
    MyString temp(*this);
    for (size_t i = 0; i < temp.len; ++i) {
        if (temp.stroka[i] >= 'a' && temp.stroka[i] <= 'z') {
            temp.stroka[i] -= 'a' - 'A';
        } else if (temp.stroka[i] >= 'A' && temp.stroka[i] <= 'Z') {
            temp.stroka[i] += 'a' - 'A';
        }
    }
    return temp;
}

char MyString::operator[](int n) {
    return this->stroka[n];
}

int MyString::operator()(const char* s) {
    if (strstr(this->stroka, s) == NULL) {
        return -1;
    } else {
        return strstr(this->stroka, s) - this->stroka;
    }
}

std::ostream& operator>>(std::ostream& os, MyString& s) {
    return os << s.get();
}

std::istream& operator>>(std::istream& is, MyString& s) {
    return is >> s.get();
}
