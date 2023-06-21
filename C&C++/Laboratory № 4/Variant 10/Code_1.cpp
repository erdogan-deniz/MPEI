#include <iostream>
#include <cmath>

using namespace std;

void InputDou(double*);

class DoubleNumber
{
private:
	double number = 0;
public:
	void SetNumber()
	{
		cout << "Введите число типа double: " << endl;
		InputDou(&number);
	}

	void operator--()
	{
		cout << "Ваше число: " << number << endl;
		number = sqrt(number);
		cout << "Из числа был взят корень!" << endl;
		cout << "Ваше изменённое число: " << number << endl;
	}

	friend void operator++(DoubleNumber tmp)
	{
		cout << "Ваше число: " << tmp.number << endl;
		tmp.number = pow(tmp.number, 3);
		cout << "Число было возведено в 3 степень!" << endl;
		cout << "Ваше изменённое число: " << tmp.number << endl;
	}
};
int main(void)
{
	setlocale(LC_ALL, "Russian");

	cout << "\n\t\t\tСоздадим представителя класса и применим к нему наши перегруженные операторы!\n\n" << endl;
	DoubleNumber tmp;
	tmp.SetNumber();
	DoubleNumber abc = tmp;
	cout << "\nПрименим операцию ++:" << endl << endl;
	--tmp;
	cout << "\nПрименим операцию --:\n" << endl;
	++abc;
	return 0;
}

void InputDou(double* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}
