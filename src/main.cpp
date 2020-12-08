// Copyright 2020 Ryzhova
#include "MyString.h"

int main() {
  MyString s1("Hello,");
  MyString s2("world!");
  MyString s3;
  s3 = s1 + s2;
  std::cout << s3.get() << std::endl;
  MyString s4;
  s4 = s3 - s2;
  std::cout << s4.get() << std::endl;
  s4 = s1 * 5;
  std::cout << s4.get() << std::endl;
  s3 = s2;
  std::cout << s3.get() << std::endl;
  std::cout << (s3 < s2) << std::endl;
  std::cout << (s3 > s2) << std::endl;
  std::cout << (s3 == s2) << std::endl;
  std::cout << (s3 != s2) << std::endl;
}
