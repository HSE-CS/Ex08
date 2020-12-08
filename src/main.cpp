//Copyright 2020 Pasmanik Irina
#include "MyString.h"
#include <iostream>
#include <string>

int main() {
	MyString a;
	MyString b("abcde");
	MyString c("defgh");
	MyString d("abcABC");

	a = b;
	std::cout << a.get() << "\n";

	a = b * 2;
	std::cout << a.get() << "\n";

	a = b + c;
	std::cout << a.get() << "\n";

	a = b - c;
	std::cout << a.get() << "\n";

	std::cout << (b == c) << "\n";

	std::cout << (b >= d) << "\n";

	a = !d;
	std::cout << a.get() << "\n";

	std::cout << b[2] << "\n";
	
	return 0;
}
