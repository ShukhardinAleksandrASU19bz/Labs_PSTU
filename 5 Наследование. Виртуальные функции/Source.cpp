#include "Object.h"
#include "Vector.h"
#include <string>
#include <iostream>
#include "Pair.h"
#include "Fraction.h"

using namespace std;

int main()
{
	Vector v(5);//вектор из 5 элементов
	Pair a;//объект класса Pair
	cin >> a;
	Fraction b;// объект класса Fration
	cin >> b;
	Object* p = &a;//ставим указатель на объект класса Pair
	v.Add(p);//добавляем объект в вектор
	p = &b;//ставим указатель на объект класса Fration
	v.Add(p); //добавляем объект в вектор
	cout << v;//вывод вектора
	return 0;
}