// Copyright 2020 VadMack

#include <iostream>
#include "MyString.h"
#include "cstring"

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
  std::cout << "123 - " << c.get() << std::endl;
  std::cout << "123123123 - " << (c * 3).get() << std::endl;
  std::cout << (MyString("123") == MyString("123")) << std::endl;
  std::cout << (MyString("1") == MyString("123")) << std::endl;
  std::cout << (MyString("123") > MyString("123")) << std::endl;
  std::cout << "1 - " << (MyString("1234") >= MyString("123")) << std::endl;
  std::cout << (MyString("123") < MyString("123")) << std::endl;
  std::cout << "1 - " << (MyString("123") <= MyString("45")) << std::endl;
  std::cout << "ABC - " << (!MyString("abc")).get() << std::endl;
  std::cout << "a - " << (MyString("abc"))[0] << std::endl;
  MyString a("454545");
  std::cout << "0 - " << a("45") << std::endl;
  std::cout << "-1 - " << a("33") << std::endl;
  MyString str8("123");
  int numb = 3;
  MyString str9;
  str9 = str8 * numb;
  std::cout << "123123123 - " << str9.get() << std::endl;
  std::cout << (strcmp("123123123", str9.get())) << std::endl;
  std::cout << (MyString("1234") != MyString("123")) << std::endl;
}
