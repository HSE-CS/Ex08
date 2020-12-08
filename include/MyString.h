// Created by mila on 08.12.2020.

#ifndef EX08_MYSTRING_H
#define EX08_MYSTRING_H

class MyString {
private:
    char *str = new char;
public:
    
    explicit MyString(const char *);           // - конструктор с одним параметром (есть значение по-умолчанию nullptr).
    explicit MyString(std::string);            // - конструктор с одним параметром.
    MyString(const MyString &);                // - конструктор копирования.
    MyString(MyString &&);                     // - конструктор переноса.
    ~MyString();                               // - деструктор.
    int length() const;                        // - количество символов (длина строки).
    char *get();                               // - возвращение указателя на данные (тип char*).

    MyString operator+(const Fraction &);       // сложение (конкатенация двух строк).
    MyString operator-(const Fraction &);       // вычитание (из первой строки удаляются все символы, присутствующие во второй строке).
    MyString operator*(int);                    // умножение на целое число (строка повторяется заданное число раз).
    MyString &operator=(const MyString &);      // - копирующее присваивание.
    MyString &operator=(MyString &&);           // - перемещающее присваивание.

    char &operator[](size_t) const;          //  - доступ к символу по индексу.
    int operator()(const char *);            // - поиск подстроки.

    friend std::ostream &operator>>(std::ostream &, MyString &);      // - чтение из потока.
    friend std::istream &operator>>(std::istream &, MyString &);      // - запись в поток.

    bool operator==(const MyString &) const;       // - сравнение на равенство.
    bool operator!=(const MyString &) const;       // - сравнение на неравенство.
    bool operator>(const MyString &) const;        //  - лексографическое сравнение .
    bool operator<(const MyString &) const;        // - лексографическое сравнение.
    bool operator>=(const MyString &) const;       // - лексографическое сравнение.
    bool operator<=(const MyString &) const;       //- лексографическое сравнение.

    MyString operator!(const MyString &) const;    //  - у латинских букв меняется регистр.

};

#endif //EX08_MYSTRING_H
