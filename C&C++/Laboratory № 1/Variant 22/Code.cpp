#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(void)
{
  setlocale(LC_ALL, "Russian");

  bool key = true;

  cout << "Ввод количества элементов вектора: ";
  int n = 0, count = 0;
  double tmp = 0;
  char ch;
  double* matrix = NULL;

  if (scanf("%lf%c", &tmp, &ch) == 2 && (ch == '\n') && (tmp > 0) && (tmp == (int)tmp))
  {
    n = tmp;
  }
  else
  {
    cout << endl << 
      "Ошибка ввода!" << endl;
    key = false;
  }

  if (key == true)
  {
    cout << "Введите сами элементы:" << endl;
    matrix = new double[n];
    for (int i = 0; i < n; i++)  // Ввод вектора
    {
      if (!(scanf("%lf%c", &matrix[i], &ch) == 2 && (ch == '\n')))
      {
        cout << endl << "Ошибка ввода!" << endl;
        key = false;
        break;
      }
      
      if ((i == 0) && (matrix[i]) >= 0)
      {
        cout << endl << "Первый элемент должен быть отрицательным!" << endl;
        key = false;
        break;
      }
    }

    for (int i = 0; i < n; i++)  // Проверка на условие задачи 
    {
      if (matrix[i] < 0)
      {
        ++count;
      }

      if ((matrix[i] > 0) && (i > 0))
      {
        matrix[i] *= matrix[i - 1];
      }
    }
  }

  if (key != 0)
  {
    cout << "Количество отрицательных элементов: " << endl;
    cout << count << endl;
    cout << "Вывод массива" << endl;
    for (int i = 0; i < n; i++)
    {
      cout << matrix[i] << " "; // вывод вектора 
    }
    cout << endl;
    delete[] matrix;
  }
  return 0;
}
