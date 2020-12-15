// Copyright 10.12.20 KostinAndrej
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

MyString::MyString(const char *String) {
    if (String != nullptr) {
        char *newString = new char[strlen(String)];
        strcpy(newString, String);
        this->lenofstr = newString;
    } else {
        char *newString = new char[0];
        this->lenofstr = newString;
    }
}
MyString::MyString(const std::string &String) {
    char *newString = new char[String.length()];
    strcpy(newString, String.c_str());
    this->lenofstr = newString;
}
MyString::MyString(const MyString &existString) {
    char *newString = new char[existString.length()];
    strcpy(newString, existString.get());
    this->lenofstr = newString;
}
MyString::MyString(MyString &&existString) {
    char *newString = new char[existString.length()];
    strcpy(newString, existString.get());
    this->lenofstr = newString;
    existString.lenofstr = nullptr;
}
MyString::~MyString() {
    delete this->lenofstr;
}

char *MyString::get() const {
    return lenofstr;
}
unsigned int MyString::length() const {
    return strlen(this->lenofstr);
}

MyString MyString::operator+(const MyString &String) const {
    std::string tempString = std::string(this->get()) + std::string(String.get());
    return MyString(tempString);
}
MyString MyString::operator-(const MyString &String) const {
    std::string endString(this->get());
    unsigned int iter = 0;
    while (iter < String.length()) {
        while (endString.find(String.lenofstr[iter]) != -1) {
            endString.erase(endString.find(String.lenofstr[iter]), 1);
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
    delete this->lenofstr;
    this->lenofstr = existString.lenofstr;
    return *this;
}
MyString &MyString::operator=(MyString &&existString) {
    delete lenofstr;
    this->lenofstr = existString.lenofstr;
    existString.lenofstr = nullptr;
    return *this;
}
MyString &MyString::operator!() {
    for (unsigned int iter = 0; iter < this->length(); iter++) {
        if (lenofstr[iter] >= 'a' && lenofstr[iter] <= 'z') {
            lenofstr[iter] -= 32;
        }
    }
    return *this;
}

bool MyString::operator==(const MyString &existString) const {
    return !strcmp(this->get(), existString.get());
}

bool MyString::operator!=(const MyString &existString) const {
    return strcmp(this->get(), existString.get());
}
bool MyString::operator>(const MyString &existString) {
    return (strcmp(this->lenofstr, existString.lenofstr) == 1);
}
bool MyString::operator<(const MyString &existString) {
    return (strcmp(this->lenofstr, existString.lenofstr) == -1);
}
bool MyString::operator>=(const MyString &existString) {
    return (strcmp(this->lenofstr, existString.lenofstr) > -1);
}
bool MyString::operator<=(const MyString &existString) {
    return (strcmp(this->lenofstr, existString.lenofstr) < 1);
}

char &MyString::operator[](unsigned int number) const {
    if (number > this->length()) throw "Number out of range!";
    return this->lenofstr[number];
}
long MyString::operator()(const char *String) const {
    char *pointerString = strstr(this->get(), String);
    if (pointerString == nullptr) {
        return -1;
    } else {
        return pointerString - this->get();
    }
}
std::ostream &operator<<(std::ostream &valueStream, MyString &valueString) {
    return valueStream << valueString.get();
}
std::istream &operator>>(std::istream &valueStream, MyString &valueString) {
    return valueStream >> valueString.get();
}
