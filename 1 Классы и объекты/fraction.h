struct fraction
{
	double first;
	int second, ipart;
	void Init(int, int); //метод для инициализации полей
	void Read(); //метод для чтения значений полей
	void Show(); //метод для вывода значений полей
	double Power(); //вычисление степени
	int Ipart(); //выделение целой части дроби
};
