#include "MyString.h"

#define PRNT(x) std::cout << (x) << std::endl

int main() {
  MyString s1("Hello,");
  MyString s2(" world!");
  MyString s3;
  MyString s4("Hello, world!");
  PRNT(s3.length());
  s3 = s1 + s2;
  PRNT(s1);
  PRNT(s2);
  PRNT(s3);
  PRNT(s3("wo"));
  PRNT(s3("mama"));  // -1
  PRNT(s3 == s4);
  PRNT(s3 > s4);
  PRNT(s3 < s4);
  PRNT(s3 >= s4);
  PRNT(s3 <= s4);
  PRNT(s2 > s4);
  MyString diff = s4 - s1;
  PRNT(diff);
  MyString times = s3*4;
  PRNT(times);
  MyString n = !s4;
  PRNT(n);
}
