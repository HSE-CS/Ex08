// Copyright 2020 sccc
#include <iostream>
#include <string>
#include "MyString.h"

int main() {
    MyString a;
    std::cout << a.length() << std::endl;
    
    
    
  MyString f("123");
  int b = 3;
  MyString c;
  c = f * b;
  std::cout << c.get() << std::endl;
}
