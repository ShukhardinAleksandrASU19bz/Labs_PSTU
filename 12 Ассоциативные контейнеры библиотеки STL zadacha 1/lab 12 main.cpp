#include <iostream>
#include <map>
using namespace std;
typedef multimap<int, double> TMap;//���������� ��� ��� ������ �� ��������
typedef TMap::iterator it;//��������
//������� ��� ������������ �������
TMap make_map(int n)
{
	TMap m;//������ �������
	double a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		//������� ���� � ��������� �� � �������
		m.insert(make_pair(i, a));
	}
	return m;//���������� ������� ��� ��������� ������ �������
}
//������� ��� ������ �������
void print_map(TMap m)
{
	for (it i= m.begin(); i != m.end(); i++)
		cout <<i->first << " : " << i->second << " " << endl;

}
// ����� ������������� ��������
double Max(TMap v)
{
	it i = v.begin();
	double m = (*i).second;//�������� ������� ��������
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
		}
		i++;//��������
	}
	i = v.find(m);
	cout << "max" << m << endl;
	return m;//����� max
}
double Min(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	double m = (*i).second;//�������� ������� ��������
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
	i = v.find(m);
	return m;//����� max
}


void main()
{
	int n;
	double mm;
	it sss;
	cout << "N?"; cin >> n;
	TMap m = make_map(n);
	print_map(m);
	//���������� � ������
	sss = m.begin();
	//m.insert(make_pair(0, Max(m)));
	m.emplace(0, Max(m));
	print_map(m);
	
}

