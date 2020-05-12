#include <iostream>
#include "Pair.h"
#include "Fraction.h"

using namespace std;

void f3(Pair& c)
{
	c.Set_first(666);
	cout << c;
}
Pair f4()
{
	Fraction K(999,999);
	return K;
}


int main()
{
	//работа с классом Pair
	Pair p;
	cin>> p;
	cout << p;
	Pair p1(1, 2);
	cout << p1;
	cout << p;
	if (p > p1) cout << "p>p1"; else cout << "p1>p";
	//работа с классом Fraction
	Fraction p2;
	cin >> p2;
	cout << p2;
	//принцип подстановки
	f3(p2);
	p = f4();
	cout << p;
	return 666;
}