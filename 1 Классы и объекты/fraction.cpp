#include <iostream>
#include "fraction.h"
//#include ""

using namespace std;

//реализация метода для инициализации полей структуры
void fraction::Init(int F, int S)
{
	first = F; second = S;
}
//реализация метода для чтения значений полей структуры
void fraction::Read()
{
	cout << "\n first?"; cin >> first;
	cout << "\n second?"; cin >> second;
}
//реализация метода для вывода значений полей структцры
void fraction::Show()
{
	cout << "\n first=" << first;
	cout << "\n second=" << second;
	cout << endl;
}
//метод для возведения в степень
double fraction::Power()
{
	return pow(first, second);
}
//метод выделение целой части дроби
int fraction::Ipart()
{
	ipart = 0;
	if (second == 0) {
		cout << "Знаменатель равен 0" << endl;
	}
	else {
		if (first >= second)
		{
			ipart = (first / second);
		}
		else ipart = 0;
	}
	return ipart;
}