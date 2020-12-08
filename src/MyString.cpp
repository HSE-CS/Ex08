// Copyright 2020 Bekina Svetlana
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

MyString::MyString(const char* new_string) {
    if (new_string != nullptr) {
        if (string != nullptr)
            delete[] string;
        string = new char[strlen(new_string) + 1];
		snprintf(string, strlen(new_string) + 1, "%s", new_string);
    } else {
        string = new char[1];
        memset(string, 0, 1);
    }
}

MyString::MyString(std::string new_string) {
    if (string != nullptr)
        delete[] string;
    string = new char[new_string.size() + 1];
    snprintf(string, new_string.size() + 1, "%s", new_string.c_str());
}

MyString::MyString(const MyString& mystring) {
    if (string != nullptr)
        delete[] string;
    string = new char[mystring.length() + 1];
    snprintf(string, mystring.length() + 1, "%s", mystring.get());
}

MyString::MyString(MyString&& mystring) {
    string = mystring.get();
    mystring.string = nullptr;
}

MyString::~MyString() {
    delete[] string;
}

size_t MyString::length() const {
    return strlen(string);
}

char* MyString::get() const {
    return string;
}
MyString MyString::operator+(const MyString& mystring) {
    return MyString(std::string(get()) + std::string(mystring.get()));
}
MyString MyString::operator-(const MyString& mystring) {
    char* result = new char[length() + 1];
    int j = 0;
    for (size_t i = 0; i < length() + 1; i++) {
        if (strchr(mystring.get(), string[i]) == nullptr) {
            result[j] = string[i];
            j++;
        }
    }
    result[j] = '\0';
    return MyString(result);
}
MyString MyString::operator*(int n) {
    std::string result;
    for (int i = 0; i < n; i++) {
        result += std::string(string);
    }
    return MyString(result);
}

MyString& MyString::operator=(const MyString& mystring) {
    if (string != nullptr)
        delete[] string;
    string = new char[mystring.length() + 1];
    snprintf(string, mystring.length() + 1, "%s", mystring.get());
    return *this;
}

MyString& MyString::operator=(MyString&& mystring) {
    if (string != nullptr)
        delete[] string;
    string = new char[mystring.length() + 1];
    snprintf(string, mystring.length() + 1, "%s", mystring.get());
    mystring.string = nullptr;
    return *this;
}

char MyString::operator[](int index) {
    if (index > 0 && index < length() + 1)
        return string[index];
    else
        throw "Index out of range!";
}

int MyString::operator()(const char* str) {
    std::string my_string = get();
    return  my_string.find(str, 0);
}

bool MyString::operator==(const MyString& mystring) {
    return strcmp(string, mystring.get()) == 0;
}
bool MyString::operator!=(const MyString& mystring) {
    return strcmp(string, mystring.get()) != 0;
}
bool MyString::operator>(const MyString& mystring) {
    return strcmp(string, mystring.get()) > 0;
}
bool MyString::operator<(const MyString& mystring) {
    return strcmp(string, mystring.get()) < 0;
}
bool MyString::operator>=(const MyString& mystring) {
    return strcmp(string, mystring.get()) >= 0;
}
bool MyString::operator<=(const MyString& mystring) {
    return strcmp(string, mystring.get()) <= 0;
}

MyString MyString::operator!() {
    char* result = new char[length() + 1];
    for (size_t i = 0; i < length() + 1; i++) {
        if (islower(string[i]))
            result[i] = toupper(string[i]);
        else
            result[i] = tolower(string[i]);
    }
    return MyString(result);
}
std::ostream& operator<<(std::ostream& stream, const MyString& mystring) {
    return stream << mystring.get();
}
std::istream& operator>>(std::istream& stream, const MyString& mystring) {
    return stream >> mystring.get();
}
