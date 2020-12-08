// Copyright 2020 mkhorosh
#include <iostream>
#include "MyString.h"
#include <string>

int main() {
  char st = 'a';
  char *p = &st;
  MyString www(p);
  char mas[4] = {"std"};
  MyString ww(&mas[1]);
  MyString w();
  int a = std::strlen(mas);
  std::cout << a << std::endl;
  std::string name = "Marina";
  MyString myname(name);
  a = name.length();
  std::cout << a << std::endl;
  MyString mylastname("Khorosh");
  MyString note;
  note = myname + mylastname;
  std::cout << note.get() << std::endl;
  bool i;
  i = (myname != mylastname);
  std::cout << i << std::endl;
}
