// Copyright 2020 Alexey Tatsenko
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include "MyString.h"

MyString::MyString() {
    this->stroka = nullptr;
}
MyString::MyString(const char* s) {
    this->stroka = nullptr;
    stroka = new char[strlen(s) + 1];
    for (int i = 0; i < strlen(s); i++)
        stroka[i] = s[i];
    stroka[strlen(s)] = '\0';
}
MyString::MyString(std::string s) {
    this->stroka = nullptr;
    stroka = new char[s.length() + 1];
    snprintf(stroka, s.length() + 1, "%s", s.c_str());
    stroka[s.length()] = '\0';
}
MyString::MyString(const MyString& s) {
    this->stroka = nullptr;
    stroka = new char[strlen(s.stroka) + 1];
    for (int i = 0; i < strlen(s.stroka); i++)
        stroka[i] = s.stroka[i];
    stroka[strlen(s.stroka)] = '\0';
}
MyString::MyString(MyString&& s) {
    this->stroka = nullptr;
    stroka = new char[strlen(s.stroka) +1];
    for (int i = 0; i < strlen(s.stroka); i++)
        stroka[i] = s.stroka[i];
    stroka[strlen(s.stroka)] = '\0';

    s.~MyString();
    s.stroka = nullptr;
}
MyString :: ~MyString() {
    delete[] stroka;
}
int MyString::length() {
    if (this->stroka == nullptr) 
        return 0;
    else
        return strlen(stroka);
}

char* MyString::get() {
    return this->stroka;
}

MyString MyString::operator+(const MyString& s) {
    char * str_new = new char[strlen(this->stroka) + strlen(s.stroka) + 1];
    int l = strlen(this->stroka) + strlen(s.stroka);

    int i = 0;
    int j = 0;
    while (i < l || j < l) {
        while (this->stroka[i] != '\0') {
            str_new[i] = stroka[i];
            i++;
        }
        while (s.stroka[i] != '\0') {
            str_new[i] = s.stroka[j];
            i++;
            j++;
        }
    }
    str_new[l] = '\0';
    return MyString(str_new);
}
MyString MyString::operator-(const MyString& s) {
    std::string x_array = std::string(s.stroka);
    std::string str_array = std::string(stroka);

    for(int i = 0; i < x_array.size(); i++)
        for (int j = 0; j < str_array.size(); j++) {
            if (str_array[j] == x_array[i]) str_array.erase(str_array.begin() + j);
        }
    return MyString(str_array);
}
MyString MyString::operator*(int n) {
    char* str_new = new char[strlen(this->stroka) * n + 1];
    int l = strlen(stroka) * n;

    int j = 0;
    for (int i = 0; i < l; i++) {
        if (j == strlen(stroka)) {
            j = 0;
        }
        str_new[i] = stroka[j];
        j++;
    }
    str_new[l] = '\0';
    return(MyString(str_new));
}
MyString MyString::operator=(const MyString& s) {
    stroka = new char[strlen(s.stroka) + 1];
    for (int i = 0; i < strlen(s.stroka); i++)
        stroka[i] = s.stroka[i];
    stroka[strlen(s.stroka)] = '\0';
    return *this;
}
MyString MyString::operator=(MyString&& s) {
    stroka = s.stroka;
    s.~MyString();
    s.stroka = nullptr;
    return *this;
}
bool MyString::operator==(const MyString& s) {
    return strcmp(this->stroka, s.stroka) == 0;
}
bool MyString::operator!=(const MyString& s) {
    return strcmp(stroka, s.stroka) != 0;
}

bool MyString::operator>(const MyString& s) {
    return strcmp(stroka, s.stroka) < 0;
}
bool MyString::operator<(const MyString& s) {
    return strcmp(stroka, s.stroka) > 0;
}
bool MyString::operator>=(const MyString& s) {
    return (strcmp(stroka, s.stroka) < 0 || strcmp(stroka, s.stroka) == 0);
}
bool MyString::operator<=(const MyString& s) {
    return (strcmp(stroka, s.stroka) > 0 || strcmp(stroka, s.stroka) == 0);
}


MyString MyString::operator!() {
    for (int i = 0; i < strlen(this->stroka); i++) {

        if (stroka[i] >= 'a' && stroka[i] <= 'z') {
            stroka[i] = toupper(stroka[i]);
            continue;
        }

        if (stroka[i] >= 'A' && stroka[i] <= 'Z') {
            stroka[i] = tolower(stroka[i]);
            continue;
        }

    }
    return MyString(stroka);
}
char MyString::operator[](int n) {
    return this->stroka[n];
}
int MyString::operator()(const char* s) {
    char* podstr = strstr(stroka, s);
    if (podstr == NULL) 
         return -1;
    else
         return (podstr - stroka);
}

std::ostream& operator<<(std::ostream &out, const MyString& s) {
    out <<  s.stroka;
    return out;
}

std::istream& operator>>(std::istream &in, MyString& s) {
    char* str = 0;
    in >> str;
    s.stroka = new char[strlen(str) + 1];
    for (int i = 0; i < strlen(s.stroka); i++)
        s.stroka[i] = str[i];
    s.stroka[strlen(str)] = '\0';
    delete[] str;
    str = nullptr;
    return in;
}
