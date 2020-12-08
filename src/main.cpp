// Copyright 2020 GHA Test Team
#include "MyString.h"
#include<stdio.h>


int main() {
  MyString str("Hello");
  printf("STR: %s\n", str.get());
  std::cout << "Str lenght: " << str.length() << std::endl;
  //
  std::string str1 = "Hello World!";
  MyString str2(str1);
  printf("STR2: %s\n", str2.get());
  std::cout << "Str lenght: " << str2.length() << std::endl;
  //
  MyString str3(str2);
  printf("STR3: %s\n", str3.get());
  std::cout << "Str lenght: " << str3.length() << std::endl;
  //
  MyString str4 = str2;
  printf("%s\n", str4.get());
  std::cout << "Str lenght: " << str4.length() << std::endl;
  //
  MyString str5 = str2 + str3;
  printf("STR2 + STR3: %s\n", str5.get());
  std::cout << "Str lenght: " << str5.length() << std::endl;
  //
  MyString str6 = str2 - str;
  printf("STR2 - STR: %s\n", str6.get());
  std::cout << "Str lenght: " << str6.length() << std::endl;
  //
  MyString str7 = str*5;
  printf("STR*5: %s\n", str7.get());
  std::cout << "Str lenght: " << str7.length() << std::endl;
  //
  MyString str8 = !str7;
  printf("!STR*5: %s\n", str8.get());
  std::cout << "Str lenght: " << str8.length() << std::endl;
  //
  bool result = str == str;
  std::cout << "STR == STR: " << result << std::endl;
  //
  result = str != str;
  std::cout << "STR != STR: " << result << std::endl;
  //
  result = str == str2;
  std::cout << "STR == STR2: " << result << std::endl;
  //
  result = str2 > str;
  std::cout << "STR2 > STR: " << result << std::endl;
  //
  result = str > str2;
  std::cout << "STR > STR2: " << result << std::endl;
  //
  result = str <= str;
  std::cout << "STR <= STR: " << result << std::endl;
  //
  result = str2 >= str;
  std::cout << "STR2 >= STR: " << result << std::endl;
  //
  std::cout << "STR2[1]: " << str2[1] << std::endl;
  //
  std::cout << "Find Hello in STR2: " << str2("Hello") << std::endl;
  std::cout << "Find hello in STR2: " << str2("hello") << std::endl;
  //
  std::cout << "STR2 in COUT: " << str2 << std::endl;
  MyString str9;
  std::cin >> str9;
  std::cout << str9;
  return 0;
}
