#include "Vector.h"
#include <iostream>
using namespace std;

// ���������� �� �������������� ��������� ���������� � ������� ������������ ���� ������.
int main()
{
	setlocale(LC_ALL, "Russian");
	//�������������� ����
	try
	{
		Vector x(2);//������ �� ���� ���������

		Vector y;//������ ������
		cout <<"������ �: "<< x;//������ ������� �
		cout <<"������ �: "<< y;//������ ������� y

		cout << "����� ������� �� ������ � �������?";
		int i;
		cin >> i;
		//����� �������� � ������� i, ���� ����� ������ 2 ��� ������ 0, ��
		//������������ �������������� ��������
		cout << x[i] << endl;
		//���������� �������� � ������, ���� MAX_SIZE=2, �� ������������
		//�������������� ��������
		cout << x() << endl;
		cout << y() << endl;
		//������� ���� ������� �� �������
		--x;
		cout <<"����� ������� � ����� �������� ��������: " <<x;
		Vector c(10);
		c[1] = 1;
		cout << c << endl;
		cout << c() << endl;
		c = c - 11;
		cout << c << endl;
		cout << c() << endl;
		//������� ���� ������� �� �������
		--x;
		cout << x; //������ ������
		//������� ���� ������� �� �������

		//������������ �������������� ��������
		--x;
	}
	//���������� ����������
	catch (int)
	{
		cout << "ERROR!!!"<< endl;
	}//��������� �� ������
	return 0;
}