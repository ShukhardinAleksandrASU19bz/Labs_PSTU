#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Time p, p1, p2,pp,ppp;
	int k, c,tt;
	char file_name[30];
	//cout << "������� ��� �����: " << endl;
	//cin >> file_name;

	do
	{
	cout << "\n1. ������� ����";
	cout << "\n2. ������� ����" << endl;
	cin >> c;
	switch (c)
	{
	case 1: cout << "file name?"; cin >> file_name;
		k = make_file(file_name);
		if (k < 0)cout << "Can't make file";
		break;
	case 2: cout << "file name?"; cin >> file_name;
		k = print_file(file_name);
		if (k == 0)cout << "Empty file\n";
		if (k < 0)cout << "Can't read file\n";

		break;
	}
}
	while (k < 0);
system("cls");

	do
	{ //����
		cout<<"------------------------" << file_name << "------------------------" << endl;
		k = print_file(file_name);
		cout << "\n1. ������� ����";
		cout << "\n2. ������� ����";
		cout << "\n3. �������� ����";
		cout << "\n4. ������� ������ �� �����";
		cout << "\n5. �������� ������ � ����";
		cout << "\n6. �������� ������ � �����";
		cout << "\n7. ������� ��� ������ ������ ";
		cout << "\n8. ��������� ��� �������� �� ";
		cout << "\n9. �������� � ��������� ����� ";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "file name?"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Can't make file";
			break;
		case 2: cout << "file name?"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "Can't read file\n";
			break;
		case 3: //cout << "file name?"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "Can't read file\n";

			break;
		case 4: //cout << "file name?"; cin >> file_name;
			int nom; cout << "nom?"; cin >> nom;
			k = del_file(file_name, nom);
			if (k < 0)cout << "Can't read file";
			break;
		case 5:// cout << "file name?";
			//cin >> file_name;
			cout << "nom?"; cin >> nom;
			cout << "New Time:";
			//Time p1;
			cin >> p1;
			k = add_file(file_name, nom, p1);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = add_end(file_name, p1);
			break;
		case 6: //cout << "file name?";
			//cin >> file_name;
			cout << "nom?"; cin >> nom;
			cout << "New Time:";
			cin >> p2;
			k = change_file(file_name, nom, p2);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		case 7:
			cout << "znachenie" << endl; cin >> pp;
			k = del_file4(file_name, pp);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		case 8:
			cout << "skol'ko dobavit'" << endl; cin >> ppp;
			k = del_uvel90(file_name, ppp);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		case 9:
			cout << "������� ����� ����� �������� ��������"; cin >> nom;
			cout << "������� ���������� ����������� ���������"; cin >> tt;
			k = add_file4(file_name, nom, tt);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = add_end(file_name, p1);
			break;

		}
		system("cls");
	} while (c != 0);

}