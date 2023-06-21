#define SIZE 10  // Фиксированная размерность массивов

#include <iostream>  // Стандартная библиотека ввода-вывода
#include <cmath>  // Математическая библиотека

using namespace std;  // Использование стандратного пространства имён

void InputINT(int*);  // Прототип функции ввода элементов целого типа
void InputDOU(double*);  // Прототип функции ввода элементов типа double
void InputFLO(float*);  // Прототип функции ввода элементов типа float
void InputINTS(int*);  // Прототип функции ввода размера массивов

template <typename T>  // Прототип шаблонна

double Proccess(T* array, int count, double* sum, int* counter)  // Основная функция обработки
{
	int I = -1;  // Индекс последнего отрицательного элемента

	for (int i = count - 1; i >= 0; --i)
	{
		if ((array[i]) < 0)
		{
			I = i;
			break;
		}
	}

	if (I == -1)  // Проверка найденного индекса последнего отрицательного элемента
	{
		cout << "У вас нет отрицательных элементов" << endl;
		*counter = -1;
	}
	else
	{
		for (int i = ++I; i < count; ++i)
		{
			*sum += array[i];
			++*counter;
		}
	}
	return *sum;
}

int main(void)
{
	setlocale(LC_ALL, "Russian");  // Установка русского языка в консоли

	double sum = 0;  // Сумма подходящих элементов
	int counter = 0;  // Счётчик подходящих элементов

	int array1[SIZE] = { 0 };
	float array2[SIZE] = { 0 };
	double array3[SIZE] = { 0 };

	cout << "\n\t\t\tРабота с шаблонами функций:\n" << endl;

	cout << "Введите размер массива:" << endl;

	int n;  // Размерность массивов
	InputINTS(&n);  // Вызов функции ввода размерности массивов

	cout << "Введите элементы int типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputINT(&array1[i]);  // Заполнение массива типа int
	}

	cout << "Введите элементы float типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputFLO(&array2[i]);  // Заполнение массива типа float
	}

	cout << "Введите элементы double типа:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputDOU(&array3[i]);  // Заполнение массива типа double
	}

	double TMP = 0;  // Временная переменная

	cout << "\nОбработка типа int:" << endl;
	TMP = Proccess(array1, n, &sum, &counter);  // Вызов функции-обработки для первого массива
	if (counter > 0)
	{
		cout << TMP;
	}
	
	if (counter == 0)
	{
		cout << "У вас нет элементов после последнего отрицательного числа!" << endl;
	}

	counter = 0;
	sum = 0;
	cout << "\nОбработка типа float:" << endl;
	TMP = Proccess(array2, n, &sum, &counter);  // Вызов функции-обработки для второго массива
	if (counter > 0)
	{
		cout << TMP;
	}

	if (counter == 0)
	{
		cout << "У вас нет элементов после последнего отрицательного числа!" << endl;
	}
	
	counter = 0;
	sum = 0;
	cout << "\nОбработка типа double:" << endl;
	TMP = Proccess(array3, n, &sum, &counter);  // Вызов функции-обработки для третьего массива
	if (counter > 0)
	{
		cout << TMP;
	}

	if (counter == 0)
	{
		cout << "У вас нет элементов после последнего отрицательного числа!" << endl;
	}

	return 0;
}

void InputINTS(int* tmp)  // Опасание функции ввода размера массивов
{
	while (!(cin >> *tmp) || (cin.peek() != '\n') || (*tmp <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputINT(int* tmp)  // Описание функции ввода числа типа int
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputDOU(double* tmp)  // Описание функции ввода числа типа double
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputFLO(float* tmp)  // Описание функции ввода числа типа float 
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}
