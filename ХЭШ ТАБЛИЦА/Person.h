#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
	Person(void);//����������� ��� ����������
public:
	virtual ~Person(void);//����������
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������
	void Input();//������� ��� ����� �������� ���������
	Person(string, string, int);//����������� � �����������
	Person(const Person&);//����������� �����������
	//���������
	string Get_name() { return name; }
	int Get_raiting() { return raiting; }
	string Get_group() { return group; }
	//������������
	void Set_name();
	void Set_raiting();
	void Set_group();
	Person& operator=(const Person&);//���������� �������� ������������
	int Get_asci()
	{
		int s;
		int* ascii_str = new int[name.size()];
		s = 0;
		for (int i = 0; i < name.size(); ++i)
		{
			ascii_str[i] = name[i];
			s += ascii_str[i];
		}
		return s;
	}
	friend istream& operator>>(istream& in, Person& t);
	friend ostream& operator<<(ostream& out, const Person& t);
protected:
	string name;
	string group;
	int raiting;
};

