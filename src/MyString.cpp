// Copyright [2020] <Olesya Nikolaeva>

#include "MyString.h"
#include <string.h>

MyString::MyString(const char* str) {
    if (str != nullptr) {
        mystr = new char[strlen(str) + 1];
        strcpy(mystr, str);
    }
}

MyString::MyString(std::string str) {
    mystr = new char[str.length() + 1];
    strcpy(mystr, str.c_str());
}

MyString::MyString(const MyString& copy) {
    mystr = new char[strlen(copy.mystr) + 1];
    strcpy(this->mystr, copy.mystr);
}

MyString::MyString(MyString&& move) {
    mystr = new char[strlen(move.mystr) + 1];
    strcpy(this->mystr, move.mystr);
    move.mystr = nullptr;
}

MyString::~MyString() {
    delete[] mystr;
}

size_t MyString::length() {
    return strlen(mystr);
}

char* MyString::get() {
    return mystr;
}

MyString MyString::operator+(const MyString& arg) {
    MyString result;
    result.mystr = new char[strlen(mystr) + strlen(arg.mystr) + 1];
    strcpy(result.mystr, this->mystr);
    strcat(result.mystr, arg.mystr);
    return result;
}

MyString MyString::operator-(const MyString& arg) {
    MyString result;
    int index = 0;
    for (int i = 0; i < strlen(this->mystr); i++) {
        int j = 0;
        while (j < strlen(arg.mystr)) {
            if (arg.mystr[j] == this->mystr[i])
                j++;
        }
        if (j == 0) {
            result.mystr[index] = this->mystr[i];
            index++;
        }
    }
    return result;
}

MyString MyString::operator*(unsigned int n) {
    MyString result;
    result.mystr = new char[strlen(mystr) * n];
    for (int i = 0; i < n; i++) {
        strcat(result.mystr, result.mystr);
    }
    return result;
}

MyString MyString::operator=(const MyString& arg) {
    MyString result;
    result.mystr = new char[strlen(arg.mystr) + 1];
    strcpy(result.mystr, arg.mystr);
    return result;
}

MyString MyString::operator=(MyString&& arg) {
    MyString result;
    result.mystr = new char[strlen(arg.mystr) + 1];
    strcpy(result.mystr, arg.mystr);
    arg.mystr = nullptr;
    return result;
}

bool MyString::operator==(const MyString& arg) {
    int answer = strcmp(this->mystr, arg.mystr);
    if (answer == 0)
        return true;
    return false;
}

bool MyString::operator!=(const MyString& arg) {
    int answer = strcmp(this->mystr, arg.mystr);
    if (answer == 0)
        return false;
    return true;
}

bool MyString::operator>(const MyString& arg) {
    int answer = strcmp(this->mystr, arg.mystr);
    if (answer > 0)
        return true;
    return false;
}

bool MyString::operator<(const MyString& arg) {
    int answer = strcmp(this->mystr, arg.mystr);
    if (answer < 0)
        return true;
    return false;
}

bool MyString::operator>=(const MyString& arg) {
    int answer = strcmp(this->mystr, arg.mystr);
    if (answer >= 0)
        return true;
    return false;
}

bool MyString::operator<=(const MyString& arg) {
    int answer = strcmp(this->mystr, arg.mystr);
    if (answer < 0)
        return true;
    return false;
}

MyString MyString::operator!() {
    MyString result;
    for (int i = 0; i < strlen(this->mystr); i++) {
        int c = this->mystr[i];
        if (islower(c))
            result.mystr[i] = toupper(c);
        else if (isupper(c))
            result.mystr[i] = tolower(c);
    }
    return result;
}

char MyString::operator[](unsigned int index) {
    if ((index < strlen(mystr))&&(index >= 0))
        return mystr[index];
    throw "error";
}

unsigned long MyString::operator()(const char* arg) {
    std::string s = mystr;
    return s.find(arg);
}

std::ostream& operator<<(std::ostream& output, MyString& arg) {
  return output << arg.mystr;
}

std::istream& operator>>(std::istream& input, MyString& arg) {
  return input >> arg.mystr;
}
