// Copyright 2020 ArinaMonicheva
#include "MyString.h"

int main() {
  MyString s1;
  MyString s2(nullptr);
  
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  
  char* charStr = "Hello";
  MyString s3(charStr);
  
  std::cout << s3 << std::endl;
  
  std::string stringStr = "World";
  MyString s4(stringStr);
  
  std::cout << s4 << std::endl;
  
  MyString s5(s4);
  std::cout << s5 << std::endl;
  
  MyString s6(s3 + s4);
  std::cout << s6 << std::endl;
  
  std::cout << s6 - s3 << std::endl;
  std::cout << s6 - s4 << std::endl;
  std::cout << s3 * 3 << std::endl;
  
  bool isTrue = (s3 > s4);
  
  std::cout << isTrue << std::endl;
  
  isTrue = (s3 < s4);
  
  std::cout << isTrue << std::endl;
  
  isTrue = (s3 == s5);
  
  std::cout << isTrue << std::endl;
  
  isTrue = (s3 != s5);
  
  std::cout << isTrue << std::endl;
  
  std::cout << !s5 << std::endl;
  std::cout << s3[4] << std::endl;
  std::cout << s3("ll") << std::endl;
  
  s1 = s6;
  std::cout << s1 << std::endl;
  std::cout << s6.length() << std::endl;
  std::cout << s2.length() << std::endl;
  
  return 0;
}