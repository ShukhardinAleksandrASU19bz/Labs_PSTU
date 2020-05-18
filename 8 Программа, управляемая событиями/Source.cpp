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
	Person* a = new Person;//создаем объект класса Person
	a->Input();
	Student* b = new Student; //создаем объект класса Student
	b->Input();
	a->Show();
	b->Show();
	Vector v(10);//Создаем вектор
	Object* p = a;//ставим указатель на объект класса Person
	v.Add();//добавляем объект в вектор
	p = b;//ставим указатель на объект класса Student
	v.Add(); //добавляем объект в вектор
	v.Show();//вывод вектора
	v.Del();//удаление элемента
	cout << "\n Vector size=" << v();
*/
	
	Dialog D;
	D.Execute();
	return 0;
}