#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//открыть для записи
	if (!stream)return -1;//ошибка открытия файла
	int n;
	Time p;
	cout << "N?"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//ввод атрибутов объекта из стандартного потока
		stream << p << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
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
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	int i = 0; Time p;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла

		if (stream.eof())break;
		i++;

		//если номер объекта не равен k, то записываем его во вспомогательый файл
		if (i != k) temp << p;
	}
	//закрыть файлы
	stream.close(); temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}
//удалить записи равные заданному значению
int del_file4(const char* f_name, Time pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	int i = 0; Time p;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла

		if (stream.eof())break;
		i++;

		//
		if (p != pp) 
		temp << p;
	}
	//закрыть файлы
	stream.close(); temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}
int del_uvel90(const char* f_name, Time pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	int i = 0; Time p;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла

		if (stream.eof())break;
		i++;

		//
		p=p + pp;
			temp << p;
	}
	//закрыть файлы
	stream.close(); temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}
//добавление записи в середину
int add_file(const char* f_name, int k, Time pp)

{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	Time p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (i == k)
		{
			temp << pp;//записать в temp новую запись
			l++;
		}
		temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//количество добавленных
}
//добавление в конец
int add_end(const char* f_name, Time pp)
{
	fstream stream(f_name, ios::app);//открыть для добавления
	if (!stream)return -1;//ошибка открытия файла
	stream << pp; //записать новую запись
	return 1;
}
int add_file4(const char* f_name, int nom, int tt)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
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
				temp << pp;//записать в temp новую запись
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
			temp << pp;//записать в temp новую запись
			l++;
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//количество добавленных
}
int change_file(const char* f_name, int k, Time pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
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
	return l;//количество измененных элементов
}