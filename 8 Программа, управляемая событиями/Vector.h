#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Vector
{
public:
	Vector(void);
	Vector(int);//����������� � �����������

public:
	~Vector(void);//����������
	void Add();//���������� �������� � ������
	//void Add(Object& o);//���������� ����������� �������� � ������
	void Del();
	void Show();
	void Show(int);
	void Snow(int);
	int operator()();//������ �������
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;//��������� �� ������ ������� �������
	int size;//������
	int cur;//������� �������
};
