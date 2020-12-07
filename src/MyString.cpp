// Copyright 2020 sccc
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "MyString.h"
#include <algorithm>


int MyString :: length() {
	if(size == 0)
		return 0;
    return size-1;
}

MyString::MyString() {
    size = 0;
    string = nullptr;
}

MyString::MyString(const char* str) {
    size = strlen(str) + 1;
    string = (char*)calloc(size,sizeof(char));
    strcpy(string,str);
}

MyString::MyString(std :: string str) {
    size = str.length() + 1;
    string = (char*)calloc(size,sizeof(char));
    strcpy(string,str.c_str());
}

MyString::MyString(const MyString& str) {
    size = str.size + 1;
    string = (char*)calloc(size,sizeof(char));
    strcpy(string,str.string);
}
MyString::MyString(MyString&& str){
    size = str.length() + 1;
    string = (char*)calloc(size,sizeof(char));
    strcpy(string,str.string);
    str.size = 0;
    str.string = nullptr;
}

MyString::~MyString() {
    free(string);
 }



char * MyString :: get() {
    return string;
}

MyString MyString::operator+(const MyString& str){
    MyString result;
    result.size = size + str.size;
    result.string = result.string = (char*)calloc(result.size,sizeof(char));
    for(int i = 0; i < size; i++) {
        result.string[i] = string[i];
    }
    for(int i = 0; i < str.size; i++) {
        result.string[i+size-1] = str.string[i];
    }
    return result;
}

MyString MyString::operator-(const MyString&str){
    MyString result;
    result.size = size;
    result.string = result.string = (char*)calloc(result.size,sizeof(char));
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(strchr(str.string,string[i]) == nullptr) {
            result.string[j] = string[i];
            j++;
        }
    }
    return result;
}

MyString MyString::operator*(int n) {
    MyString result;
    for(int i = 0; i < n; i++) {
    	result = *this + result;
    }
    return result;
}

bool MyString::operator==(const MyString& str) {
    if (size != str.size)
        return false;
    for (int i = 0; i < size; i++) {
        if (string[i] != str.string[i])
            return false;
    }
    return true;
}

bool MyString::operator!=(const MyString& str) {
    if (size != str.size)
        return true;
    for (int i = 0; i < size; i++) {
        if (string[i] != str.string[i])
            return true;
    }
    return false;
}

bool MyString::operator<(const MyString& str) {
    for (int i = 0; i < std::min(size-1,str.size-1); i++) {
        if (string[i] >= str.string[i] )
            return false;
    }
    return true;
}

bool MyString::operator<=(const MyString& str) {
    for (int i = 0; i < std::min(size-1,str.size-1); i++) {
        if ((int)string[i] > (int)str.string[i] )
            return false;
    }
    return true;
}

bool MyString::operator>(const MyString& str) {
    for (int i = 0; i < std::min(size-1,str.size-1); i++) {
        if (string[i] <= str.string[i] )
            return false;
    }
    return true;
}

bool MyString::operator>=(const MyString& str) {
    for (int i = 0; i < std::min(size-1,str.size-1); i++) {
        if (string[i] < str.string[i] )
            return false;
    }
    return true;
}

MyString MyString::operator!() {
    MyString result;
    result.size = size-1;
    result.string =  (char*)calloc(result.size,sizeof(char));
    for (int i = 0; i < size; i++) {
        if ((int)string[i] > 96)
            result.string[i] = (int)string[i] - 32;
        else if((int)string[i] > 64 && (int)string[i] < 91)
        {
                result.string[i] = (int)string[i] + 32;
        }
        else
        {
        	result.string[i] = string[i];
        }
        
    }
    return result;
}

char MyString::operator[](const int& index) {
    return string[index];
}

int MyString::operator()(const MyString& str) {
    if (strstr(string,str.string) == nullptr)
        return -1;
    return 0;
}

std::ostream& operator<<(std::ostream& os, MyString& str) {
    return os << str.string;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    return is >> str.string;
}

MyString MyString::operator=(const MyString& str) {
    size = str.size;
    free(string);
    string =  (char*)calloc(size,sizeof(char));
    strcpy(string,str.string);
    return *this;
}

MyString MyString::operator=(MyString&& str) {
    size = str.size;
    free(string);
    string =  (char*)calloc(size,sizeof(char));
    strcpy(string,str.string);
    str.size = 0;
    str.string = nullptr;
    return *this;
}
