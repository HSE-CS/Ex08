#include "MyString.h"
using namespace std;
int main()
{
    MyString s1("Hello,");
    cout << s1.length()<<endl;
    MyString s2("world!");
    cout << s2.length()<<endl;
    MyString s3;
    s3 = s1 + s2;
    cout << s3.length()<<endl;
    cout << s3 << endl;
    cout << s3.operator+(s1).get() << endl;
    cout << s3.operator-(s2).get() << endl;
    cout << s3.operator*(2).get() << endl;
    return 0;
}
