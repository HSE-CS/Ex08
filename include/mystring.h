#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>
#include <algorithm>
class MyString {
private:
    char* str;
    unsigned len;
public:
    explicit MyString(const char* str = nullptr);
    explicit MyString(std::string);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString() {
        delete[] this->str;
    }
    int length();
    char* get();
    MyString& operator= (const MyString& a) {
        if (&a == this) {
            return *this;
        }
        this->len = a.len;
        delete[] this->str;
        this->str = new char[this->len + 1];
        snprintf(this->str, this->len + 1, "%s", a.str);
        return *this;
    }
    MyString& operator= (MyString&& a) {
        if (&a == this) {
            return *this;
        }
        this->len = a.len;
        delete[] this->str;
        this->str = new char[this->len + 1];
        snprintf(this->str, this->len + 1, "%s", a.str);
        a.len = 0;
        delete[] a.str;
        a.str = nullptr;
        return *this;
    }
    MyString operator+ (const MyString& a) {
        MyString tmp;
        tmp.len = this->len + a.len;
        tmp.str = new char[tmp.len + 1];
        for (size_t i = 0; i < this->len; ++i) {
            tmp.str[i] = this->str[i];
        }
        if (a.str != nullptr) {
            for (size_t i = 0; i < a.len; ++i) {
                tmp.str[i + this->len] = a.str[i];
            }
        }
        tmp.str[tmp.len] = '\0';
        return tmp;
    }
    MyString operator- (const MyString& a) {
        std::string buf_str = std::string(this->str, this->str + len);
        for (size_t i = 0; i < a.len; i++)
            buf_str.erase(std::remove(buf_str.begin(), buf_str.end(), a.str[i]),
                buf_str.end());
        return MyString(buf_str);
    }
    MyString operator* (int a) {
        if (a < 0) {
            throw - 1;
        }
        char* tmp = new char[this->len * a + 1];
        size_t cnt = 0;
        for (size_t i = 0; i < a; ++i) {
            for (size_t j = 0; j < this->len; ++j) {
                tmp[cnt] = this->str[j];
                cnt++;
            }
        }
        tmp[cnt] = '\0';
        return MyString(tmp);
    }
    MyString operator! () {
        MyString tmp(this->str);
        for (size_t i = 0; i < (tmp.len + 1); ++i) {
            if (tmp.str[i] >= 'a' && tmp.str[i] <= 'z') {
                tmp.str[i] = toupper(tmp.str[i]);
            }
            else if (tmp.str[i] >= 'A' && tmp.str[i] <= 'Z')
            {
            }
            else if (tmp.str[i] >= 'A' && tmp.str[i] <= 'Z') {
                tmp.str[i] = tolower(tmp.str[i]);
            }
        }
        return tmp;
    }
    char& operator[](int num) const {
        if (num <= this->len) {
            return this->str[num];
        }
        else
        {
        }
 else {
 std::cout << "Out of range";
 exit(-1);
        }
    }
    int operator() (const char* a) {
        bool flag = true;
        for (size_t i = 0; i < this->len; ++i) {
            if (i + strlen(a) < this->len) {
                for (size_t j = 0; j < strlen(a); ++j) {
                    if (this->str[j] != a[j]) {
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
    friend bool operator== (const MyString& a, const MyString& b);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& os, const MyString& str);
};
#endif
