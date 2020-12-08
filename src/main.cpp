// Copyright by Stanislav on 07/12/2020.

#include "../include/MyString.h"

int main() {
  MyString s("hello!");
  MyString k = s * 2;
  std::cout << k.get();
  k = k + k;
  std::cout << k;
  std::cout << (k != s);
  return 0;
}
