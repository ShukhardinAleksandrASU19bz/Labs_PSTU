#include "Time.h"
#include "vector"
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<Time> TVector;
Time s,m;
//������������ �������
TVector make_vector(int n)
{
	Time a;
	TVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}
//������ �������
void print_vector(TVector v)
{
	for (int i = 0; i < v.size(); i++)

		cout << v[i] << endl;
	cout << endl;
}
struct Greater_s //������, ��� s
{
	bool operator()(Time t)
	{
		if (t > s) return true; else return false;
	}
};
struct MAXI //������������
{
	bool operator()(Time t)
	{
		if (t == m) return true; else return false;
	}
};
struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};
struct Comp_less // ��� ���������� �� ��������

{
public:
	bool operator()(Time t1, Time t2)
	{
		if (t1 > t2)return true;
		else return false;
	}
};

Time srednee(TVector v)
{
	Time s = v[0];
	//������� �������
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
void pluss(Time& t)
{
	t = t + s;
}


void main()
{
	int n;
	cout << "N?";
	cin >> n;

	TVector v;
	v = make_vector(n);
	print_vector(v);
	TVector::iterator i;
	//��������� �������� i �� ������������ �������
	i = max_element(v.begin(), v.end());
	cout << "max=" << *(i) << endl;
	m = *(i);
	s = srednee(v);//����� ������� �������������� �������
	cout << "sred=" << s << endl;
	//������ � �������������� ���������
	replace_if(v.begin(), v.end(), MAXI(), s);
	cout << "ZAMENA" << endl;
	print_vector(v);

	cout << "UDALENIE" << endl;
	i = min_element(v.begin(), v.end());
	s = *i;
	//����������� �������� ����������� � min � ����� �������
	i = remove_if(v.begin(), v.end(), Equal_s());
	//������� ��������, ������� � i � �� ����� �������
	v.erase(i, v.end());
	print_vector(v);

	cout << "DOBAVLENIE" << endl;
	s = srednee(v);
	//��� ������� �������� ������� ���������� ������� del
	for_each(v.begin(), v.end(), pluss);
	print_vector(v);
}