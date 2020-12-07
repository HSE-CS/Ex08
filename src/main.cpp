// Copyright 2020 Egor Buzanov

#include "../include/MyString.h"

int main() {
  MyString str1("Hello");
  MyString str2(", ");
  MyString str3(std::string("world!"));
  MyString str4 = str1 + str2 + str3;
  std::cout << str1 << str2 << str3 << std::endl;
  std::cout << str4 << std::endl;
  MyString str5(str4);
  std::cout << str4 << std::endl;
  std::cout << str5 << std::endl;
  std::cout << (str1 > str2) << std::endl;
  std::cout << (str1 < str2) << std::endl;
  std::cout << (str1 >= str2) << std::endl;
  std::cout << (str1 <= str2) << std::endl;
  std::cout << (str1 == str2) << std::endl;
  std::cout << (str1 != str2) << std::endl;
  !str1;
  std::cout << str1 << std::endl;
  std::cout << str1("ll") << std::endl;
  str4 = str1 * 3;
  std::cout << str4 << std::endl;
  str1[0] = 'Y';
  std::cout << str1 << std::endl;
  return 0;
}
