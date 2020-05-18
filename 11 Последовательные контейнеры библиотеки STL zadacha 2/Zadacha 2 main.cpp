#include <iostream>
#include <vector>
#include <cstdlib>
#include "Time.h"

using namespace std;

typedef vector<Time> Vec; //определяем тип для работы с вектором

//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100;
		int b= rand() % 100;
		int c = a + b * 60;
		Time TT(c/60, c%60);
		//Time TT(a, b);
		v.push_back(TT);//добавляем а в конец вектора
	}
	return v;//возвращаем вектор как результа работы функции
}
//функция для печати вектора
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
//вычисление среднего арифметического
Time srednee(Vec v)
{
	Time s;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s+= v[i];
	int n = v.size();//количество элементов в векторе
	return s / n;
}
void add_vector(Vec& v, Time el, int pos)
{
	//добавляем на место pos элемент el
	v.insert(v.begin() + pos, el);
}
//поиск максимального элемента
int max(Vec v)
{
	Time m = v[0];//минимальный элемент
	int	n = 0;//номер минимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m < v[i])
		{
			m = v[i];//максимальный элемент
			n = i;//номер максимального
		}
	return n;
}
//удалить элемент из позиции pos
void del_vector(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}
//поиск минимального элемента
int min(Vec v)
{
	Time m = v[0];//минимальный элемент
	int	n = 0;//номер минимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m > v[i])
		{
			m = v[i];//минимальный элемент
			n = i;//номер минимального
		}
	return n;
}
void delenie(Vec& v, int m)
{
	Time h= v[m];
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = (v[i] / h);
	}
}
void dobavlenie(Vec& v)
{
	Time s = srednee(v);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + s;
}

//основная функция

void main()
{

		vector<Time> v;
		vector<Time>::iterator vi = v.begin();
		//формирование вектора
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);
		print_vector(v);
		//вычисление среднего
		Time el = v[max(v)];
		//вызов функции для добавления
		add_vector(v, el, 0);
		//печать вектора
		print_vector(v);

		int n_min = min(v);//найти номер максимального
		del_vector(v,n_min);//удалить элемент с этим номером
		print_vector(v);
		dobavlenie(v);//
		print_vector(v);


}