// Copyright 2020 ArinaMonicheva
#include "MyString.h"

MyString::MyString() {
  myString = new char[1];
  myString[0] = '\0';
}

MyString::MyString(const char* newStr = nullptr) {
  if (newStr) {
    myString = new char[strlen(newStr) + 1];
    memcpy(myString, newStr, strlen(newStr) + 1);
  } else {
    myString = new char[1];
    myString[0] = '\0';
  }
}

MyString::MyString(std::string newStr) {
  myString = new char[newStr.length() + 1];
  memcpy(myString, newStr.c_str(), newStr.length());
}

MyString::MyString(const MyString& otherString) {
  myString = new char[otherString.length() + 1];
  memcpy(myString, otherString.get(), otherString.length() + 1);
}

MyString::MyString(MyString&& toShift) {
  myString = toShift.get();
  toShift.myString = nullptr;
}

MyString::~MyString() {
  delete[] myString;
}

char* MyString::get() const {
  return this->myString;
}

size_t MyString::length() const {
  return strlen(myString);
}

MyString MyString::operator+(const MyString& otherString) {
  return MyString(std::string(myString) + std::string(otherString.get()));
}

MyString MyString::operator-(const MyString& otherString) {
  int ptr = 0;
  std::string tempStr(this->get());
  std::string tempStr2(otherString.get());
  for (int i = 0; i < otherString.length(); i++) {
    ptr = tempStr.find(tempStr2[i]);
    while (ptr < tempStr.length()) {
      tempStr.erase(ptr, 1);
      ptr = tempStr.find(tempStr2[i]);
        }
  }
  return MyString(tempStr);
}

MyString MyString::operator*(size_t repeat) {
  std::string tempStr = "";
  for (int i = 0; i < repeat; i++) {
    tempStr += myString;
  }
  return MyString(tempStr);
}

MyString& MyString::operator=(const MyString& otherString) {
  if (myString) {
    delete[] myString;
  }
  myString = new char[otherString.length() + 1];
  memcpy(myString, otherString.get(), otherString.length() + 1);
  return *this;
}
MyString& MyString::operator=(MyString&& toShift) {
  if (myString) {
    delete[] myString;
  }
  myString = toShift.get();
  toShift.myString = nullptr;
  return *this;
}

bool MyString::operator==(const MyString& otherString) const {
  return !strcmp(myString, otherString.get());
}

bool MyString::operator!=(const MyString& otherString) const {
  return strcmp(myString, otherString.get());
}

bool MyString::operator>(const MyString& otherString) const {
  return strcmp(myString, otherString.get()) == 1;
}

bool MyString::operator<(const MyString& otherString) const {
  return strcmp(myString, otherString.get()) == -1;
}

bool MyString::operator>=(const MyString& otherString) const {
  return strcmp(myString, otherString.get()) > 1;
}

bool MyString::operator<=(const MyString& otherString) const {
  return strcmp(myString, otherString.get()) < 1;
}

MyString MyString::operator!() {
  for (int i = 0; i < this->length(); i++) {
    myString[i] = std::isupper(myString[i]) ?
    std::tolower(myString[i]) : std::toupper(myString[i]);
  }
  return *this;
}

char& MyString::operator[](size_t index) const {
  if (index >= 0 && index < strlen(myString)) {
    return myString[index];
  } else {
    throw "Index is out of range!";
  }
}

int MyString::operator()(const char* subString) {
  return std::string(myString).find(subString);
}

std::ostream& operator<<(std::ostream& sout, MyString& toPrint) {
  return sout << toPrint.myString;;
}

std::istream& operator>>(std::istream& sin, MyString& toWrite) {
  std::string toGet;
  std::getline(sin, toGet);
  toWrite = MyString(toGet);
  return sin;
}
