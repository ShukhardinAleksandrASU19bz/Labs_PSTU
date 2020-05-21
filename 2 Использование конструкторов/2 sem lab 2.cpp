#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

//функция для возврата объекта как результата
Student make_Student()
{
	string s;
	string i;
	float d;
	cout << "введите ФИО: "; cin >> s;
	cout << "введите группу: "; cin >> i;
	cout << "введите средний балл: "; cin >> d;
	Student t(s, i, d);
	return t;
}
//функция для передачи объекта как параметра
void print_Student(Student t)
{
	t.show();
}

int main() {
	setlocale(LC_ALL, "Russian");
	//конструктор без параметров
	Student t1;
	t1.show();
	//конструктор с параметрами
	Student t2("IVAN", "ASU", 15999);
	t2.show();
	//конструктор копирования
	Student t3 = t2;
	t3.show();
	t3.set_FIO("PETR");
	t3.set_group("RIS");
	t3.set_ball(4999.9);
	print_Student(t3);
	t1 = make_Student();
	t1.show();
	return 0;
}
