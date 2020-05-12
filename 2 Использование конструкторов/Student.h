#include <iostream>
#include <string>

using namespace std;
class Student
{
	//атрибуты
	string FIO;
	string group;
	float ball;
public:
	Student();//конструктор без параметров
	Student(string, string,float);//конструктор с параметрами
	Student(const Student&); //конструктор копирования
	~Student();//деструктор
	string get_FIO();//селектор
	void set_FIO(string);//модификатор
	string get_group(); //селектор
	void set_group(string); //модификатор
	float get_ball();//селектор
	void set_ball(float);// модификатор
	void show(); //просмотр атрибутов
};