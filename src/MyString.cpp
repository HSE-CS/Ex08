// Copyright 2020 Dmitry Vargin
#include "MyString.h"

MyString::MyString(const char *str) {
    if (str == nullptr) {
        this->str = new char[1]{'\0'};
    } else {
        this->str = new char[strlen(str)+1];
        snprintf(this->str, strlen(str)+1, "%s", str);
    }
}

MyString::MyString(std::string str) {
    this->str = new char[str.length()+1];
    snprintf(this->str, str.length()+1, "%s", str.c_str());
}

MyString::MyString(const MyString &str) {
    this->str = new char[str.length()+1];
    snprintf(this->str, strlen(str.str)+1, "%s", str.get());
}

MyString::MyString(MyString && str) {
    this->str = new char[str.length()+1];
    snprintf(this->str, strlen(str.str) + 1, "%s", str.get());
}

MyString::~MyString() {
    delete [] this->str;
}

int MyString::length() const {
    return strlen(this->str);
}

char * MyString::get() const {
    return this->str;
}

MyString MyString::operator+(const MyString &str) {
    char *tmp = new char[this->length() + str.length()+1];
    snprintf(tmp, this->length()+1, "%s", this->str);
    snprintf(tmp + this->length(), str.length()+1, "%s", str.str);
    return MyString(tmp);
}

int findCharacter(char *str, char c) {
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

MyString MyString::operator-(const MyString &str) {
    char *tmp = new char[this->length()]{'\0'};
    int tmp_len = 0;
    for (int i = 0; i < this->length(); ++i) {
        if (findCharacter(str.str, this->str[i]) == -1) {
            tmp[tmp_len++] = this->str[i];
        }
    }
    return MyString(tmp);
}

MyString MyString::operator*(size_t num) {
    char *tmp = new char[num * this->length() + 1];
    char *t = tmp;
    for (int i = 0; i < num; ++i) {
        snprintf(t, this->length()+1, "%s", this->str);
        t += this->length();
    }
    return MyString(tmp);
}

MyString & MyString::operator=(const MyString &str) {
    if (this->str != nullptr)
        delete [] this->str;
    this->str = new char[str.length()+1];
    snprintf(this->str, str.length()+1, "%s", str.str);
    return *this;
}

MyString & MyString::operator=(MyString &&str) {
    if (this->str != nullptr)
        delete [] this->str;
    this->str = str.str;
    str.str = nullptr;
    return *this;
}

MyString& MyString::operator!() {
    for (int i = 0; i < this->length(); ++i) {
        if (this->str[i] >= 'A' && this->str[i] <= 'Z')
            this->str[i] += 32;
        else if (this->str[i] >= 'a' && this->str[i] <= 'z')
            this->str[i] -= 32;
    }
    return *this;
}

bool MyString::operator==(const MyString &str) {
    return !strcmp(this->str, str.str);
}

bool MyString::operator!=(const MyString &str) {
    return strcmp(this->str, str.str);
}

bool MyString::operator>(const MyString &str) {
    return strcmp(this->str, str.str) > 0;
}

bool MyString::operator<(const MyString &str) {
    return strcmp(this->str, str.str) < 0;
}

bool MyString::operator>=(const MyString &str) {
    return strcmp(this->str, str.str) >= 0;
}

bool MyString::operator<=(const MyString &str) {
    return strcmp(this->str, str.str) <= 0;
}

char & MyString::operator[](unsigned int index) const {
    if (index < 0 || index >= this->length())
        throw "Index out of range\n";
    return this->str[index];
}

int MyString::operator()(const char* substring) {
    if (strstr(this->str, substring) != nullptr)
        return strstr(this->str, substring) - this->str;
    return -1;
}

std::ostream& operator<<(std::ostream& os, MyString& str) {
    return os << str.str;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    unsigned int len = is.gcount() + 1;
    std::string tmp;
    std::getline(is, tmp);
    str = MyString(tmp);
    return is;
}

