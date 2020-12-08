// Copyright 2020 jswark
#include <iostream>
#include "MyString.h"

int main() {
  MyString new_str("AAAB7");
  std::cout << 5 << " - " << new_str.length() << std::endl;
  std::cout << "AAAB7" << " - " << new_str.get() << std::endl;
  MyString new_str1 = new_str*3;
  std::cout << "AAAB7AAAB7AAAB7" << " - " << new_str1.get() << std::endl;
  MyString new_str2("no");
  new_str1 = new_str1 + new_str2;
  std::cout << "AAAB7AAAB7AAAB7no" << " - " << new_str1.get() << std::endl;
  std::cout << "1" << " - " << (new_str1 < new_str2) << std::endl;
  MyString new_str3 = !new_str2;
  std::cout << "NO" << " - " << new_str3.get() << std::endl;
  return 0;
}
