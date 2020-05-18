#pragma once
#include "Temp.h"
#include <iostream>
#include <list>
#include <algorithm>

typedef list<Temp> hran;
typedef hran::iterator it;

hran srtemp;
int j, kk;

//������� ��� ������������ list�
hran make_list(int n)
{
	hran v;
	for (int i = 0; i < n; i++)
	{
		double a = rand() % 50 - 30;
		Temp TT(a);
		v.push_back(TT);//��������� � � ����� list�
	}
	return v;//���������� list ��� �������� ������ �������
}

//������� ��� ������ list�
int print_list(hran v)
{
	j = 0;
	for (it i = v.begin(); i != v.end(); i++)
	{
		//cout/* << (*i).atr << " "*/ << (*i).temperatura << endl;
	//	if ((*i).atr != 666)
		{
			cout << j + 1 << "-� �����, ";
			cout << *i;
			j++;
		}
	}
	cout << endl;
	return j;
}
//���������� �������� ���������������
Temp srednee(hran v)
{
	Temp s;
	for (it i = v.begin(); i != v.end(); i++)
		//if ((*i).atr != 666)
		{
			s = s + (*i);
			kk++;
		}
	cout << endl;
	//int n = v.size();//���������� ��������� � list�
	return s / kk;
}
int dni_sr(hran v)
{
	Temp t = srednee(v);
	j = 0;
	for (it i = v.begin(); i != v.end(); i++)
	{
		//if ((*i).atr != 666) {

			if ((*i) > t)
			{
				cout << j + 1 << "-� �����, ";
				cout << *i;
			}
			j++;
		//}
	}
	cout << endl;
	return j;
}
int otrezok(hran v)
{
	kk = 0;
	j = 0;
	for (it i = v.begin(); i != v.end(); i++)
	{
		//if ((*i).atr != 666) {
			if ((*i) > 0)
			{
				kk++;
				if (kk > j) j = kk;
			}
			else kk = 0;
		//}
	}
	cout << endl;
	return j;
}
int add_list(hran& v, Temp el, int pos)
{
	j = 0;
	it i = v.begin();
	advance(i, pos - 1);
	v.insert(i, el);
	j++;
	return j;
}
int change_listK(hran& v, int pos)
{
	j = 0;
	it i = v.begin();
	advance(i, pos - 1);
	cin >> *i;
	j++;
	return j;
}
int change_list(hran& v, Temp s)
{
	int j = count(v.begin(), v.end(), s);
	for (int k = 0; k < j; k++)
	{
		it i = find(v.begin(), v.end(), s);
		cin >> *i;
	}
	return j;
}
//���������� �������� � �����
int add_list(hran& v, Temp el)
{
	j = 0;
	v.push_back(el);
	j++;
	return j;
}

//����� ������������� ��������
Temp max(hran v)
{
	it i = max_element(v.begin(), v.end());
	return *i;
}

//������� ������� �� ������� pos
int del_listK(hran& v, int pos)
{
	j = 0;
	it i = v.begin();
	advance(i, pos - 1);
	//(*i).atr = 666;
	v.erase(i);
	j++;
	return j;
}
int del_list(hran& v, Temp el)
{
	int j = count(v.begin(), v.end(), el);
	for (int k = 0; k < j; k++)
	{
		it i = find(v.begin(), v.end(), el);
		//(*i).atr = 666;
		v.erase(i);
	}
	return j;
}

//����� ������������ ��������
Temp min(hran v)
{
	it i = min_element(v.begin(), v.end());
	return *i;
}