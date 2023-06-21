#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

class Triangle
{
protected: double X1 = 0;
protected: double Y1 = 0;

protected: double X2 = 0;
protected: double Y2 = 0;

protected: double X3 = 0;
protected: double Y3 = 0;

protected: bool key = true;

public: void InputData()
{
	cout << "Input X1:" << endl;

	double _X1;
	char c;

	if ((scanf("%lf%c", &_X1, &c) != 2) || (c != '\n'))
	{
		cout << "Incorrect input!";
		key = false;
	}
	else
	{
		X1 = _X1;
	}

	if (key == true)
	{
		cout << "Input Y1:" << endl;
		double _Y1;
		char c ;

		if ((scanf("%lf%c", &_Y1, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			Y1 = _Y1;
		}
	}


	if (key == true)
	{
		cout << "Input X2:" << endl;
		double _X2;
		char c;

		if ((scanf("%lf%c", &_X2, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			X2 = _X2;
		}
	}

	if (key == true)
	{
		cout << "Input Y2:" << endl;
		double _Y2;
		char c;

		if ((scanf("%lf%c", &_Y2, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			Y2 = _Y2;
		}
	}

	if (key == true)
	{
		cout << "Input X3:" << endl;
		double _X3;
		char c;

		if ((scanf("%lf%c", &_X3, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			X3 = _X3;
		}
	}

	if (key == true)
	{
		cout << "Input Y3:" << endl;
		double _Y3;
		char c;

		if ((scanf("%lf%c", &_Y3, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			Y3 = _Y3;
		}
	}

	if (key == true)
	{
		if ((X1 == X2) && (X2 == X3) && (X3 == X1) && (Y1 == Y2) && (Y2 == Y3) && (Y3 == Y1))
		{
			cout << "All points in the same position!" << endl;
			key = false;
		}
	}

	if (key == true)
	{
		if (((X1 == X2) && (X2 == X3)) || ((Y1 == Y2) && (Y2 == Y3)))
		{
			cout << "All points on the line!" << endl;
			key = false;
		}
	}

	if (key == true) {
		if (((X2 - X1) != 0) && ((X3 - X1) != 0) && ((X3 - X2) != 0) && ((Y2 - Y1) != 0) && ((Y3 - Y1) != 0) && ((Y3 - Y2) != 0))
		{
			if ((((X2 - X1) / (Y2 - Y1)) == ((X3 - X1) / (Y3 - Y1))) && (((X2 - X1) / (Y2 - Y1)) == ((X3 - X2) / (Y3 - Y2)))
				&& (((X3 - X1) / (Y3 - Y1)) == ((X3 - X2) / (Y3 - Y2))))
			{
				cout << "All points on the line!" << endl;
				key = false;
			}
		}
	}

	if (key == true)
	{
		double tmp1 = 0;
		double tmp2 = 0;
		double tmp3 = 0;

		tmp1 = sqrt(pow((X3 - X1), 2) + pow((Y3 - Y1), 2));
		tmp2 = sqrt(pow((X2 - X1), 2) + pow((Y2 - Y1), 2));
		tmp3 = sqrt(pow((X3 - X2), 2) + pow((Y3 - Y2), 2));

		if ((tmp1 + tmp2 <= tmp3) || (tmp2 + tmp3 <= tmp1) || (tmp1 + tmp3 <= tmp2))
		{
			cout << "This triangle can't be created!" << endl;
			key = false;
		}
	}

	if (key == true)
	{
		cout << "New class representative was created!" << endl;
	}

}

public: void MoveT()
{
	bool flag = true;

	if ((key == true))
	{
		double StepX = 0;
		cout << "Enter size if step relative to the axis OX:" << endl;
		if (!(cin >> StepX))
		{
			cout << "Incorrect input!" << endl;
			flag = false;
		}

		double StepY = 0;
		if (flag == true)
		{
			cout << "Enter size if step relative to the axis OY:" << endl;
			if (!(cin >> StepY) || (flag == false))
			{
				cout << "Incorrect input!";
				flag = false;
			}
		}

		if (flag == true)
		{
			X1 += StepX;
			X2 += StepX;
			X3 += StepX;
			Y1 += StepY;
			Y2 += StepY;
			Y3 += StepY;
		}

		if (flag == true)
		{
			cout << "Triangle was moved!" << endl;
			cout << "X1 = " << X1 << " Y1 = " << Y1 << endl;
			cout << "X2 = " << X2 << " Y2 = " << Y2 << endl;
			cout << "X3 = " << X3 << " Y3 = " << Y3 << endl;
		}

	}
	else
	{
		cout << "Your can't move the triangle which uncreated!" << endl;
	}
}

public: void ResizeT()
{
	bool flag = true;

	double k = 0;
	if (key == true) {
		cout << "Input ratio of resize:" << endl;
		if (!(cin >> k) || (k == 0))
		{
			cout << "Incorrect input!" << endl;
			flag = false;
		}
	}

	if ((flag == true) && (key == false))
	{
		cout << "Can't resize uncreated triangle!" << endl;
		flag = false;
	}

	if ((flag == true) && (key == true))
	{
		X1 /= k;
		X2 /= k;
		X3 /= k;
		Y1 /= k;
		Y2 /= k;
		Y3 /= k;

		cout << "Triangle was resize!" << endl;
		cout << "X1 = " << X1 << " Y1 = " << Y1 << endl;
		cout << "X2 = " << X2 << " Y2 = " << Y2 << endl;
		cout << "X3 = " << X3 << " Y3 = " << Y3 << endl;
	}
}

public: void RotationT()
{
	bool flag = true;

	double tmp = 0;

	if (key == true)
	{
		cout << "Input degrees of ratation:" << endl;
		if (!(cin >> tmp))
		{
			cout << "Incorrect input!" << endl;
			flag = false;
		}
	}
	else
	{
		if (flag == false)
		{
			cout << "Can't rotate uncreated triangle!" << endl;
			flag = false;
		}
	}

	if ((key == true) && (flag == true))
	{
		X1 = X1 * cos(tmp) - Y1 * sin(tmp);
		Y1 = X1 * sin(tmp) + Y1 * cos(tmp);

		X2 = X2 * cos(tmp) - Y2 * sin(tmp);
		Y2 = X2 * sin(tmp) + Y2 * cos(tmp);

		X3 = X3 * cos(tmp) - Y3 * sin(tmp);
		Y3 += X3 * sin(tmp) + Y3 * cos(tmp);

		cout << "Triangle was rotated!" << endl;
		cout << "X1 = " << X1 << " Y1 = " << Y1 << endl;
		cout << "X2 = " << X2 << " Y2 = " << Y2 << endl;
		cout << "X3 = " << X3 << " Y3 = " << Y3 << endl;
	}
}

public: void PropertyT()
{
	if (key == true) {
		if ((X1 == 0) && (X2 == 0) && (X3 == 0) && (Y1 == 0) && (Y2 == 0) && (Y3 == 0))
		{
			cout << "Triangle uncreated!" << endl;
		}
		else
		{
			cout << "Triangle is a real!" << endl;

			if ((X1 >= 0) && (X2 >= 0) && (X3 >= 0) && (Y1 >= 0) && (Y2 >= 0) && (Y3 >= 0))
			{
				cout << "It's in a first quarter." << endl;
			}

			if ((X1 <= 0) && (X2 <= 0) && (X3 <= 0) && (Y1 <= 0) && (Y2 <= 0) && (Y3 <= 0))
			{
				cout << "It's in a third quarter." << endl;
			}

			if ((X1 <= 0) && (X2 <= 0) && (X3 <= 0) && (Y1 >= 0) && (Y2 >= 0) && (Y3 >= 0))
			{
				cout << "It's in a second quarter." << endl;
			}

			if ((X1 >= 0) && (X2 >= 0) && (X3 >= 0) && (Y1 <= 0) && (Y2 <= 0) && (Y3 <= 0))
			{
				cout << "It's in a second quarter." << endl;
			}

		}
	}
	else
	{
		cout << "Triangle wasn't created!" << endl;
	}
}
};

class Rectangle: public Triangle
{

private: double X4 = 0;
private: double Y4 = 0;

public: void InputData()
{
	cout << "Input X1:" << endl;

	double _X1;
	char c;

	if ((scanf("%lf%c", &_X1, &c) != 2) || (c != '\n'))
	{
		cout << "Incorrect input!";
		key = false;
	}
	else
	{
		X1 = _X1;
	}

	if (key == true)
	{
		cout << "Input Y1:" << endl;
		double _Y1;
		char c;

		if ((scanf("%lf%c", &_Y1, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			Y1 = _Y1;
		}
	}


	if (key == true)
	{
		cout << "Input X2:" << endl;
		double _X2;
		char c;

		if ((scanf("%lf%c", &_X2, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			X2 = _X2;
		}
	}

	if (key == true)
	{
		cout << "Input Y2:" << endl;
		double _Y2;
		char c;

		if ((scanf("%lf%c", &_Y2, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			Y2 = _Y2;
		}
	}

	if (key == true)
	{
		cout << "Input X3:" << endl;
		double _X3;
		char c;

		if ((scanf("%lf%c", &_X3, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			X3 = _X3;
		}
	}

	if (key == true)
	{
		cout << "Input Y3:" << endl;
		double _Y3;
		char c;

		if ((scanf("%lf%c", &_Y3, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			Y3 = _Y3;
		}
	}

	if (key == true)
	{
		cout << "Input X4:" << endl;
		double _X4;
		char c;

		if ((scanf("%lf%c", &_X4, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			X4 = _X4;
		}
	}

	if (key == true)
	{
		cout << "Input Y4:" << endl;
		double _Y4;
		char c;

		if ((scanf("%lf%c", &_Y4, &c) != 2) || (c != '\n'))
		{
			cout << "Incorrect input!";
			key = false;
		}
		else
		{
			Y4 = _Y4;
		}
	}

	if (key == true)
	{
		if ((X1 == X2) && (X2 == X3) && (X3 == X4) && (X4 == X1) && (Y1 == Y2) && (Y2 == Y3) && (Y3 == Y4) && (Y4 == Y1))
		{
			cout << "All points in the same position!" << endl;
			key = false;
		}
	}

	if (key == true)
	{
		if (((X1 == X2) && (X2 == X3) && (X3 == X4)) || ((Y1 == Y2) && (Y2 == Y3) && (Y3 == Y4)))
		{
			cout << "All points on the line!" << endl;
			key = false;
		}
	}

	if (key == true) {
		if (((X2 - X1) != 0) && ((X3 - X1) != 0) && ((X3 - X2) != 0) && ((Y2 - Y1) != 0) && ((Y3 - Y1) != 0) && ((Y3 - Y2) != 0))
		{
			if ((((X2 - X1) / (Y2 - Y1)) == ((X3 - X1) / (Y3 - Y1))) && (((X2 - X1) / (Y2 - Y1)) == ((X3 - X2) / (Y3 - Y2)))
				&& (((X3 - X1) / (Y3 - Y1)) == ((X3 - X2) / (Y3 - Y2))))
			{
				cout << "Points on the line!" << endl;
				key = false;
			}
		}
	}

	if (key == true)
	{
		double tmp1 = 0;
		double tmp2 = 0;
		double tmp3 = 0;
		double tmp4 = 0;

		double dig1 = 0;
		double dig2 = 0;

		tmp1 = sqrt(pow((X2 - X1), 2) + pow((Y2 - Y1), 2));
		tmp2 = sqrt(pow((X3 - X2), 2) + pow((Y3 - Y2), 2));
		tmp3 = sqrt(pow((X4 - X3), 2) + pow((Y4 - Y3), 2));
		tmp4 = sqrt(pow((X4 - X1), 2) + pow((Y4 - Y1), 2));

		dig1 = sqrt(pow(X3 - X1, 2) + pow(Y3 - Y1, 2));
		dig2 = sqrt(pow(X4 - X2, 2) + pow(Y4 - Y2, 2));

		if ((pow(tmp1, 2) + pow(tmp2, 2) == pow(dig1, 2)) && (pow(tmp3, 2) + pow(tmp4, 2) == pow(dig2, 2) && (dig1 == dig2)))
		{
			cout << "Rectangle was created!" << endl;
		}
		else 
		{
		cout << "This rectangle can't be created!" << endl;
		key = false;
		}
	}
}

public: void MoveT()
{
	bool flag = true;

	if ((key == true))
	{
		double StepX = 0;
		cout << "Enter size if step relative to the axis OX:" << endl;
		if (!(cin >> StepX))
		{
			cout << "Incorrect input!" << endl;
			flag = false;
		}

		double StepY = 0;
		if (flag == true)
		{
			cout << "Enter size if step relative to the axis OY:" << endl;
			if (!(cin >> StepY) || (flag == false))
			{
				cout << "Incorrect input!";
				flag = false;
			}
		}

		if (flag == true)
		{
			X1 += StepX;
			X2 += StepX;
			X3 += StepX;
			Y1 += StepY;
			Y2 += StepY;
			Y3 += StepY;
			X4 += StepX;
			Y4 += StepY;
		}

		if (flag == true)
		{
			cout << "Rectangle was moved!" << endl;
			cout << "X1 = " << X1 << " Y1 = " << Y1 << endl;
			cout << "X2 = " << X2 << " Y2 = " << Y2 << endl;
			cout << "X3 = " << X3 << " Y3 = " << Y3 << endl;
			cout << "X4 = " << X4 << " Y4 = " << Y4 << endl;
		}

	}
	else
	{
		cout << "Your can't move the rectangle which uncreated!" << endl;
	}
}

public: void ResizeT()
{
	bool flag = true;

	double k = 0;
	if (key == true) {
		cout << "Input ratio of resize: (2 <= x <= 10)" << endl;
		if (!(cin >> k) || (k == 0))
		{
			cout << "Incorrect input!" << endl;
			flag = false;
		}
	}

	if ((flag == true) && (key == false))
	{
		cout << "Can't resize uncreated rectangle!" << endl;
		flag = false;
	}

	if ((flag == true) && (key == true) && (k >= 2) && (k <= 10))
	{
		X1 /= k;
		X2 /= k;
		X3 /= k;
		Y1 /= k;
		Y2 /= k;
		Y3 /= k;
		X4 /= k;
		Y4 /= k;

		cout << "Rectangle was resize! ()" << endl;
		cout << "X1 = " << X1 << " Y1 = " << Y1 << endl;
		cout << "X2 = " << X2 << " Y2 = " << Y2 << endl;
		cout << "X3 = " << X3 << " Y3 = " << Y3 << endl;
		cout << "X4 = " << X4 << " Y4 = " << Y4 << endl;
	}
	else
	{
		cout << "You take unacceptable value!" << endl;
	}
}

public: void RotationT()
{
	bool flag = true;

	double tmp = 0;

	if (key == true)
	{
		cout << "Input degrees of ratation:" << endl;
		if (!(cin >> tmp))
		{
			cout << "Incorrect input!" << endl;
			flag = false;
		}
	}
	else
	{
		if (flag == false)
		{
			cout << "Can't rotate uncreated rectangle!" << endl;
			flag = false;
		}
	}

	if ((key == true) && (flag == true))
	{
		X1 = X1 * cos(tmp) - Y1 * sin(tmp);
		Y1 = X1 * sin(tmp) + Y1 * cos(tmp);

		X2 = X2 * cos(tmp) - Y2 * sin(tmp);
		Y2 = X2 * sin(tmp) + Y2 * cos(tmp);

		X3 = X3 * cos(tmp) - Y3 * sin(tmp);
		Y3 += X3 * sin(tmp) + Y3 * cos(tmp);

		X4 = X4 * cos(tmp) - Y4 * sin(tmp);
		Y4 += X4 * sin(tmp) + Y4 * cos(tmp);


		cout << "Rectangle was rotated!" << endl;
		cout << "X1 = " << X1 << " Y1 = " << Y1 << endl;
		cout << "X2 = " << X2 << " Y2 = " << Y2 << endl;
		cout << "X3 = " << X3 << " Y3 = " << Y3 << endl;
		cout << "X4 = " << X4 << " Y4 = " << Y4 << endl;
	}
}

public: void PropertyT()
{
	if (key == true) {
		if ((X1 == 0) && (X2 == 0) && (X3 == 0) && (X4 == 0) && (Y1 == 0) && (Y2 == 0) && (Y3 == 0) && (Y4 == 0))
		{
			cout << "Rectangle uncreated!" << endl;
		}
		else
		{
			cout << "Rectangle is a real!" << endl;

			if ((X1 >= 0) && (X2 >= 0) && (X3 >= 0) && (X4 >= 0) && (Y1 >= 0) && (Y2 >= 0) && (Y3 >= 0) && (Y4 >= 0))
			{
				cout << "It's in a first quarter." << endl;
			}

			if ((X1 <= 0) && (X2 <= 0) && (X3 <= 0) && (X4 <= 0) && (Y1 <= 0) && (Y2 <= 0) && (Y3 <= 0) && (Y4 <= 0))
			{
				cout << "It's in a third quarter." << endl;
			}

			if ((X1 <= 0) && (X2 <= 0) && (X3 <= 0) && (X4 <= 0) && (Y1 >= 0) && (Y2 >= 0) && (Y3 >= 0) && (Y4 >= 0))
			{
				cout << "It's in a second quarter." << endl;
			}

			if ((X1 >= 0) && (X2 >= 0) && (X3 >= 0) && (X4 >= 0) && (Y1 <= 0) && (Y2 <= 0) && (Y3 <= 0) && (Y4 <= 0))
			{
				cout << "It's in a second quarter." << endl;
			}

		}
	}
	else
	{
		cout << "Rectangle wasn't created!" << endl;
	}
}
};

int main(void)
{
	Triangle N1;
	Rectangle M1;

	/*N1.InputData();
	cout << endl;
	N1.MoveT();
	cout << endl;
	N1.ResizeT();
	cout << endl;
	N1.RotationT();
	cout << endl;
	N1.PropertyT();
	cout << endl;
	*/
	cout << "Create rectangle:" << endl;
	M1.InputData();
	cout << endl;
	M1.MoveT();
	cout << endl;
	M1.ResizeT();
	cout << endl;
	M1.RotationT();
	cout << endl;
	M1.PropertyT();
	cout << endl;
	return 0;
}
