#include <iostream>  // Подключение стандартной библиотеки

using namespace std;  // Использование стандартного пространства имён

void InputDouble(double*);  // Прототип функции ввода элементов матрицы
void InputInt(int*);  // Прототип функции ввода размерности матрицы

int main(void)
{
  setlocale(LC_ALL, "RUS");  // Установка русского языка в консоль
  cout << "\t\t№ 30. Все положительные элементы матрицы заменить значением элемента," << endl;
  cout << "\t\tстоящего в ее последней строке и последнем столбце.\n\n";
  
  int N = 0, M = 0;

  cout << "\tВведите количество строк массива:\n";
  InputInt(&N);  // Ввод размерности матрицы

  cout << "\tВведите количество столбцов массива:\n";
  InputInt(&M);  // Ввод размерности матрицы

  double** matrix;
  matrix = new double* [N];
  for (int i = 0; i < N; i++)  // Выделение памяти под матрицу
  {
    matrix[i] = new double[M];
  }

  cout << "\tВведите элементы массива:\n";

  for (int i = 0; i < N; i++)  // Ввод элементов
  {
    for (int j = 0; j < M; j++)
    {
      cout << "\t\tЭлемент" << " [" << i << "][" << j << "]\n";
      InputDouble(&matrix[i][j]);
    }
  }

  for (int i = 0; i < N; i++)  // Обработка элементов
  {
    for (int j = 0; j < M; j++)
    {
      if (matrix[i][j] > 0) 
      {
              matrix[i][j] = matrix[N-1][M-1];
      }
    }
  }

  cout << "\tВаши элементы массива:\n";

  for (int i = 0; i < N; i++)  // Вывод обработанных элементов
  {
    for (int j = 0; j < M; j++)
    {
      cout << "\t\tЭлемент" << " [" << i << "][" << j << "] = " << matrix[i][j] << endl;
    }
  }
     
  for (int i = 0; i < N; i++)  // Освобождение памяти из под матрицу
  { 
          free(matrix[i]);
  }
  free(matrix);
  cout << endl;
  return 0;
}

void InputInt(int* tmp)  // Описание функции ввода размеров матрицы
{
  while (!(cin >> *tmp) || (cin.peek() != '\n') || (*tmp <= 0))
  {
    cin.clear();
    while (cin.get() != '\n');
    cout << "\tIncorrect input!" << endl;
  }
}

void InputDouble(double* tmp)  // Описание функции ввода элементов матрицы
{
  while (!(cin >> *tmp) || (cin.peek() != '\n'))
  {
    cin.clear();
    while (cin.get() != '\n');
    cout << "\tIncorrect input!" << endl;
  }
}
