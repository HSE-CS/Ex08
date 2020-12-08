// Copyright 2020 Bulatov D.
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

std::MyString(const char* s) {
    if (s ==nullptr) {
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

std::MyString(std::string s) {
    len = s.size();
    stroka = new char[len + 1];
    for (size_t i = 0; i <= len; i++) {
        stroka[i] = s[i];
    }
}

std::MyString(const MyString& s) {
    this->len = s.len;
    this->stroka = new char[len + 1];
    for (size_t i = 0; i <= len; i++) {
        stroka[i] = s.stroka[i];
    }
}

std::MyString(MyString&& s) {
    this->len = s.len;
    this->stroka = s.stroka;
    s.len = 0;
    s.stroka = nullptr;
}

std::~MyString() {
    delete[] this->stroka;
    this->len = 0;
}

std::int MyString::length() {
    return this->len;
}

std::char* MyString::get() {
    return this->str;
}

std::MyString::operator+(const MyString& s) {
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

std::MyString::operator-(const MyString& s) {
    std::string temp = (std::string(this->str));
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

std::MyString::operator*(int n) {
    char* new_str = new char[len * n + 1];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i * len; j < (i + 1) * len; ++j) {
            new_str[j] = stroka[j - i * len];
        }
    }
    new_str[len * n] = '\0';
    MyString tmp(new_str);
    return tmp;
}

std::MyString::operator=(const MyString& s) {
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

std::MyString::operator=(MyString&& s) {
    this->len = s.len;
    this->stroka = s.stroka;
    s.len = 0;
    s.stroka = nullptr;
    return *this;
}

std::bool operator==(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) == 0) {
        return 1;
    } else {
        return 0;
    }
}

std::bool operator!=(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) != 0) {
        return 1;
    } else {
        return 0;
    }
}

std::bool operator>(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) > 0) {
        return 1;
    } else {
        return 0;
    }
}

std::bool operator<(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) < 0) {
        return 1;
    } else {
        return 0;
    }
}

std::bool operator>=(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) >= 0) {
        return 1;
    } else {
        return 0;
    }
}

std::bool operator<=(const MyString& s) {
    if (strcmp(this->stroka, s.stroka) <=0) {
        return 1;
    } else {
        return 0;
    }
}

std::MyString::operator!() {
    MyString temp(*this);
    for (size_t i = 0; i < temp.len; ++i) {
        if (temp.stroka[i] >= 'a' && temp.stroka[i] <= 'z') {
            temp.str[i] -= 'a' - 'A';
        } else if (temp.stroka[i] >= 'A' && temp.stroka[i] <= 'Z') {
            temp.stroka[i] += 'a' - 'A';
        }
    }
    return temp;
}

std::char MyString::operator[](int n) {
    return this->stroka[n];
}

std::int operator()(const char* s) {
    if (strstr(this->stroka, s) == NULL) {
        return -1;
    } else {
        return strstr(this->str, s) - this->stroka;
    }
}

std::ostream& operator>>(std::ostream& os, MyString& s) {
    return os << s.get();
}

std::istream& operator>>(std::istream& is, MyString& s) {
    return is >> s.get();
}
