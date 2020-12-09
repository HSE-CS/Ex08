// Copyright 2020 Shirokov Alexander

#include <iostream>
#include "MyString.h"

int main() {
  MyString a("111");
  MyString b;
  b = a;
  std::cout << b << "\n";
  a = b * 2;
  std::cout << a << "\n";
  b = b * 2 + a;
  std::cout << b.get() << "\n";
  std::cout << b.length() << "\n";
  MyString c("Test ");
  c = c + b;
  std::cout << c << "\n";
  std::cout << c[0] << "\n";
  std::cout << (a == b) << "\n";
  MyString d("SsSsSssSs");
  std::cout << d << "\n";
  d = !d;
  std::cout << d << "\n";
  return 0;
}
