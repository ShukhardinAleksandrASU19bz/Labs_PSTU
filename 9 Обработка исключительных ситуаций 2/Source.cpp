#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;

// Информация об исключительных ситуациях передается с помощью пользовательского класса.

int main()
{
	try
	{
		Vector x(2);
		Vector y;
		Vector z(10);
		cout << z;
		cin >> z;
		z = z - 2;
		z = z + 5;
		z[1] = 666;
		cout << z;
		cout << x;
		cout << "Nomer?";
		int i;
		cin >> i;
		cout << x[i] << endl;
		y = x + 3;
		cout << y;
		--x;
		cout << x;
		--x;
		cout << x;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}