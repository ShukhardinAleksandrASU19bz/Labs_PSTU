#pragma once
#include "Temp.h"
#include <iostream>
#include <fstream>
#include <string>
#include "listT.h"

using namespace std;


//������� ����
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int n;
	Temp p;
	n = 10;
	//cout << "N?"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		p.temperatura = rand() % 50 - 30;
		//cin >> p;//���� ��������� ������� �� ������������ ������
		stream << p << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���������� ���������� ��������
}

//������ �� �����

int file_read(const char* f_name, hran& v)
{
	v.clear();
fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Temp p; int i = 0;
	while (stream >> p)
	{
		//it i = v.begin();
		//if (p.atr != 666){
			v.push_back(p);
			i++;
	}
	stream.close();
	return i;
	return i;
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Temp p; int i = 0;
	while (stream >> p)
	{
		cout << p << endl;
		i++;
	}
	stream.close();
	return i;
}

//������ � ����
int file_zap(const char* f_name, hran v)
{
	j = 0;
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)return -1;//������ �������� �����
	int i = 0;
	for ( it i= v.begin(); i!= v.end(); i++)
	{
		j++;
		stream << *i;
	}
	stream.close();
	return j;
}