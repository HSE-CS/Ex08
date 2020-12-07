//  Copyright 2020 Nikita Naumov
#ifndef INCLUDE_MYSTRING_H
#define INCLUDE_MYSTRING_H

#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>
#include <algorithm>


class MyString {
 private:
    char* ptr;
    unsigned len;

 public:
    //  constructors and destructors
    explicit MyString(const char* str = nullptr);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString() { 
        delete[] this->ptr;
    }
    //  methods
    int length();
    char* get();

    //  operation overloading
    MyString& operator= (const MyString& a) {
        if (&a == this) {
            return *this;
        }
        this->len = a.len;
        delete[] this->ptr;
        this->ptr = new char[this->len + 1];
        snprintf(this->ptr, this->len + 1, "%s", a.ptr);
        return *this;
    } 
    MyString& operator= (MyString&& a) {
        if (&a == this) {
            return *this;
        }
        this->len = a.len;
        delete[] this->ptr;
        this->ptr = new char [this->len + 1];
        snprintf(this->ptr, this->len + 1, "%s", a.ptr);
        a.len = 0;
        delete[] a.ptr;
        a.ptr = nullptr;
        return *this;
    }

    MyString operator+ (const MyString& a) {
        MyString tmp;
        tmp.len = this->len + a.len;
        tmp.ptr = new char[tmp.len + 1];
        for (size_t i = 0; i < this->len; ++i) {
            tmp.ptr[i] = this->ptr[i];
        }
        if (a.ptr != nullptr) {
            for (size_t i = 0; i < a.len; ++i) {
                tmp.ptr[i + this->len] = a.ptr[i];
            }
        }
        tmp.ptr[tmp.len] = '\0';
        return tmp;
    }
    
    MyString operator- (const MyString& a) {
        std::string buf_str = std::string(this->ptr, this->ptr + len);
        for (size_t i = 0; i < a.len; i++)
        buf_str.erase(std::remove(buf_str.begin(), buf_str.end(), a.ptr[i]),
                  buf_str.end());
        return MyString(buf_str);
    }  //  вычитание (из первой строки удаляются все символы, присутствующие
    //  во второй строке).
    
    MyString operator* (int a) {
        if (a < 0) {
            throw -1;
        }
        char* tmp = new char[this->len * a + 1];
        size_t cnt = 0;
        for (size_t i = 0; i < a; ++i) {
            for (size_t j = 0; j < this->len; ++j) {
                tmp[cnt] = this->ptr[j];
                cnt++;
            } 
        }
        tmp[cnt] = '\0';
        return MyString(tmp);
    }

    MyString operator! () {
        MyString tmp(this->ptr);
        for (size_t i = 0; i < (tmp.len + 1); ++i) {
            if (tmp.ptr[i] >= 'a' && tmp.ptr[i] <= 'z') {
                tmp.ptr[i] = toupper(tmp.ptr[i]);
            } else if (tmp.ptr[i] >= 'A' && tmp.ptr[i] <= 'Z') {
                tmp.ptr[i] = tolower(tmp.ptr[i]);
            }
        }
        return tmp;
    }

    char & operator[](int num) const {
        if (num <= this->len) {
            return this->ptr[num];
        } else {
            std::cout << "Out of range";
            exit(-1);
        }
    }

    int operator() (const char* a) {
        bool flag = true;
        for (size_t i = 0; i < this->len; ++i) {
            if (i + strlen(a) < this->len) {
                for (size_t j = 0; j < strlen(a); ++j) {
                    if (this->ptr[j] != a[j]) {
                        flag = false;
                    }
                }
                if (flag) {
                    return i;
                }
                flag = true;
            }
        }
        return -1;
    }

    friend bool operator> (const MyString& a, const MyString& b);

    friend bool operator< (const MyString& a, const MyString& b);

    friend bool operator>= (const MyString& a, const MyString& b);

    friend bool operator<= (const MyString& a, const MyString& b);

    friend bool operator!= (const MyString& a, const MyString& b);

    friend bool operator== (const MyString &a, const MyString &b);

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

    friend std::istream& operator>>(std::istream& os, const MyString& str);
};



#endif  //  INCLUDE_MYSTRING_H
