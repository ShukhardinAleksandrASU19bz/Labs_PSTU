#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pair
{
	//конструктор без параметров
public:
	Pair(void);
public:
	//деструктор
	virtual ~Pair(void);
	//конструктор с параметрами
	Pair(int, int);
	//конструктор копирования
	Pair(const Pair&);
	//селекторы
	int Get_first() { return first; }
	int Get_second() { return second; }
	//модификтаоры
	void Set_first(int);
	void Set_second(int);
	//перегрузка операции присваивания
	Pair& operator=(const Pair&);
	friend bool operator>(const Pair& c1, const Pair& c2);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Pair& c);
	friend ostream& operator<<(ostream& out, const Pair& c);
	//атрибуты
protected:
	int first;
	int second;
};

