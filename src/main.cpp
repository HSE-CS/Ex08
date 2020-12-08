// Copyright 2020 Urtyukov Ilya
#include <iostream>
#include <string>

#include "MyString.h"

int main() {
  MyString tmp1("hello");
  std::cout << "MyString C example:\n\tarray: " << tmp1 << std::endl;
  std::cout << "\tsize: " << tmp1.length() << std::endl << std::endl;

  MyString tmp2(std::string("hello"));
  std::cout << "MyString C++ example:\n\tarray: " << tmp2 << std::endl;
  std::cout << "\tsize: " << tmp2.length() << std::endl << std::endl;

  std::cout << "Concatenation:" << std::endl;
  MyString tmp3(", world!");
  MyString tmp4 = tmp2 + tmp3;
  std::cout << "\t" << tmp2 << " + "
            << "\"" << tmp3 << "\" --> \"" << tmp4 << "\"" << std::endl;

  std::cout << "Iteration:" << std::endl;
  MyString tmp5("AbCdEfG");
  std::cout << "\tString: " << tmp5 << std::endl;
  std::cout << "\t";
  for (size_t i = 0; i < tmp5.length(); i++) std::cout << tmp5[i] << " _ ";
  std::cout << std::endl << std::endl;

  std::cout << "\'!\' unary operation:" << std::endl;
  MyString a("aabbcczz");
  MyString b("DDFFGGRR");
  MyString c("aaDDccRR");
  MyString a1(!a);
  MyString b1(!b);
  MyString c1(!c);
  std::cout << "\t" << a << " --> " << a1 << std::endl;
  std::cout << "\t" << b << " --> " << b1 << std::endl;
  std::cout << "\t" << c << " --> " << c1 << std::endl;
  return 0;
}
