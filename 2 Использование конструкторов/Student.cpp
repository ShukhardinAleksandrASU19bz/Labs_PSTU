#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

//конструктор без параметров
Student::Student()
{
	FIO = "";
	group = "";
	ball = 0;
	cout << "Конструктор без параметров для объекта" << this << endl;
}
//конструктор с параметрами
Student::Student(string N, string K,float S)
{
	FIO = N;
	group = K;
	ball = S;
	cout << "Конструктор c параметрами для объекта" << this << endl;
}
//конструктор копирования
Student::Student(const Student& t)
{
	FIO = t.FIO;
	group = t.group;
	ball = t.ball;
	cout << "Конструктор копирования для объекта" << this << endl;
}
//деструктор
Student::~Student()
{
	cout << "Деструктор для объекта" << this << endl;
}
//селекторы
string Student::get_FIO()
{
	return FIO;
}
string Student::get_group()
{
	return group;
}
float Student::get_ball()
{
	return ball;
}
//модификаторы
void Student::set_FIO(string N)
{
	FIO = N;
}
void Student::set_group(string K)
{
	group = K;
}
void Student::set_ball(float S)
{
	ball = S;
}
//метод для просмотра атрибутов
void Student::show()
{
	cout << "FIO: " << FIO << endl;
	cout << "group: " << group << endl;
	cout << "ball: " << ball << endl;
}