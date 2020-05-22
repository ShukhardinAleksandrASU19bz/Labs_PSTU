#include "Time.h"
#include "vector"
#include <iostream>
#include <algorithm> 
#include <stack>
#include <functional>

using namespace std;

typedef stack<Time> St;//����
typedef vector<Time> Vec; //
typedef stack<Time, vector<Time>> TStack;

Time s, m;


Vec copy_stack_to_vector(TStack s)
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
TStack copy_vector_to_stack(Vec v)
{
	TStack s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//�������� � ���� ������� �������
	}
	return s; //������� ���� ��� ��������� �������
}
//������������ �������
TStack make_stack(int n)
{
	Time a;
	TStack v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push(a);
	}
	return v;
}

void print_stack(TStack s)
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
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)

		cout << v[i] << endl;
	cout << endl;
}

struct MAXI //������������
{
	bool operator()(Time t)
	{
		if (t == m) return true; else return false;
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
struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};

void pluss(Time& t)
{
	t = t + s;
}

Time Srednee(TStack s)
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
Time Max(TStack s)
{
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	Vec::iterator i;
	//��������� �������� i �� ������������ �������
	i = max_element(v.begin(), v.end());
	m = *(i);
	s = copy_vector_to_stack(v);//������� ������ � ����
	return m; //���������� m
}
//����� ������������ ��������
Time Min(TStack s)
{
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	Vec::iterator i;
	//��������� �������� i �� ������������ �������
	i = min_element(v.begin(), v.end());
	m = *(i);
	s = copy_vector_to_stack(v);//������� ������ � ����
	return m; //���������� m
}
void replace_if_st_max(TStack& s,Time ss)
{
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	m = Max(s);
	replace_if(v.begin(), v.end(),MAXI(), ss);
	s = copy_vector_to_stack(v);//������� ������ � ����
}
void erase_stack(TStack& st, Time ss)
{
	Vec v = copy_stack_to_vector(st);//�������� ���� � ������
	Vec::iterator i;
	s = Min(st);
	i = remove_if(v.begin(), v.end(), Equal_s());
	//������� ��������, ������� � i � �� ����� �������
	v.erase(i, v.end());
	st = copy_vector_to_stack(v);//������� ������ � ����
}
void for_each_pluss(TStack& st)
{
	Vec v = copy_stack_to_vector(st);//�������� ���� � ������
	s = Srednee(st);
	for_each(v.begin(), v.end(), pluss);
	st = copy_vector_to_stack(v);//������� ������ � ����
}

void main()
{
	int n;
	cout << "N?";
	cin >> n;
	TStack v;
	v = make_stack(n);
	print_stack(v);

	s = Srednee(v);//����� ������� �������������� �������
	cout << "sred=" << s << endl;
	cout << "max=" << Max(v) << endl;
	cout << "min=" << Min(v) << endl;
	replace_if_st_max(v,s);
	print_stack(v);

	cout << "UDALENIE" << endl;
	erase_stack(v, Min(v));
	print_stack(v);


	//��� ������� �������� ������� ���������� ������� pluss
	cout << "DOBAVLENIE" << endl;
	for_each_pluss(v);
	print_stack(v);
}