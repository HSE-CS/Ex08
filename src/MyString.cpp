// Copyright 2020 Kasyanov

#include <string>
#include <cstdio>
#include "MyString.h"

MyString::MyString(const char *new_str) {
  if (new_str == nullptr) {
    len = 0;
    str = nullptr;
  } else {
    len = strlen(new_str);
    str = new char[len + 1];
    snprintf(str, len + 1, "%s", new_str);
  }
}

MyString::MyString(std::string new_str) {
  len = new_str.size();
  str = new char[len + 1];
  snprintf(str, len + 1, "%s", new_str.c_str());
}

MyString::MyString(const MyString &s) {
  len = s.len;
  str = new char[len + 1];
  snprintf(str, len + 1, "%s", s.str);
}

MyString::MyString(MyString &&s) {
  str = s.str;
  len = s.len;
  s.str = nullptr;
  s.len = 0;
}

MyString::~MyString() { delete[] str; }

int MyString::length() const { return len; }

char *MyString::get() const { return str; }

MyString MyString::operator+(const MyString &add_str) {
  int new_len = add_str.len + len + 1;
  char *new_str = new char[new_len];
  for (int i = 0; i < len; ++i) {
    new_str[i] = str[i];
  }
  for (int i = len; i < new_len - 1; ++i) {
    new_str[i] = add_str.str[i - len];
  }
  new_str[new_len - 1] = '\0';
  return MyString(new_str);
}

bool MyString::CharInString(char c) const {
  for (int i = 0; i < len; ++i) {
    if (str[i] == c) {
      return true;
    }
  }
  return false;
}

char *AddCharResize(char *curr, char c) {
  int curr_len = strlen(curr);
  char *new_str = new char[curr_len + 2];
  for (int i = 0; i < curr_len; ++i) {
    new_str[i] = curr[i];
  }
  new_str[curr_len] = c;
  new_str[curr_len + 1] = '\0';
  delete[] curr;
  return new_str;
}

MyString MyString::operator-(const MyString &diff_str) {
  char *new_str = new char[1];
  new_str[0] = '\0';
  for (int i = 0; i < len; ++i) {
    if (!diff_str.CharInString(str[i])) {
      new_str = AddCharResize(new_str, str[i]);
    }
  }
  return MyString(new_str);
}

MyString MyString::operator*(int n) {
  char *new_str = new char[len * n + 1];
  for (int i = 0; i < n; ++i) {
    for (int j = i * len; j < (i + 1) * len; ++j) {
      new_str[j] = str[j - i * len];
    }
  }
  new_str[len * n] = '\0';
  return MyString(new_str);
}

MyString &MyString::operator=(const MyString &s) {
  str = s.str;
  len = s.len;
  return *this;
}

MyString &MyString::operator=(MyString &&s) {
  str = s.str;
  len = s.len;
  s.str = nullptr;
  s.len = 0;
}

bool MyString::operator==(const MyString &s) {
  if (strcmp(str, s.str) == 0) {
    return true;
  }
  return false;
}

bool MyString::operator!=(const MyString &s) {
  if (strcmp(str, s.str) == 0) {
    return false;
  }
  return true;
}

bool MyString::operator>(const MyString &s) {
  if (strcmp(str, s.str) <= 0) {
    return false;
  }
  return true;
}

bool MyString::operator<(const MyString &s) {
  if (strcmp(str, s.str) >= 0) {
    return false;
  }
  return true;
}

bool MyString::operator>=(const MyString &s) {
  if (strcmp(str, s.str) < 0) {
    return false;
  }
  return true;
}

bool MyString::operator<=(const MyString &s) {
  if (strcmp(str, s.str) > 0) {
    return false;
  }
  return true;
}

MyString MyString::operator!() {
  for (int i = 0; i < len; ++i) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 'a' - 'A';
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 'a' - 'A';
    }
  }
  return MyString(str);
}

char &MyString::operator[](int i) { return str[i]; }

int MyString::operator()(const char *sstr) {
  int len_substr = strlen(sstr);
  for (int i = 0; i < len - len_substr + 1; ++i) {
    bool flag = true;
    for (int j = 0; j < len_substr; ++j) {
      if (str[i + j] != sstr[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return i;
    }
  }
  return -1;
}

std::istream &operator>>(std::istream &inp, MyString &s) {
  return inp >> s.get();
}

std::ostream &operator<<(std::ostream &out, MyString &s) {
  return out << s.get();
}
