#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int CheckingSize(bool*);
vector<double> FillingVector(bool*, int);
void OutputVector(vector<double>*);
vector<double> Process(bool*, int*, int, vector<double>, vector<double>);
void OutputResults(bool, int, vector<double>, int);

int main(void) {

	setlocale(LC_ALL, "Russian");

	bool key = true;  //  Key for checking correct input
	vector<double> vecX;
	vector<double> vecY;  
	vector<double> vecT;

	int size;
	if (size = CheckingSize(&key)) {
		if (key) {
			for (int i = 0; i < size; ++i) {
				vecX.push_back(0);
				vecY.push_back(0);
				vecY.push_back(0);
			}
		}
	}

	if (key && size != 0) {
		cout << "Введите все X координаты вектора:";
		vecX = FillingVector(&key, size);
		if (key) {
			cout << "Введите все Y координаты вектора:";
			vecY = FillingVector(&key, size);
		}
	}

	if (key && size != 0) {
		cout << "X-координаты вашего вектора:";
		OutputVector(&vecX);
		cout << "Y-координаты вашего вектора:";
		OutputVector(&vecY);
	}

	int COUNT = 0; 
	if (key && size != 0) {
		vecT = Process(&key, &COUNT, size, vecX, vecY);
	}

	OutputResults(key, COUNT, vecT, size);
	return 0;
}

int CheckingSize(bool* key) {
	cout << "Введите размер векторов:" << endl;
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
	cout << endl;
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
	cout << endl;
	for (auto el : vec2) {
		cout << el << " ";
	}
	cout << endl << endl;
}

vector<double> Process(bool* key, int* COUNT, int size, vector<double> vec1, vector<double> vec2) {
	cout << "Выполнение расчётов..." << endl << endl;
	vector<double> vecT(size);
	for (int i = 0; i < size; ++i) {
		vecT[i] = max(vec1[i], vec2[i]);
		if (vecT[i] == vec1[i]) {
			++* COUNT;
		}
	}
	return vecT;
}

void OutputResults(bool key, int COUNT, vector<double> vec, int size) {
	if (!key) {
		cout << "Некорректный ввод!" << endl;
	}
	else {
		if (size) {
			cout << "Вектор Tk: " << endl;
			for (auto el : vec) {
				cout << el << " ";
			}
		cout << endl;
		cout << "Количество элементов Tk = Xk: " << endl;
		cout << COUNT << endl;
		}
		else {
			cout << "Нет подходящих элементов!" << endl;
		}
	}
}
