#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Vector
{
public:
	Vector(void);
	Vector(int);//конструктор с параметрами

public:
	~Vector(void);//деструктор
	void Add();//добавление элемента в вектор
	//void Add(Object& o);//добавление конкретного элемента в вектор
	void Del();
	void Show();
	void Show(int);
	void Snow(int);
	int operator()();//размер вектора
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};
