#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Time a;
	Time b;
	Time c;
	cin >> a;
	cin >> b;
	++a;
	cout << a << endl;
	c=(a++)+b;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
	if (a == b) { cout << "равно" << endl; }
	else cout << "не равно" << endl;
	

}