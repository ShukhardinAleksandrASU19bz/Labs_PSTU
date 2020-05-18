#include "Temp.h"

using namespace std;

//���������� �������� ������������
Temp Temp::operator=(const Temp& t)
{
	//�������� �� ����������������
	if (&t == this) return *this;
	temperatura = t.temperatura;
	return *this;
}


ostream& operator<<(ostream& out, const Temp& p)
{
	out << "�����������: " << p.temperatura << endl;
	return out;
}

istream& operator>>(istream& in, Temp& p)
{
	cout << "�����������?"; in >> p.temperatura;
	//Temp pp; p = p + pp;
	return in;
}
//������������� ������� ��� ������ � ��������� ��������
fstream& operator>>(fstream& fin, Temp& p)
{
	fin >> p.temperatura;
	fin >> p.atr;
	return fin;
}

fstream& operator<<(fstream& fout, Temp& p)
{
	fout << p.temperatura << endl;
	fout << p.atr << endl;
	return fout;
}


bool operator!=(const Temp& t1, const Temp& t2)
{
	return (t1.temperatura != t2.temperatura);
}
bool operator==(const Temp& t1, const Temp& t2)
{
	return (t1.temperatura == t2.temperatura);
}Temp Temp::operator+(const Temp& t)
{
	Temp p;
	p.temperatura = (temperatura + t.temperatura);
	return p;
}
//���������� �������� �������� �������
Temp Temp::operator/(const Temp& t)
{
	Temp p;
	p.temperatura = (temperatura / t.temperatura);
	return p;
}
Temp Temp::operator/(const int& t)
{
	Temp p;
	p.temperatura = (temperatura / t);
	return p;
}
Temp Temp::operator+=(const Temp& t)
{
	temperatura = (temperatura + t.temperatura);
	return *this;
}
bool Temp::operator <(const Temp& t)
{

	if (temperatura < t.temperatura)return true;
	return false;
}
bool Temp::operator >(const Temp& t)
{
	if (temperatura > t.temperatura)return true;
	return false;
}
bool Temp::operator!=(const Temp c1)
{
	return (temperatura != c1.temperatura);
}
bool Temp::operator==(const Temp c1)
{
	return (temperatura == c1.temperatura);
}