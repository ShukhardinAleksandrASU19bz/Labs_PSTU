#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

//����������� ��� ����������
Student::Student()
{
	FIO = "";
	group = "";
	ball = 0;
	cout << "����������� ��� ���������� ��� �������" << this << endl;
}
//����������� � �����������
Student::Student(string N, string K,float S)
{
	FIO = N;
	group = K;
	ball = S;
	cout << "����������� c ����������� ��� �������" << this << endl;
}
//����������� �����������
Student::Student(const Student& t)
{
	FIO = t.FIO;
	group = t.group;
	ball = t.ball;
	cout << "����������� ����������� ��� �������" << this << endl;
}
//����������
Student::~Student()
{
	cout << "���������� ��� �������" << this << endl;
}
//���������
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
//������������
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
//����� ��� ��������� ���������
void Student::show()
{
	cout << "FIO: " << FIO << endl;
	cout << "group: " << group << endl;
	cout << "ball: " << ball << endl;
}