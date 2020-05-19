#include "HashTable.h""
#include <vector>
#include <iostream>

using namespace std;
typedef vector<Person>Vec;
Vec make_vector(int n)
{
	Vec v;//?????? ??????
	for (int i = 0; i < n; i++)
	{
		Person a;
		v.push_back(a);
	}
	return v;
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
	Hash* HS = new Hash(max_size);
	for (int i = 0; i < v.size(); i++)
		HS->insert(v[i]);
	HS->print(0);
	cout << "enter key?"; cin >> per;
	n = HS->search(per);
	cout << "naideno: " << n << endl;
	n = HS->search_col();
	cout << "kollizii: " << n << endl;
	HS->~Hash();
	//cout << "enter key?"; cin >> per;
	//HS->deletk(per);
	//HS->print(0);
	//cout << "enter nom?"; cin >> n;
	//HS->deletN(n);
	HS->changeK(per);
	HS->print(0);
	cin >> n;
	HS->changeN(n);
	HS->print(0);
	return 0;
}