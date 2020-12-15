// Copyright [2020] <Olesya Nikolaeva>

#include "MyString.h"
#include <string.h>

MyString::MyString(const char* str) {
    if (str != nullptr) {
        mystr = new char[strlen(str) + 1];
        snprintf(mystr, strlen(str) + 1, "%s", str);
        size = strlen(str);
    }
}

MyString::MyString(std::string str) {
    mystr = new char[str.length() + 1];
    snprintf(mystr, str.length() + 1, "%s", str.c_str());
    size = str.length();
}

MyString::MyString(const MyString& copy) {
    mystr = new char[copy.size + 1];
    snprintf(mystr, copy.size + 1, "%s", copy.mystr);
    size = copy.size;
}

MyString::MyString(MyString&& move) {
    mystr = new char[move.size + 1];
    snprintf(mystr, move.size + 1, "%s", move.mystr);
    this->size = move.size;
    move.mystr = nullptr;
    move.size = 0;
}

MyString::~MyString() {
    delete[] mystr;
}

size_t MyString::length() {
    return size;
}

char* MyString::get() {
    return mystr;
}

MyString MyString::operator+(const MyString& arg) {
    MyString result;
    result.mystr = new char[size + arg.size + 1];
    snprintf(result.mystr, size + arg.size + 1,
             "%s%s", this->mystr, arg.mystr);
    size = size + arg.size;
    return result;
}

MyString MyString::operator-(const MyString& arg) {
    std::string result = "";
    int index = 0;
    for (int i = 0; i < size; i++) {
        int j = 0;
        int n = 0;
        while (n < arg.size) {
            if (arg.mystr[n] == this->mystr[i])
                j++;
            n++;
        }
        if (j == 0) {
            result += this->mystr[i];
            index++;
        }
    }
    return MyString(result);
}

MyString MyString::operator*(unsigned int n) {
    char* result = new char[size * n];
    for (int i = 0; i < n; i++) {
        snprintf(result + i * size, size + 1, "%s", mystr);
    }
    size = size * n;
    return MyString(result);
}

MyString MyString::operator=(const MyString& arg) {
    this->mystr = new char[arg.size + 1];
    snprintf(this->mystr, arg.size + 1, "%s", arg.mystr);
    this->size = arg.size;
    return *this;
}

MyString MyString::operator=(MyString&& arg) {
    this->mystr = arg.mystr;
    this->size = arg.size;
    arg.mystr = nullptr;
    arg.size = 0;
    return *this;
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
    result.mystr = new char[size];
    for (int i = 0; i < strlen(this->mystr); i++) {
        char c = this->mystr[i];
        if (isdigit(c))
            result.mystr[i] = c;
        else if (islower(c))
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

int MyString::operator()(const char* arg) {
    std::string s = mystr;
    size_t index = s.find(arg);
    if (index != std::string::npos)
        return index;
    else
        return -1;
}

std::ostream& operator<<(std::ostream& output, MyString& arg) {
  return output << arg.mystr;
}

std::istream& operator>>(std::istream& input, MyString& arg) {
  return input >> arg.mystr;
}
