#include <iostream>
#include <cmath>

using namespace std;

void InputInt(int* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}

class IntNumber
{
private:
	int number = 0;
public:
	void SetNumber()
	{
		cout << "Введите целое число: " << endl;
		InputInt(&number);
	}

	void operator--()
	{
		cout << "Ваше число: " << number << endl;
		number = sqrt(number);
		cout << "Из числа был взят корень приведён к целому числу!" << endl;
		cout << "Ваше изменённое число: " << number << endl;
	}

	friend void operator++(IntNumber tmp)
	{
		cout << "Ваше число: " << tmp.number << endl;
		tmp.number = pow(tmp.number, 3);
		cout << "Число было возведено в 3 степень!" << endl;
		cout << "Ваше изменённое число: " << tmp.number << endl;
	}
};

void main(void)
{
	setlocale(LC_ALL, "Russian");

	cout << "\n\t\t\tСоздадим представителя класса и применим к нему наши перегруженные операторы!\n\n" << endl;
	IntNumber tmp;
	tmp.SetNumber();
	IntNumber abc = tmp;
	cout << "\nПрименим операцию ++:" << endl << endl;
	--tmp;
	cout << "\nПрименим операцию --:\n" << endl;
	++abc;
}
