#include "Temp.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	hran s;
	Temp p, p1, p2, pp, ppp;
	int k, c;
	char file_name[30];

	
	do
	{
		cout << "\n1. ������� ����";
		cout << "\n2. ������� ����";
		//cout << "\n0. �����";
		cout<< endl;
		cin >> c;
		switch (c)
		{
		case 1: cout << "file name?"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Can't make file";
			k = file_read(file_name, s);
			break;
		case 2: cout << "file name?"; cin >> file_name;
			k = file_read(file_name,s);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "Can't read file\n";

			break;
		}
	} while (k < 0);
	system("cls");
	do
	{ //����
		cout << "------------------------" << file_name << "------------------------" << endl;
		k = print_list(s);
		cout << "\n1. ������� ����";
		cout << "\n2. ������� ����";
		cout << "\n3. �������� ����";
		cout << "\n4. ������� ������ �� ����� �� ������";
		cout << "\n5. ������� ������ �� ����� �� �����";
		cout << "\n6. �������� ������ � ����";
		cout << "\n7. �������� ������ � ����� �� ������";
		cout << "\n8. �������� ������ � ����� �� �����";
		cout << "\n9. ���, ���� ��������";
		cout << "\n10. ����� ������� ������� + ����";
		cout << "\n11. ��������� ���������";
		cout << "\n12. �������� ��������� ��������";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "file name?"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Can't make file";
			k = file_read(file_name, s);
			break;
		case 2: cout << "file name?"; cin >> file_name;
			k = print_list(s);
			if (k == 0)cout << "Empty file\n";
			break;
		case 3:
			k = file_read(file_name,s);
			if (k == 0)cout << "Empty file\n";
			break;
		case 4: //
			k = file_zap("temp", s);
			int nom; cout << "����� ���������?"; cin >> nom;
			k = del_listK(s,nom);
			if (k == 0) cout << "\n��� ����� ��������";
			break;
		case 5: k = file_zap("temp", s);
			cout << "�������� ���������?"; cin >> nom;
			k = del_list(s, nom);
			break;
		case 6:
			k = file_zap("temp", s);
			cout << "����� �����������?"; cin >> nom;
			//Temp p1;
			cin >> p1;
			if (nom > s.size())
				k = add_list(s, p1);
			else {
				k = add_list(s, p1, nom);
			}
			if (k == 0) k = add_list(s, p1);
			break;
		case 7:
			k = file_zap("temp", s);
			cout << "����� ����������"; cin >> nom;
			k = change_listK(s, nom);
			if (k == 0) cout << "\nNot such record";
			break;
		case 8:
			k = file_zap("temp", s);
			cout << "�������� ����������" << endl; cin >> p;
			k = change_list(s, p);
			if (k == 0) cout << "\n��� ����� ��������" << endl;;
			break;
		case 9:
			k = file_read(file_name, s);
			k = dni_sr(s);
			if (k == 0) cout << "\n ��� ����� ����" << endl;
			break;
		case 10:
			k = file_read(file_name, s);
			k = otrezok(s);
			cout << "����� ������� ������� + ����: "<<k << endl;
			if (k == 0) cout << "\n ��� ����� ����" << endl;
			break;
		case 11:
			k = file_zap(file_name, s);
			if (k == 0) cout << "\n �� ������� �������� ������ � ����" << endl;
			break;
		case 12:
			k = file_read("temp", s);
			break;
		}
		//system("cls");
	} while (c != 0);
	
	return 0;
}