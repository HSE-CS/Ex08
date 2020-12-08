// Created by mila on 08.12.2020.

#include <iostream>
#include <string>

#ifndef EX08_MYSTRING_H
#define EX08_MYSTRING_H

class MyString {
private:
    char *str = new char;
public:

    explicit MyString(const char * = nullptr);           // - конструктор с одним параметром (есть значение по-умолчанию nullptr).
    explicit MyString(const std::string&);            // - конструктор с одним параметром.
    MyString(const MyString &);                // - конструктор копирования.
    MyString(MyString &&);                     // - конструктор переноса.
    ~MyString();                               // - деструктор.
    int length() const;                        // - количество символов (длина строки).
    char* get() const;                         // - возвращение указателя на данные (тип char*).

    MyString operator+(const MyString &);       // сложение (конкатенация двух строк).
    MyString operator-(const MyString &);       // вычитание (из первой строки удаляются все символы, присутствующие во второй строке).
    MyString operator*(int);                    // умножение на целое число (строка повторяется заданное число раз).
    MyString &operator=(const MyString &);      // - копирующее присваивание.
    MyString &operator=(MyString &&);           // - перемещающее присваивание.

    char &operator[](int) const;             //  - доступ к символу по индексу.
    int operator()(const char *);            // - поиск подстроки.

    friend std::ostream &operator<<(std::ostream &, MyString &);      // - чтение из потока.
    friend std::istream &operator>>(std::istream &, MyString &);      // - запись в поток.

    bool operator==(const MyString &) const;       // - сравнение на равенство.
    bool operator!=(const MyString &) const;       // - сравнение на неравенство.
    bool operator>(const MyString &) const;        //  - лексографическое сравнение .
    bool operator<(const MyString &) const;        // - лексографическое сравнение.
    bool operator>=(const MyString &) const;       // - лексографическое сравнение.
    bool operator<=(const MyString &) const;       //- лексографическое сравнение.

    MyString operator!();    //  - у латинских букв меняется регистр.

};

#endif //EX08_MYSTRING_H
