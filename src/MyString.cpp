// Copyright 2020 Dev-will-work
#include "MyString.h"
#include <iostream>
#include <cstring>

MyString::MyString(const char* str) {
  if (str == nullptr) {
    return;
  }
  size_t size = strlen(str);
  this->string = new char[size + 1];
  for (size_t i = 0; i < size; i++) {
    this->string[i] = str[i];
  }
  this->string[size] = '\0';
}  // default - nullptr

MyString::MyString(std::string str) {
  size_t size = str.length();
  this->string = new char[size + 1];
  for (size_t i = 0; i < size; i++) {
    this->string[i] = str[i];
  }
  this->string[size] = '\0';
}

MyString::MyString(const MyString& str) {
  if (str.string == nullptr) return;
  size_t size = strlen(str.string);
  if (this->string == nullptr) {
    this->string = new char[size + 1];
  }
  for (size_t i = 0; i < size; i++) {
    this->string[i] = str.string[i];
  }
  this->string[size] = '\0';
}  // copy constructor

MyString::~MyString() {
  delete[] this->string;
}

size_t MyString::length() {
  if (this->string == nullptr) return 0;
  else
    return strlen(this->string);
}

char* MyString::get() {
  return this->string;
}  // return char* string

MyString MyString::operator+(MyString str) {
  if (this->string == nullptr || str.string == nullptr) return *this;
  size_t size1 = strlen(this->string), size2 = strlen(str.string);
  MyString res;
  res.string = new char[size1 + size2 + 1];
  for (size_t i = 0; i < size1; i++) {
    res.string[i] = this->string[i];
  }
  for (size_t i = size1, j = 0; i < size1 + size2 && j < size2; i++, j++) {
    res.string[i] = str.string[j];
  }
  res.string[size1 + size2] = '\0';
  return res;
}  // concatenation

MyString MyString::operator-(MyString str) {
  if (this->string == nullptr || str.string == nullptr) return *this;
  size_t size1 = strlen(this->string), size2 = strlen(str.string);
  size_t deleted = 0;
  for (size_t i = 0; i < size2; i++) {
    for (size_t j = 0; j < size1; j++) {
      if (str.string[i] == this->string[j]) {
        deleted++;
        this->string[j] = -123;
      }
    }
  }
  MyString res;
  res.string = new char[size1 - deleted + 1];
  int res_index = 0;
  for (size_t i = 0; i < size1; i++) {
    if (this->string[i] != -123) res.string[res_index++] = this->string[i];
  }
  res.string[size1 - deleted] = '\0';
  return res;
}  // filter 1st string by chars in 2nd

MyString MyString::operator*(int count) {
  if (this->string == nullptr) {
    return *this;
  }
  if (count < 1) count = 1;
  size_t size = strlen(this->string);
  MyString res;
  res.string = new char[(size * count) + 1];
  for (size_t i = 0, j = 0; i < count * size; i++, j++) {
    if (j == size) j = 0;
    res.string[i] = this->string[j];
  }
  res.string[size * count] = '\0';
  return res;
}  // creates a new string from repeated old

MyString& MyString::operator=(const MyString& str) {
  size_t size;
  if (this == &str) return *this;
  delete[] this->string;
  if (str.string == nullptr) {
    this->string = nullptr;
    return *this;
  } else {
    size = strlen(str.string);
    this->string = new char[size + 1];
    for (int i = 0; i < size; i++) {
      this->string[i] = str.string[i];
    }
    this->string[size] = '\0';
    return *this;
  }
}  // copy assignment

MyString& MyString::operator=(MyString&& str) {
  if (this == &str) return *this;
  delete[] this->string;
  if (str.string == nullptr) {
    this->string = nullptr;
    return *this;
  } else {
    this->string = str.string;
    str.string = nullptr;
    return *this;
  }
}  // move assignment

bool MyString::operator==(MyString str) {
  if ((this->string == nullptr) ^ (str.string == nullptr)) return 0;
  else
  if (this->string == nullptr && str.string == nullptr) {
    return 1;
  } else {
    size_t size1 = strlen(this->string), size2 = strlen(str.string);
    if (size1 != size2) { return 0;
    } else {
      for (size_t i = 0; i < size1; i++) {
        if (this->string[i] != str.string[i]) return 0;
      }
      return 1;
    }
  }
}

bool MyString::operator!=(MyString str) {
  if ((this->string == nullptr) ^ (str.string == nullptr)) return 1;
  else
  if (this->string == nullptr && str.string == nullptr) {
    return 0;
  } else {
    size_t size1 = strlen(this->string), size2 = strlen(str.string);
    if (size1 != size2) {
      return 1;
    } else {
      for (size_t i = 0; i < size1; i++) {
        if (this->string[i] != str.string[i]) return 1;
      }
      return 0;
    }
  }
}

bool MyString::operator>(MyString str) {
  if (this->string == nullptr && !(str.string == nullptr)) return 0;
  else
  if (!(this->string == nullptr) && str.string == nullptr) return 1;
  else
  if (this->string == nullptr && str.string == nullptr) {
    return 0;
  } else {
    size_t size1 = strlen(this->string), size2 = strlen(str.string);
    for (size_t i = 0, j = 0; i < size1 && j < size2; i++, j++) {
      if (this->string[i] > str.string[j]) return 1;
      else
      if (this->string[i] == str.string[j]) continue;
      else
        return 0;
    }
    return size1 > size2;
  }
}  // lexicographic comparison

bool MyString::operator<(MyString str) {
  if (this->string == nullptr && !(str.string == nullptr)) return 1;
  else
  if (!(this->string == nullptr) && str.string == nullptr) return 0;
  else
  if (this->string == nullptr && str.string == nullptr) {
    return 0;
  } else {
    size_t size1 = strlen(this->string), size2 = strlen(str.string);
    for (size_t i = 0, j = 0; i < size1 && j < size2; i++, j++) {
      if (this->string[i] < str.string[j]) return 1;
      else
      if (this->string[i] == str.string[j]) continue;
      else
        return 0;
    }
    return size1 < size2;
  }
}  // lexicographic comparison

bool MyString::operator>=(MyString str) {
  if (this->string == nullptr && !(str.string == nullptr)) return 0;
  else
  if (!(this->string == nullptr) && str.string == nullptr) return 1;
  else
  if (this->string == nullptr && str.string == nullptr) {
    return 1;
  } else {
    size_t size1 = strlen(this->string), size2 = strlen(str.string);
    for (size_t i = 0, j = 0; i < size1 && j < size2; i++, j++) {
      if (this->string[i] > str.string[j]) return 1;
      else
      if (this->string[i] == str.string[j]) continue;
      else
        return 0;
  }
    return size1 >= size2;
  }
}  // lexicographic comparison

bool MyString::operator<=(MyString str) {
  if (this->string == nullptr && !(str.string == nullptr)) return 1;
  else
  if (!(this->string == nullptr) && str.string == nullptr) return 0;
  else
  if (this->string == nullptr && str.string == nullptr) {
    return 1;
  } else {
    size_t size1 = strlen(this->string), size2 = strlen(str.string);
    for (size_t i = 0, j = 0; i < size1 && j < size2; i++, j++) {
      if (this->string[i] < str.string[j]) return 1;
      else
      if (this->string[i] == str.string[j]) continue;
      else
        return 0;
    }
    return size1 <= size2;
  }
}  // lexicographic comparison

MyString MyString::operator!() {
  if (this->string == nullptr) {
    return *this;
  } else {
    size_t size = strlen(this->string);
    MyString res(*this);
    for (size_t i = 0; i < size; i++) {
      if (this->string[i] >= 'A' && this->string[i] <= 'Z')
        res.string[i] += 32;
      else
        if (this->string[i] >= 'a' && this->string[i] <= 'z')
          res.string[i] -= 32;
    }
    return res;
  }
}  // creates new string with inverted registers

char MyString::operator[](int index) {
  if (this->string == nullptr || index < 0 ||
    index > (strlen(this->string) + 1)) return 0;
  else
    return this->string[index];
}  // get char by index

int MyString::operator()(const char* substr) {
  size_t text_size = strlen(this->string), substr_size = strlen(substr);
  int counter = 0, place = 0;
  for (size_t i = 0; i < text_size; i++) {
    if (counter == substr_size) return place;
    if ((*this)[i] == substr[counter]) {
      if (counter == 0) place = i;
      counter++;
    } else {
      counter = 0;
      place = -1;
    }
  }
  return place;
}  // substring search (kind of naive)

std::ostream& operator<<(std::ostream& out, MyString& str) {
  if (str.string == nullptr) return out << "" << std::endl;
  else
    return out << str.string << std::endl;
}  // write

std::istream& operator>>(std::istream& in, MyString& str) {
  int size;
  if (str.string == nullptr) {
    size = 0;
    while (1) {
      in >> size;
      if (in.fail()) {
        in.clear();
        in.ignore(32767, '\n');
      } else {
        in.ignore(32767, '\n');
      }
    }
    str.string = new char[size + 1];
    str.string[size] = '\0';
  } else {
    size = strlen(str.string);
  }
  return (in >> str.string).ignore(32767, '\n');
}  // read
