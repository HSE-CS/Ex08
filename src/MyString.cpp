// Copyright 2020 test
#include "../include/MyString.h"

MyString::MyString(const char* ptr) {
    if (ptr == nullptr) {
        len = 0;
        str = nullptr;
    } else {
        len = strlen(ptr);
        str = new char[len + 1];
        for (size_t i = 0; i <= len; ++i) {
            str[i] = ptr[i];
        }
    }
}

MyString::MyString(std::string s) {
    len = s.size();
    str = new char[len + 1];
    for (size_t i = 0; i <= len; ++i) {
        str[i] = s[i];
    }
}

MyString::MyString(const MyString& s) {
    this->len = s.len;
    this->str = new char[len + 1];
    for (size_t i = 0; i <= len; ++i) {
        str[i] = s.str[i];
    }
}

MyString::MyString(MyString&& s) {
    this->len = s.len;
    this->str = s.str;
    s.len = 0;
    s.str = nullptr;
}

MyString::~MyString() {
    len = 0;
    delete[] str;
}

size_t MyString::length() {
    return len;
}

char* MyString::get() {
    return str;
}

MyString MyString::operator+(const MyString& s) {
    MyString new_str;
    new_str.len = this->len + s.len;
    new_str.str = new char[new_str.len + 1];
    for (size_t i = 0; i < this->len; ++i) {
        new_str.str[i] = this->str[i];
    }
    if (s.str != nullptr) {
        for (size_t i = 0; i < s.len; ++i) {
            new_str.str[i + this->len] = s.str[i];
        }
    }
    new_str.str[new_str.len] = '\0';
    return new_str;
}

MyString MyString::operator-(const MyString& s) {
    if (s.str == nullptr) {
        return *this;
    }
    MyString new_str;
    new_str.len = 0;
    for (size_t i = 0; i < this->len; ++i) {
        bool check = true;
        for (size_t j = 0; j < s.len; ++j) {
            if (this->str[i] == s.str[j]){
                check = false;
            }
        }
        if (check) {
            new_str.len++;
        }
    }
    new_str.str = new char[new_str.len + 1];
    size_t pointer = 0;
    for (size_t i = 0; i < this->len; ++i) {
        bool check = true;
        for (size_t j = 0; j < s.len; ++j) {
            if (this->str[i] == s.str[j]) {
                check = false;
            }
        }
        if (check) {
            new_str.str[pointer] = this->str[i];
            pointer++;
        }
    }
    new_str.str[pointer] = '\0';
    return new_str;
}

MyString MyString::operator*(size_t num) {
    if (num < 0) {
        throw - 1;
    }
    char* buffer = new char[num * this->len + 1];
    size_t pointer = 0;
    for (size_t count = 0; count < num; ++count) {
        for (size_t i = 0; i < this->len; ++i) {
            buffer[pointer] = this->str[i];
            pointer++;
        }
    }
    buffer[pointer] = '\0';
    return MyString(buffer);
}

MyString& MyString::operator=(const MyString& s) {
    if (s.str == nullptr) {
        this->len = 0;
        this->str = nullptr;
        return *this;
    }
    this->len = s.len;
    str = new char[s.len + 1];
    for (size_t i = 0; i <= this->len; ++i) {
        this->str[i] = s.str[i];
    }
    return *this;
}

MyString& MyString::operator=(MyString&& s) {
    this->len = s.len;
    this->str = s.str;
    s.len = 0;
    s.str = nullptr;
    return *this;
}

bool MyString::operator== (const MyString& s) {
    if (strcmp(this->str, s.str) == 0) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator!= (const MyString& s) {
    if (strcmp(this->str, s.str) != 0) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator> (const MyString& s) {
    if (strcmp(this->str, s.str) == 1) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator< (const MyString& s) {
    if (strcmp(this->str, s.str) == -1) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator>= (const MyString& s) {
    if (strcmp(this->str, s.str) != -1) {
        return 1;
    } else {
        return 0;
    }
}

bool MyString::operator<= (const MyString& s) {
    if (strcmp(this->str, s.str) != 1) {
        return 1;
    } else {
        return 0;
    }
}

MyString MyString::operator!() {
    if (this->str == nullptr) {
        return MyString(nullptr);
    }
    char* new_str = new char[this->len + 1];
    size_t pointer = 0;
    for (size_t i = 0; i < this->len; ++i) {
        if (this->str[i] >= 'a' && this->str[i] <= 'z') {
            new_str[pointer] = this->str[i] - 'a' + 'A';
        } else {
            if (this->str[i] >= 'A' && this->str[i] <= 'Z') {
                new_str[pointer] = this->str[i] - 'A' + 'a';
            } else {
                new_str[pointer] = this->str[i];
            }
        }
        pointer++;
    }
    new_str[pointer] = '\0';
    return MyString(new_str);
}

char& MyString::operator[](int ind) {
    if (ind < 0 || ind > this->len || this->str == nullptr) {
        throw - 1;
    }
    return this->str[ind];
}

int MyString::operator()(const char* s) {
    if (s == nullptr || str == nullptr) {
        throw - 1;
    }
    char* search = strstr(this->str, s);
    if (search == nullptr) {
        return -1;
    } else {
        return search - this->str;
    }
}

std::ostream& operator<<(std::ostream& os, MyString& s) {
    if (s.str == nullptr) {
        throw - 1;
    }
    return os << s.get();
}

std::istream& operator>>(std::istream& is, MyString& s) {
    return is >> s; // еще не доделал 
}
