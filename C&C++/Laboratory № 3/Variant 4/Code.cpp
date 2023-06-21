#include <iostream>  // Стандартная библиотека ввода-вывода
#include <Windows.h>  // Библиотека консольных настроек

using namespace std;  // Использование стандартного пространства имён

void InputINT(int*);  // Функция ввода целых чисел с проверкой

class Adress  // Класс адреса
{
private:  // Приватные поля
	string Country = "";  // Поле-страна
	string City = "";  // Поле-город
	string Street = "";  // Поле-улица
	int HomeNumber = -1;  // Поле-номер дома
	int Zipcode = -1;  // Поле-индекс

public:  // Публичные методы
	Adress()  // Описание конструктор без аргументов
	{
		cout << "Адрес был создан!" << endl;
	}

	void SetCountry()  // Описание метода установки страны
	{
		cout << "Input country:" << endl;
		cin >> Country;
	}

	void GetCountry()  // Описание метода выводаа города
	{
		if (Country != "")
		{
			cout << "Country of organisation:" << endl;
			cout << Country << endl;
		}
		else
		{
			cout << "Country is empty!" << endl;
		}
	}

	void SetCity()  // Описание метода установки города
	{
		cout << "Input city:" << endl;
		cin >> City;
	}

	void GetCity()  // Описание метода вывода города
	{
		if (City != "")
		{
			cout << "City of organisation:" << endl;
			cout << City << endl;
		}
		else
		{
			cout << "City is empty!" << endl;
		}
	}

	void SetStreet()  // Описание метода установки улицы
	{
		cout << "Input Street:" << endl;
		cin >> Street;
	}

	void GetStreet()  // Описание метода вывода улицы
	{
		if (Street != "")
		{
			cout << "Street of organisation:" << endl;
			cout << Street << endl;
		}
		else
		{
			cout << "Street is empty!" << endl;
		}
	}

	void SetHomeNumber()  // Описание метода установки номера дома
	{
		cout << "Input number of home:" << endl;
		InputINT(&HomeNumber);
	}

	void GetHomeNumber()  // Описание метода вывода номера дома
	{
		if (HomeNumber != -1)
		{
			cout << "Number of home organisation:" << endl;
			cout << HomeNumber << endl;
		}
		else
		{
			cout << "Number of home is empty!" << endl;
		}
	}

	void SetZipcode()  // Описание метода установки индекса
	{
		cout << "Input zipcode of organisation:" << endl;
		InputINT(&Zipcode);
	}

	void GetZipcode()  // Описание метода вывода индекса
	{
		if (Zipcode != -1)
		{
			cout << "Zipcode of organisation:" << endl;
			cout << Zipcode << endl;
		}
		else
		{
			cout << "Zipcode is empty!" << endl;
		}
	}
};

class Company : public Adress  // Класс-наследник компания 
{
private:  // Приватные поля 
	string Name = "";  // Поле название компании
	int CountEmp = -1;  // Поле количество рабочих компании
	int CountBuild = -1;  // Поле количества зданий компании

public: 
	Company()  // Конструктор без параметров
	{
		cout << "Company was created" << endl;
	}

	void SetName()  // Описание метода установки названия компании
	{
		cout << "Input name of company:" << endl;
		cin >> Name;
	}

	void GetName()  // Описание метода вывода названия компании
	{
		if (Name != "")
		{
			cout << "Name of company:" << endl;
			cout << Name << endl;
		}
		else
		{
			cout << "Name is empty!" << endl;
		}
	}

	void SetCountEmp()  // Описание метода установки количества работников компании
	{
		cout << "Input count of employees:" << endl;
		InputINT(&CountEmp);
	}

	void GetCountEmp()  // Описание метода вывода количества работников компании
	{
		if (CountEmp != -1)
		{
			cout << "Count of employess:" << endl;
			cout << CountEmp << endl;
		}
		else
		{
			cout << "Count is empty!" << endl;
		}
	}

	void SetCountBuild()  // Описание метода установки количества зданий компании
	{
	cout << "Input count of buildings:" << endl;
	InputINT(&CountBuild);
	}

	void GetCountBuild()  // Описание метода вывода количества зданий компании
	{
		if (CountBuild != -1)
		{
			cout << "Count of buildings:" << endl;
			cout << CountBuild << endl;
		}
		else
		{
			cout << "Count is empty!" << endl;
		}
	}
};

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);  // Установка настроек консоли вывода
	SetConsoleOutputCP(1251);  // Установка формы консоли вывода
	setlocale(LC_ALL, "Russian");  // Установка русского языка в консоле
	Company	 tmp;  // Создание представителя дочерного класса

	cout << "Попробуем вывести части почтового адреса несуществующей организации" << endl;
	tmp.GetCountry();  // Вызов метода вывода страны
	tmp.GetCity();  // Вызов метода вывода города
	tmp.GetStreet();  // Вызов метода вывода улицы
	tmp.GetHomeNumber();  // Вызов метода вывода номера дома
	tmp.GetZipcode();  // Вызов метода вывода индекса

	cout << "\nНе удивительно! \nТеперь заполним данными поля и выведем снова:" << endl;
	tmp.SetCountry();  // Вызов метода установки страны
	tmp.SetCity();  // Вызов метода установки города
	tmp.SetStreet();  // Вызов метода установки улицы
	tmp.SetHomeNumber();  // Вызов метода установки номера дома
	tmp.SetZipcode();  // Вызов метода установки индекса

	cout << "\nЗаполнили! Следующий шаг - вывод:" << endl;
	tmp.GetCountry();  // Вызов метода вывода страны
	tmp.GetCity();  // Вызов метода вывода города
	tmp.GetStreet();  // Вызов метода вывода улицы
	tmp.GetHomeNumber();  // Вызов метода вывода номера дома
	tmp.GetZipcode();  // Вызов метода вывода индекса

	cout << "\nТеперь заполним и посмотрим работу дочерного класса!" << endl;
	tmp.SetName();  // Вызов метода установки названия компании
	tmp.SetCountEmp();  // Вызов метода установки количества сотрудников компании
	tmp.SetCountBuild();  // Вызов метода установки количества зданий компании
	tmp.GetName();  // Вызов метода вывода названия компании
	tmp.GetCountEmp();  // Вызов метода вывода количества сотрудников компании
	tmp.GetCountBuild();  // Вызов метода вывода количества зданий компании
	return 0;
}

void InputINT(int* tmp)  // Описание функции ввода целых чисел с проверкой
{
	while (!(cin >> *tmp) || (cin.peek() != '\n') || (*tmp <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}
