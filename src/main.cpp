// Copyright 2020 Shelby Ltd.
#include "MyString.h"
#include <iostream>

int main() {
  MyString s1("dfsfsdf");
  std::cout << s1.get() << std::endl;
  MyString s2("JKkfsfJkf94");
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
