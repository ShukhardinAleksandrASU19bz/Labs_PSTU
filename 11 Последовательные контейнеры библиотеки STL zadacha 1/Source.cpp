#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<double>Vec;//определяем тип для работы с вектором

//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)
	{
		double a = rand() % 100;
		v.push_back(a);//добавляем а в конец вектора
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
double srednee(Vec v)
{
	double s = 0;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//количество элементов в векторе
	return s / n;
}
void add_vector(Vec& v, double el, int pos)
{
	//добавляем на место pos элемент el
	v.insert(v.begin() + pos, el);
}
//поиск максимального элемента
int max(Vec v)
{

	double m = v[0];//минимальный элемент
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
//поиск минимального элемента
int min(Vec v)
{
	double m = v[0];//минимальный элемент
	int	n = 0;//номер минимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m > v[i])
		{
			m = v[i];//минимальный элемент
			n = i;//номер минимального
		}
	return n;
}
void delenie(Vec& v)
{
	double m = min(v),
		vv = v[m];
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] / vv;

}
void dobavlenie(Vec& v)
{
	double s = srednee(v);
		for (int i = 0; i < v.size(); i++)
			v[i]=v[i]+s;
}


//основная функция
void main()
{
	try
	{
		vector<double> v;
		vector<double>::iterator vi = v.begin();
		//формирование вектора
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);
		print_vector(v);
		
		//вычисление максимального
		int n_max = max(v);//найти номер максимального
		//позиция для вставки		
		//вызов функции для добавления
		add_vector(v, v[n_max], 0);
		print_vector(v);//печать вектора
		int n_min = min(v);
		del_vector(v, n_min);//удалить элемент с этим номером
		print_vector(v);
		//каждый элемент разделить на минимальное значение вектора
		//delenie(v);
		dobavlenie(v);
		print_vector(v);
	}
	catch (int)//блок обработки ошибок
	{
		cout << "error!";
	}
}