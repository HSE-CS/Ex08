// Copyright 2020 GHA created by Klykov Anton

#include "MyString.h"

MyString::MyString(const char* _str) {
    if (_str == nullptr) {
        _string = nullptr;
        _length = 0;
    } else {
        size_t i = 0;
        while (_str[i] != '\0') {
            i++;
        }
        _string = new char[i + 1];
        _length = i;
        i = 0;
        for (; i < _length; ++i) {
            _string[i] = _str[i];
        }
        _string[i] = '\0';
    }
}

MyString::MyString(std::string _str) {
    _length = _str.size();
    _string = new char[_length + 1];
    size_t i = 0;
    for (; i < _length; ++i) {
        _string[i] = _str[i];
    }
    _string[i] = '\0';
}

MyString::MyString(const MyString& _str) {
    this->_length = _str._length;
    this->_string = new char[_length + 1];
    size_t i = 0;
    for (; i < this->_length; ++i) {
        _string[i] = _str._string[i];
    }
    _string[i] = '\0';
}

MyString::MyString(MyString&& _str)  noexcept {
    _string = _str._string;
    _length = _str._length;
    _str._string = nullptr;
    _str._length = 0;
}

MyString::~MyString() {
    delete [] _string;
}

unsigned int MyString::length() {
    return _length;
}

char* MyString::get() {
    return _string;
}

MyString MyString::operator+(const MyString& _str) {
    std::string str(this->_string);
    if (_str._string != nullptr) {
        str.append(_str._string);
        return MyString(str);
    } else {
        return *this;
    }
}

MyString MyString::operator-(const MyString& _str) {
    std::string _fstr(_str._string);
    std::string _temp;
    size_t i{0};
    while (i < _length) {
        if (_fstr.find(_string[i], 0) == std::string::npos) {
            _temp.push_back(_string[i]);
        }
        i++;
    }
    return MyString(_temp);
}

MyString MyString::operator*(int val) {
    MyString _temporary(*this);
    for (size_t i = 0; i < val - 1; ++i) {
        _temporary = *this + _temporary;
    }
    return _temporary;
}

MyString& MyString::operator=(const MyString& _str) {
    if (&_str == this) {
        return *this;
    } else if (_str._string == nullptr) {
        _length = 0;
        _string = nullptr;
        return *this;
    }
    this->_length = _str._length;
    this->_string = new char[length() + 1];
    size_t i = 0;
    for (; i < this->_length; ++i) {
        _string[i] = _str._string[i];
    }
    _string[i] = '\0';
    return *this;
}

MyString& MyString::operator=(MyString&& _str) {
    if (&_str == this) {
        return *this;
    }
    delete [] _string;
    _string = _str._string;
    _length = _str._length;
    _str._string = nullptr;
    _str._length = 0;
    return *this;
}

bool MyString::operator==(const MyString& _str) {
    return (strcmp(_string, _str._string) == 0);
}

bool MyString::operator!=(const MyString& _str) {
    return (strcmp(_string, _str._string) != 0);
}

bool MyString::operator>(const MyString& _str) {
    return (strcmp(_string, _str._string) > 0);
}

bool MyString::operator<(const MyString& _str) {
    return (strcmp(_string, _str._string) < 0);
}

bool MyString::operator>=(const MyString& _str) {
    return (strcmp(_string, _str._string) >= 0);
}

bool MyString::operator<=(const MyString& _str) {
    return (strcmp(_string, _str._string) <= 0);
}

MyString MyString::operator!() {
    MyString _temporary;
    _temporary._length = _length;
    _temporary._string = new char[_length + 1];
    for (size_t i = 0; i < _length; ++i) {
        if (_string[i] <= 122 && _string[i] >= 97) {
            _temporary._string[i] = _string[i] - 32;
        } else if (_string[i] <= 90 && _string[i] >= 65) {
            _temporary._string[i] = _string[i] + 32;
        } else if (_string[i] >= 49 && _string[i] <= 57) {
            _temporary._string[i] = _string[i];
        }
    }
    _temporary._string[_length] = '\0';
    return _temporary;
}

char& MyString::operator[](const unsigned int val) {
    return _string[val];
}

int MyString::operator()(const char* _str) {
    if (strstr(_string, _str) == nullptr) {
        return -1;
    } else {
        return 0;
    }
}

std::ostream& operator<<(std::ostream& out, MyString& _str) {
    return out << _str.get();
}

std::istream& operator>>(std::istream& in, MyString& _str) {
    std::string _temp;
    in >> _temp;
    _str = MyString(_temp);
    return in;
}
