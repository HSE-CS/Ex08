// Copyright 2020 Kuznetsov Mikhail

#include "MyString.h"

int main() {
  MyString s;
  std::cout << s.length() << std::endl;  //0
  MyString s1("Summer ");
  std::string str("is ");
  MyString s2(str);
  MyString s4("coming!");
  MyString s3(s4);
  s4 = s1 + s2 + s3;
  std::cout << s4 << std::endl;  //Summer is coming!
  MyString s5 = s4 * 2;
  std::cout << s5 << std::endl;  //Summer is coming!Summer is coming!
  std::cout << s1("m") << std::endl; ;   // 2
  std::cout << s2("si") << std::endl; ;  // -1
  std::cout << (s2 > s3) << std::endl;  //1
  std::cout << s2.length() << std::endl;  //3;
  std::cout << s2[s2.length() - 2] << std::endl;  //s
  s4 = !s3 + !s2 + !s1;
  std::cout << s4 << std::endl;  //COMING!IS sUMMER
}
