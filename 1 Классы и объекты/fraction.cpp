#include <iostream>
#include "fraction.h"
//#include ""

using namespace std;

//���������� ������ ��� ������������� ����� ���������
void fraction::Init(int F, int S)
{
	first = F; second = S;
}
//���������� ������ ��� ������ �������� ����� ���������
void fraction::Read()
{
	cout << "\n first?"; cin >> first;
	cout << "\n second?"; cin >> second;
}
//���������� ������ ��� ������ �������� ����� ���������
void fraction::Show()
{
	cout << "\n first=" << first;
	cout << "\n second=" << second;
	cout << endl;
}
//����� ��� ���������� � �������
double fraction::Power()
{
	return pow(first, second);
}
//����� ��������� ����� ����� �����
int fraction::Ipart()
{
	ipart = 0;
	if (second == 0) {
		cout << "����������� ����� 0" << endl;
	}
	else {
		if (first >= second)
		{
			ipart = (first / second);
		}
		else ipart = 0;
	}
	return ipart;
}