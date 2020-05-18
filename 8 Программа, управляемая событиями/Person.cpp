#include "Person.h"
#include <string>

//����������� ��� ����������
Person::Person(void)
{
	name = "";
	age = 0;
}
//����������
Person::~Person(void)
{
}
//����������� � �����������
Person::Person(string M, int C)
{
	name = M;
	age = C;
}
//���������� �����������
Person::Person(const Person& Person)
{
	name = Person.name;
	age = Person.age;
}
//������������
void Person::Set_age(int C)
{
	age = C;
}
void Person::Set_name(string M)
{
	name = M;
}
//���������� �������� ������������
Person& Person::operator=(const Person& c)
{
	if (&c == this) return *this;
	name = c.name;
	age = c.age;
	return *this;
}
//����� ��� ��������� ���������
void Person::Show()
{
	cout << "\nname : " << name;
	cout << "\nage : " << age;
	cout << "\n";
}
//����� ��� ����� �������� ���������
void Person::Input()
{
	cout << "\nname:"; cin >> name;
	cout << "\nage:"; cin >> age;
}
void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//�������-���������
	{ 
		switch (e.command)
		{
		case cmGet:cout << "name=" << Get_name() << endl;
			break;
		}
	}
}