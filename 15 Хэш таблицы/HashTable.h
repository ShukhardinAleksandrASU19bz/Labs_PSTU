#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Person.h"
#include <algorithm>

using namespace std;

class Spisok
{
	friend class Hash;
	Spisok* next;
	Person per;

public:
	Spisok() {    }
	Spisok(Person d, Spisok* n)
	{
		per = d;
		next = n;
	}
	~Spisok() {    }
};

class Hash
{
public:
	int size;
	vector<Spisok*>* SP;


	//конструктор таблицы
	Hash(int max_size)
	{
		size = max_size;
		SP = new vector<Spisok*>(size);
	}
	~Hash() {}

	//печать хэш таблицы
	void print(int start)
	{
		for (int i = start; i < (SP->size()); i++) {
			cout << i << "\t";
			Spisok* p = SP->at(i);
			while (p != NULL) {
				cout << p->per << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

	// вставка элемента в хэш таблицу
	void insert(Person per)
	{
		int index = getHash(per);
		if (SP->at(index) == NULL)
		{
			SP->at(index) = new Spisok(per, NULL);
			return;
		}
		Spisok* p = SP->at(getHash(per));;
		while (p != NULL) {
			if (p->next == NULL)
			{
				p->next = new Spisok(per, NULL);
				break;
			}
			p = p->next;
		}
	}

	// поиск по таблице
	int search(Person per)
	{
		for (Spisok* pos = SP->at(getHash(per)); pos; pos = pos->next)
		{
			if (pos->per.Get_name() == per.Get_name())
				return 1;
		}
		return 0;
	}

	// подсчет количества коллизий
	int search_col()
	{
		int j = 0, s = 0;
		for (int i = 0; i < (SP->size()); i++) {
			Spisok* p = SP->at(i);
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
	void deletk(Person per)
	{
		Spisok* temp;
		for (Spisok* pos = SP->at(getHash(per)); pos; pos = pos->next)
		{
			if ((pos->per.Get_name() == per.Get_name()) && (pos->next != NULL))
			{
				if (pos == SP->at(getHash(per)))
				{//удаляем первый элемент
					SP->at(getHash(per)) = pos->next;
					delete(pos);
					pos = SP->at(getHash(per));
				}
				else {
					temp = SP->at(getHash(per));
					while (temp->next != pos)
						temp = temp->next;
					temp->next = pos->next;
					delete(pos);
					pos = temp;
				}
			}

		}
	}
	//изменить по ключу из таблицы
	void changeK(Person per)
	{
		Person temp2;
		for (Spisok* pos = SP->at(getHash(per)); pos; pos = pos->next)
		{
			if ((pos->per.Get_name() == per.Get_name()))
			{
				pos->per.Set_name();
				pos->per.Set_group();
				pos->per.Set_raiting();
			}
		}
	}
	//изменить по номеру из таблицы
	void changeN(int n)
	{
		Person temp2;
		for (int i = 0; i < (SP->size()); i++) {

			if (i == n)
			{
				Spisok* p = SP->at(i);
				while (p != NULL)
				{
					p->per.Set_name();
					p->per.Set_group();
					p->per.Set_raiting();
					p = p->next;
				}
			}
		}
	}

	// размер таблицы
	int getSize()
	{
		return size;
	}

	// хэш функция
	int getHash(Person per)
	{
		int key = per.Get_asci();

		return (key % getSize());
	}

};
