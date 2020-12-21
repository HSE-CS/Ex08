// Copyright 2020 Dyryaev Daniil

#include "../include/MyString.h"

MyString::MyString(std::string s) {
    this->string = new char[s.length() + 1];
    for (unsigned int i = 0; i < s.length(); ++i)
        this->string[i] = s[i];
}

MyString::MyString(MyString &&s) noexcept {
    s.string = this->string;
    this->string = nullptr;
}

MyString MyString::operator+(const MyString &s) {
    auto result = new char[this->length() + s.length() + 1];
    for (int i = 0; i < this->length(); ++i)
        result[i] = this->string[i];
    for (unsigned int i = this->length(); i < this->length() + s.length(); ++i)
        result[i] = s.string[i - this->length()];
    // std::cout<<result<<'\n';
    return MyString(result);
}

MyString::MyString(const MyString &s) {
    this->string = new char[strlen(s.string) + 1];
    // strcpy(this->string, s.string);
    snprintf(this->string, strlen(s.string) + 1, "%s", s.string);
}

MyString::MyString(const char *s) {
    if (s) {
        this->string = new char[strlen(s) + 1];
        // strcpy(this->string, s);
        snprintf(this->string, strlen(s) + 1, "%s", s);
    } else {
        this->string = new char[1];
        this->string[0] = '\0';
    }
}

MyString MyString::operator-(const MyString &s) {
    auto result = new char[this->length() + s.length() + 1];
    memset(result, 0, this->length() + s.length() + 1);
    int current = 0;
    for (unsigned int i = 0; i < this->length(); ++i) {
        bool in_string = false;
        for (unsigned int j = 0; j < s.length(); ++j) {
            if (s.string[j] == this->string[i])
                in_string = true;
        }
        if (!in_string) {
            result[current] = this->string[i];
            current++;
        }
    }
    return MyString(result);
}

MyString MyString::operator*(int n) {
    auto result = new char[1 + n * this->length()];
    for (unsigned int i = 0; i < n; ++i)
        // strcpy(i * this->length() + result, this->string);
        snprintf(i * this->length() + result,
                 this->length(), "%s", this->string);
    return MyString(result);
}

MyString &MyString::operator=(const MyString &s) {
    this->string=new char[s.length()+1];
    // strcpy(this->string, s.string);
    snprintf(this->string, s.length() + 1, "%s", s.string);
    return *this;
}

MyString &MyString::operator=(MyString &&s) noexcept {
    s.string = this->string;
    this->string = nullptr;
    return *this;
}

bool MyString::operator>(const MyString &s) {
    return strcmp(this->string, s.string) > 0;
}

bool MyString::operator<(const MyString &s) {
    return strcmp(this->string, s.string) < 0;
}

bool MyString::operator==(const MyString &s) {
    return strcmp(this->string, s.string) == 0;
}

bool MyString::operator!=(const MyString &s) {
    return strcmp(this->string, s.string) != 0;
}

bool MyString::operator>=(const MyString &s) {
    return strcmp(this->string, s.string) >= 0;
}

bool MyString::operator<=(const MyString &s) {
    return strcmp(this->string, s.string) <= 0;
}

MyString MyString::operator!() {
    auto result = new char[this->length() + 1];
    for (unsigned int i = 0; i < this->length() + 1; ++i) {
        if (isupper(this->string[i]))
            result[i] = tolower(this->string[i]);
        else
            result[i] = toupper(this->string[i]);
    }
    return MyString(result);
}

char MyString::operator[](int n) {
    if (n > -1 && n < this->length())
        return this->string[n];
    else
        throw;
}

std::istream &operator>>(std::istream &stream, MyString &s) {
    return stream >> s.get();
}

char *MyString::get() {
    return this->string;
}

std::ostream &operator<<(std::ostream &stream, MyString &s) {
    return stream << s.get();
}

int MyString::operator()(const char *sub) {
    std::string substring(sub);
    std::string s(this->string);
    int counter = 0;
    for (unsigned int i = 0; i < this->length() - substring.length() + 1; ++i) {
        if (s.substr(i, substring.length()) == substring)
            counter++;
    }
    if (counter > 0)
        return 0;
    else
        return -1;
}

int MyString::length() const {
    return strlen(string);
}
