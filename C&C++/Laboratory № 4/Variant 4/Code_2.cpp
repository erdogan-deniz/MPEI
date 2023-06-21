#define SIZE 15  // Размер статических массивов

#include <iostream>  // Стандартная библиотека ввода-вывода

using namespace std;  // Использование стандартного пространства имён

void InputINT(int*);  // Прототип функции ввода целого значения
void InputDOU(double*);  // Прототип функции ввода double значения
void InputFLO(float*);  // Прототип функции ввода float значения
void InputINTS(int*);  // Прототип функции ввода целого значения

template <typename T>  // Шаблон

double Proccess(T* array, int count, double* sum, bool* key)  // Функция обработки элемен-тов
{
	int I = 0;  // Индекс первого отрицательного числа
	int J = 0;  // Индекс последнего отрицательного числа

	for (int i = 0; i < count; i++)  // Поиск индекса
	{
		if ((array[i]) < 0)
		{
			I = i;
			break;
		}
	}

	for (int i = 0; i < count; i++)  // Поиск индекса
	{
		if ((array[i]) < 0)
		{
			J = i;
		}
	}

	if (I == J)
	{
		cout << "Недостаточно отрицательных элементов!" << endl;
		*key = false;
		return 0;
	}

	if (array[I] < 0)  // Поиск суммы элементов между первым и последним отри-цательными числами
	{
		for (I; I <= J; ++I)
		{
			*sum += array[I];
		}
		return *sum;
	}
}

void main(void)
{
	setlocale(LC_ALL, "Russian");  // Установка русского языка в консоли

	double sum = 0;  // Сумма элементов

	bool key = true;

	int array1[SIZE] = { 0 };  // Массив целых чисел
	float array2[SIZE] = { 0 };  // Массив float чисел
	double array3[SIZE] = { 0 };  // Массив double чисел

	cout << "\n\t\t\tРабота с шаблонами функций:\n" << endl;

	cout << "Введите размер массива:" << endl;

	int  size = 0;  // Размер массива вводимого с клавиатуры
	InputINTS(&size);  // Установка размера массива

	cout << "Введите элементы int типа:" << endl;
	for (int i = 0; i < size; ++i)  // Ввод элементов массива
	{
		InputINT(&array1[i]);  // Вызов функции проверки введённого значения
	}

	cout << "Введите элементы float типа:" << endl;
	for (int i = 0; i < size; ++i)  // Ввод элементов массива
	{
		InputFLO(&array2[i]);  // Вызов функции проверки введённого значения
	}

	cout << "Введите элементы double типа:" << endl;
	for (int i = 0; i < size; ++i)  // Ввод элементов массива
	{
		InputDOU(&array3[i]);  // Вызов функции проверки введённого значения
	}

	double tmpl = 0;

	cout << "Обработка типа int:" << endl;
	tmpl = Proccess(array1, size, &sum, &key);
	if (key == true)
	{
		cout << tmpl << endl;
	}
	sum = 0;
	key = true;

	cout << "Обработка типа float:" << endl;
	tmpl = Proccess(array2, size, &sum, &key);
	if (key == true)
	{
		cout << tmpl << endl;
	}
	sum = 0;
	key = true;

	cout << "Обработка типа double:" << endl;
	tmpl = Proccess(array3, size, &sum, &key);
	if (key == true)
	{
		cout << tmpl << endl;
	}
}

void InputINTS(int* tmp)  // Функция проверки размера массива
{
	while (!(cin >> *tmp) || (cin.peek() != '\n') || (*tmp <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputINT(int* tmp)  // Функция проверки элемента типа int
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputDOU(double* tmp)  // Функция проверки элемента типа double
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}

void InputFLO(float* tmp)  // Функция проверки элемента типа float
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}
