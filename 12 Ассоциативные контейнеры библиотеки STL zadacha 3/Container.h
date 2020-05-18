#pragma once
#include <iostream>
#include <map> //�������

using namespace std;

//������������������� �����
template<class T>
class Container
{
	map<int, T> v; //��������� �������
	int len; //����� �������
public:
	Container(void); //����������� ��� ����������
	Container(int n); //����������� � �����������
	void Print(); //������
	~Container(void); //����������
	void Add(int, T);
	T Srednee();
	int Max();
	void Del();
	void Delenie();
	void Dobavlenie();
		int Min();

};
//���������� �������
//����������� ��� ����������
template <class T>
Container<T>::Container()

{
	len = 0;
}
//����������
template <class T>
Container<T>::~Container(void)
{
}
//����������� c �����������
template <class T>
Container<T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[i] = a;//�������� � � �������
	}
	len = v.size();
}
//����� ����������
template <class T>
void Container<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << i << " - " << v[i] << " " << endl;
	cout << endl;
}
//���������� �������� ���������������
template<class T>
T Container<T>::Srednee()
{
	Time s = v[0]; //��������� �������� ����� � ������ ������� �������
	//������� �������
	for (int i = 1; i < v.size(); i++)

		s = s + v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
//����������
template<class T>
void Container<T>::Add(int n, T el)
{
	v.insert(make_pair(n, el));//��������� ���� � ��������� �� � �������
}
template <class T>
int Container<T>::Max()
{
	typename map<int, T>::iterator i = v.begin();//�������� ��������� �� ������ �������
	int nom = 0, k = 0;
	Time m = (*i).second;//�������� ������� ��������
	while (i != v.end()) //���� ��� ����� ����������
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
template <class T>
void Container<T>::Del()
{
	int max = Max();
	cout << "max=" << v[max] << " nom=" << max << endl;
	v.erase(max);//������� ������������ �������
}
template<class T>
int Container<T>::Min()
{
	typename map<int, T>::iterator i = v.begin();
	int nom = 0, k = 0;
	Time m = (*i).second;//�������� ������� ��������
	while (i != v.end())
	{
		//����������� ������� �� ������ ���� ����� 0
		if ((*i).second.get_min() != 0 && (*i).second.get_sec() != 0)

			if (m > (*i).second)
			{
				m = (*i).second;
				nom = k;
			}
		i++;//��������
		k++;//������� ���������
	}
	return nom;//����� min
}
template<class T>
void Container<T>::Delenie()
{
	T m = v[Min()];//����� ����������� �������
	cout << "Min= " << m << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] / m;

}
template<class T>
void Container<T>::Dobavlenie()
{
	T m = Srednee();//����� ����������� �������
	cout << "Srednee=" << m << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + m;

}