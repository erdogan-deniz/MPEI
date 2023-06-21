#define SIZE 15

#include <iostream>
#include <cmath>

using namespace std;

void InputINT(int*);
void InputDOU(double*);
void InputFLO(float*);
void InputINTS(int*);

template <typename T>

double Proccess(T* array, int count, double* sum)
{
	int I = -1;

	for (int i = 0; i < count; i++)
	{
		if ((array[i]) == 0)
		{
			I = i;
			break;
		}
	}

	if ( I > -1)
	{
		for (I; I <= count; ++I)
		{
			*sum += abs(array[I]);
		}
	}
	else
	{
		cout << "Нет подходящих элементов!" << endl;
	}
	return *sum;
}

int main(void)
{
	setlocale(LC_ALL, "Russian");

	double sum = 0;

	int array1[SIZE] = { 0 };
	float array2[SIZE] = { 0 };
	double array3[SIZE] = { 0 };

	cout << "\n\t\t\tРабота с шаблонами функций:\n" << endl;

	cout << "Введите размер массива:" << endl;

	int n;
	InputINTS(&n);

	cout << "Введите элементы int типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputINT(&array1[i]);
	}

	cout << "Введите элементы float типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputFLO(&array2[i]);
	}

	cout << "Введите элементы double типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputDOU(&array3[i]);
	}

	cout << "Обработка типа int:" << endl;
	cout << Proccess(array1, n, &sum) << endl;
	sum = 0;
	cout << "Обработка типа float:" << endl;
	cout << Proccess(array2, n, &sum) << endl;
	sum = 0;
	cout << "Обработка типа double:" << endl;
	cout << Proccess(array3, n, &sum) << endl;
	return 0;
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
