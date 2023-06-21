#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>

using namespace std;

int CheckingSize(bool*);

int main(void) {

	setlocale(LC_ALL, "Russian");

	bool key = true;  //  Key for checking correct input

	int n = CheckingSize(&key);
	int m = CheckingSize(&key);

	vector <vector<double>> vec(n, vector<double>(m));
	
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите элементы " << i << " строки:" << endl;
		for (int j = 1; j <= m; j++)
		{
			cin >> vec[i - 1][j - 1]; //заполняем элементы матрицы по формуле
		}
	}

	cout << "Ваш массив:" << endl;
	for (auto& row : vec) //для каждой строки матрицы
	{
		cout << "|"; //Это обрамление матрицы, для красоты распечатки
		for (auto& el : row) //для каждого элемента строки
		{
			cout << setw(7) << fixed << setprecision(5) << el << " ";
		}
		cout << "|" << endl; //Печатаем обрамление и переводим вывод на следующую строку
	}

	for (auto row : vec) {
		int count1 = 0, count2 = 0;
		int number = 1;
		for (auto el : row) {
			if (el < 0) ++count1;
			if (el > 0) ++count2;
		}
		cout << "Кол-во отрицательных чисел строки №: " << number << " равно -" << count1 << endl;
		cout << "Кол-во положительных чисел строки №: " << number << " равно -" << count2 << endl;
		++number;
		cout << endl;
	}

	return 0;
}



int CheckingSize(bool* key) {
	cout << "Введите размер вектора:" << endl;
	double size;
	if (!(cin >> size && size >= 0 && (int)size == size)) {
		*key = false;
		size = 0;
	}
	cout << endl;
	return size;
}
