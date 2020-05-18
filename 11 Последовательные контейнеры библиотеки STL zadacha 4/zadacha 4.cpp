#include "Time.h"
#include <iostream>

#include <stack>
#include <vector>
using namespace std;

typedef stack<Time>St;//����
typedef vector<Time>Vec;//������

St make_stack(int n)
{
	St s;
	Time t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//���� ����������
		s.push(t);//���������� �� � ����
	}
	return s;//������� ���� ��� ��������� �������
}
//�������� ���� � ������
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//���� ���� �� ������
	{
		//�������� � ������ ������� �� ������ �����
		v.push_back(s.top());
		s.pop();
	}
	return v; //������� ������ ��� ��������� �������
}
//�������� ������ � ����
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//�������� � ���� ������� �������
	}
	return s; //������� ���� ��� ��������� �������
}
void print_stack(St s)
{
	//�������� ���� � ������
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())//���� ���� �� ������
	{
		cout << s.top() << endl;//����� �������� � ������� �����
		s.pop();//������� ������� �� �������
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
}
//���������� �������� ��������
Time Srednee(St s)
{

	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	int n = 1;
	Time sum = s.top();//��������� ����������� �����
	s.pop();//������� ������ ������� �� �������
	while (!s.empty())//���� ���� �� ������
	{
		sum = sum + s.top();//�������� � ����� ������� �� ������� �����
		s.pop();//������� �������
		n++;
	}
	s = copy_vector_to_stack(v);//����������� ������ � ����
	return sum / n; //������� ������� ��������������
}
//���������� �������� � ����
void Add_to_stack(St& s, Time el, int pos)
{
	Vec v;
	Time t;
	int i = 1;//����� �������� � �����
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� �������
		//���� ����� ����� ������ �������, �� ������ �������� �������
		if (i == pos)v.push_back(el);//�������� ����� ������� � ������
		v.push_back(t);//�������� ������� �� ����� � ������
		s.pop();//������� ������� �� �����
		i++;
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}
//����� ������������� �������� � �����
Time Max(St s)
{
	Time m = s.top();//���������� m ����������� �������� �� ������� �����
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	while (!s.empty())//���� ��� �� ������
	{
		if (s.top() > m)m = s.top();//��������� m � ������ � ������� �����
		s.pop();//������� ������� �� �����
	}
	s = copy_vector_to_stack(v);//������� ������ � ����

	return m; //���������� m
}
//����� ������������ ��������
Time Min(St s)
{
	Time m = s.top();
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
//������� ������������ ������� �� �����
void Delete_from_stack(St& s)
{
	Time m = Min(s);//
	Vec v;
	Time t;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� ������� �����
		//���� �� �� ����� �������������, ������� ������� � ������

		if (t != m)v.push_back(t);
		s.pop();//������� ������� �� �����
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}
//������� �� �����������
void Delenie(St& s)
{
	Time m = Min(s);//������� ����������� �������
	Vec v;
	Time t;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top(); //�������� ������� �� �������
			v.push_back(t / m);//����� t �� ����������� � ��������� � ������
		s.pop();//������� ������� �� �������
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}
void dobavlenie(St& s)
{
	Time sr = Srednee(s);//������� ����������� �������
	Vec v;
	Time t;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top(); //�������� ������� �� �������
		v.push_back(t + sr);//����� t �� ����������� � ��������� � ������
		s.pop();//������� ������� �� �������
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}


void main()
{
	Time t;
	St s;
	int n;

	cout << "n?";
	cin >> n;
	s = make_stack(n);//������� ����
	print_stack(s);//������ �����
	t =Max(s);//��������� �������
	cout << "Max=" << Max(s) << endl;
	cout << "Add max:" << endl;

	Add_to_stack(s, t,1);//���������� ��������
	print_stack(s);//������ �����
	
	cout << "Delete min:" << endl;
	Delete_from_stack(s);
	print_stack(s);
	
	cout << "dobavlenie:" << endl;
	dobavlenie(s);
	print_stack(s);
}