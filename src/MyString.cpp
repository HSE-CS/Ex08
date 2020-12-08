//  Copyright 2020 Trutnev Alexey

#include "MyString.h"

// Constructors
MyString::MyString(const char* new_ptr) {
    if (new_ptr == nullptr) {
        len = 0;
        string_ptr = nullptr;
    } else {
        len = strlen(new_ptr);
        string_ptr = new char[len + 1];
        for (size_t i = 0; i <= len; ++i)
            string_ptr[i] = new_ptr[i];
    }
}

MyString::MyString(std::string new_str) {
    len = new_str.size();
    string_ptr = new char[len + 1];
    for (size_t i = 0; i <= len; ++i)
        string_ptr[i] = new_str[i];
}

MyString::MyString(const MyString& new_str) {
    this->len = new_str.len;
    this->string_ptr = new char[len + 1];
    for (size_t i = 0; i <= len; ++i)
        string_ptr[i] = new_str.string_ptr[i];
}

MyString::MyString(MyString&& new_str) noexcept {
    this->len = new_str.len;
    this->string_ptr = new_str.string_ptr;
    new_str.len = 0;
    new_str.string_ptr = nullptr;
}

// Destructor
MyString::~MyString() {
    len = 0;
    delete[] string_ptr;
}

// Functions
size_t MyString::length() const {
    return len;
}

char* MyString::get() const {
    return string_ptr;
}

// Operators
MyString MyString::operator+(const MyString& new_str) {
    MyString temp_str;
    temp_str.len = this->len + new_str.len;
    temp_str.string_ptr = new char[temp_str.len + 1];
    for (size_t i = 0; i < this->len; ++i)
        temp_str.string_ptr[i] = this->string_ptr[i];
    if (new_str.string_ptr != nullptr) {
        for (size_t i = 0; i < new_str.len; ++i)
            temp_str.string_ptr[i + this->len] = new_str.string_ptr[i];
    }
    temp_str.string_ptr[temp_str.len] = '\0';
    return temp_str;
}

MyString MyString::operator-(const MyString& new_str) {
    if (new_str.string_ptr == nullptr)
        return *this;
    MyString temp_str;
    temp_str.len = 0;
    for (size_t i = 0; i < this->len; ++i) {
        bool check = true;
        for (size_t j = 0; j < new_str.len; ++j)
            if (this->string_ptr[i] == new_str.string_ptr[j])
                check = false;
        if (check)
            temp_str.len++;
    }
    temp_str.string_ptr = new char[temp_str.len + 1];
    size_t pointer = 0;
    for (size_t i = 0; i < this->len; ++i) {
        bool check = true;
        for (size_t j = 0; j < new_str.len; ++j)
            if (this->string_ptr[i] == new_str.string_ptr[j])
                check = false;
        if (check) {
            temp_str.string_ptr[pointer] = this->string_ptr[i];
            pointer++;
        }
    }
    temp_str.string_ptr[pointer] = '\0';
    return temp_str;
}

MyString MyString::operator*(size_t multiplier) {
    if (multiplier < 0)
        throw "Wrong multiplier";
    char* buffer = new char[multiplier * this->len + 1];
    size_t pointer = 0;
    for (size_t count = 0; count < multiplier; ++count)
        for (size_t i = 0; i < this->len; ++i) {
            buffer[pointer] = this->string_ptr[i];
            pointer++;
        }
    buffer[pointer] = '\0';
    return MyString(buffer);
}

MyString& MyString::operator=(const MyString& new_str) {
    if (new_str.string_ptr == nullptr) {
        this->len = 0;
        this->string_ptr = nullptr;
        return *this;
    }
    this->len = new_str.len;
    string_ptr = new char[new_str.len + 1];
    for (size_t i = 0; i <= this->len; ++i)
        this->string_ptr[i] = new_str.string_ptr[i];
    return *this;
}

MyString& MyString::operator=(MyString&& new_str) noexcept {
    this->len = new_str.len;
    this->string_ptr = new_str.string_ptr;
    new_str.len = 0;
    new_str.string_ptr = nullptr;
    return *this;
}

bool MyString::operator==(const MyString& new_str) {
    return strcmp(this->string_ptr, new_str.string_ptr) == 0;
}

bool MyString::operator!=(const MyString& new_str) {
    return strcmp(this->string_ptr, new_str.string_ptr) != 0;
}

bool MyString::operator>(const MyString& new_str) {
    return strcmp(this->string_ptr, new_str.string_ptr) == 1;
}

bool MyString::operator<(const MyString& new_str) {
    return strcmp(this->string_ptr, new_str.string_ptr) == -1;
}

bool MyString::operator>=(const MyString& new_str) {
    return strcmp(this->string_ptr, new_str.string_ptr) != -1;
}

bool MyString::operator<=(const MyString& new_str) {
    return strcmp(this->string_ptr, new_str.string_ptr) != 1;
}

MyString MyString::operator!() {
    if (nullptr == this->string_ptr)
        return MyString(nullptr);
    char* new_str = new char[this->len + 1];
    size_t ptr = 0;
    for (size_t i = 0; i < this->len; ++i) {
        if (this->string_ptr[i] >= 'a' && this->string_ptr[i] <= 'z')
            new_str[ptr] = static_cast<char>(this->string_ptr[i] - 'a' + 'A');
        else if (this->string_ptr[i] >= 'A' && this->string_ptr[i] <= 'Z') {
            new_str[ptr] = static_cast<char>(this->string_ptr[i] - 'A' + 'a');
        }else
            new_str[ptr] = this->string_ptr[i];
        ptr++;
    }
    new_str[ptr] = '\0';
    return MyString(new_str);
}

char& MyString::operator[](int index) const {
    if (index < 0 || index > this->len || this->string_ptr == nullptr)
        throw "nullptr in operator[]";
    return this->string_ptr[index];
}

int MyString::operator()(const char* new_str) const {
    if (new_str == nullptr || string_ptr == nullptr)
        throw "nullptr in operator()";
    char* search = strstr(this->string_ptr, new_str);
    return search == nullptr ? -1 : static_cast<int>(search - this->string_ptr);
}

std::ostream& operator<<(std::ostream& output_buf, MyString& new_str) {
    if (new_str.string_ptr == nullptr)
        throw "nullptr in operator<<";
    return output_buf << new_str.get();
}

std::istream& operator>>(std::istream& input_buf, MyString& new_str) {
    std::string buf;
    input_buf >> buf;
    new_str = MyString(buf);
    return input_buf;
}
