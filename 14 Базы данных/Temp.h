#pragma once
#include <iostream>//���������� ��� ������ �� ������������ ��������
#include <fstream> //���������� ��� ������ �� ��������� ��������
#include <string>

using namespace std;

class Temp
{
public:
	Temp() { temperatura = 0; atr = 0; }
	Temp(double m) { temperatura = m; atr = 0; }
	Temp(const Temp& t) { temperatura = t.temperatura; atr = t.atr; }
	~Temp() {};
	//������������� ��������
	Temp operator=(const Temp&);
	Temp operator/(const Temp&);
	Temp operator/(const int&);
	bool operator >(const Temp&);
	bool operator <(const Temp&);
	bool operator!=(const Temp);
	bool operator==(const Temp);
	Temp operator+(const Temp&);
	Temp operator+= (const Temp & t);

	//���������� ������� �����-������
	friend bool operator!= (const Temp&, const Temp&);
	friend bool operator== (const Temp&, const Temp&);
	friend bool operator<(const Temp&, const Temp&);
	friend istream& operator>>(istream& in, Temp& p);
	friend ostream& operator<<(ostream& out, const Temp& p);
	friend fstream& operator>>(fstream& fin, Temp& p);
	friend fstream& operator <<(fstream& fout, Temp& p);
	friend bool operator<(const Temp&, const Temp&);

public:
	double temperatura;
	int atr;
};