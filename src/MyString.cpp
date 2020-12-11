#include "MyString.h"

MyString::MyString(const char* _str) {
    if (_str == nullptr) {
        _string = nullptr;
        _length = 0;
    } else {
        size_t i = 0;
        size_t length_str = 0;
        while (_str[i] != '\0') {
            length_str++;
            i++;
        }
        _string = new char[length_str + 1];
        _length = length_str;
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

MyString::MyString(MyString&& _str) :
_string(_str._string), _length(_str._length) {
    _str._string = nullptr;
}

MyString::~MyString() {
    delete [] _string;
    _string = nullptr;
}

unsigned int MyString::length() {
    return _length;
}

char* MyString::get() {
    return _string;
}

MyString MyString::operator+(const MyString& _str) {
    unsigned int _temp_length = this->length() + _str._length;
    char* _tem = new char[_temp_length + 1];
    size_t i = 0;
    while (this->_string[i] != '\0') {
        _tem[i] = this->_string[i];
        i++;
    }
    size_t k{0};
    while (_str._string[k] != '\0') {
        _tem[i] = _str._string[k];
        k++;
        i++;
    }
    _tem[_temp_length] = '\0';
    MyString _temporary_str(_tem);
    return _temporary_str;
}

MyString MyString::operator-(const MyString& _str) {
    size_t temp_length{0};
    for (int i = 0; i < _str._length; ++i) {
        for (int j = 0; j < length(); ++j) {
            if (_string[j] == _str._string[i]) {
                temp_length++;
                break;
            }
        }
    }
    size_t k{0};
    static size_t i = 0;
    static size_t j = 0;
    char* _temp = new char[length() - temp_length + 1];
    for (; i < _str._length; ++i) {
        for (; j < length(); ++j) {
            if (_string[j] != _str._string[i]) {
                _temp[k] = _string[j];
                k++;
            } else {
                break;
            }
        }
    }
    _temp[length() - temp_length] = '\0';
    MyString _temporary(_temp);
    return _temporary;
}

MyString MyString::operator*(int val) {
    unsigned  int _temp_length = 3 * length();
    char* _temp = new char[_temp_length + 1];
    size_t k{0};
    for (size_t i = 0; i < val; ++i) {
        for (size_t j = 0; j < length(); ++j) {
            _temp[k] = _string[j];
            k++;
        }
    }
    _temp[_temp_length] = '\0';
    MyString _temporary(_temp);
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
    if (length() != _str._length) {
        return false;
    }
    for (size_t i = 0; i < length(); ++i) {
        if (_string[i] != _str._string[i]) {
            return false;
        }
    }
    return true;
}

bool MyString::operator!=(const MyString& _str) {
    if (length() != _str._length) {
        return true;
    }
    for (size_t i = 0; i < length(); ++i) {
        if (_string[i] != _str._string[i]) {
            return true;
        }
    }
    return false;
}

bool MyString::operator>(const MyString& _str) {
    size_t min{0};
    min = (length() > _str._length) ? _str._length : length();
    size_t i{0};
    while (i < min) {
        if (_string[i] == _str._string[i]) {
            continue;
        } else if (_string[i] > _str._string[i]) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return false;
}

bool MyString::operator<(const MyString& _str) {
    size_t min{0};
    min = (length() > _str._length) ? _str._length : length();
    size_t i{0};
    while (i < min) {
        if (_string[i] == _str._string[i]) {
            continue;
        } else if (_string[i] < _str._string[i]) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return false;
}

bool MyString::operator>=(const MyString& _str) {
    size_t min{0};
    min = (length() > _str._length) ? _str._length : length();
    size_t i{0};
    while (i < min) {
        if (_string[i] == _str._string[i]) {
            continue;
        } else if (_string[i] > _str._string[i]) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return true;
}

bool MyString::operator<=(const MyString& _str) {
    size_t min{0};
    min = (length() > _str._length) ? _str._length : length();
    size_t i{0};
    while (i < min) {
        if (_string[i] == _str._string[i]) {
            continue;
        } else if (_string[i] < _str._string[i]) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return true;
}

MyString MyString::operator!() {
    char* _temp = new char[_length];
    for (size_t i = 0; i < _length; ++i) {
        if (_string[i] <= 122 && _string[i] >= 97) {
            _string[i] -= 32;
        } else if (_string[i] <= 90 && _string[i] >= 65) {
            _string[i] += 32;
        }
    }
    MyString _temporary(_temp);
    return _temporary;
}

char& MyString::operator[](const int val) {
    if (val < _length && val >= 0) {
        return _string[val];
    } else {
        throw std::exception();
    }
}

int MyString::operator()(const char* _str) {
    size_t i{0};
    static size_t j{0};
    size_t k{0};
    while (_str[i] != '\0') {
        for (; j < _length; ++j) {
            if (_string[j] == _str[i]) {
                k++;
                break;
            }
        }
        if (k == i) {
            return -1;
        }
        i++;
    }
    return 0;
}

std::ostream& operator<<(std::ostream& out, MyString& _str) {
    if (_str._string == nullptr) {
        throw std::exception();
    } else {
        return out << _str.get();
    }
}

std::istream& operator>>(std::istream& in, MyString& _str) {
    std::string _temp;
    in >> _temp;
    _str = MyString(_temp);
    return in;
}