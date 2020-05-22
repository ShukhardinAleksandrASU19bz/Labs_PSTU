#include "Time.h"
#include "Container.h"
#include <iostream>
using namespace std;
void main()
{
	int n;
	cout << "N?"; cin >> n;
	Container<Time> v(n);
	v.Print();
	v.Dobavlenie();
	v.Print();
}