#include "Person.h"
#include <string>

//конструктор без параметров
Person::Person(void)
{
	name = "";
	age = 0;
}
//деструктор
Person::~Person(void)
{
}
//конструктор с параметрами
Person::Person(string M, int C)
{
	name = M;
	age = C;
}
//конструтор копирования
Person::Person(const Person& Person)
{
	name = Person.name;
	age = Person.age;
}
//модификаторы
void Person::Set_age(int C)
{
	age = C;
}
void Person::Set_name(string M)
{
	name = M;
}
//перегрузка операции присваивания
Person& Person::operator=(const Person& c)
{
	if (&c == this) return *this;
	name = c.name;
	age = c.age;
	return *this;
}
//метод для просмотра атрибутов
void Person::Show()
{
	cout << "\nname : " << name;
	cout << "\nage : " << age;
	cout << "\n";
}
//метод для ввода значений атрибутов
void Person::Input()
{
	cout << "\nname:"; cin >> name;
	cout << "\nage:"; cin >> age;
}
void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{ 
		switch (e.command)
		{
		case cmGet:cout << "name=" << Get_name() << endl;
			break;
		}
	}
}