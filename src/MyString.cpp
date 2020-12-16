// Copyright 10.12.20 KostinAndrej
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

MyString::MyString(const char *String) {
    if (String != nullptr) {
        char *newString = new char[strlen(String)];
        strcpy(newString, String);
        this->string_array = newString;
    } else {
        this->string_array = new char[1];
        memset(string_array, 0, 1);
    }
}
MyString::MyString(const std::string &String) {
    char *newString = new char[String.length()];
    strcpy(newString, String.c_str());
    this->string_array = newString;
}
MyString::MyString(const MyString &existString) {
    char *newString = new char[existString.length()];
    strcpy(newString, existString.get());
    this->string_array = newString;
}
MyString::MyString(MyString &&existString) {
    char *newString = new char[existString.length()];
    strcpy(newString, existString.get());
    this->string_array = newString;
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
    std::string tempString = std::string(this->get()) + std::string(String.get());
    return MyString(tempString);
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
//MyString &MyString::operator!() {
//    for (unsigned int iter = 0; iter < this->length(); iter++) {
//        if (string_array[iter] >= 'a' && string_array[iter] <= 'z') {
//            string_array[iter] -= 32;
//        }
//    }
//    return *this;
//}

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
