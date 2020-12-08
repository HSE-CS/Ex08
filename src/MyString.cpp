// Copyright Nikolaev Ivan


#include "MyString.h"

MyString::MyString(const char* strin) {
    if (strin != nullptr) {
        int length = strlen(strin) + 1;
        char* newStr = new char[length];
        for (int i = 0; i < strlen(strin); ++i) {
            newStr[i] = strin[i];
        }
        newStr[length - 1] = '\0';
        this->str = newStr;
    }
    else {
        char* newStr = new char[1];
        newStr[0] = '\0';
        this->str = newStr;
    }
}

MyString::MyString(std::string str) {
    char* tempString = new char[str.length() + 1];
    for (int i = 0; i < str.length(); i++) {
        tempString[i] = str[i];
    }
    tempString[str.length()] = '\0';
    this->str = tempString;
}

MyString::MyString(const MyString &str) {
    this->str = str.str;
}

MyString::MyString(MyString&& strin) {
 //   this->str = strin.str;
    int length = strin.length();
    char* tmp = new char[length + 1];
    for (int i = 0; i < length; i++) {
        tmp[i] = strin[i];
    }
    tmp[length] = '\0';
    this->str = tmp;
//    strin.str = nullptr;
}

MyString::~MyString() { }

int MyString::length() {
    return strlen(str);
}

char* MyString::get() {
    return str;
}

MyString MyString::operator+(MyString& myString) {
    int summaryLength = this->length() + myString.length();
    char* tempString = new char[summaryLength + 1];
    for (int i = 0; i < this->length(); i++) {
        tempString[i] = str[i];
    }
    for (int i = this->length(); i < summaryLength; i++) {
        tempString[i] = myString.str[i- this->length()];
    }
    tempString[summaryLength] = '\0';
    MyString result(tempString);
    return result;
}

MyString MyString::operator-(MyString& myString) {
    std::string s(this->get());
    for (char ch : std::string(myString.get())) {
        while (s.find(ch) != -1) {
            s.erase(s.find(ch), 1);
        }
    }
    return MyString(s);
}

MyString MyString::operator*(int num) {
    char* res = new char[(this->length() * num) + 1];
    int j = 0;
    for (int i = 0; i < this->length() * num; i++) {
        res[i] = this->str[j];
        j++;
        if (j == this->length()) {
            j = 0;
        }
    }
    res[this->length() * num] = '\0';
    MyString result(res);
    return result;
}

MyString MyString::operator=(MyString& myString) {
    this->str = myString.str;
    return *this;
}

MyString MyString::operator=(MyString&& myString) {
    this->str = myString.str;
    myString.str = nullptr;
    return *this;
}

bool MyString::operator==(MyString& myString) {
    bool result = !strcmp(this->get(), myString.str);
    return result;
}

bool MyString::operator!=(MyString& myString) {
    bool result = strcmp(this->get(), myString.str);
    return result;
}

bool MyString::operator>(MyString& myString) {
    bool result = (strcmp(str, myString.str) > 0);
    return result;
}

bool MyString::operator<(MyString& myString) {
    bool result = (strcmp(str, myString.str) < 0);
    return result;
}

bool MyString::operator>=(MyString& myString) {
    bool result = (strcmp(str, myString.str) >= 0);
    return result;
}

bool MyString::operator<=(MyString& myString) {
    bool result = (strcmp(str, myString.str) <= 0);
    return result;
}

MyString MyString::operator!() {
    char* res = new char[length() + 1];
    for (int i = 0; i < length(); i++) {
        if (this->str[i] >= 65 && this->str[i] <= 90) {
            res[i] = str[i] + 32;
        }
        else if (this->str[i] >= 97 && this->str[i] <= 122) {
            res[i] = str[i] - 32;
        } else {
            res[i] = str[i];
        }
    }
    res[length()] = '\0';
    MyString result(res);
    return result;
}

char MyString::operator[](int index) {
    if (index < 0 || index >= this->length()) {
        throw "IndexOutOfBoundsException";
    } else {
        return str[index];
    }
}

int MyString::operator()(const char* str) {
    char* res = strstr(this->str, str);
    if (res == nullptr)
        return -1;
    else
        return (res - this->str);
}

std::ostream& operator<<(std::ostream& stream, MyString& str) {
    return stream << str.get();
}

std::istream& operator>>(std::istream& stream, MyString& str) {
    return stream >> str.get();
}