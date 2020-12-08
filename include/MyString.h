// Copyrignt 2020 Bekusov Mikhail

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <cstring>
#include <string>
#include <sstream>

class MyString {
 private:
    char *s;

 public:
    explicit MyString(const char *str = nullptr);

    explicit MyString(const std::string &str);

    MyString(const MyString &str);

    MyString(MyString &&str);

    ~MyString();

    size_t length() const;

    char *get() const;

    MyString operator+(const MyString &str);

    MyString operator-(const MyString &str);

    MyString operator*(int n);

    MyString operator=(const MyString &str);

    MyString operator=(MyString &&str) noexcept;

    bool operator==(const MyString &str);

    bool operator!=(const MyString &str);

    bool operator>(const MyString &str);

    bool operator<(const MyString &str);

    bool operator>=(const MyString &str);

    bool operator<=(const MyString &str);

    MyString operator!();

    char &operator[](int i);

    int operator()(const char *str);

    friend std::ostream &operator<<(std::ostream &os, MyString &str);

    friend std::istream &operator>>(std::istream &is, MyString &str);
};
#endif  // INCLUDE_MYSTRING_H_
