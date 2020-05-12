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
	/*
	A.Init(3.0, 2);//инициализация переменной А
	B.Read();//ввод полей переменной B
	A.Show();//вывод значений полей переменной А
	B.Show();//вывод значений полей переменной В
//ввывод значения степени, вычисленного с помощью функции Power()
	cout << "A.Power(" << A.first << "," << A.second << ")=" << A.Power() << endl;
	cout << "A.Power(" << B.first << "," << B.second << ")=" << B.Power() << endl;
	//указатели
	fraction* X = new fraction;// выделение памяти под динамическую переменную
	X->Init(2.0, 5);//инициализация
	X->Show(); //вывод значений полей
	X->Power(); //вычисление степени
	cout << "X.Power(" << X->first << "," << X->second << ")=" << X->Power() << endl;
	//массивы
	fraction mas[3];//определение массива
	for (int i = 0; i < 3; i++)
		mas[i].Read();//чтение значений полей
	for (int i = 0; i < 3; i++)
		mas[i].Show();//вывод значений полей
	for (int i = 0; i < 3; i++)
	{
		mas[i].Power();//вычисление степени
		cout << "mas[" << i << "].Power(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].Power() << endl;

	}
	//динамические массивы
	fraction* p_mas = new fraction[3];//выделение памяти
	for (int i = 0; i < 3; i++)
		p_mas[i].Read(); //чтение значений полей
	for (int i = 0; i < 3; i++)
		p_mas[i].Show(); //вывод значений полей
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Power(); //вычисление степени
		cout << "p_mas[" << i << "].Power(" << p_mas[i].first << "," << p_mas[i].second;
		cout << ")=" << p_mas[i].Power() << endl;
	}
	//вызов функции make_fraction()
	double y; int z;
	cout << "first?"; cin >> y;
	cout << "second"; cin >> z;
	//переменная F формируется с помощью функции make_fraction()
	fraction F = make_fraction(y, z);
	F.Show();
	*/
	A.Init(101, 2);
	A.Show();
	B.Read();
	B.Show();
	cout << "Целая часть дроби first/second: " << A.Ipart() << endl;
	cout << "Целая часть дроби first/second: " << B.Ipart() << endl;
}