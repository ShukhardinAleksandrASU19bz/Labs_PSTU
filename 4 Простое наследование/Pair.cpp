#include "Pair.h"
//конструктор без параметров
Pair::Pair(void)
{
	first = 0;
	second = 0;
}
//деструктор
Pair::~Pair(void)
{
}
//конструктор с параметрами
Pair::Pair(int F, int S)
{

	first = F;
	second = S;
}
//конструтор копирования
Pair::Pair(const Pair& Pair)
{
	first = Pair.first;
	second = Pair.second;
}
//модификаторы
void Pair::Set_first(int F)
{
	first = F;
}
void Pair::Set_second(int S)
{
	second = S;
}
//перегрузка операции присваивания
Pair& Pair::operator=(const Pair& c)
{
	if (&c == this) return *this;
	second = c.second;
	first = c.first;
	return *this;
}
//перегрузка операции сравнения
bool operator>(const Pair& c1,const Pair& c2)
{
	return ((c1.first > c2.first) || (c1.first == c2.first && c1.second > c2.second));
}
//глобальная функция для ввода
istream& operator>>(istream& in, Pair& c)
{
	cout << "\n first:"; in >> c.first;
	cout << "\n second:"; in >> c.second;
	return in;
}
//глобальная функция для вывода
ostream& operator<<(ostream& out, const Pair& c)
{
	out << "\n first:" << c.first;
	out << "\n second:" << c.second;
	out << "\n";
	return out;
}
