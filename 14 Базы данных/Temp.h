#pragma once
#include <iostream>//библиотека для работы со стандартными потоками
#include <fstream> //библиотека для работы со файловыми потоками
#include <string>

using namespace std;

class Temp
{
public:
	Temp() { temperatura = 0; atr = 0; }
	Temp(double m) { temperatura = m; atr = 0; }
	Temp(const Temp& t) { temperatura = t.temperatura; atr = t.atr; }
	~Temp() {};
	//перегруженные операции
	Temp operator=(const Temp&);
	Temp operator/(const Temp&);
	Temp operator/(const int&);
	bool operator >(const Temp&);
	bool operator <(const Temp&);
	bool operator!=(const Temp);
	bool operator==(const Temp);
	Temp operator+(const Temp&);
	Temp operator+= (const Temp & t);

	//глобальные функции ввода-вывода
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