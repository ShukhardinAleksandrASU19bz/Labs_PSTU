#include "Time.h"
#include "list"
#include <iostream>
#include <algorithm>
using namespace std;

typedef list<Time> Tlist;
typedef Tlist::iterator it;
Time s, m;
//������������ �����
Tlist make_list(int n)
{
	Time a;
	Tlist v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}
//������ �����
void print_list(Tlist v)
{
	for (it i = v.begin(); i != v.end(); i++)
		cout <<(*i) << endl;
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

Time srednee(Tlist v)
{
//	it i = v.begin();
	Time s;
	//������� �����
	for (it i = v.begin(); i != v.end(); i++)
		s = s + *i;
	int n = v.size();//���������� ��������� � �����
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

	Tlist v;
	v = make_list(n);
	print_list(v);
	Tlist::iterator i;
	//��������� �������� i �� ������������ �������
	i = max_element(v.begin(), v.end());
	cout << "max=" << *(i) << endl;
	m = *(i);
	s = srednee(v);//����� ������� �������������� �����
	cout << "sred=" << s << endl;
	//������ � �������������� ���������
	replace_if(v.begin(), v.end(), MAXI(), s);
	cout << "ZAMENA" << endl;
	print_list(v);

	cout << "UDALENIE" << endl;
	i = min_element(v.begin(), v.end());
	s = *i;
	//����������� �������� ����������� � min � ����� �����
	i = remove_if(v.begin(), v.end(), Equal_s());
	//������� ��������, ������� � i � �� ����� �����
	v.erase(i, v.end());
	print_list(v);

	cout << "DOBAVLENIE" << endl;
	s = srednee(v);
	//��� ������� �������� ����� ���������� ������� del
	for_each(v.begin(), v.end(), pluss);
	print_list(v);
}