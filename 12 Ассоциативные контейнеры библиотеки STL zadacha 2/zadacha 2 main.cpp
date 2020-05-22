#include <iostream>
#include <map>
#include "Time.h"
using namespace std;
typedef map<int, Time>TMap;//���������� ��� ��� ������ �� �������
typedef TMap::iterator it;

//������� ��� ������������ �������
TMap make_map(int n)
{
	TMap m;//������ �������
	Time a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		//������� ���� � ��������� �� � �������
		m.insert(make_pair(i, a));
	}
	return m;//���������� ������ ��� �������� ������ �������
}
//������� ��� ������ �������
void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << " - " << m[i] << " " << endl;

}
//���������� �������� ���������������
Time srednee(TMap m)
{
	Time s = m[0];//������ ������� � ��������� �������� �����
	//������� �������
	for (int i = 1; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();//���������� ��������� � �������
	return s / n;
}
//����� ������������� ��������

int Max(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	Time m = (*i).second;//�������� ������� ��������
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//��������
		k++;//������� ���������
	}
	return nom;//����� max
}
//����� ������������ ��������
int Min(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	Time m = (*i).second;//�������� ������� ��������
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//��������
		k++;//������� ���������
	}
	return nom;//����� max
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