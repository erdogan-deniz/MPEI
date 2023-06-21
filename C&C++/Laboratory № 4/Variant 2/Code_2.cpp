#define SIZE 25

#include <iostream>
#include <cmath>

using namespace std;

void InputINT(int*);
void InputDOU(double*);
void InputFLO(float*);
void InputINTS(int*);

template <typename T>

double Proccess(T* array, int count, double* mult, bool* k, int* kk)
{
	int I = 0;
	int J = 0;

	T min = array[0];
	T max = array[0];

	for (int i = 0; i < count; i++)
	{
		if (abs(array[i]) < abs(min))
		{
			min = abs(array[i]);
			I = i;
		}

		if (abs(array[i]) > abs(max))
		{
			max = abs(array[i]);
			J = i;
		}
	}

	if (max == min)
	{
		cout << "Ваши max и min по модулям одинаковые!" << endl;
		*k = false;
		return 0;
	}

	if (I >= J)
	{
		int q = I;
		I = J;
		J = q;
	}

	for (++I; I < J; ++I)
	{
		*mult *= array[I];
		*kk = *kk + 1;
	}
	return *mult;
}

void main(void)
{
	setlocale(LC_ALL, "Russian");

	double mult = 1;

	double tmpl = 0;

	bool k = true;

	int array1[SIZE] = { 0 };
	float array2[SIZE] = { 0 };
	double array3[SIZE] = { 0 };

	cout << "Второй пункт - работа с шаблонами функций:" << endl;

	cout << "Input size of array:" << endl;

	int kk = 0;

	int n;
	InputINTS(&n);

	cout << "Input array elements int type:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputINT(&array1[i]);
	}

	cout << "Input array elements float type:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputFLO(&array2[i]);
	}

	cout << "Input array elements double type:" << endl;
	for (int i = 0; i < n; ++i)
	{
		InputDOU(&array3[i]);
	}

	cout << endl << "Показываем работу шаблонной-функции с разными типами:" << endl;

	cout << "Process type int:" << endl;
	tmpl = Proccess(array1, n, &mult, &k, &kk);
	if (k == true)
	{
		if (kk == 0)
		{
			cout << "У вас нет элементов между max и мин!" << endl;
		}
		else
		{
			if (tmpl == 0)
			{
				tmpl = abs(tmpl);
			}
			cout << tmpl << endl;
		}
	}

	k = true;
	kk = 0;
	mult = 1;

	cout << "Process type float:" << endl;
	tmpl = Proccess(array2, n, &mult, &k, &kk);
	if (k == true)
	{
		if (kk == 0)
		{
			cout << "У вас нет элементов между max и мин!" << endl;
		}
		else
		{
			if (tmpl == 0)
			{
				tmpl = abs(tmpl);
			}
			cout << tmpl << endl;
		}
	}
	k = true;
	kk = 0;
	mult = 1;


	cout << "Process tyep double:" << endl;
	tmpl = Proccess(array3, n, &mult, &k, &kk);
	if (k == true)
	{
		if (kk == 0)
		{
			cout << "У вас нет элементов между max и мин!" << endl;
		}
		else
		{
			if (tmpl == 0)
			{
				tmpl = abs(tmpl);
			}
			cout << tmpl << endl;
		}
	}
	cout << endl << "Конец работы программы!" << endl;
}

void InputINTS(int* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n') || (*tmp <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}

void InputINT(int* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}

void InputDOU(double* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}

void InputFLO(float* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}
