#include "Person.h"
#include <string>

 
//����������� ��� ����������
Person::Person(void)
{
	for (int i = 0; i < rand() % 10; i++)
	name += rand() % 10 + 's';
	for (int i = 0; i < rand() % 10; i++)
	group += rand() % 10 + 's';
	raiting = raiting = rand() % 100;
	/*for (int i = 0; i < n; i++)
{
	FIO = ; group = rand() % 10 + '0'; raiting = rand() % 100; next = s;
}
*/
}
//����������
Person::~Person(void)
{
}
//����������� � �����������
Person::Person(string M, string g, int C)
{
	name = M;
	raiting = C;
	group = g;
}
//���������� �����������
Person::Person(const Person& Person)
{
	name = Person.name;
	raiting = Person.raiting;
}
//������������
void Person::Set_raiting(int C)
{
	raiting = C;
}
void Person::Set_name(string M)
{
	name = M;
}
void Person::Set_group(string M)
{
	group = M;
}
//���������� �������� ������������
Person& Person::operator=(const Person& c)
{
	if (&c == this) return *this;
	name = c.name;
	raiting = c.raiting;
	return *this;
}
//����� ��� ��������� ���������
void Person::Show()
{
	cout << "\nname : " << name;
	cout << "\nraiting : " << raiting;
	cout << "\n";
}
//����� ��� ����� �������� ���������
void Person::Input()
{
	cout << "\nname:"; cin >> name;
	cout << "\nraiting:"; cin >> raiting;
}
//���������� ���������� ������� - �������� �����
istream& operator>>(istream& in, Person& t)
{
	cout << "name?"; in >> t.name;
	//cout << "group?"; in >> t.group;
	//cout << "raiting?"; in >> t.raiting;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Person& t)
{
	return (out << t.name << " " << t.group <<" " << t.raiting << " ");
}
