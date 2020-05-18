#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<class T>
class Vector
{
	stack <T> s;//контейнер
	int len;//размер контейнера
public:
	Vector();//конструктор без параметров
	Vector(int n);//конструктор с параметрами
	Vector(const Vector<T>&);//конструктор копирования
	void Print();
	vector<T> copy_stack_to_vector(stack <T>);
	stack<T> copy_vector_to_stack(vector <T>);
	T Srednee();
	void dobavlenie();
	void Add(T el, int pos);
	T Max();
	void Del();
	T Min();
	void Delenie();

};

//копирование стека в вектор
template <class T>
vector<T> Vector<T>::copy_stack_to_vector(stack<T> s)
{
	vector<T> v;

	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
//копирование вектора в стек
template <class T>
stack<T> Vector<T>::copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}


//конструктор без параметров
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//добавить в стек элемент а
	}
	len = s.size();
}
//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	//копируем значения стека Vec.s в вектор v
	vector v = copy_stack_to_vector(Vec.s);
	//копируем вектор v в стек s
	s = copy_vector_to_stack(v);
}
//печать
template <class T>
void Vector<T>::Print()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.top() << endl;//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}
//среднее арифметическое
template <class T>
T Vector<T>::Srednee()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	int n = 1;//количество элементов в стеке
	T sum = s.top();//начальное значение для суммы
	s.pop();//удаляем элемент из вершины стека
	while (!s.empty())//пока стек не пустой
	{
		sum = sum + s.top();//добавляем в сумму элемент из вершины стека
		s.pop();//удаляем элемент из вершины стека
		n++;//увеличиваем количество элементов
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
	return sum / n;
}
//добавление элемента el в стек на позицию pos
template <class T>
void Vector<T>::Add(T el, int pos)
{
	vector <T>v;//вспомогательный вектор
	T t;
	int i = 1;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины стека
		//если номер элемента равен pos добавляем в вектор новый элемент
		if (i == pos)v.push_back(el);
		v.push_back(t);//добавляем t в вектор
		s.pop();//удаляем элемент из вершины стека
		i++;
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}
//поиск максимального элемента
template <class T>
T Vector<T>::Max()
{
	T m = s.top();//m присвоить значение из вершины стека
	//в вектор скопировать элементы стека
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		//сравниваем m и элемент в вершине стека
		if (s.top() > m)m = s.top();
		s.pop();//удаляем элемент из вершины стека
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
	return m;
}
//удаление элемента из вектора
template <class T>
void Vector<T>::Del()
{
	T m = Min();//поиск максимального
	vector<T> v;
	T t;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины стека
		//если t не равен максимальному, то добавить его в вектор
		if (t != m)v.push_back(t);
		s.pop();//удалить элемент из стека
	}
	//копируем вектор в стек

	s = copy_vector_to_stack(v);
}
//поиск минимального элемента
template <class T>
T Vector<T>::Min()
{
	T m = s.top();
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
//деление всех элементов на минимальный
template <class T>
void Vector<T>::Delenie()
{
	T m = Min();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		v.push_back(t / m);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
template <class T>
void Vector<T>::dobavlenie()
{
	T m = Srednee();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		v.push_back(t + m);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}