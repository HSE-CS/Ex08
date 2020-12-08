//  Copyright 2020 AndreyBakurskii
#include "MyString.h"

int main() {
  MyString s1("Hello,");
  MyString s2("world!");
  MyString s3;
  s3 = s1 + s2;
  std::cout << s3 << "\n";
  std::cout << s3("ll") << "\n";  // 2
  std::cout << s3("mama") << "\n";  // -1
  return 0;
}
