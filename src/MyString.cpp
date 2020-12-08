#include <string>
#include <cstring>
#include <iostream>
#include "MyString.h"
MyString::MyString(const char* mystring_value) {
    if (mystring_value != nullptr)
        this->string_container = strdup(mystring_value);
    else
        this->string_container = new char[1];
}
MyString::MyString(const std::string mystring_value) {
    this->string_container = strdup(mystring_value.c_str());
}
MyString::MyString(const MyString& other_mystring) {
    this->string_container = strdup(other_mystring.string_container);
}
MyString::MyString(MyString&& other_mystring)
    : string_container(other_mystring.string_container) {
    other_mystring.string_container = nullptr;
}
MyString:: ~MyString() {
    delete this->string_container;
}
unsigned int MyString::length() const {
    return strlen(this->string_container);
}
char* MyString::get() const {
    return this->string_container;
}
MyString MyString::operator+(const MyString& other_mystring) {
    unsigned int new_len = strlen(this->string_container)
        + strlen(other_mystring.get());
    char* buf = new char[new_len + 1];
    snprintf(buf, new_len + 1, "%s%s",
        this->string_container, other_mystring.get());
    MyString new_mystring(buf);
    delete[] buf;
    return new_mystring;
}
MyString MyString::operator-(const MyString& other_mystring) {
    unsigned int my_len = strlen(this->string_container);
    unsigned int other_len = strlen(other_mystring.get());
    char* buf = new char[my_len + 1];
    unsigned int new_index = 0;
    for (unsigned int my_index = 0; my_index < my_len; my_index++) {
        bool is_consist = false;
        for (unsigned int other_index = 0; other_index < other_len; other_index++)
            if (this->string_container[my_index] == other_mystring[other_index]) {
                is_consist = true;
                break;
            }
        if (!is_consist) {
            buf[new_index++] = this->string_container[my_index];
        }
    }
    MyString new_mystring(buf);
    delete[] buf;
    return new_mystring;
}
MyString MyString::operator*(unsigned int num) {
    unsigned int old_len = strlen(this->string_container);
    unsigned int new_len = old_len * num;
    char* buf = new char[new_len + 1];
    for (int i = 0; i < num; i++)
    snprintf(buf + old_len * i,
        old_len + 1, "%s%s", buf, this->string_container);
    MyString new_mystring(buf);
    delete[] buf;
    return new_mystring;
}
MyString& MyString::operator=(const MyString& other_mystring) {
    this->string_container = strdup(other_mystring.string_container);
    return *this;
}
MyString& MyString::operator=(MyString&& other_mystring) {
    this->string_container = other_mystring.get();
    other_mystring.string_container = nullptr;
    return *this;
}
bool MyString::operator==(const MyString& other_mystring) const {
    return !strcmp(this->string_container, other_mystring.get());
}
bool MyString::operator!=(const MyString& other_mystring) const {
    return strcmp(this->string_container, other_mystring.get());
}
bool MyString::operator>(const MyString& other_mystring) const {
    return (strcmp(this->string_container, other_mystring.get()) == 1);
}
bool MyString::operator<(const MyString& other_mystring) const {
    return (strcmp(this->string_container, other_mystring.get()) == -1);
}
bool MyString::operator>=(const MyString& other_mystring) const {
    return (strcmp(this->string_container, other_mystring.get()) > -1);
}
bool MyString::operator<=(const MyString& other_mystring) const {
    return (strcmp(this->string_container, other_mystring.get()) < 1);
}
MyString MyString::operator!() {
    unsigned int my_len = strlen(this->string_container);
    char* buf = new char[my_len + 1];
    for (int i = 0; i < my_len; i++) {
        buf[i] = this->string_container[i];
        if (this->string_container[i] >= 65 && this->string_container[i] <= 90)
            buf[i] = this->string_container[i] + 32;
        if (this->string_container[i] >= 97 && this->string_container[i] <= 122)
            buf[i] = this->string_container[i] - 32;
    }
    MyString new_mystring(buf);
    delete[] buf;
    return new_mystring;
}
char MyString::operator[](unsigned int index) const {
    return this->string_container[index];
}
int MyString::operator()(const char* sub_string) const {
    unsigned int sub_index = 0;
    unsigned int len = strlen(this->string_container);
    for (int my_index = 0; my_index < len; my_index++) {
        if (this->string_container[my_index] == sub_string[sub_index]) {
            sub_index += 1;
            if (sub_index >= strlen(sub_string))
                return my_index - strlen(sub_string) + 1;
        }
        else {
            sub_index = 0;
        }
    }
    return -1;
}
std::ostream& operator<<(std::ostream& output, MyString& mystring) {
    return output << mystring.get();
}
std::istream& operator>>(std::istream& input, MyString& mystring) {
    unsigned int len = input.gcount() + 1;
    std::string new_str;
    std::getline(input, new_str);
    mystring = MyString(new_str);
    return input;
}
