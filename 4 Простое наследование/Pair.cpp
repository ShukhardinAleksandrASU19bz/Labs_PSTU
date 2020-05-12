#include "Pair.h"
//����������� ��� ����������
Pair::Pair(void)
{
	first = 0;
	second = 0;
}
//����������
Pair::~Pair(void)
{
}
//����������� � �����������
Pair::Pair(int F, int S)
{

	first = F;
	second = S;
}
//���������� �����������
Pair::Pair(const Pair& Pair)
{
	first = Pair.first;
	second = Pair.second;
}
//������������
void Pair::Set_first(int F)
{
	first = F;
}
void Pair::Set_second(int S)
{
	second = S;
}
//���������� �������� ������������
Pair& Pair::operator=(const Pair& c)
{
	if (&c == this) return *this;
	second = c.second;
	first = c.first;
	return *this;
}
//���������� �������� ���������
bool operator>(const Pair& c1,const Pair& c2)
{
	return ((c1.first > c2.first) || (c1.first == c2.first && c1.second > c2.second));
}
//���������� ������� ��� �����
istream& operator>>(istream& in, Pair& c)
{
	cout << "\n first:"; in >> c.first;
	cout << "\n second:"; in >> c.second;
	return in;
}
//���������� ������� ��� ������
ostream& operator<<(ostream& out, const Pair& c)
{
	out << "\n first:" << c.first;
	out << "\n second:" << c.second;
	out << "\n";
	return out;
}
