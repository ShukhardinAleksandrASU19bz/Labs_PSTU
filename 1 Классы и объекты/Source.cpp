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
	/*
	A.Init(3.0, 2);//������������� ���������� �
	B.Read();//���� ����� ���������� B
	A.Show();//����� �������� ����� ���������� �
	B.Show();//����� �������� ����� ���������� �
//������ �������� �������, ������������ � ������� ������� Power()
	cout << "A.Power(" << A.first << "," << A.second << ")=" << A.Power() << endl;
	cout << "A.Power(" << B.first << "," << B.second << ")=" << B.Power() << endl;
	//���������
	fraction* X = new fraction;// ��������� ������ ��� ������������ ����������
	X->Init(2.0, 5);//�������������
	X->Show(); //����� �������� �����
	X->Power(); //���������� �������
	cout << "X.Power(" << X->first << "," << X->second << ")=" << X->Power() << endl;
	//�������
	fraction mas[3];//����������� �������
	for (int i = 0; i < 3; i++)
		mas[i].Read();//������ �������� �����
	for (int i = 0; i < 3; i++)
		mas[i].Show();//����� �������� �����
	for (int i = 0; i < 3; i++)
	{
		mas[i].Power();//���������� �������
		cout << "mas[" << i << "].Power(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].Power() << endl;

	}
	//������������ �������
	fraction* p_mas = new fraction[3];//��������� ������
	for (int i = 0; i < 3; i++)
		p_mas[i].Read(); //������ �������� �����
	for (int i = 0; i < 3; i++)
		p_mas[i].Show(); //����� �������� �����
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Power(); //���������� �������
		cout << "p_mas[" << i << "].Power(" << p_mas[i].first << "," << p_mas[i].second;
		cout << ")=" << p_mas[i].Power() << endl;
	}
	//����� ������� make_fraction()
	double y; int z;
	cout << "first?"; cin >> y;
	cout << "second"; cin >> z;
	//���������� F ����������� � ������� ������� make_fraction()
	fraction F = make_fraction(y, z);
	F.Show();
	*/
	A.Init(101, 2);
	A.Show();
	B.Read();
	B.Show();
	cout << "����� ����� ����� first/second: " << A.Ipart() << endl;
	cout << "����� ����� ����� first/second: " << B.Ipart() << endl;
}