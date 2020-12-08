//Copyright 2020 OsmanovIslam

#include <iostream>
#include <string>
#include <cstring>
#include "MyString.h"


int MyString::length(){
    return strlen(this->str);
}

char* MyString::get() const {
    return str;
}

MyString::MyString(const char* StrArr) {
    if (StrArr == nullptr) {
        str = new char[1];
        memset(str, 0, 1);
    }
    else {
        str = new char[strlen(StrArr) + 1];
        //snprintf(str, strlen(StrArr) + 1, "%s", StrArr);
        memcpy(str, StrArr, strlen(StrArr) + 1);
    }
}

MyString::MyString(std::string only_str) {
    str = strdup(only_str.c_str());
}

MyString::MyString(MyString&& only_str) {
    str = new char[strlen(only_str.str)];
    str = only_str.str;
    only_str.str = nullptr;
}

MyString::MyString(const MyString& val_str) {
    this->str = strdup(val_str.str);
}

MyString::~MyString() {
    delete[] str;
}

MyString MyString::operator+(const MyString& other_string) {
    std::string bufStr;
    bufStr.append(str);
    bufStr.append(other_string.str);
    return MyString(bufStr);
}

MyString& MyString::operator=(const MyString& other_string) {
    str = strdup(other_string.str);
    return *this;
}

MyString& MyString::operator=(MyString&& other_string) {
    str = other_string.str;
    other_string.str = nullptr;
    return *this;
}

MyString MyString::operator-(const MyString& other_string) {
    char* bufStr = new char(length());
    int size = 0;
    bool f;
    for (int i = 0; i < length(); i++){
        f = false;
        for (int k = 0; k < strlen(other_string.str); k++){
            if (str[i] == other_string.str[k])
                f = true;
        }
        if (f == false) {
            bufStr[size] = str[i];
            size++;
        }
    }
    return MyString(bufStr);
}

MyString MyString::operator*(const int num) {
    int bufSize = (length() * num) + 1;
    char* bufStr = new char[bufSize];
    int act_len = 0;
    for (int i = 0; i < num; i++){
        for (int k = 0; k < length(); k++) {
            bufStr[act_len] = str[k];
            act_len++;
        }
    }
    bufStr[act_len] = '\0';
    return MyString(bufStr);
}

bool MyString::operator==(const MyString& string) {
    return !strcmp(str, string.str);
}

bool MyString::operator!=(const MyString& string) {
    return strcmp(str, string.str);
}

bool MyString::operator<(const MyString& string) {
    return (strcmp(str, string.get()) == -1);
}

bool MyString::operator>(const MyString& string) {
    return (strcmp(str, string.get()) == 1);
}

bool MyString::operator>=(const MyString& string)
{
    return (strcmp(str, string.get()) != -1);
}

bool MyString::operator<=(const MyString& string)
{
    return strcmp(str, string.get()) != 1;
}

MyString MyString::operator!() {
    int size = length();
    char* bufStr = new char[size + 1];
    for (int k = 0; k < size; k++) {
        if (str[k] > 64 && str[k] < 91) {
            bufStr[k] = tolower(str[k]);
        }
        if (str[k] >= 97 && str[k] <= 122) {
            bufStr[k] = toupper(str[k]);
        }
    }

    return MyString(bufStr);
}

int MyString::operator()(const char* string) {
    std::string find_pod_str = str;
    return find_pod_str.find(string);
}
char MyString::operator[](unsigned int num) const {
    return str[num];
}

std::istream& operator>>(std::istream& input, MyString& only_string) {
    int size = input.gcount() + 1;
    std::string bufString;
    std::getline(input, bufString);
    only_string = MyString(bufString);
    return input;
}

std::ostream& operator<<(std::ostream& output, MyString& only_string) {
    return output << only_string.get();
}
