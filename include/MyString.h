#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <iostream>
#include <string>


class MyString {
private:
	char* my_string = nullptr;
public:
	explicit MyString(const char* = nullptr);
	explicit MyString(std::string);
	MyString(const MyString&);
	MyString(MyString&&) noexcept;
	~MyString();
	unsigned int length() const;
	char* get() const;
	MyString& operator=(const MyString&);
	MyString& operator=(MyString&&) noexcept;
	MyString operator+(const MyString&);
	MyString operator-(const MyString&);
	MyString operator*(unsigned int number);
	MyString& operator!();
	bool operator==(const MyString&) const;
	bool operator!=(const MyString&) const;
	bool operator>(const MyString&) const;
	bool operator<(const MyString&) const;
	bool operator>=(const MyString&) const;
	bool operator<=(const MyString&) const;
	char& operator[](unsigned int) const;
	int operator()(const char*);
	friend std::ostream& operator<<(std::ostream&, MyString&);
	friend std::istream& operator>>(std::istream&, MyString&);
};
#endif  // INCLUDE_MYSTRING_H_