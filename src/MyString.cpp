//  Copyright 2020 Nikita Naumov
#include "../include/MyString.h"

    MyString::MyString(const char* str) {
        if (str == nullptr) {
            this->len = 0;
            this->ptr = nullptr;
        } else {
            this->len = strlen(str);
            this->ptr = new char[this->len + 1];
            snprintf(this->ptr, this->len + 1, "%s", str);
        }
    }

    MyString::MyString(std::string str) {
        this->len = str.length();
        this->ptr = new char[this->len + 1];
        for (size_t i = 0; i < this->len + 1; ++i) {
            this->ptr[i] = str[i];
        }
    }

    MyString::MyString(const MyString& x) {
        this->len = x.len;
        this->ptr = new char[this->len + 1];
        snprintf(this->ptr, this->len + 1, "%s", x.ptr);
    }

    MyString::MyString(MyString&& x) {
        this->len = x.len;
        this->ptr = x.ptr;
        x.len = 0;
        x.ptr = nullptr;
    }

    int MyString::length() {
        return this->len;
    }
    
    char* MyString::get() {
        return this->ptr;
    }

    bool operator== (const MyString &a, const MyString &b) {
        if (a.len != b.len) {
            return false;
        }
        for (size_t i = 0; i < a.len; ++i) {
            if (a.ptr[i] != b.ptr[i]) {
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
            if (a.ptr[i] != b.ptr[i]) {
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
                if (a.ptr[i] > b.ptr[i]) {
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
                if (a.ptr[i] < b.ptr[i]) {
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
                if (a.ptr[i] < b.ptr[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    bool operator<= (const MyString& a, const MyString& b) {
        if (a.len > b.len) {
            return false;
        } else if (a.len < b.len) {
            return true;
        } else {
            for (size_t i = 0; i < a.len; ++i) {
                if (a.ptr[i] > b.ptr[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    std::istream& operator>> (std::istream& is, const MyString& a) {
        is>> a.ptr;
        return is;
    }

    std::ostream& operator<< (std::ostream& os, const MyString& a) {
        os << a.ptr;
        return os;
    }
    