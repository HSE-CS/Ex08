//  Copyright 2020 Drobot Elizaveta
#include "MyString.h"

    MyString::MyString(const char* str) {
        if (str == nullptr) {
            this->len = 0;
            this->str = nullptr;
        } else {
            this->len = strlen(str);
            this->str = new char[this->len + 1];
            snprintf(this->str, this->len + 1, "%s", str);
        }
    }

    MyString::MyString(std::string str) {
        this->len = str.length();
        this->str = new char[this->len + 1];
        for (size_t i = 0; i < this->len + 1; ++i) {
            this->str[i] = str[i];
        }
    }

    MyString::MyString(const MyString& x) {
        this->len = x.len;
        this->str = new char[this->len + 1];
        snprintf(this->str, this->len + 1, "%s", x.str);
    }

    MyString::MyString(MyString&& x) {
        this->len = x.len;
        this->str = x.str;
        x.len = 0;
        x.str = nullptr;
    }

    int MyString::length() {
        return this->len;
    }

    char* MyString::get() {
        return this->str;
    }

    bool operator== (const MyString &a, const MyString &b) {
        if (a.len != b.len) {
            return false;
        }
        for (size_t i = 0; i < a.len; ++i) {
            if (a.str[i] != b.str[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!= (const MyString& a, const MyString& b) {
        if (a.len != b.len) {
            return true;
        }
        for (size_t i = 0; i < a.len; ++i) {
            if (a.str[i] != b.str[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator> (const MyString& a, const MyString& b) {
        if (a.len > b.len) {
            return true;
        } else if (a.len < b.len) {
            return false;
        } else {
            for (size_t i = 0; i < a.len; ++i) {
                if (a.str[i] > b.str[i]) {
                    return true;
                }
            }
            return false;
        }
    }

    bool operator< (const MyString& a, const MyString& b) {
        if (a.len < b.len) {
            return true;
        } else if (a.len > b.len) {
            return false;
        } else {
            for (size_t i = 0; i < a.len; ++i) {
                if (a.str[i] < b.str[i]) {
                    return true;
                }
            }
            return false;
        }
    }

    bool operator>= (const MyString& a, const MyString& b) {
        if (a.len < b.len) {
            return false;
        } else if (a.len > b.len) {
            return true;
        } else {
            for (size_t i = 0; i < a.len; ++i) {
                if (a.str[i] < b.str[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    bool operator<= (const MyString& a, const MyString& b) {
        if (strcmp(a.str, b.str) != 1) {
            return 1;
        } else {
            return 0;
        }
    }

    std::istream& operator>> (std::istream& is, const MyString& a) {
        is>> a.str;
        return is;
    }

    std::ostream& operator<< (std::ostream& os, const MyString& a) {
        os << a.str;
        return os;
    }
