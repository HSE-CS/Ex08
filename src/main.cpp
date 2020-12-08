// Copyright by Stanislav on 07/12/2020.

#include "../include/MyString.h"

int main() {
  MyString a("123");
  int b = 3;
  MyString c;
  c = a * b;
  std::cout << c.get();
}
