#include "Object.h"
#include "Vector.h"
#include <string>
#include <iostream>
#include "Pair.h"
#include "Fraction.h"

using namespace std;

int main()
{
	Vector v(5);//������ �� 5 ���������
	Pair a;//������ ������ Pair
	cin >> a;
	Fraction b;// ������ ������ Fration
	cin >> b;
	Object* p = &a;//������ ��������� �� ������ ������ Pair
	v.Add(p);//��������� ������ � ������
	p = &b;//������ ��������� �� ������ ������ Fration
	v.Add(p); //��������� ������ � ������
	cout << v;//����� �������
	return 0;
}