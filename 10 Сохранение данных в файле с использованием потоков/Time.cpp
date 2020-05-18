#include "Time.h"

//перегрузка операции присваивания
Time Time::operator=(const Time& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}


ostream& operator<<(ostream& out, const Time& p)
{
	out << "min: " << p.min << endl << "sec:" << p.sec << endl;
	return out;
}
istream& operator>>(istream& in, Time& p)
{
	cout << "min?"; in >> p.min;

	cout << "sec?";  in >> p.sec;
	Time pp; p = p + pp;
	return in;
}
//дружественные функции для работы с файловыми потоками
fstream& operator>>(fstream& fin, Time& p)
{
	fin >> p.min;
	fin >> p.sec;
	return fin;
}
fstream& operator<<(fstream& fout, const Time& p)
{
	fout << p.min << endl; fout << p.sec << endl;
	return fout;
}
bool operator!=(const Time& t1, const Time& t2)
{
	int temp1 = t1.min * 60 + t1.sec;
	int temp2 = t2.min * 60 + t2.sec;
	return (temp1!=temp2 );
}
bool operator==(const Time& t1, const Time& t2)
{
	return (t1.min == t2.min && t1.sec == t2.sec);
}Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}