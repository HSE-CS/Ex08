// Copyright 2020 Golovanov
#include "MyString.h"
#include <iostream>

int main() {
  MyString s1("Denis");
  std::cout << s1.get() << std::endl;
  MyString s2("Golovanov");
  MyString s3 = s1 + s2;
  std::cout << s3 << std::endl;
  s3 = s1 * 2;
  std::cout << s3 << std::endl;
  s3 = s1 - s2;
  std::cout << s3 << std::endl;
  std::cout << (s1 > s2) << std::endl;
  std::cout << (s1 == s2) << std::endl;
  std::cout << (s1(s2.get())) << std::endl;

  return 0;
}
