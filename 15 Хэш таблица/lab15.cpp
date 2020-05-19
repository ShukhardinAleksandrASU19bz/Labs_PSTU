#include "Hash.h""
#include <vector>
#include <iostream>

using namespace std;
typedef vector<Person>Vec;//определяем тип для работы с вектором

Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)
	{
		Person a;
		v.push_back(a);//добавляем а в конец вектора
	}
	return v;//возвращаем вектор как результа работы функции
}

int main()
{
	Person per;
	int n;
	string str;
	cout << "N?"; cin >> n;
	vector<Person> v;
	v = make_vector(n);

	int max_size = 20;
	Hash* hash = new Hash(max_size);

	for(int i=0;i<v.size();i++)
	hash->insert(v[i]);
	hash->print(0);	
	cout << "enter key?"; cin >> per;
	n=hash->search(per);
	cout << "naideno: " << n << endl;
	n =hash->search_col();
	cout << "kollizii: " << n << endl;
	return 0;
}