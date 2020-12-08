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
        char *newStringArray = new char[strlen(valueSringArray)];
        strcpy(newStringArray, valueSringArray);
        this->stringArray = newStringArray;
    } else {
        char *newStringArray = new char[0];
        this->stringArray = newStringArray;
    }
}

MyString::MyString(const std::string &valueSringArray) {
    char *newStringArray = new char[valueSringArray.length()];
    strcpy(newStringArray, valueSringArray.c_str());
    this->stringArray = newStringArray;
}

MyString::MyString(const MyString &existString) {
    char *newStringArray = new char[existString.length()];
    strcpy(newStringArray, existString.get());
    this->stringArray = newStringArray;
}

MyString::MyString(MyString &&existString) {
    char *newStringArray = new char[existString.length()];
    strcpy(newStringArray, existString.get());
    this->stringArray = newStringArray;
    existString.stringArray = nullptr;
}

MyString::~MyString() {
    delete this->stringArray;
}

MyString MyString::operator+(const MyString &valueSringArray) const {
    std::string sec=valueSringArray.get();
    std::string tempString = (std::string(this->get()) +sec);
    return MyString(tempString);
}


MyString MyString::operator-(const MyString &valueSringArray) const {
    std::string endString(this->get());
    unsigned int iter = 0;
    while (iter < valueSringArray.length()) {
        while (endString.find(valueSringArray.stringArray[iter]) != -1) {
            int p=endString.find(valueSringArray.stringArray[iter]);
            endString.erase(p, 1);
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
    delete this->stringArray;
    this->stringArray = existString.stringArray;
    return *this;
}

MyString &MyString::operator=(MyString &&existString) {
    delete stringArray;
    this->stringArray = existString.stringArray;
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





