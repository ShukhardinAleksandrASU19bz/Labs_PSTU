#include "Time.h"
#include "Container.h"
#include <iostream>
using namespace std;
void main()
{
	int n;
	cout << "N?"; cin >> n;
	Container<Time> v(n);
	v.Print();
	/*
	Time t = v.Srednee();//����� ������� ��������������
	cout << "Srednee=" << t << endl;
	cout << "Add srednee" << endl;
	cout << "pos?";
	int pos;
	cin >> pos;//������� ��� ����������
	v.Add(pos, t);//����������
	v.Print();//������
	cout << "Delete max: " << endl;
	v.Del();
	v.Print();
	cout << "Delenie na min: " << endl;
	*/
	v.Dobavlenie();
	v.Print();
}