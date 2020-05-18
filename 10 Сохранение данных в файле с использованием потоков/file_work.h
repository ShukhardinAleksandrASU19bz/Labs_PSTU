#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int n;
	Time p;
	cout << "N?"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//���� ��������� ������� �� ������������ ������
		stream << p << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���������� ���������� ��������
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Time p; int i = 0;
	while (stream >> p)
	{
		cout << p << endl;
		i++;
	}
	stream.close();
	return i;
}
int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int i = 0; Time p;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����

		if (stream.eof())break;
		i++;

		//���� ����� ������� �� ����� k, �� ���������� ��� �� �������������� ����
		if (i != k) temp << p;
	}
	//������� �����
	stream.close(); temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}
//������� ������ ������ ��������� ��������
int del_file4(const char* f_name, Time pp)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int i = 0; Time p;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����

		if (stream.eof())break;
		i++;

		//
		if (p != pp) 
		temp << p;
	}
	//������� �����
	stream.close(); temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}
int del_uvel90(const char* f_name, Time pp)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int i = 0; Time p;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����

		if (stream.eof())break;
		i++;

		//
		p=p + pp;
			temp << p;
	}
	//������� �����
	stream.close(); temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}
//���������� ������ � ��������
int add_file(const char* f_name, int k, Time pp)

{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Time p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (i == k)
		{
			temp << pp;//�������� � temp ����� ������
			l++;
		}
		temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� �����������
}
//���������� � �����
int add_end(const char* f_name, Time pp)
{
	fstream stream(f_name, ios::app);//������� ��� ����������
	if (!stream)return -1;//������ �������� �����
	stream << pp; //�������� ����� ������
	return 1;
}
int add_file4(const char* f_name, int nom, int tt)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Time p,pp; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (i-1 == nom)
		{
			for (int j = 0; j < tt; j++) 
			{
				cin >> pp;
				temp << pp;//�������� � temp ����� ������
				l++;
			}
		}
		temp << p;
	}
	if
		(nom == i)
	{
		for (int j = 0; j < tt; j++)
		{
			cin >> pp;
			temp << pp;//�������� � temp ����� ������
			l++;
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� �����������
}
int change_file(const char* f_name, int k, Time pp)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Time p; int i = 0, l = 0;
	char x;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (i == k)
		{
			cout << p << " - is changing... Continue[y/n]?\n";
			cin >> x;
			if (x == 'n' || x == 'N')break;
			temp << pp;
			l++;
		}
		else temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� ���������� ���������
}