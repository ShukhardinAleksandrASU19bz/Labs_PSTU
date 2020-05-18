#pragma once
#include <iostream>//библиотека для работы со стандартными потоками
#include <fstream> //библиотека для работы со файловыми потоками
#include <string>

using namespace std;

class Time
{
public:
	Time() { min = 0; sec = 0; };
	Time(int m, int s) { min = m; sec = s; }
	Time(const Time& t) { min = t.min; sec = t.sec; }
	~Time() {};
	//int get_min() { return min; }
	//int get_sec() { return sec; }
	//void set_min(int m) { min = m; }
	//void set_sec(int s) { sec = s; }
	//перегруженные операции
	Time operator=(const Time&);
	//Time& operator++();
	//Time operator++(int);//постфиксная операция
	//Time operator+(const Time&);
	//глобальные функции ввода-вывода
	friend bool operator!= (const Time& t1, const Time& t2);
	friend bool operator== (const Time& t1, const Time& t2);
	friend istream& operator>>(istream& in, Time& p);
	friend ostream& operator<<(ostream& out, const Time& p);
	friend fstream& operator>>(fstream& fin, Time& p);
	friend fstream& operator <<(fstream& fout, const Time& p);
	Time operator+(const Time&);
private:
	int min, sec;
};