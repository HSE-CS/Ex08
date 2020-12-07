// Copyright 2020 GHA Test Team
#include "MyString.h"
#include <cstring>
#include <string>


MyString::MyString( const char* x) {
    if (x)
      len=0;
      str = nullptr;
    else
      len=strlen(x);
      str = new char [len+1];
      strcpy(str,x);
}

MyString::MyString( std::string x ) {
    this.len=strlen(x.c_str());
    this.str = new char [len+1];
    strcpy(str,x.c_str());
}

MyString::MyString( const MyString& s) {
    len=s.len;
    this.str = new char [len+1];
    strcpy(str,s.str);    
}

MyString::MyString( MyString&& s) {
    len=s.len;
    str=s.str;
    s.str=nullptr;
    s.len=0;
}

MyString::~MyString() {
    len=0;
    delete[]str;
}

int MyString::length() const {
    return len;
}

const char* MyString::get() const{
    return str;
}

MyString MyString::operator+(const MyString& s) {
    unsigned l=this.len+s.len;
    char* buf=new char [l+1];
    strcpy(buf,this.str);
    strcat(buf,s.str);
    MyString ret(buf);
    delete[] buf;
    return ret;
}

MyString MyString::operator-(const MyString& s) {
    unsigned l=this.len;
    char* buf=new char [l+1];
    strcpy(buf,this.str);
    while(strcspn(buf,s.str)!=strlen(buf)){
    
    }
}

MyString MyString::operator*(int x) {
    unsigned l=this.len*x;
    char* buf=new char [l+1];
    if (x>0) {
    strcpy(buf,this.str);
    for (int i=0;i<x-1;++i)
    strcat(buf,s.str);
    }
    MyString ret(buf);
    delete[] buf;
    return ret;
}

MyString& MyString::operator=(const MyString& s) {
    len=s.len;
    delete[] str;
    str=new char [len+1];
    strcpy(str,s.str);
    return *this;
}

MyString& MyString::operator=(const MyString&& s) {
    len=s.len;
    delete[] str;
    str=new char [len+1];
    strcpy(str,s.str);
    s.len=0;
    s.str=nullptr
}

bool MyString::operator!= (const MyString& s1, const MyString& s2) {
    if (strcmp(s1.str,s2.str))
      return true;
    else
      return false;
}

bool MyString::operator== (const MyString& s1, const MyString& s2) {
    return !(s1!=s2);
}

bool MyString::operator> (const MyString& s1, const MyString& s2) {
    if (strcmp(s1.str,s2.str)>0)
      return true;
    else
      return false;
}

bool MyString::operator< (const MyString& s1, const MyString& s2) {
    if (strcmp(s1.str,s2.str)<0)
      return true;
    else
      return false;
}

bool MyString::operator>= (const MyString& s1, const MyString& s2) {
    return ((s1>s2) || (s1==s2));
}

bool MyString::operator<= (const MyString& s1, const MyString& s2) {
    return ((s1<s2) || (s1==s2));
}

ostream& MyString::operator<<(ostream& os, MyString& s) {
    return os<<s.str;
}

istream& MyString::operator>>(istream& is, MyString& s) {
    
    
    
}

