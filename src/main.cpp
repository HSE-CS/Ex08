// Copyright 2020 Bugrov
#include "MyString.h"
int main() {	
	MyString s1("Hello,");
	MyString s2("world!");
	MyString s3;
	
	std::cout << s1<< s2<<'\n';
	std::cout << s1("llo,");   // 2
	std::cout << s3("mama"); // -1

	return 0;
}