// Copyright by Stanislav on 07/12/2020.

#include "../include/MyString.h"

int main() {
  MyString s("hello!");
  MyString k = s * 2;
  std::cout << k.get() << std::endl;
  k = k + k;
  std::cout << k  << std::endl;;
  std::cout << (k != s)  << std::endl;;
  return 0;
}
