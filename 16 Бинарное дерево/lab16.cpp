#include <iostream>
#include <cstring>
#include "point.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	int n = 0, k = 0, count2 = 0;
	point* p = NULL;
	point* pp = NULL;
	point* ppp = NULL;
	int j;
	char* a;
	char s[50];
	do
	{
		cout << "1. ��������� �������� ������" << endl;
		cout << "2. �������� �������� ������" << endl;
		cout << "3. ����� � ������ �� ��������" << endl;
		cout << "4. �������������� � ������ ������" << endl;
		cout << "0. �����" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			cout << "������� ���������� ���������" << endl;
			cin >> n;
			p = Tree(n, p);
			cout << endl;
			break;
		case 2:
			Treeprint2(p, count2);
			cout << endl;
			break;
		case 3:
			cout << "������� ������� �������: " << endl;
			cin >> s;
			n = 0;
			j = 0;
			a = new char[strlen(s) + 1];
			strcpy_s(a, strlen(s) + 1, s);
			n = poisk_balance(p, a,j);
			if (n > 0)cout << "�����!" << j << "���������" << endl;
			else cout << "�� �����!" << endl;
			break;
		case 4:
			preobrazovanie(p, pp);
			cout << "��������������� ������" << endl;
			Treeprint2(pp, count2);
			break;
		}
	} while (k != 0);

	system("pause");
	return 0;
}