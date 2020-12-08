// Copyright 2020 Tyulin Igor
#include "MyString.h"

MyString::MyString(const char* p) {
    if (p != nullptr) {
        len = strlen(p);
        str = new char[len + 1];
        for (size_t i = 0; i <= len; i++)
            str[i] = p[i];
    }
    else{
        len = 0;
        str = nullptr;
    }
}

MyString::MyString(std::string p) {
    len = p.size();
    str = new char[len + 1];
    for(size_t i = 0; i <= len; i++)
        str[i] = p[i];
}

MyString::MyString(const MyString& p) {
    str = strdup(p.str);
    len = p.len;
}

MyString::MyString(MyString&& p) {
    str = strdup(p.str);
    len = p.len;
}

MyString::~MyString() {
    delete[]str;
}

size_t MyString::length() const {
    return len;
}

char* MyString::get() const {
    return str;
}

MyString MyString::operator+(const MyString& val) {
    std::string sum = std::string(this->get()) + std::string(val.get());
    return MyString(sum);
}

MyString MyString::operator-(const MyString & val) {
    std::string newstr;
    for (int i = 0; i <= strlen(str); i++) {
        bool check = true;
        for (int j = 0; j < strlen(val.str); j++) {
            if (str[i] == val.str[j])
                check = false;
        }
        if (check)
            newstr += str[i];
    }
    return MyString(newstr);
}

MyString MyString::operator*(int n) {
    std::string newstr;
    for (int i = 0; i < n; i++)
        newstr += get();
    return MyString(newstr);
}

MyString& MyString::operator=(const MyString& val) {
    str = val.str;
    return *this;
}

MyString& MyString::operator=(MyString&& val) {
    str = val.str;
    val.str = nullptr;
    return *this;
}

bool MyString::operator==(const MyString & p) {
    return !strcmp(str, p.get());
}

bool MyString::operator!=(const MyString & p) {
    return strcmp(str, p.get());
}

bool MyString::operator>(const MyString & p) {
   return(strcmp(str, p.get()) == 1);
}

bool MyString::operator<(const MyString & p) {
    return(strcmp(str, p.get()) == -1);
}

bool MyString::operator>=(const MyString & p) {
    return(strcmp(str, p.get()) != -1);
}

bool MyString::operator<=(const MyString & p) {
    return(strcmp(str, p.get()) != 1);
}

MyString MyString::operator!() {
    std::string res(this->get());
    for (size_t i = 0; i < res.length(); i++) {
        char per = res[i];
        if ('a' <= per && per <= 'z')
            res[i] -= 'a' - 'A';
        else if ('A' <= per && per <= 'Z')
            res[i] += 'a' - 'A';
    }
    return MyString(res);
}

char& MyString::operator[](int i) {
    return str[i];
}

int MyString::operator()(const char* p) {
    char* per = strstr(str, p);
    if (per == nullptr)
        return -1;
    else
        return (str - per);
}

std::ostream& operator<<(std::ostream& p, MyString& n) {
    return p << n.get();
}

std::istream& operator>>(std::istream& p, MyString& n) {
    return p >> n.get();
}