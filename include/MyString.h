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
    MyString(const MyString &OldString);
    MyString(MyString &&OldString) noexcept;
    ~MyString();
    [[nodiscard]] int length() const;
    [[nodiscard]] char *get() const;

    ////////////////////////////////////////////

    MyString operator+(const MyString &PlusString);
    MyString operator-(const MyString &MinusString);
    MyString operator*(int num) const;
    MyString &operator=(MyString const &CopyString);
    MyString &operator=(MyString &&MoveString) noexcept;
    MyString operator!() const;

    ////////////////////////////////////////////

    bool operator==(const MyString &CompareString) const;
    bool operator!=(const MyString &CompareString) const;
    bool operator>(const MyString &CompareString);
    bool operator<(const MyString &CompareString);
    bool operator>=(const MyString &CompareString);
    bool operator<=(const MyString &CompareString);

    ////////////////////////////////////////////

    char operator[](int index);
    int operator()(const char *substring);
    friend std::ostream &operator<<(std::ostream &Str, MyString &String);
    friend std::istream &operator>>(std::istream &Str, MyString &String);
};

#endif  // INCLUDE_MYSTRING_H_
