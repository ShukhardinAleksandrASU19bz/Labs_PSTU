#include "Person.h"
#include "Student.h"
#include <iostream>
#include <string>
#include "Vector.h"
#include "dialog.h"
 
using namespace std;

int main()
{
/*
	Person* a = new Person;//������� ������ ������ Person
	a->Input();
	Student* b = new Student; //������� ������ ������ Student
	b->Input();
	a->Show();
	b->Show();
	Vector v(10);//������� ������
	Object* p = a;//������ ��������� �� ������ ������ Person
	v.Add();//��������� ������ � ������
	p = b;//������ ��������� �� ������ ������ Student
	v.Add(); //��������� ������ � ������
	v.Show();//����� �������
	v.Del();//�������� ��������
	cout << "\n Vector size=" << v();
*/
	
	Dialog D;
	D.Execute();
	return 0;
}