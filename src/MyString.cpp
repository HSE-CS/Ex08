// Copyright 2020 sccc
#include "MyString.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>



int MyString :: length() {
  return size;
}

MyString::MyString() {
    size = 0;
    string = nullptr;
}

MyString::MyString(const char* str) {
    size = strlen(str);
    string =  new char[size + 1];
    snprintf(string, size+1, "%s\n", str);
}

MyString::MyString(std :: string str) {
    size = str.length();
    string = new char[size + 1];
    snprintf(string, size+1, "%s\n", str.c_str());
}

MyString::MyString(const MyString& str) {
    size = str.size;
    string = new char[size + 1];
    snprintf(string, str.size+1, "%s\n", str.string);
}
MyString::MyString(MyString&& str) {
    size = str.length();
    string = new char[size + 1];
    snprintf(string, str.size+1, "%s\n", str.string);
    str.size = 0;
    str.string = nullptr;
}

MyString::~MyString() {
    delete[] string;
}



char * MyString :: get() {
    return string;
}

MyString MyString::operator+(const MyString& str) {
    MyString result;
    result.size = size + str.size;
    result.string = result.string = new char[result.size + 1];
    for (int i = 0; i < size; i++) {
        result.string[i] = string[i];
    }
    for (int i = 0; i < str.size; i++) {
        result.string[i+size-1] = str.string[i];
    }
    return result;
}

MyString MyString::operator-(const MyString&str) {
    MyString result;
    result.size = size;
    result.string = result.string = new char[result.size + 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (strchr(str.string, string[i]) == nullptr) {
            result.string[j] = string[i];
            j++;
        }
    }
    return result;
}

MyString MyString::operator*(int n) {
    char * temp = new char[n*size + 1];
    int pointer = 0;
    for (int i = 0; i < n; i++) {
     for (int j = 0; j < size; j++) {
          temp[pointer] = string[j];
          pointer++;
     }
    }
    temp[pointer] = '\0';
    return MyString(temp);
}

bool MyString::operator==(const MyString& str) {
    if (size != str.size)
        return false;
    for (int i = 0; i < size; i++) {
        if (string[i] != str.string[i])
            return false;
    }
    return true;
}

bool MyString::operator!=(const MyString& str) {
    if (size != str.size)
        return true;
    for (int i = 0; i < size; i++) {
        if (string[i] != str.string[i])
            return true;
    }
    return false;
}

bool MyString::operator<(const MyString& str) {
    for (int i = 0; i < std::min(size-1, str.size-1); i++) {
        if (string[i] >= str.string[i] )
            return false;
    }
    return true;
}

bool MyString::operator<=(const MyString& str) {
    for (int i = 0; i < std::min(size-1, str.size-1); i++) {
        if (string[i] > str.string[i] )
            return false;
    }
    return true;
}

bool MyString::operator>(const MyString& str) {
    for (int i = 0; i < std::min(size-1, str.size-1); i++) {
        if (string[i] <= str.string[i] )
            return false;
    }
    return true;
}

bool MyString::operator>=(const MyString& str) {
    for (int i = 0; i < std::min(size-1, str.size-1); i++) {
        if (string[i] < str.string[i] )
            return false;
    }
    return true;
}

MyString MyString::operator!() {
    MyString result;
    result.size = size-1;
    result.string =  new char[result.size + 1];
    for (int i = 0; i < size; i++) {
        if (string[i] > 96)
            result.string[i] = string[i] - 32;
        else if (string[i] > 64 && string[i] < 91)
                result.string[i] = string[i] + 32;
        else
            result.string[i] = string[i];
    }
    return result;
}

char MyString::operator[](const int& index) {
    return string[index];
}

int MyString::operator()(const MyString& str) {
    if (strstr(string, str.string) == nullptr)
        return -1;
    return 0;
}

std::ostream& operator<<(std::ostream& os, MyString& str) {
    return os << str.string;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    return is >> str.string;
}

MyString& MyString::operator=(const MyString& str) {
    size = str.size;
    string =  new char[size + 1];
        snprintf(string, str.size+1, "%s\n", str.string);
    return *this;
}

MyString& MyString::operator=(MyString&& str) {
    size = str.size;
    string =  new char[size + 1];;
    snprintf(string, str.size+1, "%s\n", str.string);
    str.size = 0;
    str.string = nullptr;
    return *this;
}

