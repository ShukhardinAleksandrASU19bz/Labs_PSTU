#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<double>Vec;//���������� ��� ��� ������ � ��������

//������� ��� ������������ �������
Vec make_vector(int n)
{
	Vec v;//������ ������
	for (int i = 0; i < n; i++)
	{
		double a = rand() % 100;
		v.push_back(a);//��������� � � ����� �������
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
double srednee(Vec v)
{
	double s = 0;
	//������� �������
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
void add_vector(Vec& v, double el, int pos)
{
	//��������� �� ����� pos ������� el
	v.insert(v.begin() + pos, el);
}
//����� ������������� ��������
int max(Vec v)
{

	double m = v[0];//����������� �������
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
//����� ������������ ��������
int min(Vec v)
{
	double m = v[0];//����������� �������
	int	n = 0;//����� ������������ ��������
	for (int i = 0; i < v.size(); i++)//������� �������
		if (m > v[i])
		{
			m = v[i];//����������� �������
			n = i;//����� ������������
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


//�������� �������
void main()
{
	try
	{
		vector<double> v;
		vector<double>::iterator vi = v.begin();
		//������������ �������
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);
		print_vector(v);
		
		//���������� �������������
		int n_max = max(v);//����� ����� �������������
		//������� ��� �������		
		//����� ������� ��� ����������
		add_vector(v, v[n_max], 0);
		print_vector(v);//������ �������
		int n_min = min(v);
		del_vector(v, n_min);//������� ������� � ���� �������
		print_vector(v);
		//������ ������� ��������� �� ����������� �������� �������
		//delenie(v);
		dobavlenie(v);
		print_vector(v);
	}
	catch (int)//���� ��������� ������
	{
		cout << "error!";
	}
}