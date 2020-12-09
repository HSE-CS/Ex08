// Copyright 08.12.20 DenisKabanov

#include"MyString.h"

MyString::MyString(const char* str) {
    if (str == nullptr) {
        this->lenofstr = 0;
        this->string = nullptr;
    } else {
        this->lenofstr = strlen(str);
        this->string = new char[this->lenofstr + 1];
        for (int i = 0; i < this->lenofstr + 1; i++) {
            this->string[i] = str[i];
        }
    }
}

MyString::MyString(std::string string) {
    this->lenofstr = string.size();
    this->string = new char[this->lenofstr + 1];
    for (int i = 0; i < lenofstr + 1; i++) {
        this->string[i] = string[i];
    }
}

MyString::MyString(const MyString& prevstring) {
    this->lenofstr = prevstring.lenofstr;
    this->string = new char[this->lenofstr+1];
    for (int i = 0; i < this->lenofstr + 1; i++) {
        this->string[i] = prevstring.string[i];
    }
}

MyString::MyString(MyString&& prevstring) {
    this->lenofstr = prevstring.lenofstr;
    this->string = prevstring.string;
    prevstring.lenofstr = 0;
    prevstring.string = nullptr;
}

MyString::~MyString() {
    delete []string;
}

int MyString::length() {
    return this->lenofstr;
}

char* MyString::get() {
    return string;
}

MyString MyString::operator+(const MyString& astring) {
    char* summ = new char[this->lenofstr + astring.lenofstr + 1];
    if (astring.lenofstr != 0) {
        for (int i = 0; i < this->lenofstr; i++) {
            summ[i] = this->string[i];
        }
        for (int j = this->lenofstr;
            j < this->lenofstr + astring.lenofstr + 1; j++) {
            summ[j] = astring.string[j - this->lenofstr];
        }
    } else {
        for (int i = 0; i < this->lenofstr + 1; i++) {
            summ[i] = this->string[i];
        }
    }
    return MyString(summ);
}

MyString MyString::operator-(const MyString& string) {
    std::string str2 = std::string(this->string,
        this->string + this->lenofstr);
    for (int i = 0; i < string.lenofstr; i++) {
        str2.erase(std::remove(str2.begin(), str2.end(),
            string.string[i]), str2.end());
    }
    return MyString(str2);
}

MyString MyString::operator*(const int number) {
    MyString mult;
    for (int i = 0; i < number; i++) {
        mult = mult + *this;
    }
    return mult;
}

MyString& MyString::operator=(const MyString& string) {
    this->lenofstr = string.lenofstr;
    this->string = new char[lenofstr + 1];
    for (int i = 0; i < this->lenofstr + 1; i++) {
        this->string[i] = string.string[i];
    }
    return *this;
}

MyString& MyString::operator=(MyString&& string) {
    this->lenofstr = string.lenofstr;
    this->string = string.string;
    string.lenofstr = 0;
    string.string = nullptr;
    return *this;
}

bool MyString::operator==(const MyString& string) {
    if (strcmp(this->string, string.string) == 0) {
        return true;
    } else {
        return false;
    }
}

bool MyString::operator!=(const MyString& string) {
    if (strcmp(this->string, string.string) == 0) {
        return false;
    } else {
        return true;
    }
}

bool MyString::operator>(const MyString& string) {
    if (strcmp(this->string, string.string) > 0) {
        return true;
    } else {
        return false;
    }
}

bool MyString::operator<(const MyString& string) {
    if (strcmp(this->string, string.string) < 0) {
        return true;
    } else {
    return false;
    }
}

bool MyString::operator>=(const MyString& string) {
    if (strcmp(this->string, string.string) >= 0) {
        return true;
    } else {
        return false;
    }
}

bool MyString::operator<=(const MyString& string) {
    if (strcmp(this->string, string.string) <= 0) {
        return true;
    } else {
        return false;
    }
}

MyString MyString::operator!() {
    char* str2 = new char[lenofstr + 1];
    for (int i = 0; i < this->lenofstr + 1; i++) {
        str2[i] = this->string[i];
    }
    for (int i = 0; i < lenofstr; i++) {
        if ((str2[i] >= 'a') && (str2[i] <= 'z'))
            str2[i] = str2[i] + ('A' - 'a');
        else if (str2[i] >= 'A' && str2[i] <= 'Z')
            str2[i] = str2[i] + ('a' - 'A');
    }
    return MyString(str2);
}

char MyString::operator[](const int number) {
    return this->string[number];
}

int MyString::operator()(const char* string) {
    char* pointer = strstr(this->string, string);
    if (pointer == nullptr) {
        return -1;
    } else {
        std::cout << "Same from: " << pointer - this->string << std::endl;
        return pointer - this->string;
    }
}

std::istream& operator>>(std::istream& is, MyString& str) {
	return is >> str.get();
}

std::ostream& operator<<(std::ostream& os, MyString& str) {
    return os << str.get();
}