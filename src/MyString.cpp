// Copyright [2020] <Balayan Roman>

#include "MyString.h"

int len(const char* val) {
    int size = 0;
    while (*val != '\0') {
        size++;
        val++;
    }
    return size;
}

MyString::MyString(){
        this->reserved_size = 255;
        this->size = 0;
        this->value = new char[this->reserved_size];
        this->value[0] = '\0';
        return;
}

MyString::MyString(const MyString& val){
    this->reserved_size = val.reserved_size;
    this->size = val.size;
    this->value = new char[this->reserved_size];
    for (int i = 0; i < val.size + 1; ++i)
        this->value[i] = val.value[i];
}

MyString::MyString(std::string val){
    this->reserved_size = val.length() + 100;
    this->size = val.length();
    this->value = new char[this->reserved_size];
    for (int i = 0; i < size + 1; ++i)
        this->value[i] = val[i];
}

MyString::~MyString(){
    delete this->value;
}

void MyString::append(const char* val){
    if (len(val) + this->size >= this->reserved_size)
        this->resize(len(val) + this->size + 10);
    for (int i = this->size, j = 0; j < len(val) + 1; ++j, ++i)
        this->value[i] = val[j];
    this->size += len(val);
}

void MyString::append(const MyString& val){
    if (val.size + this->size >= this->reserved_size)
        this->resize(val.size + this->size + 10);
    for (int i = this->size, j = 0; j < val.size + 1; ++j, ++i)
        this->value[i] = val.value[j];
    this->size += val.size;
}

char MyString::pop_back(){
    char res = this->value[this->size - 1];
    this->size--;
    this->value[this->size] = '\0';
    return res;
}

void MyString::reverse(){
    MyString copy(*this);
    for (int i = 0; i < this->size; ++i)
        this->value[i] = copy.value[this->size - 1 - i];
    this->value[this->size] = '\0';
}

void MyString::del(char val){
    for (int i = 0; i < this->size; ++i)
    {
        if (this->value[i] == val) {
            int j = i;
            while (this->value[j] != '\0') {
                this->value[j] = this->value[j + 1];
                ++j;
            }
            this->size--;
        }
    }
}

unsigned int MyString::length(){
    return this->size;
}

void MyString::resize(unsigned int size){
    MyString copy(*this);
    delete this->value;
    this->reserved_size = size;
    this->value = new char[size];
    for (int i = 0; i < this->size + 1; ++i)
        this->value[i] = copy.value[i];
}

unsigned int MyString::get_reserved_size(){
    return this->reserved_size;
}

char* MyString::get(){
    return this->value;
}

float MyString::get_float(){
    float res = 0;
    int exp1 = 1, exp2 = 1;
    for (int i = this->size - 1; i >= 0; --i){
        if (this->value[i] == '.'){
            res /= exp1;
            exp1 = 1;
            continue;
        }
        res += ((int)this->value[i] - '0') * exp1;
        exp1 *= 10;
    }
    return res;
}

int* MyString::get_date(){
    int* dates = new int[3];
    dates[0] = 0;
    dates[1] = 0;
    dates[2] = 0;
    dates[0] += (this->value[0] - '0') * 10;
    dates[0] += (this->value[1] - '0');
    dates[1] += (this->value[3] - '0') * 10;
    dates[1] += (this->value[4] - '0');
    dates[2] += (this->value[6] - '0') * 1000;
    dates[2] += (this->value[7] - '0') * 100;
    dates[2] += (this->value[8] - '0') * 10;
    dates[2] += (this->value[9] - '0');
    return dates;
}

char& MyString::operator[](unsigned int i){
    return this->value[i];
}

void MyString::operator=(const MyString& val){
    this->reserved_size = val.reserved_size;
    this->size = val.size;
    this->value = new char[this->reserved_size];
    for (int i = 0; i < val.size + 1; ++i)
        this->value[i] = val.value[i];
}

void MyString::operator=(const char* val){
    this->reserved_size = len(val) + 100;
    this->size = len(val);
    this->value = new char[this->reserved_size];
    for (int i = 0; i < size + 1; ++i)
        this->value[i] = val[i];
}

void MyString::operator+=(const MyString& val){
    if (val.size + this->size >= this->reserved_size)
        this->resize(val.size + this->size + 10);
    for (int i = this->size, j = 0; j < val.size + 1; ++j, ++i)
        this->value[i] = val.value[j];
    this->size += val.size;
}

void MyString::operator+=(const char* val){
    if (len(val) + this->size >= this->reserved_size)
        this->resize(len(val) + this->size + 10);
    for (int i = this->size, j = 0; j < len(val) + 1; ++j, ++i)
        this->value[i] = val[j];
    this->size += len(val);
}

void MyString::operator+=(char val){
    if (1 + this->size >= this->reserved_size)
        this->resize(1 + this->size + 10);
    this->value[this->size] = val;
    this->size++;
    this->value[this->size] = '\0';
}

bool MyString::operator==(const MyString& val){
    if (this->size != val.size)
        return false;
    for (int i = 0; i < this->size; ++i)
        if (this->value[i] != val.value[i])
            return false;
    return true;
}

bool MyString::operator!=(const MyString& val){
    return !(*this == val);
}

bool MyString::operator>=(const MyString& val){
    return *this > val || *this == val;
}

bool MyString::operator<=(const MyString& val){
    return *this < val || *this == val;
}

bool MyString::operator>(const MyString& val){
    int i = 0;
    while (i < val.size && i < this->size) {
        if (val.value[i] < this->value[i]) {
            return true;
        }
        ++i;
    }
    if (this->size > val.size)
        return true;
    return false;
}

bool MyString::operator<(const MyString& val){
    int i = 0;
    while (i < val.size && i < this->size) {
        if (val.value[i] > this->value[i]) {
            return true;
        }
        ++i;
    }
    if (this->size < val.size)
        return true;
    return false;
}

MyString MyString::operator+(const MyString& val){
    MyString res(*this);
    res += val;
    return res;
}

MyString MyString::operator-(const MyString& val){
    MyString res(*this);
    for (int i = 0; i < val.size; ++i)
        res.del(val.value[i]);
    return res;
}

MyString MyString::operator*(int a) {
    MyString res;
    for (int i = 0; i < a; ++i)
    {
        res += *this;
    }
    return res;
}

MyString MyString::operator!(){
    MyString res(*this);
    for (int i = 0; i < res.size; ++i)
        if (res.value[i] >= 65 && res.value[i] <= 90)
            res.value[i] += 32;
        else if(res.value[i] >= 97 && res.value[i] <= 112) {
            res.value[i] -= 32;
        }
    return res;
}

int MyString::operator()(const MyString& val){
    for (int i = 0; i < this->size; ++i) {
        bool check = true;
        for (int j = 0; j < val.size; ++j) {
            if (i + j >= this->size) {
                check = false;
                break;
            }
            if (this->value[i + j] != val.value[j]) {
                check = false;
                break;
            }
        }
        if (check)
            return i;
    }
    return -1;
}

int MyString::operator()(const char* a){
    MyString val(a);
    for (int i = 0; i < this->size; ++i) {
        bool check = true;
        for (int j = 0; j < val.size; ++j) {
            if (i + j >= this->size) {
                check = false;
                break;
            }
            if (this->value[i + j] != val.value[j]) {
                check = false;
                break;
            }
        }
        if (check)
            return i;
    }
    return -1;
}

MyString intToMyString(int val){
    MyString res;
    bool isMinus = val < 0;
    if (isMinus)
        val *= -1;
    while (val != 0) {
        res += (char)(val % 10 + '0');
        val /= 10;
    }
    if (isMinus)
        res += "-";
    res += "\0";
    res.reverse();
    return res;
}

std::ostream& operator<<(std::ostream& out, const MyString& val){
    out << val.value;
    return out;
}

std::istream& operator>>(std::istream& in, MyString& val){
    char* buf = new char[255];
    std::cin.getline(buf, 255);
    val = MyString(buf);
    return in;
}
