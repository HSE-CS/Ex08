//  Copyright 2020 DBarinov
#include "MyString.h"

int main() {
  MyString s1("Commit");
  MyString s2("passed");
  MyString s3;
  s3 = s1 + s2;
  std::cout << s3 << "\n";
  std::cout << s3("ll") << "\n";
  std::cout << s3("fork") << "\n";
  return 0;
}

