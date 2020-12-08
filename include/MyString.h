// Copyright 2020 mkhorosh
#ifndef MYSTRING_H
#define MYSTRING_H
#include <string>

class MyString {
 private:
  char *string;
 public:
  explicit MyString(const char *nstring = nullptr); // pointer
  explicit MyString(const std::string &nstring); // string
  MyString(const MyString &nstring); // copy
  MyString(MyString &&nstring); // moving(r-value)
  ~MyString(); // destruct
  int length() const; // string length
  char *get() const; // get pointer
  MyString operator+(const MyString &str) const; // concatenation
  MyString operator-(const MyString &str) const;
  MyString operator*(int n) const;
  MyString &operator=(const MyString &str); // копирующее присваивание
  MyString &operator=(MyString &&str); // перемещающее присваивание
  bool operator==(const MyString &str) const; // сравнение на равенство
  bool operator!=(const MyString &str) const; // сравнение на неравенство
  bool operator>(const MyString &str) const; // лексографическое сравнение
  bool operator<(const MyString &str) const; // лексографическое сравнение
  bool operator>=(const MyString &str) const; // лексографическое сравнение
  bool operator<=(const MyString &str) const; // лексографическое сравнение
  MyString &operator!(); // у латинских букв меняется регистр
  char operator[](int i) const; // доступ к символу по индексу
  int operator()(const char *ss); // поиск подстроки
  friend std::ostream &operator<<(std::ostream &stream, MyString &str); // запись в поток
  friend std::istream &operator>>(std::istream &stream, MyString &str); // чтение из потока
};

#endif
