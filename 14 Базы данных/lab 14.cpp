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
		cout << "\n1. Создать файл";
		cout << "\n2. Открыть файл";
		//cout << "\n0. Выход";
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
	{ //Меню
		cout << "------------------------" << file_name << "------------------------" << endl;
		k = print_list(s);
		cout << "\n1. Создать файл";
		cout << "\n2. Открыть файл";
		cout << "\n3. Печатать файл";
		cout << "\n4. Удалить запись из файла по номеру";
		cout << "\n5. Удалить запись из файла по ключу";
		cout << "\n6. Добавить запись в файл";
		cout << "\n7. Изменить запись в файле по номеру";
		cout << "\n8. Изменить запись в файле по ключу";
		cout << "\n9. Дни, выше среднего";
		cout << "\n10. Самый большой отрезок + дней";
		cout << "\n11. Сохранить изменения";
		cout << "\n12. Отменить последнее действие";
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
			int nom; cout << "Номер удаляемой?"; cin >> nom;
			k = del_listK(s,nom);
			if (k == 0) cout << "\nнет таких значений";
			break;
		case 5: k = file_zap("temp", s);
			cout << "Значение удаляемой?"; cin >> nom;
			k = del_list(s, nom);
			break;
		case 6:
			k = file_zap("temp", s);
			cout << "Номер добавляемой?"; cin >> nom;
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
			cout << "Номер изменяемой"; cin >> nom;
			k = change_listK(s, nom);
			if (k == 0) cout << "\nNot such record";
			break;
		case 8:
			k = file_zap("temp", s);
			cout << "Значение изменяемой" << endl; cin >> p;
			k = change_list(s, p);
			if (k == 0) cout << "\nнет таких значений" << endl;;
			break;
		case 9:
			k = file_read(file_name, s);
			k = dni_sr(s);
			if (k == 0) cout << "\n нет таких дней" << endl;
			break;
		case 10:
			k = file_read(file_name, s);
			k = otrezok(s);
			cout << "Самый большой отрезок + дней: "<<k << endl;
			if (k == 0) cout << "\n нет таких дней" << endl;
			break;
		case 11:
			k = file_zap(file_name, s);
			if (k == 0) cout << "\n не удалось записать данные в файл" << endl;
			break;
		case 12:
			k = file_read("temp", s);
			break;
		}
		//system("cls");
	} while (c != 0);
	
	return 0;
}