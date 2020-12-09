// Copyright 2020 Vladimir Uspensky

#include "MyString.h"

MyString::MyString(const char *string) {
    if (string == nullptr){
        str_length = 0;
        my_string = nullptr;
    } else {
        str_length = strlen(string);
        my_string = new char [str_length + 1];
        for (size_t i = 0; i < str_length + 1; i++) my_string[i] = string[i];
    }
}

MyString::MyString(const std::string& string) {
    str_length = string.size();
    my_string = new char [str_length + 1];
    for (size_t i = 0; i < str_length; i++) my_string[i] = string[i];
}
MyString::MyString(const MyString &string) {
    str_length = string.str_length;
    my_string = new char [str_length + 1];
    for (size_t i = 0; i < str_length; i++) my_string[i] = string.my_string[i];
}

MyString::MyString(MyString &&string) {
    my_string = string.my_string;
    str_length = string.str_length;
    string.my_string = nullptr;
    string.str_length = 0;
}

MyString::~MyString() {
    delete [] my_string;
}

int MyString::length() const {
    return this->str_length;
}

char * MyString::get() const {
    return this->my_string;
}


MyString MyString::operator+(const MyString &str) {
    int overall_length = str_length + str.str_length;
    char *new_str = new char[overall_length];
    for (size_t i = 0; i < str_length; i++) new_str[i] = my_string[i];
    for (size_t i = str_length; i < overall_length; i++) new_str[i] = str.my_string[i - str_length];
    new_str[str_length - 1] = '\0';
    MyString result_str = MyString(new_str);
    return result_str;
}

MyString MyString::operator-(const MyString &str) {
    std::vector<int> indexes;
    bool flag = false;
    unsigned int cnt = 0;
    for (size_t i = 0; i < str_length; i++) {
        for (size_t j = 0; j < str.str_length; j++){
            if (my_string[i] == str.my_string[j]) indexes.push_back(i);
        }
    }
    char *new_str = new char [str_length - indexes.size()];
    for (size_t i = 0; i < str_length; i++){
        for (auto j : indexes){
            if (my_string[i] == j) flag = true;
        }
        if (!flag) {
            new_str[cnt] = my_string[i];
            cnt += 1;
        }
    }
    return MyString(new_str);
}

MyString MyString::operator*(int num) {
    char *new_str = new char [str_length * num + 1];
    unsigned int cnt = 0;
    for (size_t i = 0; i < num; i++){
        for (size_t j = i * str_length; j < (i + 1) * str_length; j++) new_str[j] = my_string[j - i * str_length];
    }
    new_str[str_length * num] = '\0';
    return MyString(new_str);
}

MyString & MyString::operator=(const MyString &string) {
    my_string = string.my_string;
    str_length = string.str_length;
    return *this;
}

MyString & MyString::operator=(MyString &&string) {
    my_string = string.my_string;
    str_length = string.str_length;
    string.my_string = nullptr;
    string.str_length = 0;
    return *this;
}

bool MyString::operator==(const MyString &string) {
    return strcmp(my_string, string.my_string) == 0;
}

bool MyString::operator!=(const MyString &string) {
    return strcmp(my_string, string.my_string) != 0;
}

bool MyString::operator<(const MyString &string) {
    return strcmp(my_string, string.my_string) < 0;
}

bool MyString::operator>(const MyString &string) {
    return strcmp(my_string, string.my_string) > 0;
}

bool MyString::operator>=(const MyString &string) {
    return strcmp(my_string, string.my_string) >= 0;
}

bool MyString::operator<=(const MyString &string) {
    return strcmp(my_string, string.my_string) <= 0;
}

MyString MyString::operator!() {
    for (int i = 0; i < str_length; ++i) {
        if (my_string[i] >= 'A' && my_string[i] <= 'Z') {
            my_string[i] += 'a' - 'A';
        } else if (my_string[i] >= 'a' && my_string[i] <= 'z') {
            my_string[i] -= 'a' - 'A';
        }
    }
    return MyString(my_string);
}

char & MyString::operator[](int i) {
    return my_string[i];
}

int MyString::operator()(const char *string) {
    int substring_length = strlen(string);
    for (size_t i = 0; i < str_length - substring_length + 1; i++) {
        bool flag = true;
        for (size_t j = 0; j < substring_length; j++) {
            if (string[i + j] != string[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

std::istream &operator>>(std::istream &input, MyString &string) {
    return input >> string.get();
}

std::ostream &operator<<(std::ostream &output, MyString &string) {
    return output << string.get();
}
