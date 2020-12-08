// Copyrignt 2020 BekusovMikhail

#include "MyString.h"

size_t MyString::length() const {
    return strlen(this->s);
}

char *MyString::get() const {
    return s;
}

MyString::MyString(const char *str) {
    if (str != nullptr) {
        int ln = strlen(str) + 1;
        s = new char[ln];
        strncpy(s, str, ln);
    } else {
        s = new char[1];
        memset(s, 0, 1);
    }
}

MyString::MyString(const std::string &str) {
    s = new char[str.size() + 1];
    s[str.size()] = '\0';
    for (int i = 0; i < str.size(); ++i) {
        s[i] = str[i];
    }
}

MyString::MyString(const MyString &str) {
    s = new char[str.length() + 1];
    for (int i = 0; i <= strlen(s); ++i) {
        s[i] = str.s[i];
    }
}

MyString::MyString(MyString &&str) {
    s = str.s;
    str.s = nullptr;
}

MyString::~MyString() {
    delete[] s;
}

MyString MyString::operator+(const MyString &str) {
    return MyString(std::string(this->get()) + std::string(str.get()));
}

MyString MyString::operator-(const MyString &str) {
    char *ns = new char[this->length()];
    int in = 0;
    for (int i = 0; i < this->length(); ++i) {
        bool f = false;
        for (int j = 0; j < str.length(); ++j) {
            if (s[i] == str.s[j]) {
                f = true;
            }
        }
        if (!f) {
            ns[in] = s[i];
            ++in;
        }
    }
    return MyString(ns);
}

MyString MyString::operator*(int n) {
    char *ns = new char[this->length() * n];
    int in = 0;
    for (int i = 0; i < this->length() * n; ++i) {
        ns[i] = s[in];
        in++;
        if (in == this->length()) {
            in = 0;
        }
    }
    ns[this->length() * n] = '\0';
    return MyString(ns);
}

MyString MyString::operator=(const MyString &str) {
    s = str.s;
    return *this;
}

MyString MyString::operator=(MyString &&str) noexcept {
    s = str.s;
    str.s = nullptr;
    return *this;
}

bool MyString::operator==(const MyString &str) {
    return !strcmp(s, str.get());
}

bool MyString::operator!=(const MyString &str) {
    return strcmp(s, str.get());
}

bool MyString::operator>(const MyString &str) {
    return strcmp(s, str.get()) == 1;
}

bool MyString::operator<(const MyString &str) {
    return strcmp(s, str.get()) == -1;
}

bool MyString::operator>=(const MyString &str) {
    return strcmp(s, str.get()) > -1;
}

bool MyString::operator<=(const MyString &str) {
    return strcmp(s, str.get()) < 1;
}

MyString MyString::operator!() {
    for (int i = 0; i < this->length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    return *this;
}

char &MyString::operator[](int i) {
    return s[i];
}

int MyString::operator()(const char *str) {
    char *fin = strstr(s, str);
    if (fin == nullptr)
        return -1;
    else
        return fin - s;
}

std::ostream &operator<<(std::ostream &os, MyString &str) {
    return os << str.get();
}

std::istream &operator>>(std::istream &is, MyString &str) {
    return is >> str.get();
}
