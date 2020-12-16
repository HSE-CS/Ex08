// Copyright 10.12.20 KostinAndrej
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
MyString::MyString(const char *String) {
    if (String != nullptr) {
        unsigned int len = strlen(String) + 1;
        char *newString = new char[strlen(String)];
        snprintf(newString,len, "%s", String);
        this->string_array = newString;
    } else {
        this->string_array = new char[1];
        memset(string_array, 0, 1);
    }
}
MyString::MyString(const std::string &String) {
    unsigned int len = String.length() + 1;
    char *newString = new char[len];
    snprintf(newString, len, "%s", String.c_str());
    this->string_array = newString;
}
MyString::MyString(const MyString &existString) {
    char *newString = new char[existString.length()];
    snprintf(newString,existString.length()+1,"%s", existString.string_array);
    this->string_array = newString;
}
MyString::MyString(MyString &&existString) {
    string_array = existString.string_array;
    existString.string_array = nullptr;
}
MyString::~MyString() {
    delete this->string_array;
}

char *MyString::get() const {
    return string_array;
}
unsigned int MyString::length() const {
    return strlen(this->string_array);
}

MyString MyString::operator+(const MyString &String) const {
    unsigned int len = this->length();
    char *newString = new char[len + String.length()];
    snprintf(newString, len + 1, "%s", this->string_array);
    snprintf(newString + len, len + 1, "%s", String.string_array);
    return MyString(newString);
}
MyString MyString::operator-(const MyString &String) const {
    std::string endString(this->get());
    unsigned int iter = 0;
    while (iter < String.length()) {
        while (endString.find(String.string_array[iter]) != -1) {
            endString.erase(endString.find(String.string_array[iter]), 1);
        }
        iter++;
    }
    return MyString(endString);
}
MyString MyString::operator*(unsigned int lenght) const {
    std::string endString;
    for (unsigned int iter = 0; iter < lenght; iter++) {
        endString.append(this->get());
    }
    return MyString(endString);
}
MyString &MyString::operator=(const MyString &existString) {
    delete this->string_array;
    this->string_array = existString.string_array;
    return *this;
}
MyString &MyString::operator=(MyString &&existString) {
    delete string_array;
    this->string_array = existString.string_array;
    existString.string_array = nullptr;
    return *this;
}
MyString MyString::operator!() {
    std::string res(this->get());
    for (unsigned int  iter = 0;  iter < res.length();  iter++) {
        char per = res[ iter];
        if ('a' <= per && per <= 'z')
            res[ iter] -= 32;
        else if ('A' <= per && per <= 'Z')
            res[ iter] += 32;
    }
    return MyString(res);
}

bool MyString::operator==(const MyString &existString) const {
    return !strcmp(this->get(), existString.get());
}

bool MyString::operator!=(const MyString &existString) const {
    return strcmp(this->get(), existString.get());
}
bool MyString::operator>(const MyString &existString) {
    return (strcmp(this->string_array, existString.string_array) == 1);
}
bool MyString::operator<(const MyString &existString) {
    return (strcmp(this->string_array, existString.string_array) == -1);
}
bool MyString::operator>=(const MyString &existString) {
    return (strcmp(this->string_array, existString.string_array) > -1);
}
bool MyString::operator<=(const MyString &existString) {
    return (strcmp(this->string_array, existString.string_array) < 1);
}

char &MyString::operator[](unsigned int number) const {
    if (number > this->length()) throw "Number out of range!";
    return this->string_array[number];
}
int MyString::operator()(const char *String) const {
    char *pointerString = strstr(this->get(), String);
    if (pointerString == nullptr) {
        return -1;
    } else {
        return pointerString - this->get();
    }
}
std::ostream &operator<<(std::ostream &valueStr, MyString &valueString) {
    return valueStr << valueString.get();
}
std::istream &operator>>(std::istream &valueStr, MyString &valueString) {
    return valueStr >> valueString.get();
}
