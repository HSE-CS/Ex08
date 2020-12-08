// Copyright 2020 SharunovEvgenya
//
// Created by sharg on 08.12.2020.
//
#include "MyString.h"

char *MyString::get() const {
    return stringArray;
}

unsigned int MyString::length() const {
    return strlen(this->stringArray);
}

MyString::MyString(const char *valueSringArray) {
    if (valueSringArray != nullptr) {
        unsigned int len = strlen(valueSringArray) + 1;
        char *newStringArray = new char[len];
        snprintf(newStringArray, len, "%s", valueSringArray);
        this->stringArray = newStringArray;
    } else {
        char *newStringArray = new char[1];
        this->stringArray = newStringArray;
    }
}

MyString::MyString(const std::string &valueSringArray) {
    unsigned int len = valueSringArray.length() + 1;
    char *newStringArray = new char[len];
    snprintf(newStringArray, len, "%s", valueSringArray.c_str());
    this->stringArray = newStringArray;
}

MyString::MyString(const MyString &existString) {
    unsigned int len = existString.length() + 1;
    char *newStringArray = new char[len];
    snprintf(newStringArray, len, "%s", existString.stringArray);
    this->stringArray = newStringArray;
}

MyString::MyString(MyString &&existString) {
    stringArray = existString.stringArray;
    existString.stringArray = nullptr;
}

MyString::~MyString() {
    delete [] stringArray;
}

MyString MyString::operator+(const MyString &s) {
    unsigned int len = this->length();
    char *newStringArray = new char[len + s.length()];
    snprintf(newStringArray, len + 1, "%s", this->stringArray);
    snprintf(newStringArray + len, len + 1, "%s", s.stringArray);
    return MyString(newStringArray);
}


MyString MyString::operator-(const MyString &s) const {
    std::string str(this->get());
    unsigned int iter = 0;
    while (iter < s.length()) {
        while (str.find(s.stringArray[iter]) != -1)
            str.erase(str.find(s.stringArray[iter]), 1);
        iter++;
    }
    return MyString(str);
}

MyString MyString::operator*(unsigned int lenght) const {
    std::string endString;
    for (unsigned int iter = 0; iter < lenght; iter++) {
        endString.append(this->get());
    }
    return MyString(endString);
}

MyString &MyString::operator=(const MyString &existString) {
    this->stringArray = strdup(existString.stringArray);
    return *this;
}

MyString &MyString::operator=(MyString &&existString) {
    this->stringArray = strdup(existString.stringArray);
    existString.stringArray = nullptr;
    return *this;
}

bool MyString::operator==(const MyString &existString) const {
    return !strcmp(this->get(), existString.get());
}

bool MyString::operator!=(const MyString &existString) const {
    return strcmp(this->get(), existString.get());
}

bool MyString::operator>=(const MyString &existString) {
    return (strcmp(this->stringArray, existString.stringArray) > -1);
}

bool MyString::operator>(const MyString &existString) {
    return (strcmp(this->stringArray, existString.stringArray) == 1);
}

bool MyString::operator<=(const MyString &existString) {
    return (strcmp(this->stringArray, existString.stringArray) < 1);
}

bool MyString::operator<(const MyString &existString) {
    return (strcmp(this->stringArray, existString.stringArray) == -1);
}

MyString &MyString::operator!() {
    for (unsigned int iter = 0; iter < this->length(); iter++) {
        if (stringArray[iter] >= 'a' && stringArray[iter] <= 'z') {
            stringArray[iter] -= 32;
        }
    }
    return *this;
}

char &MyString::operator[](unsigned int number) const {
    if (number > this->length()) throw "Number out of range";
    return this->stringArray[number];
}

int MyString::operator()(const char *valueStringArray) const {
    char *pointerValueStringArray = strstr(this->get(), valueStringArray);
    if (pointerValueStringArray == nullptr) {
        return -1;
    } else {
        return pointerValueStringArray - this->get();
    }
}

std::ostream &operator<<(std::ostream &valueStream, MyString &valueString) {
    return valueStream << valueString.get();
}

std::istream &operator>>(std::istream &valueStream, MyString &valueString) {
    return valueStream >> valueString.get();
}





