// Copyright Mushka Nikita 2020

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <iostream>
#include <string>
#include <cstring>

class MyString {
 private:
    char *string;

 public:
    MyString();

    explicit MyString(std::string str);

    MyString(MyString &OldString);

    MyString(MyString &&OldString) noexcept;

    ~MyString();

    [[nodiscard]] int length() const;

    char *get();

    ////////////////////////////////////////////

    MyString operator+(MyString &PlusString);

    MyString operator-(MyString &MinusString);

    MyString operator*(int num);

    MyString &operator=(MyString const &CopyString);

    MyString &operator=(MyString &&MoveString) noexcept;

    MyString operator!();

    ////////////////////////////////////////////

    bool operator==(MyString &CompareString);

    bool operator!=(MyString &CompareString);

    bool operator>(MyString &CompareString);

    bool operator<(MyString &CompareString);

    bool operator>=(MyString &CompareString);

    bool operator<=(MyString &CompareString);

    ////////////////////////////////////////////

    char operator[](int index);

    int operator()(const char *substring);

    friend std::ostream &operator<<(std::ostream &Str, MyString &String);

    friend std::istream &operator>>(std::istream &Str, MyString &String);

};

#endif //INCLUDE_MYSTRING_H_
