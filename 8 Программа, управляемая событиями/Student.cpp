#include "Student.h"
#include "Vector.h"

Student::Student(void) :Person()
{
	rating = 0;
}
Student::~Student(void)

{
}
Student::Student(string M, int C, float G) :Person(M, C)
{
	rating = G;
}
Student::Student(const Student& L)
{
	name = L.name;
	age = L.age;
	rating = L.rating;
}
void Student::Set_rating(float G)
{
	rating = G;
}
Student& Student::operator=(const Student& l)
{
	if (&l == this)return *this;
	name = l.name;
	age = l.age;
	return *this;
}
void Student::Show()
{
	cout << "\nname : " << name;
	cout << "\nage : " << age;
	cout << "\nrating : " << rating;
	cout << "\n";
}
void Student::Input()
{
	cout << "\nname:"; cin >> name;
	cout << "\nage:"; cin >> age;
	cout << "\nrating : "; cin >> rating;
}
void Student::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)  //событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << "name=" << Get_name() << endl;
			break;
		}
	}
}