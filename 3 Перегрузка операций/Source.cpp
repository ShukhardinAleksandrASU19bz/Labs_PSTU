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
	cout <<"увеличили а на 1: "<< a << endl;
	c=(a++)+b;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
	if (a == b) { cout << "a = b" << endl; }
	else cout << "a !=b" << endl;
	

}