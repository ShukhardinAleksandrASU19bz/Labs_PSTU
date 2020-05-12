#pragma once
#include "Pair.h"
class Fraction :
	public Pair
{
public:
	Fraction(void); // констурктор без параметров
public:
	~Fraction(void); //деструктор
	void Show();//функция для просмотра атрибутов класса с помощью указателя
	Fraction(int, int);//конструктор с параметрами
	Fraction(const Fraction&);// консруктор копирования
	int Get_ff() { return ff; }//селектор
	int Get_ss() { return ss; }//селектор
	void Set_ss(int);//модификатор
	void Set_ff(int);//модификатор
	Fraction& operator=(const Fraction&); //оператор присваивания
	friend bool operator>(const Fraction& c1, const Fraction& c2);
	friend bool operator==(const Fraction& c1, const Fraction& c2);
	friend bool operator<(const Fraction& c1, const Fraction& c2);
	friend bool operator!=(const Fraction& c1, const Fraction& c2);
	friend istream& operator>>(istream& in, Fraction& l);// операция ввода
	friend ostream& operator<<(ostream& out, const Fraction& l);//операция вывода
protected:
	int ff;
	int ss;
};

