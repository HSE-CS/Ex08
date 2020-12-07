// Copyright 2020 test
#include "MyString.h"

int main() {
    MyString a;                 // I did an empty class
    MyString b("123");          // I did one more variable
    a = b;                      // i so like variable b so I made a copy of it
    std::cout << a << "\n";     // and show that to the world <3
    b = a + a;                  // i need MyString longer
    std::cout << b.get() << "\n";   // and show that to the world one more time
    a = b * 3;                  // I SAID LONGER
    std::cout << a.get() << "\n";   // AND DISPLAY THAT
    std::cout << a.length() << "\n";  // what's the length of string? Hmm...
    MyString c("hELLO");        // I think i need more variables
    c = !c;                     // oops, I misclicked
    std::cout << c << "\n";     // Eee! Default "Hello"
    std::cout << c[1] << "\n";  // Just 'e' -_-
    std::cout << (a == b) << "\n";   // by the way a != b
    MyString d("Idk what to show & i'm very tired");  // does this need a com?
    std::cout << (d == c) << "\n";  // What is bigger?
    MyString e;                 // ok, the last one
    e = std::move(d);           // look a this duude
    std::cout << e;             // i wanna sleep so this us the end! Good Luck
}
