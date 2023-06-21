#include <iostream>
#include <vector>

using namespace std;

int CheckingSize(bool*);
vector<double> FillingVector(bool*, int);
void OutputVector(vector<double>*);
void InputLimits(bool*, double*, double*);
void Process(bool*, double, double, double*, int*, vector<double>);
void OutputResult(bool, double, int);

int main(void) {

	setlocale(LC_ALL, "Russian");

	bool key = true;  // Key for checking correct input
	vector<double> vec;  // For avoid a errors
	int size;
	if (size = CheckingSize(&key)) {
		if (key) {
			for (int i = 0; i < size; ++i) {
				vec.push_back(0);
			}
		}
	}

	if (key && size != 0) {
		vec = FillingVector(&key, size);
	}

	if (key && size != 0) {
		OutputVector(&vec);
	}

	double A, B;
	if (key && size != 0) {
		InputLimits(&key, &A, &B);
	}

	int COUNT = 0; 
	double SUM = 0;
	if (key && size != 0) {
		Process(&key, A, B, &SUM, &COUNT, vec);
	}

	OutputResult(key, SUM, COUNT);
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

vector<double> FillingVector(bool* key, int size) {
	vector<double> vec(size);
	cout << "Введите элементы вектора:" << endl;
	for (auto& el : vec) {
		if (!(cin >> el)) {
			*key = false;
			break;
		}
	}
	cout << endl;
	return vec;
}

void OutputVector(vector<double>* vec) {
	vector<double> vec2 = *vec;
	cout << "Ваши элементы:" << endl;
	for (auto el : vec2) {
		cout << el << " ";
	}
	cout << endl << endl;
}

void InputLimits(bool* key, double* A, double* B) {
	cout << "Введите граничные значения - A, B" << endl;
	double a, b;
	if (!(cin >> a >> b)) {
		*key = false;
		cout << endl;
	}
	else {
		*A = a;
		*B = b;
		cout << endl;
	}
}

void Process(bool* key, double A, double B, double* SUM, int* COUNT, vector<double> vec) {
	cout << "Выполнение расчётов..." << endl << endl;
	vector<double> vec2 = vec;
	for (auto el : vec2) {
		if (el >= A && B >= el) {
			*SUM += el;
			++* COUNT;
		}
	}
}

void OutputResult(bool key, double SUM, int COUNT) {
	if (!key) {
		cout << "Некорректный ввод!" << endl;
	}
	else {
		if (COUNT) {
			cout << "Сумма подходящих чисел под услови A <= Xk <= B: " << SUM << endl << endl;
			cout << "Количество подходящих чисел под услови A <= Xk <= B: " << COUNT << endl;
		}
		else {
			cout << "Нет подходящих элементов!" << endl;
		}
	}
}
