#include "Time.h"
#include "Vector.h"
#include <iostream>
using namespace std;
void main()
{
	Vector<Time>vec(5);//������� ������ �� 5 ���������
	vec.Print();//������ �������
	Time s = vec.Maxi();
	vec.Add(s, 0);//�������� ������� � ������
	vec.Print();//������ �������

	int p = vec.Min();//����� ������������ �������
	vec.Del(p);//��������
	vec.Print();//������

	s = vec.Srednee();//������� �������������
	cout << "Srednee=" << s << endl;
	vec.dobavlenie(s);//�������
	vec.Print();
}