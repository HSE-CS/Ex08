// Copyright 2020 Polina Lukicheva
#include "MyString.h"
#include "iostream"

int main() {

  MyString s1("Hello,");
  MyString s2("world!");
  MyString s3;
  s3 = s1 + s2;
  std::cout << s3;
  std::cout << s3("ll");   // 2
  std::cout << s3("mama"); // -1
  return 0;
}
