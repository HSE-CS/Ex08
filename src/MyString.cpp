// Copyright 2020 Dolgopolov Alexey
//
// Created by sharg on 09.12.2020.
//
#include "MyString.h"

char *MyString::get() const {
    return ArrString;
}

unsigned int MyString::length() const {
    return strlen(this->ArrString);
}

MyString::MyString(const char *valueArrString) {
    if (valueArrString != nullptr) {
        unsigned int leng = strlen(valueArrString) + 1;
        char *ArrStringNew = new char[leng];
        snprintf(ArrStringNew, leng, "%s", valueArrString);
        this->ArrString = ArrStringNew;
    } else {
        char *ArrStringNew = new char[1];
        this->ArrString = ArrStringNew;
    }
}

MyString::MyString(const std::string &valueArrString) {
    unsigned int leng = valueArrString.length() + 1;
    char *newArrString = new char[leng];
    snprintf(newArrString, leng, "%s", valueArrString.c_str());
    this->ArrString = newArrString;
}

MyString::MyString(const MyString &existStr) {
    unsigned int leng = existStr.length() + 1;
    char *newArrString = new char[leng];
    snprintf(newArrString, leng, "%s", existStr.ArrString);
    this->ArrString = newArrString;
}

MyString::MyString(MyString &&existStr) {
    ArrString = existStr.ArrString;
    existStr.ArrString = nullptr;
}

MyString::~MyString() {
    delete [] ArrString;
}

MyString MyString::operator+(const MyString &s) {
    unsigned int leng = this->length();
    char *ArrStringNew = new char[leng + s.length()];
    snprintf(ArrStringNew, leng + 1, "%s", this->ArrString);
    snprintf(ArrStringNew + leng, leng + 1, "%s", s.ArrString);
    return MyString(ArrStringNew);
}


MyString MyString::operator-(const MyString &Str) const {
    std::string strin(this->get());
    unsigned int iteration = 0;
    while (iteration < Str.length()) {
        while (strin.find(Str.ArrString[iteration]) != -1)
            strin.erase(strin.find(Str.ArrString[iteration]), 1);
        iteration++;
    }
    return MyString(strin);
}

MyString MyString::operator*(unsigned int leng) const {
    std::string endStr;
    for (unsigned int iteration = 0; iteration < leng; iteration++) {
        endStr.append(this->get());
    }
    return MyString(endStr);
}

MyString &MyString::operator=(const MyString &existStr) {
    this->ArrString = strdup(existStr.ArrString);
    return *this;
}

MyString &MyString::operator=(MyString &&existStr) {
    if (this->ArrString != nullptr) {
        delete this->ArrString;
    }
    this->ArrString = existStr.get();
    existStr.ArrString = nullptr;
    return *this;
}

bool MyString::operator==(const MyString &existStr) const {
    return !strcmp(this->get(), existStr.get());
}

bool MyString::operator!=(const MyString &existStr) const {
    return strcmp(this->get(), existStr.get());
}

bool MyString::operator>=(const MyString &existStr) {
    return (strcmp(this->ArrString, existStr.ArrString) > -1);
}

bool MyString::operator>(const MyString &existStr) {
    return (strcmp(this->ArrString, existStr.ArrString) == 1);
}

bool MyString::operator<=(const MyString &existStr) {
    return (strcmp(this->ArrString, existStr.ArrString) < 1);
}

bool MyString::operator<(const MyString &existStr) {
    return (strcmp(this->ArrString, existStr.ArrString) == -1);
}

MyString &MyString::operator!() {
    for (unsigned int iteration = 0; iteration < this->length(); iteration++) {
        if (ArrString[iteration] >= 'a' && ArrString[iteration] <= 'z') {
            ArrString[iteration] -= 32;
        }
    }
    return *this;
}

char &MyString::operator[](unsigned int number) const {
    if (number > this->length()) throw "Number out of range";
    return this->ArrString[number];
}

int MyString::operator()(const char *valueArrString) const {
    char *pointerValueArrString = strstr(this->get(), valueArrString);
    if (pointerValueArrString == nullptr) {
        return -1;
    } else {
        return pointerValueArrString - this->get();
    }
}

std::ostream &operator<<(std::ostream &valueStream, MyString &valueString) {
    return valueStream << valueString.get();
}

std::istream &operator>>(std::istream &valueStream, MyString &valueString) {
    return valueStream >> valueString.get();
}





