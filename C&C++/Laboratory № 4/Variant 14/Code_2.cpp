#define SIZE 25  // Размер статических массивов

#include <iostream>
#include <cmath>

using namespace std;

void InputINT(int*);
void InputDOU(double*);
void InputFLO(float*);
void InputINTS(int*);

template <typename T>

double Proccess(T* array, int count, double* mult)
{
	int I = 0;

	for (int i = 0; i < count; i++)
	{
		if ((array[i]) <= array[I])
		{
			I = i;
		}
	}

	for (int i = 0; i < count; i++)
	{
		if (((array[i]) <= 10) && (i > I))
		{
			*mult *= array[i];
		}
	}

	if (I == count - 1)
	{
		*mult = 0;
	}

	return *mult;
}

void main(void)
{
	setlocale(LC_ALL, "Russian");

	double mult = 1;

	int array1[SIZE];
	float array2[SIZE];
	double array3[SIZE];

	cout << "\tВведите размер массива:" << endl;

	int n;
	InputINTS(&n);

	cout << "\tВведите элементы int типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputINT(&array1[i]);
	}

	cout << "\tВведите элементы float типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputFLO(&array2[i]);
	}

	cout << "\tВведите элементы double типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputDOU(&array3[i]);
	}

	cout << "\t\tОбработка типа int:" << endl;
	cout << '\t' << Proccess(array1, n, &mult) << endl;
	mult = 1;
	cout << "\t\tОбработка типа float:" << endl;
	cout << '\t' << Proccess(array2, n, &mult) << endl;
	mult = 1;
	cout << "\t\tОбработка типа double:" << endl;
	cout << '\t' << Proccess(array3, n, &mult) << endl;
}

void InputINTS(int* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n') || (*tmp <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputINT(int* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputDOU(double* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputFLO(float* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}
