// Copyright 2020 jswark
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

class MyString {
 public:
  char* m_Str = new char;

  explicit MyString(const char* = nullptr);
  explicit MyString(const std::string& str);
  MyString(const MyString&);  // конструктор копирования.
  MyString(MyString&&);  // конструктор переноса.
  ~MyString();  // деструктор.
  size_t length() const;  // количество символов (длина строки).
  char* get() const;

  MyString operator+(const MyString &) const;
  MyString operator-(const MyString &) const;
  MyString operator*(int) const;

  MyString& operator=(const MyString &);  // копирующее присваивание.
  MyString& operator=(MyString &&);  // перемещающее присваивание.

  bool operator==(const MyString&) const;  // сравнение на равенство.
  bool operator!=(const MyString& str) const;  // сравнение на неравенство.
  bool operator>(const MyString& str) const;  // лексографическое сравнение .
  bool operator<(const MyString& str) const;  // лексографическое сравнение.
  bool operator>=(const MyString& str) const;  // лексографическое сравнение.
  bool operator<=(const MyString& str) const;  // лексографическое сравнение.

  MyString& operator!();  // у латинских букв меняется регистр.
  char operator[](int) const;  // доступ к символу по индексу.
  int operator()(const char*);  // поиск подстроки.

  friend std::ostream &operator>>(std::ostream&, MyString&);
  friend std::istream &operator>>(std::istream&, MyString&);  // запись в поток.
};

#endif  // INCLUDE_MYSTRING_H_
