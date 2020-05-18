#include <iostream>
#include <vector>
#include <cstdlib>
#include "Time.h"

using namespace std;

typedef vector<Time> Vec; //���������� ��� ��� ������ � ��������

//������� ��� ������������ �������
Vec make_vector(int n)
{
	Vec v;//������ ������
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100;
		int b= rand() % 100;
		int c = a + b * 60;
		Time TT(c/60, c%60);
		//Time TT(a, b);
		v.push_back(TT);//��������� � � ����� �������
	}
	return v;//���������� ������ ��� �������� ������ �������
}
//������� ��� ������ �������
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
//���������� �������� ���������������
Time srednee(Vec v)
{
	Time s;
	//������� �������
	for (int i = 0; i < v.size(); i++)
		s+= v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
void add_vector(Vec& v, Time el, int pos)
{
	//��������� �� ����� pos ������� el
	v.insert(v.begin() + pos, el);
}
//����� ������������� ��������
int max(Vec v)
{
	Time m = v[0];//����������� �������
	int	n = 0;//����� ������������ ��������
	for (int i = 0; i < v.size(); i++)//������� �������
		if (m < v[i])
		{
			m = v[i];//������������ �������
			n = i;//����� �������������
		}
	return n;
}
//������� ������� �� ������� pos
void del_vector(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}
//����� ������������ ��������
int min(Vec v)
{
	Time m = v[0];//����������� �������
	int	n = 0;//����� ������������ ��������
	for (int i = 0; i < v.size(); i++)//������� �������
		if (m > v[i])
		{
			m = v[i];//����������� �������
			n = i;//����� ������������
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

//�������� �������

void main()
{

		vector<Time> v;
		vector<Time>::iterator vi = v.begin();
		//������������ �������
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);
		print_vector(v);
		//���������� ��������
		Time el = v[max(v)];
		//����� ������� ��� ����������
		add_vector(v, el, 0);
		//������ �������
		print_vector(v);

		int n_min = min(v);//����� ����� �������������
		del_vector(v,n_min);//������� ������� � ���� �������
		print_vector(v);
		dobavlenie(v);//
		print_vector(v);


}