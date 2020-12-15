// Copyright 2020 Dumarevskaya
#include "MyString.h"

int main() {
  MyString a;
  std::cout << a.length() << std::endl;
  MyString b("hello");
  std::cout << b.length() << std::endl;
  a = b;
  std::cout << a.get() << std::endl;
  MyString c(std::string("Hello"));
  std::cout << c.get() << std::endl;
  c = a + b;
  std::cout << c.get() << std::endl;
  MyString g("123456789"), d("2468");
  c = g - d;
  std::cout << c.get() << std::endl;
  int q = 3;
  c = d * q;
  std::cout << c.get() << std::endl;
  bool s = a == b;
  std::cout << s << std::endl;
  s = a < g;
  std::cout << s << std::endl;
  c = !a;
  std::cout << c.get() << std::endl;
  b = !c;
  std::cout << b.get() << std::endl;
  std::cout << c[3] << std::endl;
  std::cout << a("EL") << std::endl;
  std::cout << c("2") << std::endl;
  return 0;
}
