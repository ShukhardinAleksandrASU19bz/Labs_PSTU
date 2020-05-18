#pragma once
#include "Temp.h"
#include <iostream>
#include <fstream>
#include <string>
#include "listT.h"

using namespace std;


//создать файл
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//открыть для записи
	if (!stream)return -1;//ошибка открытия файла
	int n;
	Temp p;
	n = 10;
	//cout << "N?"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		p.temperatura = rand() % 50 - 30;
		//cin >> p;//ввод атрибутов объекта из стандартного потока
		stream << p << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}

//чтение из файла

int file_read(const char* f_name, hran& v)
{
	v.clear();
fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
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
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	Temp p; int i = 0;
	while (stream >> p)
	{
		cout << p << endl;
		i++;
	}
	stream.close();
	return i;
}

//запись в файл
int file_zap(const char* f_name, hran v)
{
	j = 0;
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)return -1;//ошибка открытия файла
	int i = 0;
	for ( it i= v.begin(); i!= v.end(); i++)
	{
		j++;
		stream << *i;
	}
	stream.close();
	return j;
}