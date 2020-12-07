// Copyright 2020 Dev-will-work
#ifndef INCLUDE_MYSTRING_H
#define INCLUDE_MYSTRING_H
#include <string>
class MyString
{
private:
	char* string;
public:
	MyString(const char* str = nullptr); // -конструктор с одним параметром(есть значение по - умолчанию nullptr).
	MyString(std::string); // -конструктор с одним параметром.
	MyString(const MyString&); // -конструктор копирования.
	MyString(MyString&&); // -конструктор переноса.
	~MyString(); // -деструктор.
	size_t length(); // -количество символов(длина строки).
	char* get(); // -возвращение указателя на данные(тип char*).
	MyString operator+(); // -сложение(конкатенация двух строк).
	MyString operator-(); // -вычитание(из первой строки удаляются все символы, присутствующие во второй строке).
	MyString operator*(); // -умножение на целое число(строка повторяется заданное число раз).
	MyString& operator=(const MyString&); // -копирующее присваивание.
	MyString& operator=(MyString); // -перемещающее присваивание.
	MyString operator==(MyString); // -сравнение на равенство.
	MyString operator!=(MyString); // -сравнение на неравенство.
	MyString operator>(MyString); // -лексографическое сравнение .
	MyString operator<(MyString); // -лексографическое сравнение.
	MyString operator>=(MyString); // -лексографическое сравнение.
	MyString operator<=(MyString); // -лексографическое сравнение.
	MyString operator!(); // - у латинских букв меняется регистр.
	char operator[](int); // - доступ к символу по индексу.
	MyString operator()(MyString); // - поиск подстроки.
	friend std::ostream& operator<<(std::ostream& out, MyString& str); // -чтение из потока.
	friend std::istream& operator>>(std::istream& in, MyString& str); // -запись в поток.
};
#endif  // INCLUDE_MYSTRING_H