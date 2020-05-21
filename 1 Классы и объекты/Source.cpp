#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(int F, int S)
{
	fraction t; //создали временную переменную
	t.Init(F, S); //инициализировали поля переменной t с помощью параметров функции
	return t; //вернули значение переменной t
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//определение переменных А и В
	fraction A, B;
	A.Init(101, 2);
	A.Show();
	B.Read();
	B.Show();
	cout << "Целая часть дроби first/second: " << A.Ipart() << endl;
	cout << "Целая часть дроби first/second: " << B.Ipart() << endl;
}