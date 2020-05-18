#pragma once
#include "Person.h"
#include "Vector.h"

using namespace std;

class Student :
	public Person
{
public:
	Student(void);
public:
	~Student(void);
	void Show();
	void Input();
	Student(string, int,float);
	Student(const Student&);
	float Get_rating() { return rating; }
	void Set_rating(float);
	Student& operator=(const Student&);
	void HandleEvent(const TEvent& e);
protected:
	float rating;
};