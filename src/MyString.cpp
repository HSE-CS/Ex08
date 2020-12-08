// Created by mila on 08.12.2020
#include "MyString.h"
#include <string>
#include <string.h>
#include <cstring>

// - конструктор с одним параметром (есть значение по-умолчанию nullptr).
MyString::MyString(const char* s) {
    if (s != nullptr) {
        int l = std::strlen(s) + 1;
        this->str = new char[l];
        strncpy(this->str, s, l);
    }
}

// - конструктор с одним параметром.
MyString::MyString(const std::string& s) {
    int l = s.length() + 1;
    this->str = new char[l];
    strncpy(this->str, s.c_str(), l);
}

// - конструктор копирования.
MyString::MyString(const MyString &s) {
    int l = s.length() + 1;
    this->str = new char[l];
    strncpy(this->str, s.str, l);
}

// - конструктор переноса.
MyString::MyString(MyString &&s) {
    int l = s.length() + 1;
    this->str = new char[l];
    strncpy(this->str, s.str, l);
}

// - деструктор.
MyString::~MyString() {
    delete this->str;
}

// - количество символов (длина строки).
int MyString::length() const {
    return strlen(this->str);
}

// - возвращение указателя на данные (тип char*).
char *MyString::get() const {
    return this->str;
}

// сложение (конкатенация двух строк).
MyString MyString::operator+(const MyString &s) {
    return MyString(std::string(this->get()) + std::string(s.get()));
}

// вычитание (из первой строки удаляются все символы, присутствующие во второй строке).
MyString MyString::operator-(const MyString &s) {
    std::string s0 = this->get();
    int l = s.length();
    for (int i = 0; i < l; ++i) {
        while (s0.find(s.str[i]) != -1)
            s0.erase(s0.find(s.str[i]), 1);
    }
    return MyString(s0);
}

// умножение на целое число (строка повторяется заданное число раз).
MyString MyString::operator*(int k) {
    std::string s0;
    for (int i = 0; i < k; ++i) {
        s0 = s0 + this->get();
    }
    return MyString(s0);
}

// - копирующее присваивание.
MyString &MyString::operator=(const MyString &s) {
    delete this->str;
    int l = s.length() + 1;
    char *s0 = new char[l];
    strncpy(s0, s.get(), l);

    return *this;
}

// - перемещающее присваивание.
MyString &MyString::operator=(MyString &&s) {
    delete this->str;
    this->str = s.get();
    s.str = nullptr;

    return *this;
}

// - сравнение на равенство.
bool MyString::operator==(const MyString &s1) const {
    return !(strcmp(this->str, s1.get()));
}

// - сравнение на неравенство.
bool MyString::operator!=(const MyString &s1) const {
    return (strcmp(this->str, s1.get()));
}

//  - лексографическое сравнение .
bool MyString::operator>(const MyString &s1) const {
    return (strcmp(this->str, s1.get()) > 0);
}

// - лексографическое сравнение.
bool MyString::operator<(const MyString &s1) const {
    return (strcmp(this->str, s1.get()) < 0);
}

// - лексографическое сравнение.
bool MyString::operator>=(const MyString &s1) const {
    return (strcmp(this->str, s1.get()) >= 0);
}

//- лексографическое сравнение.
bool MyString::operator<=(const MyString &s1) const {
    return (strcmp(this->str, s1.get()) <= 0);
}

//  - у латинских букв меняется регистр.
MyString MyString::operator!()  {
    for (int i = 0; i < this->length(); ++i) {
        this->str[i] = std::isupper(this->str[i]) ? std::tolower(this->str[i]) : std::toupper(this->str[i]);
    }

    return *this;
}

//  - доступ к символу по индексу.
char &MyString::operator[](int k) const {
    return this->str[k];
}

// - поиск подстроки.
int MyString::operator()(const char *s) {
    std::string s0 = this->str;
    return s0.find(str);
}

// - чтение из потока.
std::ostream &operator<<(std::ostream &scr, MyString &s) {
    return scr << s.get();
}

// - запись в поток.
std::istream &operator>>(std::istream &scr, MyString &s) {
    return scr >> s.get();
}









