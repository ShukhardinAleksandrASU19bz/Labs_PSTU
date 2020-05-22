#include "HashTable.h""
#include <vector>
#include <iostream>

using namespace std;
typedef vector<Person>Vec;
Vec make_vector(int n)
{
	Vec v;
	for (int i = 0; i < n; i++)
	{
		Person a;
		v.push_back(a);
	}
	return v;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Person per;
	int n;
	string str;
	cout << "N?"; cin >> n;
	vector<Person> v;
	v = make_vector(n);
	int max_size;
	cout << "размер таблицы?"; cin >> max_size;
	Hash* HS = new Hash(max_size);
	for (int i = 0; i < v.size(); i++)
		HS->insert(v[i]);
	HS->print(0);

	int c;
	do
	{ //Меню
		cout << "\n1. Поиск";
		cout << "\n2. Удаление по ключу";
		cout << "\n3. Изменение по номеру";
		cout << "\n4. Изменение по ключу";
		cout << "\n5. Печать хэш таблицы";
		cout << "\n6. Количесвто коллизий";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "enter key?"; cin >> per;
			n = HS->search(per);
			cout << "naideno: " << n << endl;
			break;
		case 2:
			cout << "enter key?"; cin >> per;
			HS->deletk(per);
			break;
		case 3:
			cout << "введите номер изменяемой: " << endl;
			cin >> n;
			HS->changeN(n);
			break;
		case 4:
			cout << "введите значение изменяемой: " << endl;
			cin >> per;
			HS->changeK(per);
			break;
		case 5:
			HS->print(0);
			break;
		case 6:
			n = HS->search_col();
			cout << "kollizii: " << n << endl;
			break;
		}
	} while (c != 0);
	HS->~Hash();
	return 0;
}