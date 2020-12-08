// Created by mila on 08.12.2020.

#ifndef EX08_MYSTRING_H
#define EX08_MYSTRING_H

class MyString
{
private:
    char *str;
public:
    explicit MyString( const char* =nullptr);  // - конструктор с одним параметром (есть значение по-умолчанию nullptr).
    explicit MyString( std::string );  // - конструктор с одним параметром.
    MyString( const MyString&  );  // - конструктор копирования.
    MyString( MyString&& );  // - конструктор переноса.
    ~MyString();  // - деструктор.
    int length();  // - количество символов (длина строки).
    char* get();  // - возвращение указателя на данные (тип char*).
/*
 * String(size_t);   // конструктор с параметром числового типа
   String(const char* =nullptr);// конструктор с параметром-указателем
   String(const String&); // конструктор копирования
   String(String&&);  // конструктор перемещения


   String::String(size_t len)
{
	this->len = len;
	buf = new char[len];
	*buf = 0;
}

String::String(const char * str) :String(strlen(str) + 1)
{
	strcpy(buf, str);
}
String::String(const String& s) : String(s.len)
{
	strcpy(buf, s.buf);
}
String::String(String && s)
{
	buf = s.buf;
	len = s.len;
	s.buf = nullptr;
	s.len = 0;
}

 * */
    // сложение (конкатенация двух строк).
    MyString operator+( const Fraction& );

    // вычитание (из первой строки удаляются все символы, присутствующие во второй строке).
    MyString operator-( const Fraction& );

    // умножение на целое число (строка повторяется заданное число раз).
    MyString operator*( int );

    // - копирующее присваивание.
    MyString& operator=( const MyString& );

    // - перемещающее присваивание.
    MyString& operator=( MyString&& );
/*
Операция **присваивания** определена в любом классе по умолчанию как поэлементное копирование.
 Если класс содержит поля, память под которые выделяется динамически,
 необходимо определить собственную операцию присваивания.
 Чтобы сохранить семантику присваивания,
 функция должна возвращать ссылку на объект,
для которого она вызвана и принимать в качестве
 параметра ссылку на присваиваемый объект.

Оператор = можно перегружать только методом класса.
*/

    //  - доступ к символу по индексу.
    char& operator[]( size_t ) const;

    // - поиск подстроки.
    int operator()( const char* );



    // - чтение из потока.
    friend ostream& operator>>( ostream&, MyString& );
    // - запись в поток.
    friend istream& operator>>( istream&, MyString& );

/*class Complex
{
     ...
     friend ostream& operator<<(ostream& os, Complex& c);
     friend istream& operator>>(istream& is, Complex& c);
     ...
};
ostream& operator<<(ostream& os, Complex& c) {
    return os<<'('<<c.re<<','<<c.im<<')';
}
istream& operator>>(istream& is, Complex& c) {
    return is>>c.re>>c.im;
}
int main() {
Complex c(0,0); cin>>c; // 23,45 cout<<c; // (23,45)
}
*/

// - сравнение на равенство.
    bool operator==( const MyString& ) const;
// - сравнение на неравенство.
    bool operator!=( const MyString& ) const;
//  - лексографическое сравнение .
    bool operator>( const MyString& ) const;
// - лексографическое сравнение.
    bool operator<( const MyString& ) const;
// - лексографическое сравнение.
    bool operator>=( const MyString& ) const;
//- лексографическое сравнение.
    bool operator<=( const MyString& ) const;
//  - у латинских букв меняется регистр.
    MyString operator!( const MyString& ) const;

/*Поскольку в операции участвует только один операнд, то никаких внешних ссылок методу, реализующему операцию, передавать не нужно.

```cpp
Complex operator- ()
{
   Complex temp;
   temp.Re=-Re;
   temp.Im=-Im;
   return temp;
}
*/



};






#endif //EX08_MYSTRING_H
