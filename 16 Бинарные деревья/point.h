#pragma once
#include <iostream>
#include <cstring>

using namespace std;
int j = 0;
struct point
{
	char* data;//информационное поле
	point* left;//адрес левого поддерева
	point* right;//адрес правого поддерева
};

point* Tree(int n, point* p)
{
	point* r;
	int nl, nr;
	if (n == 0) { p = NULL; return p; }
	nl = n / 2;
	nr = n - nl - 1;
	r = new point;
	char s[50];
	cout << "Значение: ";
	cin >> s;
	r->data = new char[strlen(s) + 1];
	strcpy_s(r->data, strlen(s) + 1, s);
	r->left = Tree(nl, r->left);
	r->right = Tree(nr, r->right);
	p = r;
	return p;
}
//поиск в дереве поиска
void tree_poisk(point* p, char* a)
{
	if (p != NULL)
	{
		if (p->data == a)
		{
			cout << "Элемент найден" << endl;
			return;
		}
		else if (a < p->data)
		{
			tree_poisk(p->left, a);
		}
		else if (a > p->data)
		{
			tree_poisk(p->right, a);
		}

	}
	else
	{
		cout << "net elementa" << endl;
	}
}
// поиск в сбалансированном дереве
int poisk_balance(point* p, char* a)
{
	if (p != NULL)
	{
		if (*(p->data) == *a)
		{
			j++;
		}
		j = poisk_balance(p->left, a);
		j = poisk_balance(p->right, a);
	}

	return j;
}

void add_poisk(point*& pp, char* k)
{
	if (pp == NULL)
	{
		pp = new point;
		pp->data = k;
		pp->left = pp->right = NULL;
		return;
	}
	if (*k <= *(pp->data))
	{
		if (pp->left != NULL) add_poisk(pp->left, k);
		else
		{
			pp->left = new point;
			pp->left->left = pp->left->right = NULL;
			pp->left->data = k;
		}

	}
	if (*k > * (pp->data))
	{
		if (pp->right != NULL) add_poisk(pp->right, k);
		else
		{
			pp->right = new point;
			pp->right->right = pp->right->left = NULL;
			pp->right->data = k;
		}
	}
}

//обход дерева
point* preobrazovanie(point* p, point*& pp)
{
	if (p != NULL)
	{
		add_poisk(pp, p->data);
		preobrazovanie(p->left, pp);
		preobrazovanie(p->right, pp);
	}
	return pp;
}

void Treeprint2(point* p, int level)
{
	if (p == NULL)
	{
		for (int i = 0; i < level; ++i)
			cout << "   ";
		cout << '-' << endl;
		return;
	}
	Treeprint2(p->right, level + 1);
	for (int i = 0; i < level; i++)
		cout << "   ";
	cout << p->data << endl;
	Treeprint2(p->left, level + 1);

}
void udalenie(point* p)
{
	if (p != NULL)
	{
		udalenie(p->left);
		udalenie(p->right);
		delete p;
		p = NULL;
	}

}
