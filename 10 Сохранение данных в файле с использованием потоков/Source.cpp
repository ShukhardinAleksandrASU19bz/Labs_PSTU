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
	//cout << "Введите имя файла: " << endl;
	//cin >> file_name;

	do
	{
	cout << "\n1. Создать файл";
	cout << "\n2. Открыть файл" << endl;
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
	{ //Меню
		cout<<"------------------------" << file_name << "------------------------" << endl;
		k = print_file(file_name);
		cout << "\n1. Создать файл";
		cout << "\n2. Открыть файл";
		cout << "\n3. Печатать файл";
		cout << "\n4. Удалить запись из файла";
		cout << "\n5. Добавить запись в файл";
		cout << "\n6. Изменить запись в файле";
		cout << "\n7. Удалить все записи равные ";
		cout << "\n8. Увеличить все значения на ";
		cout << "\n9. Добавить К элементов после ";
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
			cout << "Введите номер после которого вставить"; cin >> nom;
			cout << "Введите количесвто вставляемых элементов"; cin >> tt;
			k = add_file4(file_name, nom, tt);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = add_end(file_name, p1);
			break;

		}
		system("cls");
	} while (c != 0);

}