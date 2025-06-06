#include <iostream>  // Стандартная библиотека ввода-вывода

using namespace std;	// Использования стандартного пространства имён

void InputDouble(double*);	// Прототип функции проверки на корректность ввода

class  Equation	// Базовый класс для работы с уравнением
{
public:
	
	double A = 0;  // Коэффициент А
	double B = 0;  // Коэффициент В
	double C = 0;  // Коэффициент С

	double X1 = 0;  // Первый корень уравнения
	double X2 = 0;  // Второй корень уравнения

	bool flag = true;  // Флаг для проверки наличия корней уравнения
	int count = 0;  // Счётчик корней

public:
	void SetABC()  // Метод установки коэффициентов
	{
	cout << "Введите A:" << endl;
	InputDouble(&A);  // Вызов функции проверки ввода коэффициента 
	cout << "Введите B:" << endl;
	InputDouble(&B);  // Вызов функции проверки ввода коэффициента 
	cout << "Введите C:" << endl;
	InputDouble(&C);  // Вызов функции проверки ввода коэффициента 

	cout << "Коэффициенты уравнени заданы!" << endl;
	}
 
	void FindX()  // Функция поиска корней уравнения
	{
		if (A == 0 && B == 0 && C != 0)  // Условия случая 0 0 C
		{
			cout << "Уравнение не имеет решения!" << endl;
			flag = false;
		}

		if ((B != 0) && (A == 0) && (C == 0) && (flag == true))  // Условия случая 0 B 0
		{
			X1 = 0;
			count = 1;
		}

		if ((B == 0) && (C == 0) && (A != 0) && (flag == true))  // Условия случая A 0 0
		{
			X1 = 0;
			count = 1;
		}

		if ((C == 0) && (A != 0) && (B != 0) && (flag == true))  // Условия случая A B 0
		{
			X1 = 0;
			X2 = -B / A;
			count = 2;
		}

		if ((A == 0 && B == 0 && C == 0) && (flag == true))  // Условия случая 0 0 C
		{
			cout << "Нет решения!" << endl;
			flag = false;
		}

		if ((B == 0) && (A != 0) && (C != 0) && (flag == true))  // Условия случая A 0 C
		{
			if ((-C / A) < 0)
			{
				cout << "Уравнение не имеет решений!" << endl;
				flag = false;
			}
			else
			{
				X1 = sqrt((-C / A));
				X2 = -X1;
				count = 2;
			}
		}

		if ((A == 0) && (B != 0) && (C != 0) && (flag == true))  // Условия случая 0 B C
		{
			X1 = -C / B;
			count = 1;
		}
		
		if ((A != 0) && (B != 0) && (C != 0) && (flag == true))  // Условия случая A B C
		{
			double D = 0;  // Поле дискриминант

			D = sqrt((B * B) - (4 * A * C));  // Поиск дискриминанта

			if (D > 0)  // Проверка на наличие корней
			{
				X1 = (-B + D) / (2 * A);
				X2 = (-B - D) / (2 * A);
				count = 2;
			}
			else
			{
				if (D == 0)
				{
					X1 = -B / (2 * A);
					count = 1;
				}
				else
				{
					cout << "D < 0, мы не имеем решение уравнения!" << endl;
					flag = false;
				}
			}
		}
	}

public:
	void Output()  // Функция вывода ответа на задачу
	{
			if (flag == true)
			{
				cout << "A = " << A << endl;
				cout << "B = " << B << endl;
				cout << "C = " << C << endl;
				cout << "Ваше уравнение:" << endl;
				cout << A << "x^2 + " << B << "x + " << C << " = 0" << endl;
				if (count == 2)
				{
					cout << "Уравнение имеет 2 корня:" << endl;
					cout << "Ваши корни:" << endl;
					cout << "X1" <<" = " << X1 << endl;
					cout << "X2" << " = " << X2 << endl;
				}
				else
				{
					if (count == 1)
					{
						cout << "Уравнение имеет 1 корень:" << endl;
						cout << "Ваш корень:" << endl;
						cout << "X" << " = " << X1 << endl;
					}
				}
			}
	}
};

class Second : public Equation  // Класс-наследник
{
	double A1;  // Коэффициент А
	double B1;  // Коэффициент В
	double C1;  // Коэффициент С

public: 
	void Sum(Equation x1, Equation x2)  // Метод сложения
	{
		A1 = x1.A + x2.A;
		B1 = x1.B + x2.B;
		C1 = x1.C + x2.C;
	}

	void Dif(Equation x1, Equation x2)  // Метод разности
	{
		A1 = x1.A - x2.A;
		B1 = x1.B - x2.B;
		C1 = x1.C - x2.C;
	}

	void Mult(Equation x1, Equation x2)  // Метод умножения
	{
		A1 = x1.A * x2.A;
		B1 = x1.B * x2.B;
		C1 = x1.C * x2.C;
	}

	void OutputB()  // Метод вывода наследников после преобразований
	{
		cout << "A = " << A1 << endl;
		cout << "B = " << B1 << endl;
		cout << "C = " << C1 << endl;
		cout << "Ваше уравнение:" << endl;
		cout << A1 << "x^2 + " << B1 << "x + " << C1 << " = 0" << endl;
	}
};

int main(void)
{
	setlocale(LC_ALL, "Russian");  // Установка русской кодировки в консоли

	Equation N;  // Создание базового представителя для первой части задания

	N.SetABC();  // Вызов метода установки коэффициентов 
	N.FindX();  // Вызов метода поиска решения уравнения
	N.Output();  // Вызов функции вывода результата

	cout << "Теперь создадим нового представиля базового класса для проведений операций наследника" << endl;

	Equation M;  // Второй базовый представитель для работы методов наследника
	M.SetABC();  // Вызов метода установки коэффициентов 

	cout << "Теперь создадим представителей наследника, чтобы показать результат работы функций:" << endl;
	Second n1, n2, n3;  // Создания представителей для сохранения результатов операций методов наследника
	
	cout << "Операция суммы:" << endl;
	n1.Sum(N, M);  // Вызов метода суммы
	n1.OutputB();
	cout << "Операция разности:" << endl;
	n2.Dif(N, M);  // Вызов метода разности
	n2.OutputB();
	cout << "Операция произведения:" << endl;
	n3.Mult(N, M);  // Вызов метода произведения
	n3.OutputB();

	return 0;
}

void InputDouble(double* tmp)  // Функция проверки на корректность ввода значения коэффициентов
{
	while (!(cin >> *tmp) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректный ввод!" << endl;
	}
}
