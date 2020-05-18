#include <iostream>
#include <map>
using namespace std;
typedef multimap<int, double> TMap;//определяем тип для работы со словарем
typedef TMap::iterator it;//итератор
//функция для формирования словаря
TMap make_map(int n)
{
	TMap m;//пустой словарь
	double a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		//создаем пару и добавляем ее в словарь
		m.insert(make_pair(i, a));
	}
	return m;//возвращаем словарь как результат работы функции
}
//функция для печати словаря
void print_map(TMap m)
{
	for (it i= m.begin(); i != m.end(); i++)
		cout <<i->first << " : " << i->second << " " << endl;

}
// поиск максимального элемента
double Max(TMap v)
{
	it i = v.begin();
	double m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
		}
		i++;//итератор
	}
	i = v.find(m);
	cout << "max" << m << endl;
	return m;//номер max
}
double Min(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	double m = (*i).second;//значение первого элемента
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
	i = v.find(m);
	return m;//номер max
}


void main()
{
	int n;
	double mm;
	it sss;
	cout << "N?"; cin >> n;
	TMap m = make_map(n);
	print_map(m);
	//добавление в начало
	sss = m.begin();
	//m.insert(make_pair(0, Max(m)));
	m.emplace(0, Max(m));
	print_map(m);
	
}

