#include"MyString.h"

int main() {
	const char st[3] = { 'o', 'k', '\0' };
	std::string st_2 = "okey";
	MyString NL;
	std::cout << NL.length() << std::endl;
	MyString str_1(st);
	std::cout << !str_1 << std::endl;
	MyString str_2(st_2);
	std::cout << str_2 * 3 << std::endl;
	std::cout << (str_2 <= str_1) << std::endl;
	std::cout << (str_2 > str_1) << std::endl;
	MyString str_3;
	str_3 = str_2 - str_1;
	std::cout << str_3 << std::endl;
	str_3 = str_2 + str_1;
	std::cout << str_3 << std::endl;
	std::cout << str_2(str_3.get()) << std::endl;
	return 0;
}