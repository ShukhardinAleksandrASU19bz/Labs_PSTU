#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(int F, int S)
{
	fraction t; //������� ��������� ����������
	t.Init(F, S); //���������������� ���� ���������� t � ������� ���������� �������
	return t; //������� �������� ���������� t
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//����������� ���������� � � �
	fraction A, B;
	A.Init(101, 2);
	A.Show();
	B.Read();
	B.Show();
	cout << "����� ����� ����� first/second: " << A.Ipart() << endl;
	cout << "����� ����� ����� first/second: " << B.Ipart() << endl;
}