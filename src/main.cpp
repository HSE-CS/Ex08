#include "mystring.h"
int main() {
	MyString s1("1234");
	MyString s2("12345");
	MyString s3("12345");
	MyString s = s1 + s2;
	MyString ss = s2 - s1;
	MyString sss = s1 * 2;
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
	MyString s4 = s1;
	std::cout << s4 << std::endl;
	MyString s5("aaaaa");
	std::cout << s5 << std::endl;
	s5[4] = 'm';
	std::cout << s5 << std::endl;
	return 0;
}