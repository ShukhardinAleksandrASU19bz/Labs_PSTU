#include "Fraction.h"

Fraction::Fraction(void) :Pair()
{
	ff = 0;
	ss = 0;
}
Fraction::~Fraction(void) {}
Fraction::Fraction(int F, int S) : Pair(F, S)
{
	ff = F;
	ss = S;
}
Fraction::Fraction(const Fraction& L)
{
	ff = L.ff;
	ss = L.ss;
}
void Fraction::Set_ff(int F)
{
	ff = F;
}
void Fraction::Set_ss(int S)
{
	ff = S;
}
Fraction& Fraction::operator=(const Fraction& l)
{
	if (&l == this) return *this;
	ff = l.ff;
	ss = l.ss;
	return *this;
}
//перегрузка операции сравнения
bool operator>(const Fraction& c1, const Fraction& c2)
{
	return ((c1.ff > c2.ff) || (c1.ff == c2.ff && c1.ss > c2.ss));
}
bool operator==(const Fraction& c1, const Fraction& c2)
{
	return (c1.ff == c2.ff && c1.ss == c2.ss);
}
bool operator<(const Fraction& c1, const Fraction& c2)
{
	return ((c1.first < c2.first) || (c1.first == c2.first && c1.second < c2.second));
}
bool operator!=(const Fraction& c1, const Fraction& c2)
{
	return (c1.ff != c2.ff || c1.ss != c2.ss);
}

istream& operator>>(istream& in, Fraction& l)
{
	cout << "\n Celiy"; in >> l.ff;
	cout << "\n drob"; in >> l.ss;
	return in;
}
ostream& operator<<(ostream& out, const Fraction& l)
{
	out << "\n Celiy:" << l.ff;
	out << "\n Drob:" << l.ss;
	out << "\n";
	return out;
}
void Fraction::Show()
{
	cout << "\n Celiy : " << ff;
	cout << "\n Drob : " << ss;
	cout << "\n";
}