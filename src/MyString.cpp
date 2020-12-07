#include "MyString.h"


MyString::MyString()
{
	this->len = 0;
	this->str = 0;
}

MyString::MyString(size_t len)
{
	this->len = len;
	this->str = new char[(this->len)];
	*(this->str) = 0;
}


MyString::MyString(const char* str) //:MyString(strlen(str) + 1)
{
	this->len = strlen(str);
	this->str = new char[this->len];
	strcpy(this->str, str);
}

MyString::MyString(std::string str) //:MyString(str.length())
{
	this->len = str.length();
	this->str = new char[this->len];
	strcpy(this->str, str.c_str());
}

MyString::MyString(const MyString& str) //:MyString(str.len)
{
	this->len = str.len;
	this->str = new char[this->len];
	strcpy(this->str, str.str);
}

MyString::MyString(MyString&& str)
{
	this->len = str.len;
	this->str = new char[this->len];
	strcpy(this->str, str.str);
	str.str = nullptr;
	str.len = 0;
}

MyString::~MyString()
{
	this->len = 0;
	delete[] this->str;
}

size_t MyString::length()
{
	return this->len;
}

char* MyString::get()
{
	return this->str;
}

MyString MyString::operator+(MyString b)
{
	MyString a(this->len + b.len);
	for (size_t i = 0; i < this->len; i++)
	{
		(a.str)[i] = (this->str)[i];
	}
	for (size_t i = this->len; i < this->len + b.len; i++)
	{
		(a.str)[i] = (b.str)[i];
	}
	return a;
}

MyString MyString::operator-(MyString b)
{
	MyString result(*this);
	size_t k = 0;
	for (size_t i = 0; i < b.len; i++) 
	{
		for (size_t j = 0; j < result.len; j++) 
		{
			if ((result.str)[j] == (b.str[i]))
			{
				result.str = sdvig(result.str, j+1);
				k++;
			}
		}
	}
	(result.str)[k + 1] = '\0';
	return result;
}

MyString MyString::operator*(size_t size)
{
	MyString result(this->len * size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < this->len; j++)
		{
			(result.str)[(i * this->len) + j] = (this->str)[i];
		}
	}
	return result;
}

MyString& MyString::operator=(const MyString& b)
{
	this->len = b.len;
	strcpy(this->str, b.str);
	return *this;
}

MyString& MyString::operator=(MyString&& b)
{
	this->len = b.len;
	strcpy(this->str, b.str);
	return *this;
}

bool MyString::operator==(MyString b)
{
	if (this->len != b.len)
		return false;
	for (size_t i = 0; i < b.len; i++)
	{
		if ((this->str)[i] != (b.str)[i])
			return false;
	}
	return true;
}

bool MyString::operator!=(MyString b)
{
	return !(*this == b);
}

bool MyString::operator<(MyString b)
{
	if (this->len < b.len)
		return true;
	if (this->len > b.len)
		return false;
	for (size_t i = 0; i < this->len; i++)
	{
		if ((this->str)[i] >= (b.str)[i])
		{
			return false;
		}
	}
	return true;
}

bool MyString::operator>(MyString b)
{
	if (this->len > b.len)
		return true;
	if (this->len < b.len)
		return false;
	for (size_t i = 0; i < this->len; i++)
	{
		if ((this->str)[i] <= (b.str)[i])
		{
			return false;
		}
	}
	return true;
}

bool MyString::operator>=(MyString b)
{
	return !(*this < b);
}

bool MyString::operator<=(MyString b)
{
	return !(*this > b);
}

MyString MyString::operator!()
{
	MyString result(*this);
	for (size_t i = 0; i < result.len; i++)
	{
		if ((result.str)[i] > 'A' && (result.str)[i] < 'Z')
			(result.str)[i] = (result.str)[i] - 'A' + 'a';
		
		if ((result.str)[i] > 'a' && (result.str)[i] < 'z')
			(result.str)[i] = (result.str)[i] - 'a' + 'A';
	}
	return result;
}

char MyString::operator[](size_t pos)
{
	return (this->str)[pos];
}

int MyString::operator()(const char* str)
{
	return podstroka(this->str, str);
}

std::ostream& operator<<(std::ostream& os, MyString& a)
{
	return os << a.get();
}

std::istream& operator>>(std::istream& is, MyString& a)
{
	return is >> a.get();
}

char* sdvig(char* str, size_t from)
{
	for (size_t i = from; i < strlen(str); i++)
	{
		str[i - 1] = str[i];
	}
	return str;
}

int podstroka(char* _where, const char* what)
{
	if (strlen(_where) < strlen(what))
		return false;
	bool result = 0;
	int answer = -1;
	for (size_t i = 0; i < strlen(_where) - strlen(what); i++)
	{
		if (result) {
			answer = i - 1;
			break;
		}
		result = true;
		for (size_t j = i; j < i + strlen(what); j++)
		{
			if (_where[j] != what[j - i]) {
				result = false;
				break;
			}
		}
	}
	return answer;
}
