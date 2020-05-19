#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Person.h"

using namespace std;

class Spisok
{
	friend class Hash;
	Spisok* next;
	Person per;

public:
	Spisok() {    };
	Spisok(Person d, Spisok* n)
	{
			per = d;
			next = n;
	}
	~Spisok(){    }
};

class Hash
{
public:
	//vector<string> fame;
	//vector<string> names;
	//vector<string> otch;
	//string group;
	//int per;
// функция создания хеш-таблицы метод деления по модулю
	//int Hash(int Key, int HashSize) {
	//	return Key % HashSize;}
	int max_size = 20;
	int size = max_size;
	vector<Spisok*>* Spisoks;
	Hash(int tableSize)
	{
		size = tableSize;
		Spisoks = new vector<Spisok*>(size);
	}
	~Hash(){}

	void print(int start)
	{
		for (int i = start; i < (Spisoks->size()); i++) {
			cout << i+1 << "\t";
			Spisok* p = Spisoks->at(i);
			while (p != NULL) {
				cout << p->per << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

	void insert(Person per)
	{
		int index = getHash(per);
		if (Spisoks->at(index) == NULL)
		{
			Spisoks->at(index) = new Spisok(per, NULL);
			return;
		}
		Spisok* p = Spisoks->at(getHash(per));;
		while (p != NULL) {
			if (p->next == NULL)
			{
				p->next = new Spisok(per, NULL);
				break;
			}
			p = p->next;
		}
	}
	int search(Person per)
	{
		for (Spisok* pos = Spisoks->at(getHash(per)); pos; pos = pos->next)
		{
			if (pos->per.Get_name() == per.Get_name())
				return 1;
		}
		return 0;
	}

	int search_col()
	{
		int j=0, s=0;
		for (int i = 0; i < (Spisoks->size()); i++) {
			Spisok* p = Spisoks->at(i);
			j = 0;
			while (p != NULL) 
			{
				p = p->next;
				j++;
			}
			if (j >= 2) s = s + j - 1;
		}
		return s;
	}
	
	int getSize()
	{
		return size;
	}
	int getHash(Person per)
	{
		int key =per.Get_asci();

		return abs(key % getSize());
	}

};
