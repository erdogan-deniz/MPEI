#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Animal
{
public: Animal ()
{
cout << "Animal was born!" << endl;
}

public: ~Animal() 
{
	cout << "Animal was dead!" << endl;
}

protected: string Class = "";
protected: bool key = true;
protected: int CountLimbs = 0;
protected: int CountDescendants = 0;

public: void SetCountLimbs() 
{
	cout << "Input count of limbs:" << endl;

	int _CountLimbs = 0;
	char ch = '@';

	if ((scanf("%d%c", &_CountLimbs, &ch) != 2) || (ch != '\n') || (_CountLimbs < 0))
	{
		cout << "Incorrect input!" << endl;
		key = false;
		exit(0);
	}
	else
	{
		CountLimbs = _CountLimbs;
	}
}

public: void SetClass()
{
	cout << "Input class of animal:" << endl;

	cin >> Class;
}

public: void GetClass()
{
	if (Class != "")
	{
		cout << "Class of animal:" << endl;
		cout << Class << endl;
	}
	else 
	{
		cout << "Class of animal empty!" << endl;
	}
}


public: void GetCountLimbs()
{
	if ((CountLimbs != 0) && (key == true))
	{
		cout << "Count of limbs:" << endl;
		cout << CountLimbs << endl;
	}
	else
	{
		cout << "Number of count limbs is empty!" << endl;
	}
}

public: void SetCountDescendants()
{
	cout << "Input count of descendants:" << endl;

	int _CountDescendants = 0;
	char ch = '@';

	if ((scanf("%d%c", &_CountDescendants, &ch) != 2) || (ch != '\n') || (_CountDescendants < 0))
	{
		cout << "Incorrect input!" << endl;
		key = false;
		exit(0);
	}
	else
	{
		CountDescendants = _CountDescendants;
	}
}

public: void GetCountDescendants()
{
	if ((CountDescendants != 0) && (key == true))
	{
		cout << "Count of descendants:" << endl;
		cout << CountDescendants << endl;
	}
	else
	{
		cout << "Number of count descendants is empty!" << endl;
	}
}

};

class HomeAnimal: public Animal
{
public: HomeAnimal()
{
	cout << "It's a home animal" << endl;
}

public: HomeAnimal(string Class)
{
	this->Class = Class;
	cout << "It's a home animal!" << endl;
}

public: void GetNickname() 
{
	if (Nickname != "")
	{
		cout << "Nickname of pet:" << endl;
		cout << Nickname << endl;
	}
	else
	{
		cout << "Nickname is empty!" << endl;
	}
}

public: void SetNickname()
{
	cout << "Input nickname of pet:" << endl;
	cin >> Nickname;
}

public: ~HomeAnimal()
{
	cout << "Oh dear... pet" << endl;
}

private: string Nickname = "";
};

int main(void)
{
	setlocale(LC_ALL, "Russian");
	HomeAnimal Cat;
	
	cout << "Сначала попробуем вывести пустые поля животного:" << endl;
	Cat.GetClass();
	Cat.GetCountLimbs();
	Cat.GetCountDescendants();
	
	cout << "Теперь заполним данные о животном:" << endl;
	Cat.SetClass();
	Cat.SetCountLimbs();
	Cat.SetCountDescendants();

	cout << "Теперь выведем заполненные данные о животном:" << endl;
	Cat.GetClass();
	Cat.GetCountLimbs();
	Cat.GetCountDescendants();
	cout << "Теперь заполним поля для дочерного класса" << endl;
	Cat.SetNickname();
	Cat.GetNickname();
	cout << "Как всё живое, животное умрёт... (деструктор)" << endl;
	return 0;
}
