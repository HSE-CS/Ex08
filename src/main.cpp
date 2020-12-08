// Copyright 2020 SmirnovGrigory
#include "MyString.h"

int main() {
	MyString a("abracdabra");
	std::cout << a.get()<<std::endl;
  MyString b(a);
	std::cout << b.get() << std::endl << b.length() << std::endl;
}
