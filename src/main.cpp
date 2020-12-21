#include "../include/mystring.h"
int main() {
	mystring s1("1234");
	mystring s2("12345");
	mystring s3("12345");
	mystring s = s1 + s2;
	mystring ss = s2 - s1;
	mystring sss = s1 * 2;
	std::cout << s << std::endl;
	std::cout << ss << std::endl;
	std::cout << sss << std::endl;
	std::cout << (s1 < s2) << std::endl;
	std::cout << (s1 <= s2) << std::endl;
	std::cout << (s1 > s2) << std::endl;
	std::cout << (s1 >= s2) << std::endl;
	std::cout << (s2 == s3) << std::endl;
	std::cout << (s1 * 2) << std::endl;
	std::cout << (s2 - s1) << std::endl;
	std::cout << (s1 + s2) << std::endl;
	mystring s4 = s1;
	std::cout << s4 << std::endl;
	mystring s5("aaaaa");
	std::cout << s5 << std::endl;
	s5[4] = 'm';
	std::cout << s5 << std::endl;
	return 0;
}