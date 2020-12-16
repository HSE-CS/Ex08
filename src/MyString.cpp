// Copyright Mushka Nikita 2020

#include "MyString.h"

MyString::MyString() {
    this->string = nullptr;
}

MyString::MyString(std::string str) {
    int newLen = static_cast<int>(str.length() + 1);
    char *newString = new char[newLen];
    for (int i = 0; i < newLen; i++) newString[i] = str[i];
    this->string = newString;
}

MyString::MyString(const MyString &OldString) {
    int newLen = OldString.length() + 1;
    char *newString = new char[newLen];
    for (int i = 0; i < newLen; i++) newString[i] = OldString.string[i];
    this->string = newString;
}

MyString::MyString(MyString &&OldString) noexcept {
    this->string = OldString.string;
    OldString.string = nullptr;
}

MyString::~MyString() {
    delete this->string;
}

char * MyString::get() const{
    if (this->string == nullptr) {
        return const_cast<char *>("");
    } else { return this->string; }
}

int MyString::length() const {
    if (this->string == nullptr) return 0;
    return strlen(this->string);
}

//////////////////////////////////////////////////////////////////

MyString MyString::operator+(const MyString &PlusString) {
    int len1 = this->length();
    int len2 = PlusString.length();
    if (len2 == 0) len1++;
    char *newString = new char[len1 + len2];
    for (int i = 0; i < len1 + 1; i++) newString[i] = this->string[i];
    for (int i = len1; i < len1 + len2; i++)
        newString[i] = PlusString.get()[i - len1];
    return MyString(newString);
}

MyString MyString::operator-(const MyString &MinusString) {
    std::string result(this->string);
    int len1 = this->length();
    int len2 = MinusString.length();
    for (int i = 0; i < len2; i++) {
        char toErase = MinusString.string[i];
        for (int j = 0; j < len1; j++) {
            if (result[j] == toErase) {
                result.erase(j, 1);
                j--;
            }
        }
    }
    return MyString(result);
}

MyString MyString::operator*(int num) const {
    std::string result;
    for (int i = 0; i < num; i++) {
        result.append(this->get());
    }
    return MyString(result);
}

MyString &MyString::operator=(MyString const &CopyString) {
    delete this->string;
    this->string = CopyString.string;
    return *this;
}

MyString &MyString::operator=(MyString &&MoveString) noexcept {
    delete string;
    this->string = MoveString.string;
    MoveString.string = nullptr;
    return *this;
}

MyString MyString::operator!() const {
    std::string result(this->get());
    for (char &i : result) {
        char x = i;
        if ('a' <= x && x <= 'z')
            i -= 32;
        else if ('A' <= x && x <= 'Z')
            i += 32;
    }
    return MyString(result);
}

///////////////////////////////////////////////////////////////

bool MyString::operator==(const MyString &CompareString) const {
    return !strcmp(this->get(), CompareString.get());
}

bool MyString::operator!=(const MyString &CompareString) const {
    return strcmp(this->get(), CompareString.get());
}

bool MyString::operator>(const MyString &CompareString) {
    return (strcmp(this->string, CompareString.string) == 1);
}

bool MyString::operator<(const MyString &CompareString) {
    return (strcmp(this->string, CompareString.string) == -1);
}

bool MyString::operator>=(const MyString &CompareString) {
    return (strcmp(this->string, CompareString.string) > -1);
}

bool MyString::operator<=(const MyString &CompareString) {
    return (strcmp(this->string, CompareString.string) < 1);
}

///////////////////////////////////////////////////////////////

char MyString::operator[](int index) {
    if (index > this->length()) throw;
    return this->string[index];
}

int MyString::operator()(const char *substring) {
    char *result = strstr(this->get(), substring);
    if (result == nullptr) {
        return -1;
    } else {
        return  static_cast<int>(result - this->get());
    }
}

std::ostream &operator<<(std::ostream &Str, MyString &String) {
    return Str << String.get();
}

std::istream &operator>>(std::istream &Str, MyString &String) {
    return Str >> String.get();
}
