#include <iostream>
#include <cmath>

using namespace std;

void InputFloat(float*);

class FloatNumber
{
private:
	float number = 0;
public:
	void SetNumber()
	{
		cout << "Введите целое число: " << endl;
		InputFloat(&number);
	}

	void operator-()
	{
		cout << "Использована команда - :" << endl;
		number = pow(number, number);
		cout << number << endl;
		cout << "Число было возведено в степень равную самому числу." << number << endl;
	}

	friend void operator++(FloatNumber tmp);
};

void main(void)
{
	setlocale(LC_ALL, "Russian");

	cout << "\n\t\t\tСоздадим представителя класса и применим к нему наши перегруженные операторы!\n\n" << endl;
	FloatNumber tmp;
	tmp.SetNumber();
	FloatNumber abc = tmp;
	cout << "\nПрименим операцию +:" << endl << endl;
	-tmp;
	cout << "\nПрименим операцию -:\n" << endl;
	++abc;
}

void operator++(FloatNumber tmp)
{
	cout << "Использована команда + :" << tmp.number << endl;
	tmp.number = exp(tmp.number);
	cout << tmp.number << endl;
	cout << "Была взята экспонента от числа. " << endl;
}

void InputFloat(float* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}
