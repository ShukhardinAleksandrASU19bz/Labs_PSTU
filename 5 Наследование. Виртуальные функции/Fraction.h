#pragma once
#include "Pair.h"
class Fraction :
	public Pair
{
public:
	Fraction(void); // ����������� ��� ����������
public:
	~Fraction(void); //����������
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������
	Fraction(int, int);//����������� � �����������
	Fraction(const Fraction&);// ���������� �����������
	int Get_ff() { return ff; }//��������
	int Get_ss() { return ss; }//��������
	void Set_ss(int);//�����������
	void Set_ff(int);//�����������
	Fraction& operator=(const Fraction&); //�������� ������������
	friend bool operator>(const Fraction& c1, const Fraction& c2);
	friend bool operator==(const Fraction& c1, const Fraction& c2);
	friend bool operator<(const Fraction& c1, const Fraction& c2);
	friend bool operator!=(const Fraction& c1, const Fraction& c2);
	friend istream& operator>>(istream& in, Fraction& l);// �������� �����
	friend ostream& operator<<(ostream& out, const Fraction& l);//�������� ������
protected:
	int ff;
	int ss;
};

