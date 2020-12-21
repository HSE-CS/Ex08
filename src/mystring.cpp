#include "../include/mystring.h"
#include <string>
mystring::mystring(const char* first_str) {
    if (first_str == nullptr) {
        str = nullptr;
        len = 0;
        len = 0;
    }
    else {
        len = strlen(first_str);
        str = new char[len + 1];
        snprintf(str, len + 1, "%s", first_str);
    }
}
mystring::mystring(std::string first_str) {
    len = first_str.size();
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = first_str[i];
    }
    str[len] = '\0';
}
mystring::mystring(const mystring& first_class) {
    len = first_class.len;
    str = new char[len + 1];
    snprintf(str, len + 1, "%s", first_class.str);
}
mystring::mystring(mystring&& second_class) {
    str = second_class.str;
    len = second_class.len;
    second_class.str = nullptr;
    second_class.len = 0;
}
mystring::~mystring() {
    delete str;
    len = 0;
}

size_t mystring::length() const {
    size_t mystring::length() const {
        return len;
    }

    char* mystring::get() const {
        return str;
    }
    mystring mystring::operator+(const mystring & second_str) {
        size_t new_len = len + second_str.length();
        char* new_str = new char[new_len + 1];
        snprintf(new_str, len + 1, "%s", str);
        snprintf(new_str + len, second_str.length() + 1, "%s", second_str.get());
        return mystring(new_str);
    }
    mystring mystring::operator-(const mystring & string) {
        std::string new_str(str, len + str);
        for (int i = 0; i < string.len; i++) {
            new_str.erase(std::remove(new_str.begin(), new_str.end(), string[i]),
                new_str.end());
        }
        return mystring(new_str);
    }
    mystring mystring::operator*(const size_t count) {
        std::string new_str;
        for (int i = 0; i < count; i++) {
            new_str += std::string(str);
        }
        return mystring(new_str);
    }
    mystring& mystring::operator=(const mystring & string) {
        len = string.len;
        str = new char[len + 1];
        snprintf(str, len + 1, "%s", string.str);
        return *this;
    }
    mystring& mystring::operator=(mystring && string) {
        len = string.len;
        str = string.str;
        string.str = nullptr;
        string.len = 0;
        return *this;
    }
    bool mystring::operator==(const mystring & string) {
        if (strcmp(str, string.str) == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    bool mystring::operator!=(const mystring & string) {
        if (strcmp(str, string.str) == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    bool mystring::operator>(const mystring & string) {
        if (strcmp(str, string.str) > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    bool mystring::operator<(const mystring & string) {
        if (strcmp(str, string.str) < 0) {
            return true;
        }
        else {
            return false;
        }
    }
    bool mystring::operator>=(const mystring & string) {
        if (strcmp(str, string.str) >= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    bool mystring::operator<=(const mystring & string) {
        if (strcmp(str, string.str) <= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    mystring mystring::operator!() {
        char* s_new = new char[len + 1];
        snprintf(s_new, len + 1, "%s", str);
        for (int i = 0; i < len; i++) {
            if (str[i] <= 'Z' && str[i] >= 'A') {
                s_new += 32;
            }
            else {
                if (str[i] <= 'z' && str[i] >= 'a') {
                    s_new[i] -= 32;
                }
            }
        }
        return mystring(s_new);
    }
    char& mystring::operator[](const size_t ind) const {
        return str[ind];
    }
    int mystring::operator()(const char* string) {
        char* point = strstr(str, string);
        if (point == nullptr) {
            return -1;
        }
        else {
            return point - str;
        }
    }
    std::ostream& operator<<(std::ostream & out, mystring & string) {
        return out << string.get();
    }
    std::istream& operator>>(std::istream & in, mystring & string) {
        return in >> string.get();
    }