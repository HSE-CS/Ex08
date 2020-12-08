// Copyright 2020 FOM

#include "MyString.h"
#include <iostream>

MyString::MyString() {
    string = nullptr;
    lenght = 0;
}

MyString::MyString(const char* str) {
    if (str != nullptr) {
        lenght = strlen(str);
        str = new char[lenght + 1];
        snprintf(string, lenght + 1, "%s", str);
    }
    else {
        string = nullptr;
        lenght = 0;
    }
}

MyString::MyString(std::string str) {
    lenght = str.size();
    string = new char[lenght + 1];
    snprintf(string, lenght + 1, "%s", str.c_str());
}

MyString::MyString(const MyString& str) {
    lenght = str.lenght;
    string = new char[str.lenght + 1];
    for (int i = 0; i < lenght; i++) {
        string[i] = str.string[i];
    }
    string[lenght] = '\0';
}

MyString::MyString(MyString&& str) {
    lenght = str.lenght;
    string = new char[str.lenght + 1];
    for (int i = 0; i < lenght; i++) {
        string[i] = str.string[i];
    }
    string[lenght] = '\0';
    str.~MyString();
}

MyString::~MyString() {
    delete[]string;
}

unsigned int MyString::length() {
    return strlen(this->string);
}

char* MyString::get() {
    return string;
}

MyString MyString::operator+(const MyString& str) {
    MyString new_string;
    new_string.lenght = lenght + str.lenght;
    new_string.string = new char[new_string.lenght + 1];
    for (int i = 0; i < lenght; i++) {
        new_string.string[i] = string[i];
    }
    if (str.string != nullptr) {
        for (int i = 0; i < str.lenght; i++) {
            new_string.string[i + lenght] = str.string[i];
        }
    }
    new_string.string[new_string.lenght] = '\0';
    return new_string;
}

MyString MyString::operator-(const MyString& str) {
    std::string new_string;
    for (int i = 0; i <= strlen(string); i++) {
        bool check = true;
        for (int j = 0; j < strlen(str.string); j++) {
            if (string[i] == str.string[j])
                check = false;
        }
        if (check)
            new_string += string[i];
        
    }
    return MyString(new_string);
}

MyString MyString::operator*(const int num) {
    std::string str;
    for (int i = 0; i < num; i++)
        str += get();
    return MyString(str);
}

MyString& MyString::operator=(const MyString& str) {
    string = str.string;
    return *this;
}

MyString& MyString::operator=(MyString&& str) {
    string = str.string;
    str.string = nullptr;
    return *this;
}

bool MyString::operator== (const MyString& str) {
    if (strcmp(string, str.string) != 0)
        return false;
    else
        return true;
}

bool MyString::operator!= (const MyString& str) {
    if (strcmp(string, str.string) == 0)
        return false;
    else
        return true;
}

bool MyString::operator> (const MyString& str) {
    if (strcmp(string, str.string) != 1)
        return false;
    else
        return true;
}

bool MyString::operator< (const MyString& str) {
    if (strcmp(string, str.string) != -1)
        return false;
    else
        return true;
}

bool MyString::operator>= (const MyString& str) {
    if (strcmp(string, str.string) == -1)
        return false;
    else
        return true;
}

bool MyString::operator<= (const MyString& str) {
    if (strcmp(string, str.string) == 1)
        return false;
    else
        return true;
}

MyString MyString::operator!() {
    MyString result(*this);
    for (int i = 0; i < result.lenght; i++) {
        if ((result.string[i] >= 'a') && (result.string[i] <= 'z'))
            result.string[i] -= 'a' - 'A';
        else
            if ((result.string[i] >= 'A') && (result.string[i] <= 'Z'))
                result.string[i] += 'a' - 'A';
    }
    return result;
}

char& MyString::operator[](int i) {
    return string[i];
}

int MyString::operator()(const char* str) {
    char* pstr = strstr(get(), str);
    int result = 0;
    if (pstr != nullptr) {
        result = pstr - get();
        return result;
    } else
        return -1;
}

std::ostream& operator<<(std::ostream& s, MyString& str) {
    return s << str.get();
}

std::istream& operator>>(std::istream& s, MyString& str) {
    return s >> str.get();
}
