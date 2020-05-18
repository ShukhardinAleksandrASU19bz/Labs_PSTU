#include "Vector.h"
#include "Person.h"
#include "Student.h"
#include "dialog.h"

Vector::Vector(void)
{
	beg = new Object * [0];
	cur = 0;
	size = 0;
}
//деструктор
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//конструктор с параметрами
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор
void Vector::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов
	cout << "1.Person" << endl;
	cout << "2.Student" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса Person
	{
		Person* a = new (Person);
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Student
		{
			Student* b = new Student;
			b->Input();
			p = b;
			if (cur < size)

			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;

}
//просмотр вектора

void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект

	}
}
void Vector::Show(int j)
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 1; i < cur+1; i++)
	{
		if (i == j) (*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект

	}
}
void Vector::Snow(int j)
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 1; i < cur + 1; i++)
	{
		if (i == j) //(*p)->Show();//вызов метода Show
		p++;//передвигаем указатель на следующий объект

	}
}
//операция, которая возвращает размер вектора
int Vector::operator ()()
{
	return cur;
}
//удаление элемента из вектора, память не освобождается!
void Vector::Del()
{
	if (cur == 0) return;//пустой
	cur--;
}
void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			if (i == e.a)
			(*p)->HandleEvent(e);//вызов метода (позднее связывание)
			p++;//передвигаем указатель на следующий объект
		}
	}
}