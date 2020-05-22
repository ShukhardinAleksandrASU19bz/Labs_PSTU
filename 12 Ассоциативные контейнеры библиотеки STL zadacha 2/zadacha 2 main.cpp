#include <iostream>
#include <map>
#include "Time.h"
using namespace std;
typedef map<int, Time>TMap;//определ€ем тип дл€ работы со словаре
typedef TMap::iterator it;

//функци€ дл€ формировани€ словар€
TMap make_map(int n)
{
	TMap m;//пустой словарь
	Time a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		//создаем пару и добавл€ем ее в словарь
		m.insert(make_pair(i, a));
	}
	return m;//возвращаем вектор как результа работы функции
}
//функци€ дл€ печати словар€
void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << " - " << m[i] << " " << endl;

}
//вычисление среднего арифметического
Time srednee(TMap m)
{
	Time s = m[0];//первый элемент Ц начальное значение суммы
	//перебор словар€
	for (int i = 1; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();//количество элементов в словаре
	return s / n;
}
//поиск максимального элемента

int Max(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	Time m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//итератор
		k++;//счетчик элементов
	}
	return nom;//номер max
}
//поиск минимального элемента
int Min(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	Time m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//итератор
		k++;//счетчик элементов
	}
	return nom;//номер max
}
void delenie(TMap& v)
{
	Time m = v[Min(v)];
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] / m;

}
void main()
{
	int n;
	cout << "N?"; cin >> n;
	map<int, Time> m = make_map(n);
	print_map(m);
	
	int min = Min(m);
	cout << "min=" << m[min] << " nom=" << min << endl;
	m.erase(min);
	print_map(m);
}