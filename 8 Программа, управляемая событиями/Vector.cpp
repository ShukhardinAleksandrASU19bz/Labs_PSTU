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
//����������
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//����������� � �����������
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//���������� �������, �� ������� ��������� ��������� p � ������
void Vector::Add()
{
	Object* p;
	//����� �� �������� ���� ��������� �������
	cout << "1.Person" << endl;
	cout << "2.Student" << endl;
	int y;
	cin >> y;
	if (y == 1)//���������� ������� ������ Person
	{
		Person* a = new (Person);
		a->Input();//���� �������� ���������
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//���������� � ������
			cur++;
		}
	}
	else
		if (y == 2) //���������� ������� ������ Student
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
//�������� �������

void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//��������� �� ��������� ���� Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������

	}
}
void Vector::Show(int j)
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//��������� �� ��������� ���� Object
	for (int i = 1; i < cur+1; i++)
	{
		if (i == j) (*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������

	}
}
void Vector::Snow(int j)
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//��������� �� ��������� ���� Object
	for (int i = 1; i < cur + 1; i++)
	{
		if (i == j) //(*p)->Show();//����� ������ Show
		p++;//����������� ��������� �� ��������� ������

	}
}
//��������, ������� ���������� ������ �������
int Vector::operator ()()
{
	return cur;
}
//�������� �������� �� �������, ������ �� �������������!
void Vector::Del()
{
	if (cur == 0) return;//������
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
			(*p)->HandleEvent(e);//����� ������ (������� ����������)
			p++;//����������� ��������� �� ��������� ������
		}
	}
}