#include <stdio.h>
#include <iostream>
#include "MyString.h"

int main() {
	MyString s1("Hello,");
	MyString s2("world!");
	MyString s3;
	s3 = s1 + s2;
	std::cout << s3 << std::endl;
	MyString s4("ll");
	s3 = s1 - s4;
	std::cout << s3 << std::endl;
	std::cout << s1("KK") << std::endl;
	s3 = s2 * 5;
	std::cout << s3 << std::endl;
}