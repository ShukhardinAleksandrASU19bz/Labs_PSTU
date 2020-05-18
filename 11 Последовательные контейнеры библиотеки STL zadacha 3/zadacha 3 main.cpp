#include "Time.h"
#include "Vector.h"
#include <iostream>
using namespace std;
void main()
{
	Vector<Time>vec(5);//создать вектор из 5 элементов
	vec.Print();//печать вектора
	Time s = vec.Maxi();
	vec.Add(s, 0);//добавить элемент в вектор
	vec.Print();//печать вектора

	int p = vec.Min();//найти максимальный элемент
	vec.Del(p);//удаление
	vec.Print();//печать

	s = vec.Srednee();//среднее ариметическое
	cout << "Srednee=" << s << endl;
	vec.dobavlenie(s);//деление
	vec.Print();
}