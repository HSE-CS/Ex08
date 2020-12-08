// Copyright 2020 FOM
#include "MyString.h"

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
