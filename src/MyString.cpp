#include <string>
#include <string.h>
#include <iostream>
#include "MyString.h"

MyString::MyString(const char* a) {
  if (!a) {
    len = 0;
    char* a = reinterpret_cast<char*>(calloc(1, sizeof(char)));
    if (!a) exit(1);
      field = a;
  }
  else {
    len = strlen(a);
    field = strdup(a);
  }
}



MyString::MyString(std::string a) {
  len = a.length();
  field = strdup(a.c_str());
}

MyString::MyString(const MyString& a) {
  field = strdup(a.field);
  len = a.len;
}

MyString::MyString(MyString&& a) {
  field = strdup(a.field);
  len = a.len;
}

MyString::~MyString() {
  free(field);
 }

int MyString::length() {
  return len;
 }

char* MyString::get() {
  return field;
 }
//
MyString MyString::operator+(const MyString& a) {
  char* buffer = reinterpret_cast<char*>(calloc(len + a.len + 1, sizeof(char)));
  strcat(buffer, field);
  strcat(buffer + len, a.field);
  MyString result = MyString(buffer);
  free(buffer);
  return result;
}

MyString MyString::operator-(const MyString& a) {
  int k = 0;
  char* result = (char*) calloc(len + 1, sizeof(char));
  bool letter_found = false;
  for (int i = 0; i < len; i++) {
    letter_found = false;
    for (int j = 0; j < a.len; j++) {
      if (field[i] == a.field[j])
        letter_found = true;
      }
      if (!letter_found)
      {
         result[k] = field[i];
         k++;
      }
     }
  MyString ans = MyString(result);
  free(result);
  return ans;
}

MyString MyString::operator*(int repeats) {
  char* result = (char*) calloc(len * repeats + 1, sizeof(char));
  for(int i = 0; i < repeats; i++)
  strcpy(result + i * repeats, field);
  MyString ans = MyString(result);
  free(result);
  return ans;
}

MyString& MyString::operator=(const MyString& a) {
  len = a.len;
  field = strdup(a.field);
  return *this;
}
MyString& MyString::operator=(MyString&& a) {
  len = a.len;
  field = strdup(a.field);
  return *this;
}

bool MyString::operator!=(const MyString& a) {
  return !(*this == a);
}

bool MyString::operator==(const MyString& a) {
  int ans = strcmp(field, a.field);
  return ans == 0;
}

bool MyString::operator<(const MyString& a) {
  return strcmp(field, a.field) < 0;
}

bool MyString::operator>(const MyString& a) {
  return strcmp(field, a.field) > 0;
}

bool MyString::operator>=(const MyString& a) {
  return strcmp(field, a.field) >= 0;
}

bool MyString::operator<=(const MyString& a) {
  return strcmp(field, a.field) <= 0;
}

MyString MyString::operator!() {
  MyString copy(*this);
  for (size_t i = 0; i < copy.len; ++i) {
    if (copy.field[i] >= 'a' && copy.field[i] <= 'z') {
      copy.field[i] -= 'a' - 'A';
    }
    else if (copy.field[i] >= 'A' && copy.field[i] <= 'Z') {
      copy.field[i] += 'a' - 'A';
    }
  }
  return copy;
}

char MyString::operator[](int index) {
  return field[index];
}

int MyString::operator()(const char* a) {
  char* ans = strstr(field, a);
  if (ans == NULL)
    return -1;
  else
    return (field - ans);
}

std::istream& operator>>(std::istream& in, MyString& a) {
  return in >> a.get();
}

std::ostream& operator<<(std::ostream& out, MyString& a) {
  return out << a.get();
}
