// Copyright 2020 Egor Trukhin
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
  std::cout << "\t\"" << tmp2 << "\""
            << " + "
            << "\"" << tmp3 << "\" --> \"" << tmp2 + tmp3 << "\"" << std::endl
            << std::endl;

  std::cout << "Iteration:" << std::endl;
  MyString tmp4("AbCdEfG");
  std::cout << "\tString: " << tmp4 << std::endl;
  std::cout << "\t";
  for (size_t i = 0; i < tmp4.length(); i++) std::cout << tmp4[i] << " _ ";
  std::cout << std::endl << std::endl;

  std::cout << "\'!\' unary operation:" << std::endl;
  MyString a("aabbcczz");
  MyString b("DDFFGGRR");
  MyString c("aaDDccRR");
  std::cout << "\t" << a << " --> " << !a << std::endl;
  std::cout << "\t" << b << " --> " << !b << std::endl;
  std::cout << "\t" << c << " --> " << !c << std::endl;
  return 0;
}
