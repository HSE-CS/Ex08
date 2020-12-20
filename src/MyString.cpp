//RogozyanAnastasiya
#include "MyString.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include "MyString.h"

MyString::MyString(const char* new_string) {
  if (new_string != nullptr) {
    string = new char[strlen(new_string) + 1];
    memcpy(string, new_string, strlen(new_string) + 1);
  } else {
    string = new char[1];
    memset(string, 0, 1);
  }
}
MyString::MyString(std::string new_string) {
  string = new char[new_string.length() + 1];
  memcpy(string, new_string.c_str(), new_string.length() + 1);
}
MyString::MyString(const MyString &new_string) {
  string = new char[strlen(new_string.string) + 1];
  snprintf(string, strlen(new_string.string) + 1, "%s", new_string.string);
}
MyString::MyString(MyString &&new_string) {
  string = new char[strlen(new_string.string)];
  string = new_string.string;
  new_string.string = NULL;
}
MyString::~MyString() {
  delete string;
}
size_t MyString::length() {
  return strlen(string);
}
char *MyString::get() {
  return string;
}
MyString MyString::operator+(const MyString &add_string) {
  std::string tmp;
  tmp.append(string);
  tmp.append(add_string.string);
  return MyString(tmp);
}
MyString MyString::operator-(const MyString &new_string) {
  int len_first = strlen(string);
  int len_second = strlen(new_string.string);
  char* buffer = new char[len_first + 1];
  int new_index = 0;
  for (int my_index = 0; my_index < len_first; my_index++) {
    bool is_consist = false;
    for (int other_index = 0; other_index < len_second; other_index++)
      if (string[my_index] == new_string.string[other_index]) {
        is_consist = true;
        break;
      }
    if (!is_consist) {
      buffer[new_index++] = string[my_index];
    }
  }
    return MyString(buffer);
}
MyString MyString::operator*(const size_t n) {
  MyString answer(string);
  for (unsigned int i = 0; i < n - 1; i++) {
    answer = answer + *this;
  }
  return answer;
}
MyString &MyString::operator=(const MyString &new_string) {
  string = new char[strlen(new_string.string) + 1];
  snprintf(string, strlen(new_string.string) + 1, "%s", new_string.string);
  return *this;
}
MyString &MyString::operator=(MyString &&new_string) {
  string = new_string.string;
  new_string.string = NULL;
  return *this;
}
bool MyString::operator==(const MyString &new_string) {
  return !strcmp(string, new_string.string);
}
bool MyString::operator!=(const MyString &new_string) {
  return strcmp(string, new_string.string);
}
bool MyString::operator>(const MyString &new_string) {
  return strcmp(string, new_string.string) == 1;
}
bool MyString::operator<(const MyString &new_string) {
  return strcmp(string, new_string.string) == -1;
}
bool MyString::operator>=(const MyString &new_string) {
  return strcmp(string, new_string.string) != -1;
}
bool MyString::operator<=(const MyString &new_string) {
  return strcmp(string, new_string.string) != 1;
}
MyString MyString::operator!() {
  std::string tmp;
  for (size_t i = 0; i < strlen(string); i++) {
    if (isupper(string[i]))
      tmp.push_back(tolower(string[i]));
    else
      tmp.push_back(toupper(string[i]));
  }
  return MyString(tmp);
}
char &MyString::operator[](const size_t ind) const {
  return string[ind];
}
int MyString::operator()(const char *new_string) {
  int sub_index = 0;
  int len = strlen(string);
  for (int my_index = 0; my_index < len; my_index++) {
    if (string[my_index] == new_string[sub_index]) {
      sub_index += 1;
      if (sub_index >= strlen(new_string))
        return my_index - strlen(new_string) + 1;
    } else {
      sub_index = 0;
    }
  }
  return -1;
}
std::ostream &operator<<(std::ostream &in, MyString &new_string) {
  return in << new_string.string;
}
std::istream &operator>>(std::istream &out, MyString &new_string) {
  return out >> new_string.string;
}
