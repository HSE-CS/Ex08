// Copyright 2020 VadMack

#include <iostream>
#include "MyString.h"

int main() {
  MyString nullStr;
  std::cout << nullStr.length() << std::endl;
  MyString str("hello");
  std::cout << str.get() << std::endl;
  std::cout << str.length() << std::endl;
  MyString copyStr(str);
  std::cout << copyStr.get() << std::endl;
  std::cout << copyStr.length() << std::endl;
  std::cout << (str + str).get() << std::endl;
  std::cout << str.get() << std::endl;
  std::cout << (MyString("1234567") - MyString("246")).get() << std::endl;
  MyString c = (MyString("12") + MyString("3"));
  std::cout << c.get() << std::endl;
  std::cout << (c * 3).get() << std::endl;
  std::cout << (MyString("123") == MyString("123")) << std::endl;
  std::cout << (MyString("1") == MyString("123")) << std::endl;
}
