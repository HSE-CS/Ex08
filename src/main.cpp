// Copyright 2020 SmirnovGrigory
#include "MyString.h"

int main() {
	MyString a("abracdabra");
  std::cout << a.get()<<std::endl;
  MyString b("243456");
	MyString null, null2;
  std::cout << b.get() << std::endl << b.length() << std::endl;
	std::cout << (MyString("123") + b).get() << std::endl;
	std::cout <<(null2 + b).get() << std::endl;
	std::cout << (MyString("1224324526") - MyString("24")).get() << std::endl;
  std::cout << (MyString("12") * 3).get() << std::endl;
  MyString c = a + b;
  a = b;
  std::cout << c.get() << b.get() << a.get() <<  std::endl;
}

