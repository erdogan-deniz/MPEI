#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void InputDOU(double* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}

class RealNumber
{
private:
	double number = 0;
public:
	void SetNumber() 
	{
		cout << "Input a number: " << endl;
		InputDOU(&number);
	}

	void operator++()
	{
		cout << "Your number: " << number << endl;
		++number;
		cout << "The number was decremented!" << endl;
		cout << "New number is: " << number << endl;
	}

	friend void operator--(RealNumber tmp)
	{
		cout << "Your number is: " << tmp.number << endl;
		--tmp.number;
		cout << "The number was incremented!" << endl;
		cout << "New number is: " << tmp.number << endl;
	}
};

void main(void)
{
	setlocale(LC_ALL, "Russian");

	cout << "Первый пункт задания - работа с перегрузками операторов, результат:" << endl;
	RealNumber zxc;
	zxc.SetNumber();
	cout << "We create a new delegate, use ++:" << endl << endl;
	++zxc;
	cout << "Let's use -- :" << endl;
	--zxc;
}
