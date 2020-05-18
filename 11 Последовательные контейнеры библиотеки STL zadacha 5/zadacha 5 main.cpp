#include "Time.h"
#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"

void main()
{
	Vector<Time>v(3);
	v.Print();
	Time t = v.Max();
	cout << "\nMax=" << t << endl;
	cout << "Add Max" << endl;
	v.Add(t,1);
	v.Print();

	cout << "min=" << v.Min() << endl;
	cout << "Delete min:" << endl;
	v.Del();
	v.Print();

	cout << "Dobavlenie srednego" << endl;
	cout << "Srednee=" << v.Srednee() << endl;
	v.dobavlenie();
	v.Print();
}