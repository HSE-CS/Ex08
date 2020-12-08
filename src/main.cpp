// Copyright 2020 Ozhiganova Polina
#include "MyString.h"

int main() {
  MyString len;
  std::cout << len.length() << std::endl;

  MyString s1("not empty");
  std::cout << s1.length() << std::endl;

  MyString hello("Hello");
  MyString everyone(hello);
  MyString new_string;
  new_string = hello + everyone;
  std::cout << new_string.get() << std::endl;

  MyString new_str("new");
  MyString empty1;
  MyString empty2;
  empty2 = new_str + empty1;
  std::cout << empty2.get() << std::endl;

  MyString str1("Little Molly");
  MyString str2("lte");
  MyString str3;
  str3 = str1 - str2;
  std::cout << str3.get() << std::endl;

  MyString str4("Hi");
  int num = 5;
  MyString str5;
  str5 = str4 * num;
  std::cout << str5.get() << std::endl;

  MyString st1("123");
  MyString st2("123");
  std::cout << (st1 == st2) << std::endl;  //true

  MyString st3("123");
  MyString st4("1234");
  std::cout << (st3 == st4) << std::endl;  //false

  MyString nq1("123");
  MyString nq2("1234");
  std::cout << (nq1 != nq2) << std::endl;  // true

  MyString be1("123");
  MyString be2("1234");
  std::cout << (be2 >= be1) << std::endl;  //true

  MyString le1("45");
  MyString le2("46");
  std::cout << (le2 <= le1) << std::endl;  // true

  MyString abc("aBc");
  MyString emp;
  emp = !abc;
  std::cout << emp.get() << std::endl;

  MyString abc123("Abc123");
  MyString emp2;
  emp2 = !abc123;
  std::cout << emp2.get() << std::endl;
  
  MyString a45("45");
  std::cout << a45[1] << std::endl;

  MyString a3("454545");
  std::cout << a3("45") << std::endl; // 0

  MyString a3_45("454545");
  std::cout << a3_45("33") << std::endl;// -1

  return 0;
}