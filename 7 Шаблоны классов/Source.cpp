#include "Vector.h" 
#include <iostream>
#include "Time.h"

using namespace std; 
void main() 
{
	// тестирование класса Time
	Time t;
	cin >> t; 
	cout << t;
	Vector<Time>A(5, t);
	cin >> A;
	cout << A << endl;
	Vector <Time>B(10, t);
	cout << B << endl;
	B = A;
	cout << B << endl; 
	cout << A[2] << endl;
	cout << "size=" << A() << endl;
	B = A + t; 
	cout << B << endl;

} 