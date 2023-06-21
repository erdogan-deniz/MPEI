#include <iostream>
#include <vector>

using namespace std;

void InputDOU(double*);

class EmployeeBase
{
public:
	string Name = "";
	string Surname = "";
	string Patronymic = "";
	double Payment = 0;

	virtual void SetName() = 0;

	virtual void GetName() = 0;

	virtual void SetSurname() = 0;

	virtual void GetSurname() = 0;

	virtual void SetPatronymic() = 0;

	virtual void GetPatronymic() = 0;

	virtual void SetPayment() = 0;

	virtual void GetPayment() = 0;
};

  // Класс для метода директора добавления сотрудников, иначе класс виртуальный и его массив анриал создать
class Employee
{
public:
	string Name = "";
	string Surname = "";
	string Patronymic = "";
	double Payment = 0;

	void SetName()
	{
		cout << "Input name of employee:" << endl;
		cin >> Name;
	}

	void GetName()
	{
		if (Name != "")
		{
			cout << "Name of employee:" << endl;
			cout << Name << endl;
		}
		else
		{
			cout << "Name is empty!" << endl;
		}
	}

	void SetSurname()
	{
		cout << "Input surname of employee:" << endl;
		cin >> Surname;
	}

	void GetSurname()
	{
		if (Surname != "")
		{
			cout << "Surname of employee:" << endl;
			cout << Surname << endl;
		}
		else
		{
			cout << "Surname is empty!" << endl;
		}
	}

	void SetPatronymic()
	{
		cout << "Input patronymic of employee:" << endl;
		cin >> Patronymic;
	}

	void GetPatronymic()
	{
		if (Patronymic != "")
		{
			cout << "Patronymic of employee:" << endl;
			cout << Patronymic << endl;
		}
		else
		{
			cout << "Patronymic is empty!" << endl;
		}
	}

	void SetPayment()
	{
		cout << "Input payment of employee:" << endl;
		InputDOU(&Payment);
	}

	void GetPayment()
	{
		if (Payment != 0)
		{
			cout << "Payment of employee:" << endl;
			cout << Payment << endl;
		}
		else
		{
			cout << "Payment is empty!" << endl;
		}
	}
};

class Director: protected virtual EmployeeBase
{
public:
	vector <Employee> Vec1;
	Employee Example;
	int Counter = 0;

	void SetName() override
	{
		cout << "Input name of director:" << endl;
		cin >> Name;
	}

	void GetName() override
	{
		if (Name != "")
		{
			cout << "Name of director:" << endl;
			cout << Name << endl;
		}
		else
		{
			cout << "Name is empty!" << endl;
		}
	}

	void SetSurname() override
	{
		cout << "Input surname of director:" << endl;
		cin >> Surname;
	}

	void GetSurname() override
	{
		if (Surname != "")
		{
			cout << "Surname of director:" << endl;
			cout << Surname << endl;
		}
		else
		{
			cout << "Surname is empty!" << endl;
		}
	}

	void SetPatronymic() override
	{
		cout << "Input patronymic of director:" << endl;
		cin >> Patronymic;
	}

	void GetPatronymic() override
	{
		if (Patronymic != "")
		{
			cout << "Patronymic of director:" << endl;
			cout << Patronymic << endl;
		}
		else
		{
			cout << "Patronymic is empty!" << endl;
		}
	}

	void SetPayment() override
	{
		cout << "Input payment:" << endl;
		InputDOU(&Payment);
	}

	void GetPayment() override
	{
		if (Payment != 0)
		{
			cout << "Payment of director:" << endl;
			cout << Payment << endl;
		}
		else
		{
			cout << "Payment is empty!" << endl;
		}
	}

	void Hiring() 
	{
		++Counter;

		Vec1.push_back(Example);
		Vec1[Counter - 1].SetName();
		Vec1[Counter - 1].SetSurname();
		Vec1[Counter - 1].SetPatronymic();
		Vec1[Counter - 1].SetPayment();
		cout << "\nNew employeer was added!" << endl << endl;
	}

	void Dismiss()
	{
		if (Counter > 0)
		{
			cout << "Last employee was dismiss!" << endl << endl;
			--Counter;
			Vec1.pop_back();
		}
		else
		{
			cout << "Director haven't employees!" << endl;
		}
	}

	void Output()
	{
		if (Counter > 0)
		{
			int i = 0;
			while (i < Counter)
			{
				cout << "Employee number - " << (i + 1) << endl << endl;
				Vec1[i].GetName();
				Vec1[i].GetSurname();
				Vec1[i].GetPatronymic();
				Vec1[i].GetPayment();
				cout << endl;
				++i;
			}
		}
		else
		{
			cout << "You haven't emloyees!" << endl;
		}
	}
};

class Accountant: protected virtual EmployeeBase
{
private:
	double Bet = 0;

public:
	void SetName() override
	{
		cout << "Input name of accountant:" << endl;
		cin >> Name;
	}

	void GetName() override
	{
		if (Name != "")
		{
			cout << "Name of accountant:" << endl;
			cout << Name << endl;
		}
		else
		{
			cout << "Name is empty!" << endl;
		}
	}

	void SetSurname() override
	{
		cout << "Input surname of accountant:" << endl;
		cin >> Surname;
	}

	void GetSurname() override
	{
		if (Surname != "")
		{
			cout << "Sername of accountant:" << endl;
			cout << Surname << endl;
		}
		else
		{
			cout << "Surname is empty!" << endl;
		}
	}

	void SetPatronymic() override
	{
		cout << "Input patronymic of accountant:" << endl;
		cin >> Patronymic;
	}

	void GetPatronymic() override
	{
		if (Patronymic != "")
		{
			cout << "Patronymic of accountant:" << endl;
			cout << Patronymic << endl;
		}
		else
		{
			cout << "Patronymic is empty!" << endl;
		}
	}

	void SetPayment() override
	{
		cout << "Input payment of accountant:" << endl;
		InputDOU(&Payment);
	}

	void GetPayment() override
	{
		if (Payment != 0)
		{
			cout << "Payment of accountant:" << endl;
			cout << Payment << endl;
		}
		else
		{
			cout << "Payment is empty!" << endl;
		}
	}

	void SetBet()
	{
		cout << "Input bet:" << endl;
		InputDOU(&Bet);
	}

	void GetBet()
	{
		if (Bet != 0)
		{
			cout << "Bet is:" << endl;
			cout << Bet << endl;
		}
		else
		{
			cout << "Bet is empty!" << endl;
		}
	}

	void Calculate(Employee Christian)
	{
		if ((Christian.Payment != 0) && (Bet != 0))
		{
			cout << "The wages of " << Christian.Name << " is " << 20 * Bet * Christian.Payment << endl;
		}
	}
};

class Security: protected virtual EmployeeBase
{
public:
	string Item = "";

	void SetName() override
	{
		cout << "Input name of security:" << endl;
		cin >> Name;
	}

	void GetName() override
	{
		if (Name != "")
		{
			cout << "Name of security:" << endl;
			cout << Name << endl;
		}
		else
		{
			cout << "Name is empty!" << endl;
		}
	}

	void SetSurname() override
	{
		cout << "Input surname of security:" << endl;
		cin >> Surname;
	}

	void GetSurname() override
	{
		if (Surname != "")
		{
			cout << "Surname of security:" << endl;
			cout << Surname << endl;
		}
		else
		{
			cout << "Surname is empty!" << endl;
		}
	}

	void SetPatronymic() override
	{
		cout << "Input patronymic of security:" << endl;
		cin >> Patronymic;
	}

	void GetPatronymic() override
	{
		if (Patronymic != "")
		{
			cout << "Patronymic of security:" << endl;
			cout << Patronymic << endl;
		}
		else
		{
			cout << "Patronymic is empty!" << endl;
		}
	}

	void SetPayment() override
	{
		cout << "Input payment of security:" << endl;
		InputDOU(&Payment);
	}

	void GetPayment() override
	{
		if (Payment != 0)
		{
			cout << "Payment of security:" << endl;
			cout << Payment << endl;
		}
		else
		{
			cout << "Payment is empty!" << endl;
		}
	}

	void SetItem()
	{
		cout << "Input item of security:" << endl;
		cin >> Item;
	}

	void GetItem()
	{
		if (Item != "")
		{
			cout << "Item of security:" << endl;
			cout << Item << endl;
		}
		else
		{
			cout << "Item is empty!" << endl;
		}
	}
};

class Secretary: protected virtual EmployeeBase
{
public:
	void SetName() override
	{
		cout << "Input name of secretary:" << endl;
		cin >> Name;
	}

	void GetName() override
	{
		if (Name != "")
		{
			cout << "Name of secretary:" << endl;
			cout << Name << endl;
		}
		else
		{
			cout << "Name is empty!" << endl;
		}
	}

	void SetSurname() override
	{
		cout << "Input surname of secretary:" << endl;
		cin >> Surname;
	}

	void GetSurname() override
	{
		if (Surname != "")
		{
			cout << "Surname of secretary:" << endl;
			cout << Surname << endl;
		}
		else
		{
			cout << "Surname is empty!" << endl;
		}
	}

	void SetPatronymic() override
	{
		cout << "Input patronymic secretary:" << endl;
		cin >> Patronymic;
	}

	void GetPatronymic() override
	{
		if (Patronymic != "")
		{
			cout << "Patronymic of secretary:" << endl;
			cout << Patronymic << endl;
		}
		else
		{
			cout << "Patronymic is empty!" << endl;
		}
	}

	void SetPayment() override
	{
		cout << "Input payment of secretary:" << endl;
		InputDOU(&Payment);
	}

	void GetPayment() override
	{
		if (Payment != 0)
		{
			cout << "The payment of secretary:" << endl;
			cout << Payment << endl;
		}
		else
		{
			cout << "Payment is empty!" << endl;
		}
	}

	void OutputSec(Security arr[2])
	{
		cout << "______________________________________\n";
		cout << "|Name|Surname|Patronymic|Payment|Item|\n";
		cout << "--------------------------------------\n";
		for (int i = 0; i < 2; ++i)
		{
			cout << "|";
			arr[i].GetName();
			cout << "|";
			arr[i].GetSurname();
			cout << "|";
			arr[i].GetPatronymic();
			cout << "|";
			arr[i].GetPayment();
			cout << "|";
			arr[i].GetItem();
			cout << "|" << endl;
			cout << "-------------------------------------\n";
		}
	}

	void OutputDir(Director ar)
	{
		cout << "_________________________________\n";
		cout << "|Name|Surname|Patronymic|Payment|\n";
		cout << "---------------------------------\n";
		for (int i = 0; i < 2; ++i)
		{
			cout << "|" << ar.Vec1[i].Name << "|" << ar.Vec1[i].Surname << "|" << ar.Vec1[i].Patronymic << "|" << ar.Vec1[i].Payment << "|" << endl;
			cout << "-------------------------------\n";
		}
	}
};

class Initials {
protected:
	Initials()
	{
		cout << "The new delegate of initials class was created!" << endl;
	}
	virtual void Greetings() = 0;
};

class Payments {
protected:
	Payments()
	{
		cout << "The new delegate of paymnets class was created!" << endl;
	}
	virtual void Greetings() = 0;
};

class Data: protected virtual Initials, Payments
{
public:
	Data()
	{
		cout << "The new delegate of data class was created!" << endl;
	}
	void Greetings() override
	{
		cout << "Welcome" << endl;
	}
};

int main()
{
	Data data;
	data.Greetings();
	return 0;
}

void InputDOU(double* tmp)
{
	while (!(cin >> *tmp) || (cin.peek() != '\n') || (*tmp <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Incorrect input!" << endl;
	}
}
