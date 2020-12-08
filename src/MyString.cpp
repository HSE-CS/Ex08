// Copyright 2020 GHA Test Team
#include "MyString.h"
#include <cstring>
#include <string>
#include <iostream>

MyString::MyString( const char* x) {
    if (x) {
      len=0;
      str = nullptr;
    }
    else {
      len=strlen(x);
      str = new char [len+1];
      strcpy(str,x);
    }
}

MyString::MyString( std::string x ) {
    len=strlen(x.c_str());
    str = new char [len+1];
    strcpy(str,x.c_str());
}

MyString::MyString( const MyString& s) {
    len=s.len;
    str = new char [len+1];
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
    unsigned l=len+s.len;
    char* buf=new char [l+1];
    strcpy(buf,this->str);
    strcat(buf,s.str);
    MyString ret(buf);
    delete[] buf;
    return ret;
}

MyString MyString::operator-(const MyString& s) {
    unsigned l=len;
    char* buf1=new char [l+1];
    char* buf2=new char [l+1];
    strcpy(buf1,str);
    char* pch = strpbrk (buf1,s.str);
    while(pch != NULL){
      *pch='\0';
      strcpy(buf2,buf1);
      strcat(buf2,pch+1);
      pch=strpbrk (buf1, s.str);
    }
    MyString ret(buf1);
    delete[] buf1;
    delete[] buf2;
    return ret;
}

MyString MyString::operator*(int x) {
    unsigned l=len*x;
    char* buf=new char [l+1];
    if (x>0) {
    strcpy(buf,str);
    for (int i=0;i<x-1;++i)
    strcat(buf,str);
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

MyString& MyString::operator=( MyString&& s) {
    len=s.len;
    delete[] str;
    str=new char [len+1];
    strcpy(str,s.str);
    s.len=0;
    s.str=nullptr;
    return *this;
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

std::ostream& MyString::operator<<(std::ostream& os, MyString& s) {
    return os<<s.str;
}

std::istream& MyString::operator>>(std::istream& is, MyString& s) {
    char* buf=new char [100];
    char ch;
    ch=is.get();
    int i=0,len=100;
    while ((ch!='\n') && (ch!=0)){
      if (i==len) {
        len+=100;
        char* buf2 =new char [len];
        buf[len]='\0';
        strcpy(buf2,buf);
        delete[] buf;
        char* buf =new char [len];
        strcpy(buf,buf2);
        delete[] buf2;
      }
      buf[i]=ch;
      i++;
      ch=is.get();
    }
    s.len=strlen(buf);
    strcpy(s.str,buf);
    return is    
}

char& MyString::operator[] (const int index) {
    return str[index];
}

const char*  MyString::operator()(const char* s) {
    return strstr (str,s);
}

const char* MyString::operator()(std::string s) {
    return strstr (str,s.c_str());
}

MyString& MyString::operator! () {
    for (size_t i=0; i<len; i++) {
      if ((str[i]>64) && (str[i]<91))
      	str[i]+=32;
      if ((str[i]>96) && (str[i]<123))
        str[i]-=32;
    }
    return *this;
}



