// Copyright 2020 Dev-will-work
#ifndef INCLUDE_MYSTRING_H
#define INCLUDE_MYSTRING_H
#include <string>
class MyString
{
private:
	char* string = nullptr;
public:
	MyString(const char* str = nullptr); // -конструктор с одним параметром(есть значение по - умолчанию nullptr).
	MyString(std::string); // -конструктор с одним параметром.
	MyString(const MyString& str); // -конструктор копирования.
	MyString(MyString&& str) : string(str.string) { str.string = nullptr; }; // -конструктор переноса.
	~MyString(); // -деструктор.
	size_t length(); // -количество символов(длина строки).
	char* get(); // -возвращение указателя на данные(тип char*).
	MyString operator+(MyString); // -сложение(конкатенация двух строк).
	MyString operator-(MyString); // -вычитание(из первой строки удаляются все символы, присутствующие во второй строке).
	MyString operator*(int); // -умножение на целое число(строка повторяется заданное число раз).
	MyString& operator=(const MyString&); // -копирующее присваивание.
	MyString& operator=(MyString&&); // -перемещающее присваивание.
	bool operator==(MyString); // -сравнение на равенство.
	bool operator!=(MyString); // -сравнение на неравенство.
	bool operator>(MyString); // -лексографическое сравнение .
	bool operator<(MyString); // -лексографическое сравнение.
	bool operator>=(MyString); // -лексографическое сравнение.
	bool operator<=(MyString); // -лексографическое сравнение.
	MyString operator!(); // - у латинских букв меняется регистр.
	char operator[](int); // - доступ к символу по индексу.
	int operator()(MyString); // - поиск подстроки.
	friend std::ostream& operator<<(std::ostream& out, MyString& str); // -чтение из потока.
	friend std::istream& operator>>(std::istream& in, MyString& str); // -запись в поток.
};
#endif  // INCLUDE_MYSTRING_H