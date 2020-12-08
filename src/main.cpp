// Copyright 2020 Konina Tatiana
#include <iostream>
#include <string>
#include "MyString.h"
int main() {
  MyString a;
  std::cout << 0 << " - " << a.length() << std::endl;
  MyString a1("hello");
  std::cout << 5 << " - " << a1.length() << std::endl;
  MyString a3("123");
  MyString b3(a3);
  std::cout << "123" << " - " << b3.get() << std::endl;
  MyString a4("123");
  MyString b4(a4);
  MyString c4;
  c4 = a4 + b4;
  std::cout << "123123" << " - " << c4.get() << std::endl;
  MyString a5("123");
  MyString b5;
  MyString c5;
  c5 = a5 + b5;
  std::cout << "123" << " - " << c5.get() << std::endl;
  MyString a6(std::string("Hello"));
  std::cout << "Hello" << " - " << a6.get() << std::endl;
  MyString a7("123456789");
  MyString b7("2468");
  MyString c7;
  c7 = a7 - b7;
  std::cout << "13579" << " - " << c7.get() << std::endl;
  MyString a8("123");
  int b8 = 3;
  MyString c8;
  c8 = a8 * b8;
  std::cout << "123123123" << " - " << c8.get() << std::endl;
  MyString a9("123");
  MyString b9("123");
  bool c9 = a9 == b9;
  std::cout << true << " - " << c9 << std::endl;
  MyString a10("123");
  MyString b10("1234");
  bool c10 = a10 == b10;
  std::cout << false << " - " << c10 << std::endl;
  MyString a11("123");
  MyString b11("1234");
  bool c11 = a11 != b11;
  std::cout << true << " - " << c11 << std::endl;
  MyString a12("123");
  MyString b12("1234");
  bool c12 = b12 >= a12;
  std::cout << true << " - " << c12 << std::endl;
  MyString a13("45");
  MyString b13("1234");
  bool c13 = b13 <= a13;
  std::cout << true << " - " << c13 << std::endl;
  MyString a14("abc");
  MyString b14;
  b14 = !a14;
  std::cout << "ABC" << " - " << b14.get() << std::endl;
  MyString a15("abc123");
  MyString b15;
  b15 = !a15;
  std::cout << "ABC123" << " - " << b15.get() << std::endl;
  MyString a16("45");
  char b16 = '5';
  std::cout << b16 << " - " << a16[1] << std::endl;
  MyString a17("454545");
  std::cout << 0 << " - " << a17("45") << std::endl;
  MyString a18("454545");
  std::cout << -1 << " - " << a18("33") << std::endl;
  return 0;
}



