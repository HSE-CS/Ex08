// Copyright 2020 Polina Lukicheva
#include "MyString.h"
#include "iostream"

int main() {
  MyString a;
  std::cout << 0 << " - " << a.length() << std::endl;
  MyString a1("hello");
  std::cout << 5 << " - " << a1.length() << std::endl;
  MyString a3("123");
  MyString b3(a3);
  std::cout << "123" << " - " << b3.get() << std::endl;
  MyString a4("123");
  MyString b4;
  MyString c4;
  c4 = a4 + b4;
  std::cout << c4.get() << std::endl;
  return 0;
}
