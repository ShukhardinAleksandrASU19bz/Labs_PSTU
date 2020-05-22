#include "Time.h"
#include "vector"
#include <iostream>
#include <algorithm> 
#include <stack>
#include <functional>

using namespace std;

typedef stack<Time> St;//стек
typedef vector<Time> Vec; //
typedef stack<Time, vector<Time>> TStack;

Time s, m;


Vec copy_stack_to_vector(TStack s)
{
	Vec v;
	while (!s.empty())//пока стек не пустой
	{
		//добавить в вектор элемент из вершиы стека
		v.push_back(s.top());
		s.pop();
	}
	return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
TStack copy_vector_to_stack(Vec v)
{
	TStack s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//добавить в стек элемент вектора
	}
	return s; //вернуть стек как результат функции
}
//формирование вектора
TStack make_stack(int n)
{
	Time a;
	TStack v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push(a);
	}
	return v;
}

void print_stack(TStack s)
{
	//копируем стек в вектор
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.top() << endl;//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)

		cout << v[i] << endl;
	cout << endl;
}

struct MAXI //максимальный
{
	bool operator()(Time t)
	{
		if (t == m) return true; else return false;
	}
};
struct Comp_less // для сортировки по убыванию

{
public:
	bool operator()(Time t1, Time t2)
	{
		if (t1 > t2)return true;
		else return false;
	}
};
struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};

void pluss(Time& t)
{
	t = t + s;
}

Time Srednee(TStack s)
{

	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	int n = 1;
	Time sum = s.top();//начальное значениедля суммы
	s.pop();//удалить первый элемент из вектора
	while (!s.empty())//пока стек не пустой
	{
		sum = sum + s.top();//добавить в сумму элемент из вершины стека
		s.pop();//удалить элемент
		n++;
	}
	s = copy_vector_to_stack(v);//скопировать вектор в стек
	return sum / n; //вернуть среднее арифметическое
}
Time Max(TStack s)
{
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	Vec::iterator i;
	//поставили итератор i на максимальный элемент
	i = max_element(v.begin(), v.end());
	m = *(i);
	s = copy_vector_to_stack(v);//копиуем вектор в стек
	return m; //возвращаем m
}
//поиск минимального элемента
Time Min(TStack s)
{
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	Vec::iterator i;
	//поставили итератор i на максимальный элемент
	i = min_element(v.begin(), v.end());
	m = *(i);
	s = copy_vector_to_stack(v);//копиуем вектор в стек
	return m; //возвращаем m
}
void replace_if_st_max(TStack& s,Time ss)
{
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	m = Max(s);
	replace_if(v.begin(), v.end(),MAXI(), ss);
	s = copy_vector_to_stack(v);//копиуем вектор в стек
}
void erase_stack(TStack& st, Time ss)
{
	Vec v = copy_stack_to_vector(st);//копируем стек в вектор
	Vec::iterator i;
	s = Min(st);
	i = remove_if(v.begin(), v.end(), Equal_s());
	//удалили элементы, начиная с i и до конца вектора
	v.erase(i, v.end());
	st = copy_vector_to_stack(v);//копиуем вектор в стек
}
void for_each_pluss(TStack& st)
{
	Vec v = copy_stack_to_vector(st);//копируем стек в вектор
	s = Srednee(st);
	for_each(v.begin(), v.end(), pluss);
	st = copy_vector_to_stack(v);//копиуем вектор в стек
}

void main()
{
	int n;
	cout << "N?";
	cin >> n;
	TStack v;
	v = make_stack(n);
	print_stack(v);

	s = Srednee(v);//нашли среднее арифметическое вектора
	cout << "sred=" << s << endl;
	cout << "max=" << Max(v) << endl;
	cout << "min=" << Min(v) << endl;
	replace_if_st_max(v,s);
	print_stack(v);

	cout << "UDALENIE" << endl;
	erase_stack(v, Min(v));
	print_stack(v);


	//для каждого элемента вектора вызывается функция pluss
	cout << "DOBAVLENIE" << endl;
	for_each_pluss(v);
	print_stack(v);
}